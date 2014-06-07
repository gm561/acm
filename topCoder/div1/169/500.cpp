#include <numeric>
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

struct FairWorkload {

    bool isGood(VI& folders, int w, int sw) {
	int cur = 0;
	REP(i, SIZE(folders)) {
	    if(cur + folders[i] <= sw) cur += folders[i];
	    else if(folders[i] > sw) { w = -1; break; }
	    else --w, cur = folders[i];
	}

	return w > 0;
    }


    int getMostWork(VI folders, int workers) {
	int high = accumulate(ALL(folders),0);
	int low = accumulate(ALL(folders),0)/workers;

	while(high - low > 1) {
	    int mid = low + (high - low)/2;
	    if(isGood(folders, workers, mid)) {
		high = mid;
	    }
	    else {
		low = mid;
	    }
	}

	return high;
    }
};

int main() {

    FairWorkload fw;
    int a0[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
    VI v0(a0, sizeof(a0)/sizeof(int) + a0);
    cout << fw.getMostWork(v0, 3) << endl;

    int a1[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
    VI v1(a1, sizeof(a1)/sizeof(int) + a1);
    cout << fw.getMostWork(v1, 5) << endl;

    int a2[] = { 568, 712, 412, 231, 241, 393, 865, 287, 128, 457, 238, 98, 980, 23, 782 };
    VI v2(a2, sizeof(a2)/sizeof(int) + a2);
    cout << fw.getMostWork(v2, 4) << endl;

    int a3[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1000 };
    VI v3(a3, sizeof(a3)/sizeof(int) + a3);
    cout << fw.getMostWork(v3, 4) << endl;

    int a4[] = { 50, 50, 50, 50, 50, 50, 50 };
    VI v4(a4, sizeof(a4)/sizeof(int) + a4);
    cout << fw.getMostWork(v4, 2) << endl;

    int a5[] = { 950, 650, 250, 250, 350, 100, 650, 150, 150, 700 };
    VI v5(a5, sizeof(a5)/sizeof(int) + a5);
    cout << fw.getMostWork(v5, 6) << endl;
    return 0;
}
