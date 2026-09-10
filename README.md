# libcds

`libcds` is a small data structures library written in C.

I created this project mainly to practice the implementation of common data structures and to learn more about how C libraries are organized, compiled and linked.

The library is built as a static library (`libcds.a`) and uses opaque types to keep implementation details separate from the public API.

## Data Structures

* Dynamic Array (Vector)
* Linked List
* Stack
* Queue
* Hash Table
* Binary Search Tree (BST)
* AVL Tree
* Trie

## Project Structure

```text
libcds/
├── include/      # Public headers
├── src/          # Implementations
├── examples/     # Usage examples
├── build/        # Generated object files (ignored by Git)
├── Makefile
├── LICENSE
└── README.md
```

The `libcds.h` header can be used to include the complete public API.

## Building

Clone the repository and run:

```bash
make
```

This generates the static library:

```text
libcds.a
```

To remove generated files:

```bash
make clean
```

## Usage

Include the library header:

```c
#include "libcds.h"
```

For example:

```c
#include "libcds.h"
#include <stdio.h>

int main(void) {
    CDSVector *vector = cds_vector_create();

    if (vector == NULL) {
        return 1;
    }

    cds_vector_push_back(vector, 10);
    cds_vector_push_back(vector, 20);
    cds_vector_push_back(vector, 30);

    int value;

    if (cds_vector_at(vector, 1, &value)) {
        printf("%d\n", value);
    }

    cds_vector_destroy(vector);

    return 0;
}
```

Compile it with:

```bash
gcc main.c -Iinclude libcds.a -o main
```

Then run:

```bash
./main
```

You can find more examples in the `examples/` directory.

## Implementation

The library uses opaque types, with their internal structures defined only in the source files.

For example, the public headers contain declarations such as:

```c
typedef struct CDSVector CDSVector;
```

Memory is dynamically allocated when necessary, and each data structure provides its own create and destroy functions.

The project is compiled with `-Wall`, `-Wextra` and `-Wpedantic`, and the examples were checked with Valgrind for memory errors and leaks.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
