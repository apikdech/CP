#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
    int arr[] = {4, 8, 15, 16, 23, 42};
    auto ask = [&](int i, int j) {
        int res;
        cout << "? " << i << " " << j << endl;
        cin >> res;
        return res;
    };
    int a = ask(1, 2);
    int b = ask(2, 3);
    int c = ask(4, 5);
    int d = ask(5, 6);
    do {
        if (arr[0] * arr[1] == a && arr[1] * arr[2] == b && arr[3] * arr[4] == c && arr[4] * arr[5] == d) {
            printf("! %d %d %d %d %d %d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
            cout << endl;
            return 0;
        }
    } while(next_permutation(arr, arr+6));
    return 0;
}