#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int mat[n][4];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 4; ++j) {
      cin >> mat[i][j];
    }
  }
  int x, y;
  int result = -1;
  cin >> x >> y;
  for (int i = 0; i < n; ++i) {
    int left = mat[i][0];
    int right = mat[i][0] + mat[i][2];
    int down = mat[i][1];
    int up = mat[i][1] + mat[i][3];
    if (left > x || right < x || up < y || down > y) {
      continue;
    }
    result = i + 1;
  }
  cout << result;

  return 0;
}
