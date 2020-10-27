/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        auto iter1 = nums1.begin();
        auto iter2 = nums2.begin();
        auto iter = iter1;
        while (iter1 != nums1.end() && iter2 != nums2.end())
        {
            if (*iter1 < *iter2)
            {
                iter = iter1++;
            }
            else
            {
                iter = iter2++;
            }
            res.push_back(*iter);
        }
        if (iter1 != nums1.end())
        {
            while (iter1 != nums1.end())
            {
                res.push_back(*iter1);
                iter1++;
            }
        }
        else
        {
            while (iter2 != nums2.end())
            {
                res.push_back(*iter2);
                iter2++;
            }
        }
        if (res.size() % 2)
        {
            return res[res.size() / 2];
        }
        else
        {
            return (double)(res[res.size() / 2 - 1] + res[res.size() / 2]) / 2;
        }
    }
};
// @lc code=end
