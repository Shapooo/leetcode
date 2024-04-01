#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2349 lang=cpp
 *
 * [2349] 设计数字容器系统
 */

// @lc code=start
class NumberContainers {
    unordered_map<int, int> v {};
    unordered_map<int, set<int>> pos {};

public:
    NumberContainers()
    {
    }

    void change(int index, int number)
    {
        auto it = v.find(index);
        if (it != v.end()) {
            auto& a = pos[it->second];
            auto b = a.find(index);
            a.erase(b);
        }
        v[index] = number;
        unordered_map<int, set<int>>::iterator tmp;
        if ((tmp = pos.find(number)) == pos.end()) {
            set<int> a { index };
            pos.insert(make_pair(number, a));
        } else {
            tmp->second.emplace(index);
        }
    }

    int find(int number)
    {
        auto tmp = pos.find(number);
        if (tmp == pos.end() || !tmp->second.size()) {
            return -1;
        }
        return *tmp->second.begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
// @lc code=end
