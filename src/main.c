#include "scef.h"
#include <locale.h>
#include <wchar.h>
#include <wctype.h>

wint_t check_special_cases(wint_t first_char, wint_t second_char) {
    for (long unsigned int i = 0; i < SPECIAL_CASES_COUNT; i++) {
        if (first_char == first_chars[i] && second_char == second_chars[i]) {
            return result_chars[i];
        }
    }
    return WEOF;
}

wint_t combine_chars(enum DiacriticType dtype, wint_t ch) {
    switch (dtype) {
    case HOOK:
        return combine_with_hook(ch);
    case LENGTH_MARK:
        return combine_with_length_mark(ch);
    case CIRCLE:
        return combine_with_circle(ch);
    case UMLAUT:
        return combine_with_umlaut(ch);
    default:
        return WEOF;
    }
}

enum DiacriticType get_diacritic_type(wint_t ch) {
    switch (ch) {
    case L'ˇ':
        return HOOK;
    case L'´':
        return LENGTH_MARK;
    case L'˚':
        return CIRCLE;
    case L'¨':
    case L'˝':
        return UMLAUT;
    default:
        return NONE;
    }
}

CombinedReturn process_chars(wint_t first_char, wint_t second_char) {
    CombinedReturn not_combined = {False, first_char};
    enum DiacriticType dtype = get_diacritic_type(first_char);

    wint_t result;
    if (dtype != NONE && (result = combine_chars(dtype, second_char)) != WEOF) {
        CombinedReturn combined = {True, result};
        return combined;
    }

    wint_t special_case = check_special_cases(first_char, second_char);
    if (special_case != WEOF) {
        CombinedReturn combined = {True, special_case};
        return combined;
    }
    return not_combined;
}

int main() {
    setlocale(LC_CTYPE, "");

    wint_t first_char = getwchar();
    wint_t second_char = getwchar();
    while (first_char != WEOF) {
        CombinedReturn result = process_chars(first_char, second_char);
        wprintf(L"%lc", result.character);

        if (result.is_combined == True) {
            first_char = getwchar();
            second_char = getwchar();
        } else {
            first_char = second_char;
            second_char = getwchar();
        }
    }

    return 0;
}
