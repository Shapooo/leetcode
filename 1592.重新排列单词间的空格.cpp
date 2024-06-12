#include <algorithm>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=1592 lang=cpp
 *
 * [1592] 重新排列单词间的空格
 */

// @lc code=start
class Solution {
public:
    string reorderSpaces(string text)
    {
        int words {}, spaces {};
        int size = text.size();
        bool inWord = false;
        for (auto& c : text) {
            if (c != ' ' && !inWord) {
                inWord = true;
                words++;
            } else if (c == ' ') {
                inWord = false;
                spaces++;
            }
        }
        string result {};
        if (words == 1) {
            remove(text.begin(), text.end(), ' ');
            for (int i = 0; i < spaces; ++i) {
                text[size - 1 - i] = ' ';
            }
            return text;
        }
        int periodSpaces = spaces / (words - 1);
        int index = 0;
        while (text[index] == ' ') {
            index++;
        }
        for (int i = 0; i < words; ++i) {
            while (index < size && text[index] != ' ') {
                result.push_back(text[index]);
                index++;
            }
            if (i != words - 1) {
                result.append(string(periodSpaces, ' '));
                spaces -= periodSpaces;
            }
            while (index < size && text[index] == ' ') {
                index++;
            }
        }
        if (spaces) {
            result.append(string(spaces, ' '));
        }

        return result;
    }
};
// @lc code=end
