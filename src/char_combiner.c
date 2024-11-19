#include <wchar.h>
#include <wctype.h>

wint_t combine_with_umlaut(wint_t ch) {
    switch (ch) {
    case L'a':
        return L'ä';
    case L'A':
        return L'Ä';
    case L'o':
        return L'ö';
    case L'O':
        return L'Ö';
    case L'u':
        return L'ü';
    case L'U':
        return L'Ü';
    default:
        return WEOF;
    }
}

wint_t combine_with_circle(wint_t ch) {
    switch (ch) {
    case L'u':
        return L'ů';
    case L'U':
        return L'Ů';
    default:
        return WEOF;
    }
}

wint_t combine_with_length_mark(wint_t ch) {
    switch (ch) {
    case L'a':
        return L'á';
    case L'A':
        return L'Á';
    case L'e':
        return L'é';
    case L'E':
        return L'É';
    case L'ı':
    case L'i':
        return L'í';
    case L'I':
        return L'Í';
    case L'y':
        return L'ý';
    case L'Y':
        return L'Ý';
    case L'o':
        return L'ó';
    case L'O':
        return L'Ó';
    case L'u':
        return L'ú';
    case L'U':
        return L'Ú';
    default:
        return WEOF;
    }
}

wint_t combine_with_hook(wint_t ch) {
    switch (ch) {
    case L'c':
        return L'č';
    case L'C':
        return L'Č';
    case L'd':
        return L'ď';
    case L'D':
        return L'Ď';
    case L'e':
        return L'ě';
    case L'E':
        return L'Ě';
    case L'n':
        return L'ň';
    case L'N':
        return L'Ň';
    case L'r':
        return L'ř';
    case L'R':
        return L'Ř';
    case L's':
        return L'š';
    case L'S':
        return L'Š';
    case L't':
        return L'ť';
    case L'T':
        return L'Ť';
    case L'z':
        return L'ž';
    case L'Z':
        return L'Ž';
    default:
        return WEOF;
    }
}
