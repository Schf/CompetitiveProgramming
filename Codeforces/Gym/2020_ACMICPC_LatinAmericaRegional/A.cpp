#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;
#define f first
#define s second
#define mp(x, y) make_pair (x, y)

typedef long long ll;

const ll   MOD   =  1e+9+7;
const ll   INF   =  0x3f3f3f3f3f3f3f3f;
const int  INFi  =  0x3f3f3f3f;
const ll   MAXN  =  1e+5+7; // UPDATE

int main ()
{
	cin.sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, a, b;

	cin >> a >> b;
	if (a != 1)
	{
		cout << "*\n";
		return 0;
	}

	vector <vector <ll>> sets = {
		{0}, {1}, 
		{1, 2, }, 
		{1, 2, 3, }, 
		{1, 2, 4, }, 
		{1, 2, 3, 5, }, 
		{1, 2, 3, 6, }, 
		{1, 2, 3, 4, 7, }, 
		{1, 2, 4, 8, }, 
		{1, 2, 3, 6, 9, }, 
		{1, 2, 3, 5, 10, }, 
		{1, 2, 3, 4, 7, 11, }, 
		{1, 2, 3, 6, 12, }, 
		{1, 2, 3, 5, 10, 13, }, 
		{1, 2, 3, 4, 7, 14, }, 
		{1, 2, 3, 5, 10, 15, }, 
		{1, 2, 4, 8, 16, }, 
		{1, 2, 4, 8, 9, 17, }, 
		{1, 2, 3, 6, 9, 18, }, 
		{1, 2, 3, 4, 8, 11, 19, }, 
		{1, 2, 3, 5, 10, 20, }, 
		{1, 2, 3, 4, 7, 14, 21, }, 
		{1, 2, 3, 4, 7, 11, 22, }, 
		{1, 2, 3, 5, 10, 13, 23, }, 
		{1, 2, 3, 6, 12, 24, }, 
		{1, 2, 3, 5, 10, 15, 25, }, 
		{1, 2, 3, 5, 10, 13, 26, }, 
		{1, 2, 3, 6, 9, 18, 27, }, 
		{1, 2, 3, 4, 7, 14, 28, }, 
		{1, 2, 3, 4, 7, 11, 22, 29, }, 
		{1, 2, 3, 5, 10, 15, 30, }, 
		{1, 2, 3, 4, 7, 14, 28, 31, }, 
		{1, 2, 4, 8, 16, 32, }, 
		{1, 2, 4, 8, 16, 17, 33, }, 
		{1, 2, 4, 8, 9, 17, 34, }, 
		{1, 2, 3, 4, 7, 14, 21, 35, }, 
		{1, 2, 3, 6, 9, 18, 36, }, 
		{1, 2, 3, 6, 9, 18, 19, 37, }, 
		{1, 2, 3, 4, 8, 11, 19, 38, }, 
		{1, 2, 3, 5, 10, 13, 26, 39, }, 
		{1, 2, 3, 5, 10, 20, 40, }, 
		{1, 2, 3, 5, 10, 20, 21, 41, }, 
		{1, 2, 3, 4, 7, 14, 21, 42, }, 
		{1, 2, 3, 5, 10, 20, 23, 43, }, 
		{1, 2, 3, 4, 7, 11, 22, 44, }, 
		{1, 2, 3, 5, 10, 15, 30, 45, }, 
		{1, 2, 3, 5, 10, 13, 23, 46, }, 
		{1, 2, 3, 4, 7, 11, 22, 44, 47, }, 
		{1, 2, 3, 6, 12, 24, 48, }, 
		{1, 2, 3, 6, 12, 24, 25, 49, }, 
		{1, 2, 3, 5, 10, 15, 25, 50, }, 
		{1, 2, 3, 6, 12, 24, 27, 51, }, 
		{1, 2, 3, 5, 10, 13, 26, 52, }, 
		{1, 2, 3, 5, 6, 12, 24, 29, 53, }, 
		{1, 2, 3, 6, 9, 18, 27, 54, }, 
		{1, 2, 3, 4, 7, 11, 22, 44, 55, }, 
		{1, 2, 3, 4, 7, 14, 28, 56, }, 
		{1, 2, 3, 4, 7, 14, 28, 29, 57, }, 
		{1, 2, 3, 4, 7, 11, 22, 29, 58, }, 
		{1, 2, 3, 4, 7, 14, 28, 31, 59, }, 
		{1, 2, 3, 5, 10, 15, 30, 60, }, 
		{1, 2, 3, 5, 7, 14, 28, 56, 61, }, 
		{1, 2, 3, 4, 7, 14, 28, 31, 62, }, 
		{1, 2, 3, 4, 7, 14, 21, 42, 63, }, 
		{1, 2, 4, 8, 16, 32, 64, }, 
		{1, 2, 4, 8, 16, 32, 33, 65, }, 
		{1, 2, 4, 8, 16, 17, 33, 66, }, 
		{1, 2, 3, 4, 8, 16, 32, 35, 67, }, 
		{1, 2, 4, 8, 9, 17, 34, 68, }, 
		{1, 2, 3, 5, 10, 13, 23, 46, 69, }, 
		{1, 2, 3, 4, 7, 14, 21, 35, 70, }, 
		{1, 2, 3, 4, 7, 8, 16, 32, 64, 71, }, 
		{1, 2, 3, 6, 9, 18, 36, 72, }, 
		{1, 2, 3, 6, 9, 18, 36, 37, 73, }, 
		{1, 2, 3, 6, 9, 18, 19, 37, 74, }, 
		{1, 2, 3, 5, 10, 15, 25, 50, 75, }, 
		{1, 2, 3, 4, 8, 11, 19, 38, 76, }, 
		{1, 2, 4, 5, 9, 18, 36, 41, 77, }, 
		{1, 2, 3, 5, 10, 13, 26, 39, 78, }, 
		{1, 2, 3, 4, 8, 11, 19, 38, 76, 79, }, 
		{1, 2, 3, 5, 10, 20, 40, 80, }, 
		{1, 2, 3, 5, 10, 20, 40, 41, 81, }, 
		{1, 2, 3, 5, 10, 20, 21, 41, 82, }, 
		{1, 2, 3, 5, 10, 20, 40, 43, 83, }, 
		{1, 2, 3, 4, 7, 14, 21, 42, 84, }, 
		{1, 2, 3, 5, 10, 20, 40, 45, 85, }, 
		{1, 2, 3, 5, 10, 20, 23, 43, 86, }, 
		{1, 2, 3, 4, 7, 11, 22, 29, 58, 87, }, 
		{1, 2, 3, 4, 7, 11, 22, 44, 88, }, 
		{1, 2, 3, 4, 7, 11, 22, 44, 88, 89, }, 
		{1, 2, 3, 5, 10, 15, 30, 45, 90, }, 
		{1, 2, 3, 4, 7, 11, 22, 44, 47, 91, }, 
		{1, 2, 3, 5, 10, 13, 23, 46, 92, }, 
		{1, 2, 3, 4, 7, 14, 28, 31, 62, 93, }, 
		{1, 2, 3, 4, 7, 11, 22, 44, 47, 94, }, 
		{1, 2, 3, 4, 7, 11, 22, 44, 88, 95, }, 
		{1, 2, 3, 6, 12, 24, 48, 96, }, 
		{1, 2, 3, 6, 12, 24, 48, 49, 97, }, 
		{1, 2, 3, 6, 12, 24, 25, 49, 98, }, 
		{1, 2, 3, 6, 12, 24, 48, 51, 99, }, 
		{1, 2, 3, 5, 10, 15, 25, 50, 100, },
	};

	if (0)
	{
		vector <set <set <ll>>> dp (b + 1);
		{
			set<ll> ts;
			ts.insert (1);
			dp[1].insert (ts);
		}
		for (i = 2; i <= b; ++i)
		{
			for (j = 1; j <= i/2; ++j)
			{
				for (auto & ts1 : dp[i-j])
				{
					for (auto & ts2 : dp[j])
					{
						auto ns = ts1;
						for (auto a : ts2)
							ns.insert (a);
						ns.insert (i);
						if (!dp[i].size () || dp[i].begin ()->size () == ns.size ())
							dp[i].insert (ns);
						else if (dp[i].begin ()->size () > ns.size ())
						{
							dp[i].clear ();
							dp[i].insert (ns);
						}
					}
				}
			}
			// for (auto ns : dp[i])
			// {
			// cout << '\t';
			// for (auto a : ns) cout << a << ' ';
			// cout << '\n';
			// }
			// cout << "{";
			// for (auto a : *dp[i].begin ()) cout << a << ", ";
			// cout << "}, \n";
		}

		sets[b].clear ();
		for (auto a : *dp[b].begin ())
			sets[b].push_back (a);
	} // if (0)

	vector <ll> out = {1, 1};
	for (i = 2; i < sets[b].size (); ++i)
		for (j = 0; j < i; ++j)
			if (sets[b][j] + sets[b][i-1] == sets[b][i])
				out.push_back (sets[b][j]),
				out.push_back (sets[b][i-1]);
	for (auto a : out)
		cout << "1 " << a << '\n';

	return 0;
}
