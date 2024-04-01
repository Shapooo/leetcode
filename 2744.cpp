#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words)
    {
        unordered_set<string> s;
        int res = 0;
        for (auto& word : words) {
            string rev = string(word.rbegin(), word.rend());
            if (s.find(rev) != s.end()) {
                res++;
                s.erase(rev);
            } else {
                s.insert(word);
            }
        }
        return res;
    }
};