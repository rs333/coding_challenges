#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>

using namespace std;
string ltrim(const string &str);
string rtrim(const string &str);
vector<string> split(const string &str, char c=',');
string stripends(const string &str, char c='"');
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
    static TreeNode *build(const vector<string> &in, int &idx );
    static void destroy(TreeNode *root);
    static void print(const TreeNode *root);
    static void printLevel(const TreeNode *root);
};
class Solution {
public:
    
    int maxAncestorDiff(TreeNode* root, int maxVal=INT_MIN, int minVal=INT_MAX) {
        if(root==nullptr){
            return 0;
        }

        if( root->val < minVal ){
            minVal = root->val;
        }
        if( root->val > maxVal ){
            maxVal = root->val;
        }

        int diff=abs(maxVal-minVal);
        cout << root << " " << root->val << " root->left " << root->left << "\n";
        diff=max(diff,maxAncestorDiff(root->left,maxVal,minVal));
        cout << root << " " << root->val << " root->right " << root->right << "\n";
        diff=max(diff,maxAncestorDiff(root->right,maxVal,minVal));

        return diff;
    }
};

// A Tree
int main(int argc, char **argv) {
    Solution solution;
    string a;
    TreeNode *root;
    int low=0;
    int high=0;
    while (getline(cin, a)) {        
        int i=0;
        a = stripends(ltrim(rtrim(a)),'[');
        cout << "Input: " << a << "\n";
        root = TreeNode::build(split(a,','),i);           
        cout << "\n";     
        TreeNode::print(root);
        cout << "\n";     
        TreeNode::printLevel(root);
        cout << "\n";
        cout << "maxAncestorDiff(a)=" << solution.maxAncestorDiff(root) << "\n";
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
// [1,null,2,null,0,3]
TreeNode *TreeNode::build(const vector<string> &in, int &idx) {    
    if (idx >= in.size()) {
        return nullptr;
    }
    cout << idx << " ";
    
    // int left_idx = idx + 1;
    // int right_idx = idx + 2;
    TreeNode *curr=nullptr;
    
    if( in[idx]!="null" ){
      curr=new TreeNode(stoi(in[idx]));    
      cout << in[idx] << " ";
      curr->left = build(in, idx);
      idx=idx+1;
      cout << in[idx] << " ";
      curr->right = build(in, idx);
      idx=idx+1;
      
    }

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
        cout << "n ";     
        return;
    }
    cout << root->val << " ";
    print(root->left);    
    print(root->right);
};

void TreeNode::printLevel(const TreeNode *root){
    queue<const TreeNode *> q;
    q.push(root);
    while(q.size() > 0 ){
        const TreeNode *curr=q.front();
        q.pop();
        if( curr == nullptr ){
            cout << "n ";
            continue;
        }else{
            cout << curr->val << " ";
        }
        q.push( curr->left );
        q.push( curr->right );
    }
}
