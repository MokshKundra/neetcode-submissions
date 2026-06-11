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

class Solution {
public:
    unordered_map<int, Node*> newNodes;

    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        if (newNodes.find(node->val) != newNodes.end()) return newNodes[node->val];

        Node* newNode = new Node(node->val);
        newNodes[node->val] = newNode;

        for (Node* neighbor : node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return newNode;
    }
};