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

enum Combined {
    True,
    False,
};

typedef struct {
    const enum Combined is_combined;
    const wint_t character;
} CombinedReturn;

static const wint_t first_chars[] = {L't', L'T'};
static const wint_t second_chars[] = {L'’', L'’'};
static const wint_t result_chars[] = {L'ť', L'Ť'};

#define SPECIAL_CASES_COUNT (sizeof(result_chars) / sizeof(result_chars[0]))

wint_t combine_with_hook(wint_t ch);

wint_t combine_with_length_mark(wint_t ch);

wint_t combine_with_circle(wint_t ch);

wint_t combine_with_umlaut(wint_t ch);

#endif
