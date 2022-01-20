//
// Created by admin on 2022/1/8.
//

#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

vector<int> GetMaxWindow(const vector<int> &vec, int w) {
    vector<int> res;
    deque<int> q;
    for (int i  = 0; i < vec.size(); i++) {
        if (q.empty()) {
            q.push_back(i);
        }
        while (!q.empty() && vec[q.back()] < vec[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (q.front())
        if (i - q.front() == w) q.pop_front();
        if (i + 1 >= w) res.push_back(vec[q.front()]);
    }
    return res;
}

void TestGetMaxWindow() {
    vector<int> vec = {4, 3, 5, 4, 3, 3, 6, 7};
    vector<int> res = GetMaxWindow(vec, 3);
    for (int &v : res) {
        printf("%d ", v);
    }
}