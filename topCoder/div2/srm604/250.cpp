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

struct FoxAndWord {

    int isPair(string w0, string w1) {
	if(w0.length() != w1.length()) return 0;

	string cmp = w1 + w1;
	if(cmp.find(w0) == string::npos) return 0;
	return 1;
    }

    int howManyPairs(vector <string> words) {

	int total = 0;
	REP(i, SIZE(words)) {
	    for(int j = i + 1; j < SIZE(words); ++j) {
		total += isPair(words[i], words[j]);
	    }
	}

	return total;
    }
};


int main() {

    FoxAndWord f;

    vector<string> ws0;
    ws0.push_back("tokyo");
    ws0.push_back("kyoto");
    cout << f.howManyPairs(ws0) << endl;

    return 0;
}
