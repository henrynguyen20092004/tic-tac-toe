#include <iostream>
#include <vector>

#include "Check.h"
#include "Draw.h"
#include "Score.h"

using namespace std;

void run(int &score1, int &score2);

int main()
{
    int score1 = 0, score2 = 0;
    char ans;
    bool running;
    cout << "Welcome to the game tic-tac-toe." << endl;
    cout << "Do you want to start? (Y/N) ";
    cin >> ans;

    do
    {
        while (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n')
        {
            cout << "Please try again! ";
            cin >> ans;
        }
        if (ans == 'Y' || ans == 'y')
        {
            running = true;
            run(score1, score2);
            cout << "Do you want to play again? (Y/N) ";
            cin >> ans;
        }
        if (ans == 'N' || ans == 'n')
        {
            cout << "Player 1 score: " << score1 << endl;
            cout << "Player 2 score: " << score2 << endl;
            cout << GetResult(score1, score2) << endl;
            running = false;
        }
    } while (running);

    return 0;
}

void run(int &score1, int &score2)
{
    int size, turn = 0;
    cout << "Enter the size of the board: ";
    cin >> size;
    vector<char> filledRow(size, ' ');
    vector<vector<char>> board(size, filledRow);
    cout << DrawBoard(board, size) << endl;
    do
    {
        turn++;
        ChoiceOfPlayer(board, size, turn);
        cout << DrawBoard(board, size) << endl;
        if (CheckResult(board, size))
            SaveScore(turn, score1, score2);
        if (CheckTie(board))
            cout << "It's a tie!" << endl;
    } while (!CheckResult(board, size) && !CheckTie(board));
}
