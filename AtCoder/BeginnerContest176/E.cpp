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
	ll i, j, n, h, w, m;
	cin >> h >> w >> m;
	vector <ll> H (h), W (w);
	set <pair <ll, ll>> bomb;
	for (i = 0; i < m; ++i)
	{
		ll hi, wi;
		cin >> hi >> wi;
		--hi, --wi;
		++H[hi], ++W[wi];
		bomb.insert ({hi, wi});
	}
	pair <ll, ll> ans = {0, 0};
	for (i = 0; i < h; ++i)
		if (H[ans.f] < H[i]) ans.f = i;
	for (i = 0; i < w; ++i)
		if (W[ans.s] < W[i]) ans.s = i;
	if (bomb.find (ans) == bomb.end ())
	{
		cout << H[ans.f] + W[ans.s] << '\n';
		return 0;
	}
	vector <ll> Word (w), Hord (h);
	iota (Word.begin (), Word.end (), 0);
	iota (Hord.begin (), Hord.end (), 0);
	sort (Word.begin (), Word.end (), [&] (auto a, auto b)
		{ return W[a] < W[b]; });
	sort (Hord.begin (), Hord.end (), [&] (auto a, auto b)
		{ return H[a] < H[b]; });
	for (i = h - 1; i >= 0; --i)
	{
		if (i < h - 1 && H[Hord[i + 1]] > H[Hord[i]]) break;
		for (j = w - 1; j >= 0; --j)
		{
			if (j < w - 1 && W[Word[j + 1]] > W[Word[j]]) break;
			if (bomb.find ({Hord[i], Word[j]}) == bomb.end ())
			{
				cout << H[Hord[i]] + W[Word[j]] << '\n';
				return 0;
			}
		}
	}
	cout << H[ans.f] + W[ans.s] - 1 << '\n';

	return 0;
}

