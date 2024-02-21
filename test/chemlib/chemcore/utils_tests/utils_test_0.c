#include "test_shared.h"

int main() {
    TEST_CASE {
        ensure(chemlib_utils_is_digit('0') == 1);
        ensure(chemlib_utils_is_digit('1') == 1);
        ensure(chemlib_utils_is_digit('2') == 1);
        ensure(chemlib_utils_is_digit('3') == 1);
        ensure(chemlib_utils_is_digit('4') == 1);
        ensure(chemlib_utils_is_digit('5') == 1);
        ensure(chemlib_utils_is_digit('6') == 1);
        ensure(chemlib_utils_is_digit('7') == 1);
        ensure(chemlib_utils_is_digit('8') == 1);
        ensure(chemlib_utils_is_digit('9') == 1);

        ensure(chemlib_utils_is_digit('A') == 0);
        ensure(chemlib_utils_is_digit('b') == 0);
    }

    TEST_CASE {
        ensure(chemlib_utils_is_uppercase('0') == 0);
        ensure(chemlib_utils_is_uppercase('1') == 0);

        ensure(chemlib_utils_is_uppercase('a') == 0);
        ensure(chemlib_utils_is_uppercase('b') == 0);
        ensure(chemlib_utils_is_uppercase('z') == 0);
        ensure(chemlib_utils_is_uppercase('h') == 0);

        ensure(chemlib_utils_is_uppercase('A') == 1);
        ensure(chemlib_utils_is_uppercase('B') == 1);
        ensure(chemlib_utils_is_uppercase('Z') == 1);
        ensure(chemlib_utils_is_uppercase('H') == 1);
    }

    TEST_CASE {
        ensure(chemlib_utils_is_lowercase('0') == 0);
        ensure(chemlib_utils_is_lowercase('1') == 0);

        ensure(chemlib_utils_is_lowercase('a') == 1);
        ensure(chemlib_utils_is_lowercase('b') == 1);
        ensure(chemlib_utils_is_lowercase('z') == 1);
        ensure(chemlib_utils_is_lowercase('h') == 1);

        ensure(chemlib_utils_is_lowercase('A') == 0);
        ensure(chemlib_utils_is_lowercase('B') == 0);
        ensure(chemlib_utils_is_lowercase('Z') == 0);
        ensure(chemlib_utils_is_lowercase('H') == 0);
    }

    return 0;
}