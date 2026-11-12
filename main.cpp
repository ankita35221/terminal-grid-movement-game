#include <iostream>
#include <vector>
#include <cstdlib>
#include <cctype>

using namespace std;

const int ROWS = 10;
const int COLS = 10;

void draw(const vector<vector<char>>& grid, int moves) {
    // Clear the terminal before drawing the updated grid.
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    cout << "===== TERMINAL GRID MOVEMENT GAME =====\n\n";

    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            cout << grid[row][col] << ' ';
        }
        cout << '\n';
    }

    cout << "\nMoves: " << moves << '\n';
    cout << "Controls: W = Up, A = Left, S = Down, D = Right\n";
    cout << "Press Q to quit.\n";
}

int main() {
    vector<vector<char>> grid(ROWS, vector<char>(COLS, '.'));

    // Player starts near the top-left corner.
    int playerX = 1;
    int playerY = 1;

    // Goal is placed near the bottom-right corner.
    const int goalX = COLS - 2;
    const int goalY = ROWS - 2;

    int moves = 0;
    bool won = false;

    while (!won) {
        // Rebuild the display grid on every turn.
        grid.assign(ROWS, vector<char>(COLS, '.'));
        grid[goalY][goalX] = 'G';
        grid[playerY][playerX] = '@';

        draw(grid, moves);

        char direction;
        cout << "\nEnter your move (W/A/S/D): ";

        if (!(cin >> direction)) {
            cout << "\nInput error. Exiting game.\n";
            return 1;
        }

        direction = static_cast<char>(
            tolower(static_cast<unsigned char>(direction))
        );

        if (direction == 'q') {
            cout << "\nThanks for playing!\n";
            break;
        }

        int newX = playerX;
        int newY = playerY;

        switch (direction) {
            case 'w': --newY; break;
            case 'a': --newX; break;
            case 's': ++newY; break;
            case 'd': ++newX; break;
            default:
                cout << "\nInvalid key. Use W, A, S, D, or Q.\n";
                cout << "Press Enter to continue...";
                cin.ignore(10000, '\n');
                cin.get();
                continue;
        }

        // Reject moves that would take the player outside the grid.
        if (newX < 0 || newX >= COLS || newY < 0 || newY >= ROWS) {
            cout << "\nYou cannot move outside the grid!\n";
            cout << "Press Enter to continue...";
            cin.ignore(10000, '\n');
            cin.get();
            continue;
        }

        // Count only valid moves.
        playerX = newX;
        playerY = newY;
        ++moves;

        if (playerX == goalX && playerY == goalY) {
            won = true;
        }
    }

    if (won) {
        grid.assign(ROWS, vector<char>(COLS, '.'));
        grid[goalY][goalX] = '@';
        draw(grid, moves);
        cout << "\nCongratulations! You reached the goal!\n";
        cout << "Total valid moves: " << moves << '\n';
    }

    return 0;
}
