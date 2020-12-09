/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// 先尝试使用push_back往unordered_set中添加元素，如果不行，则使用emplace
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node *> newGraph;
        queue<Node *> perimeter;
        unordered_set<Node *> visited;

        if (node == nullptr)
            return nullptr;

        Node *newNode = new Node(node->val);
        newGraph[node->val] = newNode;
        perimeter.push(node);
        visited.emplace(node);

        while (!perimeter.empty()) {
            auto s = perimeter.front();
            for (const auto & n : s->neighbors) {
                if (visited.find(n) == visited.end()) {
                    // if not visit, create new node
                    // So all the visited Node has created copy
                    Node *tmp = new Node(n->val);
                    newGraph[tmp->val] = tmp;
                    perimeter.push(n);
                    visited.emplace(n);
                }
                // update new Node's neighbors
                newGraph[s->val]->neighbors.push_back(newGraph[n->val]);
            }
            perimeter.pop();
        }
        return newNode;
    }
};
// @lc code=end

