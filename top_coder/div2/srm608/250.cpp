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
#define REP(x, n) for(int x=0; x<(n); ++x)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) (int)x.size()


struct OneDimensionalRobotEasy {

    int finalPosition(string commands, int A, int B) {
	int cur = 0;
	REP(i, commands.length()) {
	    commands[i] == 'R' ? ++cur : --cur;
	    cur = max(-A, cur);
	    cur = min(B, cur);
	}

	return cur;
    }

};

int main(int argc, char *argv[]) {
    OneDimensionalRobotEasy od;
    cout << od.finalPosition("RRLRRLLR", 10, 10) << endl;;

    return 0;
}
