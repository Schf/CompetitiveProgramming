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
	ll i, j, n, k;
	cin >> n >> k;
	if (n == 1)
	{
		cout << 0 << '\n';
		return 0;
	}
	--n, --k;
	ll pa_sum = k*(k+1)/2;
	if (pa_sum < n)
		cout << -1 << '\n';
	else if (pa_sum == n)
		cout << k << '\n';
	else
	{
		ll ans;
		ll step = k/2, cur = 0;
		for (; step > 0; step /= 2)
			while (n - pa_sum + (cur+step)*(cur+step+1)/2 < 0)
				cur += step;
		++cur;
		ans = k - cur;
		if (n - pa_sum + (cur+step)*(cur+step+1)/2 > 0) ++ans;
		cout << ans << '\n';
	}

	return 0;
}

