#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {

  public:
    string callme() {
   

        return "dog";
    }
};

int main(int argc, char **argv) {
    Solution solution;
   
    auto result = solution.callme();
    cout << result << "\n";
   
    return 0;
}