#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

class Solution {
    int M=0;
    int N=0;
    pair<int,int> stop;
    int MAX_COUNT=0;
    int good_paths=0;
public:

    void dfs(int m, int n, vector<vector<bool>> &visited, int count){
        if( m<0 || m>=M || n<0 || n>=N){
            return;
        }
        if( visited[m][n] != 0 ){
            return;
        }
  
        if(m==stop.first && n==stop.second){
            
            if( count == MAX_COUNT ){
                good_paths++;                            
            }
            
            return;
        }        
        visited[m][n] = true;
        dfs(m+1,n,visited,count+1); 
        dfs(m-1,n,visited,count+1);    
        dfs(m,n+1,visited,count+1);    
        dfs(m,n-1,visited,count+1);
        visited[m][n] = false;
    
    }
    int uniquePathsIII(vector<vector<int>>& grid) {        
        M=grid.size();
        N=grid[0].size();        
        pair<int,int> start;
        vector<vector<bool>> visited(M,vector<bool>(N,0));        
        for(int m=0; m<M; m++){
            for(int n=0; n<N; n++){
                if( grid[m][n]< 0 ){
                    visited[m][n]=1;
                }else if( grid[m][n] ==1 ){
                    start.first=m;
                    start.second=n;                    
                }else if( grid[m][n] ==2 ){
                    stop.first=m;
                    stop.second=n;                    
                }else{
                    MAX_COUNT++;
                }
            }
        }
        MAX_COUNT+=2;
        
        dfs(start.first,start.second,visited,1);

        return good_paths;
    }
};
int main(int argc, char**argv){
  Solution solution;
  vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
  
  auto result = solution.uniquePathsIII(grid);

  cout << "Unique paths: " << result << "\n";
  return 0;
}
