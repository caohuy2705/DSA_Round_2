#include <iostream>
using namespace std;

// Hàm tìm kiếm vị trí của phần tử X trong mảng A[]
int fibonacciSearch(int A[], int n, int X)
{
    // Khởi tạo hai số Fibonacci đầu tiên
    int fib2 = 0; // F(n-2)
    int fib1 = 1; // F(n-1)
    int fib = fib2 + fib1; // F(n)

    // Tìm số Fibonacci lớn hơn hoặc bằng n
    while (fib < n)
    {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    // Đánh dấu vị trí hiện tại trong dãy Fibonacci
    int offset = -1;

    while (fib > 1)
    {
        // Kiểm tra nếu fib2 + offset không vượt quá n - 1
        int i = min(offset + fib2, n - 1);

        // Nếu X lớn hơn phần tử tại vị trí i, di chuyển sang phần tử bên phải fib2
        if (A[i] < X)
        {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        // Nếu X nhỏ hơn phần tử tại vị trí i, di chuyển sang phần tử bên trái fib1
        else if (A[i] > X)
        {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        // Nếu X được tìm thấy tại vị trí i
        else
        {
            return 1;
        }
    }

    // Kiểm tra phần tử cuối cùng
    if (fib1 == 1 && A[n - 1] == X)
    {
        return 1;
    }

    // X không có mặt trong mảng A[]
    return -1;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, X;
        cin >> n >> X;

        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        int result = fibonacciSearch(A, n, X);
        cout << result << endl;
    }

    return 0;
}
