#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1169 lang=cpp
 *
 * [1169] 查询无效交易
 */

// @lc code=start
class Solution {
    struct Transaction {
        string name;
        int time;
        int amount;
        string city;
    };

    Transaction parse(string s)
    {
        int len = s.size();
        string name {};
        int idx = 0;
        while (s[idx] != ',') {
            name.push_back(s[idx]);
            idx++;
        }
        idx++;
        int time = 0;
        while (s[idx] != ',') {
            time *= 10;
            time += s[idx] - '0';
            idx++;
        }
        idx++;
        int amount = 0;
        while (s[idx] != ',') {
            amount *= 10;
            amount += s[idx] - '0';
            idx++;
        }
        idx++;
        string city {};
        while (idx < len) {
            city.push_back(s[idx]);
            idx++;
        }
        return { name, time, amount, city };
    }

    string serde(Transaction& t)
    {
        string res { t.name };
        res.push_back(',');
        res.append(to_string(t.time));
        res.push_back(',');
        res.append(to_string(t.amount));
        res.push_back(',');
        res.append(t.city);
        return res;
    }

public:
    vector<string> invalidTransactions(vector<string>& transactions)
    {
        unordered_map<string, vector<Transaction>> a {};
        for (auto& s : transactions) {
            auto b = parse(s);
            a[b.name].push_back(b);
        }
        vector<string> res {};
        for (auto& p : a) {
            auto& v = p.second;
            sort(v.begin(), v.end(), [](auto& lhs, auto& rhs) {
                return lhs.time < rhs.time;
            });
            int len = v.size();
            for (int i = 0; i < len; ++i) {
                if (v[i].amount > 1000) {
                    res.emplace_back(serde(v[i]));
                    continue;
                }
                int j = i - 1;
                bool flag = false;
                while (j >= 0 && v[j].time >= v[i].time - 60) {
                    if (v[j].city != v[i].city) {
                        res.emplace_back(serde(v[i]));
                        flag = true;
                        break;
                    }
                    j--;
                }
                if (!flag) {
                    j = i + 1;
                    while (j < len && v[j].time <= v[i].time + 60) {
                        if (v[j].city != v[i].city) {
                            res.emplace_back(serde(v[i]));
                            break;
                        }
                        j++;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<string> transactions { "alice,20,800,mtv", "alice,50,100,beijing" };
    for (auto& s : sol.invalidTransactions(transactions)) {
        cout << s << endl;
    }
    cout << endl;
    transactions = { "alice,20,800,mtv", "bob,50,1200,mtv", "alice,20,800,mtv", "alice,50,1200,mtv", "alice,20,800,mtv", "alice,50,100,beijing" };
    for (auto& s : sol.invalidTransactions(transactions)) {
        cout << s << endl;
    }
    cout << endl;
}