/*
 * @lc app=leetcode.cn id=1234 lang=cpp
 *
 * [1234] 替换子串得到平衡字符串
 */

// @lc code=start
class Solution {
public:
    bool isWindowCover(unordered_map<char, int>& map) {
        for (auto c : map) {
            if (c.second > 0)
                return false;
        }
        return true;
    }
    int balancedString(string s) {
        int res = numeric_limits<int>::max();
        int len;
        auto first = s.begin();
        auto last = first;
        unordered_map<char, int> map = {{'Q', 0}, {'W', 0}, {'E', 0}, {'R', 0}};
        // 分别计数'Q' 'W' 'E' 'R'出现的次数
        for (auto c : s) {
            map[c]++;
        }
        // 保留hash表大于平均数的元素
        auto it = map.begin();
        while(it != map.end()) {
            if (it->second <= s.size() / 4) {
                map.erase(it++);
            } else {
                // 大于平均数的元素应该被替换的数目
                it->second -= s.size() / 4;
                it++;
            }
        }
        if (map.empty())
            return 0;
        while (last != s.end()) {
            // 窗口一直向左滑动（增长），包含所有所需删除的元素
            if (map.count(*last))
                map[*last]--;
            if (isWindowCover(map)) {
                // 窗口向右滑动,shrink
                while (first + 1 <= last) {
                    if(map.count(*first))
                        map[*first]++;
                    if (isWindowCover(map)) {
                        first++;
                    } else {
                        // backtrace
                        if(map.count(*first))
                            map[*first]--;
                        break;
                    }
                }
                len = last - first + 1;
                res = len < res ? len : res;
            }
            last++;
        }
        return res;
    }
};
// @lc code=end

