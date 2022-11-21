#include <vector>
void HappenGame(bool &continueGame, char LocationOfRow, char LocationOfCol, int size, std::vector<std::vector<char>> row_Col, char CharOfPlayer, bool &tie, int turn);
void PrintResult(bool continueGame, int turn, int score1, int score2, bool tie, int size, std::vector<std::vector<char>> row_Col);