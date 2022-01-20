//
// Created by admin on 2022/1/20.
//
#include <vector>
#include <stack>

using namespace std;

int MacRecSizeFromBottom(const vector<int> &vec) {
    stack<int> s;
    int mx = 0;
    for (int i = 0; i < vec.size(); ++i) {
        while (!s.empty() && vec[s.top()] >= vec[i]) {
            int st = s.top();
            s.pop();
            int left = !s.empty()? s.top() : -1; // 左边最近小
            int curArea = (i - left - 1) * vec[st];
            mx = max(curArea, mx);
        }
        s.push(i);
    }

    while (!s.empty()) {
        int st = s.top();
        s.pop();
        int left = !s.empty()? s.top() :-1; // 左边最近小
        int curArea = (vec.size() - left - 1) * vec[st];
        mx = max(curArea, mx);
    }
    return mx;
}

int MaxRecSize(const vector<vector<int>> &rec) {
    vector<int> heights(rec[0].size(), 0);
    int mx = 0;
    for (int i = 0; i < rec.size(); ++i) {
        for (int j = 0; j < rec[i].size(); ++j) {
            heights[j] = rec[i][j]? heights[j] + 1: 0;
        }
        mx = max(mx, MacRecSizeFromBottom(heights));
    }
    return mx;
}

void TestMaxRecSize() {
    vector<vector<int>> rec = {
            {1, 0, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 1, 0},
    };
    printf("max size: %d\n", MaxRecSize(rec));
}