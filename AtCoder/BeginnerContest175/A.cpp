#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	string s;
	cin >> s;
	ll ans = 0;
	if (s[1] == 'S')
	{
		if (s[0] == 'R' || s[2] == 'R') cout << 1;
		else cout << 0;
	}
	else
	{
		if (s[0] == 'R')
			if (s[2] == 'R') cout << 3;
			else cout << 2;
		else if (s[2] == 'R') cout << 2;
			else cout << 1;
	}
	cout << '\n';


	return 0;
}

