#include <iostream>
#include <vector>
#include "Check.h"

using namespace std;

int CharToInt(char coor)
{
    return int(coor) - 97;
}

void ChoiceOfPlayer(vector<vector<char>> &board, int size, int turn)
{
    char row, col;
    bool occupied = false;
    do
    {
        turn = turn % 2 == 1 ? 1 : 2;
        cout << "The turn of player: " << turn << '\n';
        cout << "Enter row: ";
        cin >> row;
        cout << "Enter col: ";
        cin >> col;

        if (CharToInt(row) > size || CharToInt(col) > size || CharToInt(row) < 0 || CharToInt(col) < 0)
            cout << "Out of bounds, please enter again!\n";
        else
        {
            if (board[(CharToInt(row))][(CharToInt(col))] == ' ')
            {
                board[(CharToInt(row))][(CharToInt(col))] = turn == 1 ? 'X' : 'O';
                occupied = false;
            }
            else
            {
                cout << "That square is occupied, please enter again!\n";
                occupied = true;
            }
        }
    } while (CharToInt(row) > size || CharToInt(col) > size || CharToInt(row) < 0 || CharToInt(col) < 0 || occupied);
}

bool CheckResult(vector<vector<char>> board, int size)
{
    for (int i = 0; i < size - 4; i++)
    {
        // Row and diagonal check
        for (int j = 0; j < size - 4; j++)
        {
            if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j] && board[i][j] == board[i + 4][j])
                return true;
            if (board[i][j] != ' ' && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] && board[i][j] == board[i + 4][j + 4])
                return true;
        }
        // More row check
        for (int j = size - 4; j < size; j++)
            if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j] && board[i][j] == board[i + 4][j])
                return true;
        // Reverse diagonal check
        for (int j = size - 1; j > 3; --j)
            if (board[i][j] != ' ' && board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3] && board[i][j] == board[i + 4][j - 4])
                return true;
    }
    // Column check
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 4; j++)
            if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] && board[i][j] == board[i][j + 4])
                return true;
    return false;
}

bool CheckTie(vector<vector<char>> board)
{
    for (auto i : board)
        for (auto j : i)
            if (j == ' ')
                return false;
    return true;
}
