// http://codeforces.com/contest/371/problem/B

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
    int a,b; cin >> a >> b;
    int div[] = {2,3,5};

    int ops = 0;
    REP(i,3) {
	bool good = true;
	while(good) {
	    if(a % div[i] == 0 && b % div[i] == 0) a /= div[i], b /= div[i];
	    else if(a % div[i] == 0) a /= div[i], ++ops;
	    else if(b % div[i] == 0) b /= div[i], ++ops;
	    else good = false;
	}
    }
    cout << (a == b ? ops : -1) << "\n";
    return 0;
}
