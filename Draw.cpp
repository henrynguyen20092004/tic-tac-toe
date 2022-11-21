#include "Draw.h"
#include <iostream>
#include <vector>

using namespace std;

char FirstRowAndColumn(int x, int y)
{
    if (x == 0)
        if (y % 2 == 1)
            return '|';
        else if (y != 0)
            return char(y / 2 + 96);

    if (y == 0)
        if (x % 2 == 1)
            return '-';
        else if (x != 0)
            return char(x / 2 + 96);

    return ' ';
}

char ParseSmallBoard(vector<vector<char>> smallBoard, int x, int y, int size) {
    return x < size ? smallBoard[x / 2 - 1][y / 2 - 1] : ' ';
}

char GetCharFromCoor(vector<vector<char>> smallBoard, int x, int y, int size)
{
    if (y == size)
        return '\n';
    else if (x == 0 || y == 0)
        return FirstRowAndColumn(x, y);
    else if (x % 2 == 1)
        return y % 2 == 0 ? '-' : '+';
    else if (x % 2 == 0 && y % 2 == 1)
        return '|';
    return ParseSmallBoard(smallBoard, x, y, size);
}

string DrawBoard(vector<vector<char>> smallBoard, int size)
{
    vector<vector<char>> board(size, vector<char>(size + 1));
    string boardString;

    for (int i = 0; i < size; i++)
        for (int j = 0; j <= size; j++)
            board[i][j] = GetCharFromCoor(smallBoard, i, j, size);

    for (int i = 0; i < size; i++)
        for (int j = 0; j <= size; j++)
            boardString += board[i][j];

    return boardString;
}
