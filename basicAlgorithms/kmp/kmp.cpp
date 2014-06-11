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
#define FOREACH(i, c) for(typeof((c.begin())) i = (c).begin() ; i != (c).end(); ++i)
#define PB(x) push_back((x))
#define SZ(x) (int)x.size()
#define LN(x) (int)(x).length()
#define INF 1000001

void kmp(string s, string t,void (* f)(int)) {
    int p[t.size() + 1], i = 0, nt = SZ(t), k = 0;
    //compute prefix function moved by one
    p[1] = p[0] = 0;
    for(int i = 1; i < nt; ++i) {
        while(k > 0 && t[k] != t[i]) k = p[k];
        if(t[i] == t[k]) ++k;
        p[i+1] = k;
    }
    int ns = SZ(s);

    k = 0;
    for(int i = 0 ; i < ns; ++i) {
        while(k > 0 && t[k] != s[i]) k = p[k];
        if(s[i] == t[k]) ++k;
        if(k == nt) {
            f(i - nt + 1);
            k = p[k];
        }
    }
}

bool seen;
void cal(int a) {
    seen = true;
    cout << a << "\n";
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int _;
    while(cin >> _) {
        seen = false;
        string t; cin >> t;
        string s; cin >> s;
        kmp(s, t, cal);
        if(!seen) cout << "\n";
    }
    return 0;
}
