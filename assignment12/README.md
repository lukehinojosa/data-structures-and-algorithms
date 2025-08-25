# CSI281 Assignment 12

For this assignment, you will be implementing a priority queue backed by a binary max-heap. The tests will ensure that your priority queue works correctly and its pop() outperforms the standard library's equivalent functions for vector (finding the max element with a linear search and erasing it). You will also see an SVG chart generated with this comparison.

This assignment is heavily modeled on the pseudocode from Chapter 6 of Introduction to Algorithms. Please use the pseudocode as your reference. The one tweak we are making, is our binary heap starts at index 0, wheras the binary heap in the chapter started at index 1. Macros for parent(), left(), and right() are provided.

NOTE: For this assignment you are not allowed to add additional functions to the source files (even utility functions). Please just fill-in the provided function templates.

## Basic Instructions

1. Read [README.md](../README.md) in the root directory of this repository.
2. Implement the missing parts where it says "YOUR CODE HERE"
3. Push your code to GitHub (Don't push your binary files—the purpose of the prior step is to remove them). Every push will be automatically tested on both Windows (nmake/MSVC) and Linux (GNUMake/GCC) through a GitHub Action. You will know your code is correct when you see a green check mark next to the commit on GitHub.
4. Submit the URL to your private repository on Canvas. Submit even if you are not passing all tests so you can get partial credit.

## Standard Library Restrictions

All of the standard library is available to you except for the standard library's own priority queue.

## Directory Structure and Files

- `/` Main directory including this `README.md`, the build scripts, and will have the generated SVG search chart.
- `/src` Source files, some of which you should modify and some of which you should not.

### Specific Files

*indicates do not modify
&indicates you must modify

- `README.md`* this file

- `src/PriorityQueue.h`& the PriorityQueue class you need to finish implementing
- `src/timing.h`* a function to help compare PriorityQueue.pop() with vector equivalents
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

