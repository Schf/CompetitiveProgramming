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

#define EPS 1e-9

struct point {
	long double x, y;
	point() { x = y = 0.0; }
	point(long double _x, long double _y) : x(_x), y(_y) {}
	long double norm() { return hypot(x, y); }
	point normalized() {
		return point(x,y)*(1.0/norm());
	}
	long double angle() { return atan2(y, x); }
	long double polarAngle() {
		long double a = atan2(y, x);
		return a < 0 ? a + 2*acos(-1.0) : a;
	}
	bool operator < (point other) const {
		if (fabs(x - other.x) > EPS) return x < other.x;
		else return y < other.y;
	}
	bool operator == (point other) const {
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
	}
	point operator +(point other) const {
		return point(x + other.x, y + other.y);
	}
	point operator -(point other) const {
		return point(x - other.x, y - other.y);
	}
	point operator *(long double k) const {
		return point(x*k, y*k);
	}
};
long double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}
long double inner(point p1, point p2) {
	return p1.x*p2.x + p1.y*p2.y;
}
long double cross(point p1, point p2) {
	return p1.x*p2.y - p1.y*p2.x;
}
bool ccw(point p, point q, point r) {
	return cross(q-p, r-p) > 0;
}
bool collinear(point p, point q, point r) {
	return fabs(cross(p-q, r-p)) < EPS;
}
point rotate(point p, long double rad) {
	return point(p.x * cos(rad) - p.y * sin(rad),
	p.x * sin(rad) + p.y * cos(rad));
}
long double angle(point a, point o, point b) {
	return acos(inner(a-o, b-o) / (dist(o,a)*dist(o,b)));
}
point proj(point u, point v) {
	return v*(inner(u,v)/inner(v,v));
}
bool between(point p, point q, point r) {
	return collinear(p, q, r) && inner(p - q, r - q) <= 0;
}
point lineIntersectSeg(point p, point q, point A, point B) {
	long double c = cross(A-B, p-q);
	long double a = cross(A, B);
	long double b = cross(p, q);
	return ((p-q)*(a/c)) - ((A-B)*(b/c));
}
bool parallel(point a, point b) {
	return fabs(cross(a, b)) < EPS;
}
bool segIntersects(point a, point b, point p, point q) {
	if (parallel(a-b, p-q)) {
		return between(a, p, b) || between(a, q, b)
			|| between(p, a, q) || between(p, b, q); 
	}
	point i = lineIntersectSeg(a, b, p, q);
	return between(a, i, b) && between(p, i, q);
}
point closestToLineSegment(point p, point a, point b) {
	long double u = inner(p-a, b-a) / inner(b-a, b-a);
	if (u < 0.0) return a;
	if (u > 1.0) return b;
	return a + ((b-a)*u);
}

typedef vector<point> polygon;

long double signedArea(polygon & P) {
	long double result = 0.0;
	int n = P.size();
	for (int i = 0; i < n; i++) {
		result += cross(P[i], P[(i+1)%n]);
	}
	return result / 2.0;
}

int leftmostIndex(vector<point> & P) {
	int ans = 0;
	for(int i=1; i<(int)P.size(); i++) {
		if (P[i] < P[ans]) ans = i;
	}
	return ans;
}

polygon make_polygon(vector<point> P) {
	if (signedArea(P) < 0.0) reverse(P.begin(), P.end());
	int li = leftmostIndex(P);
	rotate(P.begin(), P.begin()+li, P.end());
	return P;
}

long double perimeter(polygon & P) {
	long double result = 0.0;
	int n = P.size();
	for (int i = 0; i < n; i++) result += dist(P[i], P[(i+1)%n]);
	return result;
}

long double area(polygon & P) {
	return fabs(signedArea(P));
}

bool isConvex(polygon & P) {
	int n = (int)P.size();
	if (n < 3) return false;
	bool left = ccw(P[0], P[1], P[2]);
	for (int i = 1; i < n; i++) {
		if (ccw(P[i], P[(i+1)%n], P[(i+2)%n]) != left)
			return false;
	}
	return true;
}

bool inPolygon(polygon & P, point p) {
	if (P.size() == 0u) return false;
	long double sum = 0.0;
	int n = P.size();
	for (int i = 0; i < n; i++) {
		if (P[i] == p || between(P[i], p, P[(i+1)%n])) return true;
		if (ccw(p, P[i], P[(i+1)%n])) sum += angle(P[i], p, P[(i+1)%n]);
		else sum -= angle(P[i], p, P[(i+1)%n]);
	}
	return fabs(fabs(sum) - 2*acos(-1.0)) < EPS;
}

polygon cutPolygon(polygon & P, point a, point b) {
	vector<point> R;
	long double left1, left2;
	int n = P.size();
	for (int i = 0; i < n; i++) {
		left1 = cross(b-a, P[i]-a);
		left2 = cross(b-a, P[(i+1)%n]-a);
		if (left1 > -EPS) R.push_back(P[i]);
		if (left1 * left2 < -EPS) 
			R.push_back(lineIntersectSeg(P[i], P[(i+1)%n], a, b));
	}
	return make_polygon(R);
}

point pivot (0, 0);

bool angleCmp (point a, point b)
{
	if (collinear (pivot, a, b))
		return inner (pivot - a, pivot - a) < inner (pivot - b, pivot - b);
	return cross (a - pivot, b - pivot) >= 0;
}

polygon convexHull (vector <point> P)
{
	int i, j, n = (int) P.size ();
	if (n <= 2) return P;
	int P0 = leftmostIndex (P);
	swap (P[0], P[P0]);
	pivot = P[0];
	sort (++P.begin (), P.end (), angleCmp);
	vector <point> S;
	S.push_back (P[n - 1]);
	S.push_back (P[0]);
	S.push_back (P[1]);
	for (i = 2; i < n; )
	{
		j = (int) S.size () - 1;
		if (ccw (S[j - 1], S[j], P[i])) S.push_back (P[i++]);
		else S.pop_back ();
	}
	reverse (S.begin (), S.end ());
	S.pop_back ();
	reverse (S.begin (), S.end ());
	return S;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	ll i, j, n, p;
	cin >> n;
	long double ans = 0;
	for (i = 0; i < n; ++i)
	{
		cin >> p;
		polygon pol (p);
		for (j = 0; j < p; ++j)
			cin >> pol[j].x >> pol[j].y;
		//pol = convexHull (pol);
		pol = make_polygon (pol);
		ans += area (pol);
	}
	string s = to_string (ans);
	trav (c, s)
	{
		if (c == '.') break;
		cout << c;
	}
	cout << '\n';

	return 0;
}

