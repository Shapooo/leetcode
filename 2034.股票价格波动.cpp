#include <cstdio>
#include <set>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=2034 lang=cpp
 *
 * [2034] 股票价格波动
 */

// @lc code=start
class StockPrice {
    multiset<int> vals {};
    unordered_map<int, int> tv {};
    int cur_time = 0;

public:
    StockPrice()
    {
    }

    void update(int timestamp, int price)
    {
        cur_time = max(timestamp, cur_time);
        auto it = tv.find(timestamp);
        if (it == tv.end()) {
            vals.insert(price);
        } else {
            auto vit = vals.find(it->second);
            vals.erase(vit);
            vals.insert(price);
        }
        tv[timestamp] = price;
        for (auto& v : vals) {
            printf("%d ", v);
        }
        printf("\n");
    }

    int current()
    {
        return tv[cur_time];
    }

    int maximum()
    {
        return *vals.rbegin();
    }

    int minimum()
    {
        return *vals.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// @lc code=end
