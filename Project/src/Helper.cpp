#include "../headers/Helper.h"

string Helper::formatHours(int value, string suffixe)
{
    return value != 0 ? to_string(value) + " " + suffixe + " " : "";
}

string Helper::formatDate(double s)
{
    int minutes = int(s) / 60;
    double x = s - minutes * 60;
    int seconds = int(x);
    x -= seconds;
    x *= 1e+3;
    int milliseconds = int(x);
    x -= milliseconds;
    x *= 1e+3;
    int microseconds = int(x);
    x -= microseconds;
    x *= 1e+3;
    int nanoseconds = int(x);

    std::string result = formatHours(minutes, "m");
    result += formatHours(seconds, "s");
    result += formatHours(milliseconds, "ms");
    result += formatHours(microseconds, "us");
    result += formatHours(nanoseconds, "ns");

    return result;
}