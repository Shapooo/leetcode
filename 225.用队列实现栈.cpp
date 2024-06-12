#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    MyStack() { }

    void push(int x) { _in.push(x); }

    int pop()
    {
        int count = _in.size() - 1;
        while (count--) {
            _out.push(_in.front());
            _in.pop();
        }
        auto result = _in.front();
        _in.pop();
        _in = _out;
        while (!_out.empty())
            _out.pop();
        return result;
    }

    int top() { return _in.back(); }

    bool empty() { return _in.empty(); }
    queue<int> _in {};
    queue<int> _out {};
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
