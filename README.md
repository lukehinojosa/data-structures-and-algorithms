# CSI281

Central repository for all assignments for the CSI281 course. 

This material was originally developed by [@davecom](https://github.com/davecom), and modified by [@tolstenko](https://github.com/tolstenko). 

## Summary

- [CSI281](#csi281)
  - [List of Assignments](#list-of-assignments) 
  - [Basic instructions](#basic-instructions)
  - [General recommendations](#general-recommendations)
  - [Directory Structure and Files](#directory-structure-and-files)
  - [Building and Running](#building-and-running)
    - [IDEs](#ides)
    - [Terminal](#terminal)

## List of Assignments

- [Assignment 01](assignment01/README.md)
- [Assignment 02](assignment02/README.md)
- [Assignment 03](assignment03/README.md)
- [Assignment 04](assignment04/README.md)
- [Assignment 05](assignment05/README.md)
- [Assignment 06](assignment06/README.md)
- [Assignment 07](assignment07/README.md)
- [Assignment 08](assignment08/README.md)
- [Assignment 09](assignment09/README.md)
- [Assignment 10](assignment10/README.md)
- [Assignment 11](assignment11/README.md)
- [Assignment 12](assignment12/README.md)

## Basic instructions

1. Create your own **private** repository from this repo by hitting the "Use this template" button at the top right of the page.
    - Forks are discouraged because of visibility issues.
2. Add me ([@tolstenko](https://github.com/tolstenko)) as a collaborator on your **private** repository;
3. Clone your repository to your local machine;
4. Open your favorite IDE (CLion, Visual Studio) and open as CMake project;
5. Enable / disable the assignments you want to work on in the `CMakeLists.txt` file;
6. Select as target your assignment (e.g. `assignment01`);
7. Implement the missing parts where it says "YOUR CODE HERE";
8. Run the tests;
9. Commit and push your code to GitHub;
10. Submit the URL to your private repository on Canvas. Submit even if you are not passing all tests so you can get partial credit.

## General recommendations

* You are encouraged to also make commits much more frequently than this, earlier in development. Just don't be surprised when seeing an X on GitHub since not all of the tests will pass;
* Remember to keep your repo in sync with the original one by pulling changes from the original repo weekly;
* Run the build target `fix-format`, or check the github-ci result to ensure you are following the `google` styleguide;

## Directory Structure and Files

- `/`: Main directory including this `README.md`, and the `LICENSE.md` file;
- `/lib`: Libraries for drawing the charts. There's no need to touch this;
- `/cmake`: CMake extra files. Don't touch this;
- `/assignmentXX`: assignment root directory. Read the child `README.md` file for more details;
- `/assignmentXX/README.md`: assignment description and instructions;
- `/assignmentXX/CMakeLists.txt`: CMake file for the specific assignment. Don't touch this;
- `/assignmentXX/questions.txt`: assignment questions that you should answer if present;
- `/CMakelists.txt`: Root CMake file, change the last lines of it to enable / disable assignments you want to work on here. By default, all assignments are enabled. You should open/target this CMake file as a project in your IDE.

## Building and Running

### IDEs

note: Tested on CLion and Visual Studio.

1. Open the `CMakeLists.txt` file as a project in your preferred IDE;
2. On the targets, select the assignment you want to work on (e.g. `assignment01`);
3. Build and run the target;

Some IDEs (e.g. CLion) allow you to run the automated tests directly from the IDE and debug them.

### Terminal

Open your terminal app and navigate to the root directory of your repository. 

To configure the project using  `build` as cmake build folder, run:

```bash
cmake -H . -B build
```

To build a specific assignment where XX is the number of the assignment, run:

```bash
cmake --build build --target assignmentXX
```

To run the assignment (for windows replace `/` for `\`, and add `.exe` at the end of the file), run:

```bash
./build/assignmentXX/assignmentXX
```

To build the assignment tests, run:

```bash
cmake --build build --target assignmentXX_tests
```

To run the assignment tests, run:

```bash
./build/assignments/assignmentXX/assignmentXX_tests
```