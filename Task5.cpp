#include <iostream>
#include <vector>
#include "header.h"
#include <climits>
using namespace std;

void Task5::runTask5(){
    vector<vector<int> > matrix;
    std::vector<int> size;
    int row, col;
    // Taking no. of rows and columns as input
    for (int i = 0; i < 2; i++)
    {
        int num;
        cin >> num;
        size.push_back(num);
    }
    // Taking matrix elements as input
    for (int i = 0; i < size[0]; i++)
    {
        vector<int> row; // A temporary vector to store values for each iteration
        // cout << "Enter " << size[1] << " numbers for row " << i + 1 << endl;
        for (int j = 0; j < size[1]; j++)
        {
            int x;
            cin >> x;
            row.push_back(x);
        }
        matrix.push_back(row); // Pushing temporary vector's all values to matrix
        row.clear();           // Clearing temporary vector for each iteration
    }

    vector<vector<int> > temp(size[0] + 1, vector<int>(size[1] + 1, 0)); // Creating temporary matrix of m+1 and n+1 size
    row = size[0] + 1, col = size[1] + 1;
    for (int r = 1; r < row; r++)
    {
        for (int c = 1; c < col; c++)
        {
            temp[r][c] = temp[r][c - 1] + matrix[r - 1][c - 1];
        }
    }
    for (int c = 1; c < col; c++)
    {
        for (int r = 1; r < row; r++)
        {
            temp[r][c] = temp[r - 1][c] + temp[r][c];
        }
    }

    int maximum_sum = INT_MIN;                         // To get the maximum sum of subrectangles in matrix
    int top, left, bottom, right; // To trace the dimensions of sub rectangle with maximum sum

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            for (int k = i; k < row; k++)
            {
                for (int l = j; l < col; l++)
                {
                    int sum_subrectangle = temp[k][l] - temp[i - 1][l] - temp[k][j - 1] + temp[i - 1][j - 1];
                    if (sum_subrectangle > maximum_sum)
                    {
                        top = i,
                        left = j,
                        bottom = k,
                        right = l;
                        maximum_sum = sum_subrectangle;
                    }
                }
            }
        }
    }

    // Print final values
    cout << top << " " << left << " " << bottom << " " << right << " " << maximum_sum << endl;
}