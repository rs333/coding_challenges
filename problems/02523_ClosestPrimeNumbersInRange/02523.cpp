#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
    int N = 1e6;

  public:
    vector<bool> prime;
    void genPrimes() {
        prime = vector<bool>(N + 1, true);

        for (auto p = 2; p * p <= N; p++) {
            if (prime[p]) {
                for (auto i = p * p; i <= N; i += p) {
                    prime[i] = false;
                }
            }
        }
        int c = 1;
        for (auto p = 2; p <= N; p++) {
            if (prime[p]) {
                c++;
            }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        genPrimes();

        vector<int> primes;

        for (int i = max(left, 2); i <= right; i++) {
            if (prime[i]) {
                primes.push_back(i);
            }
        }
        int nums1 = -1;
        int nums2 = -1;
        int mindelta = INT_MAX;
        for (int i = 1; i < primes.size(); i++) {
            if (primes[i] - primes[i - 1] < mindelta) {
                nums1 = primes[i - 1];
                nums2 = primes[i];
                mindelta = primes[i] - primes[i - 1];
            }
        }

        return {nums1, nums2};
    }
};

int main(int argc, char **argv) {
    Solution solution;

    auto ans = solution.closestPrimes(4, 6);
    assert( ans[0] == -1 );
    assert( ans[1] == -1 );

    ans = solution.closestPrimes(10,19);
    assert( ans[0] == 11 );
    assert( ans[1] == 13 );
    return 0;
}