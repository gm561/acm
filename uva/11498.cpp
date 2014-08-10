#include <iostream>

using namespace std;

void algo(const int N, const int M) {
    int x, y; cin >> x >> y;
    if(x < N && y < M) cout << "SO\n";
    else if(x < N && y > M) cout  << "NO\n";
    else if(x > N && y > M) cout << "NE\n";
    else if(x > N && y < M) cout <<"SE\n";
    else cout << "divisa\n";
}

int main() {
    int k;
    while(cin >> k, k != 0) {
        int N, M; cin >> N >> M;
        while(k--) algo(N, M);
    }
    return 0;
}
