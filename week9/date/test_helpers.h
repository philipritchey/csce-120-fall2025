#ifndef WEEK9_DATE_TEST_HELPERS_H_
#define WEEK9_DATE_TEST_HELPERS_H_

#include <iostream>

#define here __func__ << ":" << __LINE__

#define expect_equal(actual, expected) try {\
    auto actual_value = actual;\
    auto expected_value = expected;\
    if (!(actual_value == expected_value)) {\
        std::cout << "[FAIL] (" << here << ")\n";\
        std::cout << "Expected " << #actual << " to equal " << #expected << "\n";\
        std::cout << "     Got " << actual_value << " != " << expected_value << std::endl;\
    } else {\
        std::cout << "[PASS] " << #actual << " == " << #expected << std::endl;\
    }\
} catch (const std::exception& err) {\
    std::cout << "[FAIL] (" << here << ")\n";\
    std::cout << "expect_equal(" << #actual << ", " << #expected << ")\n";\
    std::cout << "unexpected exception, what: " << err.what()<< std::endl;\
} catch (...) {\
    std::cout << "[FAIL] (" << here << ")\n";\
    std::cout << "expect_equal(" << #actual << ", " << #expected << ")\n";\
    std::cout << "unexpected non-std::exception" << std::endl;\
}

#endif  // WEEK9_DATE_TEST_HELPERS_H_
