# Geometric Shapes Management in SVG

## Description

This project is a C program that allows users to create and manage geometric shapes in SVG format.

The program provides the following features:

- Create rectangles and squares.
- Create ellipses and circles.
- Create lines.
- Modify existing shapes.
- Delete shapes.
- View shapes by opening their SVG files in Visual Studio Code.

Each shape is stored in memory and exported to an SVG file.

## Features

- Interactive menu.
- User input validation.
- Maximum capacity of 100 shapes.
- Automatic SVG file generation.
- Shape modification and deletion.
- Code organized into multiple files for better readability and maintainability.

## Requirements

- GCC compiler
- Make
- Visual Studio Code
- Linux operating system

## Compilation

To compile the project, open a terminal in the project directory and run:

```bash
make
```

To remove the compiled files, run:

```bash
make clean
```

## Execution

After compiling the project, run the program with:

```bash
./programme
```

## Usage

The main menu provides the following options:

1. Create a shape.
2. Modify an existing shape.
3. Delete a shape.
4. View a shape.
5. Exit the program.

Follow the instructions displayed in the terminal to enter the coordinates and dimensions of each shape.

## Project Structure

- `main.c`: Main menu and program entry point.
- `creation.c`: Creation of new shapes.
- `modification.c`: Modification of existing shapes.
- `suppression.c`: Deletion of shapes.
- `visualisation.c`: Opening of SVG files.
- `forme.c` and `forme.h`: Definition and storage of shape data structures.
- `carre.c` and `carre.h`: Generation of rectangles and squares.
- `cercle.c` and `cercle.h`: Generation of circles and ellipses.
- `ligne.c` and `ligne.h`: Generation of lines.
- `saisie.c` and `saisie.h`: User input handling.
- `affichage.c` and `affichage.h`: Display of the list of shapes.
- `svg.c` and `svg.h`: SVG file generation.
- `Makefile`: Build automation.

## Technologies Used

- C programming language
- SVG (Scalable Vector Graphics)
- GCC
- Make

## Notes

Shapes are stored in memory while the program is running. SVG files are generated in the project directory.

This project provides an introduction to C programming, organizing code across multiple files, validating user input, and generating SVG files.