#include <stdexcept>
#include <string>
#include "date.h"

// assume gregorian calendar
// "first day" := 1582 october 15

void validate_year(int year) {
    if (year < 1582) {
        throw std::invalid_argument("invalid year");
    }
}

void validate_month(int year, int month) {
    if (month < January
        || month > December
        || (year == 1582 && month < October)) {
        throw std::invalid_argument("invalid month");
    }
}

bool is_leap_year(int year) {
    return year % 4 == 0 && (year % 100 > 0 || year % 400 == 0);
}

int days_per_month(int month, int year = 1) {
    switch (month) {
        case Febraury:
            return is_leap_year(year) ? 29 : 28;
        case April:
        case June:
        case Septemeber:
        case November:
            return 30;
        case January:
        case March:
        case May:
        case July:
        case August:
        case October:
        case December:
            return 31;
        default:
            return 0;
    }
}

void validate_day(int year, int month, int day) {
    if (day < 1
        || day > days_per_month(month, year)
        || (year == 1582 && month == October && day < 15)) {
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
        || (this->year == rhs.year
            && this->month < rhs.month)
        || (this->year == rhs.year
            && this->month == rhs.month
            && this->day < rhs.day);
}

std::string month_name(int month) {
    switch (month) {
        case January: return "January";
        case Febraury: return "February";
        case March: return "March";
        case April: return "April";
        case May: return "May";
        case June: return "June";
        case July: return "July";
        case August: return "August";
        case Septemeber: return "September";
        case October: return "October";
        case November: return "November";
        case December: return "December";
        default: return "InvalidMonth";
    }
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    return os << date.get_day()
        << " " << month_name(date.get_month())
        << " " << date.get_year();
}

Date& Date::operator++() {
    this->day += 1;
    if (this->day > days_per_month(this->month, this->year)) {
        this->day = 1;
        this->month += 1;
        if (this->month > December) {
            this->month = January;
            this->year += 1;
        }
    }
    return *this;
}
