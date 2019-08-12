
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findOther(vector<int>& numbers, int from, int other) {
        int min = from;
        int max = numbers.size();

        int mid = (min + max) / 2;
        while(true) {
            if (mid == min || mid == max) {
                return 0;
            }
            // cout << min << ':' << mid  << ':' << max << endl;
            // cout << numbers[min] << ':' << numbers[mid]  << ':' << numbers[max - 1] << endl;


            if (numbers[mid] == other) {
                return mid;
            }
            if (numbers[mid] > other) {
                max = mid;
            }
            if (numbers[mid] < other) {
                min = mid;
            }
            mid = (min + max) / 2;
        }
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::vector<int> result;
        result.push_back(0);
        result.push_back(0);
        int len = numbers.size();
        for (int i = 0; i < len; ++i)
        {
            int other = target - numbers[i];
            // cout << other << '.' << target << endl;

            // cout << i << '|' << numbers[i] << '|' << other << endl;
            int pos = this->findOther(numbers, i, other);
            if (pos > 0 && pos != i) {
                result[0] = i + 1;
                result[1] = pos + 1;
                return result;
            }
            // for (int k = i + 1; k < len; ++k)
            // {
            //     if (numbers[i] + numbers[end - 1] < target) {

            //         continue;
            //     }
            //     int sum = numbers[i] + numbers[k];
            //     if (sum == target) {
            //         result[0] = i + 1;
            //         result[1] = k + 1;
            //         return result;
            //     }
            //     if (sum > target) {
            //         break;
            //     }
            // }
        }
        return result;
    }
};

int main()
{
    Solution s;
    int nums[] = {-1, 0};
    std::vector<int> v(nums, nums + 2);
    std::vector<int> v2 = s.twoSum(v, -1);
    for (std::vector<int>::iterator i = v2.begin(); i != v2.end(); ++i)
    {
        cout <<  *i << endl;
    }


    return 0;
}