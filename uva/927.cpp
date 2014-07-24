#include <iostream>
#include <vector>
#include <algorithm>

#define REP(x, n) for(int x = 0; x < (n); ++x)
#define SZ(x) (int)((x).size())

using namespace std;

typedef vector<int> VI;

void algo() {
    int n; cin >> n;
    VI cof;
    REP(_, n + 1) {
        int c; cin >> c;
        cof.push_back(c);
    }

    int d,k; cin >> d >> k;
    int bi = 0;
    while(k >= 1) {
        ++bi;
        k -= bi * d;
    }

    long long val = 0l;
    for(int i = 0; i < SZ(cof); ++i) val += cof[i] * pow(bi, i);
    cout << val << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) algo();

    return 0;
}

