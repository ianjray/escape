#include "escape.h"

#include <stdlib.h>
#include <string.h>

enum {
    BACKSLASH = '\\',
    NEWLINE   = '\n'
};

char *escape(const char *s)
{
    const char *p = NULL;
    size_t n = 0;
    char *e = NULL;

    if (!s) {
        return NULL;
    }

    for (p = s; *p; ++p) {
        if (*p == BACKSLASH || *p == NEWLINE) {
            // These characters will be escaped.
            ++n;
        }
        ++n;
    }

    e = (char *)malloc(n + 1);
    if (e) {
        char *q = e;
        for (; *s; ++s) {
            if (*s == BACKSLASH) {
                *q++ = BACKSLASH;
                *q++ = BACKSLASH;
            } else if (*s == NEWLINE) {
                *q++ = BACKSLASH;
                *q++ = 'n';
            } else {
                *q++ = *s;
            }
        }
        *q++ = 0;
    }

    return e;
}

char *unescape(const char *s)
{
    const char *p = NULL;
    size_t n = 0;
    char *u = NULL;

    if (!s) {
        return NULL;
    }

    for (p = s; *p; ++p) {
        if (*p == BACKSLASH) {
            ++p;
            if (!*p) {
                break;
            }
        }
        ++n;
    }

    u = (char *)malloc(n + 1);
    if (u) {
        char *q = u;
        for (; *s; ++s) {
            if (*s == BACKSLASH) {
                ++s;
                if (!*s) {
                    break;
                }

                if (*s == 'n') {
                    *q++ = NEWLINE;
                } else {
                    *q++ = *s;
                }
            } else {
                *q++ = *s;
            }
        }
        *q++ = 0;
    }

    return u;
}
