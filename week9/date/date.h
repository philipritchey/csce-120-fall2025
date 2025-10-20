#ifndef WEEK9_DATE_DATE_H_
#define WEEK9_DATE_DATE_H_

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

    // TODO(student): [bonus] implement increment (++) operator
    Date& operator++();
};

enum Month {
    January = 1,
    Febraury,
    March,
    April,
    May,
    June,
    July,
    August,
    Septemeber,
    October,
    November,
    December
};

// TODO(student): define this operator
std::ostream& operator<<(std::ostream&, const Date&);

#endif  // WEEK9_DATE_DATE_H_
