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

struct ORSolitaireDiv2 {

    bool isPart(int a, int b) {
	return (~a & b) == 0;
    }

    bool isSolved(VI& num, int goal) {
	int result = 0;
	REP(i, SIZE(num))
	    if(isPart(goal, num[i])) result |= num[i];
	return result == goal;
    }

    int solve(vector<int> v, int goal, int k) {

	if(!isSolved(v, goal)) return 0;
	if(k == SIZE(v)) return INF;
	if(!isPart(goal, v[k])) return solve(v, goal, k+1);

	//do not remove
	int r0 = solve(v, goal, k + 1);
	//remove
	v[k] = 0;
	int r1 = solve(v, goal, k + 1);

	return min(r0, r1 + 1);
    }

    int getMinimum(vector<int> num, int goal) {
	int s = solve(num, goal, 0);
    	return s;
    }
};

int main() {
    ORSolitaireDiv2 o;
    VI num; num.PB(1); num.PB(2); num.PB(4);
    cout << o.getMinimum(num, 7) << endl;

    VI num0; num0.PB(1); num0.PB(2); num0.PB(4); num0.PB(7); num0.PB(8);
    cout << o.getMinimum(num0, 7) << endl;

    VI num1; num1.PB(12571295); num1.PB(2174218); num1.PB(2015120);
    cout << o.getMinimum(num1, 1) << endl;

    int t0[] = {5, 2, 4, 52, 62, 9, 8, 3, 1, 11, 6};

    VI num2(t0, t0 + sizeof(t0)/sizeof(int));
    cout << o.getMinimum(num2, 11) << endl;

    int t1[] = {503, 505, 152, 435, 491, 512, 1023, 355, 510, 500, 502, 255, 63, 508, 509, 511, 60, 250, 254, 346};

    VI num3(t1, t1 + sizeof(t1)/sizeof(int));
    cout << o.getMinimum(num3, 510) << endl;

    return 0;
}
