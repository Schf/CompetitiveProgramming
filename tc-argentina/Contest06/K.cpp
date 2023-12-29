#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef int ll;

const ll MOD = 1e+9+7;
//const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+4+7;
const ll bs = 1250;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m;
	vector <ll> lucky_vec = {
		4, 7,
		44, 47, 74, 77,
		444, 447, 474, 477, 744, 747, 774, 777,
		4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777,
		7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777
	};
	vector <bool> lucky_check (10001, false);
	trav (a, lucky_vec)
		lucky_check[a] = true;
	cin >> n >> m;
    vector <ll> bucs_upt (n/bs + 1, 0), inp ((n/bs + 1)*bs, 0);
    for (i = 0; i < n; ++i) cin >> inp[i];
    vector <vector <ll>> bucs_freq (bucs_upt.size (), vector <ll> (10001, 0));
    for (i = 0; i < bucs_freq.size (); ++i)
        for (j = i*bs; j < (i + 1)*bs; ++j)
            ++bucs_freq[i][inp[j]];
    string mode;
	for (ll qq = 0; cin >> mode; ++qq)
	{
		if (mode == "add")
		{
			ll l, r, d;
			cin >> l >> r >> d;
            --l, --r;
			if (bucs_upt[l/bs] > 0)
            {
				for (i = 0; i < bs; ++i)
                    --bucs_freq[l/bs][inp[(l/bs)*bs + i]],
					inp[(l/bs)*bs + i] += bucs_upt[l/bs],
                    ++bucs_freq[l/bs][inp[(l/bs)*bs + i]];
                bucs_upt[l/bs] = 0;
            }
            for (i = l; i < (l/bs + 1)*bs && i <= r; ++i)
                --bucs_freq[l/bs][inp[i]], inp[i] += d,
                ++bucs_freq[l/bs][inp[i]];
            if (l/bs != r/bs)
            {
                if (bucs_upt[r/bs] > 0)
                {
                    for (i = 0; i < bs; ++i)
                        --bucs_freq[r/bs][inp[(r/bs)*bs + i]],
                        inp[(r/bs)*bs + i] += bucs_upt[r/bs],
                        ++bucs_freq[r/bs][inp[(r/bs)*bs + i]];
                    bucs_upt[r/bs] = 0;
                }
                for (i = l/bs + 1; i < r/bs; ++i)
                    bucs_upt[i] += d;
                for (i = (r/bs)*bs; i <= r; ++i)
                    --bucs_freq[r/bs][inp[i]], inp[i] += d,
                    ++bucs_freq[r/bs][inp[i]];
            }
		}
		else
		{
			ll l, r;
			cin >> l >> r;
			--l, --r;
			if (bucs_upt[l/bs] > 0)
            {
				for (i = 0; i < bs; ++i)
                    --bucs_freq[l/bs][inp[(l/bs)*bs + i]],
					inp[(l/bs)*bs + i] += bucs_upt[l/bs],
                    ++bucs_freq[l/bs][inp[(l/bs)*bs + i]];
                bucs_upt[l/bs] = 0;
            }
            ll ans = 0;
            for (i = l; i < (l/bs + 1)*bs && i <= r; ++i)
                ans += lucky_check[inp[i]];
            if (l/bs != r/bs)
            {
                if (bucs_upt[r/bs] > 0)
                {
                    for (i = 0; i < bs; ++i)
                        --bucs_freq[r/bs][inp[(r/bs)*bs + i]],
                        inp[(r/bs)*bs + i] += bucs_upt[r/bs],
                        ++bucs_freq[r/bs][inp[(r/bs)*bs + i]];
                    bucs_upt[r/bs] = 0;
                }
                for (i = l/bs + 1; i < r/bs; ++i)
                    trav (a, lucky_vec)
                        ans += bucs_freq[i][max ((ll)0, a - bucs_upt[i])];
                for (i = (r/bs)*bs; i <= r; ++i)
                    ans += lucky_check[inp[i]];
            }
			cout << ans << '\n';
            /*if (r == 9)
            {
                cout << " |";
                for (i = 0; i < inp.size (); ++i)
                    cout << ' ' << inp[i] + bucs_upt[i/bs];
                cout << '\n';
            }
            else cout << ' ';*/
		}
	}

	return 0;
}
