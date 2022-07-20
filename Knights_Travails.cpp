/* Problem Statement: To find whether for a chessboard irrespective of its size, if we put a knight at base 
position(0,0), then will it be able to travel the whole chessboard. If yes, then show the tour of the Knight
This problem is known as Knight Travails.*/

/*
this solution code is developed by:
Aniket Jain
*/

/****************************************HEADER FILES****************************************/
#include <iostream>
#include <iomanip>

/******************************************NAMESPACE*****************************************/
using namespace std;

/******************************************KEYWORDS*****************************************/ 
#define N 5                 //Size of the chessboard [N] X [N]

/******************************************FUNCTIONS*****************************************/
int isSafe(int , int, int);
/* 
Desc: A Funciton to check whether the position x,y is safe for next move
Para: 
    int X -> x value of the next position
    int Y -> y value of the next position
    int sol[N][N] -> output matrix (virtual chess board)
return type: INT
*/

int solve(int , int, int, int, int, int);
/* 
Desc: A recursive function to solve Knight Travalis problem using the concept of backtracking
Para: 
    int X -> x value of the next position
    int Y -> y value of the next position
    int movei -> no. of moves taken till the current itteration
    int sol[N][N] -> output matrix (virtual chess board)
    int xMove[8] -> 8 available moves for the next x axis
    int yMove[8] -> 8 available moves for the next y axis
return type: INT
*/

int solveKT();
/* 
Desc: This function solves the Knights Travails problem using Backtracking. It returns false if no complete
tour is possible, otherwise return true and prints the tour.
return type: INT
*/


int isSafe(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}
 
int solve(int x, int y, int movei, int sol[N][N], int xMove[8], int yMove[8])
{
    int k, next_x, next_y;
    if (movei == N * N)
        return 1;
 
    /* Try all next 8 moves from the current block x,y */
    for (k = 0; k < 8; k++) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei;
            if (solve(next_x, next_y, movei + 1, sol, xMove, yMove) == 1) //backtracking
                return 1;
            else
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}

int solveKT()
{
    int sol[N][N];
 
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;
 
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
 
    // Starting the Knight from the first block
    sol[0][0] = 0;
 
    /* Start from base 0,0 and explore all moves using solve() */
    if (solve(0, 0, 1, sol, xMove, yMove) == 0) {
        cout << "Solution does not exist";
        return 0;
    }
    else{
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++)
                cout << " " << setw(2) << sol[x][y] << " ";
            cout << endl;
        }
    }
 
    return 1;
}
 
 
// Main Function
int main()
{
    solveKT();
    return 0;
}