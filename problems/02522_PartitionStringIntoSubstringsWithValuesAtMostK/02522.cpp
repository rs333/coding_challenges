#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
class Solution {
    int L;
    int K;
    int S;

  public:
    int dfs(string &s, int next) {
        if (next >= S) {
            return 0;
        }
        int avail = S - next;        
        if (avail < L) {
            return 1;
        }
        if (avail == L) {
            if (stoi(s.substr(next, avail)) <= K) {
                return 1;
            } else {
                return 2;
            }
        }

        int longtry = stoi(s.substr(next, L));
        int shorttry = 0;
        if (L > 1) {
            shorttry = stoi(s.substr(next, L - 1));

        }
        int lval = -1;
        if (longtry <= K) {            
            lval = dfs(s, next + L);
        }

        int sval = -1;
        if (L > 1) {
            sval = dfs(s, next + L - 1);
        }

        if (lval >= 0 && sval >= 0 && lval < sval) {
            return lval + 1;
        } else if (lval >= 0 && sval < 0) {
            return lval + 1;
        } else if (sval >= 0) {
            return sval + 1;
        }
        return -1;
    }

    int minimumPartition(string s, int k) {
        stringstream ss;
        ss << k;
        L = ss.str().size();
        S = s.size();
        K = k;
        cout << "L=" << L << "\n";
        cout << "K=" << K << "\n";

        return dfs(s, 0);
    }

};

int main(int argc, char **argv) {
    Solution sol;
    string s =
        "4672244363218799171498315499817814442636424382256379581923971212279769"
        "13772844995497627546378544";
    int k = 68;
    int ans = 0;
    ans = sol.minimumPartition(s, k);
    cout << "TLE Testcase: " << ans << "\n";
    s = "165462";
    k = 60;
    ans = sol.minimumPartition(s, k);
    cout << "Example 1: " << ans << "\n";
    s = "238182";
    k = 5;
    ans = sol.minimumPartition(s, k);
    cout << "Example 2: " << ans << "\n";
}