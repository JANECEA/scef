#include "scef.h"
#include <locale.h>
#include <wchar.h>
#include <wctype.h>

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
        return UMLAUT;
    default:
        return NONE;
    }
}

void process_char(wint_t ch) {
    enum DiacriticType dtype;
    if ((dtype = get_diacritic_type(ch)) == NONE) {
        wprintf(L"%lc", ch);
        return;
    }
    wint_t diacritic = ch;
    wint_t next_char;
    if ((next_char = getwchar()) == WEOF) {
        wprintf(L"%lc", diacritic);
        return;
    }

    wint_t result = combine_chars(dtype, next_char);
    if (result != WEOF)
        wprintf(L"%lc", result);
    else
        wprintf(L"%lc%lc", diacritic, next_char);
}

int main() {
    setlocale(LC_CTYPE, "");

    wint_t ch;
    while ((ch = getwchar()) != WEOF)
        process_char(ch);

    return 0;
}
