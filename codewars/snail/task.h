#include <vector>


std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
    if (snail_map.size() == 0)
        return {};

    std::vector<int> answer;
    int guard[] = {static_cast<int>(snail_map[0].size()), static_cast<int>(snail_map.size()), -1, 0};
    int guard_diff[] = {-1, -1, 1, 1};
    int x = 0, y = 0;
    int* ptrs[] = {&x, &y, &x, &y};

    int moves = snail_map.size() * snail_map[0].size();
    while(moves) {
        for(int i = 0; i < 4; ++i) {
            while(moves && *ptrs[i] != guard[i]) {
                answer.push_back(snail_map[y][x]);
                --moves;
                *ptrs[i] -= guard_diff[i];
            }
            *ptrs[i] += guard_diff[i];
            *ptrs[(i + 1) % 4] -= guard_diff[(i + 1) % 4];
            guard[i] += guard_diff[i];
        }
    }

    return answer;
}