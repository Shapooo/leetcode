#include <cstdio>
#include <string>
using namespace std;
class Solution {
public:
    int addMinimum(string word)
    {
        int n = word.size();
        int res = 0, last = 'a' - 1;
        for (int i = 0; i < n; i++) {
            res += (word[i] - last + 2) % 3;
            last = word[i];
        }
        res += 'c' - last;
        return res;
    }
};

int main()
{
    Solution sol;
    string word = "aaa";
    int res = sol.addMinimum(word);
    printf("%d\n", res);
    return 0;
}