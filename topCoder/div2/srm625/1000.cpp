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
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<LL> VL;
typedef vector<vector<LL> > VVL;
typedef pair<int, int> pii;

#define FOR(i, s, e) for(int i = (s); i <= (e); ++i)
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

struct ConundrumReloaded {

    int minl(int k, bool c, string& s, int shift, int first, map<pii, int>& dp) {
        if(k == LN(s)) return 0;

        int res = 0;
        int i = k;
        bool next = c;
        while(i < LN(s) && s[i] != '?') {
            if(!next) ++res;
            if(s[i] == 'H' && next) next = true;
            else if(s[i] =='H' && !next) next = false;
            else if(s[i] == 'L' && next) next = false;
            else if(s[i] == 'L' && !next) next = true;
            ++i;
        }

        if(i == LN(s)) {
            return (first == next) ? res : INF;
        }
        else if(s[i] == '?' && !next) ++res;

        while(i < LN(s) && s[i] == '?') ++i;

        if(dp.find(MP(i, first)) != dp.end()) {
            return res + dp.find(MP(i,first))->second;
        }

        int r0 = minl(i, 0, s, shift, first, dp);
        int r1 = minl(i, 1, s, shift, first, dp);

        res = min(r0, r1) + res;
        dp.insert(MP(MP(k, first), res));
        return res;
    }

    int minimumLiars(string ans) {
        map<pii, int> dp;
        int shift = 0;
        REP(i, LN(ans)) if(ans[i] == '?') {
            shift = i;
            break;
        }

        int r0 = minl(0, 0, ans, shift, 0, dp);
        int r1 = minl(0, 1, ans, shift, 1, dp);

        int res = min(r0, r1);
        return (res >= INF) ? -1 : res;
    }
};

int main() {
    ConundrumReloaded cr;
    cout << cr.minimumLiars("LLH") << endl;
    cout << cr.minimumLiars("??????") << endl;
    cout << cr.minimumLiars("LHLH?") << endl;
    cout << cr.minimumLiars("??LLLLLL??") << endl;
    cout << cr.minimumLiars("LLL") << endl;

    return 0;
}
