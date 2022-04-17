#include <iostream>
#include <vector>
#include "header.h"
#include <climits>
using namespace std;

void Task3B::runTask3B()
{
    int Start = 0;
    int End = 0;
    int TempStart = 0;
    std::vector<int> qualityIndexData;
    // To get the input from user
    // Array size
    int count;
    cin >> count;
    // Array
    for (int i = 0; i < count; ++i)
    {
        int num;
        cin >> num;
        qualityIndexData.push_back(num);
    }

    int MaxSubArraySum = qualityIndexData[0];
    int CurrentSubArrayMaxSum = qualityIndexData[0];

    // This loop is to iterate through each element in given input array
    for (int index = 1; index < qualityIndexData.size(); index++)
    {

        /* The below if else condition is to take one of the below options
        Option 1  : Include qualityIndexData[i] to expand subarray and sum
        Option 2 : Start new from qualityIndexData[i] by discarding previous subarray*/
        if (CurrentSubArrayMaxSum < 0)
        {
            TempStart = index;
            CurrentSubArrayMaxSum = qualityIndexData[index];
        }

        else
        {
            CurrentSubArrayMaxSum += qualityIndexData[index];
        }

        // If we get new MaxSum then we update the MaxSum and store the indices of the subarray that produced Maxsum
        if (MaxSubArraySum < CurrentSubArrayMaxSum)
        {
            Start = TempStart;
            End = index;
            MaxSubArraySum = CurrentSubArrayMaxSum;
        }
    }
    cout << Start + 1 << " " << End + 1 << " " << MaxSubArraySum << endl;
}