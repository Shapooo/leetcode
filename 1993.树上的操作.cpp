#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1993 lang=cpp
 *
 * [1993] 树上的操作
 */

// @lc code=start
class LockingTree {
    int n;
    vector<int> parent, locked;
    vector<vector<int>> children;
    bool dfs(int id)
    {
        bool res = false;
        if (locked[id]) {
            locked[id] = 0;
            res = true;
        }
        for (auto& c : children[id]) {
            res |= dfs(c);
        }
        return res;
    }

public:
    LockingTree(vector<int>& parent)
        : parent(parent)
        , n(parent.size())
    {
        locked.resize(n);
        children.resize(n);
        for (int i = 1; i < n; ++i) {
            children[parent[i]].emplace_back(i);
        }
    }

    bool lock(int num, int user)
    {
        if (locked[num]) {
            return false;
        } else {
            locked[num] = user;
            return true;
        }
    }

    bool unlock(int num, int user)
    {
        if (locked[num] == user) {
            locked[num] = 0;
            return true;
        } else {
            return false;
        }
    }

    bool upgrade(int num, int user)
    {
        int n = num;
        while (n >= 0) {
            if (locked[n]) {
                return false;
            }
            n = parent[n];
        }

        if (dfs(num)) {
            locked[num] = user;
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
// @lc code=end

int main()
{
    vector<int> parent { -1, 0, 0, 1, 1, 2, 2 };
    LockingTree t(parent);
    t.lock(2, 2);
    t.unlock(2, 3);
    t.unlock(2, 2);
    t.lock(4, 5);
    t.upgrade(0, 1);
    t.lock(0, 1);
}