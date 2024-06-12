#include <cstring>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int numTable[9][9];
  while (true) {
    int x, y, v;
    cin >> x >> y >> v;
    if (x == 0) {
      break;
    }
    numTable[x][y] = v;
  }
  int memo[9][9];
  for (int t = 0; t < 2; ++t) {
    memset(memo, 0, sizeof(memo));
    memo[0][0] = numTable[0][0];
    for (int i = 0; i < n; ++i) {
      memo[0][i] = memo[0][i - 1] + numTable[0][i];
    }
    // for ()
  }

  return 0;
}
