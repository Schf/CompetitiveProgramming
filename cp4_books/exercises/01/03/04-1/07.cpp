#include <bits/stdc++.h>

using namespace std;

int main() {
  string s = "ABCDEFGHIJ";
  do {
    cout << s << '\n';
  } while (next_permutation(s.begin(), s.end()));
}
