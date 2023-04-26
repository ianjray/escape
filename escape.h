#ifndef ESCAPE__H
#define ESCAPE__H

/// @discussion Escape string @c s.
/// Replace backslash with a backslash-backslash sequence.
/// Replace newline with an backslash-n sequence.
/// @return Reference to allocated string.
char *escape(const char *s);

/// @discussion Un-escape string @c s in-place.
/// Replace backslash-backslash sequence with backslash.
/// Replace backslash-n sequence with newline.
/// @return Reference to given string.
char *unescape(char *s);

#endif
