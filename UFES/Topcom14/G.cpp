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
	ll i, j, n;
	cin >> n;
	while (n--)
	{
		char c = 0;
		while (scanf ("%c", &c) == 1 && c != '"');
		string scn, tgt;
		while (scanf ("%c", &c) == 1 && c != '"') scn += c;
		while (scanf ("%c", &c) == 1 && c != '{');
		while (scanf ("%c", &c) == 1 && c != '}') tgt += c;
		int out, advance; bool atleast = false;
		scn += "%n";
		const char *tgtc = tgt.c_str (), *scnc = scn.c_str ();
		for (i = 0; sscanf (tgtc, scnc, &out, &advance) == 1 && i < 32000; ++i)
		{
			if (!atleast) printf ("%d", out);
			else printf (" %d", out);
			atleast = true;
			tgtc += advance;
		}
		if (!atleast || i >= 32000) printf ("FALHOU!");
		printf ("\n");
	}

	return 0;
}

