//
// Created by admin on 2022/1/6.
//
#include <string>
#include <cstdio>
#include <stack>

using namespace std;

const string left = "left";
const string mid = "mid";
const string right = "right";


/*
 * 递归解法
 */

int Process(int N, string from, string to) {
    if (N == 1) {
        if ((from == mid) || (to == mid)) {
            printf("Move 1 from %s to %s\n", from.c_str(), to.c_str());
            return 1;
        } else {
            printf("Move 1 from %s to %s\n", from.c_str(), mid.c_str());
            printf("Move 1 from %s to %s\n", mid.c_str(), to.c_str());
            return 2;
        }
    }

    if ((from == mid) || (to == mid)) {
        string another = ((from == left) || (to == left)) ? right : left;
        int step1 = Process(N - 1, from, another);
        printf("Move %d from %s to %s\n", N, from.c_str(), to.c_str());
        int step2 = 1;
        int step3 = Process(N - 1, another, to);
        return step1 + step2 + step3;
    } else {
        int step1 = Process(N - 1, from, to);
        printf("Move %d from %s to %s\n", N, from.c_str(), mid.c_str());
        int step2 = 1;
        int step3 = Process(N - 1, to, from);
        printf("Move %d from %s to %s\n", N, mid.c_str(), to.c_str());
        int step4 = 1;
        int step5 = Process(N - 1, from, to);
        return step1 + step2 + step3 + step4 + step5;
    }
}

int Hanoi(int N) {
    if (N < 1) {
        return 0;
    }
    return Process(N, left, right);
}


/*
 * 栈解法
 */

const string Left2Mid = "left2mid";
const string Mid2Left = "mid2left";
const string Mid2Right = "mid2right";
const string Right2Mid = "right2mid";
const string NoAction = "no_action";

string PreAction = NoAction;
stack<int> ls;
stack<int> ms;
stack<int> rs;

int stack2stack(string curAction, string preNoAction, stack<int> &fromS, stack<int> &toS, string from, string to) {
    if (preNoAction != PreAction && fromS.top() < toS.top()) {
        toS.push(fromS.top());
        fromS.pop();
        printf("Move from %s to  %s\n", from.c_str(), to.c_str());
        PreAction = curAction;
        return 1;
    }
    return 0;
}

int HanoiStack(int N) {

    ls.push(INT32_MAX);
    ms.push(INT32_MAX);
    rs.push(INT32_MAX);
    PreAction = NoAction;

    for (int i = N; i > 0; --i) {
        ls.push(i);
    }

    int step = 0;
    while (rs.size() != N + 1) {
        step += stack2stack(Left2Mid, Mid2Left, ls, ms, left, mid);
        step += stack2stack(Mid2Left, Left2Mid, ms, ls, mid, left);
        step += stack2stack(Right2Mid, Mid2Right, rs, ms, right, mid);
        step += stack2stack(Mid2Right, Right2Mid, ms, rs, mid, right);
    }
    return step;
}



void TestHanoi() {
    int step = HanoiStack(2);
    printf("It will move %d steps\n", step);
}
