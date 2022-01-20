//
// Created by admin on 2022/1/20.
//
#include <vector>
#include <deque>

using namespace std;

int GetNum(const vector<int> &vec, int num) {
    deque<int> qmax;
    deque<int> qmin;
    int i = 0;
    int j = 0;
    int res = 0;
    for (int i = 0; i < vec.size(); ++i) {
        while (j < vec.size()) {
            if (qmin.empty() || qmin.back() != j) { // 上次 j 没过时，j已经入过列，因此这里不用再入列
                while (!qmax.empty() && qmax.back() <= vec[i]) {
                    qmax.pop_back();
                }
                qmax.push_back(i);

                while (!qmin.empty() && qmin.back() >= vec[i]) {
                    qmin.pop_back();
                }
                qmin.push_back(i);
            }

            if (qmax.front() - qmin.front() > num) {
                break;
            }
            ++j;
        }

        res += j - i;
        if (qmax.front() == i) { // 当 i 右移时，需要判断，目前 i 是不是窗口最大或者最小值，如果是，则需要 pop
            qmax.pop_front();
        }
        if (qmin.front() == i) {
            qmin.pop_front();
        }
        ++i;
    }
    return res;
}

void TestGetNum() {
    vector<int> vec = {5, 6, 9, 7};
    int num = 4;
    int res = GetNum(vec, num);
    printf("res: %d\n", res);
}