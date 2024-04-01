#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat)
    {
        int map[100'001][2] {};
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                map[mat[i][j]][0] = i;
                map[mat[i][j]][1] = j;
            }
        }
        int x_axis[100'000] {}, y_axis[100'000] {};
        for (int i = 0; i < arr.size(); ++i) {
            int v = arr[i];
            ++x_axis[map[v][0]];
            ++y_axis[map[v][1]];
            if (x_axis[map[v][0]] == m || y_axis[map[v][1]] == n) {
                return i;
            }
        }
        return 0;
    }
};

int main()
{
    vector<int> arr { 1, 2, 3, 4, 5 };
    vector<vector<int>> mat { { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 } };
    arr = { 1, 3, 4, 2 }, mat = { { 1, 4 }, { 2, 3 } };
    arr = { 2, 8, 7, 4, 1, 3, 5, 6, 9 },
    mat = { { 3, 2, 5 }, { 1, 4, 6 }, { 8, 7, 9 } };
    arr = { 1, 4, 5, 2, 6, 3 },
    mat = { { 4, 3, 5 }, { 1, 2, 6 } };
    printf("%d\n", Solution().firstCompleteIndex(arr, mat));
    return 0;
}