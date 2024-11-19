#ifndef COMBINE_CHARS_H
#define COMBINE_CHARS_H

#include <wctype.h>

enum DiacriticType {
    HOOK,
    LENGTH_MARK,
    CIRCLE,
    UMLAUT,
    NONE,
};

wint_t combine_with_hook(wint_t ch);

wint_t combine_with_length_mark(wint_t ch);

wint_t combine_with_circle(wint_t ch);

wint_t combine_with_umlaut(wint_t ch);

#endif
