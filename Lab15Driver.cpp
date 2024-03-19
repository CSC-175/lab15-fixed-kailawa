// This program finds the probability of winning a "mini" lottery
// when the user's set of numbers match the set drawn
// by the lottery organizers. It uses three functions.
# include <iostream>
using namespace std;
// Function prototypes
void getInfo(int&, int&);
double computeWays(int, int);
double factorial(int);

int main()
{
    int pickFrom, // The number of numbers to pick from
    numPicks;// The number of numbers to select
    double ways; // The number of different possible
                 // ways to pick the set of numbers
    char again;

    do{
        getInfo(pickFrom, numPicks);
        ways = computeWays(pickFrom, numPicks);
        cout.setf(ios::fixed);
        cout.precision(4);
        cout << "\nProbability of winning is " << ways;
        cout << "\nOdds of winning are 1 in " << int(1/ways);
        cout << "\n\nWould you like to calculate the probability of another scenario? (y/n): ";
        cin >> again;
    }while(again =='y' or again == 'Y');
    return 0;
}

