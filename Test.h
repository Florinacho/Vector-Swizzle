#ifndef __TEST_FRAMEWORK_H__
#define __TEST_FRAMEWORK_H__

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define TEST_COLOR_RED         "\033[0;31m"
#define TEST_COLOR_RED_BOLD    "\033[1;31m"
#define TEST_COLOR_GREEN       "\033[0;32m"
#define TEST_COLOR_GREEN_BOLD  "\033[1;32m"
#define TEST_COLOR_YELLOW      "\033[0;33m"
#define TEST_COLOR_YELLOW_BOLD "\033[1;33m"
#define TEST_COLOR_RESET       "\033[0m"

enum TestStatus {
	TEST_PASSED = 0,
	TEST_FAILED = 1
};

struct TestFunctionState {
	char error[256];
	char file[256];
	int line;
	int status;
};
typedef void(*TestFunctionPointer)(void*);

struct TestEntry {
	char identifier[64];
	TestFunctionPointer function;
};

inline void FailTest(TestFunctionState *state,
                     const char* file,
                     int line,
                     const char *format,
                     ...)
{
    va_list args;
    va_start(args, format);
    strncpy(state->file, file, sizeof(TestFunctionState::file));
    state->line = line;
    vsnprintf(state->error, sizeof(TestFunctionState::error), format, args);
    state->status = TEST_FAILED;
    va_end(args);
}

#define UNIT_TEST(function) {#function, function}
#define RunTestArray(array) RunTests(array, sizeof(array) / sizeof(array[0]))

#define assert_condition(value) {                                             \
    const bool condition = (value);                                           \
    if ((condition) == false) {                                               \
        FailTest((TestFunctionState*)state,                                   \
                  __FILE__,                                                   \
                  __LINE__,                                                   \
                  "Assertion failed: " #value);                               \
        return;                                                               \
    }                                                                         \
}

#define assert_int_equal(lvalue, rvalue) {                                    \
    const int value0 = (lvalue);                                              \
    const int value1 = (rvalue);                                              \
    if (value0 != value1) {                                                   \
        FailTest((TestFunctionState*)state,                                   \
                  __FILE__,                                                   \
                  __LINE__,                                                   \
                  "Assertion failed: %d == %d",                               \
                  value0,                                                     \
                  value1);                                                    \
        return;                                                               \
    }                                                                         \
}

#define assert_int_not_equal(lvalue, rvalue) {                                \
	const int value0 = (lvalue);                                              \
	const int value1 = (rvalue);                                              \
    if (value0 == value1) {                                                   \
        FailTest((TestFunctionState*)state,                                   \
                  __FILE__,                                                   \
                  __LINE__,                                                   \
                  "Assertion failed: %d != %d",                               \
                  value0,                                                     \
                  value1);                                                    \
        return;                                                               \
    }                                                                         \
}


#define assert_float_equal(lvalue, rvalue) {                                  \
	const float value0 = (lvalue);                                            \
	const float value1 = (rvalue);                                            \
    if (value0 != value1) {                                                   \
        FailTest((TestFunctionState*)state,                                   \
                  __FILE__,                                                   \
                  __LINE__,                                                   \
                  "Assertion failed: %f == %f",                               \
                  value0,                                                     \
                  value1);                                                    \
        return;                                                               \
    }                                                                         \
}

#define assert_float_not_equal(lvalue, rvalue) {                              \
	const float value0 = (lvalue);                                            \
	const float value1 = (rvalue);                                            \
    if (value0 == value1) {                                                   \
        FailTest((TestFunctionState*)state,                                   \
                  __FILE__,                                                   \
                  __LINE__,                                                   \
                  "Assertion failed: %f != %f",                               \
                  value0,                                                     \
                  value1);                                                    \
        return;                                                               \
    }                                                                         \
}

void RunTests(const TestEntry* tests, unsigned int testCount) {
	unsigned int passed = 0;
	unsigned int failed = 0;

	printf("Running %u tests ...\n\n", testCount);

	for (unsigned int index = 0; index < testCount; ++index) {
		TestFunctionState state;
		state.line = 0;
		state.status = 0;
		state.error[0] = '\0';

		tests[index].function(&state);

		switch (state.status) {
		case TEST_PASSED :
			printf(TEST_COLOR_GREEN "PASSED "
					TEST_COLOR_YELLOW "%s\n"
					TEST_COLOR_RESET,
					tests[index].identifier);
			++passed;
			break;

		case TEST_FAILED :
			printf(TEST_COLOR_RED "FAILED "
					TEST_COLOR_YELLOW "%s"
					TEST_COLOR_RESET "\n\t%s::%d: %s\n",
					tests[index].identifier,
					state.file,
					state.line,
					state.error);
			++failed;
			break;
		}
	}

	printf("\nTests passed: " TEST_COLOR_GREEN "%d\n" TEST_COLOR_RESET, passed);
	printf("Tests failed: " TEST_COLOR_RED   "%d\n\n" TEST_COLOR_RESET, failed);
}

#endif // __TEST_FRAMEWORK_H__
