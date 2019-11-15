#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wununsed-variable"
#pragma GCC diagnostic ignored "-Wununsed-result"

#define ll long long
#define pii pair <int, int>
#define fi first
#define se second
#define mkp(x) make_pair ((x))
#define vi vector <int>
#define pb(x) push_back((x))
#define all(x) (x).begin (), (x).end ()
#define fora(x) for (auto & a : (x))

#define DEBUG 1
#define dbg_prnt(fmt, ...) \
        do { if (DEBUG) printf (fmt, __VA_ARGS__); } while (0)

using namespace std;

int main ()
{
    int N, T, i, j;
    scanf ("%d %d", &N, &T);
    vector <pair <int, string> > al (N);
    vector <vector <string> > ts (T);
    fora (al)
        cin >> a.se >> a.fi;
    sort (all (al));
    fora (al)
        dbg_prnt ("%s %d | ", a.se.c_str (), a.fi);
    dbg_prnt ("%c", '\n');
    for (i = 0; al.size (); i + 1 == ts.size () ? i = 0: i++)
    {
        ts[i].pb (al.back ().se);
        al.pop_back ();
    }
    for (i = 0; i < ts.size (); i++)
    {
        printf ("Time %d\n", i + 1);
        sort (all (ts[i]));
        fora (ts[i])
            printf ("%s\n", a.c_str ());
        printf ("\n");
    }

    return 0;
}
