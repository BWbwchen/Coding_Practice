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
    int id;
    const string EMPTY = "!";
    const char EMPTYCHAR = '!';
    string ans;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ans = "";
        buildString(root);  
        return ans;
    }
    void buildString(TreeNode* root) {
        if (root == nullptr) {
            ans += EMPTY + ",";
            return;
        }
        
        ans += to_string(root->val) + ",";
        buildString(root->left);
        buildString(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        id = 0;
        return buildTree(data);
    }
    
    TreeNode* buildTree(string data) {
        if (data[id] == EMPTYCHAR) {
            id += 2;
            return nullptr;
        }
        
        TreeNode* temp = new TreeNode(helper(data));
        temp->left = buildTree(data);
        temp->right = buildTree(data);
        return temp;
    }
    
    int helper(string data) {
        int ans = 0;
        if (data[id] == '-')  {
            int i;
            for (i = id+1; i < data.size() && data[i] != ','; ++i) {
                ans = 10*ans + (data[i] - '0'); 
            }
            id = i+1;
            return -ans; 
        } else {
            int i;
            for (i = id; i < data.size() && data[i] != ','; ++i) {
                ans = 10*ans + (data[i] - '0'); 
            }
            id = i + 1; 
            return ans;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
