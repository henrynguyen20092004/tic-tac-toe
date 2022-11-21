#include <iostream>
#include <vector>
#include "Draw.h"

using namespace std;

int main()
{
    char ans;
    bool running;
    int size;
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
            cout << "Enter the size of the board: ";
            cin >> size;

            // TODO: Make a real board and loop the draw function
            /* **************************************************
            vector<char> filledRow(size, ' ');
            vector<vector<char>> smallBoard(size, filledRow);

            cout << DrawBoard(smallBoard, size * 2 + 1);
            ************************************************** */

            cout << "Do you want to play again? (Y/N) ";
            cin >> ans;
        }
        if (ans == 'N' || ans == 'n')
            running = false;
    } while (running);

    return 0;
}
