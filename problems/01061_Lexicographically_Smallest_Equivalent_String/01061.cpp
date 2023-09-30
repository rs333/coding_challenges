#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
    vector<set<int>> adj;
    vector<int> converter;
  public:

    string smallestEquivalentString(string s1, string s2, string &baseStr) {
        adj.resize(26);

        for( int i=0; i<s1.size(); i++ ){
            int c1=s1[i]-'a';
            int c2=s2[i]-'a';            
            
            adj[c1].insert(c2);            
            adj[c2].insert(c1);
        }
        
        converter.resize(26);

        iota(converter.begin(), converter.end(),0);
        vector<bool> visited(26,false);
        for( int i=0; i<adj.size(); i++ ){
            cout << static_cast<char>(i+'a') << " - ";
            for( auto c : adj[i] ){
                cout << static_cast<char>(c+'a') << " ";
            }
            cout << "\n";            
            if( adj[i].size() == 0 ) continue;
            queue<int> q;
            
            q.push(i);
            visited[i]=true;
            while( q.size() > 0 ){
                auto curr=q.front();
                q.pop();
                if( curr < converter[i] ) converter[i]=curr;
                for( auto next : adj[curr] ){
                    if( visited[next] ) continue;
                    q.push(next);
                    visited[next]=true;              
                    if( converter[i] < converter[next] ) converter[next]=converter[i];
                }
            }
        }
        for( int i=0 ;i<baseStr.size(); i++ ){
            baseStr[i] = converter[baseStr[i]-'a']+'a';
        }

        return baseStr;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    string a = "parker";
    string b = "morris";
    string c = "parser";
    auto result = solution.smallestEquivalentString(a, b, c);
    cout << result << "\n";
    a = "gmerjboftfnqseogigpdnlocmmhskigdtednfnjtlcrdpcjkbj";
    b = "fnnafafhqkitbcdlkpiloiienikjiikdfcafisejgeldprcmhd";
    c = "ezrqfyguivmybqcsvibuvtajdvamcdjpmgcbvieegpyzdcypcx";
    result = solution.smallestEquivalentString(a, b, c);
    cout << result << "\n";
    return 0;
}