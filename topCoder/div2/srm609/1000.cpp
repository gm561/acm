#include <cassert>
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

typedef long long LL;

#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) (int)x.size()

#define PB push_back
#define ST first
#define ND second


typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef vector<VVL> VVVL;
typedef vector<VVVL> VVVVL;


struct VocaloidsAndSongs {

    inline int fun(VVVVL& space, int s, int g, int i, int m) {
	if(s == 0 && g == 0 && i == 0 && m == 0) return 1;

	if(s >= 0 && g >= 0 && i >= 0 && m >= 0)
	    return space[s][g][i][m];
	return 0;
    }

    int count(int S, int gu, int ia, int ma) {
	LL mod = 1000000007;

	VVVVL space(S+1, VVVL(gu+1, VVL(ia+1, VL(ma+1, 0))));
	FOR(s, 1, S)
	    FOR(g, 0, gu)
	    FOR(i, 0, ia)
	    FOR(m, 0, ma) {
	    if(space[s][g][i][m] == 0L) {
		LL r0 = 0;
                //only single sings
		r0 += fun(space, s-1, g-1, i, m);
		r0 %= mod;
		r0 += fun(space, s-1, g, i-1, m);
		r0 %= mod;
		r0 += fun(space, s-1, g, i, m-1);
		r0 %= mod;
		//two sing
		r0 += fun(space, s-1, g-1, i-1, m);
		r0 %= mod;
		r0 += fun(space, s-1, g-1, i, m-1);
		r0 %= mod;
		r0 += fun(space, s-1, g, i-1, m-1);
		r0 %= mod;
		//three sing
		r0 += fun(space, s-1, g-1, i-1, m-1);
		r0 %= mod;
		space[s][g][i][m] = r0;
	    }
	}

	return space[S][gu][ia][ma] % mod;
    }
};


int main() {

    VocaloidsAndSongs vs;
    cout << vs.count(3,1,1,1) << endl;
    cout << vs.count(3,3,1,1) << endl;
    cout << vs.count(50,10,10,10) << endl;
    cout << vs.count(18,12,8,9) << endl;
    cout << vs.count(50,25,25,25) << endl;
    return 0;
}
