# C-Algorithms

Data structures and memory exercises in C from RIT's CMPE-380 (Applied Programming in C). Each project
builds on the last, ending with a timed comparison of searching a linked list against a dynamic array.

| Project | Topics |
| --- | --- |
| [`Project_02`](Project_02) | Structs vs. unions, `malloc` and pointers, and a first growable `DynamicArrays` module |
| [`Project_03`](Project_03) | Finishing `DynamicArrays` (create, push, destroy) and loading a word list into it, tested against the English word lists in the folder |
| [`Project_04`](Project_04) | Singly linked lists: a `LinkedLists` module with add to back, remove from front and destroy |
| [`Project_05`](Project_05) | Makefiles, and `TestSearch`, which times a word search in both structures over `engWords.txt` and checks for leaks with Valgrind |

## Building

Needs `gcc` and `make`, plus Valgrind for the memory check (Linux or WSL).

```sh
cd Project_05
make            # builds TestSearch with -Wall -std=c99 -pedantic
make test       # searches engWords.txt for "space" and a word that isn't there, output in out.txt
make mem        # runs the same search under Valgrind, report in mem.txt
make clean
```

The earlier projects have no Makefile. Compile the files you want directly, for example
`gcc -Wall -std=c99 Project_04/LinkedLists/*.c -o linkedlists`.
