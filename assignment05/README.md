# CSI281 Assignment 5

For this assignment, you will be implementing merge sort, quicksort, a modified insertion sort, and a hybrid sort. You will also need to make these sorts perform within certain performance parameters.

You may look at pseudo code such as that provided in the reading or on Wikipedia, but please do yourself a favor and implement these functions yourself without copying someone else's C++. As always, cite your sources.

NOTE: For this assignment you are not allowed to add additional functions to the source files (even utility functions). Please just fill-in the provided function templates.

NOTE: Please be sure to carefully read the requirements in the comments above each function. There are more specific requirements for this assignment than some in the past.

## Basic Instructions

1. Read [README.md](../README.md) in the root directory of this repository.
2. Implement the missing parts where it says "YOUR CODE HERE"
   if you are not passing all tests so you can get partial credit.
3. Answer all of the questions in `questions.txt` in your own file `answers.txt`.
4. Push your code to GitHub (Don't push your binary files—the purpose of the prior step is to remove them). Every push will be automatically tested on both Windows (nmake/MSVC) and Linux (GNUMake/GCC) through a GitHub Action. You will know your code is correct when you see a green check mark next to the commit on GitHub.
5. Submit the URL to your private repository on Canvas. Submit even if you are not passing all tests so you can get partial credit.

## Standard Library Restrictions

Please do not use the standard library functions `sort()` or `qsort()` for this assignment. You can use the rest of the standard library as much as you want.

## Directory Structure and Files

- `./` Main directory including this `README.md`, the build scripts, and `questions.txt`.
- `./src` Source files, some of which you should modify and some of which you should not.
- `./CMakelists.txt` CMake file for building on macOS, GNU/Linux and Windows

### Specific Files

*indicates do not modify
&indicates you must modify
%indicates you must create

- `GNUMakefile`* make file for GNU Make on macOS and GNU/Linux
- `Makefile`* make file for nmake/Visual Studio on Windows
- `README.md`* this file
- `LICENSE` MIT License

- `src/sort.h`& the sort functions you must implement
- `src/main.cpp` the main file that runs the tests and makes the charts
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
