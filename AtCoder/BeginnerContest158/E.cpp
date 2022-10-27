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
     
    int main ()
    {
    	ios_base::sync_with_stdio (0);
    	cin.tie (0);
    	int tc = 1; //cin >> tc;
    	while (tc--)
    	{
    		ll i, j, n, p;
    		string s;
    		cin >> n >> p >> s;
    		vector <ll> dp (p, 0);
    		ll sum = 0, ans = 0, pot = 1;
    		if (p == 2 || p == 5)
    		{
    			for (i = 0; i < s.size (); ++i)
    				if ((s[i] - '0')%p == 0) ans += i + 1;
    		}
    		else
    		{
    			for (i = s.size () - 1; i >= 0; --i)
    			{
    				sum = (sum + pot*(ll)(s[i] - '0')) % p;
    				if (sum == 0) ++ans;
    				ans += dp[sum]++;
    				pot = pot*10LL%p;
    			}
    		}
    		cout << ans << '\n';
    	}
     
    	return 0;
    }
     
