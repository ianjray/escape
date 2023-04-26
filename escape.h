#ifndef ESCAPE__H
#define ESCAPE__H

/// Escape string @c s.
/// Replace backslash with a backslash-backslash sequence.
/// Replace newline with an backslash-n sequence.
/// @return Reference to allocated string.
/// @note Memory ownership: Caller must free() the returned pointer.
char *escape(const char *s);

/// Unescape string @c s in-place.
/// Replace backslash-backslash sequence with backslash.
/// Replace backslash-n sequence with newline.
/// @return Reference to given string.
char *unescape(char *s);

#endif
