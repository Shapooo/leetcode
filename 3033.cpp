#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> maxOfCol(n);
        for (int i = 0; i < n; i++)
        {
            int maxm = -1;
            for (int j = 0; j < m; ++j)
            {
                maxm = max(matrix[j][i], maxm);
            }
            maxOfCol[i] = maxm;
        }
        vector<vector<int>> res(matrix);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (res[i][j] == -1)
                {
                    res[i][j] = maxOfCol[j];
                }
            }
        }
        return res;
    }
};
