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
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int ans = 0;
		double maior = -INF;
		
		for(int i=1;i<=n;i++){
			int a,b,c;
			
			cin >> a >> b >> c;
			
			double r = (double)b/(2*a);
			double t = -a*r*r + b*r + c;
			
			if(t > maior){
				maior = t;
				ans = i;
			}
		}
		
		cout << ans << endl;
	
	}
	return 0;
}


