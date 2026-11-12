# Terminal Grid Movement Game (C++)

A beginner-friendly, turn-based terminal game written in C++. Move the player (`@`) across a 10 × 10 grid and reach the goal (`G`).

## Features

- 10 × 10 grid built with `std::vector<std::vector<char>>`
- Player movement using W, A, S and D
- Boundary checking: moves outside the grid are blocked
- Static goal tile and win condition
- Move counter (increases only after a valid move)
- Terminal redraw after each turn
- Quit option using Q

## Controls

| Key | Action |
|---|---|
| W | Move up |
| A | Move left |
| S | Move down |
| D | Move right |
| Q | Quit |

Type one key and press Enter after each move.

## Requirements

- A C++ compiler that supports C++11 or later
- A terminal / command prompt

## Compile and run

### Windows (g++ / MinGW)

```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o grid_game.exe
grid_game.exe
```

### macOS / Linux

```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o grid_game
./grid_game
```

If your terminal does not clear correctly, the game will still work; the screen may simply scroll instead of redrawing in place.

## Project structure

```text
terminal-grid-movement-game/
├── main.cpp
├── README.md
└── .gitignore
```

## Concepts demonstrated

- Two-dimensional vectors
- Rows and columns (`grid[y][x]`)
- Functions and loops
- Keyboard input with `std::cin`
- Coordinate updates and boundary validation
- Conditional logic and a simple game loop

## Future improvements

- Randomly place the goal
- Add obstacles and multiple levels
- Add a move limit or timer
- Support real-time keyboard input with a terminal library

## Author

Add your name and GitHub profile here before publishing.
