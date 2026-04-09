#pragma once

#undef strtok

char *strtok(char * __restrict str, const char * __restrict delim);

char *strtok(char * __restrict str, const char * __restrict delim) {
    static char *last = nullptr;
    if (str == nullptr) {
        str = last;
    }
    if (str == nullptr) {
        return nullptr;
    }

    bool is_delim[256] = {false};
    for (const char *d = delim; *d != '\0'; ++d) {
        is_delim[(unsigned char)(*d)] = true;
    }

    char *s = str;
    while (*s != '\0' && is_delim[(unsigned char)(*s)]) {
        ++s;
    }

    if (*s == '\0') {
        last = nullptr;
        return nullptr;
    }

    char *token_start = s;

    while (*s != '\0' && !is_delim[(unsigned char)(*s)]) {
        ++s;
    }

    if (*s == '\0') {
        last = nullptr;
    } else {
        *s = '\0';
        last = s + 1;
    }

    return token_start;
}