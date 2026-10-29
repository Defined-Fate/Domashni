// code copied from geeks for geeks
// https://www.geeksforgeeks.org/dsa/n-queen-problem-backtracking-3/

#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

int64_t Interation = 0;
// Function to check if it is safe to place
int isSafe(vector<vector<int>>& mat, int row, int col) {
    int n = mat.size();
    int i, j;

    // Check this col on upper side
    for (i = 0; i < row; i++)
        if (mat[i][col])  //n
            return 0;

    // Check upper diagonal on left side
    for (i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (mat[i][j]) //n
            return 0;

    // Check upper diagonal on right side
    for (i = row-1, j = col+1; j < n && i >= 0; i--, j++)
        if (mat[i][j]) //n
            return 0;

    return 1;
}

// Recursive function to place queens
void placeQueens(int row, vector<vector<int>>& mat, vector<vector<int>>&result) {
    int n = mat.size();
    Interation++;
    // base case: If all queens are placed
    if(row == n) {
        
        // store current solution
        vector<int> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j]){
                    ans.push_back(j + 1); //n^2
                }
            }
        }
        result.push_back(ans);
        return;
    }

    // Consider the row and try placing
    // queen in all columns one by one
    for(int i = 0; i < n; i++){
        
        // Check if the queen can be placed
        if(isSafe(mat, row, i)){ //n
            mat[row][i] = 1; 
            placeQueens(row + 1, mat, result); //n
            
            // backtrack
            mat[row][i] = 0; 
        }
    }
}

// Function to find all solutions
vector<vector<int>> nQueen(int n) {

    // Initialize the board
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<vector<int>> result;

    // Place queens
    placeQueens(0, mat, result);

    return result;
}

int main() {
    srand(time(0));

    int n;
    cin >> n;

    clock_t start = clock();
    vector<vector<int>> result = nQueen(n);
    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    cout << "Sortiranjeto zavrsi za: " << elapsed << " sekundi.\n";
    cout << "Iteration: " << Interation; 
    // for(auto &ans : result){
    //     for(auto i: ans){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}
