#include <string>
#include <algorithm>
#include <vector>
#include <sstream>


std::string range_extraction(std::vector<int> args) {
    std::vector<int> queue;

    std::sort(args.begin(), args.end());
    int i = 1;
    queue.push_back(args[0]);

    std::stringstream ss;

    auto dump_queue = [&]() {
        if (queue.size() > 2) {
            ss << queue.front() << "-" << queue.back();
        } else if (queue.size() == 2) {
            ss << queue.front() << "," << queue.back();
        } else if (queue.size() == 1) {
            ss << queue.front();
        }

        queue.clear();
    };

    while (i < args.size()) {
        while(i < args.size() && args[i] == queue.back() + 1) {
            queue.push_back(args[i++]);
        }

        dump_queue();

        if (i < args.size()) {
            ss << ",";
            queue.push_back(args[i++]);
        }
    }
    dump_queue();
    return ss.str();
}