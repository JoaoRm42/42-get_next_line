# Get Next Line

Welcome to the Get Next Line (GNL) project repository! This project is part of the 42 curriculum, and its goal is to implement a function that reads a line from a file descriptor, a fundamental utility for handling file input in C.

## Table of Contents
- [Introduction](#introduction)
- [Project Objectives](#project-objectives)
- [Requirements](#requirements)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [Acknowledgments](#acknowledgments)
- [Grade](#grade)

## Introduction

The Get Next Line project is designed to help students understand file I/O operations in C by implementing a function that reads a line from a file descriptor. This function will be useful for handling file input in various projects.

## Project Objectives

- Implement a function that reads a line from a file descriptor.
- Handle different edge cases and errors.
- Understand and manage dynamic memory allocation.
- Gain deeper insights into file I/O operations in C.

## Requirements

- A Unix-based operating system (Linux or macOS).
- GCC compiler.
- Basic understanding of C programming and file I/O operations.

## Project Structure

Here's a brief overview of the project structure:

```
.
├── get_next_line.h
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line_bonus.h
├── get_next_line_bonus.c
├── get_next_line_utils_bonus.c
└── README.md
```


- **includes/**: Contains the header file `get_next_line.h`.
- **srcs/**: Contains the source files for the `get_next_line` function and its utility functions.
- **tests/**: Contains test files to validate the functionality of the project.
- **Makefile**: Used to compile the project.
- **README.md**: This file.

## Installation

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/joaoped2-42PORTO/42-get_next_line.git
    cd 42-get_next_line
    ```

2. **Compile the Project**:
   
   Mandatory
    ```bash
    cc -Wall -Wextra -Werror -g get_next_line.c get_next_line_utils.c
    ```
   Bonus
    ```bash
    cc -Wall -Wextra -Werror -g get_next_line_bonus.c get_next_line_utils_bonus.c
    ```

    This will create the necessary object files and a test executable (if provided in the Makefile).

## Usage

To use the `get_next_line` function in your own projects, include the `get_next_line.h` header file and link the necessary object files during compilation.

1. **Include the Header**:
    ```c
    #include "get_next_line.h"
    ```

2. **Link the Object Files**:
    ```bash
    gcc -o myprogram myprogram.c get_next_line.o get_next_line_utils.o
    ```

3. **Run the Program**:
    ```bash
    ./myprogram
    ```

## Contributing

Contributions are welcome! If you have any suggestions or improvements, feel free to create an issue or submit a pull request. Please ensure that your contributions adhere to the coding standards and guidelines of the project.


## Acknowledgments

- The 42 Network for providing the inspiration and resources for this project.
- The C programming community for their excellent documentation and support.
- All contributors who have helped improve this project.

##Grade
- Norminette: Ok!
- Grade: 125/100
  
---

Happy coding!
