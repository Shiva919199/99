#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) 
{
    // Check the column on the left
    for (int i = 0; i < col; i++) 
    {
        if (board[row][i] == 1) 
        {
            return false;
        }
    }

    // Check the upper diagonal on the left
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
    {
        if (board[i][j] == 1) 
        {
            return false;
        }
    }

    // Check the lower diagonal on the left
    for (int i = row, j = col; i < n && j >= 0; i++, j--) 
    {
        if (board[i][j] == 1) 
        {
            return false;
        }
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int col, int n) 
{
    if (col == n) 
    {
        return true;  // All Queens are placed
    }

    for (int i = 0; i < n; i++) 
    {
        if (isSafe(board, i, col, n)) 
        {
            board[i][col] = 1;  // Place the Queen

            // Recur to place the rest of the Queens
            if (solveNQueens(board, col + 1, n))
            {
                return true;
            }

            // If placing a Queen in board[i][col] doesn't lead to a solution, backtrack
            board[i][col] = 0;
        }
    }

    // If no Queen can be placed in this column, return false
    return false;
}

void printSolution(vector<vector<int>>& board) 
{
    int n = board.size();
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


void nQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    auto start_time = high_resolution_clock::now();

    if (!solveNQueens(board, 0, n)) 
    {
        cout << "\nNo solution exists." << endl;
    } 

    else 
    {
        auto end_time = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end_time - start_time).count();

        cout << "\nSolution:" << endl;
        printSolution(board);
        cout << "\nTime taken: " << duration << " milliseconds" << endl<<endl;
    }
}

int main() 
{
    int n;
    cout << "\nEnter the board size (n): ";
    cin >> n;
    nQueens(n);
    return 0;
}