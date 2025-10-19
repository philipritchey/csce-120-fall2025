#ifndef TEST_HELPERS_H_
#define TEST_HELPERS_H_

#define here __func__ << ":" << __LINE__

#define expect_throw(expression) try{\
    expression;\
    std::cout << "[FAIL] (" << here << ")\n";\
    std::cout << "expected " << #expression << " to throw an exception, but nothing thrown" << std::endl;\
} catch (...) {\
    std::cout << "[PASS] " << #expression << " threw an exception" << std::endl;\
}

#define expect_no_throw(expression) try{\
    expression;\
    std::cout << "[PASS] " << #expression << " did not throw an exception" << std::endl;\
} catch (const std::exception& err) {\
    std::cout << "[FAIL] (" << here << ")\n";\
    std::cout << "expected " << #expression << " to not throw an exception, but something thrown" << std::endl;\
    std::cout << "what: " << err.what()<< std::endl;\
} catch (...) {\
    std::cout << "[FAIL] (" << here << ")\n";\
    std::cout << "expected " << #expression << " to not throw an exception, but something thrown" << std::endl;\
}

#define expect(expression) try {\
    if (!(expression)) {\
        std::cout << "[FAIL] (" << here << ")\n";\
        std::cout << "Expected " << #expression << " to be true " << "\n";\
        std::cout << "     Got false" << std::endl;\
    } else {\
        std::cout << "[PASS] " << #expression << std::endl;\
    }\
} catch (const std::exception& err) {\
    std::cout << "[FAIL] (" << here << ")\n";\
    std::cout << "expect(" << #expression << ")\n";\
    std::cout << "unexpected exception, what: " << err.what()<< std::endl;\
} catch (...) {\
    std::cout << "[FAIL] (" << here << ")\n";\
    std::cout << "expect(" << #expression << ")\n";\
    std::cout << "unexpected non-std::exception" << std::endl;\
}

#endif  // TEST_HELPERS_H_
