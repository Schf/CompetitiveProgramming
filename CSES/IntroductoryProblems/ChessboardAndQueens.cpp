#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

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

vector <vector <bitset <8>>> confs;
vector <bitset <8>> cur (8), inp (8);
vector <pair <int, int>> curq; 

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc = 1; //cin >> tc;
	while (tc--)
	{
		ll i = 0, j, n;
		char c;
		for (i = 0; i < 8; ++i)
		{
			for (j = 0; j < 8; ++j)
			{
				c = 0;
				while (c != '.' && c != '*') cin >> c;
				inp[i][j] = (c == '.');
			}
		}
		vector <int> ord = {0, 1, 2, 3, 4, 5, 6, 7};
		do
		{
			curq.clear ();
			trav (v, cur) v.reset ();
			bool can = true;
			curq.push_back ({0, ord[0]});
			for (i = 1; i < 8 && can; ++i)
			{
				trav (q, curq)
					if (q.f - q.s == i - ord[i] || q.f + q.s == i + ord[i])
						can = false;
				curq.push_back ({i, ord[i]});
			}
			if (can)
			{
				for (i = 0; i < 8; ++i)
					cur[i][ord[i]] = 1;
				confs.emplace_back (cur);
			}
		} while (next_permutation (ord.begin (), ord.end ()));
		ll sub = 0;
		trav (conf, confs)
		{
			for (i = 0; i < 8; ++i)
				for (j = 0; j < 8; ++j)
					if (conf[i][j] && !inp[i][j])
					{
						++sub;
						goto out;
					}
			out:;
		}
		cout << confs.size () - sub << '\n';
	}

	return 0;
}

