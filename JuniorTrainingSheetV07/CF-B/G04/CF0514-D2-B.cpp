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
	ll i, j, n, x0, y0;
	cin >> n >> x0 >> y0;
	vector <pair <ll, ll>> inp (n);
	vector <ll> tag (n, -1);
	tag[0] = 0;
	for (i = 0; i < n; ++i)
	{
		cin >> inp[i].f >> inp[i].s;
		inp[i].f -= x0, inp[i].s -= y0;
		for (j = 0; j < i; ++j)
			if (inp[i].f*inp[j].s == inp[i].s*inp[j].f)
			{
				tag[i] = tag[j] - 1;
				break;
			}
			else tag[i] = max (tag[i], tag[j]);
		++tag[i];
	}
	cout << *max_element (tag.begin (), tag.end ()) << '\n';

	return 0;
}

