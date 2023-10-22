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
	ll i, j, n, k;
	cin >> n >> k;
	map <ll, ll> inp;
	for (i = 0; i < n; ++i) cin >> j, ++inp[j];
	vector <vector <ll>> freq;
	freq.reserve (inp.size ());
	trav (p, inp)
		freq.push_back (vector <ll> (6, 0)),
		freq[freq.size () - 1][0] = p.f,
		freq[freq.size () - 1][1] = 
		freq[freq.size () - 1][3] = 
		freq[freq.size () - 1][5] = p.s;
	ll u, b;
	for (i = 1; i < freq.size (); ++i)
	{
		freq[i][2] = freq[i - 1][3]*(freq[i][0] - freq[i - 1][0]) + freq[i - 1][2],
		freq[i][3] = freq[i][1] + freq[i - 1][3];
		if (freq[i][3] >= k) b = i;
	}
	for (i = freq.size () - 2; i >= 0; --i)
	{
		freq[i][4] = freq[i + 1][5]*(freq[i + 1][0] - freq[i][0]) + freq[i + 1][4],
		freq[i][5] = freq[i][1] + freq[i + 1][5];
		if (freq[i][5] >= k) u = i;
	}
	if (abs (u - b) > 2)
	{
		ll uv = max (0LL, freq[u][4] - (freq[u][5] - k));
		ll bv = max (0LL, freq[b][2] - (freq[b][3] - k));
		cout << min (uv, bv) << '\n';
	}
	else
	{
		
	}

	return 0;
}


