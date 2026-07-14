#include <iostream>
#include <string>
#include <ctime>
#include <regex>

using  namespace std;

enum class DateFormat {
    RU,
    RU_short,
    ISO,
    ISO_short,
    UNKNOWN
};

int get_now_year() {
    time_t now = std::time(nullptr);
    
    tm* local_time = std::localtime(&now);

    return local_time->tm_year + 1900;
}

void add_year_to_date(string& date, DateFormat format) {
    switch (format) {
        case DateFormat::RU_short: date += "." + to_string(get_now_year()); break;
        case DateFormat::ISO_short: date = to_string(get_now_year()) + '-' + date; break;
        default: break;
    }
}

DateFormat check_format_date(string& date) {
    static const vector<pair<regex, DateFormat>> formats = {
        { std::regex(R"(\d{2}\.\d{2}\.\d{4})"), DateFormat::RU       }, // 13.07.2026
        { std::regex(R"(\d{2}\.\d{2})"), DateFormat::RU_short }, // 13.07.
        { std::regex(R"(\d{4}-\d{2}-\d{2})"),   DateFormat::ISO      }, // 2026-07-13
        { std::regex(R"(\d{2}-\d{2})"),   DateFormat::ISO_short}  // 07-13
    };

    for (const auto& [pattern, format_enum] : formats) {
        if (std::regex_match(date, pattern)) {
            return format_enum;
        }
    }

    return DateFormat::UNKNOWN;
}

void to_iso_translate(string& date) {
    date = date.substr(6, 4) + "-" + date.substr(3, 2) + "-" + date.substr(0, 2);
}

void date_processing(string& date) {
    auto format_date = check_format_date(date);
    switch (format_date) {
        case DateFormat::RU:
            to_iso_translate(date);
            break;

        case DateFormat::RU_short:
            add_year_to_date(date, format_date);
            to_iso_translate(date);
            break;

        case DateFormat::ISO_short:
            add_year_to_date(date, format_date);
            break;

        case DateFormat::ISO:
            break;
        default:
            cout << "Не верный формат даты" << endl;
    }
}