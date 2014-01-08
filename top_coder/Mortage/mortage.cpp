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

struct Mortgage {

    int monthlyPayment(int loan, int intrest, int term) {
	LL lo = 0;
	LL hi = loan;

	while(hi - lo > 1) {
	    LL mid = (hi - lo)/2 + lo;
	    LL x = loan;
	    int m = 0;
	    while(m++ < term * 12 && x <= loan) {
		x -= mid;
		x = ceil(((long double)intrest / 12 / 1000 + 1) * x);
	    }

	    if(x <= 0) hi = mid;
	    else lo = mid;
	}

	return hi;
    }
};

int main() {

    Mortgage m;
    cout << m.monthlyPayment(1000, 50, 1) << endl;
    cout << m.monthlyPayment(2000000000, 6000, 1) << endl;
    cout << m.monthlyPayment(1000000, 1000000, 1000) << endl;
    cout << m.monthlyPayment(1000000, 129, 30) << endl;
    cout << m.monthlyPayment(1999999999, 1000000, 1) << endl;
    return 0;
}
