# Termo CLI

This is a legacy project developed during my initial studies of C++ syntax and logic. It is maintained here as a record of my technical evolution.
This is a old project, made when I was learning basics C++ syntax and logic; after many months now I can see so much errors that I could fix, but now I am focused to learn OpenGL; There are others projects, I am regularly practicing. Maybe I refactor it.

## Project Status
While I recognize architectural flaws in this early code, my current development focus has shifted to Computer Graphics and OpenGL. This repository remains a candidate for a future refactor to demonstrate modern C++ standards, but is currently provided "as-is".

## Architecture
The project is structured to separate execution logic from static resources:

* src/: Source code (.cpp) and headers (.h).
* data/: Word dictionaries, rulesets, and persistence logs (score.txt and AllPlays.txt).

## Build and Execution
The application uses relative paths (`../data/`). To ensure resources are located correctly, the binary must be executed from the `src` directory.

Build (G++):
g++ main.cpp -o termo

Execution:
./termo

## Features
* File-based word sorting using std::mt19937.
* Game state persistence (Session and Historical logs).
* Cross-platform terminal clearing (Windows/Unix).

## License
Educational purposes only.
