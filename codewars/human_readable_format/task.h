#include <string>

std::string format_duration(int seconds) {
    if (seconds == 0) return "now";

    int years = seconds / (365 * 24 * 60 * 60);
    int days = (seconds % (365 * 24 * 60 * 60)) / (24 * 60 * 60);
    int hours = (seconds % (24 * 60 * 60)) / (60 * 60);
    int minutes = (seconds % (60 * 60)) / 60;
    int remainingSeconds = seconds % 60;

    std::string result;

    if (years > 0) {
        result += std::to_string(years);
        result += (years > 1) ? " years" : " year";
        if (days > 0 || hours > 0 || minutes > 0 || remainingSeconds > 0) result += ", ";
    }
    if (days > 0) {
        result += std::to_string(days);
        result += (days > 1) ? " days" : " day";
        if (hours > 0 || minutes > 0 || remainingSeconds > 0) result += ", ";
    }
    if (hours > 0) {
        result += std::to_string(hours);
        result += (hours > 1) ? " hours" : " hour";
        if (minutes > 0 || remainingSeconds > 0) result += ", ";
    }
    if (minutes > 0) {
        result += std::to_string(minutes);
        result += (minutes > 1) ? " minutes" : " minute";
        if (remainingSeconds > 0) result += ", ";
    }
    if (remainingSeconds > 0) {
        result += std::to_string(remainingSeconds);
        result += (remainingSeconds > 1) ? " seconds" : " second";
    }

    if (auto occurance = std::find(result.rbegin(), result.rend(), ','); occurance != result.rend()) {
        auto pos = std::distance(occurance, result.rend()) - 1;
        return result.substr(0, pos) + " and " + result.substr(pos + 2);
    }

    return result;
}
