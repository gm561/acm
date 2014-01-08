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
#define REP(x, n) for(int x=0; x<(n); ++x)
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

struct UnionOfIntervals{

    int nthElement(VI l, VI h, int n) {
	LL lo = -2000000000;
	LL hi = 2000000000;

	while(true) {
	    LL mid = lo + (hi - lo) / 2;
	    LL pos = 0;
	    LL eq = 0;
	    REP(i, SIZE(l)) {
		if(mid <= h[i] && mid >= l[i]) pos += mid - l[i], ++eq;
		else if(mid > h[i]) pos += h[i] - l[i] + 1;
	    }

	    if(pos <= n && pos + eq > n) return mid;
	    else if(pos == n) {
		int m = 2000000000;
		REP(i, SIZE(l)) {
		    if(l[i] > mid) m = min(l[i], m);
		}
		return m;
	    }
	    else if(pos < n) lo = mid + 1;
	    else if(pos > n) hi = mid - 1;
	}
    }
};


int main(int argc, char *argv[]) {

    UnionOfIntervals ui;
    int a0[] = {1,5};
    int b0[] = {3,7};

    VI v0(a0, sizeof(a0)/sizeof(int) + a0);
    VI v1(b0, sizeof(b0)/sizeof(int) + b0);

    cout << ui.nthElement(v0, v1, 4) << endl;

    int a1[] = {1,3};
    int b1[] = {4,5};

    VI v2(a1, sizeof(a1)/sizeof(int) + a1);
    VI v3(b1, sizeof(b1)/sizeof(int) + b1);

    cout << ui.nthElement(v2, v3, 3) << endl;

    VI v4; v4.PB(-1500000000);
    VI v5; v5.PB(1500000000);

    cout << ui.nthElement(v4, v5, 1500000091) << endl;

    VI v6; v6.PB(1999999999);
    VI v7; v7.PB(2000000000);

    cout << ui.nthElement(v6, v7, 1) << endl;
    return 0;
}
