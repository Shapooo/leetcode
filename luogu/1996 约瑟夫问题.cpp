#include <bitset>
#include <iostream>
using namespace std;

/**
 * P1145 约瑟夫
 */

int main() {
  int n, m;
  cin >> n >> m;
  bitset<100> circle{};

  int cur = -1;
  for (int i = 0; i < n; ++i) {
    int j = m;
    while (j) {
      cur = (cur + 1) % n;
      if (!circle[cur]) {
        j--;
      }
    }

    circle[cur] = 1;
    cout << cur + 1;
    if (i != n - 1) {
      cout << " ";
    }
  }

  return 0;
}
