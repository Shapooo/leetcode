#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    MyQueue() { }

    void push(int x) { _in.push(x); }

    int pop()
    {
        if (_out.empty()) {
            while (!_in.empty()) {
                auto tmp = _in.top();
                _out.push(tmp);
                _in.pop();
            }
        }
        auto result = _out.top();
        _out.pop();
        return result;
    }

    int peek()
    {
        if (_out.empty()) {
            while (!_in.empty()) {
                auto tmp = _in.top();
                _out.push(tmp);
                _in.pop();
            }
        }
        return _out.top();
    }

    bool empty() { return _in.empty() && _out.empty(); }
    stack<int> _in {};
    stack<int> _out {};
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
