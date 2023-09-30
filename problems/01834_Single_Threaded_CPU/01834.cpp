#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

class Solution {
    static bool cmp(vector<int> &a, vector<int> &b) {
        int l = min(a.size(), b.size());
        for (int i = 0; i < l; i++) {
            if (a[i] < b[i])
                return true;
            if (a[i] > b[i])
                return false;
        }
        return false;
    }

  public:
    void print(
        priority_queue<vector<int>, vector<vector<int>>, decltype(&cmp)> qtmp) {
        while (qtmp.size() > 0) {
            auto ctmp = qtmp.top();
            qtmp.pop();
            cout << -ctmp[1] << " {" << -ctmp[2] << "," << -ctmp[0] << "}"
                 << "\n";
        }
    };

  public:
    vector<int> getOrder(vector<vector<int>> &tasks) {
        vector<int> order;

        priority_queue<vector<int>, vector<vector<int>>, decltype(&cmp)> q(
            &cmp),
            qtmp(cmp);

        vector<int> idx(tasks.size(), 0);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&tasks](int i1, int i2) {
            if (tasks[i1][0] < tasks[i2][0])
                return true;
            if (tasks[i1][0] > tasks[i2][0])
                return false;
            if (tasks[i1][1] < tasks[i2][1])
                return true;
            return false;
        });

        for (auto i : idx) {
            cout << i << " ";
        }
        cout << "\n";
        int tick = 0;
        int task = 0;
        vector<int> curr(2, -1);

        int time_remaining = 0;
        int i = 0;
        while (i < idx.size() || q.size() > 0) {
            if( time_remaining > 0 ){
                tick+=time_remaining;
                time_remaining=0;
            }else{
                tick=tasks[idx[i]][0];
            }
            while (i < idx.size()) {
                int p_time = tasks[idx[i]][1];
                int q_time = tasks[idx[i]][0];

                if (q_time > tick) {
                    break;
                }
                q.push({-p_time, -idx[i], -q_time});
                i++;
            }
            cout << "Tick=" << tick << "\n";
            print(q);
            if (q.size() > 0 && time_remaining <= 0) {
                cout << "tick: " << tick << " q.size(): " << q.size() << "\n";

                cout << "Starting process " << -q.top()[1] << "\n";
                time_remaining = -q.top()[0];
                order.push_back(-q.top()[1]);
                q.pop();
            }
        }

        return order;
    }
};

int main(int argc, char **argv) {
    vector<vector<int>> input1 = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
    vector<vector<int>> input2 = {{7, 10}, {7, 12}, {7, 5}, {7, 4}, {7, 2}};
    vector<vector<int>> input3 = {
        {19, 13}, {16, 9},  {21, 10}, {32, 25}, {37, 4},  {49, 24}, {2, 15},
        {38, 41}, {37, 34}, {33, 6},  {45, 4},  {18, 18}, {46, 39}, {12, 24}};
    vector<vector<int>> input4 = {{1000000000,1000000000}};
    Solution s;

    vector<int> ans = s.getOrder(input4);
    for (auto v : ans) {
        cout << ">" << v << "< ";
    }
    cout << endl;

    return 0;
}