#include <vector>
#include <numeric>
#include <stdint.h>
class Solution {
public:
    uint64_t minCost(std::vector<int>& nums, std::vector<int>& cost) {
        std::gcd(3,6);
        uint64_t maxcost_idx=0;
        uint64_t sum = 0;
        uint64_t costsum = 0;
        for(int i=0; i<cost.size(); i++){
            sum += static_cast<uint64_t>(nums[i])*static_cast<uint64_t>(cost[i]);
            costsum += cost[i];
        }
        uint64_t goal = sum/costsum ;
        uint64_t totalcost = 0;
        for(int i=0; i<cost.size(); i++){
            totalcost += (static_cast<uint64_t>(nums[i])-goal)*cost[i];            
        }
        return totalcost;
    }
};