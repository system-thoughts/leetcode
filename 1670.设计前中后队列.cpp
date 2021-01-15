/*
 * @lc app=leetcode.cn id=1670 lang=cpp
 *
 * [1670] 设计前中后队列
 */

// @lc code=start
class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {

    }
    
    void pushFront(int val) {
        auto it = container.begin();
        container.insert(it, val);
    }
    
    void pushMiddle(int val) {
        auto it = container.begin() + container.size() / 2;
        container.insert(it, val);
    }
    
    void pushBack(int val) {
        container.push_back(val);
    }
    
    int popFront() {
        int res;
        if (container.empty())
            return -1;
        auto it = container.begin();
        res = *it;
        container.erase(it);
        return res;
    }
    
    int popMiddle() {
        int res;
        if (container.empty())
            return -1;
        auto it = container.begin() + container.size() / 2 - (container.size() % 2 ? 0 : 1);
        res = *it;
        container.erase(it);
        return res;
    }
    
    int popBack() {
        int res;
        if (container.empty())
            return -1;
        res = container[container.size() - 1];
        container.pop_back();
        return res;
    }
private:
    vector<int> container;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// @lc code=end

