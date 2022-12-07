#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {                
        map<int,int> indexMap = {{nums[0],0}};
        for(int i=0; i<nums.size(); i++){
            auto it = indexMap.find(target-nums[i]);
            if( it != indexMap.end() ){
                return { i,it->second };
            }
            indexMap[nums[i]]=i;
        }
        return {0,0};
    }
};


int main(int argc, char** argv){
  vector<int> testcase = {2,7,11,15};

  auto result = Solution::twoSum(testcase, 9);



  return 0;
}