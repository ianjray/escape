# escape
Simple shell-style escape of backslash and newline

## Installation

```sh
./configure
make
sudo make install
```

A `pkg-config` file is installed, so applications can use:

```sh
cc $(pkg-config --cflags --libs escape) ...
```

## Requirements

* C99 or later
* POSIX-compatible system

## Thread Safety

The library does not maintain global or shared mutable state and is safe to use concurrently provided that access to the underlying memory is properly synchronized.
