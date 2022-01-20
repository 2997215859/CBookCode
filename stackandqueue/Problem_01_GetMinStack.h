//
// Created by admin on 2021/11/14.
//
#include <stack>
#include <iostream>

using namespace std;

class GetMinStack {
private:
    stack<int> dataStack;
    stack<int> minStack;

public:
    void Push(int v) {
        dataStack.push(v);
        if (minStack.empty() || v <= minStack.top()) {
            minStack.push(v);
        }
    }
    void Pop() {
        if (minStack.empty()) return;
        if (dataStack.top() == minStack.top()) {
            minStack.pop();
        }
        dataStack.pop();
    }

    int GetMin() {
        return minStack.top();
    }
};

void TestGetMinStack() {
    GetMinStack g;
    g.Push(3); cout << g.GetMin() << endl;
    g.Push(4); cout << g.GetMin() << endl;
    g.Push(5); cout << g.GetMin() << endl;
    g.Push(1); cout << g.GetMin() << endl;
    g.Push(2); cout << g.GetMin() << endl;
    g.Push(1); cout << g.GetMin() << endl;

    cout << "Start Pop" << endl;
    cout << g.GetMin() << endl;
    g.Pop(); cout << g.GetMin() << endl;
    g.Pop(); cout << g.GetMin() << endl;
    g.Pop(); cout << g.GetMin() << endl;
    g.Pop(); cout << g.GetMin() << endl;
    g.Pop(); cout << g.GetMin() << endl;
    g.Pop(); cout << g.GetMin() << endl;
}