# CSI281 Assignment 3

In this assignment you will be creating your own implementations of a linked list and a dynamic array that follow a common interface called `Collection`. At the top of each file is a note about whether or not you should modify it. Please only modify the files that are indicated as being okay to modify.

The goal of this assignment is to write both data structures and to then test them.

## Basic Instructions

1. Read [README.md](../README.md) in the root directory of this repository.
2. Implement the missing parts where it says "YOUR CODE HERE".
3. Push your code to GitHub (Don't push your binary files—the purpose of the prior step is to remove them). Every push will be automatically tested on both Windows (nmake/MSVC) and Linux (GNUMake/GCC) through a GitHub Action. You will know your code is correct when you see a green check mark next to the commit on GitHub.
4. Submit the URL to your private repository on Canvas. Submit even if you are not passing all tests so you can get partial credit.

## Standard Library Restrictions

Please do not use the data structures included in the standard library. For example, do not use `vector` and do not use `list`. You may use the rest of the standard library as much as you would like.

## Directory Structure and Files

- `./` Main directory including this `README.md`, the build scripts.
- `./src` Source files, some of which you should modify and some of which you should not.
- `./CMakelists.txt` CMake file for building on macOS, GNU/Linux and Windows

### Specific Files

*indicates do not modify
&indicates you must modify

- `README.md`* this file
- `LICENSE` MIT License

- `src/Collection.h`* the abstract base class that `LinkedList` and `DynamicArray` are subclasses of
- `src/DynamicArray.h`& the `DynamicArray` class
- `src/LinkedList.h`& the `LinkedList` class
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
