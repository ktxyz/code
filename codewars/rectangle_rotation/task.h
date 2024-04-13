#include <cmath>

using llong = long long;
using ldouble = long double;

constexpr llong MIN = -2e4;
constexpr llong MAX = 2e4;
constexpr ldouble EPS = 1e-9;
constexpr ldouble INVALID_COORD = -1e9;
constexpr ldouble ONE = 1.f;
constexpr ldouble MONE = -1.f;
constexpr ldouble HALF_ANGLE = 180;
constexpr ldouble RADIAN = M_PI / HALF_ANGLE;


struct Point
{
    ldouble x;
    ldouble y;

    void rotate(ldouble angle) {
        ldouble s = std::sinl(angle * RADIAN);
        ldouble c = std::cosl(angle * RADIAN);

        ldouble nx = x * c - y * s;
        ldouble ny = x * s + y * c;

        x = nx;
        y = ny;
    }

    ldouble dist2(const Point& p) const {
        return (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y);
    }

    ldouble dist(const Point& p) const {
        return std::sqrt(dist2(p));
    }

    bool is_lattice() const {
        return static_cast<llong>(x) == x && static_cast<llong>(y) == y;
    }

    ldouble cross(const Point& p1, const Point& p2) {
        return (p1.x - p2.x) * (y - p1.y) - (p2.y - p1.y) * (x - p1.x);
    }
};

struct Line {
    Point a, b;

    ldouble lerp_point(ldouble y) const {
        auto top_p = a, bottom_p = b;
        if (top_p.y < bottom_p.y)
            std::swap(top_p, bottom_p);

        if (y < bottom_p.y || y > top_p.y) {
            return INVALID_COORD;
        }
        
        ldouble alpha = ((y - bottom_p.y) / (top_p.y - bottom_p.y));
        return top_p.x * alpha + bottom_p.x * (ONE - alpha);
    }
};

struct Rectangle
{
    Point a, b, c, d;
    int height, width;

    void rotate(ldouble angle) {
        a.rotate(angle);
        b.rotate(angle);
        c.rotate(angle);
        d.rotate(angle);
    }

    ldouble area() const {
        return a.dist(b) * b.dist(c);
    }
};

llong points_on_line(const Line &l) {
    return 0;
}

llong number_of_points(Rectangle& r) {
    llong points = 0;

    // We have to this in three parts
    Line left_line = {r.d, r.a};
    Line right_line = {r.d, r.c};
    for(llong y = static_cast<ldouble>(r.d.y); y < static_cast<llong>(r.a.y); ++y) {
        llong x_left = std::ceill(left_line.lerp_point(y));
        llong x_right = std::floorl(right_line.lerp_point(y));

        if (x_left == INVALID_COORD || x_right == INVALID_COORD) {
            continue;
        }

        points += (x_right - x_left + 1);
    }

    left_line = {r.a, r.b};
    for(llong y = static_cast<ldouble>(std::ceill(r.a.y)); y <= static_cast<llong>(r.c.y); ++y) {
        llong x_left = std::ceill(left_line.lerp_point(y));
        llong x_right = std::floorl(right_line.lerp_point(y));

        if (x_left == INVALID_COORD || x_right == INVALID_COORD) {
            continue;
        }

        points += (x_right - x_left + 1);
    }

    right_line = {r.b, r.c};
    for(llong y = static_cast<ldouble>(r.c.y) + 1; y <= static_cast<llong>(r.b.y); ++y) {
        llong x_left = std::ceill(left_line.lerp_point(y));
        llong x_right = std::floorl(right_line.lerp_point(y));

        if (x_left == INVALID_COORD || x_right == INVALID_COORD) {
            continue;
        }

        points += (x_right - x_left + 1);
    }

    return points;
}

llong rectangle_rotation(int w, int h) {
    // we make sure that point a is lower than point c
    if (w < h)
        std::swap(w, h);

    ldouble a = static_cast<ldouble>(w);
    ldouble b = static_cast<ldouble>(h);
    Rectangle r = {{-a/2, b/2}, {a/2, b/2}, {a/2, -b/2}, {-a/2, -b/2}};
    r.rotate(45);

    return number_of_points(r); 
}