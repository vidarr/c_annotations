# c_annotations

Tiny collection of C preprocessor macros to annotate c code.

Define some useful code annotations.
All annotations aim at 2 things:
   1. Make the code readable by replacing obfuscated bits like (void)(arg) with UNUSED(arg);
   2. Have the compiler / the program make you hint at stuff when DEBUG is set

# Usage

Just include the header `annotations.h` in your source file.

# Some examples

For a complete documentation, see the header `annotations.h` .

## UNUSED()

`UNUSED()` declares a function argument as UNUSED:

```c

void function_with_unused_arg(int i) {

    UNUSED(i);
    printf("I am not using my argument!\n");

}

```

This inhibits compiler warnings and is useful for e.g. implementin callbacks
that demand a defined prototype.
Compare to a more 'direct' approach:

```c

void function_with_unused_arg(int i) {

    (void)(i);
    printf("I am not using my argument!\n");

}

```

Would you have seen immediately what the `(void)(i);` is supposed to do?

## DEPRECATED()

Declares a function as deprecated:

```c

DEPRECATED("Use useless_function() instead")
void deprecated_function () {
    printf("I am deprecated!");
}

```

On supported compilers (currently GCC), this produces a warning when using the function, possibly
outputting `msg` (if the compiler supports this).
