
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

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int k; cin >> k;

    VI n(9,0);
    REP(i, 4) {
	REP(j, 4) {
	    char c; cin >> c;
	    if(c != '.') ++n[c - '1'];
	}
    }

    bool r = true;
    REP(i,SIZE(n)) {
	if(n[i] > 2*k) r = false;
    }

    cout << (r ? "YES\n" : "NO\n");

    return 0;
}
