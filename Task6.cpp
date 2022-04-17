#include <iostream>
#include <vector>
#include "header.h"
#include <climits>
#include <cstring>
using namespace std;

void Task6::runTask6()
{
    vector<vector<int> > matrix;
    std::vector<int> size;
    // Taking no. of rows and columns as input
    for (int i = 0; i < 2; i++)
    {
        int n;
        cin >> n;
        size.push_back(n);
    }
    // Taking matrix elements as input
    for (int i = 0; i < size[0]; i++)
    {
        vector<int> row; // A temporary vector to store values for each iteration
        for (int j = 0; j < size[1]; j++)
        {
            int n;
            cin >> n;
            row.push_back(n);
        }
        matrix.push_back(row); // Pushing temporary vector's all values to matrix
        row.clear();           // Clearing temporary vector for each iteration
    }

    vector<vector<int> > temp((size[0] + 1), vector<int>(size[1]));

    for (int i = 0; i < size[0]; i++)
    {
        for (int j = 0; j < size[1]; j++)
        {
            temp[i + 1][j] = temp[i][j] + matrix[i][j];
        }
    }

    int maximum_sum = -1;
    int minimum_sum = INT_MIN;
    int row, col, top, bottom, left, right;
    for (int from_row = 0; from_row < size[0]; from_row++)
    {
        for (int r = from_row; r < size[0]; r++)
        {
            int local_sum = 0;
            int from_col = 0;
            for (int c = 0; c < size[1]; c++)
            {
                local_sum += temp[r + 1][c] - temp[from_row][c];
                if (local_sum < 0)
                {
                    if (minimum_sum < local_sum)
                    {
                        minimum_sum = local_sum;
                        row = r+1;
                        col = c+1;
                    }
                    local_sum = 0;
                    from_col = c + 1;
                }
                else if (maximum_sum < local_sum)
                {
                    maximum_sum = local_sum;
                    top = from_row+1;
                    left = from_col+1;
                    bottom = r+1;
                    right = c+1;
                }
            }
        }
    }
    if (maximum_sum == -1)
    {
        cout << row << " " << col << " " << row << " " << col << " " << minimum_sum << endl;
    }
    else
    {
        cout << top << " " << left << " " << bottom << " " << right << " " << maximum_sum << endl;
    }
}
