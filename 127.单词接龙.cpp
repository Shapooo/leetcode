#include <bitset>
#include <queue>
#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
    int _size {};
    bool adjcent(string& a, string& b)
    {
        int count { 0 };
        for (int i = 0; i < _size; ++i) {
            if (a[i] != b[i]) {
                count++;
                if (count > 1) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        _size = beginWord.size();
        if (adjcent(beginWord, endWord)) {
            return 2;
        }
        int size = wordList.size();
        queue<int> que {};
        bitset<5000> visited {};
        for (int i = 0; i < size; ++i) {
            if (adjcent(wordList[i], beginWord)) {
                if (adjcent(wordList[i], endWord)) {
                    return 3;
                }
                que.push(i);
                visited[i] = 1;
            }
        }
        que.push(-1);

        int result { 1 };

        while (!que.empty()) {
            int cur = que.front();
            if (cur != -1) {
                if (adjcent(wordList[cur], endWord)) {
                    return result;
                }
                for (int i = 0; i < size; ++i) {
                    if (visited[i] == 0 && adjcent(wordList[i], wordList[cur])) {
                        visited[i] = 1;
                        que.push(i);
                    }
                }
            } else {
                que.push(-1);
                result++;
            }
            que.pop();
        }
        return 0;
    }
};
// @lc code=end
