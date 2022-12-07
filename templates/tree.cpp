#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
    static TreeNode *build(const vector<string> &in, int idx = 0);
    static void destroy(TreeNode *root);
    static void print(const TreeNode *root);
};


TreeNode *TreeNode::build(const vector<string> &in, int idx) {
    if (idx >= in.size()) {
        return nullptr;
    }
    if( in[idx]=="null" ){
      return nullptr;
    }

    TreeNode *curr = new TreeNode(stoi(in[idx]));
    int left_idx = 2 * idx + 1;
    int right_idx = 2 * idx + 2;
    curr->left = build(in, left_idx);
    curr->right = build(in, right_idx);

    return curr;
};
void TreeNode::destroy(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    destroy(root->left);
    destroy(root->right);
    delete root;
    return;
};
void TreeNode::print(const TreeNode *root) {
    if (root == nullptr) {        
        return;
    }
    print(root->left);
    cout << root->val << " ";
    print(root->right);
};
