//http://codeforces.com/contest/371/problem/C

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

const LL INF_LONG = 1000000000000000001;
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

struct trip {
    trip(LL b_, LL s_, LL c_) : b(b_), s(s_), c(c_) { }
    LL b; LL s; LL c;
};

bool isValid(LL num, LL m, const trip& n, const trip& p, const trip& r) {
    LL tb = max(r.b * num, n.b);
    LL ts = max(r.s * num, n.s);
    LL tc = max(r.c * num, n.c);

    return m - ((tb - n.b) * p.b + (ts - n.s) * p.s + (tc - n.c) * p.c) >= 0L;
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    string s; cin >> s;
    LL nb,ns,nc; cin >> nb >> ns >> nc;
    LL pb,ps,pc; cin >> pb >> ps >> pc;
    LL m; cin >> m;

    LL rb, rs, rc; rb = rs = rc = 0L;
    REP(i, s.length()) {
	if(s[i] == 'B') ++rb;
	else if(s[i] == 'S') ++rs;
	else if(s[i] == 'C') ++rc;
    }

    LL lo = 0;
    LL hi = m + 2*nb + 2*ns + 2*nc;

    while(hi - lo > 1) {
    	LL mid = lo + (hi - lo) / 2L;
    	if(isValid(mid, m, trip(nb, ns, nc), trip(pb, ps, pc), trip(rb, rs, rc)))
    	    lo = mid;
    	else
    	    hi = mid;
    }

   cout << lo << "\n";

   return 0;
}
