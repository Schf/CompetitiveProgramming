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
	ll i, j, n, a, b, w, x, c;
	cin >> a >> b >> w >> x >> c;
	if (c <= a)
	{
		cout << "0\n";
		return 0;
	}
	/*ll aa = a, ab = b, ac = c;
	for (i = 0; i < MAXN && c > a; ++i)
	{
		--c;
		if (b >= x) b -= x;
		else a -= 1, b = w - (x - b);
		//printf ("i:%3d, a:%3d, b:%3d, c:%3d\n", i, a, b, c);
	}
	a = aa, b = ab, c = ac;
	ll brute_ans = i;*/
	ll bi = b;
	j = 0;
	if (b >= x) b -= x;
	else ++j, b = w - (x - b);
	for (i = 1; b != bi; ++i)
		if (b >= x) b -= x;
		else ++j, b = w - (x - b);
	//cout << i << ' ' << j << '\n';
	ll ans = 0;
	//for (; c - i + j > a; c += - i + j, ans += i);
	ll fac = (c - i + j - a + abs (- i + j) - 1) / abs (- i + j);
	c -= fac*abs (- i + j);
	ans += fac*i;
	for (; c > a; ++ans)
	{
		--c;
		if (b >= x) b -= x;
		else a -= 1, b = w - (x - b);
	}
	cout << ans << '\n';

	return 0;
}

