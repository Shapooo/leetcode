
class Solution
{
    int bitSum(int x)
    {
        int res{};
        while (x)
        {
            res += x % 10;
            x /= 10;
        }
        return res;
    }

public:
    int sumOfTheDigitsOfHarshadNumber(int x)
    {
        int res = bitSum(x);
        return x % res ? -1 : res;
    }
};