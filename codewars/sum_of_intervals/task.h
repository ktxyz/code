#include <set>
#include <vector>
#include <utility>


int sum_intervals(std::vector<std::pair<int, int>> intervals) {
    std::vector<std::tuple<int, int, int>> events;

    for(auto &i : intervals) {
        events.push_back({i.first, 1, i.second});
        events.push_back({i.second + 1, -1, i.first});
    }
    std::sort(events.begin(), events.end());

    int pop = 0;
    int head = 0;
    int answer = 0;
    for(auto &[a, t, b] : events) {
        switch (t) {
            case -1:
                if (--pop == 0) {
                    answer += a - head - 1;
                }
            break;
            case 1:
                if (pop++ == 0) {
                    head = a;
                }
            break;
            default:
            break;
        }
    }

    return answer;
}
