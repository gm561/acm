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
typedef vector<int> VI;
typedef long long LL;
typedef vector<VI> VVI;


struct TheShuttles {

    int getLeastCost(vector<int> ls, int bc, int sc) {

	int leastCost = INF;
	FOR(i, 1, 50*100)
	    FOR(j, 1, 100) {
	    int nb = i;
	    REP(k, SIZE(ls)) nb -= ceil((ls[k])/(double)j);
	    if(nb >= 0) {
		leastCost = min(leastCost, i*(bc + j*sc));
	    }
	}

	return leastCost;
    }
};

int main() {

    TheShuttles s;
    VI t0; t0.PB(9);
    cout << s.getLeastCost(t0, 30, 5) << endl;
    VI t1; t1.PB(9); t1.PB(4);
    cout << s.getLeastCost(t1, 30, 5) << endl;
    VI t2; t2.PB(9); t2.PB(4);
    cout << s.getLeastCost(t2, 10, 5) << endl;
    return 0;
}
