# Use-After-Free in C vs. Ownership in Rust

## Overview

This project was created for COMP 211 Checkoff 3:
Data Representation Exploration.

I explored how use-after-free errors occur in C and
how Rust's ownership and borrowing rules help prevent
similar memory safety problems at compile time.

## What I Explored

1. How dynamically allocated memory is managed
   using malloc() and free() in C.
2. How dangling pointers can lead to use-after-free.
3. Rust's three fundamental ownership rules.
4. Pointer copying in C vs. ownership moves in Rust.
5. How borrowing allows safe shared access.

## Key Discoveries

### 1. Use-after-free in C

Freeing dynamically allocated memory does not
automatically invalidate other pointers referring
to that memory. Accessing freed memory results in
undefined behavior.

### 2. Rust ownership

Rust follows three main ownership rules:
- Each value has an owner.
- Each value has only one owner at a time.
- When the owner goes out of scope, it is dropped.

For heap-allocated values such as String, moving
ownership prevents the previous owner from
accessing the resource.

### 3. Ownership vs. setting a pointer to NULL

Setting one C pointer to NULL does not invalidate
other copies. Rust tracks ownership and borrowing
at compile time.

### 4. Borrowing allows shared access

Rust allows multiple immutable references to the
same value. Borrowing rules prevent unsafe conflicts
between mutable and immutable access.

## Code Examples

- `code/use_after_free.c`: A use-after-free bug in C.
- `code/ownership.rs`: Ownership transfer in Rust.
- `code/borrowing.rs`: Safe shared borrowing.

### Running the C example

Requires Clang with AddressSanitizer support.

```bash
clang -g -fsanitize=address code/use_after_free.c -o use_after_free
./use_after_free
```

The C example intentionally contains undefined
behavior. AddressSanitizer should report the error.

### Running the Rust examples

Requires the Rust compiler.

```bash
rustc code/ownership.rs -o ownership
./ownership
rustc code/borrowing.rs -o borrowing
./borrowing
```

The ownership example contains a commented-out
line that produces a compiler error if uncommented.

## Presentation

See `slides/Checkoff3_Rust_Ownership.pptx`.

## References

- [Rust Book: Ownership](https://doc.rust-lang.org/book/ch04-01-what-is-ownership.html)
- [Rust Book: Borrowing](https://doc.rust-lang.org/book/ch04-02-references-and-borrowing.html)
- [Rust By Example: Moves](https://doc.rust-lang.org/rust-by-example/scope/move.html)

## Conclusion

My most important takeaway is that Rust approaches
memory safety differently from C. Instead of relying
entirely on programmers to manage pointers correctly,
Rust checks ownership and borrowing rules during
compilation. This prevents many use-after-free errors
without requiring a garbage collector.
  
