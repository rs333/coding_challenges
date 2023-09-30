#include "data.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int s=0;
        int f=1;
        bool lastWasMove=false;
        while( f < points.size() ){
            if( points[s][1] < points[f][0] ){                            
                s++;
                if( s!=f ){
                    points[s]=points[f];
                }
                f++;
                continue;
            }
            lastWasMove=false;
            while( f< points.size() && points[s][1] >= points[f][0] ){
                if( points[s][0] < points[f][0] ){
                    points[s][0] = points[f][0];
                }
                if( points[s][1] > points[f][1] ){
                    points[s][1] = points[f][1];
                }
                f++;          
            }
            
            if( f < points.size()){
                s++;
                points[s]=points[f];
                f++;
            }           
        }        
        s++;
        
        
        return s;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    vector<vector<int>> small_input={{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};
    int ans;
    ans = solution.findMinArrowShots(small_input);
    cout << "Answer is: " << ans << " and should be 2" << "\n";

    ans = solution.findMinArrowShots(large_input);
    cout << "Answer is: " << ans << " and should be 213" << "\n";
    return 0;
}
