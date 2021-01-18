/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string duplicate(string s, int num) {
        string res;
        for (int i = 0; i < num; i++)
            res += s;
        return res;
    }
    string decodeString(string s) {
        string res;
        stack<string> st;
        int i = 0;
        int point = i;

        while (i < s.size()) {
            if (s[i] == '[') {
                st.push("[");
                i++;
            } else if (s[i] == ']') {
                string s;
                while (st.top() != "[") {
                    s = st.top() + s;
                    st.pop();
                }
                // pop [
                st.pop();
                int num = stoi(st.top());
                s = duplicate(s, num);
                // pop num
                st.pop();
                st.push(s);
                i++;
            } else if (isdigit(s[i])) {
                while (isdigit(s[i]))
                    i++;
                st.push(s.substr(point, i - point));
            } else {
                while (isalpha(s[i]))
                    i++;
                st.push(s.substr(point, i - point));
            }
            point = i;
        }
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};
// @lc code=end

