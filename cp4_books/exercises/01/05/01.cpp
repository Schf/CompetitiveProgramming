#include <bits/stdc++.h>

using namespace std;

int main() {

  char str[1024];
  int pos = 0;

  while (fgets(str + pos, 128, stdin)) {
    if (memcmp(str + pos, ".......", 7) != 0)
      pos += strlen(str + pos), str[pos - 1] = ' ';
  }
  str[pos - 1] = '\0';

  puts(str);

  return 0;
}
