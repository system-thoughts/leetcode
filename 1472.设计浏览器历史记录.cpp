/*
 * @lc app=leetcode.cn id=1472 lang=cpp
 *
 * [1472] 设计浏览器历史记录
 */

// @lc code=start
class BrowserHistory {
private:
    vector<string> history;
    int cur;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        cur = 0;
    }
    
    void visit(string url) {
        while (cur != history.size() - 1) {
            history.pop_back();
        }
        history.push_back(url);
        cur++;
    }
    
    string back(int steps) {
        cur = cur - steps >= 0 ? cur - steps : 0;
        return history[cur];
    }
    
    string forward(int steps) {
        cur = cur + steps >= history.size() ? history.size() - 1 : cur + steps;
        return history[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end

