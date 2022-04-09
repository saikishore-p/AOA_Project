#include <iostream>
#include <vector>
#include <climits>
#include "header.h"
using namespace std;

void Task2::runTask2()
{
    int start = 0, end = 0;
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

    int size = qualityIndexData.size();
    // we initiliaze MaxSubArraySum to most possible minimum integer so as to handle most of the possibilities
    int MaxSubArraySum = INT_MIN;

    // This below two for loops are used to explore all potentil subarrays where each subarray starts at index left and ends at right
    for (int left = 0; left < size; left++)
    {
        int CurrentSubArrayMaxSum = 0;

        for (int right = left; right < size; right++)
        {

            // To compute the SubArraysum, we add the element at index right to previous Max sum computed
            CurrentSubArrayMaxSum += qualityIndexData[right];
            // If the new sum is greater than Maximum we already got, then it means that new subarray with max sum is found and so we update the start and end values
            if (CurrentSubArrayMaxSum > MaxSubArraySum)
            {
                start = left;
                end = right;
                MaxSubArraySum = CurrentSubArrayMaxSum;
            }
        }
    }
    cout << (start + 1) << " " << (end + 1) << " " << MaxSubArraySum << endl;
}