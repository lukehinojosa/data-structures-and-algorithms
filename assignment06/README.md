# CSI281 Assignment 6

In this assignment you will be creating your own implementations of a hash table. At the top of each file is a note about whether or not you should modify it. Please only modify the files that are indicated as being okay to modify.

You can effectively use a lot of standard library constructs in this assignment including `list`, `pair`, `find_if()`, `remove_if()`, and `optional`.

## Basic Instructions

1. Read [README.md](../README.md) in the root directory of this repository.
2. Implement the missing parts where it says "YOUR CODE HERE"
   if you are not passing all tests so you can get partial credit.
3. Submit the URL to your private repository on Canvas. Submit even if you are not passing all tests so you can get partial credit.

## Standard Library Restrictions

Please do not use the hash table or dictionary like data structures included in the standard library. For example, do not use `map` and do not use `unordered_map`. You may use the rest of the standard library as much as you would like (and you are encouraged to).

## Directory Structure and Files

- `./` Main directory including this `README.md`, the build scripts, and the make files.
- `./src` Source files, some of which you should modify and some of which you should not.
- `./CMakelists.txt` CMake file for building on macOS, GNU/Linux and Windows

### Specific Files

*indicates do not modify
&indicates you must modify

- `README.md`* this file
- `LICENSE` MIT License

- `src/HashTable.h`& the `HashTable` class
- `src/main.cpp` the main file that runs the tests and makes the chart
- `src/test.cpp`* the unit tests to prove your code works

## Checklist for Submission

- [ ] Did you add me ([@tolstenko](https://github.com/tolstenko)) as a collaborator on the repository?
- [ ] Did you replace every area that said "YOUR CODE HERE" with your code?
- [ ] Did you ensure you are passing all of the unit tests? Do you see a green check mark on GitHub?
- [ ] Did you cite all sources, especially any place that you copied code from? Put code citations right next to where you inserted them.
- [ ] Did you add sufficient comments?
- [ ] Did you double check your code for good style?
- [ ] Did you remember to free any memory you manually allocated on the heap?
- [ ] Did you put your name below mine at the top of any files you modified and any other appropriate places?
- [ ] Did you try cleaning, building, and running once to make sure everything is in working order before submitting?
- [ ] If you were working with an IDE, did you test building on the command line with make or nmake? I will go by the tests of your work with make or nmake done automatically by the GitHub action.
- [ ] Did you check the repository is free of your object files and other garbage and just contains source files?
- [ ] Did you submit the URL to your repository on Canvas?
