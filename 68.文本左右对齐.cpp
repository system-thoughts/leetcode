/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

// @lc code=start
class Solution {
public:
    // [start, end)
    void output(vector<string>&res, vector<string>&words, int start, int end, int count, int maxWidth) {
        vector<string> espaces(end - start - 1, " ");
        int i;     
        
        // 需要插入空格
        if (end - start - 1) {
             // 普通情况，插入空格：要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
            if (end != words.size()) {
                int totalEspaces = maxWidth - count;
                int avg = totalEspaces / (end - start - 1);
                int mod = totalEspaces % (end - start - 1);
                for (i = 0; i < mod; i++) {
                    espaces[i] = string(avg + 1, ' ');
                }
                for (i = mod; i < end - start - 1; i++) {
                    espaces[i] = string(avg, ' ');
                }
            }
            string tmp = words[start];
            for (i = 1; i < end - start; i++) {
                tmp += espaces[i - 1] + words[start + i];
            }
            // 最后一行：文本的最后一行应为左对齐，且单词之间不插入额外的空格，行末要补齐
            if (end == words.size() && tmp.size() < maxWidth) {
                tmp += string(maxWidth - tmp.size(), ' ');
            }
            res.push_back(tmp);
        } else {
            res.push_back(words[start] + string(maxWidth - words[start].size(), ' '));
        }
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int start = 0;
        int end = start;
        vector<string> res;
        int count = 0;

        while (end < words.size()) {
            count += words[end].size();
            // if words length is more than maxWidth, fallback
            if (count + (end - start) > maxWidth) {
                // begin to output to oneline
                output(res, words, start, end, count - words[end].size(), maxWidth);
                count = 0;
                start = end;
            } else {
                end++;
            }
        }
        // last line is special
        // 文本的最后一行应为左对齐，且单词之间不插入额外的空格。
        output(res, words, start, end, count, maxWidth);
        return res;
    }
};
// @lc code=end

