#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        
        return 0;
    }
};

int main(int argc, char**argv){
  Solution solution;
  string a;
  while (getline(cin, a)) {
    cout << "Input: " << a << "\n";
    cout << "longestValidParentheses(a)=" << solution.longestValidParentheses(a) << "\n";
    
  }    
  return 0;
}