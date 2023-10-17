#include <bits/stdc++.h>
using namespace std;

int n, k, C[35], A[1000];

void in() {
    for (int i = 1; i <= k; i++)
        cout << A[C[i]] << " ";
    cout << endl;
}

void sinh(int m) {
    int i, j;
    i = k;
    while (C[i] == m - k + i)
        i--;
    if (i == 0)
        return; // Điểm dừng của đệ quy

    C[i]++;
    for (j = i + 1; j <= k; j++)
        C[j] = C[j - 1] + 1;

    in();
    sinh(m); // Gọi đệ quy tiếp tục sinh các cấu hình kế tiếp
}

int main() {
    int i, j = 0;
    set<int> s;
    cin >> n >> k;
    for (i = 1; i <= n; i++) {
        cin >> A[i];
        s.insert(A[i]);
    }
    for (i = 1; i <= k; i++) {
        C[i] = i;
    }
    for (int x : s) {
        j++;
        A[j] = x;
    }

    sinh(j); // Gọi hàm đệ quy

    return 0;
}
