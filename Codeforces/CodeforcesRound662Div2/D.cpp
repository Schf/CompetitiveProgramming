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

ll rhombus_size (vector <string> & inp, int x, int y)
{
	ll cx = x, cy = y, out = 1, i, j, n = inp.size (), m = inp[0].size ();
	for (bool ok = true; ok; ++out)
	{
		bool uplft = true;
		for (i = 0; i < out; ++i)
			if (cx - out < 0 || cy - out < 0) uplft = false;
			else if (inp[cx - i][cy - out + i] != inp[cx][cy]) uplft = false;
		bool uprgt = true;
		for (i = 0; i < out; ++i)
			if (cx - out < 0 || cy + out >= m) uprgt = false;
			else if (inp[cx - out + i][cy + i] != inp[cx][cy]) uprgt = false;
		bool dnrgt = true;
		for (i = 0; i < out; ++i)
			if (cx + out >= n || cy + out >= m) dnrgt = false;
			else if (inp[cx + i][cy + out - i] != inp[cx][cy]) dnrgt = false;
		bool dnlft = true;
		for (i = 0; i < out; ++i)
			if (cx + out >= n || cy - out < 0) dnlft = false;
			else if (inp[cx + out - i][cy - i] != inp[cx][cy]) dnlft = false;
		if ((!uplft && !dnrgt) || (!uprgt && !dnlft)) ok = false;
		cout << uplft << uprgt << dnrgt << dnlft << ok << ' ';
		cx += (dnrgt && dnlft) - (uprgt && uplft);
		cy += (dnrgt && uprgt) - (dnlft && uplft);
	}
	--out;
	for (ll k = 0; k < out; ++k)
	{
		for (i = 0; i < k; ++i)
			inp[cx - i][cy - k + i] = '0',
			inp[cx - k + i][cy + i] = '0',
			inp[cx + i][cy + k - i] = '0',
			inp[cx + k - i][cy - i] = '0';
	}
	return out;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m, ans = 0;
	cin >> n >> m;
	vector <string> inp (n);
	trav (s, inp) cin >> s;
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			if (inp[i][j] != '0')
				for (ll k = rhombus_size (inp, i, j); k > 0; --k)
					ans += k*k + (k - 1)*(k - 1);
	cout << ans << '\n';

	return 0;
}
/* Square of size n has:
(n-0)*(n-0) + (n-1)*(n-1) +
(n-1)*(n-1) + (n-2)*(n-2) +
(n-2)*(n-2) + (n-3)*(n-3)
subsquares. */