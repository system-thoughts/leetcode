/*
 * @lc app=leetcode.cn id=468 lang=cpp
 *
 * [468] 验证IP地址
 */

// @lc code=start
class Solution {
public:
    bool isIPv4(string field) {
        if (field.empty() || field.size() > 3)
            return false;
        for (auto c : field) {
            if (!isdigit(c))
                return false;
        }
        if (field.find('0') == 0)
            return field.size() == 1;
        return stoi(field) < 256;
    }
    bool isIPv6(string field) {
        if (field.empty() || field.size() > 4)
            return false;
        for (auto c : field) {
            if (!isdigit(c) && !((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')))
                return false;
        }
        return true;
    }
    string validIPAddress(string IP) {
        if (IP.empty())
            return "Neither";
        string::size_type index = 0;
        auto next = index;
        int count = 0;

        if (IP.find('.') != string::npos) {
            // IPv4 check
            while ((next = IP.find('.', index)) != string::npos) {
                if (!isIPv4(IP.substr(index, next - index)))
                    return "Neither";
                index = next + 1;
                count++;
            }
            return count == 3 && isIPv4(IP.substr(index, IP.size() - index)) ? "IPv4" : "Neither";
        } else if (IP.find(':') != string::npos) {
            // IPv6 check
            while ((next = IP.find(':', index)) != string::npos) {
                if (!isIPv6(IP.substr(index, next - index)))
                    return "Neither";
                index = next + 1;
                count++;
            }
            return count == 7 && isIPv6(IP.substr(index, IP.size() - index)) ? "IPv6": "Neither";
        } else {
            return "Neither";
        }
    }
};
// @lc code=end

