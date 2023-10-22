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
	ll i, j, n, k;
    cin >> n >> k;
    string s, ans;
    cin >> s;
    ans = s;
    for (i = 0; i < k; ++i)
        for (j = i + k; j < n; j += k)
            ans[j] = ans[i];
    if (ans < s)
    {
        for (i = k - 1; s[i] == '9'; --i);
        for (j = i + 1; j < k; ++j) ans[j] = '0';
        ans[i]++;
        for (i = 0; i < k; ++i)
            for (j = i + k; j < n; j += k)
                ans[j] = ans[i];
    }
    cout << n << '\n' << ans << '\n';

	return 0;
}

