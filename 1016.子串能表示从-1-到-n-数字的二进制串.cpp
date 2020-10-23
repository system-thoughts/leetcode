/*
 * @lc app=leetcode.cn id=1016 lang=cpp
 *
 * [1016] 子串能表示从 1 到 N 数字的二进制串
 * 不需要遍历1~N的每个数字去判断改数字的二进制表示的字符串是字符串S的子串
 * 从N/2 + 1开始遍历，一直到N即可，1~N/2的所有数字的二进制表示肯定是N/2 + 1 ~ N的二进制的子串
 * 如N = 9
 * 1000 1001
 * 100 101 110 111
 * 10 11
 * 0 1
 * (0, 1, 10, 11, 100)肯定是(101, 110, 111, 1000, 1001)中数字的子串
 */
// @lc code=start
class Solution {
public:
    bool queryString(string S, int N) {
        int i;
        string str, binStr;
        string::size_type idx;
        size_t pos;
        for (i = N / 2 + 1; i <= N; i++) {
            bitset<30> bst(i);
            str = bst.to_string();
            pos = str.find_first_of('1');
            binStr = str.substr(pos);
            idx = S.find(binStr);
            if (idx == string::npos) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

