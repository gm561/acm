#include <stack>
#include <set>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <fstream>
#include <bitset>
#include <numeric>
#include <sstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<LL> VL;
typedef vector<vector<LL> > VVL;
typedef pair<int, int> pii;

#define REP(x, n) for(int x = 0; x < (n); ++x)
#define MP(x,y) make_pair(x,y)
#define ALL(x) (x).begin(), (x).end()
#define FT first
#define ST second
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB(x) push_back((x))
#define SZ(x) (int)x.size()
#define LN(x) (int)(x).length()
const int INF = 1000000001;

int optResultRec(const vector<int> &v, int i, int j, bool who) {
    if(i == j) return v[i];
    int result = 0;
    if(who) {
		result = max(optResultRec(v, i + 1, j, !who) + v[i], optResultRec(v, i, j-1,!who) + v[j]);
    }
    else {
        result = min(optResultRec(v, i + 1, j, !who), optResultRec(v, i, j-1,!who));
    }
	return result;
}


int optRestultIter(const vector<int>& vs) {
    int n = vs.size();
	bool who = !(vs.size() % 2); // true - max
	VVI res(n, VI(n,0));
	for(int i = 0; i < n; ++i) res[0][i] = vs[i];
	for(int i =  1; i < n; ++i) {
		for(int j = 0; j < n - i; ++j) {
			res[i][j] = (who) ? max(res[i-1][j] + vs[j + i], res[i-1][j+1] + vs[j] ) :
                min(res[i-1][j], res[i-1][j+1]);
        }
        who = !who;
    }
	return res[n-1][0];
}


void test0() {
    int as[] = {3,2,4,5,1};
    VI vs(as, as + sizeof(as) / sizeof(int));
    cout << optResultRec(vs, 0, vs.size()-1, true) << endl;
    cout << optRestultIter(vs) << endl;
}

void test1() {
    int as[] = {26,25,78,12,17};
    int sum = 0; REP(i, 5) sum += as[i];
    VI vs(as, as + sizeof(as) / sizeof(int));
    cout << optResultRec(vs, 0, vs.size()-1, true) << endl;
    cout << optRestultIter(vs) << endl;
    cout << "Oponent " << sum - optRestultIter(vs) << endl;
}

int main(int argc, char *argv[]) {
    test0(); test1();
    return 0;
}
