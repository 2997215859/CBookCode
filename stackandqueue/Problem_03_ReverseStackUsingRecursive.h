//
// Created by admin on 2021/11/14.
//
#include <stack>
#include <iostream>

using namespace std;

int getAndRemoveLast(stack<int> &s) {
    int t = s.top();
    s.pop();
    if (s.empty()) {
        return t;
    }

    int last = getAndRemoveLast(s);
    s.push(t);
    return last;
}

void ReverseStackByRecursive(stack<int> &s) {
    if (s.empty()) return;
    int last = getAndRemoveLast(s);
    ReverseStackByRecursive(s);
    s.push(last);
}

void TestReverseStackByRecursive() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    ReverseStackByRecursive(s);
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

}