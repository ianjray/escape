#ifndef ESCAPE__H
#define ESCAPE__H

/// @discussion Escape string @c s.
/// Replace backslash with a backslash-backslash sequence.
/// Replace newline with an backslash-n sequence.
/// @return Reference to allocated string.
char *escape(const char *s);

/// @discussion Unescape string @c s.
/// Replace backslash-backslash sequence with backslash.
/// Replace backslash-n sequence with newline.
/// @return Reference to allocated string.
char *unescape(const char *s);

#endif
