#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
string ltrim(const string &str);
string rtrim(const string &str);
vector<string> split(const string &str, char c=' ');
string stripends(const string &str, char c = '"');

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

class Solution {
  public:
    int rangeSumBST(TreeNode *root, int low, int high) {        
        if( root==nullptr ){
          return 0;
        }
        int sum=0;
        if( root->val >= low && root->val <=high ){
          sum+=root->val;
        }
        return sum+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
    }
};

int main(int argc, char **argv) {
    Solution solution;
    string a;
    TreeNode *root;
    int low=0;
    int high=0;
    while (getline(cin, a)) {        
        a = stripends(ltrim(rtrim(a)),'[');
        cout << "Input: " << a << "\n";
        root = TreeNode::build(split(a,','));
        getline(cin,a);
        low=stoi(a);
        getline(cin,a);
        high=stoi(a);        
        cout << "rangeSumBST(a)=" << solution.rangeSumBST(root,low,high) << "\n";
    }
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(s.begin(),
            find_if_not(s.begin(), s.end(), [](char c) { return isspace(c); }));

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(find_if_not(s.rbegin(), s.rend(), [](char c) { return isspace(c); })
                .base(),
            s.end());

    return s;
}

vector<string> split(const string &str, char c) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(c, start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

string stripends(const string &str, char c) {
    int start = 0;
    int end = str.size() - 1;
    while (str[start] == c) {
        start++;
    }
    end = start + 1;
    if (c == '[')
        c = ']';
    while (str[end] != c) {
        end++;
    }
    return str.substr(start, end - start);
}

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
