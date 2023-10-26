#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &e : v)
    cin >> e;

  random_device rd;
  mt19937 g(rd());

  // Exercise 2.2.1.3 has 7 subtopics. My answers are presented below.

  shuffle(v.begin(), v.end(), g);
  {
    cout << "Topic 1\n";
    for (auto &e : v)
      cout << e << ' ';
    cout << "\n\n";
    map<int, int> count;
    for (auto &e : v)
      if (count.count(e) != 0)
        count[e]++;
      else
        count[e] = 1;
    pair<int, int> gg(-1, -1);
    for (auto &p : count)
      if (p.second > gg.second)
        gg = p;
    if (gg.second >= 2)
      cout << "Yes, at least <" << gg.first << ", " << gg.second << ">\n";
    else
      cout << "No\n";
  }

  shuffle(v.begin(), v.end(), g);
  {
    cout << "\n\nTopic 2\n";
    for (auto &e : v)
      cout << e << ' ';
    cout << "\n";
    int t;
    cin >> t;
    cout << t << "\n\n";
    map<int, int> has;
    for (int i = 0; i < v.size(); ++i)
      if (has.count(v[i])) {
        cout << "Found " << v[has[v[i]]] << " + " << v[i] << " = " << t << '\n';
        break;
      } else
        has[t - v[i]] = i;
  }

  shuffle(v.begin(), v.end(), g);
  {
    // Algorithm used on Topic 2 already performs at O(N).
  }

  shuffle(v.begin(), v.end(), g);
  {
    cout << "\n\nTopic 4\n";
    for (auto &e : v)
      cout << e << ' ';
    cout << "\n\n";
    int a, b, has = 0;
    cin >> a >> b;
    sort(v.begin(), v.end());
    auto l = lower_bound(v.begin(), v.end(), a);
    auto r = upper_bound(v.begin(), v.end(), b);
    for (; l != r; ++l)
      has = 1, cout << setw(4) << *l;
    if (has)
      cout << '\n';
  }

  shuffle(v.begin(), v.end(), g);
  {
    cout << "\n\nTopic 5\n";
    for (auto &e : v)
      cout << e << ' ';
    cout << "\n\n";
    int ans = 1;
    for (int i = 1, j = 1; i < v.size(); ++i)
      j = v[i - 1] < v[i] ? j + 1 : 1, ans = max(ans, j);
    cout << ans << '\n';
  }

  shuffle(v.begin(), v.end(), g);
  {
    cout << "\n\nTopic 6\n";
    for (auto &e : v)
      cout << e << ' ';
    cout << "\n\n";
    sort(v.begin(), v.end());
    cout << v[v.size() / 2] << '\n';
  }

  shuffle(v.begin(), v.end(), g);
  {
    cout << "\n\nTopic 7\n";
    for (auto &e : v)
      cout << e << ' ';
    cout << "\n\n";
    map<int, int> h;
    for (auto &e : v)
      h[e]++;
    pair<int, int> gg(-1, -1);
    for (auto &p : h)
      if (p.second > gg.second)
        gg = p;
    cout << gg.first << " appears " << gg.second << " times.\n";
  }

  return 0;
}
