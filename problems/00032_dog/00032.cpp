#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;
string ltrim(const string &str);
string rtrim(const string &str);
vector<string> split(const string &str);
string stripends(const string &str, char c='"');

class Solution {
public:
    int callme(string s) {
        
        return 0;
    }
};

int main(int argc, char**argv){
  Solution solution;
  string a;
  while (getline(cin, a)) {    
    a=stripends(ltrim(rtrim(a)));
    cout << "Input: " << a << "\n";
    cout << split(a).size() << "\n";
    cout << "callme(a)=" << solution.callme(a) << "\n";    
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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

string stripends(const string &str, char c) {    
    int start=0;
    int end=str.size()-1;
    while( str[start]==c ){
      start++;
    }
    end=start+1;
    while( str[end]!=c ){
      end++;
    }
    return str.substr(start,end-start);    
}

