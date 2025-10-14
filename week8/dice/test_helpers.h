#ifndef TEST_HELPERS_H_
#define TEST_HELPERS_H_

#define expect_equal(actual, expected) try {\
    unsigned actual_value = actual;\
    unsigned expected_value = expected;\
    if (!(actual_value == expected_value)) {\
        std::cout << "[FAIL] " << __func__ << ":" <<__LINE__ << "\n";\
        std::cout << "Expected " << #actual << " == " << #expected << "\n";\
        std::cout << "     Got " << actual_value << " != " << expected_value << std::endl;\
    } else {\
        std::cout << "[PASS] " << #actual << " == " << #expected << std::endl;\
    }\
} catch (const std::exception& err) {\
    std::cout << "[FAIL] " << __func__ << ":" <<__LINE__ << "\n";\
    std::cout << "unexpected exception, what: " << err.what()<< std::endl;\
} catch (...) {\
    std::cout << "[FAIL] " << __func__ << ":" <<__LINE__ << "\n";\
    std::cout << "unexpected non-std::exception" << std::endl;\
}

#define expect_between(actual, expected_lower, expected_upper) try {\
    unsigned actual_value = actual;\
    unsigned expected_lower_value = expected_lower;\
    unsigned expected_upper_value = expected_upper;\
    if (!(actual_value >= expected_lower_value)) {\
        std::cout << "[FAIL] " << __func__ << ":" <<__LINE__ << "\n";\
        std::cout << "Expected " << #expected_lower << " <= " << #actual << "\n";\
        std::cout << "     Got " << expected_lower_value << " > " <<  actual_value << std::endl;\
    } else if (!(actual_value <= expected_upper_value)) {\
        std::cout << "[FAIL] " << __func__ << ":" <<__LINE__ << "\n";\
        std::cout << "Expected " << #actual << " <= " << #expected_upper << "\n";\
        std::cout << "     Got " << actual_value << " > " << expected_upper_value << std::endl;\
    } else {\
        std::cout << "[PASS] " << #expected_lower << " <= " << #actual << " <= " << #expected_upper << std::endl;\
    }\
} catch (const std::exception& err) {\
    std::cout << "[FAIL] " << __func__ << ":" <<__LINE__ << "\n";\
    std::cout << "unexpected exception, what: " << err.what()<< std::endl;\
} catch (...) {\
    std::cout << "[FAIL] " << __func__ << ":" <<__LINE__ << "\n";\
    std::cout << "unexpected non-std::exception" << std::endl;\
}

#endif  // TEST_HELPERS_H_
