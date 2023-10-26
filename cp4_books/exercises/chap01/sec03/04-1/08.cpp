#include <bits/stdc++.h>

using namespace std;

int main() {
  int l = 20, s = 1 << l;
  for (int i = 0; i < s; ++i, cout << '\n')
    for (int j = 0; j < l; ++j)
      if (i & (1 << j))
        cout << j + 1 << ' ';
}
