#include <string>
#include <vector>
using namespace std;

struct TrieNode {
    vector<TrieNode *> next = vector<TrieNode *>(26, nullptr);

    int count = 0;
    string word;

    static TrieNode *addWord(TrieNode *root, string word) {
        if (root == nullptr) {
            root = new TrieNode();
        }
        TrieNode *curr = root;
        int i = 0;
        while (i < word.size()) {
            int l = word[i] - 'a';
            if (curr->next[l] == nullptr) {
                curr->next[l] = new TrieNode();
            }
            curr = curr->next[l];
            i++;
        }
        curr->count++;
        curr->word = word;
        return root;
    }
    static void print(TrieNode *root) {
        if (root == nullptr) {
            return;
        }
        printf("%x (%s,%d)\n", root, root->word.c_str(), root->count);
        for (int i = 0; i < 26; i++) {
            if (root->next[i] != nullptr) {
                print(root->next[i]);
            }
        }
    }
    static void search(vector<vector<char>> &board, int r, int c,
                       TrieNode *root, vector<string> &ans) {
        int R = board.size();
        int C = board[0].size();
        if (root == nullptr) {
            return;
        }

        if (root->count > 0) {
            ans.push_back(root->word);
            root->count--;
        }

        char ch = board[r][c];
        board[r][c] = '!';

        if (r > 0 && board[r - 1][c] != '!') {
            search(board, r - 1, c, root->next[board[r - 1][c] - 'a'], ans);
        }

        if (r + 1 < R && board[r + 1][c] != '!') {
            search(board, r + 1, c, root->next[board[r + 1][c] - 'a'], ans);
        }

        if (c > 0 && board[r][c - 1] != '!') {
            search(board, r, c - 1, root->next[board[r][c - 1] - 'a'], ans);
        }

        if (c + 1 < C && board[r][c + 1] != '!') {
            search(board, r, c + 1, root->next[board[r][c + 1] - 'a'], ans);
        }

        board[r][c] = ch;
    }
};