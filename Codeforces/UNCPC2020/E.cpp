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
	ll i, j, n;
	cin >> n;
	cout << 1 << endl;
	ll floor, cur;
	cin >> floor;
	cur = 1 << floor;
	while (1)
	{
		ll resp;
		cout << cur << endl;
		cin >> resp;
		if (resp == 0)
		{
			cout << "! " << cur << endl;
			break;
		}
		else if (resp == 2)
		{
			cout << "! " << cur + 1 << endl;
			break;
		}
		else cur += 1LL << (resp/2 - 1);
	}

	return 0;
}

