#include <iostream>
#include <sstream>
#include "date.h"
#include "test_helpers.h"

int main() {
    // TODO(student): [bonus^2] write tests
    {
        Date date(2025, 10, 20);
        // put into stream
        std::ostringstream oss;
        oss << date;
        // get string from stream
        expect_equal(oss.str(), "20 October 2025");
    }

    {
        // end of month
        Date date(2025, 10, 31);
        ++date;
        expect_equal(date.get_day(), 1);
        expect_equal(date.get_month(), 11);
        expect_equal(date.get_year(), 2025);
    }

    {
        // end of year
        Date date(2025, 12, 31);
        ++date;
        expect_equal(date.get_day(), 1);
        expect_equal(date.get_month(), 1);
        expect_equal(date.get_year(), 2026);
    }

    {
        // leap year
        Date date(2000, 02, 28);
        ++date;
        expect_equal(date.get_day(), 29);
        expect_equal(date.get_month(), 2);
        expect_equal(date.get_year(), 2000);
    }

        {
        // not a leap year
        Date date(2025, 02, 28);
        ++date;
        expect_equal(date.get_day(), 1);
        expect_equal(date.get_month(), 3);
        expect_equal(date.get_year(), 2025);
    }

    return 0;
}
