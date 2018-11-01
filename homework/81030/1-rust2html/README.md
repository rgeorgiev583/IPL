# Rust syntax highlighter

This is an implementation of a syntax highlighter for the Rust programming language (`rust2html.c`).  It takes a Rust program as input (or a Rust source file as an argument) and outputs a HTML page with a colorized version of the program.  The C source is generated from a Flex-based scanner (`rust2html.flex`).

This is a solution to the first homework assignment.

## Generating and building

On Unix-like OS:

    flex rust2html.l
    cc -o rust2html lex.yy.c

## Usage

This will generate a HTML document named `example.html` with a colorized version of the `example.rs` Rust program:

    ./rust2html example.rs > example.html
