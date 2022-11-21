#include "Declare.h"
#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
    int size;
    std::cout << "Enter size of row and col: ";
    std::cin >> size;
    //  row_Col[size * size];
    std::vector<char> row(size, ' ');
    std::vector<std::vector<char>> row_Col(size, row);
    bool checkResult = true;
    int turn = 1;
    char LocationOfRow, LocationOfCol;
    bool continueGame = false, tie = false;
    int score1{0}, score2{0};
    char CharOfPlayer;
    HappenGame(continueGame, LocationOfRow, LocationOfCol, size, row_Col, CharOfPlayer, tie, turn);
    PrintResult(continueGame, turn, score1, score2, tie, size, row_Col);
    return 0;
}