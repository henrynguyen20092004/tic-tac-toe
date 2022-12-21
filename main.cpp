#include <iostream>
#include <vector>

#include "Check.h"
#include "Draw.h"
#include "Score.h"

using namespace std;

void run(int &score1, int &score2);

int main() {
    int score1 = 0, score2 = 0;
    char ans;
    bool running;
    cout << "Welcome to the game tic-tac-toe.\n";
    cout << "Do you want to start? (Y/N) ";
    inputChar(ans);

    do {
        while (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n') {
            cout << "Please try again! ";
            inputChar(ans);
        }
        if (ans == 'Y' || ans == 'y') {
            running = true;
            run(score1, score2);
            cout << "Do you want to play again? (Y/N) ";
            inputChar(ans);
        }
        if (ans == 'N' || ans == 'n') {
            cout << "Player 1 score: " << score1 << "\n";
            cout << "Player 2 score: " << score2 << "\n";
            cout << GetResult(score1, score2) << "\n";
            running = false;
        }
    } while (running);

    cout << "Press enter to exit... ";
    cin.get();
    return 0;
}

void run(int &score1, int &score2) {
    int size, turn = 0;
    do {
        cout << "Enter the size of the board (5 - 26): ";
        cin >> size;
        while (cin.get() != '\n') {
        }
        if (size < 5 || size > 26)
            cout << "Please try again!\n";
    } while (size < 5 || size > 26);
    vector<char> filledRow(size, ' ');
    vector<vector<char>> board(size, filledRow);
    cout << DrawBoard(board, size) << "\n";
    do {
        turn++;
        ChoiceOfPlayer(board, size, turn);
        cout << DrawBoard(board, size) << "\n";
        if (CheckResult(board, size))
            SaveScore(turn, score1, score2);
        if (CheckTie(board))
            cout << "It's a tie!\n";
    } while (!CheckResult(board, size) && !CheckTie(board));
}
