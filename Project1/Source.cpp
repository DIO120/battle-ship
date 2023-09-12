#include <iostream>
#include <vector>
#include <ctime>
#include <clocale> // Include the clocale library

using namespace std;

const int BOARD_SIZE = 10;

// Structure to store information about a cell on the game board
struct Cell {
    bool hasShip;
    bool isHit;

    Cell() : hasShip(false), isHit(false) {}
};

// Game board class
class Board {
private:
    vector<vector<Cell>> cells;

public:
    Board() {
        cells.resize(BOARD_SIZE, vector<Cell>(BOARD_SIZE));
    }

    void draw() {
        cout << "   ";
        for (int i = 0; i < BOARD_SIZE; i++)
            cout << " " << i << " ";
        cout << endl;
        for (int i = 0; i < BOARD_SIZE * 4 + 2; i++)
            cout << "-";
        cout << endl;
        string letters = "abcdefghjk";
        for (size_t i = 0; i < BOARD_SIZE; i++) {
            cout << letters[i];
            for (int j = 0; j < BOARD_SIZE; j++)
                cout << "  " << "|";
            cout << "  " << "|";
            cout << endl;
            for (int j = 0; j < BOARD_SIZE * 4 + 2; j++)
                cout << "-";
            cout << endl;
        }
    }

    void placeShip(int x, int y) {
        cells[x][y].hasShip = true;
    }

    bool attack(int x, int y) {
        if (cells[x][y].hasShip) {
            cells[x][y].isHit = true;
            return true;
        }
        return false;
    }

    bool isGameOver() {
        for (auto row : cells) {
            for (auto cell : row) {
                if (cell.hasShip && !cell.isHit) {
                    return false;
                }
            }
        }
        return true;
    }

    void print() {
        for (auto row : cells) {
            for (auto cell : row) {
                if (cell.isHit) {
                    cout << (cell.hasShip ? "X" : "-") << " ";
                }
                else {
                    cout << "~ ";
                }
            }
            cout << endl;
        }
    }

    void set() {
        srand(time(NULL));
        int xstart, ystart;
        xstart = rand() % BOARD_SIZE;
        ystart = rand() % BOARD_SIZE;

        cout << xstart << " " << ystart << endl;
        int direction = rand() % 4;
        cout << direction << endl;
        bool flag = true;
        if (direction == 0 && xstart < 3)
            flag = false;
        if (direction == 1 && ystart > 6)
            flag = false;
        if (direction == 2 && xstart > 6)
            flag = false;
        if (direction == 3 && ystart < 3)
            flag = false;

        cout << flag << endl;

        if (flag) {
            int xend = -1, yend = -1;
            if (flag) {
                if (direction == 0) {
                    xend = xstart - 3;
                    yend = ystart;
                    for (int i = xstart; i >= xend; i--)
                        cells[i][ystart].hasShip = true;
                }
                if (direction == 1) {
                    xend = xstart;
                    yend = ystart + 3;
                    for (int j = ystart; j <= yend; j++)
                        cells[xstart][j].hasShip = true;
                }
                if (direction == 2) {
                    xend = xstart + 3;
                    yend = ystart;
                    for (int i = xstart; i <= xend; i++)
                        cells[i][ystart].hasShip = true;
                }
                if (direction == 3) {
                    xend = xstart;
                    yend = ystart - 3;
                    for (int j = ystart; j >= yend; j--)
                        cells[xstart][j].hasShip = true;
                }
            }
            cout << xend << " " << yend << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru"); // Set the locale to Russian

    Board board;

    board.draw();
    board.set();

    // Place the remaining ships as desired
    board.placeShip(2, 3);
    board.placeShip(5, 7);

    while (!board.isGameOver()) {
        int x, y;
        cout <<"Enter attack coordinates (x, y): ";
        cin >> x >> y;

        if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
            cout << "Coordinates are incorrect. Try again." << endl;
            continue;
        }

        if (board.attack(x, y)) {
            cout <<"Hit!" << endl;
        }
        else {
            cout <<"Miss!" << endl;
        }

        board.print();
    }

    cout << "The game is over. You win!" << endl;

    return 0;
}