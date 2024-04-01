#include <cstdio>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start
class LFUCache {
    int rem_capacity;
    unordered_map<int, int> kvs;
    unordered_map<int, int> kfs;
    map<int, list<int>> fks;

public:
    LFUCache(int capacity)
        : rem_capacity(capacity)
    {
    }

    int get(int key)
    {
        auto it = kvs.find(key);
        if (it == kvs.end()) {
            return -1;
        }
        int freq = kfs[key]++;
        for (auto it2 = fks[freq].begin(); it2 != fks[freq].end(); ++it2) {
            if (*it2 == key) {
                fks[freq].erase(it2);
                break;
            }
        }
        if (fks[freq].empty()) {
            fks.erase(freq);
        }
        fks[freq + 1].push_front(key);
        return it->second;
    }

    void put(int key, int value)
    {
        auto it = kvs.find(key);
        if (it == kvs.end()) {
            if (!rem_capacity) {
                auto it = fks.begin();
                int depr_key = it->second.back();
                kvs.erase(depr_key);
                kfs.erase(depr_key);
                // printf("%d poped\n", it->second.back());
                it->second.pop_back();
                if (it->second.empty()) {
                    fks.erase(it);
                }
            } else {
                rem_capacity--;
            }
            fks[1].push_front(key);
        } else {
            int freq = kfs[key];
            for (auto it = fks[freq].begin(); it != fks[freq].end(); ++it) {
                if (*it == key) {
                    fks[freq].erase(it);
                    break;
                }
            }
            if (fks[freq].empty()) {
                fks.erase(freq);
            }
            fks[freq + 1].push_front(key);
        }
        kvs[key] = value;
        kfs[key]++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main()
{
    // cache=[] 将显示最后一次使用的顺序（最左边的元素是最近的）
    LFUCache lfu(2);
    lfu.put(1, 1); // cache=[1,_], cnt(1)=1
    lfu.put(2, 2); // cache=[2,1], cnt(2)=1, cnt(1)=1
    lfu.get(1); // 返回 1
                // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3); // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
                   // cache=[3,1], cnt(3)=1, cnt(1)=2
    lfu.get(2); // 返回 -1（未找到）
    lfu.get(3); // 返回 3
                // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4, 4); // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
                   // cache=[4,3], cnt(4)=1, cnt(3)=2
    lfu.get(1); // 返回 -1（未找到）
    lfu.get(3); // 返回 3
                // cache=[3,4], cnt(4)=1, cnt(3)=3
    lfu.get(4); // 返回 4
                // cache=[3,4], cnt(4)=2, cnt(3)=3
}