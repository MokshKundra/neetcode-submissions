/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    void serializeHelper(TreeNode* root, string& s) {
        if (!root) {
            s += "null,";
            return;
        }

        s += to_string(root->val) + ",";
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        serializeHelper(root, s);
        return s;
    }

    TreeNode* deserializeHelper(queue<string>& q) {
        string cur = q.front();
        q.pop();

        if (cur == "null")
            return nullptr;

        TreeNode* node = new TreeNode(stoi(cur));
        node->left = deserializeHelper(q);
        node->right = deserializeHelper(q);

        return node;
    }

    TreeNode* deserialize(string data) {
        queue<string> q;
        string token;
        stringstream ss(data);

        while (getline(ss, token, ','))
            q.push(token);

        return deserializeHelper(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));