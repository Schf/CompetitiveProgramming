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
	ll tc;
	cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		cin >> n;
		vector <ll> inp (n), vld (n);
		vector <ll> maxb (n), maxf (n);
		trav (a, inp) cin >> a;
		maxb[0] = inp[0];
		for (i = 1; i < n; ++i)
			maxb[i] = max (inp[i], maxb[i - 1]);
		maxf[n - 1] = inp[n - 1];
		for (i = n - 2; i >= 0; --i)
			maxf[i] = max (inp[i], maxf[i + 1]);
		set <ll> A, B;
		for (i = 0; i < n; ++i)
			if (A.find (inp[i]) != A.end ()) break;
			else
			{
				A.insert (inp[i]);
				if (*(A.rbegin ()) == A.size ()) vld[i] = 1;
			}
		for (i = n - 1; i >= 0; --i)
			if (B.find (inp[i]) != B.end ()) break;
			else
			{
				B.insert (inp[i]);
				if (*(B.rbegin ()) == B.size ()) vld[i] += 2;
			}
		vector <ll> out;
		for (i = 0; i < n - 1; ++i)
			if (vld[i]%2 == 1 && vld[i + 1] > 1) out.push_back (i);
		cout << out.size () << '\n';
		trav (a, out) cout << maxb[a] << ' ' << maxf[a + 1] << '\n';
	}

	return 0;
}

