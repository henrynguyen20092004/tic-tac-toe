#include "Declare.h"
#include <iostream>
#include <vector>
int TurnOfPlayer(int &turn)
{
    ++turn;
    return turn % 2 == 0 ? 1 : 2;
}

int Change(char CH)
{
    return static_cast<int>(CH);
}

void ChooseOfPlayer(char LocationOfRow, char LocationOfCol, int size, int turn, std::vector<std::vector<char>> row_Col, char CharOfPlayer)
{
    do
    {
        std::cout << "The turn of player: " << TurnOfPlayer(turn) << '\n';
        std::cout << "Enter row: ";
        std::cin >> LocationOfRow;
        std::cout << "Enter col: ";
        std::cin >> LocationOfCol;

        if (Change(LocationOfCol) > size || Change(LocationOfRow) > size || Change(LocationOfCol) - 96 < 1 || Change(LocationOfRow) - 96 < 1)
        {
            std::cout << "\aEnter again\n";
            --turn;
        }

        else
        {
            if (row_Col[(Change(LocationOfRow) - 96)][(Change(LocationOfCol) - 96)] == ' ')
            {
                CharOfPlayer = turn % 2 == 0 ? 'X' : 'O';
                row_Col[(Change(LocationOfRow) - 96)][(Change(LocationOfCol) - 96)] = CharOfPlayer;
            }

            else
            {
                std::cout << "\aEnter again!\n";
                --turn;
            }
        }
    } while (Change(LocationOfCol) > size || Change(LocationOfRow) > size || Change(LocationOfCol) < 1 || Change(LocationOfRow) < 1);
}
bool checkResult(int size, std::vector<std::vector<char>> row_Col, bool &tie)
{
    // duyet cot
    // for (int j = 0; j < size - 4; ++j)
    // {
    //     for (int i = j; i < 5 + j; ++i)
    //     {
    //         // if (row_Col[i] != ' ' && row_Col[i] == row_Col[1 * size + i] && row_Col[1 * size + i] == row_Col[2 * size + i] && row_Col[2 * size + i] == row_Col[3 * size + i] && row_Col[3 * size + i] == row_Col[4 * size + i])
    //         // {
    //         //     return true;
    //         // }
    //     }
    // }
    // // duyet hang
    // for (int j = 0; j < size - 4; ++j)
    // {
    //     for (int i = j; i < 5 + j; ++i)
    //     {
    //         if (row_Col[i * size] != ' ' && row_Col[i * size] == row_Col[i * size + 1] && row_Col[i * size + 1] == row_Col[i * size + 2] && row_Col[i * size + 2] == row_Col[i * size + 3] && row_Col[i * size + 3] == row_Col[i * size + 4])
    //         {
    //             return true;
    //         }
    //     }
    // }
    // // duyet duong cheo thuan
    // for (int j = 0; j < size - 4; ++j)
    // {
    //     for (int i = j; i < 5 + j; ++i)
    //     {
    //         if (row_Col[i * size + i] != ' ' && row_Col[i * size + i] == row_Col[i * size + i + 1] && row_Col[i * size + i + 1] == row_Col[i * size + i + 2] && row_Col[i * size + i + 2] == row_Col[i * size + i + 3] && row_Col[i * size + i + 3] == row_Col[i * size + i + 4])
    //         {
    //             return true;
    //         }
    //     }
    // }
    // // duyet duong cheo nguoc
    // for (int j = 0; j < size - 4; ++j)
    // {
    //     for (int i = j; i < 5 + j; ++i)
    //     {
    //         if (row_Col[i * size + 9 - i] != ' ' && row_Col[i * size + 9 - i] == row_Col[i * size + 8 - i] && row_Col[i * size + 8 - i] == row_Col[i * size + 7 - i] && row_Col[i * size + 7 - i] == row_Col[i * size + 6 - i] && row_Col[i * size + 6 - i] == row_Col[i * size + 5 - i])
    //         {
    //             return true;
    //         }
    //     }
    // }
    // // duyet tie
    // int count{0};

    // for (int i = 0; i < size * size; ++i)
    // {
    //     if (row_Col[i] == ' ')
    //     {
    //         ++count;
    //     }
    // }

    // if (count == 0)
    // {
    //     tie = true;
    //     return true;
    // }

    // return false;
    for (int i = 0; i < size - 4; ++i)
    {
        for (int j = 0; j < size - 4; ++j)
        {
            if (row_Col[i][j] != ' ' && row_Col[i][j] == row_Col[i][j + 1] && row_Col[i][j + 1] == row_Col[i][j + 2] && row_Col[i][j + 2] == row_Col[i][j + 3] && row_Col[i][j + 3] == row_Col[i][j + 4])
            {
                return true;
            }
            if (row_Col[i][j] != ' ' && row_Col[i][j] == row_Col[i + 1][j] && row_Col[i + 1][j] == row_Col[i + 2][j] && row_Col[i + 2][j] == row_Col[i + 3][j] && row_Col[i + 3][j] == row_Col[i + 4][j])
            {
                return true;
            }
            if (row_Col[i][j] != ' ' && row_Col[i][j] == row_Col[i + 1][j + 1] && row_Col[i + 1][j + 1] == row_Col[i + 2][j + 2] && row_Col[i + 2][j + 2] == row_Col[i + 3][j + 3] && row_Col[i + 3][j + 3] == row_Col[i + 4][j + 4])
            {
                return true;
            }
        }
        for (int j = size - 1; j > 4; --j)
        {
            if (row_Col[i][j] != ' ' && row_Col[i][j] == row_Col[i + 1][j - 1] && row_Col[i + 1][j - 1] == row_Col[i + 2][j - 2] && row_Col[i + 2][j - 2] == row_Col[i + 3][j - 3] && row_Col[i + 3][j - 3] == row_Col[i + 4][j - 4])
            {
                return true;
            }
        }
    }
    int count{0};
    for (int i = 0; i < size && count == 0; ++i)
    {
        for (int j = 0; j < size && count == 0; ++j)
        {
            if (row_Col[i][j] == ' ')
            {
                ++count;
            }
        }
    }
    if (count == 0)
    {
        tie = true;
        return true;
    }

    return false;
}

int saveResult(int &score1, int &score2, int turn)
{
    return (turn % 2 == 0) ? ++score2 : ++score1;
}
void HappenGame(bool &continueGame, char LocationOfRow, char LocationOfCol, int size, std::vector<std::vector<char>> row_Col, char CharOfPlayer, bool &tie, int turn)
{
    while (!continueGame)
    {
        ChooseOfPlayer(LocationOfRow, LocationOfCol, size, turn, row_Col, CharOfPlayer);
        // add desgin
        continueGame = checkResult(size, row_Col, tie);
    }
}
void PrintResult(bool continueGame, int turn, int score1, int score2, bool tie, int size, std::vector<std::vector<char>> row_Col)
{

    if (continueGame)
    {
        if (tie)

            std::cout << "Two players are tie!\n";
    }
    else
    {
        std::cout << "The player " << --turn << " are Winner!\n";
        saveResult(score1, score2, turn);
        std::cout << "The result of two players now are: " << score1 << " vs " << score2 << std::endl;
    }
}
