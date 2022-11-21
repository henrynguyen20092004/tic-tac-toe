#include <iostream>

using namespace std;

void SaveScore(int turn, int &score1, int &score2)
{
    if (turn % 2 == 1)
    {
        score1++;
        cout << "Player 1 won!" << endl;
    }
    else
    {
        score2++;
        cout << "Player 2 won!" << endl;
    }
}

string GetResult(int score1, int score2)
{
    if (score1 > score2)
        return "Player 1 won the matches!";
    if (score1 < score2)
        return "Player 2 won the matches!";
    return "It's a tie";
}
