#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int bx, by;
  int mx, my;
  unsigned long long memo[21][21];
  memset(memo, 0, sizeof(memo));

  cin >> bx >> by >> mx >> my;
  int ma[9][2] = {{0, 0},  {1, 2},  {2, 1},   {-1, 2}, {2, -1},
                  {-2, 1}, {1, -2}, {-1, -2}, {-2, -1}};
  memo[0][0] = 1;
  for (int i = 0; i < 9; ++i) {
    memo[mx + ma[i][0]][my + ma[i][1]] = -1;
  }

  for (int y = 1; y <= by; ++y) {
    if (memo[0][y] == -1) {
      memo[0][y] = 0;
    } else {
      memo[0][y] = memo[0][y - 1];
    }
  }

  for (int x = 1; x <= bx; ++x) {
    memo[x][0] = memo[x - 1][0];
    for (int y = 1; y <= by; ++y) {
      if (memo[x][y] != -1) {
        memo[x][y] = memo[x - 1][y] + memo[x][y - 1];
      } else {
        memo[x][y] = 0;
      }
    }
  }
  cout << memo[bx][by];

  return 0;
}
