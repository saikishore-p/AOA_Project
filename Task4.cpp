#include <iostream>
#include <vector>
#include <climits>
#include "header.h"
using namespace std;

void Task4::runTask4()
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

    int maximum_sum = INT_MIN, left, right, top, bottom; // To trace the dimensions of sub rectangle with maximum sum
    for (int row_start = 0; row_start < size[0]; ++row_start)
    {
        for (int col_start = 0; col_start < size[1]; ++col_start)
        {
            for (int row_end = row_start; row_end < size[0]; ++row_end)
            {
                for (int col_end = col_start; col_end < size[1]; ++col_end)
                {
                    int current_sum = 0;
                    for (int row = row_start; row <= row_end; ++row)
                    {
                        for (int col = col_start; col <= col_end; ++col)
                        {
                            current_sum += matrix[row][col];
                        }
                    }
                    if (current_sum > maximum_sum)
                    {
                        maximum_sum = current_sum;
                        top = row_start + 1;
                        left = col_start + 1;
                        bottom = row_end + 1;
                        right = col_end + 1;
                    }
                }
            }
        }
    }

    // Print final values
    cout << top << " " << left << " " << bottom << " " << right << " " << maximum_sum << endl;
}