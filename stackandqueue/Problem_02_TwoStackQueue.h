//
// Created by admin on 2021/11/14.
//
#include <stack>
#include <iostream>

using namespace std;

class TwoStackQueue {
private:
    stack<int> stackPush;
    stack<int> stackPop;
    void pushToPop() {
        while (stackPop.empty()) {
            while (!stackPush.empty()) {
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }
    }
public:
    void Add(int v) {
        stackPush.push(v);
        pushToPop();
    }

    int Poll() {
        if (stackPop.empty() && stackPush.empty()) return 0;
        pushToPop();
        int t = stackPop.top();
        stackPop.pop();
        return t;
    }

    int Peek() {
        if (stackPop.empty() && stackPush.empty()) return 0;
        pushToPop();
        return stackPop.top();
    }
};

void TestTwoStackQueue() {
    TwoStackQueue q;
    q.Add(1); cout << q.Peek() << endl;
    q.Add(2); cout << q.Peek() << endl;
    q.Add(3); cout << q.Peek() << endl;
    q.Add(4); cout << q.Peek() << endl;
    q.Add(5); cout << q.Peek() << endl;

    q.Poll(); cout << q.Peek() << endl;
    q.Poll(); cout << q.Peek() << endl;
    q.Poll(); cout << q.Peek() << endl;
    q.Poll(); cout << q.Peek() << endl;
    q.Poll(); cout << q.Peek() << endl;
}