#include <iostream>
#include "date.h"
#include "test_helpers.h"

int main() {
    // test constructor
    expect_throw(Date(-1, 6, 6));        // invalid year
    expect_throw(Date(2000, -1, 6));     // invalid month
    expect_throw(Date(2000, 13, 6));     // invalid month
    expect_throw(Date(2000, 6, 0));      // invalid day
    expect_throw(Date(2000, 6, 31));     // invalid day
    expect_throw(Date(1582, 10, 14));    // before the gregorian calendar began
    expect_throw(Date(1900, 2, 29));     // not a leap year
    expect_no_throw(Date(2000, 2, 29));  // a once every 400 years leap year
    expect_no_throw(Date(2025, 10, 18)); // a valid date

    // test operator==
    expect(Date(2025, 10, 18) == Date(2025, 10, 18));
    expect(!(Date(2025, 10, 18) == Date(2025, 10, 19)));
    expect(!(Date(2025, 10, 18) == Date(2025, 9, 18)));
    expect(!(Date(2025, 10, 18) == Date(2026, 10, 18)));

    // test operator<
    expect(Date(2025, 10, 18) < Date(2025, 12, 19));
    expect(Date(1582, 10, 15) < Date(5883517, 1, 1));
    expect(Date(2025, 10, 31) < Date(2025, 12 ,31));  // but OCT 31 == DEC 25 ... get it? =)

    return 0;
}
