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

int main (int argc, char * argv[])
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
    cout.tie (0);
	ll i, j, n;
    if (argc > 1)
        n = atoi (argv[1]);
    for (i = 0; i < n; ++i)
        cout << (char) (rand ()%26 + 'A');
    cout << '\n';

	return 0;
}

