#include <bits/stdc++.h>

using namespace std;

int main() {
  int s, n;
  cin >> s >> n;

  {
    cout << "Topic 1\n";
    cout << (s & (n - 1)) << '\n';
  }

  {
    cout << "\nTopic 2\n";
    cout << (__builtin_popcount(s) <= 1 ? "Yes" : "No") << '\n';
  }

  {
    cout << "\nTopic 3\n";
    cout << (s ^ (1 << __builtin_ctz(s))) << '\n';
  }

  {
    cout << "\nTopic 4\n";
    cout << (s | (1 << __builtin_ctz(~s))) << '\n';
  }

  {
    cout << "\nTopic 5\n";
    cout << (s &
             ~((1 << __builtin_ctz(~(((1 << __builtin_ctz(s)) - 1) | s))) - 1))
         << '\n';
  }

  {
    cout << "\nTopic 6\n";
    cout << (s |
             ((1 << __builtin_ctz(~((1 << __builtin_ctz(~s)) - 1) & s)) - 1))
         << '\n';
  }

  { cout << "\nTopic 7 is to solve UVa 11173.\n"; }

  {
    cout << "\nTopic 8\n";
    n = 0;
    for (int i = (8*sizeof(s) - __builtin_clz(s))-1; i >= 0; --i)
      n = (n<<1)|((__builtin_popcount(s>>(i+1))&1)^((s>>i)&1));
    cout << n << '\n';
  }

  return 0;
}
