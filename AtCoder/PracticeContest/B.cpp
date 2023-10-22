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
	ll i, j, n, q;
	cin >> n >> q;
	vector <ll> vec (n);
	for (i = 0; i < vec.size (); ++i) vec[i] = i;
	sort (vec.begin (), vec.end (), [&] (ll it, ll jt)
	{
		cout << "? " << (char) (it + 'A') << ' ' << (char) (jt + 'A') << endl;
		char c;
		cin >> c;
		if (c == '<') return true;
		else return false;
	});
	cout << "! ";
	trav (a, vec) cout << (char) (a + 'A');
	cout << endl;

	return 0;
}

