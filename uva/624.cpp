#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <numeric>

#define REP(x, n) for(int x = 0; x < (n); ++x)
#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef vector<int> VI;

VI choose(int cur, int N, const VI& tracks, VI chosen) {
    if(N == 0 || cur >= SZ(tracks)) return chosen;
    VI ans0 = choose(cur + 1, N, tracks, chosen);

    if(N - tracks[cur] >= 0) {
        chosen.push_back(tracks[cur]);
        VI ans1 = choose(cur + 1, N - tracks[cur], tracks, chosen);

        int ans0_value = accumulate(ALL(ans0), 0);
        int ans1_value = accumulate(ALL(ans1), 0);
        return (ans0_value > ans1_value) ? ans0 : ans1;
    }
    return ans0;
}

void algo(const string& line) {
    stringstream ss(line);
    int N; ss >> N;
    int tracks_num; ss >> tracks_num;
    VI tracks; tracks.reserve(tracks_num);
    REP(_, tracks_num) {
        int len; ss >> len;
        tracks.push_back(len);
    }

    VI chosen;
    VI ans = choose(0, N, tracks, chosen);
    for(int x : ans) cout << x << " ";
    cout << "sum:" << accumulate(ans.begin(), ans.end(), 0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);

    string line;
    while(getline(cin, line)) algo(line);

    return 0;
}
