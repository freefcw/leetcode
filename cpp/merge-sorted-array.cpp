#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        if (n == 0) {
            return;
        }
        int pos = 0;

        for (int i = 0; i < n; ++i)
        {
            while (true) {
                // find pos
                if (nums2[i] <= nums1[pos]) {
                    break;
                }
                pos++;
                if (pos >= m) {
                    break;
                }
            }
            for (int k = m; k > pos; k--)
            {
                nums1[k] = nums1[k - 1];
            }
            m++;
            nums1[pos] = nums2[i];
        }
    }
};

int main()
{
    Solution s;
    int nums1[] = {};
    int nums2[] = {1};
    vector<int> vn1(nums1, nums1 + 1);
    vector<int> vn2(nums2, nums2 + 1);

    s.merge(vn1, vn1.size(), vn2, vn2.size());
    cout << endl;
    for (int i = 0; i < vn1.size(); ++i)
    {
        cout << vn1[i] << ':';
    }
    cout << endl;
    // cout << s.merge(vn1,3, vn2,3) << endl;

    return 0;
}