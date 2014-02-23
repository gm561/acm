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

struct MagicalStringDiv2 {

    int minimalMoves(string s) {
	int len = s.length();
	int ch = 0;
	FOR(i, 0, len/2-1) if(s[i] != '>') ++ch;
	FOR(i, len/2, len-1) if(s[i] != '<') ++ch;

	return ch;
    }
};

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    MagicalStringDiv2 ms;

    cout << ms.minimalMoves(">><<><") << endl;
    cout << ms.minimalMoves(">>>><<<<") << endl;
    cout << ms.minimalMoves("<<>>") << endl;
    cout << ms.minimalMoves("<><<<>>>>><<>>>>><>><<<>><><><><<><<<<<><<>>><><><") << endl;

    return 0;
}










