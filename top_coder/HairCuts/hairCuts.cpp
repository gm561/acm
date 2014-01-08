#include <iomanip>
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
const double EPS = 1e-9;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

#define PF push_front
#define MP make_pair

struct HairCuts {

    double isPos(const VD& enter, double exit, double minCut) {
	double timeCurrent = 0.0;
	REP(i, SIZE(enter)) timeCurrent = minCut + max(enter[i], timeCurrent);

	return timeCurrent - exit;
    }

    double to24h(string t) {
	if(t[0] == '0' && t[1] != '9') {
	    t[0] = '1'; t[1] += 2;
	}

	double et = double(t[0] - '0')*3600*10
	    + double(t[1] - '0')*3600
	    + double(t[3] - '0')*60*10
	    + double(t[4] - '0')*60;

	return et - 9*3600;
    }

    double maxCut(VS enter, string exit) {
	VD en(SIZE(enter), 0.0);
	REP(i, SIZE(enter)) en[i] = to24h(enter[i]);
	double ex = to24h(exit);
	sort(ALL(en));

	double lo = 0.0;
	double hi = 8.0 * 3600;

	while(hi - lo >= EPS) {
	    double mid = (lo + hi) / 2;
	    double r = isPos(en, ex, mid);
	    if(abs(r) <= EPS)
		hi = mid;
	    else if(r < 0)
		lo = mid;
	    else
		hi = mid;
	}

	return hi >= 5.0 * 60.0 ? hi / 60.0 : -1;
    }
};

int main() {
    HairCuts hc;
    string a0[] = {"04:22","09:00"};
    string e0 = "05:52";
    VS s0(a0, a0 + 2);
    cout << hc.maxCut(s0, e0) << endl;

    string a1[] = {"09:00","09:22","09:22"};
    string e1 = "10:11";
    VS s1(a1, a1 + 3);
    cout << std::setprecision(20) << hc.maxCut(s1, e1) << endl;

    string a3[] = {"09:00","04:00","04:02"};
    string e3 = "04:09";
    VS s3(a3, a3 + 3);
    cout << std::setprecision(20) << hc.maxCut(s3, e3) << endl;

    return 0;
}
