#include <bits/stdc++.h>

using namespace std;

int main() {

  string str;
  int count = 0;

  while (getline(cin, str), str.substr(0, 7) != ".......")
    ;

  while(getchar() != EOF)
    count++;

  cout << count << '\n';

  return 0;
}
