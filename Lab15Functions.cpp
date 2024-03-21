/*******************************************************************
* getInfo *
* Gets and validates lottery info from the user and places it in   *
* reference parameters referencing variables in the main function. *
*******************************************************************/
#include <iostream>
#include <limits>
using namespace std;
void getInfo(int&, int&);
double computeWays(int, int);
double factorial(int);

void getInfo(int & pickFrom, int & numPicks){
    cout << "How many balls (1-12) are in the pool to pick from? ";
    cin >> pickFrom;

    while (cin.fail() || pickFrom < 1 || pickFrom > 12) {
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Input Error! There must be between 1 and 12 balls." << endl;
        cout << "How many balls (1-12) are in the pool to pick from? ";
        cin >> pickFrom;
    }

    cout << "How many balls (1-" << pickFrom << ") will be drawn? ";
    cin >> numPicks;

    while (numPicks < 1 || numPicks > pickFrom || cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input Error! " << endl;
        cout << "How many balls (1-" << pickFrom << ") will be drawn? ";
        cin >> numPicks;
    }
}

/******************************************************************
* computeWays                                                     *
* Computes and returns the number of different possible sets      *
* of k numbers that can be chosen from a set of n numbers.        *
* The formula for this is     k!(n- k)!                           *
*                             --------                            *
*                                 n!                              *
*******************************************************************/
// Note that the computation is done in a way that does not require
// multiplying two factorials together. This is done to prevent any
// intermediate result becoming so large that it causes overflow.
double computeWays(int n, int k){
    double ways = (factorial(k) * factorial(n - k)) / factorial(n);
    return ways;
}


// This function computes factorials recursively. It is called by computeWays.
double factorial(int n){
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}
