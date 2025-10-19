#include <stdexcept>
#include "date.h"

// assume gregorian calendar
// "first day" := 1582 october 15

void validate_year(int year) {
    if (year < 1582) {
        throw std::invalid_argument("invalid year");
    }
}

void validate_month(int year, int month) {
    if (month < 1 || month > 12 || (year == 1582 && month < 10)) {
        throw std::invalid_argument("invalid month");
    }
}

bool is_leap_year(int year) {
    return year % 4 == 0 && (year % 100 > 0 || year % 400 == 0);
}

void validate_day(int year, int month, int day) {
    int DAYS_PER_MONTH[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day < 1 || day > DAYS_PER_MONTH[month] || (year == 1582 && month == 10 && day < 15)) {
        if (month == 2 && day == 29 && is_leap_year(year)) {
            return;
        }
        throw std::invalid_argument("invalid day");
    }
}

Date::Date(int year, int month, int day) : year{year}, month{month}, day{day} {
    validate_year(year);
    validate_month(year, month);
    validate_day(year, month, day);
}

bool Date::operator==(const Date& rhs) const {
    return this->year == rhs.year
        && this->month == rhs.month
        && this->day == rhs.day;
}

bool Date::operator<(const Date& rhs) const {
    return this->year < rhs.year
        || (this->year == rhs.year && this->month < rhs.month)
        || (this->year == rhs.year && this->month == rhs.month && this->day < rhs.day);
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    return os << date.get_year() << "/" << date.get_month() << "/" << date.get_day();
}