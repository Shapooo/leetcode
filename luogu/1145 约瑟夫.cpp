#include <bitset>
#include <iostream>
using namespace std;

/**
 * P1145 约瑟夫
 */

int main() {
  int k;
  cin >> k;
  int m = k + 1;
  while (true) {
    int i = 0;
    int sum = 2 * k;
    int cur = 0;
    for (; i < k; ++i) {
      cur = (cur + m - 1) % (sum);
      sum--;
      if (cur < k) {
        break;
      }
    }
    if (i == k) {
      break;
    }
    m++;
  }

  cout << m;

  return 0;
}
