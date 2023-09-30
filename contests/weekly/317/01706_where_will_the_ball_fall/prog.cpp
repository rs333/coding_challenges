#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> balls(grid[0].size(),0);
        iota(balls.begin(),balls.end(),0);
        
        for(int row=0; row< grid.size(); row++){
            for(int ball=0; ball<balls.size(); ball++){                
                int curr_col = balls[ball];
                if (curr_col < 0 ){
                    cout << "S ";
                    continue;
                }
                int next_col = curr_col + grid[row][curr_col];
                if( next_col < 0 
                   || next_col >= balls.size()
                   || grid[row][curr_col] == -grid[row][next_col] ){
                    balls[ball] = -1;
                    cout << "S ";
                    continue;
                }
                balls[ball]+=grid[row][curr_col];                                
                cout << balls[ball] << " ";
            }
            cout << " \n";
        }
        return balls;
        
    }
};