#include <bits/stdc++.h>

using namespace std;

int main() {

  char str[1024];
  int vowels = 0, i = 0;

  fgets(str, 1023, stdin);
  for (i = 0; i < 1024 && str[i]; ++i) {
    if ('A' <= str[i] && str[i] <= 'Z')
      str[i] += 'a' - 'A';
    switch(str[i]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        vowels++;
        break;
    }
  }
  printf("%d %d %s\n", vowels, i - vowels - 1, str);

  return 0;
}
