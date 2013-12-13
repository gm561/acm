//http://codeforces.com/contest/371/problem/A
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <complex>
#include <iterator>
#include <set>
#include <bitset>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>

using namespace std;
typedef vector<int> VI;
typedef long long LL;

#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); --x)
#define REP(x, n) for(int x=0; x<(int)(n); ++x)
#define VAR(v,n) typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) (int)x.size()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second

const int INF = 1000000001;
const double EPS = 10e-9;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

#define PF push_front
#define MP make_pair

int main() {
    int n,k; cin >> n >> k;
    VI a; a.reserve(n);
    REP(i, n) {
	int t; cin >> t;
	a.PB(t);
    }

    int r = 0;
    VI ks; ks.reserve(n/k);
    REP(i, k) {
	ks.clear();
	REP(j, n/k) ks.PB(a[i + k*j]);
	sort(ALL(ks));
	int m,t; m  = t = 1;

	REP(l, n/k-1) {
	    if(ks[l] == ks[l+1]) ++t; else t = 1;
	    m = max(t,m);
	}

	r += n/k - m;
    }

    cout << r << "\n";
    return 0;
}
