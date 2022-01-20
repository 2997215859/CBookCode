//
// Created by admin on 2022/1/20.
//
#include <vector>
#include <stack>

using namespace std;

vector<pair<int, int>> GetNearLessNoRepeat(const vector<int> &vec) {
    vector<pair<int, int>> res(vec.size());

    stack<int> s;
    for (int i = 0; i < vec.size(); ++i) {
        while (!s.empty() && vec[s.top()] > vec[i]) {
            int st = s.top();
            res[st].second = i;
            s.pop();
            res[st].first = !s.empty()? s.top(): -1;
        }
        s.push(i);
    }

    while (!s.empty()) {
        int st = s.top();
        res[st].second = -1;
        s.pop();
        res[st].first = !s.empty()? s.top(): -1;
    }
    return res;
}

void TestGetNearLessNoRepeat() {
    vector<int> vec = {3, 4, 1, 5, 6, 2, 7};
    auto res = GetNearLessNoRepeat(vec);
    for (auto &p :res) {
        printf("{%d, %d}\n", p.first, p.second);
    }
}

vector<pair<int, int>> GetNearLessRepeat(const vector<int> &vec) {
    vector<pair<int, int>> res(vec.size());

    stack<vector<int>> s;
    for (int i = 0; i < vec.size(); ++i) {
        while (!s.empty() && vec[s.top()[0]] > vec[i]) {
            vector<int> st = s.top();
            s.pop();
            for (int j = 0; j < st.size(); ++j) {
                res[st[j]].second = i;
                res[st[j]].first = !s.empty()? s.top().back(): -1;
            }
        }
        if (!s.empty() && vec[s.top().back()] == vec[i]) {
            s.top().push_back(i);
        } else {
            s.push(vector<int>{i});
        }
    }

    while (!s.empty()) {
        vector<int> st = s.top();
        s.pop();
        for (int i = 0; i < st.size(); ++i) {
            res[st[i]].second = -1;
            res[st[i]].first = !s.empty()? s.top().back(): -1;
        }
    }
    return res;
}

void TestGetNearLessRepeat() {
    vector<int> vec = {3, 1, 3, 4, 3, 5, 3, 2, 2};
    auto res = GetNearLessRepeat(vec);
    for (auto &p :res) {
        printf("{%d, %d}\n", p.first, p.second);
    }
}