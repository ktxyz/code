#include <queue>
#include <string>

int knight(std::string start, std::string finish) {
    int size = 8;

    std::vector<std::vector<bool>> vis;
    for(int i = 0; i < size; ++i)
        vis.push_back(std::vector<bool>(size, false));


    std::queue<std::tuple<int, int, int>> q;

    int sx = start[0] - 'a';
    int sy = start[1] - '1';
    int ex = finish[0] - 'a';
    int ey = finish[1] - '1';

    std::vector<std::pair<int, int>> moves = {
        {2, 1},
        {-2, 1},
        {2, -1},
        {-2, -1},
        {1, 2},
        {-1, 2},
        {1, -2},
        {-1, -2}
    };

    q.push({sx, sy, 0});
    vis[sx][sy] = true;
    while(!q.empty()) {
        auto [x, y, d] = q.front();
        q.pop();

        if (x == ex && y == ey)
            return d;

        for (auto &m : moves) {
            int nx = x + m.first;
            int ny = y + m.second;

            if (nx < 0 || nx >= size || ny < 0 || ny >= size)
                continue;

            if (vis[nx][ny])
                continue;

            q.push({nx, ny, d + 1});
            vis[nx][ny] = true;
        }
    }

    return 0;
}