// Let's make a Date class.
// It should only allow valid dates and it can compare if dates are equal or less than.

#ifndef DATE_H_
#define DATE_H_

#include <iostream>

class Date {
    int year;
    int month;
    int day;

public:
    Date(int year, int month, int day);

    bool operator==(const Date& rhs) const;
    bool operator<(const Date& rhs) const;

    int get_year() const { return year; }
    int get_month() const { return month; }
    int get_day() const { return day; }
};

// std::ostream& operator<<(std::ostream&, const Date&);

#endif  // DATE_H_