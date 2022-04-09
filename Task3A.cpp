#include <iostream>
#include "header.h"
#include <vector>
#include <climits>
using namespace std;

int MaxSubArraySum;
int Start = 0;
int End = 0;
int TempStart = 0;
int compute_sum(vector<int> &qualityIndexData, int size);

void Task3A::runTask3A()
{
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
    MaxSubArraySum = INT_MIN;
    MaxSubArraySum = qualityIndexData[0];
    compute_sum(qualityIndexData, qualityIndexData.size());
    cout << Start + 1 << " " << End + 1 << " " << MaxSubArraySum << endl;
}

int compute_sum(std::vector<int> &qualityIndexData, int size)
{

    // Base case : if the size of input array qualityIndexData[index] is 1 or if the qualityIndexData[index] reaches the last index, then MaxSubArraySum will be the qualityIndexData[index].Then the startand End indices would be 1.
    if (size == 1)
        return qualityIndexData[0];

    // Recursive case: we explore the 2 options described above, i.e we compare the current element in the Input A[index] with the sum from recursion output for the next index +1.
    int CurrentSubArrayMaxSum = compute_sum(qualityIndexData, size - 1);
    /* The below if else condition is to take one of the below options
         Option 1  : Include qualityIndexData[i] to expand subarray and sum
         Option 2 : Start new from qualityIndexData[i] by discarding previous subarray*/
    if (CurrentSubArrayMaxSum < 0)
    {
        TempStart = size - 1;
        CurrentSubArrayMaxSum = qualityIndexData[size - 1];
    }

    else
        CurrentSubArrayMaxSum += qualityIndexData[size - 1];

    // If we get new MaxSum then we update the MaxSum and store the indices of the subarray that produced Maxsum
    if (MaxSubArraySum < CurrentSubArrayMaxSum)
    {
        MaxSubArraySum = CurrentSubArrayMaxSum;
        Start = TempStart;
        End = size - 1;
    }
    return CurrentSubArrayMaxSum;
}