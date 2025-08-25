# CSI281 Assignment 9

In this assignment you will be implementing Dijkstra's algorithm on a weighted graph class. You will also be adding a test case (in addition to two existing test cases) to prove your implementation works.

You should follow the pseudo-code we went over in class. You may not add any additional methods to `WeightedGraph`. The beginning and end of the `dijkstra()` function are already defined. You must reuse this code.

Don't forget to add your test case to the bottom of `test.cpp`!

NOTE: Because the code you need to add to `dijkstra()` is only about 10-15 lines, unlike in previous assignments, I will not be helping you write these few lines. I am happy to answer as many conceptual questions about how the rest of the code works, or how Dijkstra's algorithm works as you would like, but there is so little code to write here, that I don't think it's appropriate for me to help you write it. Again, I am not saying I am not open to questions, just that I won't help you write the literal code for `dijkstra()`.

NOTE: If you prefer to use different pseudocode than we went over in class (Python code really), feel free to. Just cite it next to your `dijkstra()` method. Please do not look at other C++ implementations of dijkstra's algorithm. 

REMINDER: In addition to being covered in class, Dijkstra's algorithm was covered in Chapter 7 of your book.

## Basic Instructions

1. Read [README.md](../README.md) in the root directory of this repository.
2. Implement the missing parts where it says "YOUR CODE HERE"
3. Push your code to GitHub (Don't push your binary files—the purpose of the prior step is to remove them). Every push will be automatically tested on both Windows (nmake/MSVC) and Linux (GNUMake/GCC) through a GitHub Action. You will know your code is correct when you see a green check mark next to the commit on GitHub.
4. Submit the URL to your private repository on Canvas. Submit even if you are not passing all tests so you can get partial credit.

## Standard Library Restrictions

There are no standard library restrictions.

## Directory Structure and Files

- `/` Main directory including this `README.md`, the build scripts, and the make files
- `/src` Source files, some of which you should modify and some of which you should not.

### Specific Files

*indicates do not modify
&indicates you must modify

- `README.md`* this file

- `src/WeightedGraph.h`& the `WeightedGraph` class
- `src/main.cpp` the main file that runs the tests and makes the chart
- `src/test.cpp`& the unit tests to prove your code works

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

