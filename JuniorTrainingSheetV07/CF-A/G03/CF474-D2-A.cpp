#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	string s ("qwertyuiopasdfghjkl;zxcvbnm,./"), inp;
	vector <ll> pos (200);
	for (i = 0; i < s.size (); ++i)
		pos[s[i]] = i;
	char c;
	cin >> c >> inp;
	for (i = 0; i < inp.size (); ++i)
		if (c == 'R') cout << s[pos[inp[i]] - 1];
		else cout << s[pos[inp[i]] + 1];
	cout << '\n';

	return 0;
}

