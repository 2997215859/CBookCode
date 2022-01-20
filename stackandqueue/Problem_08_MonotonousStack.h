//
// Created by admin on 2022/1/8.
//

#include <cstdio>
#include <vector>

using namespace std;

vector<pair<int, int>> MonotonousStack(const vector<int> &vec) {
    int N = vec.size();
    vector<pair<int, int>> res(N);

}

void TestMonotonousStack() {
    vector<int> vec = {3, 4, 1, 5, 6, 2, 7};
    auto res = MonotonousStack(vec);
    for (auto &p: res) {
        printf("%d %d\n", p.first, p.second);
    }
}