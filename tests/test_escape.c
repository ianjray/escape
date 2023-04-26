#include "escape.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *e;
    char *u;

    e = escape(NULL);
    assert(e == NULL);
    u = unescape(NULL);
    assert(u == NULL);

    e = escape("");
    assert(0 == strcmp(e, ""));
    u = unescape(e);
    assert(u == e);
    assert(0 == strcmp(u, ""));
    free(e);

    e = escape("abc");
    assert(0 == strcmp(e, "abc"));
    u = unescape(e);
    assert(u == e);
    assert(0 == strcmp(u, "abc"));
    free(e);

    u = unescape(strdup("abc\\"));
    assert(0 == strcmp(u, "abc"));
    free(u);

    e = escape("a\tbc");
    assert(0 == strcmp(e, "a\tbc"));
    u = unescape(e);
    assert(u == e);
    assert(0 == strcmp(u, "a\tbc"));
    free(e);

    e = escape("a\nbc\\");
    assert(0 == strcmp(e, "a\\nbc\\\\"));
    u = unescape(e);
    assert(u == e);
    assert(0 == strcmp(u, "a\nbc\\"));
    free(e);

    e = escape("a:\\b\nc");
    assert(0 == strcmp(e, "a:\\\\b\\nc"));
    u = unescape(e);
    assert(u == e);
    assert(0 == strcmp(u, "a:\\b\nc"));
    free(e);
}
