#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

ll MOD = 1LL<<40;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e5+7;

string tb (ll num)
{
	string ret;
	for (ll i = 0; (1LL<<i) <= (1LL<<40); ++i)
		ret += '0' + !!(num&(1LL<<i));
	reverse (ret.begin (), ret.end ());
	return ret;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n = MAXN;
	vector <long double> base = {0x600DCAFE, 12345};
	vector <vector <long double>> mult = 
	{
		{((long double) ((1LL<<20) + 1LL)) / (1LL<<20), 0},
		{1, 1}
	};
	for (i = 0; i < MAXN; ++i)
	{
		vector <long double> nbase = {0, 0};
		for (ll k = 0; k < 2; ++k)
			for (j = 0; j < 2; ++j)
				nbase[j] += base[k]*mult[k][j];
		base = nbase;
	}
	vector <ll> dp (MAXN), imp (MAXN);
	dp[0] = 0x600DCAFE;
	imp[0] = dp[0]%2;
	for (i = 1; i < MAXN; ++i)
	{
		dp[i] = (dp[i - 1] + (dp[i - 1] >> 20) + 12345) % MOD,
		imp[i] = imp[i - 1] + dp[i]%2;
	}
	cout << (ll) base[0] << '\n';
	cout << dp.back () << '\n';
	/*ll lin = 40, col = 11;
	for (i = 0; i < lin; ++i)
	{
		for (j = 0; j < col; ++j)
			printf ("% 4d", i*col+j+1 - imp[i*col+j]);
		printf ("\n");
	}
	/*
	ll num = 0x600DCAFE, par = 1;
	for (i = 1; i < n; ++i)
		num = (num + (num >> 20) + 12345) % MOD,
		par += !(num&1);
	cout << par << '\n';
	*/

	return 0;
}

