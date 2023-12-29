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
	ll tc = 1;
	cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		cin >> n;
		vector <ll> inp (n), freq (2*n + 1);
		trav (a, inp) cin >> a, ++freq[a];
		sort (inp.begin (), inp.end ());
		vector <ll> nums (2*n + 1);
		for (ll num = 0; num <= 2*n; ++num)
		{
			auto cfreq = freq;
			ll cur = 0;
			for (i = 0; i < n; ++i)
				if (inp[i] <= num)
					if ((num - inp[i] == inp[i] && cfreq[inp[i]] > 1) ||
							(num - inp[i] != inp[i] && cfreq[inp[i]] > 0 && cfreq[num - inp[i]] > 0))
					++cur, --cfreq[inp[i]], --cfreq[num - inp[i]];
			nums[num] = cur;
		}
		cout << *max_element (nums.begin (), nums.end ()) << '\n';
	}

	return 0;
}

