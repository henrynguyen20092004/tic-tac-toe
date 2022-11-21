#include <iostream>

using namespace std;

int main()
{
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
            cout << "Do sth here!" << endl;
            cout << "Do you want to play again? (Y/N) ";
            cin >> ans;
        }
        if (ans == 'N' || ans == 'n')
            running = false;
    } while (running);
    return 0;
}
