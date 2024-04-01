#include <bitset>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B)
    {
        bitset<64> a {}, b {};
        auto len = A.size();
        int count = 0;
        vector<int> res(len);
        for (size_t i = 0; i < len; i++) {
            int ia = A[i], ib = B[i];
            a[ia] = 1;
            b[ib] = 1;
            if (ia == ib) {
                count++;
            } else {
                if (a[ib]) {
                    count++;
                }
                if (b[ia]) {
                    count++;
                }
            }
            res[i] = count;
        }
        return res;
    }
};