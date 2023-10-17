// File: CHELLO - Hello World.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << "Hello PTIT.";
}
 

// File: CHÊNH LỆCH NHỎ NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int to_int(string s)
{
    int a = 0;
    for (int i = 0; i < s.size(); i++)
    {
        a = a * 10 + s[i] - '0';
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    int a[n + 1], MIN = 1e9;
    vector<string> b(m);
    vector<string> c;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        b[i] = "0" + b[i];
    }
    for (int i = 1; i <= n; i++)
        a[i] = i;
    while (1)
    {
        c.clear();
        for (int i = 0; i < m; i++)
        {
            string x = b[i];
            for (int j = 1; j <= n; j++)
                x[j] = b[i][a[j]];
            c.push_back(x);
        }
        sort(c.begin(), c.end());
        MIN = min(MIN, to_int(c[c.size() - 1]) - to_int(c[0]));
        int ok = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a + i + 1, a + n + 1);
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > a[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (ok == 0)
            break;
    }
    cout << MIN;
}
 

// File: CTDL_001 - THUẬT TOÁN SINH.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool thuannghich(string s)
{
    int n = s.size();
    for (int i = 0; i <= n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
            return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string a;
    for (int i = 0; i < n; i++)
        a += '0';
    while (1)
    {
        if (thuannghich(a))
        {
            for (int i = 0; i < a.size(); i++)
                cout << a[i] << " ";
            cout << endl;
        }
        int ok = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == '0')
            {
                ok = 1;
                a[i] = '1';
                for (int j = i + 1; j < n; j++)
                    a[j] = '0';
                break;
            }
        }
        if (ok == 0)
            break;
    }
}
 

// File: CTDL_002 - Tổng dãy con = K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, k;
vector<int> a, b;
vector<vector<int>> res;
void pb()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == 1)
            sum += b[i];
    if (sum == k)
        res.push_back(a);
}
void BackTrack(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        a[i] = j;
        if (i == n - 1)
            pb();
        else
            BackTrack(i + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    a.resize(n, 0);
    b.resize(n, 0);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    BackTrack(0);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            if (res[i][j] == 1)
                cout << b[j] << ' ';
        cout << endl;
    }
    cout << res.size();
}
 

// File: CTDL_003 - PHƯƠNG ÁN TỐI ƯU.cpp
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string ans;
vector<pair<int, int>> x;
vector<vector<int>> F;
void trace(int n, int k)
{
    if (n == 0)
        return;
    if (F[n][k] == F[n - 1][k])
        trace(n - 1, k);
    else
    {
        trace(n - 1, k - x[n].first);
        ans[n - 1] = '1';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    F.resize((n + 1), vector<int>(k + 1, 0));
    x.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ans = ans + "0";
        cin >> x[i].second;
    }
    for (int i = 1; i <= n; i++)
        cin >> x[i].first;
    for (int i = 0; i <= n; i++)
    {
        F[i][0] = 0;
        F[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
        {
            if (j < x[i].first)
                F[i][j] = F[i - 1][j];
            else
                F[i][j] = max(F[i - 1][j], F[i - 1][j - x[i].first] + x[i].second);
        }
    cout << F[n][k] << endl;
    trace(n, k);
    for (char i : ans)
        cout << i << ' ';
}
 

// File: CTDL_004 - DÃY CON TĂNG DẦN BẬC K.cpp
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, k, ans = 0;
int a[200], b[200];
void backtracking(int pos1, int pos2)
{
    if (pos2 == k)
    {
        ans++;
        return;
    }
    for (int i = pos1 + 1; i < n; i++)
    {
        if (a[i] > a[pos1])
        {
            b[pos2 + 1] = a[i];
            backtracking(i, pos2 + 1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        b[0] = a[i];
        backtracking(i, 1);
    }
    cout << ans;
}
 

// File: CTDL_005 - XÓA DỮ LIỆU TRONG DSLK ĐƠN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n], k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> k;
    for (int i = 0; i < n; i++)
        if (a[i] != k)
            cout << a[i] << " ";
}
 

// File: CTDL_006 - LỌC DỮ LIỆU TRÙNG TRONG DSLK ĐƠN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        m[x]++;
        if (m[x] == 1)
            cout << x << " ";
    }
}
 

// File: DI CHUYỂN TRONG MÊ CUNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[12][12];
vector<string> ans;
vector<pair<string, pair<int, int>>> p = {{"D", {1, 0}}, {"L", {0, -1}}, {"R", {0, 1}}, {"U", {-1, 0}}};
void Try(int i, int j, string s)
{
    if (i == n && j == n)
    {
        ans.push_back(s);
        return;
    }
    for (int k = 0; k < 4; k++)
    {
        int u = i + p[k].second.first;
        int v = j + p[k].second.second;
        if (u >= 1 && u <= n && v >= 1 && v <= n && a[u][v])
        {
            a[u][v] = 0;
            Try(u, v, s + p[k].first);
            a[u][v] = 1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        if (a[1][1] == 1)
        {
            a[1][1] = 0;
            Try(1, 1, "");
        }
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            cout << ans.size() << " ";
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
            cout << endl;
        }
    }
}
 

// File: DSA01001 - XÂU NHỊ PHÂN KẾ TIẾP.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        s = '0' + s;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                s[i] = '1';
                for (int j = i + 1; j < s.size(); j++)
                    s[j] = '0';
                break;
            }
        }
        for (int i = 1; i < s.size(); i++)
            cout << s[i];
        cout << endl;
    }
}
 

// File: DSA01002 - TẬP CON KẾ TIẾP.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[k + 1];
        for (int i = 1; i <= k; i++)
            cin >> a[i];
        a[0] = -1;
        for (int i = k; i >= 0; i--)
        {
            if (a[i] != n - k + i)
            {
                a[i]++;
                for (int j = i + 1; j <= k; j++)
                    a[j] = a[j - 1] + 1;
                break;
            }
        }
        for (int i = 1; i <= k; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}
 

// File: DSA01003 - HOÁN VỊ KẾ TIẾP.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ok = 0, a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a + i, a + n + 1);
                swap(a[i], a[i + 1]);
                break;
            }
        }
        if (ok == 0)
        {
            for (int i = 1; i <= n; i++)
                a[i] = i;
        }
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}
 

// File: DSA01004 - SINH TỔ HỢP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[k + 1];
		for (int i = 1; i <= k; i++)
			a[i] = i;
		while (1)
		{
			for (int i = 1; i <= k; i++)
				cout << a[i];
			cout << " ";
			int ok = 0;
			for (int i = k; i >= 1; i--)
			{
				if (a[i] != n - k + i)
				{
					ok = 1;
					a[i]++;
					for (int j = i + 1; j <= k; j++)
						a[j] = a[j - 1] + 1;
					break;
				}
			}
			if (ok == 0)
				break;
		}
		cout << endl;
	}
}
 

// File: DSA01005 - SINH HOÁN VỊ.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            a[i] = i;
        while (1)
        {
            for (int i = 1; i <= n; i++)
                cout << a[i];
            cout << " ";
            int ok = 0;
            for (int i = n - 1; i >= 1; i--)
            {
                if (a[i] < a[i + 1])
                {
                    ok = 1;
                    sort(a + i + 1, a + n + 1);
                    for (int j = i + 1; j <= n; j++)
                    {
                        if (a[j] > a[i])
                        {
                            swap(a[i], a[j]);
                            break;
                        }
                    }
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        cout << endl;
    }
}
 

// File: DSA01006 - HOÁN VỊ NGƯỢC.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            a[i] = i;
        stack<string> st;
        while (1)
        {
            string s = "";
            for (int i = 1; i <= n; i++)
                s += to_string(a[i]);
            st.push(s);
            int ok = 0;
            for (int i = n - 1; i >= 1; i--)
            {
                if (a[i] < a[i + 1])
                {
                    ok = 1;
                    sort(a + i + 1, a + n + 1);
                    for (int j = i + 1; j <= n; j++)
                    {
                        if (a[j] > a[i])
                        {
                            swap(a[i], a[j]);
                            break;
                        }
                    }
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        while (st.size())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
}
 

// File: DSA01007 - XÂU AB CÓ ĐỘ DÀI N.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a;
        for (int i = 0; i < n; i++)
            a += 'A';
        while (1)
        {
            cout << a << " ";
            int ok = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (a[i] == 'A')
                {
                    ok = 1;
                    a[i] = 'B';
                    for (int j = i + 1; j < n; j++)
                        a[j] = 'A';
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        cout << endl;
    }
}
 

// File: DSA01008 - XÂU NHỊ PHÂN CÓ K BIT 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[k];
        for (int i = 0; i < k; i++)
            a[i] = i;
        stack<string> st;
        while (1)
        {
            string s = "";
            for (int i = 0; i < n; i++)
                s += '0';
            for (int i = 0; i < k; i++)
                s[a[i]] = '1';
            st.push(s);
            int ok = 0;
            for (int i = k - 1; i >= 0; i--)
            {
                if (a[i] != n - k + i)
                {
                    ok = 1;
                    a[i]++;
                    for (int j = i + 1; j < k; j++)
                        a[j] = a[j - 1] + 1;
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        while (st.size())
        {
            cout << st.top() << endl;
            st.pop();
        }
    }
}
 

// File: DSA01009 - XÂU AB ĐẶC BIỆT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool check(string s, int n)
{
    s = 'B' + s + 'B';
    for (int i = 0; i < s.size() - n - 1; i++)
    {
        if (s[i] == 'B' && s[i + n + 1] == 'B')
        {
            int d = 0;
            for (int j = i + 1; j <= i + n; j++)
            {
                if (s[j] == 'A')
                    d++;
            }
            if (d == n)
                return 1;
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string a;
    queue<string> q;
    for (int i = 0; i < n; i++)
        a += 'A';
    while (1)
    {
        if (check(a, k))
            q.push(a);
        int ok = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == 'A')
            {
                ok = 1;
                a[i] = 'B';
                for (int j = i + 1; j < n; j++)
                    a[j] = 'A';
                break;
            }
        }
        if (ok == 0)
            break;
    }
    cout << q.size() << endl;
    while (q.size())
    {
        cout << q.front() << endl;
        q.pop();
    }
}
 

// File: DSA01010 - TẬP QUÂN SỰ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, s = 0, ok = 0;
        cin >> n >> k;
        int a[k + 1], b[k + 1];
        map<int, int> m;
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i];
            b[i] = a[i];
            m[a[i]]++;
        }
        for (int i = k; i >= 1; i--)
        {
            if (a[i] != n - k + i)
            {
                ok = 1;
                a[i]++;
                for (int j = i + 1; j <= k; j++)
                    a[j] = a[j - 1] + 1;
                break;
            }
        }
        for (int i = 1; i <= k; i++)
        {
            if (m[a[i]] == 0)
                s++;
        }
        if (ok == 0)
            s = k;
        cout << s << endl;
    }
}
 

// File: DSA01011 - HOÁN VỊ TIẾP THEO CỦA CHUỖI SỐ.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int test;
		string s;
		cin >> test >> s;
		int n = s.length();
		int i = n - 2;
		while (s[i + 1] <= s[i])
			i--;
		if (i < 0)
			cout << test << " BIGGEST" << endl;
		else
		{
			int k = n - 1;
			while (s[i] >= s[k])
				k--;
			swap(s[i], s[k]);
			sort(s.begin() + i + 1, s.end());
			cout << test << ' ' << s << endl;
		}
	}
}
 

// File: DSA01012 - MÃ GRAY 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> a;
        a.push_back("0");
        a.push_back("1");
        for (int i = 2; i < (1 << n); i = i << 1)
        {
            for (int j = i - 1; j >= 0; j--)
                a.push_back(a[j]);
            for (int j = 0; j < i; j++)
                a[j] = "0" + a[j];
            for (int j = i; j < 2 * i; j++)
                a[j] = "1" + a[j];
        }
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        cout << endl;
    }
}
 

// File: DSA01013 - MÃ GRAY 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{

    vector<vector<string>> ans;
    vector<string> a;
    a.push_back("0");
    a.push_back("1");
    ans.push_back(a);
    for (int i = 0; i < 9; i++)
    {
        a.clear();
        for (int j = 0; j < ans[i].size(); j++)
        {
            a.push_back('0' + ans[i][j]);
        }
        for (int j = ans[i].size() - 1; j >= 0; j--)
        {
            a.push_back('1' + ans[i][j]);
        }
        ans.push_back(a);
    }
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int k;
        vector<int> b;
        for (int i = 0; i < ans[s.length() - 1].size(); i++)
        {
            if (ans[s.length() - 1][i] == s)
            {
                k = i;
                break;
            }
        }
        while (k != 0)
        {
            b.push_back(k % 2);
            k /= 2;
        }
        for (int i = 0; i < s.length() - b.size(); i++)
            cout << 0;
        for (int i = b.size() - 1; i >= 0; i--)
            cout << b[i];
        cout << endl;
    }
}
 

// File: DSA01014 - TẬP HỢP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (1)
    {
        int n, k, s, d = 0;
        cin >> n >> k >> s;
        if (n < k)
        {
            cout << 0 << endl;
            continue;
        }
        if (n == 0 && k == 0 && s == 0)
            return 0;
        int a[k + 1];
        for (int i = 1; i <= k; i++)
            a[i] = i;
        while (1)
        {
            int x = 0;
            for (int i = 1; i <= k; i++)
                x += a[i];
            if (x == s)
                d++;
            int ok = 0;
            for (int i = k; i >= 1; i--)
            {
                if (a[i] != n - k + i)
                {
                    ok = 1;
                    a[i]++;
                    for (int j = i + 1; j <= k; j++)
                        a[j] = a[j - 1] + 1;
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        cout << d << endl;
    }
}
 

// File: DSA01015 - TÌM BỘI SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        queue<long long> q;
        q.push(9);
        while (q.size())
        {
            long long k = q.front();
            q.pop();
            if (k % n == 0)
            {
                cout << k << endl;
                break;
            }
            q.push(k * 10);
            q.push(k * 10 + 9);
        }
    }
}
 

// File: DSA01016 - PHÂN TÍCH SỐ 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    int d[10];
};
bool cmp(struct data a, struct data b)
{
    for (int i = 0; i < 10; i++)
    {
        if (a.d[i] != b.d[i])
            return a.d[i] > b.d[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x = 0;
        cin >> n;
        struct data c[50];
        for (int i = 0; i < 50; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                c[i].d[j] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            int a[i];
            for (int j = 0; j < i; j++)
                a[j] = n - i + 1;
            while (1)
            {
                int s = 0, ok = 0;
                for (int j = 0; j < i; j++)
                    s += a[j];
                if (s == n)
                {
                    for (int j = 0; j < i; j++)
                        c[x].d[j] = a[j];
                    x++;
                }
                for (int j = i - 1; j >= 0; j--)
                {
                    if (a[j] != 1)
                    {
                        ok = 1;
                        a[j]--;
                        for (int jj = j + 1; jj < i; jj++)
                            a[jj] = a[j];
                        break;
                    }
                }
                if (ok == 0)
                    break;
            }
        }
        sort(c, c + x, cmp);
        for (int i = 0; i < x; i++)
        {
            cout << "(" << c[i].d[0];
            for (int j = 1; j < 10; j++)
            {
                if (c[i].d[j] == 0)
                    break;
                cout << " " << c[i].d[j];
            }
            cout << ") ";
        }
        cout << endl;
    }
}
 

// File: DSA01017 - MÃ GRAY 3.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    vector<vector<string>> ans;
    vector<string> a;
    a.push_back("0");
    a.push_back("1");
    ans.push_back(a);
    for (int i = 0; i < 9; i++)
    {
        a.clear();
        for (int j = 0; j < ans[i].size(); j++)
        {
            a.push_back('0' + ans[i][j]);
        }
        for (int j = ans[i].size() - 1; j >= 0; j--)
        {
            a.push_back('1' + ans[i][j]);
        }
        ans.push_back(a);
    }
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        long long k = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                k += (1 << (s.length() - 1 - i));
            }
        }
        cout << ans[s.length() - 1][k] << endl;
    }
}
 

// File: DSA01018 - TẬP CON LIỀN KỀ PHÍA TRƯỚC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[k + 1], ok = 0, pos = k - 1;
		for (int i = 1; i <= k; i++)
			cin >> a[i];
		while (a[pos] + 1 == a[pos + 1] && pos > 0)
		{
			pos--;
		}
		if (pos == 0)
			for (int i = n - k + 1; i <= n; i++)
				cout << i << " ";
		else
		{
			pos++;
			a[pos]--;
			for (int i = k; i > pos; i--)
				a[i] = n - k + i;
			for (int i = 1; i <= k; i++)
				cout << a[i] << " ";
		}
		cout << endl;
	}
}
 

// File: DSA01019 - HAHAHA.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool check(string a)
{
    int n = a.size();
    if (a[0] != 'H' || a[n - 1] != 'A')
        return 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == 'H' && a[i + 1] == 'H')
            return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a;
        for (int i = 0; i < n; i++)
            a += 'A';
        while (1)
        {
            if (check(a))
                cout << a << endl;
            int ok = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (a[i] == 'A')
                {
                    ok = 1;
                    a[i] = 'H';
                    for (int j = i + 1; j < n; j++)
                        a[j] = 'A';
                    break;
                }
            }
            if (ok == 0)
                break;
        }
    }
}
 

// File: DSA01020 - XÂU NHỊ PHÂN TRƯỚC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        int n = a.size();
        a = "1" + a;
        for (int i = n; i >= 0; i--)
        {
            if (a[i] == '1')
            {
                a[i] = '0';
                for (int j = i + 1; j <= n; j++)
                    a[j] = '1';
                break;
            }
        }
        for (int i = 1; i <= n; i++)
            cout << a[i];
        cout << endl;
    }
}
 

// File: DSA01021 - TỔ HỢP TIẾP THEO.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, s = 0, ok = 0;
        cin >> n >> k;
        int a[k + 1], b[k + 1];
        map<int, int> m;
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i];
            b[i] = a[i];
            m[a[i]]++;
        }
        for (int i = k; i >= 1; i--)
        {
            if (a[i] != n - k + i)
            {
                ok = 1;
                a[i]++;
                for (int j = i + 1; j <= k; j++)
                    a[j] = a[j - 1] + 1;
                break;
            }
        }
        for (int i = 1; i <= k; i++)
        {
            if (m[a[i]] == 0)
                s++;
        }
        if (ok == 0)
            s = k;
        cout << s << endl;
    }
}
 

// File: DSA01022 - SỐ THỨ TỰ HOÁN VỊ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[10], b[10];
bool check()
{
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int p = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            a[i] = i;
            cin >> b[i];
        }
        while (++p)
        {
            if (check())
            {
                cout << p << endl;
                break;
            }
            for (int i = n - 1; i >= 1; i--)
            {
                if (a[i] < a[i + 1])
                {
                    sort(a + i + 1, a + n + 1);
                    for (int j = i + 1; j <= n; j++)
                    {
                        if (a[j] > a[i])
                        {
                            swap(a[i], a[j]);
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
}
 

// File: DSA01023 - SỐ THỨ TỰ TỔ HỢP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, k, a[15], b[15];
bool check()
{
    for (int i = 1; i <= k; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int p = 0;
        cin >> n >> k;
        for (int i = 1; i <= k; i++)
        {
            a[i] = i;
            cin >> b[i];
        }
        while (++p)
        {
            if (check())
            {
                cout << p << endl;
                break;
            }
            for (int i = k; i >= 1; i--)
            {
                if (a[i] != n - k + i)
                {
                    a[i]++;
                    for (int j = i + 1; j <= k; j++)
                        a[j] = a[j - 1] + 1;
                    break;
                }
            }
        }
    }
}
 

// File: DSA01024 - ĐẶT TÊN - 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string x;
    vector<string> a;
    map<string, int> m;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        m[x]++;
    }
    for (auto i : m)
        a.push_back(i.first);
    n = a.size();
    a.insert(a.begin(), 1, "");
    int dd[k + 1];
    for (int i = 1; i <= k; i++)
        dd[i] = i;
    while (1)
    {
        for (int i = 1; i <= k; i++)
            cout << a[dd[i]] << " ";
        cout << endl;
        int ok = 0;
        for (int i = k; i >= 1; i--)
        {
            if (dd[i] != n - k + i)
            {
                ok = 1;
                dd[i]++;
                for (int j = i + 1; j <= k; j++)
                    dd[j] = dd[j - 1] + 1;
                break;
            }
        }
        if (ok == 0)
            return 0;
    }
}
 

// File: DSA01025 - ĐẶT TÊN - 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[k + 1];
        for (int i = 1; i <= k; i++)
            a[i] = i;
        while (1)
        {
            int ok = 0;
            for (int i = 1; i <= k; i++)
                cout << (char)(a[i] + 'A' - 1);
            cout << endl;
            for (int i = k; i >= 1; i--)
            {
                if (a[i] != n - k + i)
                {
                    ok = 1;
                    a[i]++;
                    for (int j = i + 1; j <= k; j++)
                        a[j] = a[j - 1] + 1;
                    break;
                }
            }
            if (ok == 0)
                break;
        }
    }
}
 

// File: DSA01026 - PHÁT LỘC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
void Try(string s)
{
    int k = s.size();
    if (n == k)
    {
        if (s[n - 1] == '6')
            cout << s << endl;
        return;
    }
    if (s[k - 1] == '8')
        Try(s + "6");
    else
    {
        if (k < 4)
            Try(s + "6");
        else if (s[k - 2] == '8' || s[k - 3] == '8')
            Try(s + "6");
        Try(s + "8");
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    Try("8");
}
 

// File: DSA01027 - HOÁN VỊ DÃY SỐ.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
        cin >> b[i];
    }
    sort(b + 1, b + n + 1);
    while (1)
    {
        for (int i = 1; i <= n; i++)
            cout << b[a[i]] << " ";
        cout << endl;
        int ok = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a + i + 1, a + n + 1);
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > a[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (ok == 0)
            break;
    }
}
 

// File: DSA01028 - LIỆT KÊ TỔ HỢP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, x;
    cin >> n >> k;
    int a[k + 1];
    vector<int> b;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        m[x]++;
    }
    b.push_back(0);
    for (auto i : m)
        b.push_back(i.first);
    n = b.size() - 1;
    for (int i = 1; i <= k; i++)
        a[i] = i;
    while (1)
    {
        for (int i = 1; i <= k; i++)
            cout << b[a[i]] << " ";
        cout << endl;
        int ok = 0;
        for (int i = k; i >= 1; i--)
        {
            if (a[i] != n - k + i)
            {
                ok = 1;
                a[i]++;
                for (int j = i + 1; j <= k; j++)
                    a[j] = a[j - 1] + 1;
                break;
            }
        }
        if (ok == 0)
            break;
    }
}
 

// File: DSA02001 - DÃY SỐ 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            cout << "[" << a[0];
            for (int j = 1; j < n - i; j++)
            {
                cout << " " << a[j];
                b[j - 1] = a[j - 1] + a[j];
            }
            cout << "]" << endl;
            for (int j = 0; j < n - i; j++)
            {
                a[j] = b[j];
            }
        }
    }
}
 

// File: DSA02002 - DÃY SỐ 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s = "";
        vector<int> a(n), b(n);
        stack<string> st;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            s += "[" + to_string(a[0]);
            for (int j = 1; j < n - i; j++)
            {
                s += " " + to_string(a[j]);
                b[j - 1] = a[j - 1] + a[j];
            }
            s += "]";
            st.push(s);
            s = "";
            for (int j = 0; j < n - i; j++)
            {
                a[j] = b[j];
            }
        }
        while (st.size())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
}

// File: DSA02003 - DI CHUYỂN TRONG MÊ CUNG 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[12][12];
vector<string> ans;
void Try(int i, int j, string s)
{
    if (i == n && j == n)
    {
        ans.push_back(s);
        return;
    }
    if (i < n && a[i + 1][j] == 1)
        Try(i + 1, j, s + "D");
    if (j < n && a[i][j + 1] == 1)
        Try(i, j + 1, s + "R");
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
            }
        }
        if (a[1][1] == 1)
            Try(1, 1, "");
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
            cout << endl;
        }
    }
}
 

// File: DSA02004 - DI CHUYỂN TRONG MÊ CUNG 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[12][12];
vector<string> ans;
vector<pair<string, pair<int, int>>> p = {{"D", {1, 0}}, {"L", {0, -1}}, {"R", {0, 1}}, {"U", {-1, 0}}};
void Try(int i, int j, string s)
{
    if (i == n && j == n)
    {
        ans.push_back(s);
        return;
    }
    for (int k = 0; k < 4; k++)
    {
        int u = i + p[k].second.first;
        int v = j + p[k].second.second;
        if (u >= 1 && u <= n && v >= 1 && v <= n && a[u][v])
        {
            a[u][v] = 0;
            Try(u, v, s + p[k].first);
            a[u][v] = 1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        if (a[1][1] == 1)
        {
            a[1][1] = 0;
            Try(1, 1, "");
        }
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
            cout << endl;
        }
    }
}
 

// File: DSA02005 - HOÁN VỊ XÂU KÝ TỰ.cpp
#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000], dd[1000] = {};
void Try(int n)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (!dd[i])
        {
            a[n] = i;
            dd[i] = 1;
            if (n == s.size() - 1)
            {
                for (int i = 0; i < s.size(); i++)
                    cout << s[a[i]];
                cout << " ";
            }
            else
                Try(n + 1);
            dd[i] = 0;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        Try(0);
        cout << endl;
    }
}
 

// File: DSA02006 - DÃY CON TỔNG BẰNG K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, k, a[101], b[101], ok;
void Try(int posa, int posb, int s)
{
    for (int i = posa + 1; i <= n; i++)
    {
        if (s + a[i] == k)
        {
            ok = 1;
            b[posb + 1] = a[i];
            cout << "[" << b[0];
            for (int j = 1; j <= posb + 1; j++)
                cout << " " << b[j];
            cout << "] ";
            return;
        }
        else if (s + a[i] < k)
        {
            b[posb + 1] = a[i];
            Try(i, posb + 1, s + a[i]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ok = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        Try(0, -1, 0);
        if (ok == 0)
            cout << -1 << endl;
        cout << endl;
    }
}
 

// File: DSA02007 - ĐỔI CHỖ CÁC CHỮ SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        while (n--)
        {
            int l = 0, r = s.size() - 1, k = r;
            while (l < r && s[l + 1] <= s[l])
                l++;
            if (l == r)
                break;
            while (l < r)
            {
                if (s[r] > s[k])
                    k = r;
                r--;
            }
            l = 0;
            while (l < k && s[l] >= s[k])
                l++;
            swap(s[l], s[k]);
        }
        cout << s << endl;
    }
}
 

// File: DSA02008 - CHỌN SỐ TỪ MA TRẬN VUÔNG CẤP N.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    int b[n + 1][n + 1];
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> b[i][j];
    while (1)
    {
        int x = 0;
        for (int i = 1; i <= n; i++)
            x += b[i][a[i]];
        if (x == k)
            ans.push_back(a);
        int ok = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a.begin() + i + 1, a.end());
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > a[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (ok == 0)
            break;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 1; j <= n; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
 

// File: DSA02009 - CHIA MẢNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, k, sum;
bool ans = 0;
vector<int> a;
void Try(int s, int tmp)
{
    if (ans)
        return;
    if (tmp == k)
    {
        ans = 1;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (s == sum)
            Try(0, tmp + 1);
        else if (s < sum)
            Try(s + a[i], tmp);
        else
            return;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        sum = 0;
        a.clear();
        a.resize(n);
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % k != 0)
            cout << 0 << endl;
        else
        {
            sum /= k;
            Try(0, 0);
            cout << ans << endl;
        }
    }
}
 

// File: DSA02010 - TỔ HỢP SỐ CÓ TỔNG BẰNG X.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    vector<int> b;
};
int n, k, a[25], c[105];
vector<struct data> d;
void Try(int x, int i, int s)
{
    for (int ii = i; ii <= n; ii++)
    {
        s += a[ii];
        c[x] = a[ii];
        if (s == k)
        {
            struct data e;
            for (int jj = 1; jj <= x; jj++)
                e.b.push_back(c[jj]);
            d.push_back(e);
        }
        else if (s < k)
            Try(x + 1, ii, s);
        s -= a[ii];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        d.clear();
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        Try(1, 1, 0);
        if (d.size() == 0)
        {
            cout << "-1" << endl;
            continue;
        }
        for (int i = 0; i < d.size(); i++)
        {
            cout << "[" << d[i].b[0];
            for (int j = 1; j < d[i].b.size(); j++)
            {
                if (d[i].b[j] == 0)
                    break;
                cout << " " << d[i].b[j];
            }
            cout << "]";
        }
        cout << endl;
    }
}
 

// File: DSA02011 - MÁY ATM.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, k, a[35], b[35], ss, mi, ok;
void Try(int x)
{
    for (int i = b[x - 1] + 1; i <= n; i++)
    {
        b[x] = i;
        if (x == k)
        {
            int s = 0;
            for (int j = 1; j <= k; j++)
                s += a[b[j]];
            if (s == ss)
            {
                ok = 1;
                mi = k;
                return;
            }
        }
        else
            Try(x + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        a[0] = ok = 0;
        mi = 50;
        cin >> n >> ss;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            k = i;
            Try(1);
            if (ok == 1)
                break;
        }
        if (ok == 0)
            cout << -1 << endl;
        else
            cout << mi << endl;
    }
}
 

// File: DSA02012 - DI CHUYỂN TRONG MA TRẬN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m;
        int a[n + 1][m + 1] = {};
        a[0][1] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> x;
                a[i][j] = a[i - 1][j] + a[i][j - 1];
            }
        }
        cout << a[n][m] << endl;
    }
}
 

// File: DSA02013 - SỐ NGUYÊN TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, p, ss;
vector<int> a, x;
vector<bool> check(205, 1);
vector<vector<int>> ans;
void era()
{
    for (int i = 2; i <= 200; i++)
    {
        if (check[i])
        {
            a.push_back(i);
            for (int j = i * i; j <= 200; j += i)
                check[j] = 0;
        }
    }
    m = a.size() - 1;
}
void Try(int pos, int k, int s)
{
    for (int i = pos + 1; i <= m; i++)
    {
        if (s + a[i] == ss && k == n - 1)
        {
            x.push_back(a[i]);
            ans.push_back(x);
            x.pop_back();
        }
        else if (k < n - 1 && s + a[i] < ss)
        {
            x.push_back(a[i]);
            Try(i, k + 1, s + a[i]);
            x.pop_back();
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    era();
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        cin >> n >> p >> ss;
        int b = 0;
        while (a[b] <= p)
            b++;
        Try(b - 1, 0, 0);
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
}
 

// File: DSA02014 - TỪ ĐIỂN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int k, n, m, ok;
char b[4][4];
bool check[4][4];
vector<string> a;
map<string, int> c;
vector<pair<int, int>> p = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
void Try(int i1, int i2, string x)
{
    if (c[x] > 0)
    {
        cout << x << " ";
        ok = 1;
    }
    for (int i = 0; i < 8; i++)
    {
        int p1 = i1 + p[i].first;
        int p2 = i2 + p[i].second;
        if (p1 < n && p1 >= 0 && p2 < m && p2 >= 0 && !check[p1][p2])
        {
            check[p1][p2] = 1;
            Try(p1, p2, x + b[p1][p2]);
            check[p1][p2] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s = "";
        ok = 0;
        c.clear();
        cin >> k >> n >> m;
        a.resize(k);
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
            c[a[i]]++;
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> b[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                check[i][j] = 1;
                Try(i, j, s + b[i][j]);
                check[i][j] = 0;
            }
        if (ok == 0)
            cout << -1;
        cout << endl;
    }
}
 

// File: DSA02015 - LOẠI BỎ DẤU NGOẶC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int k;
string s;
map<string, int> m;
bool check(string a)
{
    if (a.size() < 2)
        return 0;
    stack<int> st;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '(')
            st.push(1);
        else if (a[i] == ')')
        {
            if (st.empty())
                return 0;
            else
                st.pop();
        }
    }
    if (st.empty())
        return 1;
    return 0;
}
void Try(string a, int pos)
{
    if (check(a))
    {
        if (a.size() > k)
        {
            k = a.size();
            m.clear();
            m[a]++;
        }
        else if (a.size() == k)
            m[a]++;
        return;
    }
    for (int i = pos + 1; i < a.size(); i++)
    {
        if (a[i] == '(' || a[i] == ')')
        {
            string x = a;
            x.erase(x.begin() + i, x.begin() + i + 1);
            Try(x, i - 1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        k = 0;
        m.clear();
        cin >> s;
        Try(s, -1);
        if (m.empty())
            cout << -1;
        else
        {
            for (auto i : m)
                cout << i.first << " ";
        }
        cout << endl;
    }
}
 

// File: DSA02016 - SẮP XẾP QUÂN HẬU 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, ans, c1[50], c2[50], c3[50];
void Try(int x)
{
    if (x == n + 1)
    {
        ans++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (c1[i] == 0 && c2[i + x] == 0 && c3[x - i + n] == 0)
        {
            c1[i] = c2[i + x] = c3[x - i + n] = 1;
            Try(x + 1);
            c1[i] = c2[i + x] = c3[x - i + n] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans = 0;
        for (int i = 0; i < 20; i++)
            c1[i] = c2[i] = c3[i] = 0;
        cin >> n;
        Try(1);
        cout << ans << endl;
    }
}
 

// File: DSA02017 - SẮP XẾP QUÂN HẬU 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n = 8, ans;
int c1[20], c2[20], c3[20], a[10][10];
void Try(int x, int s)
{
    if (x == n + 1)
    {
        ans = max(ans, s);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (c1[i] == 0 && c2[i + x] == 0 && c3[x - i + n] == 0)
        {
            c1[i] = c2[i + x] = c3[x - i + n] = 1;
            Try(x + 1, s + a[x][i]);
            c1[i] = c2[i + x] = c3[x - i + n] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans = 0;
        for (int i = 0; i < 20; i++)
            c1[i] = c2[i] = c3[i] = 0;
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
                cin >> a[i][j];
        }
        Try(1, 0);
        cout << ans << endl;
    }
}
 

// File: DSA02018 - BIỂU THỨC TOÁN HỌC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string ans = "NO";
        int a[10], b[10], c[10];
        for (int i = 1; i <= 5; i++)
        {
            cin >> a[i];
            b[i] = i;
        }
        do
        {
            c[1] = c[2] = c[3] = c[4] = 1;
            while (1)
            {
                int ok = 0;
                int x = a[b[1]];
                for (int i = 1; i <= 4; i++)
                {
                    if (c[i] == 1)
                        x = x + a[b[i + 1]];
                    else if (c[i] == 2)
                        x = x - a[b[i + 1]];
                    else
                        x = x * a[b[i + 1]];
                }
                if (x == 23)
                {
                    ans = "YES";
                    break;
                }
                for (int i = 4; i >= 1; i--)
                {
                    if (c[i] != 3)
                    {
                        ok = 1;
                        c[i]++;
                        for (int j = i + 1; j <= 4; j++)
                            c[j] = 1;
                        break;
                    }
                }
                if (ok == 0)
                    break;
            }
        } while (next_permutation(b + 1, b + 6));
        cout << ans << endl;
    }
}
 

// File: DSA02019 - ĐƯỜNG ĐI DÀI NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, x, y, ans;
bool check[20][20];
vector<vector<int>> a(20);
void Try(int pos, int k)
{
    ans = max(ans, k);
    for (auto i : a[pos])
    {
        if (!check[i][pos])
        {
            check[i][pos] = check[pos][i] = 1;
            Try(i, k + 1);
            check[i][pos] = check[pos][i] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n >> m;
        for (int i = 0; i < 20; i++)
            a[i].clear();
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 0; i < n; i++)
            Try(i, 0);
        cout << ans << endl;
    }
}
 

// File: DSA02020 - SỐ NHỎ NHẤT CÓ N ƯỚC SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef unsigned long long ll;
const ll INF = 1e19 + 1;
int main()
{
    ll f[15][1111];
    vector<ll> p[15];
    ll a[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    for (int i = 1; i <= 11; i = i + 1)
    {
        p[i].push_back(1);
        p[i].push_back(a[i]);
        while (p[i][p[i].size() - 1] > p[i][p[i].size() - 2])
        {
            int k = p[i].size() - 1;
            p[i].push_back(p[i][k] * a[i]);
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i = i + 1)
        {
            if (i - 1 >= p[1].size() - 1)
                f[1][i] = INF;
            else
                f[1][i] = p[1][i - 1];
        }
        for (int i = 2; i <= 11; i = i + 1)
            for (int j = 1; j <= n; j = j + 1)
            {
                f[i][j] = INF;
                for (int k = 1; k <= j; k = k + 1)
                    if (j % k == 0)
                        if ((k - 1 < p[i].size() - 1) && (f[i - 1][j / k] < INF))
                            if ((f[i - 1][j / k] * p[i][k - 1]) % f[i - 1][j / k] == 0)
                                if (f[i][j] > f[i - 1][j / k] * p[i][k - 1])
                                    f[i][j] = f[i - 1][j / k] * p[i][k - 1];
            }
        cout << f[11][n] << endl;
    }
}
 

// File: DSA02021 - KÝ TỰ ĐẶC BIỆT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, x, a[62], pos = 61;
        string s;
        cin >> s >> k;
        n = s.size();
        s = ' ' + s;
        a[1] = n;
        for (int i = 2; i <= 61; i++)
        {
            if (a[i - 1] * 2 >= 2e18)
            {
                pos = i - 1;
                break;
            }
            else
                a[i] = a[i - 1] * 2;
        }
        while (k > n)
        {
            if (a[pos] < k)
            {
                long long x = k - a[pos];
                if (x == 1)
                    k = a[pos - 1];
                else
                    k = x - 1;
            }
            pos--;
        }
        cout << s[k] << endl;
    }
}
 

// File: DSA02022 - NGÀY ĐẶC BIỆT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<string> a1 = {"02", "20", "22"};
    vector<string> a2 = {"02"};
    vector<string> a3 = {"2000", "2002", "2020", "2022", "2200", "2202", "2220", "2222"};
    for (int i = 0; i < a1.size(); i++)
        for (int j = 0; j < a2.size(); j++)
            for (int k = 0; k < a3.size(); k++)
                cout << a1[i] + "/" + a2[j] + "/" + a3[k] << endl;
}
 

// File: DSA02022 - NGƯỜI DU LỊCH.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[20], b[20] = {};
long long s = 1e15, c[20][20], S = 0;
void Try(int x)
{
    for (int i = 2; i <= n; i++)
    {
        if (b[i] == 0)
        {
            a[x] = i;
            b[i] = 1;
            S += c[a[x - 1]][i];
            if (x == n && S + c[i][1] < s)
                s = S + c[i][1];
            else if (S < s && x < n)
                Try(x + 1);
            S -= c[a[x - 1]][i];
            b[i] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    a[1] = 1;
    b[1] = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
        }
    }
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    Try(2);
    cout << s;
}
 

// File: DSA02023 - ĐẶT TÊN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string x;
    vector<string> a;
    map<string, int> m;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        m[x]++;
    }
    for (auto i : m)
        a.push_back(i.first);
    n = a.size();
    a.insert(a.begin(), 1, "");
    int dd[k + 1];
    for (int i = 1; i <= k; i++)
        dd[i] = i;
    while (1)
    {
        for (int i = 1; i <= k; i++)
            cout << a[dd[i]] << " ";
        cout << endl;
        int ok = 0;
        for (int i = k; i >= 1; i--)
        {
            if (dd[i] != n - k + i)
            {
                ok = 1;
                dd[i]++;
                for (int j = i + 1; j <= k; j++)
                    dd[j] = dd[j - 1] + 1;
                break;
            }
        }
        if (ok == 0)
            return 0;
    }
}
 

// File: DSA02024 - DÃY CON TĂNG DẦN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[25];
string k;
vector<int> x;
vector<string> v;
vector<vector<int>> ans;
void Try(int posa)
{
    for (int i = posa + 1; i <= n; i++)
    {
        if (a[i] > a[posa])
        {
            x.push_back(a[i]);
            if (x.size() > 1)
                ans.push_back(x);
            Try(i);
            x.erase(x.end() - 1, x.end());
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Try(0);
    for (int i = 0; i < ans.size(); i++)
    {
        k = "";
        for (int j = 0; j < ans[i].size(); j++)
        {
            k += to_string(ans[i][j]);
            k += " ";
        }
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}
 

// File: DSA02025 - KÝ TỰ LẶP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, s = 1e9, S = 0;
int a[100], b[100] = {};
vector<string> c(20);
int kt(string a, string b)
{
    int i = 0, j = 0, e = a.size(), f = b.size(), ss = 0;
    while (i < e && j < f)
    {
        if (a[i] == b[j])
        {
            ss++;
            i++;
            j++;
        }
        while (a[i] < b[j])
        {
            i++;
            if (i == e)
                break;
        }
        while (a[i] > b[j])
        {
            j++;
            if (j == f)
                break;
        }
    }
    return ss;
}
void Try(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == 0)
        {
            a[x] = i;
            b[i] = 1;
            int k = kt(c[a[x - 1]], c[i]);
            S += k;
            if (x == n && S < s)
                s = S;
            else if (x < n && S < s)
                Try(x + 1);
            b[i] = 0;
            S -= k;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    c[0] = "";
    Try(1);
    cout << s;
}
 

// File: DSA02027 - NGƯỜI DU LỊCH.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[20], b[20] = {};
long long s = 1e15, c[20][20], S = 0;
void Try(int x)
{
    for (int i = 2; i <= n; i++)
    {
        if (b[i] == 0)
        {
            a[x] = i;
            b[i] = 1;
            S += c[a[x - 1]][i];
            if (x == n && S + c[i][1] < s)
                s = S + c[i][1];
            else if (S < s && x < n)
                Try(x + 1);
            S -= c[a[x - 1]][i];
            b[i] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    a[1] = 1;
    b[1] = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
        }
    }
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    Try(2);
    cout << s;
}
 

// File: DSA02028 - CHIA ĐỀU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, k, d;
int a[15];
int solve(int u, int t)
{
    if (t > k)
        return 0;
    if (u == n + 1)
    {
        if (t == k)
            return 1;
        return 0;
    }
    int sum = 0, ans = 0;
    for (int i = u; i <= n; i++)
    {
        sum += a[i];
        if (sum == d)
            ans += solve(i + 1, t + 1);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        d += a[i];
    if (d % k != 0)
        cout << 0;
    else
    {
        d /= k;
        cout << solve(1, 0);
    }
}
 

// File: DSA02029 - THÁP HÀ NỘI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void Tower(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << a << " -> " << c << endl;
        return;
    }
    Tower(n - 1, a, c, b);
    Tower(1, a, b, c);
    Tower(n - 1, b, a, c);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char a = 'A', b = 'B', c = 'C';
    int n;
    cin >> n;
    Tower(n, a, b, c);
}
 

// File: DSA02030 - LIỆT KÊ XÂU KÝ TỰ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char c;
    int n, k;
    cin >> c >> k;
    n = c - 'A' + 1;
    int a[k + 1];
    for (int i = 1; i <= k; i++)
        a[i] = 1;
    while (1)
    {
        for (int i = 1; i <= k; i++)
            cout << (char)('A' + a[i] - 1);
        cout << endl;
        int ok = 0;
        for (int i = k; i >= 1; i--)
        {
            if (a[i] != n)
            {
                ok = 1;
                a[i]++;
                for (int j = i + 1; j <= k; j++)
                    a[j] = a[i];
                break;
            }
        }
        if (ok == 0)
            break;
    }
}
 

// File: DSA02031 - GHÉP CHỮ CÁI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[100];
bool check()
{
    for (int i = 2; i <= n - 1; i++)
        if ((a[i] == 1 || a[i] == 5) && 
        (a[i - 1] != 1 && a[i - 1] != 5) && 
        (a[i + 1] != 1 && a[i + 1] != 5))
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char c;
    cin >> c;
    n = c - 'A' + 1;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    while (1)
    {
        if (check())
        {
            for (int i = 1; i <= n; i++)
                cout << (char)(a[i] + 'A' - 1);
            cout << endl;
        }
        int ok = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a + i + 1, a + n + 1);
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > a[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (ok == 0)
            break;
    }
}
 

// File: DSA02032 - TỔ HỢP SỐ CÓ TỔNG BẰNG X.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    vector<int> b;
};
int n, k, a[25], c[105];
vector<struct data> d;
void Try(int x, int i, int s)
{
    for (int ii = i; ii <= n; ii++)
    {
        s += a[ii];
        c[x] = a[ii];
        if (s == k)
        {
            struct data e;
            for (int jj = 1; jj <= x; jj++)
                e.b.push_back(c[jj]);
            d.push_back(e);
        }
        else if (s < k)
            Try(x + 1, ii, s);
        s -= a[ii];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        d.clear();
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        Try(1, 1, 0);
        if (d.size() == 0)
        {
            cout << "-1" << endl;
            continue;
        }
        cout << d.size() << " ";
        for (int i = 0; i < d.size(); i++)
        {
            cout << "{" << d[i].b[0];
            for (int j = 1; j < d[i].b.size(); j++)
            {
                if (d[i].b[j] == 0)
                    break;
                cout << " " << d[i].b[j];
            }
            cout << "} ";
        }
        cout << endl;
    }
}
 

// File: DSA02033 - SỐ XA CÁCH.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, check[15];
void Try(string s)
{
    int k = s.size();
    if (k == n)
        cout << s << endl;
    for (int i = 1; i <= n; i++)
        if (k == 0 || (!check[i] && abs(s[k - 1] - '0' - i) != 1))
        {
            check[i] = 1;
            Try(s + to_string(i));
            check[i] = 0;
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        Try("");
    }
}
 

// File: DSA02034 - TRÒ CHƠI VỚI CÁC CON SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, check[15];
void Try(string s)
{
    int k = s.size();
    if (k == n)
        cout << s << endl;
    for (int i = 1; i <= n; i++)
        if (k == 0 || (!check[i] && abs(s[k - 1] - '0' - i) != 1))
        {
            check[i] = 1;
            Try(s + to_string(i));
            check[i] = 0;
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        Try("");
    }
}
 

// File: DSA02035 - HOÁN VỊ CÁC CHỮ SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int to_int(string s)
{
    int a = 0;
    for (int i = 0; i < s.size(); i++)
    {
        a = a * 10 + s[i] - '0';
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    int a[n + 1], MIN = 1e9;
    vector<string> b(m);
    vector<string> c;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        b[i] = "0" + b[i];
    }
    for (int i = 1; i <= n; i++)
        a[i] = i;
    while (1)
    {
        c.clear();
        for (int i = 0; i < m; i++)
        {
            string x = b[i];
            for (int j = 1; j <= n; j++)
                x[j] = b[i][a[j]];
            c.push_back(x);
        }
        sort(c.begin(), c.end());
        MIN = min(MIN, to_int(c[c.size() - 1]) - to_int(c[0]));
        int ok = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a + i + 1, a + n + 1);
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > a[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (ok == 0)
            break;
    }
    cout << MIN;
}
 

// File: DSA02036 - DÃY CON CÓ TỔNG LẺ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[20];
vector<int> x;
vector<vector<int>> ans;
map<vector<int>, int> m;
void Try(int k, int s)
{
    for (int i = k + 1; i <= n; i++)
    {
        Try(i, s);
        x.push_back(a[i]);
        if ((s + a[i]) % 2 == 1)
        {
            if (m[x] == 0)
            {
                m[x]++;
                ans.push_back(x);
            }
        }
        Try(i, s + a[i]);
        x.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        m.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        Try(0, 0);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
}
 

// File: DSA02037 - DÃY CON CÓ TỔNG NGUYÊN TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[20];
vector<int> x;
vector<vector<int>> ans;
map<vector<int>, int> m;
bool nto(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}
void Try(int k, int s)
{
    for (int i = k + 1; i <= n; i++)
    {
        Try(i, s);
        x.push_back(a[i]);
        if (nto(s + a[i]))
        {
            if (m[x] == 0)
            {
                m[x]++;
                ans.push_back(x);
            }
        }
        Try(i, s + a[i]);
        x.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        m.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        Try(0, 0);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
}
 

// File: DSA02038 - DÃY CON CÓ K PHẦN TỬ TĂNG DẦN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[k + 1], b[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= k; i++)
            a[i] = i;
        while (1)
        {
            for (int i = 1; i <= k; i++)
                cout << b[a[i]] << " ";
            cout << endl;
            int ok = 0;
            for (int i = k; i >= 1; i--)
            {
                if (a[i] != n - k + i)
                {
                    ok = 1;
                    a[i]++;
                    for (int j = i + 1; j <= k; j++)
                        a[j] = a[j - 1] + 1;
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        cout << endl;
    }
}
 

// File: DSA02039 - PHÂN TÍCH SỐ 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    int d[10];
};
bool cmp(struct data a, struct data b)
{
    for (int i = 0; i < 10; i++)
    {
        if (a.d[i] != b.d[i])
            return a.d[i] > b.d[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x = 0;
        cin >> n;
        struct data c[50];
        for (int i = 0; i < 50; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                c[i].d[j] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            int a[i];
            for (int j = 0; j < i; j++)
                a[j] = n - i + 1;
            while (1)
            {
                int s = 0, ok = 0;
                for (int j = 0; j < i; j++)
                    s += a[j];
                if (s == n)
                {
                    for (int j = 0; j < i; j++)
                        c[x].d[j] = a[j];
                    x++;
                }
                for (int j = i - 1; j >= 0; j--)
                {
                    if (a[j] != 1)
                    {
                        ok = 1;
                        a[j]--;
                        for (int jj = j + 1; jj < i; jj++)
                            a[jj] = a[j];
                        break;
                    }
                }
                if (ok == 0)
                    break;
            }
        }
        sort(c, c + x, cmp);
        cout << x << endl;
        for (int i = 0; i < x; i++)
        {
            cout << "(" << c[i].d[0];
            for (int j = 1; j < 10; j++)
            {
                if (c[i].d[j] == 0)
                    break;
                cout << " " << c[i].d[j];
            }
            cout << ") ";
        }
        cout << endl;
    }
}
 

// File: DSA02041 - BIẾN ĐỔI VỀ 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        pair<int, int> x, k;
        queue<pair<int, int>> q;
        x.first = n;
        x.second = 0;
        q.push(x);
        while (q.size())
        {
            x = q.front();
            q.pop();
            if (x.first == 1)
            {
                cout << x.second << endl;
                break;
            }
            k.second = x.second + 1;
            if (x.first % 2 == 0)
            {
                k.first = x.first / 2;
                q.push(k);
            }
            if (x.first % 3 == 0)
            {
                k.first = x.first / 3;
                q.push(k);
            }
            if (x.first > 1)
            {
                k.first = x.first - 1;
                q.push(k);
            }
        }
    }
}
 

// File: DSA02045 - TẬP CON CỦA XÂU KÝ TỰ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
string s;
vector<string> ans;
map<string, int> m;
void Try(int i, string x)
{
    if (x != "" && m[x] == 0)
    {
        ans.push_back(x);
        m[x]++;
    }
    if (i == n)
        return;
    Try(i + 1, x + s[i]);
    Try(i + 1, x);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        m.clear();
        cin >> n >> s;
        Try(0, "");
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}
 

// File: DSA03001 - ĐỔI TIỀN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	int a[100001] = {};
	int b[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
	for (int i = 1; i <= 100000; i++)
	{
		a[i] = 1e9;
		for (int j = 0; j < 10; j++)
		{
			if (i == b[j])
			{
				a[i] = 1;
				break;
			}
			if (i - b[j] > 0 && a[i - b[j]] > 0)
				a[i] = min(a[i], a[i - b[j]] + 1);
		}
	}
	while (t--)
	{
		int n;
		cin >> n;
		cout << a[n] << endl;
	}
}
 

// File: DSA03002 - NHẦM CHỮ SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int to_five(string s)
{
	int n = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '6')
			s[i] = '5';
		n = n * 10 + s[i] - '0';
	}
	return n;
}
int to_six(string s)
{
	int n = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '5')
			s[i] = '6';
		n = n * 10 + s[i] - '0';
	}
	return n;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	cout << to_five(a) + to_five(b) << " " << to_six(a) + to_six(b);
}
 

// File: DSA03003 - TÌM MAX.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long a[n], s = 0, mod = 1e9 + 7;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++)
			s = (s + a[i] * i) % mod;
		cout << s << endl;
	}
}
 

// File: DSA03004 - TỔNG NHỎ NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        long long s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for (int i = 0; i < n; i += 2)
            s1 = s1 * 10 + a[i];
        for (int i = 1; i < n; i += 2)
            s2 = s2 * 10 + a[i];
        cout << s1 + s2 << endl;
    }
}
 

// File: DSA03005 - CHIA MẢNG THÀNH HAI MẢNG CON CÓ TỔNG LỚN NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n], s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        k = min(k, n - k);
        for (int i = 0; i < k; i++)
            s1 += a[i];
        for (int i = k; i < n; i++)
            s2 += a[i];
        cout << s2 - s1 << endl;
    }
}
 

// File: DSA03006 - SẮP XẾP THAM LAM.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n], ok = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i] && a[i] != b[n - i - 1])
            {
                ok = 0;
                break;
            }
        }
        if (ok == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
 

// File: DSA03007 - GIÁ TRỊ NHỎ NHẤT CỦA BIỂU THỨC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool cmp(long long a, long long b)
{
	return a > b;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long s = 0;
		vector<long long> a(n), b(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end(), cmp);
		for (int i = 0; i < n; i++)
			s += a[i] * b[i];
		cout << s << endl;
	}
}
 

// File: DSA03008 - SẮP XẾP CÔNG VIỆC 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		pair<int, int> a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i].second;
		for (int i = 0; i < n; i++)
			cin >> a[i].first;
		sort(a, a + n);
		int ans = 1, k = a[0].first;
		for (int i = 1; i < n; i++)
		{
			if (a[i].second >= k)
			{
				ans++;
				k = a[i].first;
			}
		}
		cout << ans << endl;
	}
}
 

// File: DSA03009 - SẮP XẾP CÔNG VIỆC 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, d = 0, ans = 0;
        cin >> n;
        int check[n + 1] = {};
        vector<pair<int, int>> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> x >> a[i].second >> a[i].first;
        sort(a.begin() + 1, a.end(), greater<pair<int, int>>());
        for (int i = 1; i <= n; i++)
        {
            for (int j = min(n, a[i].second); j >= 1; j--)
            {
                if (!check[j])
                {
                    ans += a[i].first;
                    d++;
                    check[j] = 1;
                    break;
                }
            }
        }
        cout << d << " " << ans << endl;
    }
}
 

// File: DSA03010 - NỐI DÂY 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        long long s = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            q.push(x);
        }
        while (q.size() > 1)
        {
            int s1 = q.top();
            q.pop();
            int s2 = q.top();
            q.pop();
            int k = s1 + s2;
            s += k;
            q.push(k);
        }
        cout << s << endl;
    }
}
 

// File: DSA03011 - NỐI DÂY 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int x, s = 0, mod = 1e9 + 7;
		priority_queue<int, vector<int>, greater<int>> q;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			q.push(x);
		}
		while (q.size() > 1)
		{
			int s1 = q.top();
			q.pop();
			int s2 = q.top();
			q.pop();
			int k = (s1 + s2) % mod;
			s = (s + k) % mod;
			q.push(k);
		}
		cout << s << endl;
	}
}
 

// File: DSA03012 - SẮP ĐẶT XÂU KÝ TỰ 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int a[30] = {}, MAX = 0;
        for (int i = 0; i < s.size(); i++)
            a[s[i] - 'a']++;
        for (int i = 0; i < 30; i++)
            MAX = max(MAX, a[i]);
        if (MAX * 2 > s.size() + 1)
            cout << -1 << endl;
        else
            cout << 1 << endl;
    }
}
 

// File: DSA03013 - SẮP ĐẶT XÂU KÝ TỰ 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        string s;
        cin >> k >> s;
        int a[30] = {}, MAX = 0;
        for (int i = 0; i < s.size(); i++)
            a[s[i] - 'A']++;
        for (int i = 0; i < 30; i++)
            MAX = max(MAX, a[i]);
        if (MAX * k > s.size() + 1)
            cout << -1 << endl;
        else
            cout << 1 << endl;
    }
}
 

// File: DSA03014 - SỐ KHỐI LẬP PHƯƠNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool check(string s1, string s2)
{
    int k = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        int ok = 0;
        for (int j = k; j < s2.size(); j++)
        {
            if (s1[i] == s2[j])
            {
                ok = 1;
                k = j + 1;
                break;
            }
        }
        if (!ok)
            return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<string> f;
    for (long long i = 1; i <= 50; i++)
        f.push_back(to_string(i * i * i));
    while (t--)
    {
        string s, ans = "-1";
        cin >> s;
        for (int i = f.size() - 1; i >= 0; i--)
        {
            if ((f[i].size() < s.size() || f[i] < s) && check(f[i], s))
            {
                ans = f[i];
                break;
            }
        }
        cout << ans << endl;
    }
}
 

// File: DSA03015 - MUA LƯƠNG THỰC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, s, m;
        cin >> n >> s >> m;
        if (s * m > (s - s / 7) * n)
            cout << -1 << endl;
        else
        {
            for (int i = 1; i <= s - s / 7; i++)
            {
                if (n * i >= s * m)
                {
                    cout << i << '\n';
                    break;
                }
            }
        }
    }
}
 

// File: DSA03016 - SỐ NHỎ NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string a;
int s, n, d, ok;
void Try(int sn)
{
    if (ok)
        return;
    int n = a.size();
    if (n == d)
    {
        if (sn == s)
        {
            ok = 1;
            cout << a << endl;
        }
        return;
    }
    if (s - sn < 0 || s - sn > (d - n) * 9)
        return;
    for (int i = 0; i <= 9; i++)
    {
        a += to_string(i);
        Try(sn + i);
        a.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ok = 0;
        cin >> s >> d;
        for (int i = 1; i <= 9; i++)
        {
            if (!ok)
            {
                a = to_string(i);
                Try(i);
                a.pop_back();
            }
        }
        if (!ok)
            cout << -1 << endl;
    }
}
 

// File: DSA03017 - GIÁ TRỊ NHỎ NHẤT CỦA XÂU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int k, x, n = 0;
        string s;
        cin >> k >> s;
        map<char, int> m;
        priority_queue<int> q;
        for (int i = 0; i < s.size(); i++)
            m[s[i]]++;
        for (auto i : m)
            q.push(i.second);
        while (k--)
        {
            x = q.top();
            q.pop();
            q.push(x - 1);
        }
        while (q.size())
        {
            n += q.top() * q.top();
            q.pop();
        }
        cout << n << endl;
    }
}
 

// File: DSA03018 - SỐ MAY MẮN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, ok = 0;
        cin >> n;
        for (int i = 0; i <= n / 4; i++)
        {
            if ((n - i * 4) % 7 == 0)
            {
                ok = 1;
                for (int j = 0; j < i; j++)
                    cout << 4;
                for (int j = 0; j < (n - i * 4) / 7; j++)
                    cout << 7;
                cout << endl;
                break;
            }
        }
        if (ok == 0)
            cout << -1 << endl;
    }
}
 

// File: DSA03019 - PHÂN SỐ ĐƠN VỊ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, n, m, x;
        cin >> a >> b;
        while (b % a != 0)
        {
            n = a;
            m = b;
            x = b / a;
            cout << 1 << "/" << x + 1 << " + ";
            a = (x + 1) * n - m;
            b = (x + 1) * b;
        }
        cout << 1 << "/" << b / a;
        cout << '\n';
    }
}
 

// File: DSA03020 - BIỂU THỨC ĐÚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<char> st;
        int k = 0, ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.size() == 0)
                st.push(s[i]);
            else if (st.top() == '[' && s[i] == ']')
            {
                st.pop();
                k += 2;
            }
            else if (st.top() == ']' && s[i] == '[')
            {
                ans += st.size() + k;
                st.pop();
            }
            else if (s[i] == '[')
                st.push(s[i]);
            else if (st.top() == ']' && s[i] == ']')
                st.push(s[i]);
            if (st.size() == 0)
                k = 0;
        }
        cout << ans << endl;
    }
}
 

// File: DSA03021 - TÌM DÃY SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, ans = 0;
vector<int> a(1000), b(1000);
bool check(int pos)
{
    for (int i = 0; i < n; i++)
        if (a[i] / pos == a[i] / (pos + 1))
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    b = a;
    sort(b.begin(), b.begin() + n);
    for (int i = b[0]; i >= 0; i--)
    {
        if (check(i))
        {
            for (int j = 0; j < n; ++j)
                ans += a[j] / (i + 1) + 1;
            break;
        }
    }
    cout << ans;
}
 

// File: DSA03022 - TÍCH LỚN NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, ok = 0;
    cin >> n;
    long long x;
    vector<long long> a;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x)
            a.push_back(x);
        else
            ok = 1;
    }
    n = a.size();
    sort(a.begin(), a.end());
    long long ans = max(a[0] * a[1], max(a[0] * a[1] * a[n - 1], max(a[n - 1] * a[n - 2], a[n - 1] * a[n - 2] * a[n - 3])));
    if (ans > 0)
        cout << ans;
    else
        cout << 0;
}
 

// File: DSA03023 - SẮP XẾP VIÊN BI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, ok, ans = 0;
string s;
void Try(int l, int pos, char c)
{
    for (int i = l; i < n; i++)
    {
        if (s[i] == c)
        {
            ok = 1;
            swap(s[pos], s[i]);
            ans++;
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    int dx = 0, dt = 0, dd = 0;
    for (auto i : s)
    {
        if (i == 'X')
            dx++;
        else if (i == 'T')
            dt++;
        else
            dd++;
    }
    for (int i = 0; i < dx; ++i)
    {
        if (s[i] == 'T')
            Try(dx, i, 'X');
        else if (s[i] == 'D')
        {
            ok = 0;
            Try(dx + dt, i, 'X');
            if (ok == 0)
                Try(dx, i, 'X');
        }
    }
    for (int i = dx; i < dt + dx; i++)
        if (s[i] == 'D')
            Try(dx + dt, i, 'T');
    cout << ans;
}
 

// File: DSA03024 - LỰA CHỌN TỐI ƯU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0, k = 0;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i].first >> a[i].second;
        sort(a.begin(), a.end(), cmp);
        for (int i = 0; i < n; i++)
        {
            if (a[i].first >= k)
            {
                k = a[i].second;
                ans++;
            }
        }
        cout << ans << endl;
    }
}
 

// File: DSA03025 - TRỤC TỌA ĐỘ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0, k = 0;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i].first >> a[i].second;
        sort(a.begin(), a.end(), cmp);
        for (int i = 0; i < n; i++)
        {
            if (a[i].first >= k)
            {
                k = a[i].second;
                ans++;
            }
        }
        cout << ans << endl;
    }
}
 

// File: DSA03026 - LỰA CHỌN THAM LAM.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    if (n == 1 && s < 10)
        cout << s << " " << s;
    else if (s == 0 || s > n * 9)
        cout << "-1 -1";
    else
    {
        int k = s / 9;
        int d = s - k * 9;
        if (k == n)
        {
            for (int i = 0; i < n; i++)
                cout << 9;
            cout << " ";
            for (int i = 0; i < n; i++)
                cout << 9;
        }
        else if (d == 0)
        {
            cout << 1;
            for (int i = k + 1; i < n; i++)
                cout << 0;
            cout << 8;
            for (int i = 1; i < k; i++)
                cout << 9;
            cout << " ";
            for (int i = 0; i < k; i++)
                cout << 9;
            for (int i = k; i < n; i++)
                cout << 0;
        }
        else
        {
            if (k == n - 1)
            {
                cout << d;
                for (int i = k + 1; i < n; i++)
                    cout << 0;
                for (int i = 0; i < k; i++)
                    cout << 9;
            }
            else
            {
                cout << 1;
                for (int i = k + 2; i < n; i++)
                    cout << 0;
                cout << d - 1;
                for (int i = 0; i < k; i++)
                    cout << 9;
            }
            cout << " ";
            for (int i = 0; i < k; i++)
                cout << 9;
            cout << d;
            for (int i = k + 1; i < n; i++)
                cout << 0;
        }
    }
}
 

// File: DSA03027 - GIÁ TRỊ LỚN NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long x, s = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s += x + abs(x);
	}
	cout << s;
}
 

// File: DSA03034 - DÃY CON CHUNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        long long a1[n], a2[m], a3[k];
        for (int i = 0; i < n; i++)
            cin >> a1[i];
        for (int i = 0; i < m; i++)
            cin >> a2[i];
        for (int i = 0; i < k; i++)
            cin >> a3[i];
        int i = 0, j = 0, h = 0;
        vector<long long> a;
        while (i < n && j < m && h < k)
        {
            if (a1[i] == a2[j] && a2[j] == a3[h])
            {
                a.push_back(a1[i]);
                i++;
                j++;
                h++;
            }
            else if (a1[i] < a2[j])
                i++;
            else if (a2[j] < a3[h])
                j++;
            else
                h++;
        }
        if (a.size() == 0)
            cout << "NO" << endl;
        else
        {
            for (int i = 0; i < a.size(); i++)
                cout << a[i] << " ";
            cout << endl;
        }
    }
}
 

// File: DSA03035 - SẮP XẾP ĐƠN GIẢN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s = 0;
    cin >> n;
    vector<int> a(n + 5), f(n + 5, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        f[a[i]] = f[a[i] - 1] + 1;
        s = max(s, f[a[i]]);
    }
    cout << n - s;
}
 

// File: DSA04001 - LŨY THỪA.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
long long mod = 1e9 + 7;
long long poww(long long n, long long k)
{
    if (k == 1)
        return n;
    long long x = poww(n, k / 2);
    if (k % 2 == 0)
        return (x * x) % mod;
    else
        return (((x * x) % mod) * n) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        cout << poww(n, k) << endl;
    }
}
 

// File: DSA04002 - LŨY THỪA ĐẢO.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
long long mod = 1e9 + 7;
long long poww(long long n, long long k)
{
    if (k == 0)
        return 1;
    long long x = poww(n, k / 2);
    if (k % 2 == 0)
        return (x * x) % mod;
    else
        return (((x * x) % mod) * n) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, k;
        cin >> n;
        m = n;
        k = 0;
        while (m != 0)
        {
            k = k * 10 + m % 10;
            m /= 10;
        }
        cout << poww(n, k) << endl;
    }
}
 

// File: DSA04003 - ĐẾM DÃY.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
long long mod = 123456789;
long long poww(long long n, long long k)
{
    if (k == 1)
        return n;
    long long x = poww(n, k / 2);
    if (k % 2 == 0)
        return (x * x) % mod;
    else
        return (((x * x) % mod) * n) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << poww(2, n - 1) << endl;
    }
}
 

// File: DSA04004 - GẤP ĐÔI DÃY SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long a[n + 1];
        for (long long i = 1; i <= n; i++)
        {
            a[i] = pow(2, i - 1);
        }
        for (int i = n; i >= 1; i--)
        {
            if (k == a[i])
            {
                cout << i << endl;
                break;
            }
            else if (k > a[i])
                k -= a[i];
        }
    }
}
 

// File: DSA04005 - DÃY XÂU FIBONACI.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long a[n + 1];
        a[1] = 1;
        a[2] = 1;
        for (int i = 3; i <= n; i++)
            a[i] = a[i - 1] + a[i - 2];
        while (1)
        {
            if (n == 1)
            {
                cout << "A\n";
                break;
            }
            else if (n == 2)
            {
                cout << "B\n";
                break;
            }
            if (k > a[n - 2])
            {
                k -= a[n - 2];
                n--;
            }
            else
                n -= 2;
        }
    }
}
 

// File: DSA04006 - ĐẾM SỐ BÍT 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
long long Find(long long pos, long long n, long long ctr)
{
	if (pos & 1)
		return 1;
	if (pos == ctr)
		return (n % 2);
	if (pos > ctr)
		return Find(pos - ctr, n / 2, ctr / 2);
	return Find(pos, n / 2, ctr / 2);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		long long n, l, r;
		cin >> n >> l >> r;
		long long ctr = pow(2, (long long)log2(n)), ans = 0;
		for (long long i = l; i <= r; i++)
			ans += Find(i, n, ctr);
		cout << ans << "\n";
	}
}
 

// File: DSA04007 - HỆ CƠ SỐ K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x, ok = 0;
        string s1, s2, s = "";
        cin >> k >> s1 >> s2;
        while (s1.size() < s2.size())
            s1 = '0' + s1;
        while (s2.size() < s1.size())
            s2 = '0' + s2;
        n = s1.size();
        for (int i = n - 1; i >= 0; i--)
        {
            x = s1[i] + s2[i] - 2 * '0';
            if (ok == 1)
            {
                x++;
                ok = 0;
            }
            if (x > k - 1)
            {
                ok = 1;
                x -= k;
            }
            if (x >= 10)
                s = (char)('A' + x - 10) + s;
            else
                s = to_string(x) + s;
        }
        if (ok == 1)
            s = '1' + s;
        cout << s << endl;
    }
}
 

// File: DSA04008 - SỐ FIBONACCI THỨ N.cpp
#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7, F[2][2], M[2][2];
void Mul(long long f[2][2], long long m[2][2])
{
    long long x = (f[0][0] * m[0][0] % mod + f[0][1] * m[1][0] % mod) % mod;
    long long y = (f[0][0] * m[0][1] % mod + f[0][1] * m[1][1] % mod) % mod;
    long long z = (f[1][0] * m[0][0] % mod + f[1][1] * m[1][0] % mod) % mod;
    long long t = (f[1][0] * m[0][1] % mod + f[1][1] * m[1][1] % mod) % mod;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = t;
}
void Pow(long long f[2][2], long long n)
{
    if (n <= 1)
        return;
    Pow(f, n / 2);
    Mul(f, f);
    if (n & 1)
        Mul(f, M);
}
long long fibo(long long n)
{
    F[0][0] = F[0][1] = F[1][0] = 1;
    F[1][1] = 0;
    M[0][0] = M[0][1] = M[1][0] = 1;
    M[1][1] = 0;
    Pow(F, n - 1);
    return F[0][0];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << fibo(n) << endl;
    }
}
 

// File: DSA04009 - LŨY THỪA MA TRẬN 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
	long long x[10][10];
};
int n;
long long mod = 1000000007;
struct data operator*(struct data a, struct data b)
{
	struct data xx;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			xx.x[i][j] = 0;
			for (int k = 0; k < n; k++)
				xx.x[i][j] = (xx.x[i][j] + (a.x[i][k] * b.x[k][j]) % mod) % mod;
		}
	}
	return xx;
};
struct data poww(struct data a, long long k)
{
	if (k == 1)
		return a;
	if (k % 2 == 1)
		return a * poww(a, k - 1);
	struct data xx = poww(a, k / 2);
	return xx * xx;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		long long k;
		cin >> n >> k;
		struct data a;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a.x[i][j];
		a = poww(a, k);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << a.x[i][j] << " ";
			cout << endl;
		}
	}
}
 

// File: DSA04010 - DÃY CON LIÊN TIẾP CÓ TỔNG LỚN NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x, ans = 0, s = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            s += x;
            ans = max(ans, s);
            if (s < 0)
                s = 0;
        }
        cout << ans << endl;
    }
}
 

// File: DSA04011 - TÍCH HAI SỐ NHỊ PHÂN.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        long long s1 = 0, s2 = 0;
        long long n1 = a.size(), n2 = b.size();
        for (long long i = n1 - 1; i >= 0; i--)
            s1 += (a[i] - '0') * pow(2, n1 - i - 1);
        for (long long i = n2 - 1; i >= 0; i--)
            s2 += (b[i] - '0') * pow(2, n2 - i - 1);
        cout << s1 * s2 << endl;
    }
}
 

// File: DSA04012 - TÍCH ĐA THỨC.cpp
#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int a[n + 1], b[m + 1], c[m + n + 1] = {};
        for (int i = n; i >= 1; i--)
            scanf("%d", &a[i]);
        for (int i = m; i >= 1; i--)
            scanf("%d", &b[i]);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                c[i + j] += a[i] * b[j];
            }
        }
        for (int i = m + n; i >= 2; i--)
            printf("%d ", c[i]);
        printf("\n");
    }
}
 

// File: DSA04013 - SẮP XẾP KANGURU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        int ans = n, l = n / 2 - 1, r = n - 1;
        while (l >= 0 && r >= n / 2)
        {
            if (2 * a[l] <= a[r])
            {
                l--;
                r--;
                ans--;
            }
            else
                l--;
        }
        cout << ans << endl;
    }
}
 

// File: DSA04014 - CẶP NGHỊCH THẾ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
long long Merge(long long *a, long long l, long long r, long long mid)
{
    long long p1 = mid - l + 1, p2 = r - mid, ans = 0;
    long long L[p1], R[p2];
    for (int i = 0; i < p1; i++)
        L[i] = a[l + i];
    for (int i = 0; i < p2; i++)
        R[i] = a[mid + i + 1];
    int i = 0, j = 0, k = l;
    while (i < p1 and j < p2)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
        {
            a[k++] = R[j++];
            ans += p1 - i;
        }
    }
    while (i < p1)
        a[k++] = L[i++];
    while (j < p2)
        a[k++] = R[j++];
    return ans;
}
long long calc(long long *a, int l, int r)
{
    long long ans = 0;
    int mid;
    if (l < r)
    {
        mid = (l + r) >> 1;
        ans += calc(a, l, mid);
        ans += calc(a, mid + 1, r);
        ans += Merge(a, l, r, mid);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << calc(a, 0, n - 1) << endl;
    }
}
 

// File: DSA04015 - TÍNH FLOOR(X).cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n + 2);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        a[n + 1] = 1e18;
        int ans = lower_bound(a.begin(), a.end() - 1, k) - a.begin();
        if (a[ans] != k)
            ans--;
        if (ans != -1)
            ans++;
        cout << ans << endl;
    }
}
 

// File: DSA04016 - PHẦN TỬ THỨ K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int a[n], b[m], p1 = 0, p2 = 0, ans;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        while (k--)
        {
            if (p1 == n - 1)
                ans = b[p2++];
            if (p2 == m - 1)
                ans = a[p1++];
            if (a[p1] < b[p2])
            {
                ans = a[p1];
                p1++;
            }
            else
            {
                ans = b[p2];
                p2++;
            }
        }
        cout << ans << endl;
    }
}
 

// File: DSA04017 - PHẦN TỬ KHÁC NHAU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n - 1; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }
}
 

// File: DSA04018 - ĐẾM SỐ 0.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int m = lower_bound(a, a + n, 1) - a;
        cout << m << endl;
    }
}
 

// File: DSA04019 - CẶP ĐIỂM GẦN NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
double distance(pair<double, double> a, pair<double, double> b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        double ans = 1e9;
        vector<pair<double, double>> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
            b[i].second = a[i].first;
            b[i].first = a[i].second;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i = 1; i < n; i++)
        {
            ans = min(ans, distance(a[i], a[i - 1]));
            ans = min(ans, distance(b[i], b[i - 1]));
        }
        cout << setprecision(6) << fixed << ans << endl;
    }
}
 

// File: DSA04020 - TÌM KIẾM NHỊ PHÂN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int m = lower_bound(a, a + n, k) - a;
        if (a[m] != k)
            cout << "NO" << endl;
        else
            cout << m + 1 << endl;
    }
}
 

// File: DSA04021 - DÃY XÂU NHỊ PHÂN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long a[n + 1];
        a[1] = 1;
        a[2] = 1;
        for (int i = 3; i <= n; i++)
            a[i] = a[i - 1] + a[i - 2];
        while (1)
        {
            if (n == 1)
            {
                cout << "0\n";
                break;
            }
            else if (n == 2)
            {
                cout << "1\n";
                break;
            }
            if (k > a[n - 2])
            {
                k -= a[n - 2];
                n--;
            }
            else
                n -= 2;
        }
    }
}
 

// File: DSA04022 - KÝ TỰ THỨ K TRONG XÂU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long a[n + 1];
        for (long long i = 1; i <= n; i++)
            a[i] = pow(2, i - 1);
        for (int i = n; i >= 1; i--)
        {
            if (k == a[i])
            {
                cout << (char)(i + 'A' - 1) << endl;
                break;
            }
            else if (k > a[i])
                k -= a[i];
        }
    }
}
 

// File: DSA04023 - KHOẢNG CÁCH NHỎ HƠN K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		long long s = 0;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			int x = lower_bound(a + i + 1, a + n, a[i] + k) - a;
			s += x - i - 1;
		}
		cout << s << endl;
	}
}
 

// File: DSA04024 - LŨY THỪA MA TRẬN 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
	long long x[10][10];
};
int n;
long long mod = 1000000007;
struct data operator*(struct data a, struct data b)
{
	struct data xx;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			xx.x[i][j] = 0;
			for (int k = 0; k < n; k++)
				xx.x[i][j] = (xx.x[i][j] + (a.x[i][k] * b.x[k][j]) % mod) % mod;
		}
	}
	return xx;
};
struct data poww(struct data a, long long k)
{
	if (k == 1)
		return a;
	if (k % 2 == 1)
		return a * poww(a, k - 1);
	struct data xx = poww(a, k / 2);
	return xx * xx;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		long long k, s = 0;
		cin >> n >> k;
		struct data a;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a.x[i][j];
		a = poww(a, k);
		for (int i = 0; i < n; i++)
			s = (s + a.x[i][n - 1]) % mod;
		cout << s << endl;
	}
}
 

// File: DSA04025 - DÃY SỐ VÔ HẠN.cpp
#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7, F[2][2], M[2][2];
void Mul(long long f[2][2], long long m[2][2])
{
    long long x = (f[0][0] * m[0][0] % mod + f[0][1] * m[1][0] % mod) % mod;
    long long y = (f[0][0] * m[0][1] % mod + f[0][1] * m[1][1] % mod) % mod;
    long long z = (f[1][0] * m[0][0] % mod + f[1][1] * m[1][0] % mod) % mod;
    long long t = (f[1][0] * m[0][1] % mod + f[1][1] * m[1][1] % mod) % mod;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = t;
}
void Pow(long long f[2][2], long long n)
{
    if (n <= 1)
        return;
    Pow(f, n / 2);
    Mul(f, f);
    if (n & 1)
        Mul(f, M);
}
long long fibo(long long n)
{
    F[0][0] = F[0][1] = F[1][0] = 1;
    F[1][1] = 0;
    M[0][0] = M[0][1] = M[1][0] = 1;
    M[1][1] = 0;
    Pow(F, n - 1);
    return F[0][0];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << fibo(n) << endl;
    }
}
 

// File: DSA04030 - SỐ TRIBONACCI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct matrix
{
	long long a[5][5] = {};
};

long long n = 4, MOD = 1e15 + 7;

long long nhan(long long x, long long y)
{
	if (y == 1)
		return x % MOD;
	if (y == 0)
		return 0;
	long long tmp = nhan(x, y / 2) % MOD;
	if (y % 2 == 0)
		return (2 * tmp) % MOD;
	return ((2 * tmp) % MOD + x % MOD) % MOD;
}

matrix mulMatrix(matrix A, matrix B)
{
	matrix tmp;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			long long sum = 0;
			for (int k = 1; k <= n; k++)
				sum = (sum % MOD + nhan(A.a[i][k], B.a[k][j]) % MOD) % MOD;
			tmp.a[i][j] = sum;
		}
	}
	return tmp;
}

matrix operator^(matrix A, long long k)
{
	if (k == 1)
		return A;
	matrix tmp = A ^ (k / 2);
	matrix c = mulMatrix(tmp, tmp);
	if (k % 2 == 0)
		return c;
	return mulMatrix(c, A);
}

matrix createI()
{
	matrix res;
	for (int i = 1; i <= n; i++)
		res.a[i][i] = 1;
	return res;
}

matrix operator+(matrix A, matrix B)
{
	matrix c;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			c.a[i][j] = (A.a[i][j] + B.a[i][j]) % MOD;
	return c;
}

matrix sumPowMatrix(matrix A, long long k)
{
	if (k == 1)
		return A;
	long long h = k / 2;
	matrix c = mulMatrix((createI() + (A ^ h)), sumPowMatrix(A, h));
	if (k % 2 == 1)
		c = c + (A ^ k);
	return c;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		long long k, ans = 0;
		matrix A;
		cin >> k;
		if (k <= 3)
		{
			cout << k * (k + 1) / 2 << endl;
			continue;
		}
		A.a[1][1] = 1; A.a[1][2] = 1; A.a[1][3] = 0; A.a[1][4] = 0;
		A.a[2][1] = 0; A.a[2][2] = 1; A.a[2][3] = 1; A.a[2][4] = 1;
		A.a[3][1] = 0; A.a[3][2] = 1; A.a[3][3] = 0; A.a[3][4] = 0;
		A.a[4][1] = 0; A.a[4][2] = 0; A.a[4][3] = 1; A.a[4][4] = 0;
		matrix B = A ^ (k - 2);
		for (int i = 2; i <= n; i++)
		{
			ans += nhan(B.a[1][i], (5 - i));
			ans %= MOD;
		}
		ans += nhan(B.a[1][1], 3);
		ans %= MOD;
		cout << ans << endl;
	}
}
 

// File: DSA04035 - TÍNH LŨY THỪA.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
long long mod = 1e9 + 7;
long long poww(long long n, long long k)
{
    if (k == 1)
        return n;
    long long x = poww(n, k / 2);
    if (k % 2 == 0)
        return (x * x) % mod;
    else
        return (((x * x) % mod) * n) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (1)
    {
        long long n, k;
        cin >> n >> k;
        if (n == 0 && k == 0)
            return 0;
        if (k == 0)
            cout << 1 << endl;
        else
            cout << poww(n, k) << endl;
    }
}
 

// File: DSA05001 - XÂU CON CHUNG DÀI NHẤT.cpp
#include <bits/stdc++.h>
using namespace std;
int LCS(string s1, string s2)
{
    int F[s1.size() + 1][s2.size() + 1] = {};
    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            if (s1[i] == s2[j])
                F[i + 1][j + 1] = F[i][j] + 1;
            else
                F[i + 1][j + 1] = max(F[i][j + 1], F[i + 1][j]);
        }
    }
    return F[s1.size()][s2.size()];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        cout << LCS(a, b) << endl;
    }
}
 

// File: DSA05003 - DÃY CON CHUNG DÀI NHẤT CỦA BA XÂU.cpp
#include <bits/stdc++.h>
using namespace std;
int LCS(string s1, string s2, string s3)
{
    int F[s1.size() + 1][s2.size() + 1][s3.size() + 1] = {};
    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            for (int k = 0; k < s3.size(); k++)
            {
                if (s1[i] == s2[j] && s2[j] == s3[k])
                    F[i + 1][j + 1][k + 1] = F[i][j][k] + 1;
                else
                    F[i + 1][j + 1][k + 1] = max(F[i][j + 1][k + 1], max(F[i + 1][j + 1][k], F[i + 1][j][k + 1]));
            }
        }
    }
    return F[s1.size()][s2.size()][s3.size()];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        string a, b, c;
        cin >> n >> m >> k >> a >> b >> c;
        cout << LCS(a, b, c) << endl;
    }
}
 

// File: DSA05004 - DÃY CON TĂNG DÀI NHẤT.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n], l[n], ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        l[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && l[i] <= l[j])
                l[i] = l[j] + 1;
        }
        ans = max(ans, l[i]);
    }
    cout << ans;
}
 

// File: DSA05005 - SỐ BƯỚC ÍT NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, s = 0;
        cin >> n;
        int a[n], l[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            l[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (a[i] >= a[j] && l[i] <= l[j])
                    l[i] = l[j] + 1;
            }
            s = max(s, l[i]);
        }
        cout << n - s << endl;
    }
}
 

// File: DSA05006 - TỔNG LỚN NHẤT CỦA DÃY CON TĂNG DẦN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], l[n], ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            l[i] = a[i];
            for (int j = 0; j < i; j++)
                if (a[i] > a[j])
                    l[i] = max(l[i], l[j] + a[i]);
            ans = max(ans, l[i]);
        }
        cout << ans << endl;
    }
}
 

// File: DSA05007 - TỔNG LỚN NHẤT CỦA DÃY CON KHÔNG KỀ NHAU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 2];
        a[0] = a[1] = 0;
        for (int i = 2; i <= n + 1; i++)
        {
            cin >> a[i];
            a[i] = max(a[i] + a[i - 2], a[i - 1]);
        }
        cout << max(a[n], a[n + 1]) << endl;
    }
}
 

// File: DSA05008 - DÃY CON CÓ TỔNG BẰNG S.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n + 5], l[k + 5] = {};
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        l[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = k; j >= a[i]; j--)
            {
                if (l[j] == 0 && l[j - a[i]] == 1)
                    l[j] = 1;
            }
        }
        if (l[k] == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA05009 - TẬP CON BẰNG NHAU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, s;
int a[105];
string ans;
void Try(int pos, int k)
{
    if (ans == "YES")
        return;
    if (2 * k == s)
    {
        ans = "YES";
        return;
    }
    if (pos < n)
    {
        if (2 * (k + a[pos]) <= s)
            Try(pos + 1, k + a[pos]);
        Try(pos + 1, k);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        s = 0;
        ans = "NO";
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        if (s % 2 == 0)
            Try(0, 0);
        cout << ans << endl;
    }
}
 

// File: DSA05010 - DÃY CON DÀI NHẤT CÓ TỔNG CHIA HẾT CHO K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n + 1);
        vector<vector<long long>> f(n + 1, vector<long long>(k, 0));
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] %= k;
        }
        for (int i = 1; i < k; i++)
            f[1][i] = -1e18;
        f[1][a[1]] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                f[i][j] = max(f[i - 1][j], f[i - 1][(j - a[i] + k) % k] + 1);
            }
        }
        cout << f[n][0] << endl;
    }
}
 

// File: DSA05011 - SỐ CÓ TỔNG CHỮ SỐ BẰNG K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long f[105][50005] = {}, mod = 1e9 + 7;
    for (int i = 1; i <= 9; i++)
        f[1][i] = 1;
    for (int i = 2; i <= 100; i++)
    {
        for (int j = 5000; j >= 0; j--)
        {
            for (int k = 0; k <= 9; k++)
            {
                if (j >= k)
                {
                    f[i][j] += f[i - 1][j - k];
                    f[i][j] %= mod;
                }
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << f[n][k] << endl;
    }
}
 

// File: DSA05012 - TỔ HỢP C(n, k).cpp
#include <stdio.h>
int a[1001][1001], mod = 1e9 + 7;
int main()
{
    a[0][0] = 1;
    for (int i = 1; i < 1001; i++)
    {
        a[i][0] = 1;
        for (int j = 1; j < 1001; j++)
            a[i][j] = (a[i - 1][j - 1] % mod + a[i - 1][j] % mod) % mod;
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        printf("%d\n", a[n][k]);
    }
}
 

// File: DSA05013 - BẬC THANG.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, mod = 1e9 + 7;
        cin >> n >> k;
        long long a[n] = {}, b[n];
        for (int i = 0; i < min(n, k); i++)
            a[i] = 1;
        b[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (i <= k)
                a[i] = (a[i] + b[i - 1]) % mod;
            else
            {
                long long m = (b[i - 1] - b[i - k - 1]) % mod;
                if (m < 0)
                    m += mod;
                a[i] = (a[i] + m) % mod;
            }
            b[i] = (b[i - 1] + a[i]) % mod;
        }
        cout << a[n - 1] << endl;
    }
}
 

// File: DSA05014 - CATALAN NUMBER.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, s[200], a[200], len;
void add(int x, int delta)
{
    for (int i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            s[i] += delta;
            x /= i;
        }
    }
    if (x != 1)
        s[x] += delta;
}
void mul(int x)
{
    len += 5;
    for (int i = 0; i < len; i++)
        a[i] *= x;
    for (int i = 0; i < len; i++)
    {
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    while (len > 0 && !a[len - 1])
        len--;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= n; i++)
            add(2 * n - i + 1, 1);
        for (int i = 1; i <= n + 1; i++)
            add(i, -1);
        a[0] = len = 1;
        for (int i = 1; i < 200; i++)
        {
            while (s[i]--)
                mul(i);
        }
        for (int i = len - 1; i >= 0; i--)
            cout << a[i];
        cout << endl;
    }
}
 

// File: DSA05015 - TÍNH P(N,K).cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long P[1001][1001] = {}, mod = 1e9 + 7;
	for (int i = 1; i <= 1000; i++)
		P[i][1] = i;
	for (int i = 2; i <= 1000; i++)
		for (int j = 2; j <= i; j++)
			P[i][j] = (P[i - 1][j - 1] * i) % mod;
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		cout << P[n][k] << endl;
	}
}
 

// File: DSA05016 - SỐ UGLY.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<long long> s;
    vector<long long> v;
    s.insert(1);
    while (1)
    {
        for (auto i : s)
        {
            if (i > 1e18)
                break;
            v.push_back(i * 2);
            v.push_back(i * 3);
            v.push_back(i * 5);
        }
        for (auto i : v)
            s.insert(i);
        v.clear();
        if (s.size() > 1e4)
            break;
    }
    for (auto i : s)
        v.push_back(i);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << v[n - 1] << endl;
    }
}
 

// File: DSA05017 - DÃY SỐ BI-TONIC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], l[n], r[n], ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            l[i] = a[i];
            for (int j = 0; j < i; j++)
                if (a[i] > a[j])
                    l[i] = max(l[i], l[j] + a[i]);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            r[i] = a[i];
            for (int j = i + 1; j < n; j++)
                if (a[i] > a[j])
                    r[i] = max(r[i], r[j] + a[i]);
            ans = max(ans, l[i] + r[i] - a[i]);
        }
        cout << ans << endl;
    }
}
 

// File: DSA05018 - XÂU CON ĐỐI XỨNG DÀI NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int n = s.size(), ans = 1;
		vector<vector<bool>> a(n, vector<bool>(n));
		for (int i = 0; i < n; i++)
			a[i][i] = 1;
		for (int i = 1; i < n; i++)
			for (int j = 0; j < n - i; j++)
			{
				int k = i + j;
				a[j][k] = ((j + 1 > k - 1 || a[j + 1][k - 1]) && s[j] == s[k]);
				if (a[j][k])
					ans = i + 1;
			}
		cout << ans << endl;
	}
}
 

// File: DSA05019 - HÌNH VUÔNG LỚN NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, s = 0;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                if (a[j][i] == 1)
                    a[j][i] = a[j - 1][i] + 1;
        for (int i = 0; i < n; i++)
        {
            stack<int> b, c;
            int l[m], r[m];
            for (int j = 0; j < m; j++)
            {
                while (!b.empty() && a[i][j] <= a[i][b.top()])
                    b.pop();
                if (b.empty())
                    l[j] = 0;
                else
                    l[j] = b.top() + 1;
                b.push(j);
            }
            for (int j = m - 1; j >= 0; j--)
            {
                while (!c.empty() && a[i][j] <= a[i][c.top()])
                    c.pop();
                if (c.empty())
                    r[j] = m - 1;
                else
                    r[j] = c.top() - 1;
                c.push(j);
            }
            for (int j = 0; j < m; j++)
                s = max(s, min(r[j] - l[j] + 1, a[i][j]));
        }
        cout << s << endl;
    }
}
 

// File: DSA05020 - ĐƯỜNG ĐI NHỎ NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n + 1][m + 1], b[n + 1][m + 1] = {};
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i == 1)
                    b[i][j] = b[i][j - 1];
                else if (j == 1)
                    b[i][j] = b[i - 1][j];
                else
                    b[i][j] = min(b[i - 1][j - 1], min(b[i - 1][j], b[i][j - 1]));
                b[i][j] += a[i][j];
            }
        }
        cout << b[n][m] << endl;
    }
}
 

// File: DSA05021 - CẶP SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int l[n], maz = 0;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i].first >> a[i].second;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            l[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (a[i].first > a[j].second && l[i] <= l[j])
                    l[i] = l[j] + 1;
            }
            maz = max(maz, l[i]);
        }
        cout << maz << endl;
    }
}
 

// File: DSA05022 - KÝ TỰ GIỐNG NHAU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y, z;
        cin >> n >> x >> y >> z;
        int a[n + 2];
        a[1] = x;
        a[2] = a[1] + min(x, z);
        for (int i = 3; i <= n + 1; i++)
        {
            a[i] = a[i - 1] + x;
            if (i % 2 == 0)
                a[i] = min(a[i], a[i / 2] + z);
            a[i - 1] = min(a[i - 1], a[i] + y);
        }
        cout << a[n] << endl;
    }
}
 

// File: DSA05023 - TỔNG CÁC XÂU CON.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        long long ans = 0, k = 1, n = a.size(), s;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            s = (long long)(a[i] - '0') * k;
            s *= n;
            ans += s;
            k = k * 10 + 1;
            n--;
        }
        cout << ans << endl;
    }
}
 

// File: DSA05024 - TỔNG BẰNG K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        long long f[k + 1] = {}, mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        f[0] = 1;
        for (int i = 1; i <= k; i++)
            for (int j = 0; j < n; j++)
                if (i >= a[j])
                    f[i] = (f[i] + f[i - a[j]]) % mod;
        cout << f[k] << endl;
    }
}
 

// File: DSA05025 - CON ẾCH.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long a[n] = {}, b[n];
		for (int i = 0; i < min(n, 3); i++)
			a[i] = 1;
		b[0] = 1;
		for (int i = 1; i < n; i++)
		{
			if (i <= 3)
				a[i] = (a[i] + b[i - 1]);
			else
				a[i] += b[i - 1] - b[i - 4];
			b[i] = b[i - 1] + a[i];
		}
		cout << a[n - 1] << endl;
	}
}
 

// File: DSA05026 - XEM PHIM.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int s, n;
	cin >> s >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector<vector<int>> l(n + 1, vector<int>(s + 1, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= s; j++)
			if (a[i] <= j)
				l[i][j] = max(l[i - 1][j - a[i]] + a[i], l[i - 1][j]);
			else
				l[i][j] = l[i - 1][j];
	cout << l[n][s];
}
 

// File: DSA05027 - CÁI TÚI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int a[n], b[n];
		vector<vector<int>> l(n, vector<int>(m + 1, 0));
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		for (int i = 0; i < n; i++)
			for (int j = 1; j <= m; j++)
			{
				if (i > 0)
				{
					if (a[i] <= j)
						l[i][j] = max(l[i - 1][j], l[i - 1][j - a[i]] + b[i]);
					else
						l[i][j] = l[i - 1][j];
				}
				else if (a[i] <= j)
					l[i][j] = b[i];
			}
		cout << l[n - 1][m] << endl;
	}
}
 

// File: DSA05028 - BIẾN ĐỔI XÂU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string s1, s2;
int dp()
{
    int m = s1.size(), n = s2.size();
    int f[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                f[i][j] = j;
            else if (j == 0)
                f[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                f[i][j] = f[i - 1][j - 1];
            else
                f[i][j] = 1 + min(f[i][j - 1], min(f[i - 1][j], f[i - 1][j - 1]));
        }
    }
    return f[m][n];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s1 >> s2;
        cout << dp() << endl;
    }
}
 

// File: DSA05029 - GIẢI MÃ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		s = ' ' + s;
		int n = s.size(), k;
		int a[n];
		a[0] = a[1] = 1;
		if (s[1] == '0')
		{
			cout << 0 << endl;
			continue;
		}
		for (int i = 2; i < n; i++)
		{
			if (s[i] == '0')
			{
				if (s[i - 1] > '2')
				{
					a[n - 1] = 0;
					break;
				}
				a[i] = 0;
			}
			else
				a[i] = a[i - 1];
			k = (s[i - 1] - '0') * 10 + s[i] - '0';
			if (k <= 26 && k >= 10)
				a[i] += a[i - 2];
		}
		cout << a[n - 1] << endl;
	}
}
 

// File: DSA05030 - DI CHUYỂN VỀ GỐC TỌA ĐỘ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<long long>> a(n + 1, vector<long long>(m + 1, 1));
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--)
                a[i][j] = a[i + 1][j] + a[i][j + 1];
        cout << a[0][0] << endl;
    }
}
 

// File: DSA05031 - TỔNG BÌNH PHƯƠNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        a[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            a[i] = 1e9;
            for (int j = 1; j <= sqrt(i); j++)
                if (a[i - j * j] != 1e9)
                    a[i] = min(a[i], a[i - j * j] + 1);
        }
        cout << a[n] << endl;
    }
}
 

// File: DSA05032 - XÂU ĐỐI XỨNG 1.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int f[n][n];
        for (int i = 0; i < n; i++)
            f[i][i] = 1;
        for (int k = 2; k <= n; k++)
        {
            for (int i = 0; i < n - k + 1; i++)
            {
                int j = i + k - 1;
                if (s[i] == s[j] && k == 2)
                    f[i][j] = 2;
                else if (s[i] == s[j])
                    f[i][j] = f[i + 1][j - 1] + 2;
                else
                    f[i][j] = max(f[i + 1][j], f[i][j - 1]);
            }
        }
        cout << n - f[0][n - 1] << endl;
    }
}

// File: DSA05033 - XÂU ĐỐI XỨNG 2.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int f[n][n];
        for (int i = 0; i < n; i++)
            f[i][i] = 1;
        for (int k = 2; k <= n; k++)
        {
            for (int i = 0; i < n - k + 1; i++)
            {
                int j = i + k - 1;
                if (s[i] == s[j] && k == 2)
                    f[i][j] = 2;
                else if (s[i] == s[j])
                    f[i][j] = f[i + 1][j - 1] + 2;
                else
                    f[i][j] = max(f[i + 1][j], f[i][j - 1]);
            }
        }
        cout << n - f[0][n - 1] << endl;
    }
}

// File: DSA05034 - TỔNG SỐ CÁCH DI CHUYỂN.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, mod = 1e9 + 7;
        cin >> n >> k;
        long long a[n] = {}, b[n];
        for (int i = 0; i < min(n, k); i++)
            a[i] = 1;
        b[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (i <= k)
                a[i] = (a[i] + b[i - 1]) % mod;
            else
            {
                long long m = (b[i - 1] - b[i - k - 1]) % mod;
                if (m < 0)
                    m += mod;
                a[i] = (a[i] + m) % mod;
            }
            b[i] = (b[i - 1] + a[i]) % mod;
        }
        cout << a[n - 1] << endl;
    }
}
 

// File: DSA05035 - CHỮ SỐ SẮP XẾP TĂNG DẦN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a[11], f[101] = {}, mod = 1e9 + 7;
    for (int i = 1; i <= 10; i++)
        a[i] = 1;
    f[1] = 10;
    for (int i = 2; i <= 100; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            long long s = 0;
            for (int k = j; k <= 9; k++)
                s += a[k];
            a[j] = s;
            f[i] = (f[i] + s) % mod;
        }
    }
    for (int i = 2; i <= 100; i++)
        f[i] = (f[i] + f[i - 1]) % mod;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
}
 

// File: DSA05036 - TĂNG - GIẢM.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int f[n], ans = 0;
        pair<float, float> a[n];
        for (int i = 0; i < n; i++)
        {
            f[i] = 1;
            cin >> a[i].first >> a[i].second;
            for (int j = 0; j < i; j++)
                if (a[i].first > a[j].first && a[i].second < a[j].second && f[i] <= f[j])
                    f[i] = f[j] + 1;
            ans = max(ans, f[i]);
        }
        cout << ans << endl;
    }
}
 

// File: DSA05037 - CHỮ SỐ SẮP XẾP TĂNG DẦN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a[11], f[101] = {}, mod = 1e9 + 7;
    for (int i = 1; i <= 10; i++)
        a[i] = 1;
    f[1] = 10;
    for (int i = 2; i <= 100; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            long long s = 0;
            for (int k = j; k <= 9; k++)
                s += a[k];
            a[j] = s;
            f[i] = (f[i] + s) % mod;
        }
    }
    for (int i = 2; i <= 100; i++)
        f[i] = (f[i] + f[i - 1]) % mod;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
}
 

// File: DSA05038 - DÃY CON TĂNG DÀI NHẤT 2 CHIỀU.cpp
#include <bits/stdc++.h>
using namespace std;
int n, ans;
pair<int, int> a;
set<pair<int, int>> s[100000];
bool check(const pair<int, int> a, const pair<int, int> b)
{
    return ((a.first < b.first) && (a.second < b.second));
}
bool kt(set<pair<int, int>> &st)
{
    for (set<pair<int, int>>::iterator i = st.begin(); i != st.end(); i++)
    {
        if (check(*i, a))
            return 1;
        else if (i->first >= a.first)
            break;
    }
    return 0;
}
int binary_search(int l, int r)
{
    while (l < r)
    {
        int m = (l + r) / 2;
        if (kt(s[m]))
            l = m + 1;
        else
            r = m;
    }
    return l;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a.first >> a.second;
        int pos = binary_search(0, n);
        if (pos < n)
        {
            set<pair<int, int>>::iterator k = ++s[pos].insert(a).first;
            while (k != s[pos].end())
            {
                if (check(a, *k))
                    s[pos].erase(k++);
                else
                    k++;
            }
        }
    }
    while (ans < n && s[ans].size())
        ans++;
    cout << ans;
}

// File: DSA05040 - DÃY TAM GIÁC DÀI NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, s = 0;
		cin >> n;
		int a[n + 1], maxa[n + 1], mina[n + 1];
		maxa[n] = mina[n] = n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = n - 1; i >= 1; i--)
		{
			if (a[i] > a[i + 1])
				mina[i] = mina[i + 1];
			else
				mina[i] = i;
			if (a[i] < a[i + 1])
				maxa[i] = maxa[i + 1];
			else
				maxa[i] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			s = max(s, mina[maxa[i]] - i + 1);
		}
		cout << s << endl;
	}
}
 

// File: DSA05041 - BIẾN ĐỔI VỀ XÂU ĐỐI XỨNG.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int f[n][n];
        for (int i = 0; i < n; i++)
            f[i][i] = 1;
        for (int k = 2; k <= n; k++)
        {
            for (int i = 0; i < n - k + 1; i++)
            {
                int j = i + k - 1;
                if (s[i] == s[j] && k == 2)
                    f[i][j] = 2;
                else if (s[i] == s[j])
                    f[i][j] = f[i + 1][j - 1] + 2;
                else
                    f[i][j] = max(f[i + 1][j], f[i][j - 1]);
            }
        }
        cout << n - f[0][n - 1] << endl;
    }
}

// File: DSA05042 - DÃY CON LIÊN TIẾP TỔNG BẰNG K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r, x, ok = 0;
        long long k;
        cin >> n >> k;
        long long a[n + 1];
        a[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        for (int i = 1; i <= n; i++)
        {
            l = i;
            r = n;
            while (l <= r)
            {
                x = (l + r) / 2;
                if (a[x] - a[i - 1] == k)
                {
                    ok = 1;
                    break;
                }
                else if (a[x] - a[i - 1] > k)
                {
                    r = x - 1;
                }
                else
                    l = x + 1;
            }
            if (ok)
                break;
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA05043 - SỐ THUẬN NGHỊCH.cpp
#include <bits/stdc++.h>
using namespace std;
bool a[1001][1001];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size(), ans = 1;
        for (int i = 0; i < n; i++)
            a[i][i] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                int k = i + j;
                if (i + j < n)
                {
                    a[j][k] = ((j + 1 > k - 1 || a[j + 1][k - 1]) && s[j] == s[k]);
                    if (a[j][k])
                        ans = i + 1;
                }
            }
        }
        cout << ans << endl;
    }
}

// File: DSA05047 - CHỌN Ô.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = -1e9, s = -1e9;
        cin >> n;
        int a[4][n + 1], f[n + 1][11] = {}, d[] = {0, 1, 2, 4, 5, 8, 9, 10};
        for (int i = 0; i < 4; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                for (int i = 0; i < 4; i++)
                    if (d[k] & (1 << i))
                        f[j][d[k]] += a[i][j];
                int x = -1e9;
                for (int i = 0; i < 8; i++)
                    if ((d[k] | d[i]) == (d[k] ^ d[i]))
                        x = max(x, f[j - 1][d[i]]);
                f[j][d[k]] += x;
            }
        }
        for (int i = 0; i < 8; i++)
            s = max(f[n][d[i]], s);
        for (int i = 0; i < 4; i++)
            for (int j = 1; j <= n; j++)
                ans = max(ans, a[i][j]);
        if (ans < 0)
            cout << ans << endl;
        else
            cout << s << endl;
    }
}

// File: DSA06001 - SẮP XẾP XEN KẼ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for (int i = 1; i < n; i += 2)
        {
            b[i] = a[(i - 1) / 2];
        }
        for (int i = 0; i < n; i += 2)
        {
            b[i] = a[n - i / 2 - 1];
        }
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";
        cout << endl;
    }
}
 

// File: DSA06002 - SẮP XẾP THEO GIÁ TRỊ TUYỆT ĐỐI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            v[i].first = abs(a[i] - k);
            v[i].second = i;
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
            cout << a[v[i].second] << " ";
        cout << endl;
    }
}
 

// File: DSA06003 - ĐỔI CHỖ ÍT NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k, ans = 0;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n - 1; i++)
		{
			k = i;
			for (int j = i + 1; j < n; j++)
				if (a[j] < a[k])
					k = j;
			if (k != i)
				ans++;
			swap(a[k], a[i]);
		}
		cout << ans << endl;
	}
}
 

// File: DSA06004 - HỢP VÀ GIAO CỦA HAI DÃY SỐ 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m;
        map<int, int> a, b, c;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            a[x]++;
            c[x]++;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            b[x]++;
            c[x]++;
        }
        for (auto i : c)
            cout << i.first << " ";
        cout << endl;
        for (auto i : a)
        {
            if (b[i.first] > 0)
                cout << i.first << " ";
        }
        cout << endl;
    }
}
 

// File: DSA06005 - HỢP VÀ GIAO CỦA HAI DÃY SỐ 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m;
        map<int, int> a, b, c;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            a[x]++;
            c[x]++;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            b[x]++;
            c[x]++;
        }
        for (auto i : c)
            cout << i.first << " ";
        cout << endl;
        for (auto i : a)
        {
            if (b[i.first] > 0)
                cout << i.first << " ";
        }
        cout << endl;
    }
}
 

// File: DSA06006 - SẮP XẾP [0 1 2].cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, a[3] = {};
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            a[x]++;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < a[i]; j++)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}
 

// File: DSA06007 - SẮP XẾP DÃY CON LIÊN TỤC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n + 1], b[n + 1], s = 0, l, r, ma = 0, mi = 1e9;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (a[i] > s)
				s = a[i];
			b[i] = s;
		}
		for (int i = 1; i <= n - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				l = i;
				break;
			}
		}
		for (int i = n; i >= 2; i--)
		{
			if (a[i] < a[i - 1])
			{
				r = i;
				break;
			}
		}
		for (int i = l; i <= r; i++)
		{
			if (a[i] > ma)
				ma = a[i];
			if (a[i] < mi)
				mi = a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			if (a[i] > mi)
			{
				cout << i << " ";
				break;
			}
		}
		for (int i = n; i >= 1; i--)
		{
			if (a[i] <= ma)
			{
				cout << i << endl;
				break;
			}
		}
	}
}
 

// File: DSA06008 - ĐẾM CẶP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int count(int x, int y[], int n, int a[])
{
	if (x == 0)
		return 0;
	if (x == 1)
		return a[0];
	int it = upper_bound(y, y + n, x) - y;
	int ans = n - it;
	ans += (a[0] + a[1]);
	if (x == 2)
		ans -= (a[3] + a[4]);
	if (x == 3)
		ans += a[2];
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int x[n], y[m], a[5] = {}, s = 0;
		for (int i = 0; i < n; i++)
			cin >> x[i];
		for (int i = 0; i < m; i++)
			cin >> y[i];
		for (int i = 0; i < n; i++)
		{
			if (y[i] < 5)
				a[y[i]]++;
		}
		sort(y, y + n);
		for (int i = 0; i < m; i++)
			s += count(x[i], y, n, a);
		cout << s << endl;
	}
}
 

// File: DSA06009 - CẶP SỐ TỔNG BẰNG K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k, x, s = 0;
		cin >> n >> k;
		int a[n];
		map<int, int> m;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			m[x]++;
		}
		for (auto i : m)
		{
			if (i.first * 2 == k)
				s += i.second * (i.second - 1);
			else
				s += i.second * m[k - i.first];
		}
		s /= 2;
		cout << s << endl;
	}
}
 

// File: DSA06010 - SẮP XẾP CHỮ SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, x, a[10] = {};
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			while (x != 0)
			{
				int k = x % 10;
				a[k]++;
				x /= 10;
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (a[i] > 0)
				cout << i << " ";
		}
		cout << endl;
	}
}
 

// File: DSA06011 - TỔNG GẦN 0 NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, s = 1e7;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (abs(a[i] + a[j]) < abs(s))
					s = a[i] + a[j];
			}
		}
		cout << s << endl;
	}
}
 

// File: DSA06012 - PHẦN TỬ LỚN NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		for (int i = n - 1; i >= n - k; i--)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}
}
 

// File: DSA06013 - SỐ LẦN XUẤT HIỆN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k, s = 0;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] == k)
				s++;
		}
		if (s == 0)
			cout << -1 << endl;
		else
			cout << s << endl;
	}
}
 

// File: DSA06014 - TỔNG CẶP SỐ NGUYÊN TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool nto(int n)
{
	if (n < 2)
		return 0;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, ok = 0;
		cin >> n;
		for (int i = 2; i <= n / 2; i++)
		{
			if (nto(i) == 1 && nto(n - i) == 1)
			{
				ok = 1;
				cout << i << " " << n - i << endl;
				break;
			}
		}
		if (ok == 0)
			cout << -1 << endl;
	}
}
 

// File: DSA06015 - MERGE SORT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
}
 

// File: DSA06016 - TÍCH LỚN NHẤT - NHỎ NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, x, maxa = -1e9, minb = 1e9;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			maxa = max(maxa, x);
		}
		for (int i = 0; i < m; i++)
		{
			cin >> x;
			minb = min(minb, x);
		}
		cout << (long long)maxa * minb << endl;
	}
}
 

// File: DSA06017 - TRỘN HAI DÃY.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> a(n + m);
		for (int i = 0; i < n + m; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		for (int i = 0; i < n + m; i++)
			cout << a[i] << " ";
		cout << endl;
	}
}
 

// File: DSA06018 - BỔ SUNG PHẦN TỬ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, s = 0;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 1; i < n; i++)
			if (a[i] != a[i - 1])
				s += a[i] - a[i - 1] - 1;
		cout << s << endl;
	}
}
 

// File: DSA06019 - SẮP XẾP THEO SỐ LẦN XUẤT HIỆN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second > b.second)
		return 1;
	if (a.second == b.second && a.first < b.first)
		return 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		map<int, int> ts;
		vector<pair<int, int>> p;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			ts[a[i]]++;
		}
		for (int i = 0; i < n; i++)
			p.push_back(make_pair(a[i], ts[a[i]]));
		sort(p.begin(), p.end(), cmp);
		for (int i = 0; i < p.size(); i++)
			cout << p[i].first << ' ';
		cout << endl;
	}
}
 

// File: DSA06020 - TÌM KIẾM.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, x, k, ans = -1;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (x == k)
				ans = 1;
		}
		cout << ans << endl;
	}
}
 

// File: DSA06021 - TÌM KIẾM TRONG DÃY SẮP XẾP VÒNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k, x, pos;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (x == k)
				pos = i;
		}
		cout << pos + 1 << endl;
	}
}
 

// File: DSA06022 - SỐ NHỎ NHẤT VÀ NHỎ THỨ HAI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, min1 = 1e9, min2 = 1e9;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			min1 = min(min1, a[i]);
		}
		for (int i = 0; i < n; i++)
		{
			if (a[i] < min2 && a[i] > min1)
				min2 = a[i];
		}
		if (min2 == 1e9)
			cout << -1 << endl;
		else
			cout << min1 << " " << min2 << endl;
	}
}
 

// File: DSA06023 - SẮP XẾP ĐỔI CHỖ TRỰC TIẾP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
		cout << "Buoc " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cout << a[j] << " ";
		cout << endl;
	}
}
 

// File: DSA06024 - SẮP XẾP CHỌN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[k])
				k = j;
		swap(a[k], a[i]);
		cout << "Buoc " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cout << a[j] << " ";
		cout << endl;
	}
}
 

// File: DSA06025 - SẮP XẾP CHÈN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		int k = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > k)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = k;
		cout << "Buoc " << i << ": ";
		for (j = 0; j <= i; j++)
			cout << a[j] << " ";
		cout << endl;
	}
}
 

// File: DSA06026 - SẮP XẾP NỔI BỌT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, b = 1;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++)
	{
		bool k = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				k = true;
			}
		}
		if (k == false)
			break;
		cout << "Buoc " << b++ << ": ";
		for (int j = 0; j < n; j++)
			cout << a[j] << " ";
		cout << endl;
	}
}
 

// File: DSA06027 - SẮP XẾP ĐỔI CHỖ TRỰC TIẾP - LIỆT KÊ NGƯỢC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int b = n - 1;
		vector<int> a(n);
		stack<vector<int>> st;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[i] > a[j])
					swap(a[i], a[j]);
			}
			st.push(a);
		}
		while (st.size())
		{
			a = st.top();
			st.pop();
			cout << "Buoc " << b-- << ": ";
			for (int j = 0; j < n; j++)
				cout << a[j] << " ";
			cout << endl;
		}
	}
}
 

// File: DSA06028 - SẮP XẾP CHỌN - LIỆT KÊ NGƯỢC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int b = n - 1;
	vector<int> a(n);
	stack<vector<int>> st;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[k])
				k = j;
		swap(a[k], a[i]);
		st.push(a);
	}
	while (st.size())
	{
		a = st.top();
		st.pop();
		cout << "Buoc " << b-- << ": ";
		for (int j = 0; j < n; j++)
			cout << a[j] << " ";
		cout << endl;
	}
}
 

// File: DSA06029 - SẮP XẾP CHÈN - LIỆT KÊ NGƯỢC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int b = n - 1;
	vector<int> a(n);
	stack<vector<int>> st;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		int k = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > k)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = k;
		st.push(a);
	}
	while (st.size())
	{
		a = st.top();
		st.pop();
		cout << "Buoc " << b-- << ": ";
		for (int j = 0; j <= b + 1; j++)
			cout << a[j] << " ";
		cout << endl;
	}
}
 

// File: DSA06030 - SẮP XẾP NỔI BỌT - LIỆT KÊ NGƯỢC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, b;
		cin >> n;
		vector<int> a(n);
		stack<vector<int>> st;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n - 1; i++)
		{
			bool k = false;
			for (int j = 0; j < n - i - 1; j++)
			{
				if (a[j] > a[j + 1])
				{
					swap(a[j], a[j + 1]);
					k = true;
				}
			}
			if (k == false)
				break;
			st.push(a);
		}
		b = st.size();
		while (st.size())
		{
			a = st.top();
			st.pop();
			cout << "Buoc " << b-- << ": ";
			for (int j = 0; j < n; j++)
				cout << a[j] << " ";
			cout << endl;
		}
	}
}
 

// File: DSA06031 - PHẦN TỬ LỚN NHẤT TRONG DÃY CON.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[n];
		deque<int> st;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; ++i)
		{
			while (st.size() && a[st.back()] <= a[i])
				st.pop_back();
			st.push_back(i);
			if (st.front() + k <= i)
				st.pop_front();
			if (i >= k - 1)
				cout << a[st.front()] << " ";
		}
		cout << endl;
	}
}
 

// File: DSA06032 - BỘ BA SỐ CÓ TỔNG NHỎ HƠN K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		long long s = 0;
		cin >> n >> k;
		long long a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				int x = lower_bound(a + j + 1, a + n, k - a[i] - a[j]) - a;
				s += x - j - 1;
			}
		}
		cout << s << endl;
	}
}
 

// File: DSA06033 - KHOẢNG CÁCH XA NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
	{
		return a.second > b.second;
	}
	return a.first < b.first;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		pair<int, int> a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].first;
			a[i].second = i;
		}
		sort(a, a + n);
		int ans = -1, Min = a[0].second, k = a[0].first;
		for (int i = 1; i < n; i++)
		{
			if (a[i].first > k)
				ans = max(ans, a[i].second - Min);
			if (Min > a[i].second)
			{
				Min = a[i].second;
				k = a[i].first;
			}
		}
		cout << ans << endl;
	}
}
 

// File: DSA06034 - CẶP SỐ CÓ TỔNG BẰNG K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[n];
		long long s = 0;
		map<int, long long> m;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			m[a[i]]++;
		}
		for (auto i : m)
		{
			if (i.first * 2 == k)
				s += i.second * (i.second - 1);
			else
				s += i.second * m[k - i.first];
		}
		cout << s / 2 << endl;
	}
}
 

// File: DSA06035 - DÃY TAM GIÁC DÀI NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, s = 0;
		cin >> n;
		int a[n + 1], maxa[n + 1], mina[n + 1];
		maxa[n] = mina[n] = n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = n - 1; i >= 1; i--)
		{
			if (a[i] > a[i + 1])
				mina[i] = mina[i + 1];
			else
				mina[i] = i;
			if (a[i] < a[i + 1])
				maxa[i] = maxa[i + 1];
			else
				maxa[i] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			s = max(s, mina[maxa[i]] - i + 1);
		}
		cout << s << endl;
	}
}
 

// File: DSA06036 - BỘ BA SỐ BẰNG K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[n];
		string ans = "NO";
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (binary_search(a + j + 1, a + n, k - a[i] - a[j]))
				{
					ans = "YES";
					break;
				}
			}
			if (ans == "YES")
				break;
		}
		cout << ans << endl;
	}
}
 

// File: DSA06037 - SẮP XẾP ĐOẠN CON.cpp
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct dt
{
    int first;
    int second;
    int third;
};
bool cmp1(dt a, dt b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
bool cmp2(dt a, dt b)
{
    return a.second < b.second;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m = 0;
        cin >> n;
        vector<dt> a(n);
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end(), cmp1);
        for (int i = 0; i < n; i++)
            a[i].third = i + 1;
        sort(a.begin(), a.end(), cmp2);
        for (int i = 0; i < n - 1; i++)
        {
            m = max(m, a[i].third);
            if (i + 1 == m)
                ans.push_back(i + 1);
        }
        cout << ans.size() << endl;
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
}
 

// File: DSA06038 - CẶP SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int bit[1000001];
void update(int i)
{
    for (; i < 1000001; i += i & -i)
        bit[i]++;
}
int get(int i)
{
    int s = 0;
    for (; i; i -= i & -i)
        s += bit[i];
    return s;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    int a[n + 1];
    stack<int> st;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i > 0; i--)
    {
        if (a[i] % 2 == 0)
        {
            ans += get(a[i] - 1);
            st.push(a[i]);
        }
        else
        {
            while (!st.empty())
            {
                update(st.top());
                st.pop();
            }
        }
    }
    cout << ans;
}
 

// File: DSA06039 - SỐ ĐẦU TIÊN BỊ LẶP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n + 1];
		pair<int, int> k;
		k.second = 1e9;
		map<int, int> m;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (m[a[i]] == 0)
				m[a[i]] = i;
			else if (k.second > m[a[i]])
			{
				k.first = a[i];
				k.second = m[a[i]];
			}
		}
		if (k.second != 1e9)
			cout << k.first << endl;
		else
			cout << "NO" << endl;
	}
}
 

// File: DSA06040 - GIAO CỦA BA DÃY SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		long long a1[n], a2[m], a3[k];
		for (int i = 0; i < n; i++)
			cin >> a1[i];
		for (int i = 0; i < m; i++)
			cin >> a2[i];
		for (int i = 0; i < k; i++)
			cin >> a3[i];
		int i = 0, j = 0, h = 0;
		vector<long long> a;
		while (i < n && j < m && h < k)
		{
			if (a1[i] == a2[j] && a2[j] == a3[h])
			{
				a.push_back(a1[i]);
				i++;
				j++;
				h++;
			}
			else if (a1[i] < a2[j])
				i++;
			else if (a2[j] < a3[h])
				j++;
			else
				h++;
		}
		if (a.size() == 0)
			cout << -1 << endl;
		else
		{
			for (int i = 0; i < a.size(); i++)
				cout << a[i] << " ";
			cout << endl;
		}
	}
}
 

// File: DSA06041 - SỐ XUẤT HIỆN NHIỀU NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, x, s = 0;
		cin >> n;
		pair<int, int> k;
		map<int, int> m;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			m[x]++;
		}
		for (auto i : m)
		{
			if (i.second > s)
			{
				s = i.second;
				k = i;
			}
		}
		if (k.second > (float)n / 2)
			cout << k.first << endl;
		else
			cout << "NO" << endl;
	}
}
 

// File: DSA06043 - ĐIỂM CÂN BẰNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n], s = 0, k = 0, ans = -1;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			s += a[i];
		}
		for (int i = 0; i < n; i++)
		{
			if (k * 2 + a[i] == s)
			{
				ans = i + 1;
				break;
			}
			k += a[i];
		}
		cout << ans << endl;
	}
}
 

// File: DSA06044 - SẮP XẾP CHẴN LẺ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, i1 = 0, i2 = 0;
	cin >> n;
	int a[n];
	vector<int> b, c;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i % 2 == 0)
			b.push_back(a[i]);
		else
			c.push_back(a[i]);
	}
	sort(b.begin(), b.end());
	sort(c.begin(), c.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			cout << b[i1++] << " ";
		else
			cout << c[i2++] << " ";
	}
}
 

// File: DSA06046 - CHÊNH LỆCH NHỎ NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n], s = 1e9;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 1; i < n; i++)
			s = min(s, a[i] - a[i - 1]);
		cout << s << endl;
	}
}
 

// File: DSA06047 - BỘ BA SỐ PYTAGO.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long a[n];
		string ans = "NO";
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				long long k = a[i] * a[i] + a[j] * a[j];
				long long x = sqrt(k);
				if (x * x == k && binary_search(a + j + 1, a + n, x))
				{
					ans = "YES";
					break;
				}
			}
			if (ans == "YES")
				break;
		}
		cout << ans << endl;
	}
}
 

// File: DSA06048 - SỐ LẦN QUAY VÒNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n], ans = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 1; i < n; i++)
		{
			if (a[i] < a[i - 1])
			{
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}
}
 

// File: DSA06049 - ĐẾM CẶP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		long long s = 0;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			int x = lower_bound(a + i + 1, a + n, a[i] + k) - a;
			s += x - i - 1;
		}
		cout << s << endl;
	}
}
 

// File: DSA07001 - NGĂN XẾP 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    stack<int> st;
    while (cin >> s)
    {
        if (s == "push")
        {
            cin >> n;
            st.push(n);
        }
        else if (s == "pop")
            st.pop();
        else if (s == "show")
        {
            if (st.size())
            {
                stack<int> q;
                while (st.size())
                {
                    q.push(st.top());
                    st.pop();
                }
                while (q.size())
                {
                    cout << q.top() << " ";
                    st.push(q.top());
                    q.pop();
                }
                cout << endl;
            }
            else
                cout << "empty" << endl;
        }
    }
}
 

// File: DSA07002 - NGĂN XẾP 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    string s;
    cin >> t;
    stack<int> st;
    while (t--)
    {
        cin >> s;
        if (s == "PUSH")
        {
            cin >> n;
            st.push(n);
        }
        else if (s == "POP")
        {
            if (st.size())
                st.pop();
        }
        else if (s == "PRINT")
        {
            if (st.size())
                cout << st.top() << endl;
            else
                cout << "NONE" << endl;
        }
    }
}
 

// File: DSA07003 - KIỂM TRA BIỂU THỨC SỐ HỌC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int ok = 0;
        string s;
        getline(cin, s);
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
                st.push(s[i]);
            if (s[i] == ')')
            {
                if (st.top() == '(')
                {
                    ok = 1;
                    break;
                }
                while (st.size() && st.top() != '(')
                    st.pop();
                st.pop();
            }
        }
        if (ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
 

// File: DSA07004 - ĐẾM SỐ DẤU NGOẶC ĐỔI CHIỀU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<char> st;
        if (s.length() % 2 == 1)
        {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')' && !st.empty())
            {
                if (st.top() == '(')
                    st.pop();
                else
                    st.push(s[i]);
            }
            else
                st.push(s[i]);
        }
        int k = st.size(), n = 0;
        while (!st.empty() && st.top() == '(')
        {
            st.pop();
            n++;
        }
        cout << (k / 2 + n % 2) << endl;
    }
}
 

// File: DSA07005 - BIỂU THỨC TƯƠNG ĐƯƠNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, k, ans = "";
        cin >> s;
        char c, d;
        stack<char> st, ld;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
                ld.push(s[i - 1]);
            }
            else if (s[i] == ')')
            {
                k = "";
                while (st.size())
                {
                    c = st.top();
                    st.pop();
                    d = st.top();
                    st.pop();
                    if (ld.top() == '-')
                    {
                        k = c + k;
                        if (d == '-')
                            k = '+' + k;
                        else
                            k = '-' + k;
                    }
                    else
                    {
                        k = c + k;
                        k = d + k;
                    }
                    if (d == '(')
                    {
                        for (int j = 1; j < k.size(); j++)
                            st.push(k[j]);
                        break;
                    }
                }
                ld.pop();
            }
            else
                st.push(s[i]);
        }
        while (st.size())
        {
            ans = st.top() + ans;
            st.pop();
        }
        cout << ans << endl;
    }
}
 

// File: DSA07007 - SO SÁNH BIỂU THỨC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string Try(string s)
{
    string k, ans = "";
    char c, d;
    stack<char> st, ld;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
            ld.push(s[i - 1]);
        }
        else if (s[i] == ')')
        {
            k = "";
            while (st.size())
            {
                c = st.top();
                st.pop();
                d = st.top();
                st.pop();
                if (ld.top() == '-')
                {
                    k = c + k;
                    if (d == '-')
                        k = '+' + k;
                    else
                        k = '-' + k;
                }
                else
                {
                    k = c + k;
                    k = d + k;
                }
                if (d == '(')
                {
                    for (int j = 1; j < k.size(); j++)
                        st.push(k[j]);
                    break;
                }
            }
            ld.pop();
        }
        else
            st.push(s[i]);
    }
    while (st.size())
    {
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        a = Try(a);
        b = Try(b);
        if (a == b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA07008 - BIẾN ĐỔI TRUNG TỐ - HẬU TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string ts = "+-*/^";
bool check(char c)
{
    for (int i = 0; i < ts.size(); i++)
        if (ts[i] == c)
            return 1;
    return 0;
}
bool Var(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
int Deg(char c)
{
    if (c == '^')
        return 50;
    if (c == '*' || c == '/')
        return 100;
    if (c == '+' || c == '-')
        return 300;
    return 1000;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, ans;
        cin >> s;
        stack<char> st;
        st.push('#');
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
                continue;
            }
            if (s[i] == ')')
            {
                while (st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
                continue;
            }
            if (Var(s[i]))
            {
                ans += s[i];
                continue;
            }
            if (check(s[i]))
            {
                while (Deg(st.top()) <= Deg(s[i]))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
                continue;
            }
        }
        while (st.top() != '#')
        {
            ans += st.top();
            st.pop();
        }
        cout << ans << endl;
    }
}
 

// File: DSA07009 - BIẾN ĐỔI TIỀN TỐ - TRUNG TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string ts = "+-*/";
bool check(char c)
{
    for (int i = 0; i < ts.size(); i++)
        if (ts[i] == c)
            return 1;
    return 0;
}
bool Var(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, k;
        cin >> s;
        stack<string> st;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (check(s[i]))
            {
                k = '(' + st.top();
                st.pop();
                k += s[i];
                k = k + st.top() + ')';
                st.pop();
                st.push(k);
            }
            else
                st.push(string(1, s[i]));
        }
        cout << st.top() << endl;
    }
}
 

// File: DSA07010 - BIẾN ĐỐI TIỀN TỐ - HẬU TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string ts = "+-*/";
bool check(char c)
{
    for (int i = 0; i < ts.size(); i++)
        if (ts[i] == c)
            return 1;
    return 0;
}
bool Var(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, k1, k2;
        cin >> s;
        stack<string> st;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (check(s[i]))
            {
                k1 = st.top();
                st.pop();
                k2 = st.top();
                st.pop();
                st.push(k1 + k2 + s[i]);
            }
            else
                st.push(string(1, s[i]));
        }
        cout << st.top() << endl;
    }
}
 

// File: DSA07011 - BIẾN ĐỔI HẬU TỐ - TIỀN TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string ts = "+-*/^";
bool check(char c)
{
    for (int i = 0; i < ts.size(); i++)
        if (ts[i] == c)
            return 1;
    return 0;
}
bool Var(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, k, ans;
        cin >> s;
        stack<string> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (Var(s[i]))
                st.push(string(1, s[i]));
            if (check(s[i]))
            {
                k = st.top();
                st.pop();
                k = s[i] + k;
                k = st.top() + k;
                st.pop();
                k = "(" + k + ")";
                st.push(k);
            }
        }
        s = st.top();
        while (!st.empty())
            st.pop();
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (Var(s[i]))
                ans = s[i] + ans;
            if (check(s[i]))
                st.push(string(1, s[i]));
            if (s[i] == '(')
            {
                ans = st.top() + ans;
                st.pop();
            }
        }
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        cout << ans << endl;
    }
}
 

// File: DSA07012 - BIẾN ĐỔI HẬU TỐ - TRUNG TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool Var(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, k;
        cin >> s;
        stack<string> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (Var(s[i]))
                st.push(string(1, s[i]));
            else
            {
                k = st.top();
                st.pop();
                k = s[i] + k;
                k = st.top() + k;
                st.pop();
                k = "(" + k + ")";
                st.push(k);
            }
        }
        cout << st.top() << endl;
    }
}
 

// File: DSA07013 - TÍNH GIÁ TRỊ BIỂU THỨC HẬU TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool Var(char c)
{
    return (c >= '1' && c <= '9');
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int st[s.size()] = {}, p = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (Var(s[i]))
                st[++p] = s[i] - '0';
            if (s[i] == '*')
            {
                st[p - 1] *= st[p];
                p--;
                continue;
            }
            if (s[i] == '/')
            {
                st[p - 1] /= st[p];
                p--;
                continue;
            }
            if (s[i] == '+')
            {
                st[p - 1] += st[p];
                p--;
                continue;
            }
            if (s[i] == '-')
            {
                st[p - 1] -= st[p];
                p--;
                continue;
            }
        }
        cout << st[0] << endl;
    }
}
 

// File: DSA07014 - TÍNH GIÁ TRỊ BIỂU THỨC TIỀN TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool Var(char c)
{
    return (c >= '1' && c <= '9');
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int st[s.size()] = {}, p = -1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (Var(s[i]))
            {
                st[++p] = s[i] - '0';
                continue;
            }
            if (s[i] == '*')
            {
                st[p - 1] = st[p] * st[p - 1];
                p--;
                continue;
            }
            if (s[i] == '/')
            {
                st[p - 1] = st[p] / st[p - 1];
                p--;
                continue;
            }
            if (s[i] == '+')
            {
                st[p - 1] = st[p] + st[p - 1];
                p--;
                continue;
            }
            if (s[i] == '-')
            {
                st[p - 1] = st[p] - st[p - 1];
                p--;
                continue;
            }
        }
        cout << st[0] << endl;
    }
}
 

// File: DSA07015 - TÍNH TOÁN GIÁ TRỊ BIỂU THỨC TRUNG TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string op = "+-*/";
bool check(char k)
{
    for (int i = 0; i < op.size(); i++)
    {
        if (op[i] == k)
            return 1;
    }
    return 0;
}
int deg(char k)
{
    if (k == '*' || k == '/')
        return 10;
    else if (k == '+' || k == '-')
        return 20;
    else
        return 100;
}
string topost(string a)
{
    string res = "";
    stack<char> st;
    st.push('#');
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '(')
        {
            st.push(a[i]);
            continue;
        }
        else if (a[i] == ')')
        {
            while (st.size() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
            continue;
        }
        else if (check(a[i]))
        {
            while (st.size() && deg(st.top()) <= deg(a[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(a[i]);
            continue;
        }
        long long so = 0, ok = 0;
        while (i < a.size() && a[i] != ')' && !check(a[i]))
        {
            long long ss = a[i] - '0';
            i++;
            so = so * 10 + ss;
            ok = 1;
        }
        if (ok == 1)
            i--;
        res += "(";
        res += to_string(so);
        res += ")";
    }
    while (st.size() && st.top() != '#')
    {
        res += st.top();
        st.pop();
    }
    return res;
}
long long tinh(string a)
{
    stack<long long> st;
    int i = 0;
    while (i < a.size())
    {
        if (a[i] == '(')
        {
            i++;
            long long so = 0;
            while (a[i] != ')')
            {
                so = so * 10 + (a[i] - '0');
                i++;
            }
            i++;
            st.push(so);
        }
        else if (st.size() > 1)
        {
            long long tmp1 = st.top();
            st.pop();
            long long tmp2 = st.top();
            st.pop();
            if (a[i] == '+')
                st.push(tmp1 + tmp2);
            else if (a[i] == '-')
                st.push(tmp2 - tmp1);
            else if (a[i] == '*')
                st.push(tmp1 * tmp2);
            else if (a[i] == '/')
                st.push(tmp2 / tmp1);
            i++;
        }
    }
    return st.top();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        cout << tinh(topost(a)) << endl;
    }
}
 

// File: DSA07016 - BIỂU THỨC TĂNG GIẢM.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<int> st;
        int pos = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'D')
            {
                if (i == 0 || s[i - 1] == 'I')
                {
                    st.push(pos + 1);
                    pos++;
                }
                st.push(pos + 1);
                pos++;
            }
            else
            {
                while (st.size())
                {
                    cout << st.top();
                    st.pop();
                }
                if (i == 0)
                {
                    cout << pos + 1;
                    pos++;
                }
                if (s[i + 1] != 'D')
                {
                    cout << pos + 1;
                    pos++;
                }
            }
        }
        while (st.size())
        {
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
}
 

// File: DSA07017 - PHẦN TỬ BÊN PHẢI NHỎ HƠN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), l(n, -1), r(n, -1);
        stack<int> b, c;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            while (!b.empty() && a[i] > a[b.top()])
            {
                l[b.top()] = i;
                b.pop();
            }
            b.push(i);
        }
        for (int i = 0; i < n; i++)
        {
            while (!c.empty() && a[i] < a[c.top()])
            {
                r[c.top()] = i;
                c.pop();
            }
            c.push(i);
        }
        for (int i = 0; i < n; i++)
        {
            if (l[i] == -1 || r[l[i]] == -1)
                cout << -1 << " ";
            else
                cout << a[r[l[i]]] << " ";
        }
        cout << endl;
    }
}
 

// File: DSA07018 - TỔNG ĐA THỨC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
map<int, int> m;
void Do(string s)
{
    s += ' ';
    int k1 = 0, k2 = 0, ok = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            if (ok == 0)
                k1 = k1 * 10 + s[i] - '0';
            else
                k2 = k2 * 10 + s[i] - '0';
        }
        else if (s[i] == '^')
            ok = 1;
        else if (s[i] == ' ')
        {
            m[k2] += k1;
            k1 = k2 = ok = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        m.clear();
        string a, b;
        getline(cin, a);
        getline(cin, b);
        Do(a);
        Do(b);
        vector<pair<int, int>> v;
        for (auto i : m)
            v.push_back(i);
        cout << v[v.size() - 1].second << "*x^" << v[v.size() - 1].first;
        for (int i = v.size() - 2; i >= 0; i--)
            cout << " + " << v[i].second << "*x^" << v[i].first;
        cout << endl;
    }
}
 

// File: DSA07019 - HÌNH CHỮ NHẬT LỚN NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long a[n] = {0}, MAX = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            int pos1 = i, pos2 = i, s1 = 0, s2 = 0;
            while (a[pos1] >= a[i] && pos1 >= 0)
            {
                pos1--;
                s1++;
            }
            while (a[pos2] >= a[i] && pos2 < n)
            {
                pos2++;
                s2++;
            }
            MAX = max(MAX, a[i] * (s1 + s2 - 1));
        }
        cout << MAX << "\n";
    }
}
 

// File: DSA07021 - DÃY NGOẶC ĐÚNG DÀI NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<pair<char, int>> st;
        int ans = 0, n = s.size();
        vector<int> F(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ')' && !st.empty() && st.top().first == '(')
            {
                F[i] = F[i - 1];
                if (st.top().second != 0)
                    F[i] += F[st.top().second - 1];
                F[i] += 2;
                st.pop();
            }
            else
                st.push({s[i], i});
        }
        for (int i = 0; i < n; i++)
            ans = max(ans, F[i]);
        cout << ans << endl;
    }
}
 

// File: DSA07022 - PHẦN TỬ CÓ SỐ LẦN XUẤT HIỆN NHIỀU HƠN BÊN PHẢI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], ans[n];
        stack<int> st;
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.size() && m[st.top()] <= m[a[i]])
                st.pop();
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(a[i]);
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}
 

// File: DSA07023 - ĐẢO TỪ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s, x = "";
        stack<string> st;
        getline(cin, s);
        s += ' ';
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                if (x != "")
                {
                    st.push(x);
                    x = "";
                }
            }
            else
                x += s[i];
        }
        while (st.size())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
}
 

// File: DSA07024 - GHÉP VÁN GỖ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], l[n], r[n], ans = 0;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            while (st.size() && a[i] <= a[st.top()])
                st.pop();
            if (st.empty())
                l[i] = 0;
            else
                l[i] = st.top() + 1;
            st.push(i);
        }
        while (st.size())
            st.pop();
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.size() && a[st.top()] >= a[i])
                st.pop();
            if (st.empty())
                r[i] = n - 1;
            else
                r[i] = st.top() - 1;
            st.push(i);
        }
        for (int i = 0; i < n; i++)
            if (r[i] - l[i] + 1 >= a[i])
                ans = max(ans, a[i]);
        cout << ans << endl;
    }
}

// File: DSA07027 - PHẦN TỬ BÊN PHẢI ĐẦU TIÊN LỚN HƠN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        stack<int> st;
        vector<int> a(n), b(n, -1);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && a[i] > a[st.top()])
            {
                b[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for (int i = 0; i < n; i++)
        {
            if (b[i] == -1)
                cout << -1 << " ";
            else
                cout << a[b[i]] << " ";
        }
        cout << endl;
    }
}
 

// File: DSA07028 - NHỊP CHỨNG KHOÁN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        stack<int> st;
        st.push(0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            while (st.size() > 1 && a[st.top()] <= a[i])
                st.pop();
            cout << i - st.top() << " ";
            st.push(i);
        }
        cout << endl;
    }
}
 

// File: DSA07029 - GIẢI MÃ XÂU KÝ TỰ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, k, ls, ans;
        cin >> s;
        int n;
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ']')
            {
                k = ls = ans = "";
                while (st.top() != '[')
                {
                    k = st.top() + k;
                    st.pop();
                }
                st.pop();
                while (st.size() && st.top() >= '0' && st.top() <= '9')
                {
                    ls = st.top() + ls;
                    st.pop();
                }
                n = 0;
                for (auto c : ls) n = n * 10 + c - '0';
                if (n == 0) n++;
                for (int j = 0; j < n; j++) ans += k;
                for (auto c : ans) st.push(c);
            }
            else st.push(s[i]);
        }
        ans = "";
        while (st.size())
        {
            ans = st.top() + ans;
            st.pop();
        }
        cout << ans << endl;
    }
}
 

// File: DSA07030 - HÌNH CHỮ NHẬT 0-1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, s = 1;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                if (a[j][i] == 1)
                    a[j][i] = a[j - 1][i] + 1;
        for (int i = 0; i < n; i++)
        {
            stack<int> b, c;
            int l[m], r[m];
            for (int j = 0; j < m; j++)
            {
                while (!b.empty() && a[i][j] <= a[i][b.top()])
                    b.pop();
                if (b.empty())
                    l[j] = 0;
                else
                    l[j] = b.top() + 1;
                b.push(j);
            }
            for (int j = m - 1; j >= 0; j--)
            {
                while (!c.empty() && a[i][j] <= a[i][c.top()])
                    c.pop();
                if (c.empty())
                    r[j] = m - 1;
                else
                    r[j] = c.top() - 1;
                c.push(j);
            }
            for (int j = 0; j < m; j++)
                s = max(s, (r[j] - l[j] + 1) * a[i][j]);
        }
        cout << s << endl;
    }
}
 

// File: DSA07041 - BIỂU THỨC ĐÚNG DÀI NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int ans = 0;
		stack<char> st;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				st.push(s[i]);
			else
			{
				if (!st.empty())
				{
					ans += 2;
					st.pop();
				}
			}
		}
		cout << ans << endl;
	}
}
 

// File: DSA07045 - GÕ BÀN PHÍM.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin >> a;
    stack<char> a1, a2;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '<')
        {
            if (!a1.empty())
            {
                a2.push(a1.top());
                a1.pop();
            }
        }
        else if (a[i] == '>')
        {
            if (!a2.empty())
            {
                a1.push(a2.top());
                a2.pop();
            }
        }
        else if (a[i] == '-')
        {
            if (!a1.empty())
                a1.pop();
        }
        else
            a1.push(a[i]);
    }
    while (a1.size())
    {
        a2.push(a1.top());
        a1.pop();
    }
    while (a2.size())
    {
        cout << a2.top();
        a2.pop();
    }
}
 

// File: DSA07110 - KIỂM TRA DÃY NGOẶC ĐÚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int ok = 1;
        string s;
        cin >> s;
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                if (st.size() && st.top() == '(')
                    st.pop();
                else
                {
                    ok = 0;
                    break;
                }
            }
            else if (s[i] == ']')
            {
                if (st.size() && st.top() == '[')
                    st.pop();
                else
                {
                    ok = 0;
                    break;
                }
            }
            else
            {
                if (st.size() && st.top() == '{')
                    st.pop();
                else
                {
                    ok = 0;
                    break;
                }
            }
        }
        if (st.size())
            ok = 0;
        if (ok == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA08001 - CẤU TRÚC DỮ LIỆU HÀNG ĐỢI 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        deque<int> st;
        while (n--)
        {
            cin >> x;
            if (x == 1)
                cout << st.size() << endl;
            else if (x == 2)
            {
                if (st.empty())
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else if (x == 3)
            {
                cin >> x;
                st.push_back(x);
            }
            else if (x == 4)
            {
                if (st.size())
                    st.pop_front();
            }
            else if (x == 5)
            {
                if (st.size())
                    cout << st.front() << endl;
                else
                    cout << -1 << endl;
            }
            else if (x == 6)
            {
                if (st.size())
                    cout << st.back() << endl;
                else
                    cout << -1 << endl;
            }
        }
    }
}
 

// File: DSA08002 - CẤU TRÚC DỮ LIỆU HÀNG ĐỢI 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n;
    string s;
    deque<int> dq;
    while (n--)
    {
        cin >> s;
        if (s == "PUSH")
        {
            cin >> x;
            dq.push_back(x);
        }
        else if (s == "PRINTFRONT")
        {
            if (dq.size())
                cout << dq.front() << endl;
            else
                cout << "NONE" << endl;
        }
        else if (s == "POP")
        {
            if (dq.size())
                dq.pop_front();
        }
    }
}
 

// File: DSA08003 - HÀNG ĐỢI HAI ĐẦU (DEQUEUE).cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n;
    string s;
    deque<int> dq;
    while (n--)
    {
        cin >> s;
        if (s == "PUSHFRONT")
        {
            cin >> x;
            dq.push_front(x);
        }
        else if (s == "PRINTFRONT")
        {
            if (dq.size())
                cout << dq.front() << endl;
            else
                cout << "NONE" << endl;
        }
        else if (s == "POPFRONT")
        {
            if (dq.size())
                dq.pop_front();
        }
        else if (s == "PUSHBACK")
        {
            cin >> x;
            dq.push_back(x);
        }
        else if (s == "PRINTBACK")
        {
            if (dq.size())
                cout << dq.back() << endl;
            else
                cout << "NONE" << endl;
        }
        else if (s == "POPBACK")
        {
            if (dq.size())
                dq.pop_back();
        }
    }
}
 

// File: DSA08004 - GIÁ TRỊ NHỎ NHẤT CỦA XÂU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int k, x;
        string s;
        cin >> k >> s;
        long long n = 0;
        map<char, int> m;
        priority_queue<int> q;
        for (int i = 0; i < s.size(); i++)
            m[s[i]]++;
        for (auto i : m)
            q.push(i.second);
        while (k--)
        {
            x = q.top();
            q.pop();
            q.push(x - 1);
        }
        while (q.size())
        {
            n += (long long)q.top() * q.top();
            q.pop();
        }
        cout << n << endl;
    }
}
 

// File: DSA08005 - SỐ NHỊ PHÂN TỪ 1 ĐẾN N.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string to_binary(int n)
{
    string s = "";
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            s = '0' + s;
        }
        else
        {
            s = '1' + s;
            n--;
        }
        n /= 2;
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cout << to_binary(i) << " ";
        }
        cout << endl;
    }
}
 

// File: DSA08006 - SỐ 0 VÀ SỐ 9.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        queue<long long> q;
        q.push(9);
        while (q.size())
        {
            long long k = q.front();
            q.pop();
            if (k % n == 0)
            {
                cout << k << endl;
                break;
            }
            q.push(k * 10);
            q.push(k * 10 + 9);
        }
    }
}
 

// File: DSA08007 - SỐ BDN 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string n, k;
bool check(string s)
{
	return s.size() < n.size() || (s.size() == n.size() && s <= n);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int d = 0;
		cin >> n;
		stack<string> st;
		st.push("1");
		while (st.size())
		{
			k = st.top();
			d++;
			st.pop();
			if (check(k + "0"))
				st.push(k + "0");
			if (check(k + "1"))
				st.push(k + "1");
		}
		cout << d << endl;
	}
}
 

// File: DSA08008 - SỐ BDN 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n;
        queue<long long> q;
        q.push(1);
        while (q.size())
        {
            k = q.front();
            if (k % n == 0)
            {
                cout << k << endl;
                break;
            }
            q.pop();
            q.push(k * 10);
            q.push(k * 10 + 1);
        }
    }
}
 

// File: DSA08009 - BIẾN ĐỔI S – T.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int s, t;
        cin >> s >> t;
        pair<int, int> u;
        u.first = s;
        u.second = 0;
        map<int, int> m;
        queue<pair<int, int>> q;
        q.push(u);
        while (q.size())
        {
            u = q.front();
            if (u.first == t)
            {
                cout << u.second << endl;
                break;
            }
            q.pop();
            if (u.first <= t && !m[u.first * 2])
            {
                m[u.first * 2]++;
                q.push({u.first * 2, u.second + 1});
            }
            if (u.first > 1 && !m[u.first - 1])
            {
                m[u.first - 1]++;
                q.push({u.first - 1, u.second + 1});
            }
        }
    }
}
 

// File: DSA08010 - BIẾN ĐỔI SỐ TỰ NHIÊN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        pair<int, int> u, v;
        queue<pair<int, int>> q;
        map<int, int> m;
        u.first = n;
        u.second = 0;
        q.push(u);
        while (q.size())
        {
            u = q.front();
            q.pop();
            if (u.first == 2)
            {
                cout << u.second + 1 << endl;
                break;
            }
            for (int i = 2; i <= sqrt(u.first); i++)
            {
                if (u.first % i == 0 && !m[u.first / i])
                {
                    m[u.first / i]++;
                    q.push({u.first / i, u.second + 1});
                }
            }
            q.push({u.first - 1, u.second + 1});
        }
    }
}
 

// File: DSA08011 - KHOẢNG CÁCH XÂU KÝ TỰ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string st, ed, k;
        cin >> n >> st >> ed;
        set<string> s;
        pair<string, int> u, v;
        queue<pair<string, int>> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> k;
            s.insert(k);
        }
        s.erase(st);
        u.first = st;
        u.second = 1;
        q.push(u);
        while (q.size())
        {
            u = q.front();
            q.pop();
            if (u.first == ed)
            {
                cout << u.second << endl;
                break;
            }
            v.second = u.second + 1;
            for (int i = 0; i < u.first.size(); i++)
            {
                k = u.first;
                for (char j = 'A'; j <= 'Z'; j++)
                {
                    k[i] = j;
                    if (s.find(k) != s.end())
                    {
                        s.erase(k);
                        v.first = k;
                        q.push(v);
                    }
                }
            }
        }
    }
}
 

// File: DSA08012 - TÌM SỐ K THỎA MÃN ĐIỀU KIỆN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> v;
int m[6];
void Try(int n)
{
    v.push_back(n);
    for (int i = 0; i <= 5; i++)
    {
        if (!m[i])
        {
            m[i] = 1;
            Try(n * 10 + i);
            m[i] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= 5; i++)
    {
        m[i] = 1;
        Try(i);
        m[i] = 0;
    }
    v.push_back(0);
    sort(v.begin(), v.end());
    int t;
    cin >> t;
    while (t--)
    {
        int l, r, s = 0;
        cin >> l >> r;
        int k1 = lower_bound(v.begin(), v.end(), l) - v.begin();
        int k2 = lower_bound(v.begin(), v.end(), r) - v.begin();
        if (v[k2] != r)
            k2--;
        cout << k2 - k1 + 1 << endl;
    }
}
 

// File: DSA08013 - DI CHUYỂN TRÁNH VẬT CẢN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    int x, y, s;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cin.ignore();
        int check[n][n] = {};
        char a[n][n];
        struct data u, v, ed;
        queue<struct data> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        cin >> u.x >> u.y >> ed.x >> ed.y;
        check[u.x][u.y] = 1;
        u.s = 0;
        q.push(u);
        while (q.size())
        {
            u = q.front();
            q.pop();
            if (u.x == ed.x && u.y == ed.y)
            {
                cout << u.s << endl;
                break;
            }
            v.s = u.s + 1;
            v.y = u.y;
            for (int i = u.x + 1; i < n; i++)
            {
                if (a[i][u.y] == 'X' || check[i][u.y])
                    break;
                v.x = i;
                check[i][u.y] = 1;
                q.push(v);
            }
            for (int i = u.x - 1; i >= 0; i--)
            {
                if (a[i][u.y] == 'X' || check[i][u.y])
                    break;
                v.x = i;
                check[i][u.y] = 1;
                q.push(v);
            }
            v.x = u.x;
            for (int i = u.y + 1; i < n; i++)
            {
                if (a[u.x][i] == 'X' || check[u.x][i])
                    break;
                v.y = i;
                check[u.x][i] = 1;
                q.push(v);
            }
            for (int i = u.y - 1; i >= 0; i--)
            {
                if (a[u.x][i] == 'X' || check[u.x][i])
                    break;
                v.y = i;
                check[u.x][i] = 1;
                q.push(v);
            }
        }
    }
}
 

// File: DSA08014 - GIEO MẦM.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int rx[] = {1, -1, 0, 0};
int ry[] = {0, 0, 1, -1};
struct data
{
    int x, y, s;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, ans = 0;
        cin >> n >> m;
        int a[n + 1][m + 1];
        struct data u, v;
        queue<struct data> q;
        u.s = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 2)
                {
                    u.x = i;
                    u.y = j;
                    q.push(u);
                }
            }
        }
        while (q.size())
        {
            u = q.front();
            q.pop();
            ans = max(ans, u.s);
            for (int i = 0; i < 4; i++)
            {
                v.x = u.x + rx[i];
                v.y = u.y + ry[i];
                if (v.x >= 1 && v.x <= n && v.y >= 1 && v.y <= m && a[v.x][v.y] == 1)
                {
                    a[v.x][v.y] = 2;
                    v.s = u.s + 1;
                    q.push(v);
                }
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (a[i][j] == 1)
                    ans = -1;
        cout << ans << endl;
    }
}
 

// File: DSA08015 - DI CHUYỂN TRONG KHÔNG GIAN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct point
{
	int x, y, z, s;
};
int gx[6] = {1, -1, 0, 0, 0, 0};
int gy[6] = {0, 0, 1, -1, 0, 0};
int gz[6] = {0, 0, 0, 0, 1, -1};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int h, r, d, ok = -1;
		cin >> h >> r >> d;
		point st, ed, b, c;
		char a[h + 1][r + 1][d + 1];
		queue<point> q;
		for (int i = 1; i <= h; i++)
		{
			cin.ignore();
			for (int j = 1; j <= r; j++)
			{
				for (int k = 1; k <= d; k++)
				{
					cin >> a[i][j][k];
					if (a[i][j][k] == 'S')
					{
						st.x = i;
						st.y = j;
						st.z = k;
						st.s = 0;
						a[i][j][k] = '#';
					}
					else if (a[i][j][k] == 'E')
					{
						ed.x = i;
						ed.y = j;
						ed.z = k;
					}
				}
			}
		}
		q.push(st);
		while (q.size())
		{
			b = q.front();
			q.pop();
			c = b;
			c.s++;
			if (b.x == ed.x && b.y == ed.y && b.z == ed.z)
			{
				ok = b.s;
				break;
			}
			for (int i = 0; i < 6; i++)
			{
				c.x += gx[i];
				c.y += gy[i];
				c.z += gz[i];
				if (c.x >= 1 && c.x <= h && c.y >= 1 && c.y <= r && c.z >= 1 && c.z <= d && a[c.x][c.y][c.z] != '#')
				{
					q.push(c);
					a[c.x][c.y][c.z] = '#';
				}
				c.x -= gx[i];
				c.y -= gy[i];
				c.z -= gz[i];
			}
		}
		cout << ok << endl;
	}
}
 

// File: DSA08016 - HEXGAME.cpp
#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
using namespace std;
int l1[10] = {0, 4, 1, 3, 8, 5, 2, 7, 9, 6};
int r1[10] = {3, 0, 2, 7, 4, 1, 6, 8, 5, 9};
int l2[10] = {1, 5, 2, 0, 4, 8, 6, 3, 7, 9};
int r2[10] = {0, 2, 6, 3, 1, 5, 9, 7, 4, 8};
string left1(string a)
{
	string b = "";
	for (int i = 0; i < 10; i++)
		b += a[l1[i]];
	return b;
}
string right1(string a)
{
	string b = "";
	for (int i = 0; i < 10; i++)
		b += a[r1[i]];
	return b;
}
string left2(string a)
{
	string b = "";
	for (int i = 0; i < 10; i++)
		b += a[l2[i]];
	return b;
}
string right2(string a)
{
	string b = "";
	for (int i = 0; i < 10; i++)
		b += a[r2[i]];
	return b;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string a, b, y;
		int x, mim = 1e9;
		for (int i = 0; i < 10; i++)
		{
			cin >> x;
			a += to_string(x);
		}
		b = "1238004765";
		pair<string, int> x1, x2, y1, y2, k;
		map<string, int> f;
		x1.fi = a;
		x1.se = 0;
		x2.fi = b;
		x2.se = 0;
		queue<pair<string, int>> q1, q2;
		q1.push(x1);
		q2.push(x2);
		while (q1.size())
		{
			y1 = q1.front();
			q1.pop();
			k.se = y1.se + 1;
			k.fi = left1(y1.fi);
			if (f[k.fi] == 0)
				f[k.fi] = k.se;
			q1.push(k);
			k.fi = right1(y1.fi);
			if (f[k.fi] == 0)
				f[k.fi] = k.se;
			q1.push(k);
			if (k.se == 14)
				break;
		}
		while (q2.size())
		{
			y2 = q2.front();
			q2.pop();
			if (f[y2.fi] > 0)
				mim = min(mim, f[y2.fi] + y2.se);
			k.se = y2.se + 1;
			k.fi = left2(y2.fi);
			q2.push(k);
			k.fi = right2(y2.fi);
			q2.push(k);
			if (k.se == 14)
				break;
		}
		cout << mim << endl;
	}
}
 

// File: DSA08017 - SỐ LỘC PHÁT 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        queue<string> dq;
        stack<string> ans;
        dq.push("6");
        dq.push("8");
        while (dq.size())
        {
            string k = dq.front();
            ans.push(k);
            dq.pop();
            if (k.size() != n)
            {
                dq.push(k + "6");
                dq.push(k + "8");
            }
        }
        while (ans.size())
        {
            cout << ans.top() << " ";
            ans.pop();
        }
        cout << endl;
    }
}
 

// File: DSA08018 - SỐ LỘC PHÁT 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, s = 0;
        cin >> n;
        queue<string> dq;
        dq.push("6");
        dq.push("8");
        for (int i = 1; i <= n; i++)
        {
            s += pow(2, i);
        }
        cout << s << endl;
        while (dq.size())
        {
            string k = dq.front();
            cout << k << " ";
            dq.pop();
            if (k.size() != n)
            {
                dq.push(k + "6");
                dq.push(k + "8");
            }
        }
        cout << endl;
    }
}
 

// File: DSA08019 - SỐ LỘC PHÁT 3.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        queue<string> dq;
        stack<string> ans;
        dq.push("6");
        dq.push("8");
        while (dq.size())
        {
            string k = dq.front();
            ans.push(k);
            dq.pop();
            if (k.size() != n)
            {
                dq.push(k + "6");
                dq.push(k + "8");
            }
        }
        cout << ans.size() << endl;
        while (ans.size())
        {
            cout << ans.top() << " ";
            ans.pop();
        }
        cout << endl;
    }
}
 

// File: DSA08020 - BIẾN ĐỔI SỐ NGUYÊN TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> check(10000, 1);
void era()
{
    for (int i = 2; i * i <= 9999; i++)
        if (check[i])
            for (int j = i * i; j <= 9999; j += i)
                check[j] = 0;
}
int to_int(string s)
{
    int n = 0;
    for (int i = 0; i < s.size(); i++)
        n = n * 10 + s[i] - '0';
    return n;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    era();
    int t;
    cin >> t;
    while (t--)
    {
        string st, ed, s;
        cin >> st >> ed;
        pair<string, int> u, v;
        queue<pair<string, int>> q;
        map<string, int> m;
        m[st]++;
        q.push({st, 0});
        while (q.size())
        {
            u = q.front();
            q.pop();
            s = u.first;
            if (s == ed)
            {
                cout << u.second << endl;
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                int pos = 0;
                if (i == 0)
                    pos++;
                for (int j = pos; j <= 9; j++)
                {
                    s[i] = j + '0';
                    if (!m[s] && check[to_int(s)])
                    {
                        m[s]++;
                        q.push({s, u.second + 1});
                    }
                }
                s = u.first;
            }
        }
    }
}
 

// File: DSA08021 - DI CHUYỂN TRONG MA TRẬN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct point
{
    int x, y, s;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, ans = 1e9;
        cin >> n >> m;
        vector<vector<bool>> check(n + 1, vector<bool>(m + 1, 1));
        vector<vector<int>> a(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        point st, k;
        queue<point> q;
        st.x = st.y = 1;
        st.s = 0;
        q.push(st);
        while (q.size())
        {
            st = q.front();
            q.pop();
            if (st.x == n && st.y == m)
                ans = min(ans, st.s);
            k = st;
            k.s++;
            if (st.x + a[st.x][st.y] <= n && check[st.x + a[st.x][st.y]][st.y])
            {
                check[st.x + a[st.x][st.y]][st.y] = 0;
                k.x += a[st.x][st.y];
                q.push(k);
                k.x -= a[st.x][st.y];
            }
            if (st.y + a[st.x][st.y] <= m && check[st.x][st.y + a[st.x][st.y]])
            {
                check[st.x][st.y + a[st.x][st.y]] = 0;
                k.y += a[st.x][st.y];
                q.push(k);
                k.y -= a[st.x][st.y];
            }
        }
        if (ans == 1e9)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
}
 

// File: DSA08022 - BỘI SỐ LỚN NHẤT CỦA 3.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, s = 0;
        cin >> n;
        vector<int> a1, a2, a3;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (x == 0)
                s++;
            else if (x % 3 == 0)
                a3.push_back(x);
            else if (x % 3 == 1)
                a1.push_back(x);
            else
                a2.push_back(x);
        }
        sort(a1.begin(), a1.end(), greater<int>());
        sort(a2.begin(), a2.end(), greater<int>());
        int k = min(a1.size(), a2.size());
        if (abs((int)a1.size() - (int)a2.size()) % 3 == 2 && k != 0)
            k--;
        for (int i = 0; i < k; i++)
        {
            a3.push_back(a1[i]);
            a3.push_back(a2[i]);
        }
        k += 2;
        for (int i = k; i < a1.size(); i += 3)
        {
            a3.push_back(a1[i]);
            a3.push_back(a1[i - 1]);
            a3.push_back(a1[i - 2]);
        }
        for (int i = k; i < a2.size(); i += 3)
        {
            a3.push_back(a2[i]);
            a3.push_back(a2[i - 1]);
            a3.push_back(a2[i - 2]);
        }
        sort(a3.begin(), a3.end(), greater<int>());
        for (int i = 0; i < a3.size(); i++)
            cout << a3[i];
        if (a3.size())
            for (int i = 0; i < s; i++)
                cout << 0;
        else
            cout << -1;
        cout << endl;
    }
}
 

// File: DSA08025 - QUÂN MÃ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    int x, y, s;
};
int rx[] = {1, 2, -1, 2, 1, -2, -1, -2};
int ry[] = {2, 1, 2, -1, -2, 1, -2, -1};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int check[9][9] = {};
        struct data u, v, k;
        queue<struct data> q;
        u.x = a[0] - 'a' + 1;
        u.y = a[1] - '0';
        u.s = 0;
        v.x = b[0] - 'a' + 1;
        v.y = b[1] - '0';
        q.push(u);
        while (q.size())
        {
            u = q.front();
            q.pop();
            if (u.x == v.x && u.y == v.y)
            {
                cout << u.s << endl;
                break;
            }
            k.s = u.s + 1;
            for (int i = 0; i < 8; i++)
            {
                k.x = u.x + rx[i];
                k.y = u.y + ry[i];
                if (k.x >= 1 && k.x <= 8 && k.y >= 1 && k.y <= 8 && !check[k.x][k.y])
                {
                    check[k.x][k.y] = 1;
                    q.push(k);
                }
            }
        }
    }
}
 

// File: DSA08029 - QUAY HÌNH VUÔNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
using namespace std;
int l[6] = {3, 0, 2, 4, 1, 5};
int r[6] = {0, 4, 1, 3, 5, 2};
string rleft(string a)
{
    string b = "";
    for (int i = 0; i < 6; i++)
        b += a[l[i]];
    return b;
}
string rright(string a)
{
    string b = "";
    for (int i = 0; i < 6; i++)
        b += a[r[i]];
    return b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        int x;
        for (int i = 0; i < 6; i++)
        {
            cin >> x;
            a += to_string(x);
        }
        for (int i = 0; i < 6; i++)
        {
            cin >> x;
            b += to_string(x);
        }
        pair<string, int> d, k, e;
        d.fi = a;
        d.se = 0;
        queue<pair<string, int>> c;
        c.push(d);
        while (c.size())
        {
            k = c.front();
            c.pop();
            if (k.fi == b)
            {
                cout << k.se << endl;
                break;
            }
            e.se = k.se + 1;
            e.fi = rleft(k.fi);
            c.push(e);
            e.fi = rright(k.fi);
            c.push(e);
        }
    }
}

// File: DSA09001 - CHUYỂN DANH SÁCH CẠNH SANG DANH SÁCH KỀ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, u, v;
		cin >> n >> m;
		vector<vector<int>> a(n + 1);
		while (m--)
		{
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
		{
			cout << i << ": ";
			for (int j = 0; j < a[i].size(); j++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
}
 

// File: DSA09002 - CHUYỂN TỪ DANH SÁCH KỀ SANG DANH SÁCH CẠNH.cpp
#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	set<pair<int, int>> m;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		s += ' ';
		int k = 0;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] >= '0' && s[j] <= '9')
			{
				k = k * 10 + s[j] - '0';
			}
			else
			{
				int a = i + 1, b = k;
				if (a > b)
					swap(a, b);
				m.insert(make_pair(a, b));
				k = 0;
			}
		}
	}
	for (auto i : m)
	{
		cout << i.fi << " " << i.se << endl;
	}
}
 

// File: DSA09003 - BIỂU DIỄN ĐỒ THỊ CÓ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, u, v;
		cin >> n >> m;
		vector<vector<int>> a(n + 1);
		while (m--)
		{
			cin >> u >> v;
			a[u].push_back(v);
		}
		for (int i = 1; i <= n; i++)
		{
			cout << i << ": ";
			for (int j = 0; j < a[i].size(); j++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
}
 

// File: DSA09004 - DFS TRÊN ĐỒ THỊ VÔ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, x, y;
        cin >> n >> m >> u;
        vector<bool> check(n + 1, 1);
        vector<vector<int>> a(n + 1);
        stack<int> st;
        while (m--)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
            sort(a[i].begin(), a[i].end());
        st.push(u);
        check[u] = 0;
        cout << u << " ";
        while (st.size())
        {
            u = st.top();
            st.pop();
            for (int i = 0; i < a[u].size(); i++)
            {
                int v = a[u][i];
                if (check[v])
                {
                    cout << v << " ";
                    check[v] = 0;
                    st.push(u);
                    st.push(v);
                    break;
                }
            }
        }
        cout << endl;
    }
}
 

// File: DSA09005 - BFS TRÊN ĐỒ THỊ VÔ HƯỚNG.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, x, y;
        cin >> n >> m >> u;
        vector<int> a[n + 1], check(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
            sort(a[i].begin(), a[i].end());
        queue<int> q;
        q.push(u);
        check[u] = 1;
        while (q.size())
        {
            u = q.front();
            q.pop();
            cout << u << " ";
            for (int i = 0; i < a[u].size(); i++)
            {
                int v = a[u][i];
                if (!check[v])
                {
                    q.push(v);
                    check[v] = 1;
                }
            }
        }
        cout << endl;
    }
}
 

// File: DSA09006 - ĐƯỜNG ĐI THEO DFS VỚI ĐỒ THỊ VÔ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, v, x, y, ok = 0;
        cin >> n >> m >> u >> v;
        string s;
        vector<bool> check(n + 1, 1);
        vector<vector<int>> a(n + 1);
        stack<pair<int, string>> st;
        while (m--)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        st.push({u, to_string(u) + " "});
        check[u] = 0;
        while (st.size())
        {
            x = st.top().first;
            s = st.top().second;
            if (x == v)
            {
                ok = 1;
                cout << s << endl;
                break;
            }
            st.pop();
            for (int i = 0; i < a[x].size(); i++)
            {
                int y = a[x][i];
                if (check[y])
                {
                    check[y] = 0;
                    st.push({x, s});
                    st.push({y, s + to_string(y) + " "});
                    break;
                }
            }
        }
        if (ok == 0)
            cout << -1 << endl;
    }
}
 

// File: DSA09007 - ĐƯỜNG ĐI THEO BFS TRÊN ĐỒ THỊ VÔ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, v, x, y, ok = 0;
        cin >> n >> m >> u >> v;
        string s;
        vector<bool> check(n + 1, 1);
        vector<vector<int>> a(n + 1);
        queue<pair<int, string>> st;
        while (m--)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        st.push({u, to_string(u) + " "});
        check[u] = 0;
        while (st.size())
        {
            x = st.front().first;
            s = st.front().second;
            if (x == v)
            {
                ok = 1;
                cout << s << endl;
                break;
            }
            st.pop();
            for (int i = 0; i < a[x].size(); i++)
            {
                int y = a[x][i];
                if (check[y])
                {
                    check[y] = 0;
                    st.push({y, s + to_string(y) + " "});
                }
            }
        }
        if (ok == 0)
            cout << -1 << endl;
    }
}
 

// File: DSA09008 - ĐẾM SỐ THÀNH PHẦN LIÊN THÔNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y, s = 0, k;
        cin >> n >> m;
        int check[n + 1] = {};
        vector<vector<int>> a(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!check[i])
            {
                s++;
                check[i] = 1;
                stack<int> st;
                st.push(i);
                while (st.size())
                {
                    k = st.top();
                    st.pop();
                    for (auto j : a[k])
                    {
                        if (!check[j])
                        {
                            check[j] = 1;
                            st.push(j);
                        }
                    }
                }
            }
        }
        cout << s << endl;
    }
}
 

// File: DSA09009 - TÌM SỐ THÀNH PHẦN LIÊN THÔNG VỚI BFS.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y, s = 0, k;
        cin >> n >> m;
        int check[n + 1] = {};
        vector<vector<int>> a(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!check[i])
            {
                s++;
                check[i] = 1;
                stack<int> st;
                st.push(i);
                while (st.size())
                {
                    k = st.top();
                    st.pop();
                    for (auto j : a[k])
                    {
                        if (!check[j])
                        {
                            check[j] = 1;
                            st.push(j);
                        }
                    }
                }
            }
        }
        cout << s << endl;
    }
}
 

// File: DSA09010 - KIỂM TRA TÍNH LIÊN THÔNG MẠNH.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y, ok = 1;
        cin >> n >> m;
        queue<int> q;
        vector<bool> check(n + 1, 1);
        vector<vector<int>> a(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
        }
        q.push(1);
        check[1] = 0;
        while (q.size())
        {
            x = q.front();
            q.pop();
            for (auto y : a[x])
            {
                if (check[y])
                {
                    check[y] = 0;
                    q.push(y);
                }
            }
        }
        for (int i = 2; i <= n; i++)
        {
            if (check[i])
            {
                ok = 0;
                break;
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA09011 - SỐ LƯỢNG HÒN ĐẢO.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, s;
int a[501][501];
int gx[] = {1, 1, 0, 0, -1, -1, 1, -1};
int gy[] = {1, -1, 1, -1, -1, 1, 0, 0};
void BFS(int x, int y)
{
    pair<int, int> k;
    queue<pair<int, int>> q;
    q.push({x, y});
    a[x][y] = 0;
    while (q.size())
    {
        k = q.front();
        q.pop();
        x = k.first;
        y = k.second;
        for (int i = 0; i < 8; i++)
        {
            x += gx[i];
            y += gy[i];
            if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y])
            {
                a[x][y] = 0;
                q.push({x, y});
            }
            x -= gx[i];
            y -= gy[i];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        s = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == 1)
                {
                    s++;
                    BFS(i, j);
                }
            }
        }
        cout << s << endl;
    }
}
 

// File: DSA09012 - LIỆT KÊ ĐỈNH TRỤ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<bool> check;
vector<vector<int>> a;
void bfs(int n)
{
    queue<int> q;
    q.push(n);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : a[u])
        {
            if (check[v])
            {
                check[v] = 0;
                q.push(v);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y, stp = 0, s;
        cin >> n >> m;
        a.clear();
        a.resize(n + 1);
        check.clear();
        check.resize(n + 1, 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
        {
            if (check[i])
            {
                stp++;
                check[i] = 0;
                bfs(i);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            check.clear();
            check.resize(n + 1, 1);
            s = 0;
            check[i] = 0;
            for (int j = 1; j <= n; j++)
            {
                if (check[j])
                {
                    s++;
                    check[j] = 0;
                    bfs(j);
                }
            }
            if (s > stp)
                cout << i << " ";
        }
        cout << endl;
    }
}
 

// File: DSA09013 - LIỆT KÊ CẠNH CẦU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<bool> check;
vector<vector<int>> a;
void bfs(int n, int x, int y)
{
    queue<int> q;
    q.push(n);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : a[u])
        {
            if ((u == x && v == y) || (u == y && v == x))
                continue;
            if (check[v])
            {
                check[v] = 0;
                q.push(v);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, stp = 0, s;
        cin >> n >> m;
        a.clear();
        a.resize(n + 1);
        check.clear();
        check.resize(n + 1, 1);
        vector<pair<int, int>> e(m);
        for (int i = 0; i < m; i++)
        {
            cin >> e[i].first >> e[i].second;
            a[e[i].first].push_back(e[i].second);
            a[e[i].second].push_back(e[i].first);
        }
        sort(e.begin(), e.end());
        for (int i = 1; i <= n; i++)
        {
            if (check[i])
            {
                stp++;
                check[i] = 0;
                bfs(i, -1, -1);
            }
        }
        for (int i = 0; i < m; i++)
        {
            check.clear();
            check.resize(n + 1, 1);
            s = 0;
            for (int j = 1; j <= n; j++)
            {
                if (check[j])
                {
                    s++;
                    check[j] = 0;
                    bfs(j, e[i].first, e[i].second);
                }
            }
            if (s > stp)
                cout << e[i].first << " " << e[i].second << " ";
        }
        cout << endl;
    }
}
 

// File: DSA09014 - KIỂM TRA CHU TRÌNH TRÊN ĐỒ THỊ VÔ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, x, y, ok;
vector<int> svs;
vector<bool> check;
vector<vector<int>> a;
void BFS(int k)
{
    check[k] = 0;
    for (auto i : a[k])
    {
        if (check[i])
        {
            svs[i] = k;
            BFS(i);
        }
        else if (i != svs[k])
        {
            ok = 1;
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ok = 0;
        a.clear();
        svs.clear();
        check.clear();
        a.resize(n + 1);
        svs.resize(n + 1, -1);
        check.resize(n + 1, 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
            if (check[i] && !ok)
                BFS(i);
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA09015 - KIỂM TRA CHU TRÌNH TRÊN ĐỒ THỊ CÓ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, x, y, ok;
vector<int> check;
vector<vector<int>> a;
void DFS(int k)
{
    check[k] = 1;
    for (auto i : a[k])
    {
        if (check[i] == 0)
            DFS(i);
        else if (check[i] == 1)
            ok = 1;
    }
    check[k] = 2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ok = 0;
        a.clear();
        check.clear();
        a.resize(n + 1);
        check.resize(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
        }
        for (int i = 1; i <= n; i++)
            if (!check[i] && !ok)
                DFS(i);
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA09016 - KIỂM TRA CHU TRÌNH TRÊN ĐỒ THỊ CÓ HƯỚNG VỚI DFS.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, x, y, ok;
vector<int> check;
vector<vector<int>> a;
void DFS(int k)
{
    check[k] = 1;
    for (auto i : a[k])
    {
        if (check[i] == 0)
            DFS(i);
        else if (check[i] == 1)
            ok = 1;
    }
    check[k] = 2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ok = 0;
        a.clear();
        check.clear();
        a.resize(n + 1);
        check.resize(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
        }
        for (int i = 1; i <= n; i++)
            if (!check[i] && !ok)
                DFS(i);
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA09017 - KIỂM TRA ĐỒ THỊ CÓ PHẢI LÀ CÂY HAY KHÔNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int check[1001], ok;
vector<vector<int>> a(1001);
void dfs(int u)
{
    for (auto v : a[u])
    {
        if (check[v])
        {
            ok = 1;
            return;
        }
        check[v]++;
        dfs(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ok = 0;
        int n, u, v;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            a[i].clear();
            check[i] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            cin >> u >> v;
            a[u].push_back(v);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!check[i] && !ok)
            {
                check[i]++;
                dfs(i);
            }
        }
        if (!ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA09018 - LIỆT KÊ ĐỈNH TRỤ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<bool> check;
vector<vector<int>> a;
void bfs(int n)
{
    queue<int> q;
    q.push(n);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : a[u])
        {
            if (check[v])
            {
                check[v] = 0;
                q.push(v);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y, stp = 0, s;
        cin >> n >> m;
        a.clear();
        a.resize(n + 1);
        check.clear();
        check.resize(n + 1, 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
        {
            if (check[i])
            {
                stp++;
                check[i] = 0;
                bfs(i);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            check.clear();
            check.resize(n + 1, 1);
            s = 0;
            check[i] = 0;
            for (int j = 1; j <= n; j++)
            {
                if (check[j])
                {
                    s++;
                    check[j] = 0;
                    bfs(j);
                }
            }
            if (s > stp)
                cout << i << " ";
        }
        cout << endl;
    }
}
 

// File: DSA09019 - KIỂM TRA CHU TRÌNH.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, x, y, ok;
vector<int> svs;
vector<bool> check;
vector<vector<int>> a;
void BFS(int k)
{
    check[k] = 0;
    for (auto i : a[k])
    {
        if (check[i])
        {
            svs[i] = k;
            BFS(i);
        }
        else if (i != svs[k])
        {
            ok = 1;
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ok = 0;
        a.clear();
        svs.clear();
        check.clear();
        a.resize(n + 1);
        svs.resize(n + 1, -1);
        check.resize(n + 1, 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
            if (check[i] && !ok)
                BFS(i);
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA09020 - CHUYỂN DANH SÁCH KỀ SANG MA TRẬN KỀ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        getline(cin, s);
        s += ' ';
        int k = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] >= '0' && s[j] <= '9')
                k = k * 10 + s[j] - '0';
            else
            {
                a[i][k] = a[k][i] = 1;
                k = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
 

// File: DSA09021 - CHUYỂN MA TRẬN KỀ SANG DANH SÁCH KỀ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n;
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            if (i > j && x == 1)
            {
                a[i].push_back(j);
                a[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto j : a[i])
            cout << j << " ";
        cout << endl;
    }
}
 

// File: DSA09022 - DFS TRÊN ĐỒ THỊ CÓ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, x, y;
        cin >> n >> m >> u;
        vector<bool> check(n + 1, 1);
        vector<vector<int>> a(n + 1);
        stack<int> st;
        while (m--)
        {
            cin >> x >> y;
            a[x].push_back(y);
        }
        for (int i = 1; i <= n; i++)
            sort(a[i].begin(), a[i].end());
        st.push(u);
        check[u] = 0;
        cout << u << " ";
        while (st.size())
        {
            u = st.top();
            st.pop();
            for (int i = 0; i < a[u].size(); i++)
            {
                int v = a[u][i];
                if (check[v])
                {
                    cout << v << " ";
                    check[v] = 0;
                    st.push(u);
                    st.push(v);
                    break;
                }
            }
        }
        cout << endl;
    }
}
 

// File: DSA09024 - BFS TRÊN ĐỒ THỊ CÓ HƯỚNG.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, x, y;
        cin >> n >> m >> u;
        vector<int> a[n + 1], check(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
        }
        for (int i = 1; i <= n; i++)
            sort(a[i].begin(), a[i].end());
        queue<int> q;
        q.push(u);
        check[u] = 1;
        while (q.size())
        {
            u = q.front();
            q.pop();
            cout << u << " ";
            for (int i = 0; i < a[u].size(); i++)
            {
                int v = a[u][i];
                if (!check[v])
                {
                    q.push(v);
                    check[v] = 1;
                }
            }
        }
        cout << endl;
    }
}
 

// File: DSA09025 - ĐƯỜNG ĐI THEO DFS VỚI ĐỒ THỊ CÓ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, v, x, y, ok = 0;
        cin >> n >> m >> u >> v;
        string s;
        vector<bool> check(n + 1, 1);
        vector<vector<int>> a(n + 1);
        stack<pair<int, string>> st;
        while (m--)
        {
            cin >> x >> y;
            a[x].push_back(y);
        }
        st.push({u, to_string(u) + " "});
        check[u] = 0;
        while (st.size())
        {
            x = st.top().first;
            s = st.top().second;
            if (x == v)
            {
                ok = 1;
                cout << s << endl;
                break;
            }
            st.pop();
            for (int i = 0; i < a[x].size(); i++)
            {
                int y = a[x][i];
                if (check[y])
                {
                    check[y] = 0;
                    st.push({x, s});
                    st.push({y, s + to_string(y) + " "});
                    break;
                }
            }
        }
        if (ok == 0)
            cout << -1 << endl;
    }
}
 

// File: DSA09026 - ĐƯỜNG ĐI THEO BFS TRÊN ĐỒ THỊ CÓ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, v, x, y, ok = 0;
        cin >> n >> m >> u >> v;
        string s;
        vector<bool> check(n + 1, 1);
        vector<vector<int>> a(n + 1);
        queue<pair<int, string>> st;
        while (m--)
        {
            cin >> x >> y;
            a[x].push_back(y);
        }
        st.push({u, to_string(u) + " "});
        check[u] = 0;
        while (st.size())
        {
            x = st.front().first;
            s = st.front().second;
            if (x == v)
            {
                ok = 1;
                cout << s << endl;
                break;
            }
            st.pop();
            for (int i = 0; i < a[x].size(); i++)
            {
                int y = a[x][i];
                if (check[y])
                {
                    check[y] = 0;
                    st.push({y, s + to_string(y) + " "});
                }
            }
        }
        if (ok == 0)
            cout << -1 << endl;
    }
}
 

// File: DSA09027 - KIỂM TRA ĐƯỜNG ĐI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y, k;
        cin >> n >> m;
        vector<vector<int>> a(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        cin >> m;
        while (m--)
        {
            cin >> x >> y;
            queue<int> q;
            q.push(x);
            int ok = 0, check[n + 1] = {};
            while (q.size())
            {
                k = q.front();
                q.pop();
                if (k == y)
                {
                    ok = 1;
                    break;
                }
                for (int i = 0; i < a[k].size(); i++)
                {
                    if (!check[a[k][i]])
                    {
                        check[a[k][i]] = 1;
                        q.push(a[k][i]);
                    }
                }
            }
            if (ok)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}
 

// File: DSA09028 - TÔ MÀU ĐỒ THỊ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int V, E, M, s;
vector<bool> d;
vector<vector<int>> x;
vector<pair<int, int>> a;
void countdeg()
{
    for (int i = 1; i <= V; i++)
    {
        int k = 0;
        for (int v = 1; v <= V; v++)
            if (x[i][v] == 1)
                k++;
        a.push_back({k, i});
    }
}
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> V >> E >> M;
        s = 0;
        x.clear();
        x.resize(V + 1, vector<int>(V + 1, 0));
        a.clear();
        d.clear();
        d.resize(V + 1, 0);
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            x[u][v] = x[v][u] = 1;
        }
        countdeg();
        sort(a.begin(), a.end(), cmp);
        for (auto i : a)
        {
            int u = i.second;
            if (d[u])
                continue;
            d[u] = 1;
            s++;
            for (int v = 1; v <= V; v++)
                if (x[u][v] == 0)
                    d[v] = 1;
        }
        if (s <= M)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
 

// File: DSA09029 - ĐƯỜNG ĐI HAMILTON.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> x[100];
int n, m;
bool ok;
vector<bool> a;
void dfs(int s, int k)
{
    for (int v : x[s])
    {
        if (a[v] == 0)
            continue;
        if (k == n)
        {
            ok = 1;
            return;
        }
        a[v] = 0;
        dfs(v, k + 1);
        a[v] = 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < 100; i++)
            x[i].clear();
        ok = 0;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            x[u].push_back(v);
            x[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            a.clear();
            a.resize(100, 1);
            dfs(i, 1);
            if (ok)
            {
                cout << 1 << endl;
                break;
            }
        }
        if (!ok)
            cout << 0 << endl;
    }
}
 

// File: DSA09030 - ĐỒ THỊ HAI PHÍA.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, u, v, ok;
vector<int> check;
vector<vector<int>> a;
void dfs(int u)
{
    for (auto v : a[u])
    {
        if (check[u] == check[v])
        {
            ok = 0;
            return;
        }
        else if (!check[v])
        {
            check[v] = 3 - check[u];
            dfs(v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ok = 1;
        a.clear();
        a.resize(n + 1);
        check.clear();
        check.resize(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!check[i])
            {
                check[i] = 1;
                dfs(i);
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA09032 - KẾT BẠN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int a[100005], t[100005];
int find(int u)
{
    if (t[u] == u)
        return u;
    t[u] = find(t[u]);
    return t[u];
}
void merge(int u, int v)
{
    int pu = find(u);
    int pv = find(v);
    if (pu == pv)
        return;
    else
        t[pu] = pv;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            a[i] = 0;
            t[i] = i;
        }
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            merge(x, y);
        }
        for (int i = 1; i <= n; i++)
        {
            t[i] = find(t[i]);
            a[t[i]]++;
        }
        cout << *max_element(a + 1, a + n + 1) << endl;
    }
}
 

// File: DSA09033 - MẠNG XÃ HỘI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y, ok = 1;
        cin >> n >> m;
        vector<vector<int>> a(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
        {
            for (auto x : a[i])
            {
                if (a[i].size() != a[x].size())
                {
                    ok = 0;
                    cout << "NO" << endl;
                    break;
                }
            }
            if (!ok)
                break;
        }
        if (ok)
            cout << "YES" << endl;
    }
}
 

// File: DSA09034 - ĐẾM SỐ AO.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, dx, dy, s = 0;
char a[105][105];
int rx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int ry[] = {1, 0, -1, 1, -1, 0, 1, -1};
void dfs(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        dx = x + rx[i];
        dy = y + ry[i];
        if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && a[dx][dy] == 'W')
        {
            a[dx][dy] = '.';
            dfs(dx, dy);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin.ignore(0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 'W')
            {
                a[i][j] = '.';
                dfs(i, j);
                s++;
            }
        }
    }
    cout << s;
}

// File: DSA09037 - HỌP MẶT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k, n, m, u, v, s = 0;
    cin >> k >> n >> m;
    vector<vector<int>> a(n + 1);
    int b[k];
    vector<int> c(n + 1, 0);
    for (int i = 0; i < k; i++)
        cin >> b[i];
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
    }
    for (int i = 0; i < k; i++)
    {
        queue<int> q;
        int check[n + 1] = {};
        q.push(b[i]);
        check[b[i]] = 1;
        while (q.size())
        {
            u = q.front();
            c[u]++;
            q.pop();
            for (auto v : a[u])
            {
                if (!check[v])
                {
                    q.push(v);
                    check[v] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (c[i] == k)
            s++;
    cout << s;
}
 

// File: DSA10001 - TÌM ĐƯỜNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int gx[] = {1, -1, 0, 0};
int gy[] = {0, 0, 1, -1};
int gh[] = {1, 2, 3, 4};
struct point
{
    int x, y, h, s;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, ok = 0;
        cin >> n >> m;
        cin.ignore();
        char a[n + 1][m + 1];
        point st, ed, k;
        queue<point> q;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 'S')
                {
                    st.x = i;
                    st.y = j;
                }
                else if (a[i][j] == 'T')
                {
                    ed.x = i;
                    ed.y = j;
                }
            }
        }
        k = st;
        k.s = 0;
        for (int i = 0; i < 4; i++)
        {
            k.x += gx[i];
            k.y += gy[i];
            k.h = gh[i];
            if (k.x >= 1 && k.x <= n && k.y >= 1 && k.y <= m && a[k.x][k.y] == '.')
                q.push(k);
            k.x -= gx[i];
            k.y -= gy[i];
        }
        while (q.size())
        {
            st = q.front();
            q.pop();
            if (st.x == ed.x && st.y == ed.y)
            {
                ok = 1;
                break;
            }
            k = st;
            for (int i = 0; i < 4; i++)
            {
                k.h = st.h;
                k.s = st.s;
                k.x += gx[i];
                k.y += gy[i];
                if (st.h != gh[i])
                {
                    k.h = gh[i];
                    k.s++;
                }
                if (k.x >= 1 && k.x <= n && k.y >= 1 && k.y <= m && k.s <= 2 && a[k.x][k.y] != '*')
                    q.push(k);
                k.x -= gx[i];
                k.y -= gy[i];
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA10003 - KIỂM TRA CHU TRÌNH SỬ DỤNG DISJOIN SET.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, x, y, ok;
vector<int> svs;
vector<bool> check;
vector<vector<int>> a;
void BFS(int k)
{
    check[k] = 0;
    for (auto i : a[k])
    {
        if (check[i])
        {
            svs[i] = k;
            BFS(i);
        }
        else if (i != svs[k])
        {
            ok = 1;
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ok = 0;
        a.clear();
        svs.clear();
        check.clear();
        a.resize(n + 1);
        svs.resize(n + 1, -1);
        check.resize(n + 1, 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
            if (check[i] && !ok)
                BFS(i);
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA10004 - ĐƯỜNG ĐI VÀ CHU TRÌNH EULER VỚI ĐỒ THỊ VÔ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, v, s = 0;
        cin >> n >> m;
        vector<vector<int>> a(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
            if (a[i].size() % 2 == 0)
                s++;
        if (s == n)
            cout << 2 << '\n';
        else if (s == n - 2)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}
 

// File: DSA10005 - CHU TRÌNH EULER TRONG ĐỒ THỊ CÓ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, v, ok = 1;
        cin >> n >> m;
        int a[n + 1] = {};
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            a[u]++;
            a[v]--;
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != 0)
            {
                ok = 0;
                cout << 0 << endl;
                break;
            }
        }
        if (ok)
            cout << 1 << endl;
    }
}
 

// File: DSA10006 - CÂY KHUNG CỦA ĐỒ THỊ THEO THUẬT TOÁN DFS.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, x, y;
        cin >> n >> m >> u;
        vector<pair<int, int>> v;
        vector<vector<int>> a(n + 1);
        vector<int> check(n + 1, 0);
        for (int i = 1; i <= m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        stack<int> st;
        st.push(u);
        check[u] = 1;
        while (st.size())
        {
            u = st.top();
            st.pop();
            for (auto i : a[u])
            {
                if (!check[i])
                {
                    check[i] = 1;
                    v.push_back({u, i});
                    st.push(u);
                    st.push(i);
                    break;
                }
            }
        }
        if (v.size() == n - 1)
            for (auto i : v)
                cout << i.first << " " << i.second << endl;
        else
            cout << "-1" << endl;
    }
}
 

// File: DSA10007 - CÂY KHUNG CỦA ĐỒ THỊ THEO THUẬT TOÁN BFS.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, x, y;
        cin >> n >> m >> u;
        vector<pair<int, int>> v;
        vector<vector<int>> a(n + 1);
        vector<int> check(n + 1, 0);
        for (int i = 1; i <= m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        queue<int> q;
        q.push(u);
        check[u] = 1;
        while (q.size())
        {
            u = q.front();
            q.pop();
            for (auto i : a[u])
            {
                if (!check[i])
                {
                    check[i] = 1;
                    q.push(i);
                    v.push_back({u, i});
                }
            }
        }
        if (v.size() == n - 1)
            for (auto i : v)
                cout << i.first << " " << i.second << endl;
        else
            cout << "-1" << endl;
    }
}
 

// File: DSA10011 - DI CHUYỂN TRÊN BẢNG SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
	int x, y, s;
};
struct cmp
{
	bool operator()(struct data a, struct data b)
	{
		return a.s > b.s;
	}
};
int rx[] = {1, -1, 0, 0};
int ry[] = {0, 0, 1, -1};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int a[n + 1][m + 1], check[n + 1][m + 1] = {};
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				cin >> a[i][j];
		}
		struct data u, v;
		priority_queue<struct data, vector<struct data>, cmp> q;
		q.push({1, 1, a[1][1]});
		while (q.size())
		{
			u = q.top();
			q.pop();
			if (u.x == n && u.y == m)
			{
				cout << u.s << endl;
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				v.x = u.x + rx[i];
				v.y = u.y + ry[i];
				v.s = u.s + a[v.x][v.y];
				if (v.x >= 1 && v.x <= n && v.y >= 1 && v.y <= m && !check[v.x][v.y])
				{
					check[v.x][v.y] = 1;
					q.push(v);
				}
			}
		}
	}
}
 

// File: DSA11001 - CÂY BIỂU THỨC 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool Var(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, k;
        cin >> s;
        stack<string> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (Var(s[i]))
                st.push(string(1, s[i]));
            else
            {
                k = st.top();
                st.pop();
                k = s[i] + k;
                k = st.top() + k;
                st.pop();
                st.push(k);
            }
        }
        cout << st.top() << endl;
    }
}
 

// File: DSA11002 - CÂY BIỂU THỨC 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool Op(string s)
{
    if (s == "+" || s == "-" || s == "*" || s == "/")
        return 1;
    return 0;
}
int so(string s)
{
    int n = 0;
    for (int i = 0; i < s.length(); i++)
        n = n * 10 + s[i] - '0';
    return n;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y, k;
        cin >> n;
        cin.ignore();
        string s, a;
        getline(cin, s);
        queue<int> st;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                if (a.size() > 0)
                    st.push(so(a));
                a = "";
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9')
            {
                a = s[i] + a;
                continue;
            }
            x = st.front();
            st.pop();
            y = st.front();
            st.pop();
            if (s[i] == '*')
                k = y * x;
            if (s[i] == '/')
                k = y / x;
            if (s[i] == '+')
                k = y + x;
            if (s[i] == '-')
                k = y - x;
            st.push(k);
        }
        cout << st.front() << endl;
    }
}
 

// File: DSA11003 - DUYỆT CÂY 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int find(int n, int x, int in[])
{
    for (int i = 0; i < n; i++)
        if (in[i] == x)
            return i;
    return -1;
}
void Try(int n, int in[], int pre[])
{
    int k = find(n, pre[0], in);
    if (k != 0)
        Try(k, in, pre + 1);
    if (k != n - 1)
        Try(n - k - 1, in + k + 1, pre + k + 1);
    cout << pre[0] << " ";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int in[n], pre[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> pre[i];
        Try(n, in, pre);
        cout << endl;
    }
}
 

// File: DSA11005 - DUYỆT CÂY 2.cpp
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node
{
    int val;
    Node *left, *right;
};
Node *createNode(int x)
{
    Node *k = new Node;
    k->val = x;
    k->left = k->right = NULL;
    return k;
}
Node *buildTree(int n, int *inorder, int *levelorder, int st, int e)
{
    if (n > 0)
    {
        Node *root = createNode(levelorder[0]);
        int idx = -1;
        unordered_map<int, int> m;
        for (int i = st; i <= e; ++i)
        {
            if (inorder[i] == levelorder[0])
            {
                idx = i;
                break;
            }
            m[inorder[i]]++;
        }
        int L[m.size()], R[e - st - m.size()], l, r;
        l = r = 0;
        for (int i = 1; i < n; ++i)
        {
            if (m[levelorder[i]])
                L[l++] = levelorder[i];
            else
                R[r++] = levelorder[i];
        }
        root->left = buildTree(idx - st, inorder, L, st, idx - 1);
        root->right = buildTree(e - idx, inorder, R, idx + 1, e);
        return root;
    }
    return NULL;
}
void postOrder(Node *root)
{
    if (root->left != NULL)
        postOrder(root->left);
    if (root->right != NULL)
        postOrder(root->right);
    cout << root->val << ' ';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int inorder[n], levelorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> levelorder[i];
        Node *root = buildTree(n, inorder, levelorder, 0, n - 1);
        postOrder(root);
        cout << endl;
    }
}

// File: DSAKT012 - ĐỔI TIỀN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, k, a[35], b[35], ss, mi, ok;
void Try(int x)
{
    for (int i = b[x - 1] + 1; i <= n; i++)
    {
        b[x] = i;
        if (x == k)
        {
            int s = 0;
            for (int j = 1; j <= k; j++)
                s += a[b[j]];
            if (s == ss)
            {
                ok = 1;
                mi = k;
                return;
            }
        }
        else
            Try(x + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    a[0] = ok = 0;
    mi = 50;
    cin >> n >> ss;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        k = i;
        Try(1);
        if (ok == 1)
            break;
    }
    if (ok == 0)
        cout << -1;
    else
        cout << mi;
}
 

// File: DSAKT053 - SỐ NGUYÊN LỚN.cpp
#include <bits/stdc++.h>
using namespace std;
int LCS(string s1, string s2)
{
    int F[s1.size() + 1][s2.size() + 1] = {};
    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            if (s1[i] == s2[j])
                F[i + 1][j + 1] = F[i][j] + 1;
            else
                F[i + 1][j + 1] = max(F[i][j + 1], F[i + 1][j]);
        }
    }
    return F[s1.size()][s2.size()];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        cout << LCS(a, b) << endl;
    }
}
 

// File: DSAKT055 - BÀI TOÁN CÁI TÚI 0-1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int a[n], b[n];
		vector<vector<int>> l(n, vector<int>(m + 1, 0));
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		for (int i = 0; i < n; i++)
			for (int j = 1; j <= m; j++)
			{
				if (i > 0)
				{
					if (a[i] <= j)
						l[i][j] = max(l[i - 1][j], l[i - 1][j - a[i]] + b[i]);
					else
						l[i][j] = l[i - 1][j];
				}
				else if (a[i] <= j)
					l[i][j] = b[i];
			}
		cout << l[n - 1][m] << endl;
	}
}
 

// File: DSAKT110 - NHÀ KHÔNG KỀ NHAU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 3], f[n + 3] = {};
        for (int i = 3; i <= n + 2; i++)
        {
            cin >> a[i];
            f[i] = max(f[i - 2], f[i - 3]) + a[i];
        }
        cout << max(f[n + 2], f[n + 1]) << endl;
    }
}
 

// File: DÃY CON CÓ K PHẦN TỬ TĂNG DẦN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[k + 1], b[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= k; i++)
            a[i] = i;
        while (1)
        {
            for (int i = 1; i <= k; i++)
                cout << b[a[i]] << " ";
            cout << endl;
            int ok = 0;
            for (int i = k; i >= 1; i--)
            {
                if (a[i] != n - k + i)
                {
                    ok = 1;
                    a[i]++;
                    for (int j = i + 1; j <= k; j++)
                        a[j] = a[j - 1] + 1;
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        cout << endl;
    }
}
 

// File: DÃY CON CÓ TỔNG BẰNG S.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, ans = 1e9;
long long s, a[35];
void Try(int pos, int m, long long d)
{
    if (d == s)
    {
        ans = min(ans, m);
        return;
    }
    for (int i = pos + 1; i <= n; i++)
        if (d + a[i] <= s && m < ans)
            Try(i, m + 1, d + a[i]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Try(0, 0, 0);
    if (ans == 1e9)
        cout << -1;
    else
        cout << ans;
}
 

// File: DÃY CON CÓ TỔNG LẺ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[20];
vector<int> x;
vector<vector<int>> ans;
map<vector<int>, int> m;
void Try(int k, int s)
{
    for (int i = k + 1; i <= n; i++)
    {
        Try(i, s);
        x.push_back(a[i]);
        if ((s + a[i]) % 2 == 1)
        {
            if (m[x] == 0)
            {
                m[x]++;
                ans.push_back(x);
            }
        }
        Try(i, s + a[i]);
        x.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        m.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        Try(0, 0);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
}
 

// File: DÃY CON CÓ TỔNG NGUYÊN TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[20];
vector<int> x;
vector<vector<int>> ans;
map<vector<int>, int> m;
bool nto(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}
void Try(int k, int s)
{
    for (int i = k + 1; i <= n; i++)
    {
        Try(i, s);
        x.push_back(a[i]);
        if (nto(s + a[i]))
        {
            if (m[x] == 0)
            {
                m[x]++;
                ans.push_back(x);
            }
        }
        Try(i, s + a[i]);
        x.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        m.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        Try(0, 0);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
}
 

// File: DÃY CON LIÊN TIẾP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n], m = 0, s = 0, ans = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m = max(m, a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == m)
            s++;
        else
            s = 0;
        ans = max(ans, s);
    }
    cout << ans;
}
 

// File: DÃY CON TĂNG DẦN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[25];
string k;
vector<int> x;
vector<string> v;
vector<vector<int>> ans;
void Try(int posa)
{
    for (int i = posa + 1; i <= n; i++)
    {
        if (a[i] > a[posa])
        {
            x.push_back(a[i]);
            if (x.size() > 1)
                ans.push_back(x);
            Try(i);
            x.erase(x.end() - 1, x.end());
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Try(0);
    for (int i = 0; i < ans.size(); i++)
    {
        k = "";
        for (int j = 0; j < ans[i].size(); j++)
        {
            k += to_string(ans[i][j]);
            k += " ";
        }
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}
 

// File: DÃY SỐ ĐẸP.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b, c, k, ans = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 1; i < n; i++)
        {
            b = min(a[i], a[i - 1]);
            c = max(a[i], a[i - 1]);
            k = log2(c / b);
            if (pow(2, k) * b == c && k > 0)
                k--;
            ans += k;
        }
        cout << ans << endl;
    }
}

// File: GHÉP CHỮ CÁI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[100];
bool check()
{
    for (int i = 2; i <= n - 1; i++)
        if ((a[i] == 1 || a[i] == 5) && 
        (a[i - 1] != 1 && a[i - 1] != 5) && 
        (a[i + 1] != 1 && a[i + 1] != 5))
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char c;
    cin >> c;
    n = c - 'A' + 1;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    while (1)
    {
        if (check())
        {
            for (int i = 1; i <= n; i++)
                cout << (char)(a[i] + 'A' - 1);
            cout << endl;
        }
        int ok = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a + i + 1, a + n + 1);
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > a[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (ok == 0)
            break;
    }
}
 

// File: HOÁN VỊ CÁC CHỮ SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int to_int(string s)
{
    int a = 0;
    for (int i = 0; i < s.size(); i++)
    {
        a = a * 10 + s[i] - '0';
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    int a[n + 1], MIN = 1e9;
    vector<string> b(m);
    vector<string> c;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        b[i] = "0" + b[i];
    }
    for (int i = 1; i <= n; i++)
        a[i] = i;
    while (1)
    {
        c.clear();
        for (int i = 0; i < m; i++)
        {
            string x = b[i];
            for (int j = 1; j <= n; j++)
                x[j] = b[i][a[j]];
            c.push_back(x);
        }
        sort(c.begin(), c.end());
        MIN = min(MIN, to_int(c[c.size() - 1]) - to_int(c[0]));
        int ok = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a + i + 1, a + n + 1);
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > a[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (ok == 0)
            break;
    }
    cout << MIN;
}
 

// File: HOÁN VỊ DÃY SỐ.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
        cin >> b[i];
    }
    sort(b + 1, b + n + 1);
    while (1)
    {
        for (int i = 1; i <= n; i++)
            cout << b[a[i]] << " ";
        cout << endl;
        int ok = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a + i + 1, a + n + 1);
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > a[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (ok == 0)
            break;
    }
}
 

// File: HOÁN VỊ NGƯỢC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<vector<int>> b;
        for (int i = 1; i <= n; i++)
            a[i] = i;
        while (1)
        {
            b.push_back(a);
            int ok = 0;
            for (int i = n - 1; i >= 1; i--)
            {
                if (a[i] < a[i + 1])
                {
                    ok = 1;
                    sort(a.begin() + i + 1, a.end());
                    for (int j = i + 1; j <= n; j++)
                        if (a[j] > a[i])
                        {
                            swap(a[i], a[j]);
                            break;
                        }
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        for(int i=1;i<=n;i++) cout<<b[b.size()-1][i];
        for(int i=b.size()-2;i>=0;i--){
        	cout<<",";
        	for(int j=1;j<=n;j++) cout<<b[i][j];
		}
		cout<<endl;
    }
}
 

// File: LIỆT KÊ TỔ HỢP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, x;
    cin >> n >> k;
    int a[k + 1];
    vector<int> b;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        m[x]++;
    }
    b.push_back(0);
    for (auto i : m)
        b.push_back(i.first);
    n = b.size() - 1;
    for (int i = 1; i <= k; i++)
        a[i] = i;
    while (1)
    {
        for (int i = 1; i <= k; i++)
            cout << b[a[i]] << " ";
        cout << endl;
        int ok = 0;
        for (int i = k; i >= 1; i--)
        {
            if (a[i] != n - k + i)
            {
                ok = 1;
                a[i]++;
                for (int j = i + 1; j <= k; j++)
                    a[j] = a[j - 1] + 1;
                break;
            }
        }
        if (ok == 0)
            break;
    }
}
 

// File: LIỆT KÊ XÂU KÝ TỰ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char c;
    int n, k;
    cin >> c >> k;
    n = c - 'A' + 1;
    int a[k + 1];
    for (int i = 1; i <= k; i++)
        a[i] = 1;
    while (1)
    {
        for (int i = 1; i <= k; i++)
            cout << (char)('A' + a[i] - 1);
        cout << endl;
        int ok = 0;
        for (int i = k; i >= 1; i--)
        {
            if (a[i] != n)
            {
                ok = 1;
                a[i]++;
                for (int j = i + 1; j <= k; j++)
                    a[j] = a[i];
                break;
            }
        }
        if (ok == 0)
            break;
    }
}
 

// File: LŨY THỪA MA TRẬN 4.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    long long x[10][10];
};
int n;
long long mod = 1000000007;
struct data operator*(struct data a, struct data b)
{
    struct data xx;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            xx.x[i][j] = 0;
            for (int k = 0; k < n; k++)
                xx.x[i][j] = (xx.x[i][j] + (a.x[i][k] * b.x[k][j]) % mod) % mod;
        }
    }
    return xx;
};
struct data poww(struct data a, long long k)
{
    if (k == 1)
        return a;
    if (k % 2 == 1)
        return a * poww(a, k - 1);
    struct data xx = poww(a, k / 2);
    return xx * xx;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long k, s = 0;
        cin >> n >> k;
        struct data a;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a.x[i][j];
        a = poww(a, k);
        for (int i = 0; i < n; i++)
        {
            s += a.x[0][i];
            s %= mod;
        }
        cout << s << endl;
    }
}
 

// File: LŨY THỪA MA TRẬN 5.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    long long x[10][10];
};
int n;
long long mod = 1000000007;
struct data operator*(struct data a, struct data b)
{
    struct data xx;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            xx.x[i][j] = 0;
            for (int k = 0; k < n; k++)
                xx.x[i][j] = (xx.x[i][j] + (a.x[i][k] * b.x[k][j]) % mod) % mod;
        }
    }
    return xx;
};
struct data poww(struct data a, long long k)
{
    if (k == 1)
        return a;
    if (k % 2 == 1)
        return a * poww(a, k - 1);
    struct data xx = poww(a, k / 2);
    return xx * xx;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long k, s = 0;
        cin >> n >> k;
        struct data a;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a.x[i][j];
        a = poww(a, k);
        for (int i = 0; i < n; i++)
        {
            s += a.x[n - 1][i];
            s %= mod;
        }
        cout << s << endl;
    }
}
 

// File: LŨY THỪA MA TRẬN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    long long x[10][10];
};
int n;
long long mod = 1000000007;
struct data operator*(struct data a, struct data b)
{
    struct data xx;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            xx.x[i][j] = 0;
            for (int k = 0; k < n; k++)
                xx.x[i][j] = (xx.x[i][j] + (a.x[i][k] * b.x[k][j]) % mod) % mod;
        }
    }
    return xx;
};
struct data poww(struct data a, long long k)
{
    if (k == 1)
        return a;
    if (k % 2 == 1)
        return a * poww(a, k - 1);
    struct data xx = poww(a, k / 2);
    return xx * xx;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long k, s = 0;
        cin >> n >> k;
        struct data a;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a.x[i][j];
        a = poww(a, k);
        for (int i = 0; i < n; i++)
        {
            s += a.x[n - i - 1][i];
            s %= mod;
        }
        cout << s << endl;
    }
}
 

// File: MIN VÀ MAX.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long s = 0;
    cin >> n;
    vector<int> a(n), l(n), r(n);
    stack<int> b, c;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        while (!b.empty() && a[i] <= a[b.top()])
            b.pop();
        if (b.empty())
            l[i] = 0;
        else
            l[i] = b.top() + 1;
        b.push(i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!c.empty() && a[i] <= a[c.top()])
            c.pop();
        if (c.empty())
            r[i] = n - 1;
        else
            r[i] = c.top() - 1;
        c.push(i);
    }
    for (int i = 0; i < n; i++)
        s = max(s, (long long)a[i] * (r[i] - l[i] + 1));
    cout << s;
}
 

// File: MÃ SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<vector<int>> v1, v2;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
        b[i] = 1;
    }
    while (1)
    {
        v1.push_back(a);
        int ok = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a.begin() + i + 1, a.end());
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > a[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (ok == 0)
            break;
    }
    while (1)
    {
        v2.push_back(b);
        int ok = 0;
        for (int i = n; i >= 1; i--)
        {
            if (b[i] != n)
            {
                ok = 1;
                b[i]++;
                for (int j = i + 1; j <= n; j++)
                    b[j] = 1;
                break;
            }
        }
        if (ok == 0)
            break;
    }
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v2.size(); j++)
        {
            for (int k = 1; k <= n; k++)
                cout << (char)(v1[i][k] + 'A' - 1);
            for (int k = 1; k <= n; k++)
                cout << v2[j][k];
            cout << endl;
        }
    }
}
 

// File: NGƯỜI DU LỊCH.cpp
#include <bits/stdc++.h>
using namespace std;
int n, a[20], b[20], c[20][20], ans = 1e9, s = 0;
vector<int> as;
void Try(int x, vector<int> k)
{
    for (int i = 2; i <= n; i++)
    {
        if (!b[i])
        {
            a[x] = i;
            b[i]++;
            s += c[a[x - 1]][i];
            k.push_back(i);
            if (x == n && s + c[i][1] < ans)
            {
                ans = s + c[i][1];
                as = k;
            }
            else if (s < ans && x < n)
                Try(x + 1, k);
            s -= c[a[x - 1]][i];
            b[i]--;
            k.pop_back();
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
        }
    }
    a[1] = b[1] = 1;
    as.push_back(1);
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    Try(2, as);
    cout << "(";
    for (auto i : as)
        cout << i << ",";
    cout << 1 << ")" << endl;
    cout << ans;
}

// File: PHÁT LỘC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
void Try(string s)
{
    int k = s.size();
    if (n == k)
    {
        if (s[n - 1] == '6')
            cout << s << endl;
        return;
    }
    if (s[k - 1] == '8')
        Try(s + "6");
    else
    {
        if (k < 4)
            Try(s + "6");
        else if (s[k - 2] == '8' || s[k - 3] == '8')
            Try(s + "6");
        Try(s + "8");
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    Try("8");
}
 

// File: PHẦN TỬ LỚN NHẤT TRONG DÃY CON.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        deque<int> d;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            while (d.size() && a[d.back()] <= a[i])
                d.pop_back();
            d.push_back(i);
            while (d.size() && d.front() <= i - k)
                d.pop_front();
            if (i >= k - 1)
                cout << a[d.front()] << " ";
        }
        cout << endl;
    }
}
 

// File: PTIT125D - Di chuyển ăn cỏ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, u, v, ans, a[6][6];
int rx[] = { 1, -1, 0, 0 };
int ry[] = { 0, 0, 1, -1 };
void Try(int x, int y, int s) {
	if (x == 5 && y == 5 && s + n == 25) {
		ans++;
		return;
	}
	for (int i = 0;i < 4;i++) {
		int xx = x + rx[i];
		int yy = y + ry[i];
		if (xx >= 1 && xx <= 5 && yy >= 1 && yy <= 5 && a[xx][yy] == 0) {
			a[xx][yy] = 1;
			Try(xx, yy, s + 1);
			a[xx][yy] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	a[1][1] = 1;
	for (int i = 0;i < n;i++) {
		cin >> u >> v;
		a[u][v] = 1;
	}
	Try(1, 1, 1);
	cout << ans;
}
 

// File: QUÂN VUA TRÊN BÀN CỜ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    int x, y, s;
};
int rx[] = {1, 1, -1, -1, 0, 0, 1, -1};
int ry[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    struct data u, v, ed;
    queue<struct data> q;
    int check[9][9] = {};
    cin >> u.x >> u.y >> ed.x >> ed.y;
    u.s = 0;
    q.push(u);
    while (q.size())
    {
        u = q.front();
        q.pop();
        if (u.x == ed.x && u.y == ed.y)
        {
            cout << u.s;
            return 0;
        }
        v.s = u.s + 1;
        for (int i = 0; i < 8; i++)
        {
            v.x = u.x + rx[i];
            v.y = u.y + ry[i];
            if (v.x >= 1 && v.x <= 8 && v.y >= 1 && v.y <= 8 && !check[v.x][v.y])
            {
                check[v.x][v.y]++;
                q.push(v);
            }
        }
    }
}
 

// File: SẮP XẾP CHẴN LẺ.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, posl = 0, posc = 0;
    cin >> n;
    vector<int> pl, l, c;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x % 2 == 1)
        {
            l.push_back(x);
            pl.push_back(i);
        }
        else
            c.push_back(x);
    }
    sort(c.begin(), c.end());
    sort(l.begin(), l.end(), greater<int>());
    for (int i = 0; i < n; i++)
    {
        if (posl < pl.size() && i == pl[posl])
            cout << l[posl++] << " ";
        else
            cout << c[posc++] << " ";
    }
}

// File: SẮP XẾP QUÂN HẬU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n = 8, ans;
int c1[20], c2[20], c3[20], a[10][10];
void Try(int x, int s)
{
    if (x == n + 1)
    {
        ans = max(ans, s);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (c1[i] == 0 && c2[i + x] == 0 && c3[x - i + n] == 0)
        {
            c1[i] = c2[i + x] = c3[x - i + n] = 1;
            Try(x + 1, s + a[x][i]);
            c1[i] = c2[i + x] = c3[x - i + n] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        ans = 0;
        for (int i = 0; i < 20; i++)
            c1[i] = c2[i] = c3[i] = 0;
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
                cin >> a[i][j];
        }
        Try(1, 0);
        cout << "Test " << k << ": " << ans << endl;
    }
}
 

// File: SỐ 2 ƯU THẾ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool check(string s)
{
    int d = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '2')
            d++;
    if (d > s.size() / 2)
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string u, v;
    vector<string> a;
    queue<string> q;
    q.push("1");
    q.push("2");
    a.push_back("2");
    while (q.size())
    {
        u = q.front();
        q.pop();
        if (check(u))
            a.push_back(u);
        if (a.size() == 1005)
            break;
        q.push(u + '0');
        q.push(u + '1');
        q.push(u + '2');
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}
 

// File: SỐ CẶP BẠN TỐT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, ans = 0;
    cin >> n >> k;
    vector<string> s(n + 1);
    vector<vector<int>> f(n + 1, vector<int>(30, 0));
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        f[i] = f[i - 1];
        f[i][s[i].size()]++;
    }
    for (int i = 1; i <= n; i++)
        ans += f[i - 1][s[i].size()] - f[max(i - k - 1, 0)][s[i].size()];
    cout << ans;
}
 

// File: SỐ LỘC PHÁT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, s = 0;
        cin >> n;
        queue<string> dq;
        dq.push("6");
        dq.push("8");
        cout << pow(2, n) << endl;
        while (dq.size())
        {
            string k = dq.front();
            if (k.size() == n)
                cout << k << " ";
            dq.pop();
            if (k.size() != n)
            {
                dq.push(k + "6");
                dq.push(k + "8");
            }
        }
        cout << endl;
    }
}
 

// File: SỐ THỨ TỰ HOÁN VỊ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[10], b[10];
bool check()
{
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int p = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            a[i] = i;
            cin >> b[i];
        }
        while (++p)
        {
            if (check())
            {
                cout << p << endl;
                break;
            }
            for (int i = n - 1; i >= 1; i--)
            {
                if (a[i] < a[i + 1])
                {
                    sort(a + i + 1, a + n + 1);
                    for (int j = i + 1; j <= n; j++)
                    {
                        if (a[j] > a[i])
                        {
                            swap(a[i], a[j]);
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
}
 

// File: SỐ THỨ TỰ TỔ HỢP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, k, a[15], b[15];
bool check()
{
    for (int i = 1; i <= k; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int p = 0;
        cin >> n >> k;
        for (int i = 1; i <= k; i++)
        {
            a[i] = i;
            cin >> b[i];
        }
        while (++p)
        {
            if (check())
            {
                cout << p << endl;
                break;
            }
            for (int i = k; i >= 1; i--)
            {
                if (a[i] != n - k + i)
                {
                    a[i]++;
                    for (int j = i + 1; j <= k; j++)
                        a[j] = a[j - 1] + 1;
                    break;
                }
            }
        }
    }
}
 

// File: SỐ XA CÁCH.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, check[15];
void Try(string s)
{
    int k = s.size();
    if (k == n)
        cout << s << endl;
    for (int i = 1; i <= n; i++)
        if (k == 0 || (!check[i] && abs(s[k - 1] - '0' - i) != 1))
        {
            check[i] = 1;
            Try(s + to_string(i));
            check[i] = 0;
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        Try("");
    }
}
 

// File: THI ĐẤU ĐỐI KHÁNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    long long a[n + 1], b[m + 1], f[n + 1][m + 1][k + 1] = {}, mod = 1e9 + 9;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] > b[j])
                f[i][j][1] = 1;
            else
                f[i][j][1] = 0;
        }
    }
    for (int p = 1; p <= k; p++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                f[i][j][p] += f[i - 1][j][p] + f[i][j - 1][p] - f[i - 1][j - 1][p];
                if (a[i] > b[j])
                    f[i][j][p] += f[i - 1][j - 1][p - 1];
                f[i][j][p] %= mod;
            }
        }
    }
    while (f[n][m][k] < 0)
        f[n][m][k] += mod;
    cout << f[n][m][k];
}
 

// File: THÁP HÀ NỘI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void Tower(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << a << " -> " << c << endl;
        return;
    }
    Tower(n - 1, a, c, b);
    Tower(1, a, b, c);
    Tower(n - 1, b, a, c);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char a = 'A', b = 'B', c = 'C';
    int n;
    cin >> n;
    Tower(n, a, b, c);
}
 

// File: TN05009 - CHU TRÌNH THEO DFS.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, v, ok = 0;
        cin >> n >> m;
        vector<int> ans;
        vector<int> check(n + 1);
        vector<int> pre(n + 1, 0);
        vector<vector<int>> a(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
            sort(a[i].begin(), a[i].end());
        stack<int> st;
        st.push(1);
        check[1] = 1;
        while (st.size())
        {
            u = st.top();
            st.pop();
            for (auto i : a[u])
            {
                if (i == 1 && pre[u] != 1)
                {
                    ok = u;
                    break;
                }
                if (!check[i])
                {
                    pre[i] = u;
                    check[i] = 1;
                    st.push(u);
                    st.push(i);
                    break;
                }
            }
            if (ok)
                break;
        }
        if (ok)
        {
            while (pre[ok])
            {
                ans.push_back(ok);
                ok = pre[ok];
            }
            cout << 1 << " ";
            for (int i = ans.size() - 1; i >= 0; i--)
                cout << ans[i] << " ";
            cout << 1;
        }
        else
            cout << "NO";
        cout << endl;
    }
}
 

// File: TRÒ CHƠI CARO “NGANG”.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
char c;
int n;
string s;
bool check()
{
    int dc = 0, dd = 0, fc = 0, fd = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == c)
        {
            dc++;
            dd = 0;
        }
        else
        {
            dc = 0;
            dd++;
        }
        fc = max(fc, dc);
        fd = max(fd, dd);
    }
    if (fc > fd && fc >= 5)
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> c;
        s = "";
        for (int i = 0; i < n; i++)
            s += 'O';
        while (1)
        {
            int ok = 0;
            if (check())
                cout << s << endl;
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] != 'X')
                {
                    ok = 1;
                    s[i] = 'X';
                    for (int j = i + 1; j < n; j++)
                        s[j] = 'O';
                    break;
                }
            }
            if (!ok)
                break;
        }
        cout << endl;
    }
}
 

// File: TRÒ CHƠI VỚI CÁC CON SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, check[15];
void Try(string s)
{
    int k = s.size();
    if (k == n)
        cout << s << endl;
    for (int i = 1; i <= n; i++)
        if (k == 0 || (!check[i] && abs(s[k - 1] - '0' - i) != 1))
        {
            check[i] = 1;
            Try(s + to_string(i));
            check[i] = 0;
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        Try("");
    }
}
 

// File: TÁCH NHÓM TỐI ƯU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, ans = 1;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 1; i < n; i++)
        if (a[i] > a[i - 1] + k)
            ans++;
    cout << ans;
}
 

// File: TÍCH CHỮ SỐ.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        stack<int> st;
        for (int i = 9; i >= 2; i--)
        {
            while (n % i == 0)
            {
                st.push(i);
                n /= i;
            }
        }
        if (n > 1)
            cout << -1 << endl;
        else
        {
            while (st.size())
            {
                cout << st.top();
                st.pop();
            }
            cout << endl;
        }
    }
}

// File: TỔ HỢP “NGƯỢC”.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(k + 1);
        vector<vector<int>> v;
        for (int i = 1; i <= k; i++)
            a[i] = i;
        while (1)
        {
            v.push_back(a);
            int ok = 0;
            for (int i = k; i >= 1; i--)
            {
                if (a[i] != n - k + i)
                {
                    ok = 1;
                    a[i]++;
                    for (int j = i + 1; j <= k; j++)
                        a[j] = a[j - 1] + 1;
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        for (int i = v.size() - 1; i >= 0; i--)
        {
            for (int j = 1; j <= k; j++)
                cout << v[i][j] << " ";
            cout << endl;
        }
    }
}
 

// File: TỔNG CÁC SỐ TỰ NHIÊN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<int> a;
vector<vector<int>> b;
void Try(int k, int pos)
{
    if (k == n)
        b.push_back(a);
    for (int i = pos; i >= 1; i--)
    {
        if (i + k <= n)
        {
            a.push_back(i);
            Try(i + k, i);
            a.pop_back();
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        b.clear();
        cin >> n;
        for (int i = n; i >= 1; i--)
        {
            a.push_back(i);
            Try(i, i);
            a.pop_back();
        }
        cout << b.size() << endl;
        for (int i = 0; i < b.size(); i++)
        {
            cout << "(" << b[i][0];
            for (int j = 1; j < b[i].size(); j++)
                cout << " " << b[i][j];
            cout << ") ";
        }
        cout << endl;
    }
}
 

// File: TỔNG ƯỚC SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> a(1000001, 1);
void era()
{
    for (int i = 2; i <= 1000000; i++)
    {
        for (int j = i * 2; j <= 1000000; j += i)
            a[j] += i;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    era();
    int l, r, s = 0;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
        if (a[i] > i)
            s++;
    cout << s;
}
 

// File: XÂU AB.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, d = 0;
        cin >> n;
        string a;
        for (int i = 0; i < n; i++)
            a += 'A';
        cout << a;
        while (1)
        {
            if (d != 0)
                cout << "," << a;
            d++;
            int ok = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (a[i] == 'A')
                {
                    ok = 1;
                    a[i] = 'B';
                    for (int j = i + 1; j < n; j++)
                        a[j] = 'A';
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        cout << endl;
    }
}
 

// File: XÂU CON NHỎ NHẤT.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size(), k = 0, st = 0, ans = 1e9, x = 0, a[256] = {};
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        map<char, int> m;
        for (int i = 0; i < n; i++)
        {
            if (!m[s[i]])
            {
                m[s[i]]++;
                k++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            a[s[i]]++;
            if (a[s[i]] == 1)
                x++;
            if (x == k)
            {
                while (a[s[st]] > 1)
                {
                    if (a[s[st]] > 1)
                        a[s[st]]--;
                    st++;
                }
                int l = i - st + 1;
                ans = min(ans, l);
            }
        }
        cout << ans << endl;
    }
}

// File: combined.cpp
// File: CHELLO - Hello World.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << "Hello PTIT.";
}
 

// File: CHÊNH LỆCH NHỎ NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int to_int(string s)
{
    int a = 0;
    for (int i = 0; i < s.size(); i++)
    {
        a = a * 10 + s[i] - '0';
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    int a[n + 1], MIN = 1e9;
    vector<string> b(m);
    vector<string> c;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        b[i] = "0" + b[i];
    }
    for (int i = 1; i <= n; i++)
        a[i] = i;
    while (1)
    {
        c.clear();
        for (int i = 0; i < m; i++)
        {
            string x = b[i];
            for (int j = 1; j <= n; j++)
                x[j] = b[i][a[j]];
            c.push_back(x);
        }
        sort(c.begin(), c.end());
        MIN = min(MIN, to_int(c[c.size() - 1]) - to_int(c[0]));
        int ok = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a + i + 1, a + n + 1);
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > a[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (ok == 0)
            break;
    }
    cout << MIN;
}
 

// File: CTDL_001 - THUẬT TOÁN SINH.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool thuannghich(string s)
{
    int n = s.size();
    for (int i = 0; i <= n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
            return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string a;
    for (int i = 0; i < n; i++)
        a += '0';
    while (1)
    {
        if (thuannghich(a))
        {
            for (int i = 0; i < a.size(); i++)
                cout << a[i] << " ";
            cout << endl;
        }
        int ok = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == '0')
            {
                ok = 1;
                a[i] = '1';
                for (int j = i + 1; j < n; j++)
                    a[j] = '0';
                break;
            }
        }
        if (ok == 0)
            break;
    }
}
 

// File: CTDL_002 - Tổng dãy con = K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, k;
vector<int> a, b;
vector<vector<int>> res;
void pb()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == 1)
            sum += b[i];
    if (sum == k)
        res.push_back(a);
}
void BackTrack(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        a[i] = j;
        if (i == n - 1)
            pb();
        else
            BackTrack(i + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    a.resize(n, 0);
    b.resize(n, 0);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    BackTrack(0);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            if (res[i][j] == 1)
                cout << b[j] << ' ';
        cout << endl;
    }
    cout << res.size();
}
 

// File: CTDL_003 - PHƯƠNG ÁN TỐI ƯU.cpp
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string ans;
vector<pair<int, int>> x;
vector<vector<int>> F;
void trace(int n, int k)
{
    if (n == 0)
        return;
    if (F[n][k] == F[n - 1][k])
        trace(n - 1, k);
    else
    {
        trace(n - 1, k - x[n].first);
        ans[n - 1] = '1';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    F.resize((n + 1), vector<int>(k + 1, 0));
    x.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ans = ans + "0";
        cin >> x[i].second;
    }
    for (int i = 1; i <= n; i++)
        cin >> x[i].first;
    for (int i = 0; i <= n; i++)
    {
        F[i][0] = 0;
        F[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
        {
            if (j < x[i].first)
                F[i][j] = F[i - 1][j];
            else
                F[i][j] = max(F[i - 1][j], F[i - 1][j - x[i].first] + x[i].second);
        }
    cout << F[n][k] << endl;
    trace(n, k);
    for (char i : ans)
        cout << i << ' ';
}
 

// File: CTDL_004 - DÃY CON TĂNG DẦN BẬC K.cpp
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, k, ans = 0;
int a[200], b[200];
void backtracking(int pos1, int pos2)
{
    if (pos2 == k)
    {
        ans++;
        return;
    }
    for (int i = pos1 + 1; i < n; i++)
    {
        if (a[i] > a[pos1])
        {
            b[pos2 + 1] = a[i];
            backtracking(i, pos2 + 1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        b[0] = a[i];
        backtracking(i, 1);
    }
    cout << ans;
}
 

// File: CTDL_005 - XÓA DỮ LIỆU TRONG DSLK ĐƠN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n], k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> k;
    for (int i = 0; i < n; i++)
        if (a[i] != k)
            cout << a[i] << " ";
}
 

// File: CTDL_006 - LỌC DỮ LIỆU TRÙNG TRONG DSLK ĐƠN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        m[x]++;
        if (m[x] == 1)
            cout << x << " ";
    }
}
 

// File: DI CHUYỂN TRONG MÊ CUNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[12][12];
vector<string> ans;
vector<pair<string, pair<int, int>>> p = {{"D", {1, 0}}, {"L", {0, -1}}, {"R", {0, 1}}, {"U", {-1, 0}}};
void Try(int i, int j, string s)
{
    if (i == n && j == n)
    {
        ans.push_back(s);
        return;
    }
    for (int k = 0; k < 4; k++)
    {
        int u = i + p[k].second.first;
        int v = j + p[k].second.second;
        if (u >= 1 && u <= n && v >= 1 && v <= n && a[u][v])
        {
            a[u][v] = 0;
            Try(u, v, s + p[k].first);
            a[u][v] = 1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        if (a[1][1] == 1)
        {
            a[1][1] = 0;
            Try(1, 1, "");
        }
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            cout << ans.size() << " ";
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
            cout << endl;
        }
    }
}
 

// File: DSA01001 - XÂU NHỊ PHÂN KẾ TIẾP.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        s = '0' + s;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                s[i] = '1';
                for (int j = i + 1; j < s.size(); j++)
                    s[j] = '0';
                break;
            }
        }
        for (int i = 1; i < s.size(); i++)
            cout << s[i];
        cout << endl;
    }
}
 

// File: DSA01002 - TẬP CON KẾ TIẾP.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[k + 1];
        for (int i = 1; i <= k; i++)
            cin >> a[i];
        a[0] = -1;
        for (int i = k; i >= 0; i--)
        {
            if (a[i] != n - k + i)
            {
                a[i]++;
                for (int j = i + 1; j <= k; j++)
                    a[j] = a[j - 1] + 1;
                break;
            }
        }
        for (int i = 1; i <= k; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}
 

// File: DSA01003 - HOÁN VỊ KẾ TIẾP.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ok = 0, a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a + i, a + n + 1);
                swap(a[i], a[i + 1]);
                break;
            }
        }
        if (ok == 0)
        {
            for (int i = 1; i <= n; i++)
                a[i] = i;
        }
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}
 

// File: DSA01004 - SINH TỔ HỢP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[k + 1];
		for (int i = 1; i <= k; i++)
			a[i] = i;
		while (1)
		{
			for (int i = 1; i <= k; i++)
				cout << a[i];
			cout << " ";
			int ok = 0;
			for (int i = k; i >= 1; i--)
			{
				if (a[i] != n - k + i)
				{
					ok = 1;
					a[i]++;
					for (int j = i + 1; j <= k; j++)
						a[j] = a[j - 1] + 1;
					break;
				}
			}
			if (ok == 0)
				break;
		}
		cout << endl;
	}
}
 

// File: DSA01005 - SINH HOÁN VỊ.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            a[i] = i;
        while (1)
        {
            for (int i = 1; i <= n; i++)
                cout << a[i];
            cout << " ";
            int ok = 0;
            for (int i = n - 1; i >= 1; i--)
            {
                if (a[i] < a[i + 1])
                {
                    ok = 1;
                    sort(a + i + 1, a + n + 1);
                    for (int j = i + 1; j <= n; j++)
                    {
                        if (a[j] > a[i])
                        {
                            swap(a[i], a[j]);
                            break;
                        }
                    }
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        cout << endl;
    }
}
 

// File: DSA01006 - HOÁN VỊ NGƯỢC.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            a[i] = i;
        stack<string> st;
        while (1)
        {
            string s = "";
            for (int i = 1; i <= n; i++)
                s += to_string(a[i]);
            st.push(s);
            int ok = 0;
            for (int i = n - 1; i >= 1; i--)
            {
                if (a[i] < a[i + 1])
                {
                    ok = 1;
                    sort(a + i + 1, a + n + 1);
                    for (int j = i + 1; j <= n; j++)
                    {
                        if (a[j] > a[i])
                        {
                            swap(a[i], a[j]);
                            break;
                        }
                    }
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        while (st.size())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
}
 

// File: DSA01007 - XÂU AB CÓ ĐỘ DÀI N.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a;
        for (int i = 0; i < n; i++)
            a += 'A';
        while (1)
        {
            cout << a << " ";
            int ok = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (a[i] == 'A')
                {
                    ok = 1;
                    a[i] = 'B';
                    for (int j = i + 1; j < n; j++)
                        a[j] = 'A';
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        cout << endl;
    }
}
 

// File: DSA01008 - XÂU NHỊ PHÂN CÓ K BIT 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[k];
        for (int i = 0; i < k; i++)
            a[i] = i;
        stack<string> st;
        while (1)
        {
            string s = "";
            for (int i = 0; i < n; i++)
                s += '0';
            for (int i = 0; i < k; i++)
                s[a[i]] = '1';
            st.push(s);
            int ok = 0;
            for (int i = k - 1; i >= 0; i--)
            {
                if (a[i] != n - k + i)
                {
                    ok = 1;
                    a[i]++;
                    for (int j = i + 1; j < k; j++)
                        a[j] = a[j - 1] + 1;
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        while (st.size())
        {
            cout << st.top() << endl;
            st.pop();
        }
    }
}
 

// File: DSA01009 - XÂU AB ĐẶC BIỆT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool check(string s, int n)
{
    s = 'B' + s + 'B';
    for (int i = 0; i < s.size() - n - 1; i++)
    {
        if (s[i] == 'B' && s[i + n + 1] == 'B')
        {
            int d = 0;
            for (int j = i + 1; j <= i + n; j++)
            {
                if (s[j] == 'A')
                    d++;
            }
            if (d == n)
                return 1;
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string a;
    queue<string> q;
    for (int i = 0; i < n; i++)
        a += 'A';
    while (1)
    {
        if (check(a, k))
            q.push(a);
        int ok = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == 'A')
            {
                ok = 1;
                a[i] = 'B';
                for (int j = i + 1; j < n; j++)
                    a[j] = 'A';
                break;
            }
        }
        if (ok == 0)
            break;
    }
    cout << q.size() << endl;
    while (q.size())
    {
        cout << q.front() << endl;
        q.pop();
    }
}
 

// File: DSA01010 - TẬP QUÂN SỰ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, s = 0, ok = 0;
        cin >> n >> k;
        int a[k + 1], b[k + 1];
        map<int, int> m;
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i];
            b[i] = a[i];
            m[a[i]]++;
        }
        for (int i = k; i >= 1; i--)
        {
            if (a[i] != n - k + i)
            {
                ok = 1;
                a[i]++;
                for (int j = i + 1; j <= k; j++)
                    a[j] = a[j - 1] + 1;
                break;
            }
        }
        for (int i = 1; i <= k; i++)
        {
            if (m[a[i]] == 0)
                s++;
        }
        if (ok == 0)
            s = k;
        cout << s << endl;
    }
}
 

// File: DSA01011 - HOÁN VỊ TIẾP THEO CỦA CHUỖI SỐ.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int test;
		string s;
		cin >> test >> s;
		int n = s.length();
		int i = n - 2;
		while (s[i + 1] <= s[i])
			i--;
		if (i < 0)
			cout << test << " BIGGEST" << endl;
		else
		{
			int k = n - 1;
			while (s[i] >= s[k])
				k--;
			swap(s[i], s[k]);
			sort(s.begin() + i + 1, s.end());
			cout << test << ' ' << s << endl;
		}
	}
}
 

// File: DSA01012 - MÃ GRAY 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> a;
        a.push_back("0");
        a.push_back("1");
        for (int i = 2; i < (1 << n); i = i << 1)
        {
            for (int j = i - 1; j >= 0; j--)
                a.push_back(a[j]);
            for (int j = 0; j < i; j++)
                a[j] = "0" + a[j];
            for (int j = i; j < 2 * i; j++)
                a[j] = "1" + a[j];
        }
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        cout << endl;
    }
}
 

// File: DSA01013 - MÃ GRAY 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{

    vector<vector<string>> ans;
    vector<string> a;
    a.push_back("0");
    a.push_back("1");
    ans.push_back(a);
    for (int i = 0; i < 9; i++)
    {
        a.clear();
        for (int j = 0; j < ans[i].size(); j++)
        {
            a.push_back('0' + ans[i][j]);
        }
        for (int j = ans[i].size() - 1; j >= 0; j--)
        {
            a.push_back('1' + ans[i][j]);
        }
        ans.push_back(a);
    }
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int k;
        vector<int> b;
        for (int i = 0; i < ans[s.length() - 1].size(); i++)
        {
            if (ans[s.length() - 1][i] == s)
            {
                k = i;
                break;
            }
        }
        while (k != 0)
        {
            b.push_back(k % 2);
            k /= 2;
        }
        for (int i = 0; i < s.length() - b.size(); i++)
            cout << 0;
        for (int i = b.size() - 1; i >= 0; i--)
            cout << b[i];
        cout << endl;
    }
}
 

// File: DSA01014 - TẬP HỢP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (1)
    {
        int n, k, s, d = 0;
        cin >> n >> k >> s;
        if (n < k)
        {
            cout << 0 << endl;
            continue;
        }
        if (n == 0 && k == 0 && s == 0)
            return 0;
        int a[k + 1];
        for (int i = 1; i <= k; i++)
            a[i] = i;
        while (1)
        {
            int x = 0;
            for (int i = 1; i <= k; i++)
                x += a[i];
            if (x == s)
                d++;
            int ok = 0;
            for (int i = k; i >= 1; i--)
            {
                if (a[i] != n - k + i)
                {
                    ok = 1;
                    a[i]++;
                    for (int j = i + 1; j <= k; j++)
                        a[j] = a[j - 1] + 1;
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        cout << d << endl;
    }
}
 

// File: DSA01015 - TÌM BỘI SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        queue<long long> q;
        q.push(9);
        while (q.size())
        {
            long long k = q.front();
            q.pop();
            if (k % n == 0)
            {
                cout << k << endl;
                break;
            }
            q.push(k * 10);
            q.push(k * 10 + 9);
        }
    }
}
 

// File: DSA01016 - PHÂN TÍCH SỐ 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    int d[10];
};
bool cmp(struct data a, struct data b)
{
    for (int i = 0; i < 10; i++)
    {
        if (a.d[i] != b.d[i])
            return a.d[i] > b.d[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x = 0;
        cin >> n;
        struct data c[50];
        for (int i = 0; i < 50; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                c[i].d[j] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            int a[i];
            for (int j = 0; j < i; j++)
                a[j] = n - i + 1;
            while (1)
            {
                int s = 0, ok = 0;
                for (int j = 0; j < i; j++)
                    s += a[j];
                if (s == n)
                {
                    for (int j = 0; j < i; j++)
                        c[x].d[j] = a[j];
                    x++;
                }
                for (int j = i - 1; j >= 0; j--)
                {
                    if (a[j] != 1)
                    {
                        ok = 1;
                        a[j]--;
                        for (int jj = j + 1; jj < i; jj++)
                            a[jj] = a[j];
                        break;
                    }
                }
                if (ok == 0)
                    break;
            }
        }
        sort(c, c + x, cmp);
        for (int i = 0; i < x; i++)
        {
            cout << "(" << c[i].d[0];
            for (int j = 1; j < 10; j++)
            {
                if (c[i].d[j] == 0)
                    break;
                cout << " " << c[i].d[j];
            }
            cout << ") ";
        }
        cout << endl;
    }
}
 

// File: DSA01017 - MÃ GRAY 3.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    vector<vector<string>> ans;
    vector<string> a;
    a.push_back("0");
    a.push_back("1");
    ans.push_back(a);
    for (int i = 0; i < 9; i++)
    {
        a.clear();
        for (int j = 0; j < ans[i].size(); j++)
        {
            a.push_back('0' + ans[i][j]);
        }
        for (int j = ans[i].size() - 1; j >= 0; j--)
        {
            a.push_back('1' + ans[i][j]);
        }
        ans.push_back(a);
    }
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        long long k = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                k += (1 << (s.length() - 1 - i));
            }
        }
        cout << ans[s.length() - 1][k] << endl;
    }
}
 

// File: DSA01018 - TẬP CON LIỀN KỀ PHÍA TRƯỚC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[k + 1], ok = 0, pos = k - 1;
		for (int i = 1; i <= k; i++)
			cin >> a[i];
		while (a[pos] + 1 == a[pos + 1] && pos > 0)
		{
			pos--;
		}
		if (pos == 0)
			for (int i = n - k + 1; i <= n; i++)
				cout << i << " ";
		else
		{
			pos++;
			a[pos]--;
			for (int i = k; i > pos; i--)
				a[i] = n - k + i;
			for (int i = 1; i <= k; i++)
				cout << a[i] << " ";
		}
		cout << endl;
	}
}
 

// File: DSA01019 - HAHAHA.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool check(string a)
{
    int n = a.size();
    if (a[0] != 'H' || a[n - 1] != 'A')
        return 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == 'H' && a[i + 1] == 'H')
            return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a;
        for (int i = 0; i < n; i++)
            a += 'A';
        while (1)
        {
            if (check(a))
                cout << a << endl;
            int ok = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (a[i] == 'A')
                {
                    ok = 1;
                    a[i] = 'H';
                    for (int j = i + 1; j < n; j++)
                        a[j] = 'A';
                    break;
                }
            }
            if (ok == 0)
                break;
        }
    }
}
 

// File: DSA01020 - XÂU NHỊ PHÂN TRƯỚC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        int n = a.size();
        a = "1" + a;
        for (int i = n; i >= 0; i--)
        {
            if (a[i] == '1')
            {
                a[i] = '0';
                for (int j = i + 1; j <= n; j++)
                    a[j] = '1';
                break;
            }
        }
        for (int i = 1; i <= n; i++)
            cout << a[i];
        cout << endl;
    }
}
 

// File: DSA01021 - TỔ HỢP TIẾP THEO.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, s = 0, ok = 0;
        cin >> n >> k;
        int a[k + 1], b[k + 1];
        map<int, int> m;
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i];
            b[i] = a[i];
            m[a[i]]++;
        }
        for (int i = k; i >= 1; i--)
        {
            if (a[i] != n - k + i)
            {
                ok = 1;
                a[i]++;
                for (int j = i + 1; j <= k; j++)
                    a[j] = a[j - 1] + 1;
                break;
            }
        }
        for (int i = 1; i <= k; i++)
        {
            if (m[a[i]] == 0)
                s++;
        }
        if (ok == 0)
            s = k;
        cout << s << endl;
    }
}
 

// File: DSA01022 - SỐ THỨ TỰ HOÁN VỊ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[10], b[10];
bool check()
{
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int p = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            a[i] = i;
            cin >> b[i];
        }
        while (++p)
        {
            if (check())
            {
                cout << p << endl;
                break;
            }
            for (int i = n - 1; i >= 1; i--)
            {
                if (a[i] < a[i + 1])
                {
                    sort(a + i + 1, a + n + 1);
                    for (int j = i + 1; j <= n; j++)
                    {
                        if (a[j] > a[i])
                        {
                            swap(a[i], a[j]);
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
}
 

// File: DSA01023 - SỐ THỨ TỰ TỔ HỢP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, k, a[15], b[15];
bool check()
{
    for (int i = 1; i <= k; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int p = 0;
        cin >> n >> k;
        for (int i = 1; i <= k; i++)
        {
            a[i] = i;
            cin >> b[i];
        }
        while (++p)
        {
            if (check())
            {
                cout << p << endl;
                break;
            }
            for (int i = k; i >= 1; i--)
            {
                if (a[i] != n - k + i)
                {
                    a[i]++;
                    for (int j = i + 1; j <= k; j++)
                        a[j] = a[j - 1] + 1;
                    break;
                }
            }
        }
    }
}
 

// File: DSA01024 - ĐẶT TÊN - 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string x;
    vector<string> a;
    map<string, int> m;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        m[x]++;
    }
    for (auto i : m)
        a.push_back(i.first);
    n = a.size();
    a.insert(a.begin(), 1, "");
    int dd[k + 1];
    for (int i = 1; i <= k; i++)
        dd[i] = i;
    while (1)
    {
        for (int i = 1; i <= k; i++)
            cout << a[dd[i]] << " ";
        cout << endl;
        int ok = 0;
        for (int i = k; i >= 1; i--)
        {
            if (dd[i] != n - k + i)
            {
                ok = 1;
                dd[i]++;
                for (int j = i + 1; j <= k; j++)
                    dd[j] = dd[j - 1] + 1;
                break;
            }
        }
        if (ok == 0)
            return 0;
    }
}
 

// File: DSA01025 - ĐẶT TÊN - 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[k + 1];
        for (int i = 1; i <= k; i++)
            a[i] = i;
        while (1)
        {
            int ok = 0;
            for (int i = 1; i <= k; i++)
                cout << (char)(a[i] + 'A' - 1);
            cout << endl;
            for (int i = k; i >= 1; i--)
            {
                if (a[i] != n - k + i)
                {
                    ok = 1;
                    a[i]++;
                    for (int j = i + 1; j <= k; j++)
                        a[j] = a[j - 1] + 1;
                    break;
                }
            }
            if (ok == 0)
                break;
        }
    }
}
 

// File: DSA01026 - PHÁT LỘC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
void Try(string s)
{
    int k = s.size();
    if (n == k)
    {
        if (s[n - 1] == '6')
            cout << s << endl;
        return;
    }
    if (s[k - 1] == '8')
        Try(s + "6");
    else
    {
        if (k < 4)
            Try(s + "6");
        else if (s[k - 2] == '8' || s[k - 3] == '8')
            Try(s + "6");
        Try(s + "8");
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    Try("8");
}
 

// File: DSA01027 - HOÁN VỊ DÃY SỐ.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
        cin >> b[i];
    }
    sort(b + 1, b + n + 1);
    while (1)
    {
        for (int i = 1; i <= n; i++)
            cout << b[a[i]] << " ";
        cout << endl;
        int ok = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a + i + 1, a + n + 1);
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > a[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (ok == 0)
            break;
    }
}
 

// File: DSA01028 - LIỆT KÊ TỔ HỢP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, x;
    cin >> n >> k;
    int a[k + 1];
    vector<int> b;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        m[x]++;
    }
    b.push_back(0);
    for (auto i : m)
        b.push_back(i.first);
    n = b.size() - 1;
    for (int i = 1; i <= k; i++)
        a[i] = i;
    while (1)
    {
        for (int i = 1; i <= k; i++)
            cout << b[a[i]] << " ";
        cout << endl;
        int ok = 0;
        for (int i = k; i >= 1; i--)
        {
            if (a[i] != n - k + i)
            {
                ok = 1;
                a[i]++;
                for (int j = i + 1; j <= k; j++)
                    a[j] = a[j - 1] + 1;
                break;
            }
        }
        if (ok == 0)
            break;
    }
}
 

// File: DSA02001 - DÃY SỐ 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            cout << "[" << a[0];
            for (int j = 1; j < n - i; j++)
            {
                cout << " " << a[j];
                b[j - 1] = a[j - 1] + a[j];
            }
            cout << "]" << endl;
            for (int j = 0; j < n - i; j++)
            {
                a[j] = b[j];
            }
        }
    }
}
 

// File: DSA02002 - DÃY SỐ 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s = "";
        vector<int> a(n), b(n);
        stack<string> st;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            s += "[" + to_string(a[0]);
            for (int j = 1; j < n - i; j++)
            {
                s += " " + to_string(a[j]);
                b[j - 1] = a[j - 1] + a[j];
            }
            s += "]";
            st.push(s);
            s = "";
            for (int j = 0; j < n - i; j++)
            {
                a[j] = b[j];
            }
        }
        while (st.size())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
}

// File: DSA02003 - DI CHUYỂN TRONG MÊ CUNG 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[12][12];
vector<string> ans;
void Try(int i, int j, string s)
{
    if (i == n && j == n)
    {
        ans.push_back(s);
        return;
    }
    if (i < n && a[i + 1][j] == 1)
        Try(i + 1, j, s + "D");
    if (j < n && a[i][j + 1] == 1)
        Try(i, j + 1, s + "R");
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
            }
        }
        if (a[1][1] == 1)
            Try(1, 1, "");
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
            cout << endl;
        }
    }
}
 

// File: DSA02004 - DI CHUYỂN TRONG MÊ CUNG 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[12][12];
vector<string> ans;
vector<pair<string, pair<int, int>>> p = {{"D", {1, 0}}, {"L", {0, -1}}, {"R", {0, 1}}, {"U", {-1, 0}}};
void Try(int i, int j, string s)
{
    if (i == n && j == n)
    {
        ans.push_back(s);
        return;
    }
    for (int k = 0; k < 4; k++)
    {
        int u = i + p[k].second.first;
        int v = j + p[k].second.second;
        if (u >= 1 && u <= n && v >= 1 && v <= n && a[u][v])
        {
            a[u][v] = 0;
            Try(u, v, s + p[k].first);
            a[u][v] = 1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        if (a[1][1] == 1)
        {
            a[1][1] = 0;
            Try(1, 1, "");
        }
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
            cout << endl;
        }
    }
}
 

// File: DSA02005 - HOÁN VỊ XÂU KÝ TỰ.cpp
#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000], dd[1000] = {};
void Try(int n)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (!dd[i])
        {
            a[n] = i;
            dd[i] = 1;
            if (n == s.size() - 1)
            {
                for (int i = 0; i < s.size(); i++)
                    cout << s[a[i]];
                cout << " ";
            }
            else
                Try(n + 1);
            dd[i] = 0;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        Try(0);
        cout << endl;
    }
}
 

// File: DSA02006 - DÃY CON TỔNG BẰNG K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, k, a[101], b[101], ok;
void Try(int posa, int posb, int s)
{
    for (int i = posa + 1; i <= n; i++)
    {
        if (s + a[i] == k)
        {
            ok = 1;
            b[posb + 1] = a[i];
            cout << "[" << b[0];
            for (int j = 1; j <= posb + 1; j++)
                cout << " " << b[j];
            cout << "] ";
            return;
        }
        else if (s + a[i] < k)
        {
            b[posb + 1] = a[i];
            Try(i, posb + 1, s + a[i]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ok = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        Try(0, -1, 0);
        if (ok == 0)
            cout << -1 << endl;
        cout << endl;
    }
}
 

// File: DSA02007 - ĐỔI CHỖ CÁC CHỮ SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        while (n--)
        {
            int l = 0, r = s.size() - 1, k = r;
            while (l < r && s[l + 1] <= s[l])
                l++;
            if (l == r)
                break;
            while (l < r)
            {
                if (s[r] > s[k])
                    k = r;
                r--;
            }
            l = 0;
            while (l < k && s[l] >= s[k])
                l++;
            swap(s[l], s[k]);
        }
        cout << s << endl;
    }
}
 

// File: DSA02008 - CHỌN SỐ TỪ MA TRẬN VUÔNG CẤP N.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    int b[n + 1][n + 1];
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> b[i][j];
    while (1)
    {
        int x = 0;
        for (int i = 1; i <= n; i++)
            x += b[i][a[i]];
        if (x == k)
            ans.push_back(a);
        int ok = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a.begin() + i + 1, a.end());
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > a[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (ok == 0)
            break;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 1; j <= n; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
 

// File: DSA02009 - CHIA MẢNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, k, sum;
bool ans = 0;
vector<int> a;
void Try(int s, int tmp)
{
    if (ans)
        return;
    if (tmp == k)
    {
        ans = 1;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (s == sum)
            Try(0, tmp + 1);
        else if (s < sum)
            Try(s + a[i], tmp);
        else
            return;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        sum = 0;
        a.clear();
        a.resize(n);
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % k != 0)
            cout << 0 << endl;
        else
        {
            sum /= k;
            Try(0, 0);
            cout << ans << endl;
        }
    }
}
 

// File: DSA02010 - TỔ HỢP SỐ CÓ TỔNG BẰNG X.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    vector<int> b;
};
int n, k, a[25], c[105];
vector<struct data> d;
void Try(int x, int i, int s)
{
    for (int ii = i; ii <= n; ii++)
    {
        s += a[ii];
        c[x] = a[ii];
        if (s == k)
        {
            struct data e;
            for (int jj = 1; jj <= x; jj++)
                e.b.push_back(c[jj]);
            d.push_back(e);
        }
        else if (s < k)
            Try(x + 1, ii, s);
        s -= a[ii];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        d.clear();
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        Try(1, 1, 0);
        if (d.size() == 0)
        {
            cout << "-1" << endl;
            continue;
        }
        for (int i = 0; i < d.size(); i++)
        {
            cout << "[" << d[i].b[0];
            for (int j = 1; j < d[i].b.size(); j++)
            {
                if (d[i].b[j] == 0)
                    break;
                cout << " " << d[i].b[j];
            }
            cout << "]";
        }
        cout << endl;
    }
}
 

// File: DSA02011 - MÁY ATM.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, k, a[35], b[35], ss, mi, ok;
void Try(int x)
{
    for (int i = b[x - 1] + 1; i <= n; i++)
    {
        b[x] = i;
        if (x == k)
        {
            int s = 0;
            for (int j = 1; j <= k; j++)
                s += a[b[j]];
            if (s == ss)
            {
                ok = 1;
                mi = k;
                return;
            }
        }
        else
            Try(x + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        a[0] = ok = 0;
        mi = 50;
        cin >> n >> ss;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            k = i;
            Try(1);
            if (ok == 1)
                break;
        }
        if (ok == 0)
            cout << -1 << endl;
        else
            cout << mi << endl;
    }
}
 

// File: DSA02012 - DI CHUYỂN TRONG MA TRẬN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m;
        int a[n + 1][m + 1] = {};
        a[0][1] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> x;
                a[i][j] = a[i - 1][j] + a[i][j - 1];
            }
        }
        cout << a[n][m] << endl;
    }
}
 

// File: DSA02013 - SỐ NGUYÊN TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, p, ss;
vector<int> a, x;
vector<bool> check(205, 1);
vector<vector<int>> ans;
void era()
{
    for (int i = 2; i <= 200; i++)
    {
        if (check[i])
        {
            a.push_back(i);
            for (int j = i * i; j <= 200; j += i)
                check[j] = 0;
        }
    }
    m = a.size() - 1;
}
void Try(int pos, int k, int s)
{
    for (int i = pos + 1; i <= m; i++)
    {
        if (s + a[i] == ss && k == n - 1)
        {
            x.push_back(a[i]);
            ans.push_back(x);
            x.pop_back();
        }
        else if (k < n - 1 && s + a[i] < ss)
        {
            x.push_back(a[i]);
            Try(i, k + 1, s + a[i]);
            x.pop_back();
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    era();
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        cin >> n >> p >> ss;
        int b = 0;
        while (a[b] <= p)
            b++;
        Try(b - 1, 0, 0);
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
}
 

// File: DSA02014 - TỪ ĐIỂN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int k, n, m, ok;
char b[4][4];
bool check[4][4];
vector<string> a;
map<string, int> c;
vector<pair<int, int>> p = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
void Try(int i1, int i2, string x)
{
    if (c[x] > 0)
    {
        cout << x << " ";
        ok = 1;
    }
    for (int i = 0; i < 8; i++)
    {
        int p1 = i1 + p[i].first;
        int p2 = i2 + p[i].second;
        if (p1 < n && p1 >= 0 && p2 < m && p2 >= 0 && !check[p1][p2])
        {
            check[p1][p2] = 1;
            Try(p1, p2, x + b[p1][p2]);
            check[p1][p2] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s = "";
        ok = 0;
        c.clear();
        cin >> k >> n >> m;
        a.resize(k);
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
            c[a[i]]++;
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> b[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                check[i][j] = 1;
                Try(i, j, s + b[i][j]);
                check[i][j] = 0;
            }
        if (ok == 0)
            cout << -1;
        cout << endl;
    }
}
 

// File: DSA02015 - LOẠI BỎ DẤU NGOẶC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int k;
string s;
map<string, int> m;
bool check(string a)
{
    if (a.size() < 2)
        return 0;
    stack<int> st;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '(')
            st.push(1);
        else if (a[i] == ')')
        {
            if (st.empty())
                return 0;
            else
                st.pop();
        }
    }
    if (st.empty())
        return 1;
    return 0;
}
void Try(string a, int pos)
{
    if (check(a))
    {
        if (a.size() > k)
        {
            k = a.size();
            m.clear();
            m[a]++;
        }
        else if (a.size() == k)
            m[a]++;
        return;
    }
    for (int i = pos + 1; i < a.size(); i++)
    {
        if (a[i] == '(' || a[i] == ')')
        {
            string x = a;
            x.erase(x.begin() + i, x.begin() + i + 1);
            Try(x, i - 1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        k = 0;
        m.clear();
        cin >> s;
        Try(s, -1);
        if (m.empty())
            cout << -1;
        else
        {
            for (auto i : m)
                cout << i.first << " ";
        }
        cout << endl;
    }
}
 

// File: DSA02016 - SẮP XẾP QUÂN HẬU 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, ans, c1[50], c2[50], c3[50];
void Try(int x)
{
    if (x == n + 1)
    {
        ans++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (c1[i] == 0 && c2[i + x] == 0 && c3[x - i + n] == 0)
        {
            c1[i] = c2[i + x] = c3[x - i + n] = 1;
            Try(x + 1);
            c1[i] = c2[i + x] = c3[x - i + n] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans = 0;
        for (int i = 0; i < 20; i++)
            c1[i] = c2[i] = c3[i] = 0;
        cin >> n;
        Try(1);
        cout << ans << endl;
    }
}
 

// File: DSA02017 - SẮP XẾP QUÂN HẬU 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n = 8, ans;
int c1[20], c2[20], c3[20], a[10][10];
void Try(int x, int s)
{
    if (x == n + 1)
    {
        ans = max(ans, s);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (c1[i] == 0 && c2[i + x] == 0 && c3[x - i + n] == 0)
        {
            c1[i] = c2[i + x] = c3[x - i + n] = 1;
            Try(x + 1, s + a[x][i]);
            c1[i] = c2[i + x] = c3[x - i + n] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans = 0;
        for (int i = 0; i < 20; i++)
            c1[i] = c2[i] = c3[i] = 0;
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
                cin >> a[i][j];
        }
        Try(1, 0);
        cout << ans << endl;
    }
}
 

// File: DSA02018 - BIỂU THỨC TOÁN HỌC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string ans = "NO";
        int a[10], b[10], c[10];
        for (int i = 1; i <= 5; i++)
        {
            cin >> a[i];
            b[i] = i;
        }
        do
        {
            c[1] = c[2] = c[3] = c[4] = 1;
            while (1)
            {
                int ok = 0;
                int x = a[b[1]];
                for (int i = 1; i <= 4; i++)
                {
                    if (c[i] == 1)
                        x = x + a[b[i + 1]];
                    else if (c[i] == 2)
                        x = x - a[b[i + 1]];
                    else
                        x = x * a[b[i + 1]];
                }
                if (x == 23)
                {
                    ans = "YES";
                    break;
                }
                for (int i = 4; i >= 1; i--)
                {
                    if (c[i] != 3)
                    {
                        ok = 1;
                        c[i]++;
                        for (int j = i + 1; j <= 4; j++)
                            c[j] = 1;
                        break;
                    }
                }
                if (ok == 0)
                    break;
            }
        } while (next_permutation(b + 1, b + 6));
        cout << ans << endl;
    }
}
 

// File: DSA02019 - ĐƯỜNG ĐI DÀI NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, x, y, ans;
bool check[20][20];
vector<vector<int>> a(20);
void Try(int pos, int k)
{
    ans = max(ans, k);
    for (auto i : a[pos])
    {
        if (!check[i][pos])
        {
            check[i][pos] = check[pos][i] = 1;
            Try(i, k + 1);
            check[i][pos] = check[pos][i] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n >> m;
        for (int i = 0; i < 20; i++)
            a[i].clear();
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 0; i < n; i++)
            Try(i, 0);
        cout << ans << endl;
    }
}
 

// File: DSA02020 - SỐ NHỎ NHẤT CÓ N ƯỚC SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef unsigned long long ll;
const ll INF = 1e19 + 1;
int main()
{
    ll f[15][1111];
    vector<ll> p[15];
    ll a[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    for (int i = 1; i <= 11; i = i + 1)
    {
        p[i].push_back(1);
        p[i].push_back(a[i]);
        while (p[i][p[i].size() - 1] > p[i][p[i].size() - 2])
        {
            int k = p[i].size() - 1;
            p[i].push_back(p[i][k] * a[i]);
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i = i + 1)
        {
            if (i - 1 >= p[1].size() - 1)
                f[1][i] = INF;
            else
                f[1][i] = p[1][i - 1];
        }
        for (int i = 2; i <= 11; i = i + 1)
            for (int j = 1; j <= n; j = j + 1)
            {
                f[i][j] = INF;
                for (int k = 1; k <= j; k = k + 1)
                    if (j % k == 0)
                        if ((k - 1 < p[i].size() - 1) && (f[i - 1][j / k] < INF))
                            if ((f[i - 1][j / k] * p[i][k - 1]) % f[i - 1][j / k] == 0)
                                if (f[i][j] > f[i - 1][j / k] * p[i][k - 1])
                                    f[i][j] = f[i - 1][j / k] * p[i][k - 1];
            }
        cout << f[11][n] << endl;
    }
}
 

// File: DSA02021 - KÝ TỰ ĐẶC BIỆT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, x, a[62], pos = 61;
        string s;
        cin >> s >> k;
        n = s.size();
        s = ' ' + s;
        a[1] = n;
        for (int i = 2; i <= 61; i++)
        {
            if (a[i - 1] * 2 >= 2e18)
            {
                pos = i - 1;
                break;
            }
            else
                a[i] = a[i - 1] * 2;
        }
        while (k > n)
        {
            if (a[pos] < k)
            {
                long long x = k - a[pos];
                if (x == 1)
                    k = a[pos - 1];
                else
                    k = x - 1;
            }
            pos--;
        }
        cout << s[k] << endl;
    }
}
 

// File: DSA02022 - NGÀY ĐẶC BIỆT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<string> a1 = {"02", "20", "22"};
    vector<string> a2 = {"02"};
    vector<string> a3 = {"2000", "2002", "2020", "2022", "2200", "2202", "2220", "2222"};
    for (int i = 0; i < a1.size(); i++)
        for (int j = 0; j < a2.size(); j++)
            for (int k = 0; k < a3.size(); k++)
                cout << a1[i] + "/" + a2[j] + "/" + a3[k] << endl;
}
 

// File: DSA02022 - NGƯỜI DU LỊCH.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[20], b[20] = {};
long long s = 1e15, c[20][20], S = 0;
void Try(int x)
{
    for (int i = 2; i <= n; i++)
    {
        if (b[i] == 0)
        {
            a[x] = i;
            b[i] = 1;
            S += c[a[x - 1]][i];
            if (x == n && S + c[i][1] < s)
                s = S + c[i][1];
            else if (S < s && x < n)
                Try(x + 1);
            S -= c[a[x - 1]][i];
            b[i] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    a[1] = 1;
    b[1] = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
        }
    }
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    Try(2);
    cout << s;
}
 

// File: DSA02023 - ĐẶT TÊN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string x;
    vector<string> a;
    map<string, int> m;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        m[x]++;
    }
    for (auto i : m)
        a.push_back(i.first);
    n = a.size();
    a.insert(a.begin(), 1, "");
    int dd[k + 1];
    for (int i = 1; i <= k; i++)
        dd[i] = i;
    while (1)
    {
        for (int i = 1; i <= k; i++)
            cout << a[dd[i]] << " ";
        cout << endl;
        int ok = 0;
        for (int i = k; i >= 1; i--)
        {
            if (dd[i] != n - k + i)
            {
                ok = 1;
                dd[i]++;
                for (int j = i + 1; j <= k; j++)
                    dd[j] = dd[j - 1] + 1;
                break;
            }
        }
        if (ok == 0)
            return 0;
    }
}
 

// File: DSA02024 - DÃY CON TĂNG DẦN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[25];
string k;
vector<int> x;
vector<string> v;
vector<vector<int>> ans;
void Try(int posa)
{
    for (int i = posa + 1; i <= n; i++)
    {
        if (a[i] > a[posa])
        {
            x.push_back(a[i]);
            if (x.size() > 1)
                ans.push_back(x);
            Try(i);
            x.erase(x.end() - 1, x.end());
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Try(0);
    for (int i = 0; i < ans.size(); i++)
    {
        k = "";
        for (int j = 0; j < ans[i].size(); j++)
        {
            k += to_string(ans[i][j]);
            k += " ";
        }
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}
 

// File: DSA02025 - KÝ TỰ LẶP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, s = 1e9, S = 0;
int a[100], b[100] = {};
vector<string> c(20);
int kt(string a, string b)
{
    int i = 0, j = 0, e = a.size(), f = b.size(), ss = 0;
    while (i < e && j < f)
    {
        if (a[i] == b[j])
        {
            ss++;
            i++;
            j++;
        }
        while (a[i] < b[j])
        {
            i++;
            if (i == e)
                break;
        }
        while (a[i] > b[j])
        {
            j++;
            if (j == f)
                break;
        }
    }
    return ss;
}
void Try(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == 0)
        {
            a[x] = i;
            b[i] = 1;
            int k = kt(c[a[x - 1]], c[i]);
            S += k;
            if (x == n && S < s)
                s = S;
            else if (x < n && S < s)
                Try(x + 1);
            b[i] = 0;
            S -= k;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    c[0] = "";
    Try(1);
    cout << s;
}
 

// File: DSA02027 - NGƯỜI DU LỊCH.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[20], b[20] = {};
long long s = 1e15, c[20][20], S = 0;
void Try(int x)
{
    for (int i = 2; i <= n; i++)
    {
        if (b[i] == 0)
        {
            a[x] = i;
            b[i] = 1;
            S += c[a[x - 1]][i];
            if (x == n && S + c[i][1] < s)
                s = S + c[i][1];
            else if (S < s && x < n)
                Try(x + 1);
            S -= c[a[x - 1]][i];
            b[i] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    a[1] = 1;
    b[1] = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
        }
    }
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    Try(2);
    cout << s;
}
 

// File: DSA02028 - CHIA ĐỀU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, k, d;
int a[15];
int solve(int u, int t)
{
    if (t > k)
        return 0;
    if (u == n + 1)
    {
        if (t == k)
            return 1;
        return 0;
    }
    int sum = 0, ans = 0;
    for (int i = u; i <= n; i++)
    {
        sum += a[i];
        if (sum == d)
            ans += solve(i + 1, t + 1);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        d += a[i];
    if (d % k != 0)
        cout << 0;
    else
    {
        d /= k;
        cout << solve(1, 0);
    }
}
 

// File: DSA02029 - THÁP HÀ NỘI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void Tower(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << a << " -> " << c << endl;
        return;
    }
    Tower(n - 1, a, c, b);
    Tower(1, a, b, c);
    Tower(n - 1, b, a, c);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char a = 'A', b = 'B', c = 'C';
    int n;
    cin >> n;
    Tower(n, a, b, c);
}
 

// File: DSA02030 - LIỆT KÊ XÂU KÝ TỰ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char c;
    int n, k;
    cin >> c >> k;
    n = c - 'A' + 1;
    int a[k + 1];
    for (int i = 1; i <= k; i++)
        a[i] = 1;
    while (1)
    {
        for (int i = 1; i <= k; i++)
            cout << (char)('A' + a[i] - 1);
        cout << endl;
        int ok = 0;
        for (int i = k; i >= 1; i--)
        {
            if (a[i] != n)
            {
                ok = 1;
                a[i]++;
                for (int j = i + 1; j <= k; j++)
                    a[j] = a[i];
                break;
            }
        }
        if (ok == 0)
            break;
    }
}
 

// File: DSA02031 - GHÉP CHỮ CÁI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[100];
bool check()
{
    for (int i = 2; i <= n - 1; i++)
        if ((a[i] == 1 || a[i] == 5) && 
        (a[i - 1] != 1 && a[i - 1] != 5) && 
        (a[i + 1] != 1 && a[i + 1] != 5))
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char c;
    cin >> c;
    n = c - 'A' + 1;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    while (1)
    {
        if (check())
        {
            for (int i = 1; i <= n; i++)
                cout << (char)(a[i] + 'A' - 1);
            cout << endl;
        }
        int ok = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a + i + 1, a + n + 1);
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > a[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (ok == 0)
            break;
    }
}
 

// File: DSA02032 - TỔ HỢP SỐ CÓ TỔNG BẰNG X.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    vector<int> b;
};
int n, k, a[25], c[105];
vector<struct data> d;
void Try(int x, int i, int s)
{
    for (int ii = i; ii <= n; ii++)
    {
        s += a[ii];
        c[x] = a[ii];
        if (s == k)
        {
            struct data e;
            for (int jj = 1; jj <= x; jj++)
                e.b.push_back(c[jj]);
            d.push_back(e);
        }
        else if (s < k)
            Try(x + 1, ii, s);
        s -= a[ii];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        d.clear();
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        Try(1, 1, 0);
        if (d.size() == 0)
        {
            cout << "-1" << endl;
            continue;
        }
        cout << d.size() << " ";
        for (int i = 0; i < d.size(); i++)
        {
            cout << "{" << d[i].b[0];
            for (int j = 1; j < d[i].b.size(); j++)
            {
                if (d[i].b[j] == 0)
                    break;
                cout << " " << d[i].b[j];
            }
            cout << "} ";
        }
        cout << endl;
    }
}
 

// File: DSA02033 - SỐ XA CÁCH.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, check[15];
void Try(string s)
{
    int k = s.size();
    if (k == n)
        cout << s << endl;
    for (int i = 1; i <= n; i++)
        if (k == 0 || (!check[i] && abs(s[k - 1] - '0' - i) != 1))
        {
            check[i] = 1;
            Try(s + to_string(i));
            check[i] = 0;
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        Try("");
    }
}
 

// File: DSA02034 - TRÒ CHƠI VỚI CÁC CON SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, check[15];
void Try(string s)
{
    int k = s.size();
    if (k == n)
        cout << s << endl;
    for (int i = 1; i <= n; i++)
        if (k == 0 || (!check[i] && abs(s[k - 1] - '0' - i) != 1))
        {
            check[i] = 1;
            Try(s + to_string(i));
            check[i] = 0;
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        Try("");
    }
}
 

// File: DSA02035 - HOÁN VỊ CÁC CHỮ SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int to_int(string s)
{
    int a = 0;
    for (int i = 0; i < s.size(); i++)
    {
        a = a * 10 + s[i] - '0';
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    int a[n + 1], MIN = 1e9;
    vector<string> b(m);
    vector<string> c;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        b[i] = "0" + b[i];
    }
    for (int i = 1; i <= n; i++)
        a[i] = i;
    while (1)
    {
        c.clear();
        for (int i = 0; i < m; i++)
        {
            string x = b[i];
            for (int j = 1; j <= n; j++)
                x[j] = b[i][a[j]];
            c.push_back(x);
        }
        sort(c.begin(), c.end());
        MIN = min(MIN, to_int(c[c.size() - 1]) - to_int(c[0]));
        int ok = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a + i + 1, a + n + 1);
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > a[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (ok == 0)
            break;
    }
    cout << MIN;
}
 

// File: DSA02036 - DÃY CON CÓ TỔNG LẺ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[20];
vector<int> x;
vector<vector<int>> ans;
map<vector<int>, int> m;
void Try(int k, int s)
{
    for (int i = k + 1; i <= n; i++)
    {
        Try(i, s);
        x.push_back(a[i]);
        if ((s + a[i]) % 2 == 1)
        {
            if (m[x] == 0)
            {
                m[x]++;
                ans.push_back(x);
            }
        }
        Try(i, s + a[i]);
        x.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        m.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        Try(0, 0);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
}
 

// File: DSA02037 - DÃY CON CÓ TỔNG NGUYÊN TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[20];
vector<int> x;
vector<vector<int>> ans;
map<vector<int>, int> m;
bool nto(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}
void Try(int k, int s)
{
    for (int i = k + 1; i <= n; i++)
    {
        Try(i, s);
        x.push_back(a[i]);
        if (nto(s + a[i]))
        {
            if (m[x] == 0)
            {
                m[x]++;
                ans.push_back(x);
            }
        }
        Try(i, s + a[i]);
        x.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        m.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        Try(0, 0);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
}
 

// File: DSA02038 - DÃY CON CÓ K PHẦN TỬ TĂNG DẦN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[k + 1], b[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= k; i++)
            a[i] = i;
        while (1)
        {
            for (int i = 1; i <= k; i++)
                cout << b[a[i]] << " ";
            cout << endl;
            int ok = 0;
            for (int i = k; i >= 1; i--)
            {
                if (a[i] != n - k + i)
                {
                    ok = 1;
                    a[i]++;
                    for (int j = i + 1; j <= k; j++)
                        a[j] = a[j - 1] + 1;
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        cout << endl;
    }
}
 

// File: DSA02039 - PHÂN TÍCH SỐ 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    int d[10];
};
bool cmp(struct data a, struct data b)
{
    for (int i = 0; i < 10; i++)
    {
        if (a.d[i] != b.d[i])
            return a.d[i] > b.d[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x = 0;
        cin >> n;
        struct data c[50];
        for (int i = 0; i < 50; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                c[i].d[j] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            int a[i];
            for (int j = 0; j < i; j++)
                a[j] = n - i + 1;
            while (1)
            {
                int s = 0, ok = 0;
                for (int j = 0; j < i; j++)
                    s += a[j];
                if (s == n)
                {
                    for (int j = 0; j < i; j++)
                        c[x].d[j] = a[j];
                    x++;
                }
                for (int j = i - 1; j >= 0; j--)
                {
                    if (a[j] != 1)
                    {
                        ok = 1;
                        a[j]--;
                        for (int jj = j + 1; jj < i; jj++)
                            a[jj] = a[j];
                        break;
                    }
                }
                if (ok == 0)
                    break;
            }
        }
        sort(c, c + x, cmp);
        cout << x << endl;
        for (int i = 0; i < x; i++)
        {
            cout << "(" << c[i].d[0];
            for (int j = 1; j < 10; j++)
            {
                if (c[i].d[j] == 0)
                    break;
                cout << " " << c[i].d[j];
            }
            cout << ") ";
        }
        cout << endl;
    }
}
 

// File: DSA02041 - BIẾN ĐỔI VỀ 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        pair<int, int> x, k;
        queue<pair<int, int>> q;
        x.first = n;
        x.second = 0;
        q.push(x);
        while (q.size())
        {
            x = q.front();
            q.pop();
            if (x.first == 1)
            {
                cout << x.second << endl;
                break;
            }
            k.second = x.second + 1;
            if (x.first % 2 == 0)
            {
                k.first = x.first / 2;
                q.push(k);
            }
            if (x.first % 3 == 0)
            {
                k.first = x.first / 3;
                q.push(k);
            }
            if (x.first > 1)
            {
                k.first = x.first - 1;
                q.push(k);
            }
        }
    }
}
 

// File: DSA02045 - TẬP CON CỦA XÂU KÝ TỰ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
string s;
vector<string> ans;
map<string, int> m;
void Try(int i, string x)
{
    if (x != "" && m[x] == 0)
    {
        ans.push_back(x);
        m[x]++;
    }
    if (i == n)
        return;
    Try(i + 1, x + s[i]);
    Try(i + 1, x);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        m.clear();
        cin >> n >> s;
        Try(0, "");
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}
 

// File: DSA03001 - ĐỔI TIỀN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	int a[100001] = {};
	int b[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
	for (int i = 1; i <= 100000; i++)
	{
		a[i] = 1e9;
		for (int j = 0; j < 10; j++)
		{
			if (i == b[j])
			{
				a[i] = 1;
				break;
			}
			if (i - b[j] > 0 && a[i - b[j]] > 0)
				a[i] = min(a[i], a[i - b[j]] + 1);
		}
	}
	while (t--)
	{
		int n;
		cin >> n;
		cout << a[n] << endl;
	}
}
 

// File: DSA03002 - NHẦM CHỮ SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int to_five(string s)
{
	int n = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '6')
			s[i] = '5';
		n = n * 10 + s[i] - '0';
	}
	return n;
}
int to_six(string s)
{
	int n = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '5')
			s[i] = '6';
		n = n * 10 + s[i] - '0';
	}
	return n;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	cout << to_five(a) + to_five(b) << " " << to_six(a) + to_six(b);
}
 

// File: DSA03003 - TÌM MAX.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long a[n], s = 0, mod = 1e9 + 7;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++)
			s = (s + a[i] * i) % mod;
		cout << s << endl;
	}
}
 

// File: DSA03004 - TỔNG NHỎ NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        long long s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for (int i = 0; i < n; i += 2)
            s1 = s1 * 10 + a[i];
        for (int i = 1; i < n; i += 2)
            s2 = s2 * 10 + a[i];
        cout << s1 + s2 << endl;
    }
}
 

// File: DSA03005 - CHIA MẢNG THÀNH HAI MẢNG CON CÓ TỔNG LỚN NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n], s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        k = min(k, n - k);
        for (int i = 0; i < k; i++)
            s1 += a[i];
        for (int i = k; i < n; i++)
            s2 += a[i];
        cout << s2 - s1 << endl;
    }
}
 

// File: DSA03006 - SẮP XẾP THAM LAM.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n], ok = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i] && a[i] != b[n - i - 1])
            {
                ok = 0;
                break;
            }
        }
        if (ok == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
 

// File: DSA03007 - GIÁ TRỊ NHỎ NHẤT CỦA BIỂU THỨC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool cmp(long long a, long long b)
{
	return a > b;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long s = 0;
		vector<long long> a(n), b(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end(), cmp);
		for (int i = 0; i < n; i++)
			s += a[i] * b[i];
		cout << s << endl;
	}
}
 

// File: DSA03008 - SẮP XẾP CÔNG VIỆC 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		pair<int, int> a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i].second;
		for (int i = 0; i < n; i++)
			cin >> a[i].first;
		sort(a, a + n);
		int ans = 1, k = a[0].first;
		for (int i = 1; i < n; i++)
		{
			if (a[i].second >= k)
			{
				ans++;
				k = a[i].first;
			}
		}
		cout << ans << endl;
	}
}
 

// File: DSA03009 - SẮP XẾP CÔNG VIỆC 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, d = 0, ans = 0;
        cin >> n;
        int check[n + 1] = {};
        vector<pair<int, int>> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> x >> a[i].second >> a[i].first;
        sort(a.begin() + 1, a.end(), greater<pair<int, int>>());
        for (int i = 1; i <= n; i++)
        {
            for (int j = min(n, a[i].second); j >= 1; j--)
            {
                if (!check[j])
                {
                    ans += a[i].first;
                    d++;
                    check[j] = 1;
                    break;
                }
            }
        }
        cout << d << " " << ans << endl;
    }
}
 

// File: DSA03010 - NỐI DÂY 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        long long s = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            q.push(x);
        }
        while (q.size() > 1)
        {
            int s1 = q.top();
            q.pop();
            int s2 = q.top();
            q.pop();
            int k = s1 + s2;
            s += k;
            q.push(k);
        }
        cout << s << endl;
    }
}
 

// File: DSA03011 - NỐI DÂY 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int x, s = 0, mod = 1e9 + 7;
		priority_queue<int, vector<int>, greater<int>> q;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			q.push(x);
		}
		while (q.size() > 1)
		{
			int s1 = q.top();
			q.pop();
			int s2 = q.top();
			q.pop();
			int k = (s1 + s2) % mod;
			s = (s + k) % mod;
			q.push(k);
		}
		cout << s << endl;
	}
}
 

// File: DSA03012 - SẮP ĐẶT XÂU KÝ TỰ 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int a[30] = {}, MAX = 0;
        for (int i = 0; i < s.size(); i++)
            a[s[i] - 'a']++;
        for (int i = 0; i < 30; i++)
            MAX = max(MAX, a[i]);
        if (MAX * 2 > s.size() + 1)
            cout << -1 << endl;
        else
            cout << 1 << endl;
    }
}
 

// File: DSA03013 - SẮP ĐẶT XÂU KÝ TỰ 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        string s;
        cin >> k >> s;
        int a[30] = {}, MAX = 0;
        for (int i = 0; i < s.size(); i++)
            a[s[i] - 'A']++;
        for (int i = 0; i < 30; i++)
            MAX = max(MAX, a[i]);
        if (MAX * k > s.size() + 1)
            cout << -1 << endl;
        else
            cout << 1 << endl;
    }
}
 

// File: DSA03014 - SỐ KHỐI LẬP PHƯƠNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool check(string s1, string s2)
{
    int k = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        int ok = 0;
        for (int j = k; j < s2.size(); j++)
        {
            if (s1[i] == s2[j])
            {
                ok = 1;
                k = j + 1;
                break;
            }
        }
        if (!ok)
            return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<string> f;
    for (long long i = 1; i <= 50; i++)
        f.push_back(to_string(i * i * i));
    while (t--)
    {
        string s, ans = "-1";
        cin >> s;
        for (int i = f.size() - 1; i >= 0; i--)
        {
            if ((f[i].size() < s.size() || f[i] < s) && check(f[i], s))
            {
                ans = f[i];
                break;
            }
        }
        cout << ans << endl;
    }
}
 

// File: DSA03015 - MUA LƯƠNG THỰC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, s, m;
        cin >> n >> s >> m;
        if (s * m > (s - s / 7) * n)
            cout << -1 << endl;
        else
        {
            for (int i = 1; i <= s - s / 7; i++)
            {
                if (n * i >= s * m)
                {
                    cout << i << '\n';
                    break;
                }
            }
        }
    }
}
 

// File: DSA03016 - SỐ NHỎ NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string a;
int s, n, d, ok;
void Try(int sn)
{
    if (ok)
        return;
    int n = a.size();
    if (n == d)
    {
        if (sn == s)
        {
            ok = 1;
            cout << a << endl;
        }
        return;
    }
    if (s - sn < 0 || s - sn > (d - n) * 9)
        return;
    for (int i = 0; i <= 9; i++)
    {
        a += to_string(i);
        Try(sn + i);
        a.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ok = 0;
        cin >> s >> d;
        for (int i = 1; i <= 9; i++)
        {
            if (!ok)
            {
                a = to_string(i);
                Try(i);
                a.pop_back();
            }
        }
        if (!ok)
            cout << -1 << endl;
    }
}
 

// File: DSA03017 - GIÁ TRỊ NHỎ NHẤT CỦA XÂU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int k, x, n = 0;
        string s;
        cin >> k >> s;
        map<char, int> m;
        priority_queue<int> q;
        for (int i = 0; i < s.size(); i++)
            m[s[i]]++;
        for (auto i : m)
            q.push(i.second);
        while (k--)
        {
            x = q.top();
            q.pop();
            q.push(x - 1);
        }
        while (q.size())
        {
            n += q.top() * q.top();
            q.pop();
        }
        cout << n << endl;
    }
}
 

// File: DSA03018 - SỐ MAY MẮN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, ok = 0;
        cin >> n;
        for (int i = 0; i <= n / 4; i++)
        {
            if ((n - i * 4) % 7 == 0)
            {
                ok = 1;
                for (int j = 0; j < i; j++)
                    cout << 4;
                for (int j = 0; j < (n - i * 4) / 7; j++)
                    cout << 7;
                cout << endl;
                break;
            }
        }
        if (ok == 0)
            cout << -1 << endl;
    }
}
 

// File: DSA03019 - PHÂN SỐ ĐƠN VỊ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, n, m, x;
        cin >> a >> b;
        while (b % a != 0)
        {
            n = a;
            m = b;
            x = b / a;
            cout << 1 << "/" << x + 1 << " + ";
            a = (x + 1) * n - m;
            b = (x + 1) * b;
        }
        cout << 1 << "/" << b / a;
        cout << '\n';
    }
}
 

// File: DSA03020 - BIỂU THỨC ĐÚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<char> st;
        int k = 0, ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.size() == 0)
                st.push(s[i]);
            else if (st.top() == '[' && s[i] == ']')
            {
                st.pop();
                k += 2;
            }
            else if (st.top() == ']' && s[i] == '[')
            {
                ans += st.size() + k;
                st.pop();
            }
            else if (s[i] == '[')
                st.push(s[i]);
            else if (st.top() == ']' && s[i] == ']')
                st.push(s[i]);
            if (st.size() == 0)
                k = 0;
        }
        cout << ans << endl;
    }
}
 

// File: DSA03021 - TÌM DÃY SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, ans = 0;
vector<int> a(1000), b(1000);
bool check(int pos)
{
    for (int i = 0; i < n; i++)
        if (a[i] / pos == a[i] / (pos + 1))
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    b = a;
    sort(b.begin(), b.begin() + n);
    for (int i = b[0]; i >= 0; i--)
    {
        if (check(i))
        {
            for (int j = 0; j < n; ++j)
                ans += a[j] / (i + 1) + 1;
            break;
        }
    }
    cout << ans;
}
 

// File: DSA03022 - TÍCH LỚN NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, ok = 0;
    cin >> n;
    long long x;
    vector<long long> a;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x)
            a.push_back(x);
        else
            ok = 1;
    }
    n = a.size();
    sort(a.begin(), a.end());
    long long ans = max(a[0] * a[1], max(a[0] * a[1] * a[n - 1], max(a[n - 1] * a[n - 2], a[n - 1] * a[n - 2] * a[n - 3])));
    if (ans > 0)
        cout << ans;
    else
        cout << 0;
}
 

// File: DSA03023 - SẮP XẾP VIÊN BI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, ok, ans = 0;
string s;
void Try(int l, int pos, char c)
{
    for (int i = l; i < n; i++)
    {
        if (s[i] == c)
        {
            ok = 1;
            swap(s[pos], s[i]);
            ans++;
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    int dx = 0, dt = 0, dd = 0;
    for (auto i : s)
    {
        if (i == 'X')
            dx++;
        else if (i == 'T')
            dt++;
        else
            dd++;
    }
    for (int i = 0; i < dx; ++i)
    {
        if (s[i] == 'T')
            Try(dx, i, 'X');
        else if (s[i] == 'D')
        {
            ok = 0;
            Try(dx + dt, i, 'X');
            if (ok == 0)
                Try(dx, i, 'X');
        }
    }
    for (int i = dx; i < dt + dx; i++)
        if (s[i] == 'D')
            Try(dx + dt, i, 'T');
    cout << ans;
}
 

// File: DSA03024 - LỰA CHỌN TỐI ƯU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0, k = 0;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i].first >> a[i].second;
        sort(a.begin(), a.end(), cmp);
        for (int i = 0; i < n; i++)
        {
            if (a[i].first >= k)
            {
                k = a[i].second;
                ans++;
            }
        }
        cout << ans << endl;
    }
}
 

// File: DSA03025 - TRỤC TỌA ĐỘ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0, k = 0;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i].first >> a[i].second;
        sort(a.begin(), a.end(), cmp);
        for (int i = 0; i < n; i++)
        {
            if (a[i].first >= k)
            {
                k = a[i].second;
                ans++;
            }
        }
        cout << ans << endl;
    }
}
 

// File: DSA03026 - LỰA CHỌN THAM LAM.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    if (n == 1 && s < 10)
        cout << s << " " << s;
    else if (s == 0 || s > n * 9)
        cout << "-1 -1";
    else
    {
        int k = s / 9;
        int d = s - k * 9;
        if (k == n)
        {
            for (int i = 0; i < n; i++)
                cout << 9;
            cout << " ";
            for (int i = 0; i < n; i++)
                cout << 9;
        }
        else if (d == 0)
        {
            cout << 1;
            for (int i = k + 1; i < n; i++)
                cout << 0;
            cout << 8;
            for (int i = 1; i < k; i++)
                cout << 9;
            cout << " ";
            for (int i = 0; i < k; i++)
                cout << 9;
            for (int i = k; i < n; i++)
                cout << 0;
        }
        else
        {
            if (k == n - 1)
            {
                cout << d;
                for (int i = k + 1; i < n; i++)
                    cout << 0;
                for (int i = 0; i < k; i++)
                    cout << 9;
            }
            else
            {
                cout << 1;
                for (int i = k + 2; i < n; i++)
                    cout << 0;
                cout << d - 1;
                for (int i = 0; i < k; i++)
                    cout << 9;
            }
            cout << " ";
            for (int i = 0; i < k; i++)
                cout << 9;
            cout << d;
            for (int i = k + 1; i < n; i++)
                cout << 0;
        }
    }
}
 

// File: DSA03027 - GIÁ TRỊ LỚN NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long x, s = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s += x + abs(x);
	}
	cout << s;
}
 

// File: DSA03034 - DÃY CON CHUNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        long long a1[n], a2[m], a3[k];
        for (int i = 0; i < n; i++)
            cin >> a1[i];
        for (int i = 0; i < m; i++)
            cin >> a2[i];
        for (int i = 0; i < k; i++)
            cin >> a3[i];
        int i = 0, j = 0, h = 0;
        vector<long long> a;
        while (i < n && j < m && h < k)
        {
            if (a1[i] == a2[j] && a2[j] == a3[h])
            {
                a.push_back(a1[i]);
                i++;
                j++;
                h++;
            }
            else if (a1[i] < a2[j])
                i++;
            else if (a2[j] < a3[h])
                j++;
            else
                h++;
        }
        if (a.size() == 0)
            cout << "NO" << endl;
        else
        {
            for (int i = 0; i < a.size(); i++)
                cout << a[i] << " ";
            cout << endl;
        }
    }
}
 

// File: DSA03035 - SẮP XẾP ĐƠN GIẢN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s = 0;
    cin >> n;
    vector<int> a(n + 5), f(n + 5, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        f[a[i]] = f[a[i] - 1] + 1;
        s = max(s, f[a[i]]);
    }
    cout << n - s;
}
 

// File: DSA04001 - LŨY THỪA.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
long long mod = 1e9 + 7;
long long poww(long long n, long long k)
{
    if (k == 1)
        return n;
    long long x = poww(n, k / 2);
    if (k % 2 == 0)
        return (x * x) % mod;
    else
        return (((x * x) % mod) * n) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        cout << poww(n, k) << endl;
    }
}
 

// File: DSA04002 - LŨY THỪA ĐẢO.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
long long mod = 1e9 + 7;
long long poww(long long n, long long k)
{
    if (k == 0)
        return 1;
    long long x = poww(n, k / 2);
    if (k % 2 == 0)
        return (x * x) % mod;
    else
        return (((x * x) % mod) * n) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, k;
        cin >> n;
        m = n;
        k = 0;
        while (m != 0)
        {
            k = k * 10 + m % 10;
            m /= 10;
        }
        cout << poww(n, k) << endl;
    }
}
 

// File: DSA04003 - ĐẾM DÃY.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
long long mod = 123456789;
long long poww(long long n, long long k)
{
    if (k == 1)
        return n;
    long long x = poww(n, k / 2);
    if (k % 2 == 0)
        return (x * x) % mod;
    else
        return (((x * x) % mod) * n) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << poww(2, n - 1) << endl;
    }
}
 

// File: DSA04004 - GẤP ĐÔI DÃY SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long a[n + 1];
        for (long long i = 1; i <= n; i++)
        {
            a[i] = pow(2, i - 1);
        }
        for (int i = n; i >= 1; i--)
        {
            if (k == a[i])
            {
                cout << i << endl;
                break;
            }
            else if (k > a[i])
                k -= a[i];
        }
    }
}
 

// File: DSA04005 - DÃY XÂU FIBONACI.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long a[n + 1];
        a[1] = 1;
        a[2] = 1;
        for (int i = 3; i <= n; i++)
            a[i] = a[i - 1] + a[i - 2];
        while (1)
        {
            if (n == 1)
            {
                cout << "A\n";
                break;
            }
            else if (n == 2)
            {
                cout << "B\n";
                break;
            }
            if (k > a[n - 2])
            {
                k -= a[n - 2];
                n--;
            }
            else
                n -= 2;
        }
    }
}
 

// File: DSA04006 - ĐẾM SỐ BÍT 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
long long Find(long long pos, long long n, long long ctr)
{
	if (pos & 1)
		return 1;
	if (pos == ctr)
		return (n % 2);
	if (pos > ctr)
		return Find(pos - ctr, n / 2, ctr / 2);
	return Find(pos, n / 2, ctr / 2);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		long long n, l, r;
		cin >> n >> l >> r;
		long long ctr = pow(2, (long long)log2(n)), ans = 0;
		for (long long i = l; i <= r; i++)
			ans += Find(i, n, ctr);
		cout << ans << "\n";
	}
}
 

// File: DSA04007 - HỆ CƠ SỐ K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x, ok = 0;
        string s1, s2, s = "";
        cin >> k >> s1 >> s2;
        while (s1.size() < s2.size())
            s1 = '0' + s1;
        while (s2.size() < s1.size())
            s2 = '0' + s2;
        n = s1.size();
        for (int i = n - 1; i >= 0; i--)
        {
            x = s1[i] + s2[i] - 2 * '0';
            if (ok == 1)
            {
                x++;
                ok = 0;
            }
            if (x > k - 1)
            {
                ok = 1;
                x -= k;
            }
            if (x >= 10)
                s = (char)('A' + x - 10) + s;
            else
                s = to_string(x) + s;
        }
        if (ok == 1)
            s = '1' + s;
        cout << s << endl;
    }
}
 

// File: DSA04008 - SỐ FIBONACCI THỨ N.cpp
#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7, F[2][2], M[2][2];
void Mul(long long f[2][2], long long m[2][2])
{
    long long x = (f[0][0] * m[0][0] % mod + f[0][1] * m[1][0] % mod) % mod;
    long long y = (f[0][0] * m[0][1] % mod + f[0][1] * m[1][1] % mod) % mod;
    long long z = (f[1][0] * m[0][0] % mod + f[1][1] * m[1][0] % mod) % mod;
    long long t = (f[1][0] * m[0][1] % mod + f[1][1] * m[1][1] % mod) % mod;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = t;
}
void Pow(long long f[2][2], long long n)
{
    if (n <= 1)
        return;
    Pow(f, n / 2);
    Mul(f, f);
    if (n & 1)
        Mul(f, M);
}
long long fibo(long long n)
{
    F[0][0] = F[0][1] = F[1][0] = 1;
    F[1][1] = 0;
    M[0][0] = M[0][1] = M[1][0] = 1;
    M[1][1] = 0;
    Pow(F, n - 1);
    return F[0][0];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << fibo(n) << endl;
    }
}
 

// File: DSA04009 - LŨY THỪA MA TRẬN 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
	long long x[10][10];
};
int n;
long long mod = 1000000007;
struct data operator*(struct data a, struct data b)
{
	struct data xx;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			xx.x[i][j] = 0;
			for (int k = 0; k < n; k++)
				xx.x[i][j] = (xx.x[i][j] + (a.x[i][k] * b.x[k][j]) % mod) % mod;
		}
	}
	return xx;
};
struct data poww(struct data a, long long k)
{
	if (k == 1)
		return a;
	if (k % 2 == 1)
		return a * poww(a, k - 1);
	struct data xx = poww(a, k / 2);
	return xx * xx;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		long long k;
		cin >> n >> k;
		struct data a;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a.x[i][j];
		a = poww(a, k);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << a.x[i][j] << " ";
			cout << endl;
		}
	}
}
 

// File: DSA04010 - DÃY CON LIÊN TIẾP CÓ TỔNG LỚN NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x, ans = 0, s = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            s += x;
            ans = max(ans, s);
            if (s < 0)
                s = 0;
        }
        cout << ans << endl;
    }
}
 

// File: DSA04011 - TÍCH HAI SỐ NHỊ PHÂN.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        long long s1 = 0, s2 = 0;
        long long n1 = a.size(), n2 = b.size();
        for (long long i = n1 - 1; i >= 0; i--)
            s1 += (a[i] - '0') * pow(2, n1 - i - 1);
        for (long long i = n2 - 1; i >= 0; i--)
            s2 += (b[i] - '0') * pow(2, n2 - i - 1);
        cout << s1 * s2 << endl;
    }
}
 

// File: DSA04012 - TÍCH ĐA THỨC.cpp
#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int a[n + 1], b[m + 1], c[m + n + 1] = {};
        for (int i = n; i >= 1; i--)
            scanf("%d", &a[i]);
        for (int i = m; i >= 1; i--)
            scanf("%d", &b[i]);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                c[i + j] += a[i] * b[j];
            }
        }
        for (int i = m + n; i >= 2; i--)
            printf("%d ", c[i]);
        printf("\n");
    }
}
 

// File: DSA04013 - SẮP XẾP KANGURU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        int ans = n, l = n / 2 - 1, r = n - 1;
        while (l >= 0 && r >= n / 2)
        {
            if (2 * a[l] <= a[r])
            {
                l--;
                r--;
                ans--;
            }
            else
                l--;
        }
        cout << ans << endl;
    }
}
 

// File: DSA04014 - CẶP NGHỊCH THẾ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
long long Merge(long long *a, long long l, long long r, long long mid)
{
    long long p1 = mid - l + 1, p2 = r - mid, ans = 0;
    long long L[p1], R[p2];
    for (int i = 0; i < p1; i++)
        L[i] = a[l + i];
    for (int i = 0; i < p2; i++)
        R[i] = a[mid + i + 1];
    int i = 0, j = 0, k = l;
    while (i < p1 and j < p2)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
        {
            a[k++] = R[j++];
            ans += p1 - i;
        }
    }
    while (i < p1)
        a[k++] = L[i++];
    while (j < p2)
        a[k++] = R[j++];
    return ans;
}
long long calc(long long *a, int l, int r)
{
    long long ans = 0;
    int mid;
    if (l < r)
    {
        mid = (l + r) >> 1;
        ans += calc(a, l, mid);
        ans += calc(a, mid + 1, r);
        ans += Merge(a, l, r, mid);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << calc(a, 0, n - 1) << endl;
    }
}
 

// File: DSA04015 - TÍNH FLOOR(X).cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n + 2);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        a[n + 1] = 1e18;
        int ans = lower_bound(a.begin(), a.end() - 1, k) - a.begin();
        if (a[ans] != k)
            ans--;
        if (ans != -1)
            ans++;
        cout << ans << endl;
    }
}
 

// File: DSA04016 - PHẦN TỬ THỨ K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int a[n], b[m], p1 = 0, p2 = 0, ans;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        while (k--)
        {
            if (p1 == n - 1)
                ans = b[p2++];
            if (p2 == m - 1)
                ans = a[p1++];
            if (a[p1] < b[p2])
            {
                ans = a[p1];
                p1++;
            }
            else
            {
                ans = b[p2];
                p2++;
            }
        }
        cout << ans << endl;
    }
}
 

// File: DSA04017 - PHẦN TỬ KHÁC NHAU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n - 1; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }
}
 

// File: DSA04018 - ĐẾM SỐ 0.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int m = lower_bound(a, a + n, 1) - a;
        cout << m << endl;
    }
}
 

// File: DSA04019 - CẶP ĐIỂM GẦN NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
double distance(pair<double, double> a, pair<double, double> b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        double ans = 1e9;
        vector<pair<double, double>> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
            b[i].second = a[i].first;
            b[i].first = a[i].second;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i = 1; i < n; i++)
        {
            ans = min(ans, distance(a[i], a[i - 1]));
            ans = min(ans, distance(b[i], b[i - 1]));
        }
        cout << setprecision(6) << fixed << ans << endl;
    }
}
 

// File: DSA04020 - TÌM KIẾM NHỊ PHÂN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int m = lower_bound(a, a + n, k) - a;
        if (a[m] != k)
            cout << "NO" << endl;
        else
            cout << m + 1 << endl;
    }
}
 

// File: DSA04021 - DÃY XÂU NHỊ PHÂN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long a[n + 1];
        a[1] = 1;
        a[2] = 1;
        for (int i = 3; i <= n; i++)
            a[i] = a[i - 1] + a[i - 2];
        while (1)
        {
            if (n == 1)
            {
                cout << "0\n";
                break;
            }
            else if (n == 2)
            {
                cout << "1\n";
                break;
            }
            if (k > a[n - 2])
            {
                k -= a[n - 2];
                n--;
            }
            else
                n -= 2;
        }
    }
}
 

// File: DSA04022 - KÝ TỰ THỨ K TRONG XÂU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long a[n + 1];
        for (long long i = 1; i <= n; i++)
            a[i] = pow(2, i - 1);
        for (int i = n; i >= 1; i--)
        {
            if (k == a[i])
            {
                cout << (char)(i + 'A' - 1) << endl;
                break;
            }
            else if (k > a[i])
                k -= a[i];
        }
    }
}
 

// File: DSA04023 - KHOẢNG CÁCH NHỎ HƠN K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		long long s = 0;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			int x = lower_bound(a + i + 1, a + n, a[i] + k) - a;
			s += x - i - 1;
		}
		cout << s << endl;
	}
}
 

// File: DSA04024 - LŨY THỪA MA TRẬN 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
	long long x[10][10];
};
int n;
long long mod = 1000000007;
struct data operator*(struct data a, struct data b)
{
	struct data xx;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			xx.x[i][j] = 0;
			for (int k = 0; k < n; k++)
				xx.x[i][j] = (xx.x[i][j] + (a.x[i][k] * b.x[k][j]) % mod) % mod;
		}
	}
	return xx;
};
struct data poww(struct data a, long long k)
{
	if (k == 1)
		return a;
	if (k % 2 == 1)
		return a * poww(a, k - 1);
	struct data xx = poww(a, k / 2);
	return xx * xx;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		long long k, s = 0;
		cin >> n >> k;
		struct data a;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a.x[i][j];
		a = poww(a, k);
		for (int i = 0; i < n; i++)
			s = (s + a.x[i][n - 1]) % mod;
		cout << s << endl;
	}
}
 

// File: DSA04025 - DÃY SỐ VÔ HẠN.cpp
#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7, F[2][2], M[2][2];
void Mul(long long f[2][2], long long m[2][2])
{
    long long x = (f[0][0] * m[0][0] % mod + f[0][1] * m[1][0] % mod) % mod;
    long long y = (f[0][0] * m[0][1] % mod + f[0][1] * m[1][1] % mod) % mod;
    long long z = (f[1][0] * m[0][0] % mod + f[1][1] * m[1][0] % mod) % mod;
    long long t = (f[1][0] * m[0][1] % mod + f[1][1] * m[1][1] % mod) % mod;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = t;
}
void Pow(long long f[2][2], long long n)
{
    if (n <= 1)
        return;
    Pow(f, n / 2);
    Mul(f, f);
    if (n & 1)
        Mul(f, M);
}
long long fibo(long long n)
{
    F[0][0] = F[0][1] = F[1][0] = 1;
    F[1][1] = 0;
    M[0][0] = M[0][1] = M[1][0] = 1;
    M[1][1] = 0;
    Pow(F, n - 1);
    return F[0][0];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << fibo(n) << endl;
    }
}
 

// File: DSA04030 - SỐ TRIBONACCI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct matrix
{
	long long a[5][5] = {};
};

long long n = 4, MOD = 1e15 + 7;

long long nhan(long long x, long long y)
{
	if (y == 1)
		return x % MOD;
	if (y == 0)
		return 0;
	long long tmp = nhan(x, y / 2) % MOD;
	if (y % 2 == 0)
		return (2 * tmp) % MOD;
	return ((2 * tmp) % MOD + x % MOD) % MOD;
}

matrix mulMatrix(matrix A, matrix B)
{
	matrix tmp;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			long long sum = 0;
			for (int k = 1; k <= n; k++)
				sum = (sum % MOD + nhan(A.a[i][k], B.a[k][j]) % MOD) % MOD;
			tmp.a[i][j] = sum;
		}
	}
	return tmp;
}

matrix operator^(matrix A, long long k)
{
	if (k == 1)
		return A;
	matrix tmp = A ^ (k / 2);
	matrix c = mulMatrix(tmp, tmp);
	if (k % 2 == 0)
		return c;
	return mulMatrix(c, A);
}

matrix createI()
{
	matrix res;
	for (int i = 1; i <= n; i++)
		res.a[i][i] = 1;
	return res;
}

matrix operator+(matrix A, matrix B)
{
	matrix c;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			c.a[i][j] = (A.a[i][j] + B.a[i][j]) % MOD;
	return c;
}

matrix sumPowMatrix(matrix A, long long k)
{
	if (k == 1)
		return A;
	long long h = k / 2;
	matrix c = mulMatrix((createI() + (A ^ h)), sumPowMatrix(A, h));
	if (k % 2 == 1)
		c = c + (A ^ k);
	return c;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		long long k, ans = 0;
		matrix A;
		cin >> k;
		if (k <= 3)
		{
			cout << k * (k + 1) / 2 << endl;
			continue;
		}
		A.a[1][1] = 1; A.a[1][2] = 1; A.a[1][3] = 0; A.a[1][4] = 0;
		A.a[2][1] = 0; A.a[2][2] = 1; A.a[2][3] = 1; A.a[2][4] = 1;
		A.a[3][1] = 0; A.a[3][2] = 1; A.a[3][3] = 0; A.a[3][4] = 0;
		A.a[4][1] = 0; A.a[4][2] = 0; A.a[4][3] = 1; A.a[4][4] = 0;
		matrix B = A ^ (k - 2);
		for (int i = 2; i <= n; i++)
		{
			ans += nhan(B.a[1][i], (5 - i));
			ans %= MOD;
		}
		ans += nhan(B.a[1][1], 3);
		ans %= MOD;
		cout << ans << endl;
	}
}
 

// File: DSA04035 - TÍNH LŨY THỪA.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
long long mod = 1e9 + 7;
long long poww(long long n, long long k)
{
    if (k == 1)
        return n;
    long long x = poww(n, k / 2);
    if (k % 2 == 0)
        return (x * x) % mod;
    else
        return (((x * x) % mod) * n) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (1)
    {
        long long n, k;
        cin >> n >> k;
        if (n == 0 && k == 0)
            return 0;
        if (k == 0)
            cout << 1 << endl;
        else
            cout << poww(n, k) << endl;
    }
}
 

// File: DSA05001 - XÂU CON CHUNG DÀI NHẤT.cpp
#include <bits/stdc++.h>
using namespace std;
int LCS(string s1, string s2)
{
    int F[s1.size() + 1][s2.size() + 1] = {};
    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            if (s1[i] == s2[j])
                F[i + 1][j + 1] = F[i][j] + 1;
            else
                F[i + 1][j + 1] = max(F[i][j + 1], F[i + 1][j]);
        }
    }
    return F[s1.size()][s2.size()];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        cout << LCS(a, b) << endl;
    }
}
 

// File: DSA05003 - DÃY CON CHUNG DÀI NHẤT CỦA BA XÂU.cpp
#include <bits/stdc++.h>
using namespace std;
int LCS(string s1, string s2, string s3)
{
    int F[s1.size() + 1][s2.size() + 1][s3.size() + 1] = {};
    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            for (int k = 0; k < s3.size(); k++)
            {
                if (s1[i] == s2[j] && s2[j] == s3[k])
                    F[i + 1][j + 1][k + 1] = F[i][j][k] + 1;
                else
                    F[i + 1][j + 1][k + 1] = max(F[i][j + 1][k + 1], max(F[i + 1][j + 1][k], F[i + 1][j][k + 1]));
            }
        }
    }
    return F[s1.size()][s2.size()][s3.size()];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        string a, b, c;
        cin >> n >> m >> k >> a >> b >> c;
        cout << LCS(a, b, c) << endl;
    }
}
 

// File: DSA05004 - DÃY CON TĂNG DÀI NHẤT.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n], l[n], ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        l[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && l[i] <= l[j])
                l[i] = l[j] + 1;
        }
        ans = max(ans, l[i]);
    }
    cout << ans;
}
 

// File: DSA05005 - SỐ BƯỚC ÍT NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, s = 0;
        cin >> n;
        int a[n], l[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            l[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (a[i] >= a[j] && l[i] <= l[j])
                    l[i] = l[j] + 1;
            }
            s = max(s, l[i]);
        }
        cout << n - s << endl;
    }
}
 

// File: DSA05006 - TỔNG LỚN NHẤT CỦA DÃY CON TĂNG DẦN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], l[n], ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            l[i] = a[i];
            for (int j = 0; j < i; j++)
                if (a[i] > a[j])
                    l[i] = max(l[i], l[j] + a[i]);
            ans = max(ans, l[i]);
        }
        cout << ans << endl;
    }
}
 

// File: DSA05007 - TỔNG LỚN NHẤT CỦA DÃY CON KHÔNG KỀ NHAU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 2];
        a[0] = a[1] = 0;
        for (int i = 2; i <= n + 1; i++)
        {
            cin >> a[i];
            a[i] = max(a[i] + a[i - 2], a[i - 1]);
        }
        cout << max(a[n], a[n + 1]) << endl;
    }
}
 

// File: DSA05008 - DÃY CON CÓ TỔNG BẰNG S.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n + 5], l[k + 5] = {};
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        l[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = k; j >= a[i]; j--)
            {
                if (l[j] == 0 && l[j - a[i]] == 1)
                    l[j] = 1;
            }
        }
        if (l[k] == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA05009 - TẬP CON BẰNG NHAU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, s;
int a[105];
string ans;
void Try(int pos, int k)
{
    if (ans == "YES")
        return;
    if (2 * k == s)
    {
        ans = "YES";
        return;
    }
    if (pos < n)
    {
        if (2 * (k + a[pos]) <= s)
            Try(pos + 1, k + a[pos]);
        Try(pos + 1, k);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        s = 0;
        ans = "NO";
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        if (s % 2 == 0)
            Try(0, 0);
        cout << ans << endl;
    }
}
 

// File: DSA05010 - DÃY CON DÀI NHẤT CÓ TỔNG CHIA HẾT CHO K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n + 1);
        vector<vector<long long>> f(n + 1, vector<long long>(k, 0));
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] %= k;
        }
        for (int i = 1; i < k; i++)
            f[1][i] = -1e18;
        f[1][a[1]] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                f[i][j] = max(f[i - 1][j], f[i - 1][(j - a[i] + k) % k] + 1);
            }
        }
        cout << f[n][0] << endl;
    }
}
 

// File: DSA05011 - SỐ CÓ TỔNG CHỮ SỐ BẰNG K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long f[105][50005] = {}, mod = 1e9 + 7;
    for (int i = 1; i <= 9; i++)
        f[1][i] = 1;
    for (int i = 2; i <= 100; i++)
    {
        for (int j = 5000; j >= 0; j--)
        {
            for (int k = 0; k <= 9; k++)
            {
                if (j >= k)
                {
                    f[i][j] += f[i - 1][j - k];
                    f[i][j] %= mod;
                }
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << f[n][k] << endl;
    }
}
 

// File: DSA05012 - TỔ HỢP C(n, k).cpp
#include <stdio.h>
int a[1001][1001], mod = 1e9 + 7;
int main()
{
    a[0][0] = 1;
    for (int i = 1; i < 1001; i++)
    {
        a[i][0] = 1;
        for (int j = 1; j < 1001; j++)
            a[i][j] = (a[i - 1][j - 1] % mod + a[i - 1][j] % mod) % mod;
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        printf("%d\n", a[n][k]);
    }
}
 

// File: DSA05013 - BẬC THANG.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, mod = 1e9 + 7;
        cin >> n >> k;
        long long a[n] = {}, b[n];
        for (int i = 0; i < min(n, k); i++)
            a[i] = 1;
        b[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (i <= k)
                a[i] = (a[i] + b[i - 1]) % mod;
            else
            {
                long long m = (b[i - 1] - b[i - k - 1]) % mod;
                if (m < 0)
                    m += mod;
                a[i] = (a[i] + m) % mod;
            }
            b[i] = (b[i - 1] + a[i]) % mod;
        }
        cout << a[n - 1] << endl;
    }
}
 

// File: DSA05014 - CATALAN NUMBER.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, s[200], a[200], len;
void add(int x, int delta)
{
    for (int i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            s[i] += delta;
            x /= i;
        }
    }
    if (x != 1)
        s[x] += delta;
}
void mul(int x)
{
    len += 5;
    for (int i = 0; i < len; i++)
        a[i] *= x;
    for (int i = 0; i < len; i++)
    {
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    while (len > 0 && !a[len - 1])
        len--;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= n; i++)
            add(2 * n - i + 1, 1);
        for (int i = 1; i <= n + 1; i++)
            add(i, -1);
        a[0] = len = 1;
        for (int i = 1; i < 200; i++)
        {
            while (s[i]--)
                mul(i);
        }
        for (int i = len - 1; i >= 0; i--)
            cout << a[i];
        cout << endl;
    }
}
 

// File: DSA05015 - TÍNH P(N,K).cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long P[1001][1001] = {}, mod = 1e9 + 7;
	for (int i = 1; i <= 1000; i++)
		P[i][1] = i;
	for (int i = 2; i <= 1000; i++)
		for (int j = 2; j <= i; j++)
			P[i][j] = (P[i - 1][j - 1] * i) % mod;
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		cout << P[n][k] << endl;
	}
}
 

// File: DSA05016 - SỐ UGLY.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<long long> s;
    vector<long long> v;
    s.insert(1);
    while (1)
    {
        for (auto i : s)
        {
            if (i > 1e18)
                break;
            v.push_back(i * 2);
            v.push_back(i * 3);
            v.push_back(i * 5);
        }
        for (auto i : v)
            s.insert(i);
        v.clear();
        if (s.size() > 1e4)
            break;
    }
    for (auto i : s)
        v.push_back(i);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << v[n - 1] << endl;
    }
}
 

// File: DSA05017 - DÃY SỐ BI-TONIC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], l[n], r[n], ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            l[i] = a[i];
            for (int j = 0; j < i; j++)
                if (a[i] > a[j])
                    l[i] = max(l[i], l[j] + a[i]);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            r[i] = a[i];
            for (int j = i + 1; j < n; j++)
                if (a[i] > a[j])
                    r[i] = max(r[i], r[j] + a[i]);
            ans = max(ans, l[i] + r[i] - a[i]);
        }
        cout << ans << endl;
    }
}
 

// File: DSA05018 - XÂU CON ĐỐI XỨNG DÀI NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int n = s.size(), ans = 1;
		vector<vector<bool>> a(n, vector<bool>(n));
		for (int i = 0; i < n; i++)
			a[i][i] = 1;
		for (int i = 1; i < n; i++)
			for (int j = 0; j < n - i; j++)
			{
				int k = i + j;
				a[j][k] = ((j + 1 > k - 1 || a[j + 1][k - 1]) && s[j] == s[k]);
				if (a[j][k])
					ans = i + 1;
			}
		cout << ans << endl;
	}
}
 

// File: DSA05019 - HÌNH VUÔNG LỚN NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, s = 0;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                if (a[j][i] == 1)
                    a[j][i] = a[j - 1][i] + 1;
        for (int i = 0; i < n; i++)
        {
            stack<int> b, c;
            int l[m], r[m];
            for (int j = 0; j < m; j++)
            {
                while (!b.empty() && a[i][j] <= a[i][b.top()])
                    b.pop();
                if (b.empty())
                    l[j] = 0;
                else
                    l[j] = b.top() + 1;
                b.push(j);
            }
            for (int j = m - 1; j >= 0; j--)
            {
                while (!c.empty() && a[i][j] <= a[i][c.top()])
                    c.pop();
                if (c.empty())
                    r[j] = m - 1;
                else
                    r[j] = c.top() - 1;
                c.push(j);
            }
            for (int j = 0; j < m; j++)
                s = max(s, min(r[j] - l[j] + 1, a[i][j]));
        }
        cout << s << endl;
    }
}
 

// File: DSA05020 - ĐƯỜNG ĐI NHỎ NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n + 1][m + 1], b[n + 1][m + 1] = {};
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i == 1)
                    b[i][j] = b[i][j - 1];
                else if (j == 1)
                    b[i][j] = b[i - 1][j];
                else
                    b[i][j] = min(b[i - 1][j - 1], min(b[i - 1][j], b[i][j - 1]));
                b[i][j] += a[i][j];
            }
        }
        cout << b[n][m] << endl;
    }
}
 

// File: DSA05021 - CẶP SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int l[n], maz = 0;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i].first >> a[i].second;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            l[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (a[i].first > a[j].second && l[i] <= l[j])
                    l[i] = l[j] + 1;
            }
            maz = max(maz, l[i]);
        }
        cout << maz << endl;
    }
}
 

// File: DSA05022 - KÝ TỰ GIỐNG NHAU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y, z;
        cin >> n >> x >> y >> z;
        int a[n + 2];
        a[1] = x;
        a[2] = a[1] + min(x, z);
        for (int i = 3; i <= n + 1; i++)
        {
            a[i] = a[i - 1] + x;
            if (i % 2 == 0)
                a[i] = min(a[i], a[i / 2] + z);
            a[i - 1] = min(a[i - 1], a[i] + y);
        }
        cout << a[n] << endl;
    }
}
 

// File: DSA05023 - TỔNG CÁC XÂU CON.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        long long ans = 0, k = 1, n = a.size(), s;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            s = (long long)(a[i] - '0') * k;
            s *= n;
            ans += s;
            k = k * 10 + 1;
            n--;
        }
        cout << ans << endl;
    }
}
 

// File: DSA05024 - TỔNG BẰNG K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        long long f[k + 1] = {}, mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        f[0] = 1;
        for (int i = 1; i <= k; i++)
            for (int j = 0; j < n; j++)
                if (i >= a[j])
                    f[i] = (f[i] + f[i - a[j]]) % mod;
        cout << f[k] << endl;
    }
}
 

// File: DSA05025 - CON ẾCH.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long a[n] = {}, b[n];
		for (int i = 0; i < min(n, 3); i++)
			a[i] = 1;
		b[0] = 1;
		for (int i = 1; i < n; i++)
		{
			if (i <= 3)
				a[i] = (a[i] + b[i - 1]);
			else
				a[i] += b[i - 1] - b[i - 4];
			b[i] = b[i - 1] + a[i];
		}
		cout << a[n - 1] << endl;
	}
}
 

// File: DSA05026 - XEM PHIM.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int s, n;
	cin >> s >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector<vector<int>> l(n + 1, vector<int>(s + 1, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= s; j++)
			if (a[i] <= j)
				l[i][j] = max(l[i - 1][j - a[i]] + a[i], l[i - 1][j]);
			else
				l[i][j] = l[i - 1][j];
	cout << l[n][s];
}
 

// File: DSA05027 - CÁI TÚI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int a[n], b[n];
		vector<vector<int>> l(n, vector<int>(m + 1, 0));
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		for (int i = 0; i < n; i++)
			for (int j = 1; j <= m; j++)
			{
				if (i > 0)
				{
					if (a[i] <= j)
						l[i][j] = max(l[i - 1][j], l[i - 1][j - a[i]] + b[i]);
					else
						l[i][j] = l[i - 1][j];
				}
				else if (a[i] <= j)
					l[i][j] = b[i];
			}
		cout << l[n - 1][m] << endl;
	}
}
 

// File: DSA05028 - BIẾN ĐỔI XÂU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string s1, s2;
int dp()
{
    int m = s1.size(), n = s2.size();
    int f[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                f[i][j] = j;
            else if (j == 0)
                f[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                f[i][j] = f[i - 1][j - 1];
            else
                f[i][j] = 1 + min(f[i][j - 1], min(f[i - 1][j], f[i - 1][j - 1]));
        }
    }
    return f[m][n];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s1 >> s2;
        cout << dp() << endl;
    }
}
 

// File: DSA05029 - GIẢI MÃ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		s = ' ' + s;
		int n = s.size(), k;
		int a[n];
		a[0] = a[1] = 1;
		if (s[1] == '0')
		{
			cout << 0 << endl;
			continue;
		}
		for (int i = 2; i < n; i++)
		{
			if (s[i] == '0')
			{
				if (s[i - 1] > '2')
				{
					a[n - 1] = 0;
					break;
				}
				a[i] = 0;
			}
			else
				a[i] = a[i - 1];
			k = (s[i - 1] - '0') * 10 + s[i] - '0';
			if (k <= 26 && k >= 10)
				a[i] += a[i - 2];
		}
		cout << a[n - 1] << endl;
	}
}
 

// File: DSA05030 - DI CHUYỂN VỀ GỐC TỌA ĐỘ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<long long>> a(n + 1, vector<long long>(m + 1, 1));
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--)
                a[i][j] = a[i + 1][j] + a[i][j + 1];
        cout << a[0][0] << endl;
    }
}
 

// File: DSA05031 - TỔNG BÌNH PHƯƠNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        a[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            a[i] = 1e9;
            for (int j = 1; j <= sqrt(i); j++)
                if (a[i - j * j] != 1e9)
                    a[i] = min(a[i], a[i - j * j] + 1);
        }
        cout << a[n] << endl;
    }
}
 

// File: DSA05032 - XÂU ĐỐI XỨNG 1.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int f[n][n];
        for (int i = 0; i < n; i++)
            f[i][i] = 1;
        for (int k = 2; k <= n; k++)
        {
            for (int i = 0; i < n - k + 1; i++)
            {
                int j = i + k - 1;
                if (s[i] == s[j] && k == 2)
                    f[i][j] = 2;
                else if (s[i] == s[j])
                    f[i][j] = f[i + 1][j - 1] + 2;
                else
                    f[i][j] = max(f[i + 1][j], f[i][j - 1]);
            }
        }
        cout << n - f[0][n - 1] << endl;
    }
}

// File: DSA05033 - XÂU ĐỐI XỨNG 2.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int f[n][n];
        for (int i = 0; i < n; i++)
            f[i][i] = 1;
        for (int k = 2; k <= n; k++)
        {
            for (int i = 0; i < n - k + 1; i++)
            {
                int j = i + k - 1;
                if (s[i] == s[j] && k == 2)
                    f[i][j] = 2;
                else if (s[i] == s[j])
                    f[i][j] = f[i + 1][j - 1] + 2;
                else
                    f[i][j] = max(f[i + 1][j], f[i][j - 1]);
            }
        }
        cout << n - f[0][n - 1] << endl;
    }
}

// File: DSA05034 - TỔNG SỐ CÁCH DI CHUYỂN.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, mod = 1e9 + 7;
        cin >> n >> k;
        long long a[n] = {}, b[n];
        for (int i = 0; i < min(n, k); i++)
            a[i] = 1;
        b[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (i <= k)
                a[i] = (a[i] + b[i - 1]) % mod;
            else
            {
                long long m = (b[i - 1] - b[i - k - 1]) % mod;
                if (m < 0)
                    m += mod;
                a[i] = (a[i] + m) % mod;
            }
            b[i] = (b[i - 1] + a[i]) % mod;
        }
        cout << a[n - 1] << endl;
    }
}
 

// File: DSA05035 - CHỮ SỐ SẮP XẾP TĂNG DẦN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a[11], f[101] = {}, mod = 1e9 + 7;
    for (int i = 1; i <= 10; i++)
        a[i] = 1;
    f[1] = 10;
    for (int i = 2; i <= 100; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            long long s = 0;
            for (int k = j; k <= 9; k++)
                s += a[k];
            a[j] = s;
            f[i] = (f[i] + s) % mod;
        }
    }
    for (int i = 2; i <= 100; i++)
        f[i] = (f[i] + f[i - 1]) % mod;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
}
 

// File: DSA05036 - TĂNG - GIẢM.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int f[n], ans = 0;
        pair<float, float> a[n];
        for (int i = 0; i < n; i++)
        {
            f[i] = 1;
            cin >> a[i].first >> a[i].second;
            for (int j = 0; j < i; j++)
                if (a[i].first > a[j].first && a[i].second < a[j].second && f[i] <= f[j])
                    f[i] = f[j] + 1;
            ans = max(ans, f[i]);
        }
        cout << ans << endl;
    }
}
 

// File: DSA05037 - CHỮ SỐ SẮP XẾP TĂNG DẦN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a[11], f[101] = {}, mod = 1e9 + 7;
    for (int i = 1; i <= 10; i++)
        a[i] = 1;
    f[1] = 10;
    for (int i = 2; i <= 100; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            long long s = 0;
            for (int k = j; k <= 9; k++)
                s += a[k];
            a[j] = s;
            f[i] = (f[i] + s) % mod;
        }
    }
    for (int i = 2; i <= 100; i++)
        f[i] = (f[i] + f[i - 1]) % mod;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
}
 

// File: DSA05038 - DÃY CON TĂNG DÀI NHẤT 2 CHIỀU.cpp
#include <bits/stdc++.h>
using namespace std;
int n, ans;
pair<int, int> a;
set<pair<int, int>> s[100000];
bool check(const pair<int, int> a, const pair<int, int> b)
{
    return ((a.first < b.first) && (a.second < b.second));
}
bool kt(set<pair<int, int>> &st)
{
    for (set<pair<int, int>>::iterator i = st.begin(); i != st.end(); i++)
    {
        if (check(*i, a))
            return 1;
        else if (i->first >= a.first)
            break;
    }
    return 0;
}
int binary_search(int l, int r)
{
    while (l < r)
    {
        int m = (l + r) / 2;
        if (kt(s[m]))
            l = m + 1;
        else
            r = m;
    }
    return l;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a.first >> a.second;
        int pos = binary_search(0, n);
        if (pos < n)
        {
            set<pair<int, int>>::iterator k = ++s[pos].insert(a).first;
            while (k != s[pos].end())
            {
                if (check(a, *k))
                    s[pos].erase(k++);
                else
                    k++;
            }
        }
    }
    while (ans < n && s[ans].size())
        ans++;
    cout << ans;
}

// File: DSA05040 - DÃY TAM GIÁC DÀI NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, s = 0;
		cin >> n;
		int a[n + 1], maxa[n + 1], mina[n + 1];
		maxa[n] = mina[n] = n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = n - 1; i >= 1; i--)
		{
			if (a[i] > a[i + 1])
				mina[i] = mina[i + 1];
			else
				mina[i] = i;
			if (a[i] < a[i + 1])
				maxa[i] = maxa[i + 1];
			else
				maxa[i] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			s = max(s, mina[maxa[i]] - i + 1);
		}
		cout << s << endl;
	}
}
 

// File: DSA05041 - BIẾN ĐỔI VỀ XÂU ĐỐI XỨNG.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int f[n][n];
        for (int i = 0; i < n; i++)
            f[i][i] = 1;
        for (int k = 2; k <= n; k++)
        {
            for (int i = 0; i < n - k + 1; i++)
            {
                int j = i + k - 1;
                if (s[i] == s[j] && k == 2)
                    f[i][j] = 2;
                else if (s[i] == s[j])
                    f[i][j] = f[i + 1][j - 1] + 2;
                else
                    f[i][j] = max(f[i + 1][j], f[i][j - 1]);
            }
        }
        cout << n - f[0][n - 1] << endl;
    }
}

// File: DSA05042 - DÃY CON LIÊN TIẾP TỔNG BẰNG K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r, x, ok = 0;
        long long k;
        cin >> n >> k;
        long long a[n + 1];
        a[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        for (int i = 1; i <= n; i++)
        {
            l = i;
            r = n;
            while (l <= r)
            {
                x = (l + r) / 2;
                if (a[x] - a[i - 1] == k)
                {
                    ok = 1;
                    break;
                }
                else if (a[x] - a[i - 1] > k)
                {
                    r = x - 1;
                }
                else
                    l = x + 1;
            }
            if (ok)
                break;
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA05043 - SỐ THUẬN NGHỊCH.cpp
#include <bits/stdc++.h>
using namespace std;
bool a[1001][1001];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size(), ans = 1;
        for (int i = 0; i < n; i++)
            a[i][i] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                int k = i + j;
                if (i + j < n)
                {
                    a[j][k] = ((j + 1 > k - 1 || a[j + 1][k - 1]) && s[j] == s[k]);
                    if (a[j][k])
                        ans = i + 1;
                }
            }
        }
        cout << ans << endl;
    }
}

// File: DSA05047 - CHỌN Ô.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = -1e9, s = -1e9;
        cin >> n;
        int a[4][n + 1], f[n + 1][11] = {}, d[] = {0, 1, 2, 4, 5, 8, 9, 10};
        for (int i = 0; i < 4; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                for (int i = 0; i < 4; i++)
                    if (d[k] & (1 << i))
                        f[j][d[k]] += a[i][j];
                int x = -1e9;
                for (int i = 0; i < 8; i++)
                    if ((d[k] | d[i]) == (d[k] ^ d[i]))
                        x = max(x, f[j - 1][d[i]]);
                f[j][d[k]] += x;
            }
        }
        for (int i = 0; i < 8; i++)
            s = max(f[n][d[i]], s);
        for (int i = 0; i < 4; i++)
            for (int j = 1; j <= n; j++)
                ans = max(ans, a[i][j]);
        if (ans < 0)
            cout << ans << endl;
        else
            cout << s << endl;
    }
}

// File: DSA06001 - SẮP XẾP XEN KẼ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for (int i = 1; i < n; i += 2)
        {
            b[i] = a[(i - 1) / 2];
        }
        for (int i = 0; i < n; i += 2)
        {
            b[i] = a[n - i / 2 - 1];
        }
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";
        cout << endl;
    }
}
 

// File: DSA06002 - SẮP XẾP THEO GIÁ TRỊ TUYỆT ĐỐI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            v[i].first = abs(a[i] - k);
            v[i].second = i;
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
            cout << a[v[i].second] << " ";
        cout << endl;
    }
}
 

// File: DSA06003 - ĐỔI CHỖ ÍT NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k, ans = 0;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n - 1; i++)
		{
			k = i;
			for (int j = i + 1; j < n; j++)
				if (a[j] < a[k])
					k = j;
			if (k != i)
				ans++;
			swap(a[k], a[i]);
		}
		cout << ans << endl;
	}
}
 

// File: DSA06004 - HỢP VÀ GIAO CỦA HAI DÃY SỐ 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m;
        map<int, int> a, b, c;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            a[x]++;
            c[x]++;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            b[x]++;
            c[x]++;
        }
        for (auto i : c)
            cout << i.first << " ";
        cout << endl;
        for (auto i : a)
        {
            if (b[i.first] > 0)
                cout << i.first << " ";
        }
        cout << endl;
    }
}
 

// File: DSA06005 - HỢP VÀ GIAO CỦA HAI DÃY SỐ 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m;
        map<int, int> a, b, c;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            a[x]++;
            c[x]++;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            b[x]++;
            c[x]++;
        }
        for (auto i : c)
            cout << i.first << " ";
        cout << endl;
        for (auto i : a)
        {
            if (b[i.first] > 0)
                cout << i.first << " ";
        }
        cout << endl;
    }
}
 

// File: DSA06006 - SẮP XẾP [0 1 2].cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, a[3] = {};
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            a[x]++;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < a[i]; j++)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}
 

// File: DSA06007 - SẮP XẾP DÃY CON LIÊN TỤC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n + 1], b[n + 1], s = 0, l, r, ma = 0, mi = 1e9;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (a[i] > s)
				s = a[i];
			b[i] = s;
		}
		for (int i = 1; i <= n - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				l = i;
				break;
			}
		}
		for (int i = n; i >= 2; i--)
		{
			if (a[i] < a[i - 1])
			{
				r = i;
				break;
			}
		}
		for (int i = l; i <= r; i++)
		{
			if (a[i] > ma)
				ma = a[i];
			if (a[i] < mi)
				mi = a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			if (a[i] > mi)
			{
				cout << i << " ";
				break;
			}
		}
		for (int i = n; i >= 1; i--)
		{
			if (a[i] <= ma)
			{
				cout << i << endl;
				break;
			}
		}
	}
}
 

// File: DSA06008 - ĐẾM CẶP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int count(int x, int y[], int n, int a[])
{
	if (x == 0)
		return 0;
	if (x == 1)
		return a[0];
	int it = upper_bound(y, y + n, x) - y;
	int ans = n - it;
	ans += (a[0] + a[1]);
	if (x == 2)
		ans -= (a[3] + a[4]);
	if (x == 3)
		ans += a[2];
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int x[n], y[m], a[5] = {}, s = 0;
		for (int i = 0; i < n; i++)
			cin >> x[i];
		for (int i = 0; i < m; i++)
			cin >> y[i];
		for (int i = 0; i < n; i++)
		{
			if (y[i] < 5)
				a[y[i]]++;
		}
		sort(y, y + n);
		for (int i = 0; i < m; i++)
			s += count(x[i], y, n, a);
		cout << s << endl;
	}
}
 

// File: DSA06009 - CẶP SỐ TỔNG BẰNG K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k, x, s = 0;
		cin >> n >> k;
		int a[n];
		map<int, int> m;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			m[x]++;
		}
		for (auto i : m)
		{
			if (i.first * 2 == k)
				s += i.second * (i.second - 1);
			else
				s += i.second * m[k - i.first];
		}
		s /= 2;
		cout << s << endl;
	}
}
 

// File: DSA06010 - SẮP XẾP CHỮ SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, x, a[10] = {};
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			while (x != 0)
			{
				int k = x % 10;
				a[k]++;
				x /= 10;
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (a[i] > 0)
				cout << i << " ";
		}
		cout << endl;
	}
}
 

// File: DSA06011 - TỔNG GẦN 0 NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, s = 1e7;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (abs(a[i] + a[j]) < abs(s))
					s = a[i] + a[j];
			}
		}
		cout << s << endl;
	}
}
 

// File: DSA06012 - PHẦN TỬ LỚN NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		for (int i = n - 1; i >= n - k; i--)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}
}
 

// File: DSA06013 - SỐ LẦN XUẤT HIỆN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k, s = 0;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] == k)
				s++;
		}
		if (s == 0)
			cout << -1 << endl;
		else
			cout << s << endl;
	}
}
 

// File: DSA06014 - TỔNG CẶP SỐ NGUYÊN TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool nto(int n)
{
	if (n < 2)
		return 0;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, ok = 0;
		cin >> n;
		for (int i = 2; i <= n / 2; i++)
		{
			if (nto(i) == 1 && nto(n - i) == 1)
			{
				ok = 1;
				cout << i << " " << n - i << endl;
				break;
			}
		}
		if (ok == 0)
			cout << -1 << endl;
	}
}
 

// File: DSA06015 - MERGE SORT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
}
 

// File: DSA06016 - TÍCH LỚN NHẤT - NHỎ NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, x, maxa = -1e9, minb = 1e9;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			maxa = max(maxa, x);
		}
		for (int i = 0; i < m; i++)
		{
			cin >> x;
			minb = min(minb, x);
		}
		cout << (long long)maxa * minb << endl;
	}
}
 

// File: DSA06017 - TRỘN HAI DÃY.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> a(n + m);
		for (int i = 0; i < n + m; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		for (int i = 0; i < n + m; i++)
			cout << a[i] << " ";
		cout << endl;
	}
}
 

// File: DSA06018 - BỔ SUNG PHẦN TỬ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, s = 0;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 1; i < n; i++)
			if (a[i] != a[i - 1])
				s += a[i] - a[i - 1] - 1;
		cout << s << endl;
	}
}
 

// File: DSA06019 - SẮP XẾP THEO SỐ LẦN XUẤT HIỆN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second > b.second)
		return 1;
	if (a.second == b.second && a.first < b.first)
		return 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		map<int, int> ts;
		vector<pair<int, int>> p;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			ts[a[i]]++;
		}
		for (int i = 0; i < n; i++)
			p.push_back(make_pair(a[i], ts[a[i]]));
		sort(p.begin(), p.end(), cmp);
		for (int i = 0; i < p.size(); i++)
			cout << p[i].first << ' ';
		cout << endl;
	}
}
 

// File: DSA06020 - TÌM KIẾM.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, x, k, ans = -1;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (x == k)
				ans = 1;
		}
		cout << ans << endl;
	}
}
 

// File: DSA06021 - TÌM KIẾM TRONG DÃY SẮP XẾP VÒNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k, x, pos;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (x == k)
				pos = i;
		}
		cout << pos + 1 << endl;
	}
}
 

// File: DSA06022 - SỐ NHỎ NHẤT VÀ NHỎ THỨ HAI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, min1 = 1e9, min2 = 1e9;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			min1 = min(min1, a[i]);
		}
		for (int i = 0; i < n; i++)
		{
			if (a[i] < min2 && a[i] > min1)
				min2 = a[i];
		}
		if (min2 == 1e9)
			cout << -1 << endl;
		else
			cout << min1 << " " << min2 << endl;
	}
}
 

// File: DSA06023 - SẮP XẾP ĐỔI CHỖ TRỰC TIẾP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
		cout << "Buoc " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cout << a[j] << " ";
		cout << endl;
	}
}
 

// File: DSA06024 - SẮP XẾP CHỌN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[k])
				k = j;
		swap(a[k], a[i]);
		cout << "Buoc " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cout << a[j] << " ";
		cout << endl;
	}
}
 

// File: DSA06025 - SẮP XẾP CHÈN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		int k = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > k)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = k;
		cout << "Buoc " << i << ": ";
		for (j = 0; j <= i; j++)
			cout << a[j] << " ";
		cout << endl;
	}
}
 

// File: DSA06026 - SẮP XẾP NỔI BỌT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, b = 1;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++)
	{
		bool k = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				k = true;
			}
		}
		if (k == false)
			break;
		cout << "Buoc " << b++ << ": ";
		for (int j = 0; j < n; j++)
			cout << a[j] << " ";
		cout << endl;
	}
}
 

// File: DSA06027 - SẮP XẾP ĐỔI CHỖ TRỰC TIẾP - LIỆT KÊ NGƯỢC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int b = n - 1;
		vector<int> a(n);
		stack<vector<int>> st;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[i] > a[j])
					swap(a[i], a[j]);
			}
			st.push(a);
		}
		while (st.size())
		{
			a = st.top();
			st.pop();
			cout << "Buoc " << b-- << ": ";
			for (int j = 0; j < n; j++)
				cout << a[j] << " ";
			cout << endl;
		}
	}
}
 

// File: DSA06028 - SẮP XẾP CHỌN - LIỆT KÊ NGƯỢC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int b = n - 1;
	vector<int> a(n);
	stack<vector<int>> st;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[k])
				k = j;
		swap(a[k], a[i]);
		st.push(a);
	}
	while (st.size())
	{
		a = st.top();
		st.pop();
		cout << "Buoc " << b-- << ": ";
		for (int j = 0; j < n; j++)
			cout << a[j] << " ";
		cout << endl;
	}
}
 

// File: DSA06029 - SẮP XẾP CHÈN - LIỆT KÊ NGƯỢC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int b = n - 1;
	vector<int> a(n);
	stack<vector<int>> st;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		int k = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > k)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = k;
		st.push(a);
	}
	while (st.size())
	{
		a = st.top();
		st.pop();
		cout << "Buoc " << b-- << ": ";
		for (int j = 0; j <= b + 1; j++)
			cout << a[j] << " ";
		cout << endl;
	}
}
 

// File: DSA06030 - SẮP XẾP NỔI BỌT - LIỆT KÊ NGƯỢC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, b;
		cin >> n;
		vector<int> a(n);
		stack<vector<int>> st;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n - 1; i++)
		{
			bool k = false;
			for (int j = 0; j < n - i - 1; j++)
			{
				if (a[j] > a[j + 1])
				{
					swap(a[j], a[j + 1]);
					k = true;
				}
			}
			if (k == false)
				break;
			st.push(a);
		}
		b = st.size();
		while (st.size())
		{
			a = st.top();
			st.pop();
			cout << "Buoc " << b-- << ": ";
			for (int j = 0; j < n; j++)
				cout << a[j] << " ";
			cout << endl;
		}
	}
}
 

// File: DSA06031 - PHẦN TỬ LỚN NHẤT TRONG DÃY CON.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[n];
		deque<int> st;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; ++i)
		{
			while (st.size() && a[st.back()] <= a[i])
				st.pop_back();
			st.push_back(i);
			if (st.front() + k <= i)
				st.pop_front();
			if (i >= k - 1)
				cout << a[st.front()] << " ";
		}
		cout << endl;
	}
}
 

// File: DSA06032 - BỘ BA SỐ CÓ TỔNG NHỎ HƠN K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		long long s = 0;
		cin >> n >> k;
		long long a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				int x = lower_bound(a + j + 1, a + n, k - a[i] - a[j]) - a;
				s += x - j - 1;
			}
		}
		cout << s << endl;
	}
}
 

// File: DSA06033 - KHOẢNG CÁCH XA NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
	{
		return a.second > b.second;
	}
	return a.first < b.first;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		pair<int, int> a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].first;
			a[i].second = i;
		}
		sort(a, a + n);
		int ans = -1, Min = a[0].second, k = a[0].first;
		for (int i = 1; i < n; i++)
		{
			if (a[i].first > k)
				ans = max(ans, a[i].second - Min);
			if (Min > a[i].second)
			{
				Min = a[i].second;
				k = a[i].first;
			}
		}
		cout << ans << endl;
	}
}
 

// File: DSA06034 - CẶP SỐ CÓ TỔNG BẰNG K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[n];
		long long s = 0;
		map<int, long long> m;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			m[a[i]]++;
		}
		for (auto i : m)
		{
			if (i.first * 2 == k)
				s += i.second * (i.second - 1);
			else
				s += i.second * m[k - i.first];
		}
		cout << s / 2 << endl;
	}
}
 

// File: DSA06035 - DÃY TAM GIÁC DÀI NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, s = 0;
		cin >> n;
		int a[n + 1], maxa[n + 1], mina[n + 1];
		maxa[n] = mina[n] = n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = n - 1; i >= 1; i--)
		{
			if (a[i] > a[i + 1])
				mina[i] = mina[i + 1];
			else
				mina[i] = i;
			if (a[i] < a[i + 1])
				maxa[i] = maxa[i + 1];
			else
				maxa[i] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			s = max(s, mina[maxa[i]] - i + 1);
		}
		cout << s << endl;
	}
}
 

// File: DSA06036 - BỘ BA SỐ BẰNG K.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[n];
		string ans = "NO";
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (binary_search(a + j + 1, a + n, k - a[i] - a[j]))
				{
					ans = "YES";
					break;
				}
			}
			if (ans == "YES")
				break;
		}
		cout << ans << endl;
	}
}
 

// File: DSA06037 - SẮP XẾP ĐOẠN CON.cpp
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct dt
{
    int first;
    int second;
    int third;
};
bool cmp1(dt a, dt b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
bool cmp2(dt a, dt b)
{
    return a.second < b.second;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m = 0;
        cin >> n;
        vector<dt> a(n);
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end(), cmp1);
        for (int i = 0; i < n; i++)
            a[i].third = i + 1;
        sort(a.begin(), a.end(), cmp2);
        for (int i = 0; i < n - 1; i++)
        {
            m = max(m, a[i].third);
            if (i + 1 == m)
                ans.push_back(i + 1);
        }
        cout << ans.size() << endl;
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
}
 

// File: DSA06038 - CẶP SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int bit[1000001];
void update(int i)
{
    for (; i < 1000001; i += i & -i)
        bit[i]++;
}
int get(int i)
{
    int s = 0;
    for (; i; i -= i & -i)
        s += bit[i];
    return s;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    int a[n + 1];
    stack<int> st;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i > 0; i--)
    {
        if (a[i] % 2 == 0)
        {
            ans += get(a[i] - 1);
            st.push(a[i]);
        }
        else
        {
            while (!st.empty())
            {
                update(st.top());
                st.pop();
            }
        }
    }
    cout << ans;
}
 

// File: DSA06039 - SỐ ĐẦU TIÊN BỊ LẶP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n + 1];
		pair<int, int> k;
		k.second = 1e9;
		map<int, int> m;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (m[a[i]] == 0)
				m[a[i]] = i;
			else if (k.second > m[a[i]])
			{
				k.first = a[i];
				k.second = m[a[i]];
			}
		}
		if (k.second != 1e9)
			cout << k.first << endl;
		else
			cout << "NO" << endl;
	}
}
 

// File: DSA06040 - GIAO CỦA BA DÃY SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		long long a1[n], a2[m], a3[k];
		for (int i = 0; i < n; i++)
			cin >> a1[i];
		for (int i = 0; i < m; i++)
			cin >> a2[i];
		for (int i = 0; i < k; i++)
			cin >> a3[i];
		int i = 0, j = 0, h = 0;
		vector<long long> a;
		while (i < n && j < m && h < k)
		{
			if (a1[i] == a2[j] && a2[j] == a3[h])
			{
				a.push_back(a1[i]);
				i++;
				j++;
				h++;
			}
			else if (a1[i] < a2[j])
				i++;
			else if (a2[j] < a3[h])
				j++;
			else
				h++;
		}
		if (a.size() == 0)
			cout << -1 << endl;
		else
		{
			for (int i = 0; i < a.size(); i++)
				cout << a[i] << " ";
			cout << endl;
		}
	}
}
 

// File: DSA06041 - SỐ XUẤT HIỆN NHIỀU NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, x, s = 0;
		cin >> n;
		pair<int, int> k;
		map<int, int> m;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			m[x]++;
		}
		for (auto i : m)
		{
			if (i.second > s)
			{
				s = i.second;
				k = i;
			}
		}
		if (k.second > (float)n / 2)
			cout << k.first << endl;
		else
			cout << "NO" << endl;
	}
}
 

// File: DSA06043 - ĐIỂM CÂN BẰNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n], s = 0, k = 0, ans = -1;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			s += a[i];
		}
		for (int i = 0; i < n; i++)
		{
			if (k * 2 + a[i] == s)
			{
				ans = i + 1;
				break;
			}
			k += a[i];
		}
		cout << ans << endl;
	}
}
 

// File: DSA06044 - SẮP XẾP CHẴN LẺ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, i1 = 0, i2 = 0;
	cin >> n;
	int a[n];
	vector<int> b, c;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i % 2 == 0)
			b.push_back(a[i]);
		else
			c.push_back(a[i]);
	}
	sort(b.begin(), b.end());
	sort(c.begin(), c.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			cout << b[i1++] << " ";
		else
			cout << c[i2++] << " ";
	}
}
 

// File: DSA06046 - CHÊNH LỆCH NHỎ NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n], s = 1e9;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 1; i < n; i++)
			s = min(s, a[i] - a[i - 1]);
		cout << s << endl;
	}
}
 

// File: DSA06047 - BỘ BA SỐ PYTAGO.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long a[n];
		string ans = "NO";
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				long long k = a[i] * a[i] + a[j] * a[j];
				long long x = sqrt(k);
				if (x * x == k && binary_search(a + j + 1, a + n, x))
				{
					ans = "YES";
					break;
				}
			}
			if (ans == "YES")
				break;
		}
		cout << ans << endl;
	}
}
 

// File: DSA06048 - SỐ LẦN QUAY VÒNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n], ans = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 1; i < n; i++)
		{
			if (a[i] < a[i - 1])
			{
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}
}
 

// File: DSA06049 - ĐẾM CẶP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		long long s = 0;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			int x = lower_bound(a + i + 1, a + n, a[i] + k) - a;
			s += x - i - 1;
		}
		cout << s << endl;
	}
}
 

// File: DSA07001 - NGĂN XẾP 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    stack<int> st;
    while (cin >> s)
    {
        if (s == "push")
        {
            cin >> n;
            st.push(n);
        }
        else if (s == "pop")
            st.pop();
        else if (s == "show")
        {
            if (st.size())
            {
                stack<int> q;
                while (st.size())
                {
                    q.push(st.top());
                    st.pop();
                }
                while (q.size())
                {
                    cout << q.top() << " ";
                    st.push(q.top());
                    q.pop();
                }
                cout << endl;
            }
            else
                cout << "empty" << endl;
        }
    }
}
 

// File: DSA07002 - NGĂN XẾP 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    string s;
    cin >> t;
    stack<int> st;
    while (t--)
    {
        cin >> s;
        if (s == "PUSH")
        {
            cin >> n;
            st.push(n);
        }
        else if (s == "POP")
        {
            if (st.size())
                st.pop();
        }
        else if (s == "PRINT")
        {
            if (st.size())
                cout << st.top() << endl;
            else
                cout << "NONE" << endl;
        }
    }
}
 

// File: DSA07003 - KIỂM TRA BIỂU THỨC SỐ HỌC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int ok = 0;
        string s;
        getline(cin, s);
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
                st.push(s[i]);
            if (s[i] == ')')
            {
                if (st.top() == '(')
                {
                    ok = 1;
                    break;
                }
                while (st.size() && st.top() != '(')
                    st.pop();
                st.pop();
            }
        }
        if (ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
 

// File: DSA07004 - ĐẾM SỐ DẤU NGOẶC ĐỔI CHIỀU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<char> st;
        if (s.length() % 2 == 1)
        {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')' && !st.empty())
            {
                if (st.top() == '(')
                    st.pop();
                else
                    st.push(s[i]);
            }
            else
                st.push(s[i]);
        }
        int k = st.size(), n = 0;
        while (!st.empty() && st.top() == '(')
        {
            st.pop();
            n++;
        }
        cout << (k / 2 + n % 2) << endl;
    }
}
 

// File: DSA07005 - BIỂU THỨC TƯƠNG ĐƯƠNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, k, ans = "";
        cin >> s;
        char c, d;
        stack<char> st, ld;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
                ld.push(s[i - 1]);
            }
            else if (s[i] == ')')
            {
                k = "";
                while (st.size())
                {
                    c = st.top();
                    st.pop();
                    d = st.top();
                    st.pop();
                    if (ld.top() == '-')
                    {
                        k = c + k;
                        if (d == '-')
                            k = '+' + k;
                        else
                            k = '-' + k;
                    }
                    else
                    {
                        k = c + k;
                        k = d + k;
                    }
                    if (d == '(')
                    {
                        for (int j = 1; j < k.size(); j++)
                            st.push(k[j]);
                        break;
                    }
                }
                ld.pop();
            }
            else
                st.push(s[i]);
        }
        while (st.size())
        {
            ans = st.top() + ans;
            st.pop();
        }
        cout << ans << endl;
    }
}
 

// File: DSA07007 - SO SÁNH BIỂU THỨC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string Try(string s)
{
    string k, ans = "";
    char c, d;
    stack<char> st, ld;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
            ld.push(s[i - 1]);
        }
        else if (s[i] == ')')
        {
            k = "";
            while (st.size())
            {
                c = st.top();
                st.pop();
                d = st.top();
                st.pop();
                if (ld.top() == '-')
                {
                    k = c + k;
                    if (d == '-')
                        k = '+' + k;
                    else
                        k = '-' + k;
                }
                else
                {
                    k = c + k;
                    k = d + k;
                }
                if (d == '(')
                {
                    for (int j = 1; j < k.size(); j++)
                        st.push(k[j]);
                    break;
                }
            }
            ld.pop();
        }
        else
            st.push(s[i]);
    }
    while (st.size())
    {
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        a = Try(a);
        b = Try(b);
        if (a == b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA07008 - BIẾN ĐỔI TRUNG TỐ - HẬU TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string ts = "+-*/^";
bool check(char c)
{
    for (int i = 0; i < ts.size(); i++)
        if (ts[i] == c)
            return 1;
    return 0;
}
bool Var(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
int Deg(char c)
{
    if (c == '^')
        return 50;
    if (c == '*' || c == '/')
        return 100;
    if (c == '+' || c == '-')
        return 300;
    return 1000;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, ans;
        cin >> s;
        stack<char> st;
        st.push('#');
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
                continue;
            }
            if (s[i] == ')')
            {
                while (st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
                continue;
            }
            if (Var(s[i]))
            {
                ans += s[i];
                continue;
            }
            if (check(s[i]))
            {
                while (Deg(st.top()) <= Deg(s[i]))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
                continue;
            }
        }
        while (st.top() != '#')
        {
            ans += st.top();
            st.pop();
        }
        cout << ans << endl;
    }
}
 

// File: DSA07009 - BIẾN ĐỔI TIỀN TỐ - TRUNG TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string ts = "+-*/";
bool check(char c)
{
    for (int i = 0; i < ts.size(); i++)
        if (ts[i] == c)
            return 1;
    return 0;
}
bool Var(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, k;
        cin >> s;
        stack<string> st;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (check(s[i]))
            {
                k = '(' + st.top();
                st.pop();
                k += s[i];
                k = k + st.top() + ')';
                st.pop();
                st.push(k);
            }
            else
                st.push(string(1, s[i]));
        }
        cout << st.top() << endl;
    }
}
 

// File: DSA07010 - BIẾN ĐỐI TIỀN TỐ - HẬU TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string ts = "+-*/";
bool check(char c)
{
    for (int i = 0; i < ts.size(); i++)
        if (ts[i] == c)
            return 1;
    return 0;
}
bool Var(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, k1, k2;
        cin >> s;
        stack<string> st;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (check(s[i]))
            {
                k1 = st.top();
                st.pop();
                k2 = st.top();
                st.pop();
                st.push(k1 + k2 + s[i]);
            }
            else
                st.push(string(1, s[i]));
        }
        cout << st.top() << endl;
    }
}
 

// File: DSA07011 - BIẾN ĐỔI HẬU TỐ - TIỀN TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string ts = "+-*/^";
bool check(char c)
{
    for (int i = 0; i < ts.size(); i++)
        if (ts[i] == c)
            return 1;
    return 0;
}
bool Var(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, k, ans;
        cin >> s;
        stack<string> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (Var(s[i]))
                st.push(string(1, s[i]));
            if (check(s[i]))
            {
                k = st.top();
                st.pop();
                k = s[i] + k;
                k = st.top() + k;
                st.pop();
                k = "(" + k + ")";
                st.push(k);
            }
        }
        s = st.top();
        while (!st.empty())
            st.pop();
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (Var(s[i]))
                ans = s[i] + ans;
            if (check(s[i]))
                st.push(string(1, s[i]));
            if (s[i] == '(')
            {
                ans = st.top() + ans;
                st.pop();
            }
        }
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        cout << ans << endl;
    }
}
 

// File: DSA07012 - BIẾN ĐỔI HẬU TỐ - TRUNG TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool Var(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, k;
        cin >> s;
        stack<string> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (Var(s[i]))
                st.push(string(1, s[i]));
            else
            {
                k = st.top();
                st.pop();
                k = s[i] + k;
                k = st.top() + k;
                st.pop();
                k = "(" + k + ")";
                st.push(k);
            }
        }
        cout << st.top() << endl;
    }
}
 

// File: DSA07013 - TÍNH GIÁ TRỊ BIỂU THỨC HẬU TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool Var(char c)
{
    return (c >= '1' && c <= '9');
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int st[s.size()] = {}, p = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (Var(s[i]))
                st[++p] = s[i] - '0';
            if (s[i] == '*')
            {
                st[p - 1] *= st[p];
                p--;
                continue;
            }
            if (s[i] == '/')
            {
                st[p - 1] /= st[p];
                p--;
                continue;
            }
            if (s[i] == '+')
            {
                st[p - 1] += st[p];
                p--;
                continue;
            }
            if (s[i] == '-')
            {
                st[p - 1] -= st[p];
                p--;
                continue;
            }
        }
        cout << st[0] << endl;
    }
}
 

// File: DSA07014 - TÍNH GIÁ TRỊ BIỂU THỨC TIỀN TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool Var(char c)
{
    return (c >= '1' && c <= '9');
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int st[s.size()] = {}, p = -1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (Var(s[i]))
            {
                st[++p] = s[i] - '0';
                continue;
            }
            if (s[i] == '*')
            {
                st[p - 1] = st[p] * st[p - 1];
                p--;
                continue;
            }
            if (s[i] == '/')
            {
                st[p - 1] = st[p] / st[p - 1];
                p--;
                continue;
            }
            if (s[i] == '+')
            {
                st[p - 1] = st[p] + st[p - 1];
                p--;
                continue;
            }
            if (s[i] == '-')
            {
                st[p - 1] = st[p] - st[p - 1];
                p--;
                continue;
            }
        }
        cout << st[0] << endl;
    }
}
 

// File: DSA07015 - TÍNH TOÁN GIÁ TRỊ BIỂU THỨC TRUNG TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string op = "+-*/";
bool check(char k)
{
    for (int i = 0; i < op.size(); i++)
    {
        if (op[i] == k)
            return 1;
    }
    return 0;
}
int deg(char k)
{
    if (k == '*' || k == '/')
        return 10;
    else if (k == '+' || k == '-')
        return 20;
    else
        return 100;
}
string topost(string a)
{
    string res = "";
    stack<char> st;
    st.push('#');
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '(')
        {
            st.push(a[i]);
            continue;
        }
        else if (a[i] == ')')
        {
            while (st.size() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
            continue;
        }
        else if (check(a[i]))
        {
            while (st.size() && deg(st.top()) <= deg(a[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(a[i]);
            continue;
        }
        long long so = 0, ok = 0;
        while (i < a.size() && a[i] != ')' && !check(a[i]))
        {
            long long ss = a[i] - '0';
            i++;
            so = so * 10 + ss;
            ok = 1;
        }
        if (ok == 1)
            i--;
        res += "(";
        res += to_string(so);
        res += ")";
    }
    while (st.size() && st.top() != '#')
    {
        res += st.top();
        st.pop();
    }
    return res;
}
long long tinh(string a)
{
    stack<long long> st;
    int i = 0;
    while (i < a.size())
    {
        if (a[i] == '(')
        {
            i++;
            long long so = 0;
            while (a[i] != ')')
            {
                so = so * 10 + (a[i] - '0');
                i++;
            }
            i++;
            st.push(so);
        }
        else if (st.size() > 1)
        {
            long long tmp1 = st.top();
            st.pop();
            long long tmp2 = st.top();
            st.pop();
            if (a[i] == '+')
                st.push(tmp1 + tmp2);
            else if (a[i] == '-')
                st.push(tmp2 - tmp1);
            else if (a[i] == '*')
                st.push(tmp1 * tmp2);
            else if (a[i] == '/')
                st.push(tmp2 / tmp1);
            i++;
        }
    }
    return st.top();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        cout << tinh(topost(a)) << endl;
    }
}
 

// File: DSA07016 - BIỂU THỨC TĂNG GIẢM.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<int> st;
        int pos = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'D')
            {
                if (i == 0 || s[i - 1] == 'I')
                {
                    st.push(pos + 1);
                    pos++;
                }
                st.push(pos + 1);
                pos++;
            }
            else
            {
                while (st.size())
                {
                    cout << st.top();
                    st.pop();
                }
                if (i == 0)
                {
                    cout << pos + 1;
                    pos++;
                }
                if (s[i + 1] != 'D')
                {
                    cout << pos + 1;
                    pos++;
                }
            }
        }
        while (st.size())
        {
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
}
 

// File: DSA07017 - PHẦN TỬ BÊN PHẢI NHỎ HƠN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), l(n, -1), r(n, -1);
        stack<int> b, c;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            while (!b.empty() && a[i] > a[b.top()])
            {
                l[b.top()] = i;
                b.pop();
            }
            b.push(i);
        }
        for (int i = 0; i < n; i++)
        {
            while (!c.empty() && a[i] < a[c.top()])
            {
                r[c.top()] = i;
                c.pop();
            }
            c.push(i);
        }
        for (int i = 0; i < n; i++)
        {
            if (l[i] == -1 || r[l[i]] == -1)
                cout << -1 << " ";
            else
                cout << a[r[l[i]]] << " ";
        }
        cout << endl;
    }
}
 

// File: DSA07018 - TỔNG ĐA THỨC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
map<int, int> m;
void Do(string s)
{
    s += ' ';
    int k1 = 0, k2 = 0, ok = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            if (ok == 0)
                k1 = k1 * 10 + s[i] - '0';
            else
                k2 = k2 * 10 + s[i] - '0';
        }
        else if (s[i] == '^')
            ok = 1;
        else if (s[i] == ' ')
        {
            m[k2] += k1;
            k1 = k2 = ok = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        m.clear();
        string a, b;
        getline(cin, a);
        getline(cin, b);
        Do(a);
        Do(b);
        vector<pair<int, int>> v;
        for (auto i : m)
            v.push_back(i);
        cout << v[v.size() - 1].second << "*x^" << v[v.size() - 1].first;
        for (int i = v.size() - 2; i >= 0; i--)
            cout << " + " << v[i].second << "*x^" << v[i].first;
        cout << endl;
    }
}
 

// File: DSA07019 - HÌNH CHỮ NHẬT LỚN NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long a[n] = {0}, MAX = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            int pos1 = i, pos2 = i, s1 = 0, s2 = 0;
            while (a[pos1] >= a[i] && pos1 >= 0)
            {
                pos1--;
                s1++;
            }
            while (a[pos2] >= a[i] && pos2 < n)
            {
                pos2++;
                s2++;
            }
            MAX = max(MAX, a[i] * (s1 + s2 - 1));
        }
        cout << MAX << "\n";
    }
}
 

// File: DSA07021 - DÃY NGOẶC ĐÚNG DÀI NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<pair<char, int>> st;
        int ans = 0, n = s.size();
        vector<int> F(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ')' && !st.empty() && st.top().first == '(')
            {
                F[i] = F[i - 1];
                if (st.top().second != 0)
                    F[i] += F[st.top().second - 1];
                F[i] += 2;
                st.pop();
            }
            else
                st.push({s[i], i});
        }
        for (int i = 0; i < n; i++)
            ans = max(ans, F[i]);
        cout << ans << endl;
    }
}
 

// File: DSA07022 - PHẦN TỬ CÓ SỐ LẦN XUẤT HIỆN NHIỀU HƠN BÊN PHẢI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], ans[n];
        stack<int> st;
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.size() && m[st.top()] <= m[a[i]])
                st.pop();
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(a[i]);
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}
 

// File: DSA07023 - ĐẢO TỪ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s, x = "";
        stack<string> st;
        getline(cin, s);
        s += ' ';
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                if (x != "")
                {
                    st.push(x);
                    x = "";
                }
            }
            else
                x += s[i];
        }
        while (st.size())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
}
 

// File: DSA07024 - GHÉP VÁN GỖ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], l[n], r[n], ans = 0;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            while (st.size() && a[i] <= a[st.top()])
                st.pop();
            if (st.empty())
                l[i] = 0;
            else
                l[i] = st.top() + 1;
            st.push(i);
        }
        while (st.size())
            st.pop();
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.size() && a[st.top()] >= a[i])
                st.pop();
            if (st.empty())
                r[i] = n - 1;
            else
                r[i] = st.top() - 1;
            st.push(i);
        }
        for (int i = 0; i < n; i++)
            if (r[i] - l[i] + 1 >= a[i])
                ans = max(ans, a[i]);
        cout << ans << endl;
    }
}

// File: DSA07027 - PHẦN TỬ BÊN PHẢI ĐẦU TIÊN LỚN HƠN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        stack<int> st;
        vector<int> a(n), b(n, -1);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && a[i] > a[st.top()])
            {
                b[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for (int i = 0; i < n; i++)
        {
            if (b[i] == -1)
                cout << -1 << " ";
            else
                cout << a[b[i]] << " ";
        }
        cout << endl;
    }
}
 

// File: DSA07028 - NHỊP CHỨNG KHOÁN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        stack<int> st;
        st.push(0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            while (st.size() > 1 && a[st.top()] <= a[i])
                st.pop();
            cout << i - st.top() << " ";
            st.push(i);
        }
        cout << endl;
    }
}
 

// File: DSA07029 - GIẢI MÃ XÂU KÝ TỰ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, k, ls, ans;
        cin >> s;
        int n;
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ']')
            {
                k = ls = ans = "";
                while (st.top() != '[')
                {
                    k = st.top() + k;
                    st.pop();
                }
                st.pop();
                while (st.size() && st.top() >= '0' && st.top() <= '9')
                {
                    ls = st.top() + ls;
                    st.pop();
                }
                n = 0;
                for (auto c : ls) n = n * 10 + c - '0';
                if (n == 0) n++;
                for (int j = 0; j < n; j++) ans += k;
                for (auto c : ans) st.push(c);
            }
            else st.push(s[i]);
        }
        ans = "";
        while (st.size())
        {
            ans = st.top() + ans;
            st.pop();
        }
        cout << ans << endl;
    }
}
 

// File: DSA07030 - HÌNH CHỮ NHẬT 0-1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, s = 1;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                if (a[j][i] == 1)
                    a[j][i] = a[j - 1][i] + 1;
        for (int i = 0; i < n; i++)
        {
            stack<int> b, c;
            int l[m], r[m];
            for (int j = 0; j < m; j++)
            {
                while (!b.empty() && a[i][j] <= a[i][b.top()])
                    b.pop();
                if (b.empty())
                    l[j] = 0;
                else
                    l[j] = b.top() + 1;
                b.push(j);
            }
            for (int j = m - 1; j >= 0; j--)
            {
                while (!c.empty() && a[i][j] <= a[i][c.top()])
                    c.pop();
                if (c.empty())
                    r[j] = m - 1;
                else
                    r[j] = c.top() - 1;
                c.push(j);
            }
            for (int j = 0; j < m; j++)
                s = max(s, (r[j] - l[j] + 1) * a[i][j]);
        }
        cout << s << endl;
    }
}
 

// File: DSA07041 - BIỂU THỨC ĐÚNG DÀI NHẤT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int ans = 0;
		stack<char> st;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				st.push(s[i]);
			else
			{
				if (!st.empty())
				{
					ans += 2;
					st.pop();
				}
			}
		}
		cout << ans << endl;
	}
}
 

// File: DSA07045 - GÕ BÀN PHÍM.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin >> a;
    stack<char> a1, a2;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '<')
        {
            if (!a1.empty())
            {
                a2.push(a1.top());
                a1.pop();
            }
        }
        else if (a[i] == '>')
        {
            if (!a2.empty())
            {
                a1.push(a2.top());
                a2.pop();
            }
        }
        else if (a[i] == '-')
        {
            if (!a1.empty())
                a1.pop();
        }
        else
            a1.push(a[i]);
    }
    while (a1.size())
    {
        a2.push(a1.top());
        a1.pop();
    }
    while (a2.size())
    {
        cout << a2.top();
        a2.pop();
    }
}
 

// File: DSA07110 - KIỂM TRA DÃY NGOẶC ĐÚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int ok = 1;
        string s;
        cin >> s;
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                if (st.size() && st.top() == '(')
                    st.pop();
                else
                {
                    ok = 0;
                    break;
                }
            }
            else if (s[i] == ']')
            {
                if (st.size() && st.top() == '[')
                    st.pop();
                else
                {
                    ok = 0;
                    break;
                }
            }
            else
            {
                if (st.size() && st.top() == '{')
                    st.pop();
                else
                {
                    ok = 0;
                    break;
                }
            }
        }
        if (st.size())
            ok = 0;
        if (ok == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA08001 - CẤU TRÚC DỮ LIỆU HÀNG ĐỢI 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        deque<int> st;
        while (n--)
        {
            cin >> x;
            if (x == 1)
                cout << st.size() << endl;
            else if (x == 2)
            {
                if (st.empty())
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else if (x == 3)
            {
                cin >> x;
                st.push_back(x);
            }
            else if (x == 4)
            {
                if (st.size())
                    st.pop_front();
            }
            else if (x == 5)
            {
                if (st.size())
                    cout << st.front() << endl;
                else
                    cout << -1 << endl;
            }
            else if (x == 6)
            {
                if (st.size())
                    cout << st.back() << endl;
                else
                    cout << -1 << endl;
            }
        }
    }
}
 

// File: DSA08002 - CẤU TRÚC DỮ LIỆU HÀNG ĐỢI 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n;
    string s;
    deque<int> dq;
    while (n--)
    {
        cin >> s;
        if (s == "PUSH")
        {
            cin >> x;
            dq.push_back(x);
        }
        else if (s == "PRINTFRONT")
        {
            if (dq.size())
                cout << dq.front() << endl;
            else
                cout << "NONE" << endl;
        }
        else if (s == "POP")
        {
            if (dq.size())
                dq.pop_front();
        }
    }
}
 

// File: DSA08003 - HÀNG ĐỢI HAI ĐẦU (DEQUEUE).cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n;
    string s;
    deque<int> dq;
    while (n--)
    {
        cin >> s;
        if (s == "PUSHFRONT")
        {
            cin >> x;
            dq.push_front(x);
        }
        else if (s == "PRINTFRONT")
        {
            if (dq.size())
                cout << dq.front() << endl;
            else
                cout << "NONE" << endl;
        }
        else if (s == "POPFRONT")
        {
            if (dq.size())
                dq.pop_front();
        }
        else if (s == "PUSHBACK")
        {
            cin >> x;
            dq.push_back(x);
        }
        else if (s == "PRINTBACK")
        {
            if (dq.size())
                cout << dq.back() << endl;
            else
                cout << "NONE" << endl;
        }
        else if (s == "POPBACK")
        {
            if (dq.size())
                dq.pop_back();
        }
    }
}
 

// File: DSA08004 - GIÁ TRỊ NHỎ NHẤT CỦA XÂU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int k, x;
        string s;
        cin >> k >> s;
        long long n = 0;
        map<char, int> m;
        priority_queue<int> q;
        for (int i = 0; i < s.size(); i++)
            m[s[i]]++;
        for (auto i : m)
            q.push(i.second);
        while (k--)
        {
            x = q.top();
            q.pop();
            q.push(x - 1);
        }
        while (q.size())
        {
            n += (long long)q.top() * q.top();
            q.pop();
        }
        cout << n << endl;
    }
}
 

// File: DSA08005 - SỐ NHỊ PHÂN TỪ 1 ĐẾN N.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string to_binary(int n)
{
    string s = "";
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            s = '0' + s;
        }
        else
        {
            s = '1' + s;
            n--;
        }
        n /= 2;
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cout << to_binary(i) << " ";
        }
        cout << endl;
    }
}
 

// File: DSA08006 - SỐ 0 VÀ SỐ 9.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        queue<long long> q;
        q.push(9);
        while (q.size())
        {
            long long k = q.front();
            q.pop();
            if (k % n == 0)
            {
                cout << k << endl;
                break;
            }
            q.push(k * 10);
            q.push(k * 10 + 9);
        }
    }
}
 

// File: DSA08007 - SỐ BDN 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string n, k;
bool check(string s)
{
	return s.size() < n.size() || (s.size() == n.size() && s <= n);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int d = 0;
		cin >> n;
		stack<string> st;
		st.push("1");
		while (st.size())
		{
			k = st.top();
			d++;
			st.pop();
			if (check(k + "0"))
				st.push(k + "0");
			if (check(k + "1"))
				st.push(k + "1");
		}
		cout << d << endl;
	}
}
 

// File: DSA08008 - SỐ BDN 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n;
        queue<long long> q;
        q.push(1);
        while (q.size())
        {
            k = q.front();
            if (k % n == 0)
            {
                cout << k << endl;
                break;
            }
            q.pop();
            q.push(k * 10);
            q.push(k * 10 + 1);
        }
    }
}
 

// File: DSA08009 - BIẾN ĐỔI S – T.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int s, t;
        cin >> s >> t;
        pair<int, int> u;
        u.first = s;
        u.second = 0;
        map<int, int> m;
        queue<pair<int, int>> q;
        q.push(u);
        while (q.size())
        {
            u = q.front();
            if (u.first == t)
            {
                cout << u.second << endl;
                break;
            }
            q.pop();
            if (u.first <= t && !m[u.first * 2])
            {
                m[u.first * 2]++;
                q.push({u.first * 2, u.second + 1});
            }
            if (u.first > 1 && !m[u.first - 1])
            {
                m[u.first - 1]++;
                q.push({u.first - 1, u.second + 1});
            }
        }
    }
}
 

// File: DSA08010 - BIẾN ĐỔI SỐ TỰ NHIÊN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        pair<int, int> u, v;
        queue<pair<int, int>> q;
        map<int, int> m;
        u.first = n;
        u.second = 0;
        q.push(u);
        while (q.size())
        {
            u = q.front();
            q.pop();
            if (u.first == 2)
            {
                cout << u.second + 1 << endl;
                break;
            }
            for (int i = 2; i <= sqrt(u.first); i++)
            {
                if (u.first % i == 0 && !m[u.first / i])
                {
                    m[u.first / i]++;
                    q.push({u.first / i, u.second + 1});
                }
            }
            q.push({u.first - 1, u.second + 1});
        }
    }
}
 

// File: DSA08011 - KHOẢNG CÁCH XÂU KÝ TỰ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string st, ed, k;
        cin >> n >> st >> ed;
        set<string> s;
        pair<string, int> u, v;
        queue<pair<string, int>> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> k;
            s.insert(k);
        }
        s.erase(st);
        u.first = st;
        u.second = 1;
        q.push(u);
        while (q.size())
        {
            u = q.front();
            q.pop();
            if (u.first == ed)
            {
                cout << u.second << endl;
                break;
            }
            v.second = u.second + 1;
            for (int i = 0; i < u.first.size(); i++)
            {
                k = u.first;
                for (char j = 'A'; j <= 'Z'; j++)
                {
                    k[i] = j;
                    if (s.find(k) != s.end())
                    {
                        s.erase(k);
                        v.first = k;
                        q.push(v);
                    }
                }
            }
        }
    }
}
 

// File: DSA08012 - TÌM SỐ K THỎA MÃN ĐIỀU KIỆN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> v;
int m[6];
void Try(int n)
{
    v.push_back(n);
    for (int i = 0; i <= 5; i++)
    {
        if (!m[i])
        {
            m[i] = 1;
            Try(n * 10 + i);
            m[i] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= 5; i++)
    {
        m[i] = 1;
        Try(i);
        m[i] = 0;
    }
    v.push_back(0);
    sort(v.begin(), v.end());
    int t;
    cin >> t;
    while (t--)
    {
        int l, r, s = 0;
        cin >> l >> r;
        int k1 = lower_bound(v.begin(), v.end(), l) - v.begin();
        int k2 = lower_bound(v.begin(), v.end(), r) - v.begin();
        if (v[k2] != r)
            k2--;
        cout << k2 - k1 + 1 << endl;
    }
}
 

// File: DSA08013 - DI CHUYỂN TRÁNH VẬT CẢN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    int x, y, s;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cin.ignore();
        int check[n][n] = {};
        char a[n][n];
        struct data u, v, ed;
        queue<struct data> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        cin >> u.x >> u.y >> ed.x >> ed.y;
        check[u.x][u.y] = 1;
        u.s = 0;
        q.push(u);
        while (q.size())
        {
            u = q.front();
            q.pop();
            if (u.x == ed.x && u.y == ed.y)
            {
                cout << u.s << endl;
                break;
            }
            v.s = u.s + 1;
            v.y = u.y;
            for (int i = u.x + 1; i < n; i++)
            {
                if (a[i][u.y] == 'X' || check[i][u.y])
                    break;
                v.x = i;
                check[i][u.y] = 1;
                q.push(v);
            }
            for (int i = u.x - 1; i >= 0; i--)
            {
                if (a[i][u.y] == 'X' || check[i][u.y])
                    break;
                v.x = i;
                check[i][u.y] = 1;
                q.push(v);
            }
            v.x = u.x;
            for (int i = u.y + 1; i < n; i++)
            {
                if (a[u.x][i] == 'X' || check[u.x][i])
                    break;
                v.y = i;
                check[u.x][i] = 1;
                q.push(v);
            }
            for (int i = u.y - 1; i >= 0; i--)
            {
                if (a[u.x][i] == 'X' || check[u.x][i])
                    break;
                v.y = i;
                check[u.x][i] = 1;
                q.push(v);
            }
        }
    }
}
 

// File: DSA08014 - GIEO MẦM.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int rx[] = {1, -1, 0, 0};
int ry[] = {0, 0, 1, -1};
struct data
{
    int x, y, s;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, ans = 0;
        cin >> n >> m;
        int a[n + 1][m + 1];
        struct data u, v;
        queue<struct data> q;
        u.s = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 2)
                {
                    u.x = i;
                    u.y = j;
                    q.push(u);
                }
            }
        }
        while (q.size())
        {
            u = q.front();
            q.pop();
            ans = max(ans, u.s);
            for (int i = 0; i < 4; i++)
            {
                v.x = u.x + rx[i];
                v.y = u.y + ry[i];
                if (v.x >= 1 && v.x <= n && v.y >= 1 && v.y <= m && a[v.x][v.y] == 1)
                {
                    a[v.x][v.y] = 2;
                    v.s = u.s + 1;
                    q.push(v);
                }
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (a[i][j] == 1)
                    ans = -1;
        cout << ans << endl;
    }
}
 

// File: DSA08015 - DI CHUYỂN TRONG KHÔNG GIAN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct point
{
	int x, y, z, s;
};
int gx[6] = {1, -1, 0, 0, 0, 0};
int gy[6] = {0, 0, 1, -1, 0, 0};
int gz[6] = {0, 0, 0, 0, 1, -1};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int h, r, d, ok = -1;
		cin >> h >> r >> d;
		point st, ed, b, c;
		char a[h + 1][r + 1][d + 1];
		queue<point> q;
		for (int i = 1; i <= h; i++)
		{
			cin.ignore();
			for (int j = 1; j <= r; j++)
			{
				for (int k = 1; k <= d; k++)
				{
					cin >> a[i][j][k];
					if (a[i][j][k] == 'S')
					{
						st.x = i;
						st.y = j;
						st.z = k;
						st.s = 0;
						a[i][j][k] = '#';
					}
					else if (a[i][j][k] == 'E')
					{
						ed.x = i;
						ed.y = j;
						ed.z = k;
					}
				}
			}
		}
		q.push(st);
		while (q.size())
		{
			b = q.front();
			q.pop();
			c = b;
			c.s++;
			if (b.x == ed.x && b.y == ed.y && b.z == ed.z)
			{
				ok = b.s;
				break;
			}
			for (int i = 0; i < 6; i++)
			{
				c.x += gx[i];
				c.y += gy[i];
				c.z += gz[i];
				if (c.x >= 1 && c.x <= h && c.y >= 1 && c.y <= r && c.z >= 1 && c.z <= d && a[c.x][c.y][c.z] != '#')
				{
					q.push(c);
					a[c.x][c.y][c.z] = '#';
				}
				c.x -= gx[i];
				c.y -= gy[i];
				c.z -= gz[i];
			}
		}
		cout << ok << endl;
	}
}
 

// File: DSA08016 - HEXGAME.cpp
#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
using namespace std;
int l1[10] = {0, 4, 1, 3, 8, 5, 2, 7, 9, 6};
int r1[10] = {3, 0, 2, 7, 4, 1, 6, 8, 5, 9};
int l2[10] = {1, 5, 2, 0, 4, 8, 6, 3, 7, 9};
int r2[10] = {0, 2, 6, 3, 1, 5, 9, 7, 4, 8};
string left1(string a)
{
	string b = "";
	for (int i = 0; i < 10; i++)
		b += a[l1[i]];
	return b;
}
string right1(string a)
{
	string b = "";
	for (int i = 0; i < 10; i++)
		b += a[r1[i]];
	return b;
}
string left2(string a)
{
	string b = "";
	for (int i = 0; i < 10; i++)
		b += a[l2[i]];
	return b;
}
string right2(string a)
{
	string b = "";
	for (int i = 0; i < 10; i++)
		b += a[r2[i]];
	return b;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string a, b, y;
		int x, mim = 1e9;
		for (int i = 0; i < 10; i++)
		{
			cin >> x;
			a += to_string(x);
		}
		b = "1238004765";
		pair<string, int> x1, x2, y1, y2, k;
		map<string, int> f;
		x1.fi = a;
		x1.se = 0;
		x2.fi = b;
		x2.se = 0;
		queue<pair<string, int>> q1, q2;
		q1.push(x1);
		q2.push(x2);
		while (q1.size())
		{
			y1 = q1.front();
			q1.pop();
			k.se = y1.se + 1;
			k.fi = left1(y1.fi);
			if (f[k.fi] == 0)
				f[k.fi] = k.se;
			q1.push(k);
			k.fi = right1(y1.fi);
			if (f[k.fi] == 0)
				f[k.fi] = k.se;
			q1.push(k);
			if (k.se == 14)
				break;
		}
		while (q2.size())
		{
			y2 = q2.front();
			q2.pop();
			if (f[y2.fi] > 0)
				mim = min(mim, f[y2.fi] + y2.se);
			k.se = y2.se + 1;
			k.fi = left2(y2.fi);
			q2.push(k);
			k.fi = right2(y2.fi);
			q2.push(k);
			if (k.se == 14)
				break;
		}
		cout << mim << endl;
	}
}
 

// File: DSA08017 - SỐ LỘC PHÁT 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        queue<string> dq;
        stack<string> ans;
        dq.push("6");
        dq.push("8");
        while (dq.size())
        {
            string k = dq.front();
            ans.push(k);
            dq.pop();
            if (k.size() != n)
            {
                dq.push(k + "6");
                dq.push(k + "8");
            }
        }
        while (ans.size())
        {
            cout << ans.top() << " ";
            ans.pop();
        }
        cout << endl;
    }
}
 

// File: DSA08018 - SỐ LỘC PHÁT 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, s = 0;
        cin >> n;
        queue<string> dq;
        dq.push("6");
        dq.push("8");
        for (int i = 1; i <= n; i++)
        {
            s += pow(2, i);
        }
        cout << s << endl;
        while (dq.size())
        {
            string k = dq.front();
            cout << k << " ";
            dq.pop();
            if (k.size() != n)
            {
                dq.push(k + "6");
                dq.push(k + "8");
            }
        }
        cout << endl;
    }
}
 

// File: DSA08019 - SỐ LỘC PHÁT 3.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        queue<string> dq;
        stack<string> ans;
        dq.push("6");
        dq.push("8");
        while (dq.size())
        {
            string k = dq.front();
            ans.push(k);
            dq.pop();
            if (k.size() != n)
            {
                dq.push(k + "6");
                dq.push(k + "8");
            }
        }
        cout << ans.size() << endl;
        while (ans.size())
        {
            cout << ans.top() << " ";
            ans.pop();
        }
        cout << endl;
    }
}
 

// File: DSA08020 - BIẾN ĐỔI SỐ NGUYÊN TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> check(10000, 1);
void era()
{
    for (int i = 2; i * i <= 9999; i++)
        if (check[i])
            for (int j = i * i; j <= 9999; j += i)
                check[j] = 0;
}
int to_int(string s)
{
    int n = 0;
    for (int i = 0; i < s.size(); i++)
        n = n * 10 + s[i] - '0';
    return n;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    era();
    int t;
    cin >> t;
    while (t--)
    {
        string st, ed, s;
        cin >> st >> ed;
        pair<string, int> u, v;
        queue<pair<string, int>> q;
        map<string, int> m;
        m[st]++;
        q.push({st, 0});
        while (q.size())
        {
            u = q.front();
            q.pop();
            s = u.first;
            if (s == ed)
            {
                cout << u.second << endl;
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                int pos = 0;
                if (i == 0)
                    pos++;
                for (int j = pos; j <= 9; j++)
                {
                    s[i] = j + '0';
                    if (!m[s] && check[to_int(s)])
                    {
                        m[s]++;
                        q.push({s, u.second + 1});
                    }
                }
                s = u.first;
            }
        }
    }
}
 

// File: DSA08021 - DI CHUYỂN TRONG MA TRẬN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct point
{
    int x, y, s;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, ans = 1e9;
        cin >> n >> m;
        vector<vector<bool>> check(n + 1, vector<bool>(m + 1, 1));
        vector<vector<int>> a(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        point st, k;
        queue<point> q;
        st.x = st.y = 1;
        st.s = 0;
        q.push(st);
        while (q.size())
        {
            st = q.front();
            q.pop();
            if (st.x == n && st.y == m)
                ans = min(ans, st.s);
            k = st;
            k.s++;
            if (st.x + a[st.x][st.y] <= n && check[st.x + a[st.x][st.y]][st.y])
            {
                check[st.x + a[st.x][st.y]][st.y] = 0;
                k.x += a[st.x][st.y];
                q.push(k);
                k.x -= a[st.x][st.y];
            }
            if (st.y + a[st.x][st.y] <= m && check[st.x][st.y + a[st.x][st.y]])
            {
                check[st.x][st.y + a[st.x][st.y]] = 0;
                k.y += a[st.x][st.y];
                q.push(k);
                k.y -= a[st.x][st.y];
            }
        }
        if (ans == 1e9)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
}
 

// File: DSA08022 - BỘI SỐ LỚN NHẤT CỦA 3.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, s = 0;
        cin >> n;
        vector<int> a1, a2, a3;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (x == 0)
                s++;
            else if (x % 3 == 0)
                a3.push_back(x);
            else if (x % 3 == 1)
                a1.push_back(x);
            else
                a2.push_back(x);
        }
        sort(a1.begin(), a1.end(), greater<int>());
        sort(a2.begin(), a2.end(), greater<int>());
        int k = min(a1.size(), a2.size());
        if (abs((int)a1.size() - (int)a2.size()) % 3 == 2 && k != 0)
            k--;
        for (int i = 0; i < k; i++)
        {
            a3.push_back(a1[i]);
            a3.push_back(a2[i]);
        }
        k += 2;
        for (int i = k; i < a1.size(); i += 3)
        {
            a3.push_back(a1[i]);
            a3.push_back(a1[i - 1]);
            a3.push_back(a1[i - 2]);
        }
        for (int i = k; i < a2.size(); i += 3)
        {
            a3.push_back(a2[i]);
            a3.push_back(a2[i - 1]);
            a3.push_back(a2[i - 2]);
        }
        sort(a3.begin(), a3.end(), greater<int>());
        for (int i = 0; i < a3.size(); i++)
            cout << a3[i];
        if (a3.size())
            for (int i = 0; i < s; i++)
                cout << 0;
        else
            cout << -1;
        cout << endl;
    }
}
 

// File: DSA08025 - QUÂN MÃ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    int x, y, s;
};
int rx[] = {1, 2, -1, 2, 1, -2, -1, -2};
int ry[] = {2, 1, 2, -1, -2, 1, -2, -1};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int check[9][9] = {};
        struct data u, v, k;
        queue<struct data> q;
        u.x = a[0] - 'a' + 1;
        u.y = a[1] - '0';
        u.s = 0;
        v.x = b[0] - 'a' + 1;
        v.y = b[1] - '0';
        q.push(u);
        while (q.size())
        {
            u = q.front();
            q.pop();
            if (u.x == v.x && u.y == v.y)
            {
                cout << u.s << endl;
                break;
            }
            k.s = u.s + 1;
            for (int i = 0; i < 8; i++)
            {
                k.x = u.x + rx[i];
                k.y = u.y + ry[i];
                if (k.x >= 1 && k.x <= 8 && k.y >= 1 && k.y <= 8 && !check[k.x][k.y])
                {
                    check[k.x][k.y] = 1;
                    q.push(k);
                }
            }
        }
    }
}
 

// File: DSA08029 - QUAY HÌNH VUÔNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
using namespace std;
int l[6] = {3, 0, 2, 4, 1, 5};
int r[6] = {0, 4, 1, 3, 5, 2};
string rleft(string a)
{
    string b = "";
    for (int i = 0; i < 6; i++)
        b += a[l[i]];
    return b;
}
string rright(string a)
{
    string b = "";
    for (int i = 0; i < 6; i++)
        b += a[r[i]];
    return b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        int x;
        for (int i = 0; i < 6; i++)
        {
            cin >> x;
            a += to_string(x);
        }
        for (int i = 0; i < 6; i++)
        {
            cin >> x;
            b += to_string(x);
        }
        pair<string, int> d, k, e;
        d.fi = a;
        d.se = 0;
        queue<pair<string, int>> c;
        c.push(d);
        while (c.size())
        {
            k = c.front();
            c.pop();
            if (k.fi == b)
            {
                cout << k.se << endl;
                break;
            }
            e.se = k.se + 1;
            e.fi = rleft(k.fi);
            c.push(e);
            e.fi = rright(k.fi);
            c.push(e);
        }
    }
}

// File: DSA09001 - CHUYỂN DANH SÁCH CẠNH SANG DANH SÁCH KỀ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, u, v;
		cin >> n >> m;
		vector<vector<int>> a(n + 1);
		while (m--)
		{
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
		{
			cout << i << ": ";
			for (int j = 0; j < a[i].size(); j++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
}
 

// File: DSA09002 - CHUYỂN TỪ DANH SÁCH KỀ SANG DANH SÁCH CẠNH.cpp
#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	set<pair<int, int>> m;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		s += ' ';
		int k = 0;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] >= '0' && s[j] <= '9')
			{
				k = k * 10 + s[j] - '0';
			}
			else
			{
				int a = i + 1, b = k;
				if (a > b)
					swap(a, b);
				m.insert(make_pair(a, b));
				k = 0;
			}
		}
	}
	for (auto i : m)
	{
		cout << i.fi << " " << i.se << endl;
	}
}
 

// File: DSA09003 - BIỂU DIỄN ĐỒ THỊ CÓ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, u, v;
		cin >> n >> m;
		vector<vector<int>> a(n + 1);
		while (m--)
		{
			cin >> u >> v;
			a[u].push_back(v);
		}
		for (int i = 1; i <= n; i++)
		{
			cout << i << ": ";
			for (int j = 0; j < a[i].size(); j++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
}
 

// File: DSA09004 - DFS TRÊN ĐỒ THỊ VÔ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, x, y;
        cin >> n >> m >> u;
        vector<bool> check(n + 1, 1);
        vector<vector<int>> a(n + 1);
        stack<int> st;
        while (m--)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
            sort(a[i].begin(), a[i].end());
        st.push(u);
        check[u] = 0;
        cout << u << " ";
        while (st.size())
        {
            u = st.top();
            st.pop();
            for (int i = 0; i < a[u].size(); i++)
            {
                int v = a[u][i];
                if (check[v])
                {
                    cout << v << " ";
                    check[v] = 0;
                    st.push(u);
                    st.push(v);
                    break;
                }
            }
        }
        cout << endl;
    }
}
 

// File: DSA09005 - BFS TRÊN ĐỒ THỊ VÔ HƯỚNG.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, x, y;
        cin >> n >> m >> u;
        vector<int> a[n + 1], check(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
            sort(a[i].begin(), a[i].end());
        queue<int> q;
        q.push(u);
        check[u] = 1;
        while (q.size())
        {
            u = q.front();
            q.pop();
            cout << u << " ";
            for (int i = 0; i < a[u].size(); i++)
            {
                int v = a[u][i];
                if (!check[v])
                {
                    q.push(v);
                    check[v] = 1;
                }
            }
        }
        cout << endl;
    }
}
 

// File: DSA09006 - ĐƯỜNG ĐI THEO DFS VỚI ĐỒ THỊ VÔ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, v, x, y, ok = 0;
        cin >> n >> m >> u >> v;
        string s;
        vector<bool> check(n + 1, 1);
        vector<vector<int>> a(n + 1);
        stack<pair<int, string>> st;
        while (m--)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        st.push({u, to_string(u) + " "});
        check[u] = 0;
        while (st.size())
        {
            x = st.top().first;
            s = st.top().second;
            if (x == v)
            {
                ok = 1;
                cout << s << endl;
                break;
            }
            st.pop();
            for (int i = 0; i < a[x].size(); i++)
            {
                int y = a[x][i];
                if (check[y])
                {
                    check[y] = 0;
                    st.push({x, s});
                    st.push({y, s + to_string(y) + " "});
                    break;
                }
            }
        }
        if (ok == 0)
            cout << -1 << endl;
    }
}
 

// File: DSA09007 - ĐƯỜNG ĐI THEO BFS TRÊN ĐỒ THỊ VÔ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, v, x, y, ok = 0;
        cin >> n >> m >> u >> v;
        string s;
        vector<bool> check(n + 1, 1);
        vector<vector<int>> a(n + 1);
        queue<pair<int, string>> st;
        while (m--)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        st.push({u, to_string(u) + " "});
        check[u] = 0;
        while (st.size())
        {
            x = st.front().first;
            s = st.front().second;
            if (x == v)
            {
                ok = 1;
                cout << s << endl;
                break;
            }
            st.pop();
            for (int i = 0; i < a[x].size(); i++)
            {
                int y = a[x][i];
                if (check[y])
                {
                    check[y] = 0;
                    st.push({y, s + to_string(y) + " "});
                }
            }
        }
        if (ok == 0)
            cout << -1 << endl;
    }
}
 

// File: DSA09008 - ĐẾM SỐ THÀNH PHẦN LIÊN THÔNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y, s = 0, k;
        cin >> n >> m;
        int check[n + 1] = {};
        vector<vector<int>> a(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!check[i])
            {
                s++;
                check[i] = 1;
                stack<int> st;
                st.push(i);
                while (st.size())
                {
                    k = st.top();
                    st.pop();
                    for (auto j : a[k])
                    {
                        if (!check[j])
                        {
                            check[j] = 1;
                            st.push(j);
                        }
                    }
                }
            }
        }
        cout << s << endl;
    }
}
 

// File: DSA09009 - TÌM SỐ THÀNH PHẦN LIÊN THÔNG VỚI BFS.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y, s = 0, k;
        cin >> n >> m;
        int check[n + 1] = {};
        vector<vector<int>> a(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!check[i])
            {
                s++;
                check[i] = 1;
                stack<int> st;
                st.push(i);
                while (st.size())
                {
                    k = st.top();
                    st.pop();
                    for (auto j : a[k])
                    {
                        if (!check[j])
                        {
                            check[j] = 1;
                            st.push(j);
                        }
                    }
                }
            }
        }
        cout << s << endl;
    }
}
 

// File: DSA09010 - KIỂM TRA TÍNH LIÊN THÔNG MẠNH.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y, ok = 1;
        cin >> n >> m;
        queue<int> q;
        vector<bool> check(n + 1, 1);
        vector<vector<int>> a(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
        }
        q.push(1);
        check[1] = 0;
        while (q.size())
        {
            x = q.front();
            q.pop();
            for (auto y : a[x])
            {
                if (check[y])
                {
                    check[y] = 0;
                    q.push(y);
                }
            }
        }
        for (int i = 2; i <= n; i++)
        {
            if (check[i])
            {
                ok = 0;
                break;
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA09011 - SỐ LƯỢNG HÒN ĐẢO.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, s;
int a[501][501];
int gx[] = {1, 1, 0, 0, -1, -1, 1, -1};
int gy[] = {1, -1, 1, -1, -1, 1, 0, 0};
void BFS(int x, int y)
{
    pair<int, int> k;
    queue<pair<int, int>> q;
    q.push({x, y});
    a[x][y] = 0;
    while (q.size())
    {
        k = q.front();
        q.pop();
        x = k.first;
        y = k.second;
        for (int i = 0; i < 8; i++)
        {
            x += gx[i];
            y += gy[i];
            if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y])
            {
                a[x][y] = 0;
                q.push({x, y});
            }
            x -= gx[i];
            y -= gy[i];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        s = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == 1)
                {
                    s++;
                    BFS(i, j);
                }
            }
        }
        cout << s << endl;
    }
}
 

// File: DSA09012 - LIỆT KÊ ĐỈNH TRỤ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<bool> check;
vector<vector<int>> a;
void bfs(int n)
{
    queue<int> q;
    q.push(n);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : a[u])
        {
            if (check[v])
            {
                check[v] = 0;
                q.push(v);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y, stp = 0, s;
        cin >> n >> m;
        a.clear();
        a.resize(n + 1);
        check.clear();
        check.resize(n + 1, 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
        {
            if (check[i])
            {
                stp++;
                check[i] = 0;
                bfs(i);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            check.clear();
            check.resize(n + 1, 1);
            s = 0;
            check[i] = 0;
            for (int j = 1; j <= n; j++)
            {
                if (check[j])
                {
                    s++;
                    check[j] = 0;
                    bfs(j);
                }
            }
            if (s > stp)
                cout << i << " ";
        }
        cout << endl;
    }
}
 

// File: DSA09013 - LIỆT KÊ CẠNH CẦU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<bool> check;
vector<vector<int>> a;
void bfs(int n, int x, int y)
{
    queue<int> q;
    q.push(n);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : a[u])
        {
            if ((u == x && v == y) || (u == y && v == x))
                continue;
            if (check[v])
            {
                check[v] = 0;
                q.push(v);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, stp = 0, s;
        cin >> n >> m;
        a.clear();
        a.resize(n + 1);
        check.clear();
        check.resize(n + 1, 1);
        vector<pair<int, int>> e(m);
        for (int i = 0; i < m; i++)
        {
            cin >> e[i].first >> e[i].second;
            a[e[i].first].push_back(e[i].second);
            a[e[i].second].push_back(e[i].first);
        }
        sort(e.begin(), e.end());
        for (int i = 1; i <= n; i++)
        {
            if (check[i])
            {
                stp++;
                check[i] = 0;
                bfs(i, -1, -1);
            }
        }
        for (int i = 0; i < m; i++)
        {
            check.clear();
            check.resize(n + 1, 1);
            s = 0;
            for (int j = 1; j <= n; j++)
            {
                if (check[j])
                {
                    s++;
                    check[j] = 0;
                    bfs(j, e[i].first, e[i].second);
                }
            }
            if (s > stp)
                cout << e[i].first << " " << e[i].second << " ";
        }
        cout << endl;
    }
}
 

// File: DSA09014 - KIỂM TRA CHU TRÌNH TRÊN ĐỒ THỊ VÔ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, x, y, ok;
vector<int> svs;
vector<bool> check;
vector<vector<int>> a;
void BFS(int k)
{
    check[k] = 0;
    for (auto i : a[k])
    {
        if (check[i])
        {
            svs[i] = k;
            BFS(i);
        }
        else if (i != svs[k])
        {
            ok = 1;
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ok = 0;
        a.clear();
        svs.clear();
        check.clear();
        a.resize(n + 1);
        svs.resize(n + 1, -1);
        check.resize(n + 1, 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
            if (check[i] && !ok)
                BFS(i);
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA09015 - KIỂM TRA CHU TRÌNH TRÊN ĐỒ THỊ CÓ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, x, y, ok;
vector<int> check;
vector<vector<int>> a;
void DFS(int k)
{
    check[k] = 1;
    for (auto i : a[k])
    {
        if (check[i] == 0)
            DFS(i);
        else if (check[i] == 1)
            ok = 1;
    }
    check[k] = 2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ok = 0;
        a.clear();
        check.clear();
        a.resize(n + 1);
        check.resize(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
        }
        for (int i = 1; i <= n; i++)
            if (!check[i] && !ok)
                DFS(i);
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA09016 - KIỂM TRA CHU TRÌNH TRÊN ĐỒ THỊ CÓ HƯỚNG VỚI DFS.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, x, y, ok;
vector<int> check;
vector<vector<int>> a;
void DFS(int k)
{
    check[k] = 1;
    for (auto i : a[k])
    {
        if (check[i] == 0)
            DFS(i);
        else if (check[i] == 1)
            ok = 1;
    }
    check[k] = 2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ok = 0;
        a.clear();
        check.clear();
        a.resize(n + 1);
        check.resize(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
        }
        for (int i = 1; i <= n; i++)
            if (!check[i] && !ok)
                DFS(i);
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA09017 - KIỂM TRA ĐỒ THỊ CÓ PHẢI LÀ CÂY HAY KHÔNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int check[1001], ok;
vector<vector<int>> a(1001);
void dfs(int u)
{
    for (auto v : a[u])
    {
        if (check[v])
        {
            ok = 1;
            return;
        }
        check[v]++;
        dfs(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ok = 0;
        int n, u, v;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            a[i].clear();
            check[i] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            cin >> u >> v;
            a[u].push_back(v);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!check[i] && !ok)
            {
                check[i]++;
                dfs(i);
            }
        }
        if (!ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA09018 - LIỆT KÊ ĐỈNH TRỤ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<bool> check;
vector<vector<int>> a;
void bfs(int n)
{
    queue<int> q;
    q.push(n);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : a[u])
        {
            if (check[v])
            {
                check[v] = 0;
                q.push(v);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y, stp = 0, s;
        cin >> n >> m;
        a.clear();
        a.resize(n + 1);
        check.clear();
        check.resize(n + 1, 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
        {
            if (check[i])
            {
                stp++;
                check[i] = 0;
                bfs(i);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            check.clear();
            check.resize(n + 1, 1);
            s = 0;
            check[i] = 0;
            for (int j = 1; j <= n; j++)
            {
                if (check[j])
                {
                    s++;
                    check[j] = 0;
                    bfs(j);
                }
            }
            if (s > stp)
                cout << i << " ";
        }
        cout << endl;
    }
}
 

// File: DSA09019 - KIỂM TRA CHU TRÌNH.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, x, y, ok;
vector<int> svs;
vector<bool> check;
vector<vector<int>> a;
void BFS(int k)
{
    check[k] = 0;
    for (auto i : a[k])
    {
        if (check[i])
        {
            svs[i] = k;
            BFS(i);
        }
        else if (i != svs[k])
        {
            ok = 1;
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ok = 0;
        a.clear();
        svs.clear();
        check.clear();
        a.resize(n + 1);
        svs.resize(n + 1, -1);
        check.resize(n + 1, 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
            if (check[i] && !ok)
                BFS(i);
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA09020 - CHUYỂN DANH SÁCH KỀ SANG MA TRẬN KỀ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        getline(cin, s);
        s += ' ';
        int k = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] >= '0' && s[j] <= '9')
                k = k * 10 + s[j] - '0';
            else
            {
                a[i][k] = a[k][i] = 1;
                k = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
 

// File: DSA09021 - CHUYỂN MA TRẬN KỀ SANG DANH SÁCH KỀ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n;
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            if (i > j && x == 1)
            {
                a[i].push_back(j);
                a[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto j : a[i])
            cout << j << " ";
        cout << endl;
    }
}
 

// File: DSA09022 - DFS TRÊN ĐỒ THỊ CÓ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, x, y;
        cin >> n >> m >> u;
        vector<bool> check(n + 1, 1);
        vector<vector<int>> a(n + 1);
        stack<int> st;
        while (m--)
        {
            cin >> x >> y;
            a[x].push_back(y);
        }
        for (int i = 1; i <= n; i++)
            sort(a[i].begin(), a[i].end());
        st.push(u);
        check[u] = 0;
        cout << u << " ";
        while (st.size())
        {
            u = st.top();
            st.pop();
            for (int i = 0; i < a[u].size(); i++)
            {
                int v = a[u][i];
                if (check[v])
                {
                    cout << v << " ";
                    check[v] = 0;
                    st.push(u);
                    st.push(v);
                    break;
                }
            }
        }
        cout << endl;
    }
}
 

// File: DSA09024 - BFS TRÊN ĐỒ THỊ CÓ HƯỚNG.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, x, y;
        cin >> n >> m >> u;
        vector<int> a[n + 1], check(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
        }
        for (int i = 1; i <= n; i++)
            sort(a[i].begin(), a[i].end());
        queue<int> q;
        q.push(u);
        check[u] = 1;
        while (q.size())
        {
            u = q.front();
            q.pop();
            cout << u << " ";
            for (int i = 0; i < a[u].size(); i++)
            {
                int v = a[u][i];
                if (!check[v])
                {
                    q.push(v);
                    check[v] = 1;
                }
            }
        }
        cout << endl;
    }
}
 

// File: DSA09025 - ĐƯỜNG ĐI THEO DFS VỚI ĐỒ THỊ CÓ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, v, x, y, ok = 0;
        cin >> n >> m >> u >> v;
        string s;
        vector<bool> check(n + 1, 1);
        vector<vector<int>> a(n + 1);
        stack<pair<int, string>> st;
        while (m--)
        {
            cin >> x >> y;
            a[x].push_back(y);
        }
        st.push({u, to_string(u) + " "});
        check[u] = 0;
        while (st.size())
        {
            x = st.top().first;
            s = st.top().second;
            if (x == v)
            {
                ok = 1;
                cout << s << endl;
                break;
            }
            st.pop();
            for (int i = 0; i < a[x].size(); i++)
            {
                int y = a[x][i];
                if (check[y])
                {
                    check[y] = 0;
                    st.push({x, s});
                    st.push({y, s + to_string(y) + " "});
                    break;
                }
            }
        }
        if (ok == 0)
            cout << -1 << endl;
    }
}
 

// File: DSA09026 - ĐƯỜNG ĐI THEO BFS TRÊN ĐỒ THỊ CÓ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, v, x, y, ok = 0;
        cin >> n >> m >> u >> v;
        string s;
        vector<bool> check(n + 1, 1);
        vector<vector<int>> a(n + 1);
        queue<pair<int, string>> st;
        while (m--)
        {
            cin >> x >> y;
            a[x].push_back(y);
        }
        st.push({u, to_string(u) + " "});
        check[u] = 0;
        while (st.size())
        {
            x = st.front().first;
            s = st.front().second;
            if (x == v)
            {
                ok = 1;
                cout << s << endl;
                break;
            }
            st.pop();
            for (int i = 0; i < a[x].size(); i++)
            {
                int y = a[x][i];
                if (check[y])
                {
                    check[y] = 0;
                    st.push({y, s + to_string(y) + " "});
                }
            }
        }
        if (ok == 0)
            cout << -1 << endl;
    }
}
 

// File: DSA09027 - KIỂM TRA ĐƯỜNG ĐI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y, k;
        cin >> n >> m;
        vector<vector<int>> a(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        cin >> m;
        while (m--)
        {
            cin >> x >> y;
            queue<int> q;
            q.push(x);
            int ok = 0, check[n + 1] = {};
            while (q.size())
            {
                k = q.front();
                q.pop();
                if (k == y)
                {
                    ok = 1;
                    break;
                }
                for (int i = 0; i < a[k].size(); i++)
                {
                    if (!check[a[k][i]])
                    {
                        check[a[k][i]] = 1;
                        q.push(a[k][i]);
                    }
                }
            }
            if (ok)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}
 

// File: DSA09028 - TÔ MÀU ĐỒ THỊ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int V, E, M, s;
vector<bool> d;
vector<vector<int>> x;
vector<pair<int, int>> a;
void countdeg()
{
    for (int i = 1; i <= V; i++)
    {
        int k = 0;
        for (int v = 1; v <= V; v++)
            if (x[i][v] == 1)
                k++;
        a.push_back({k, i});
    }
}
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> V >> E >> M;
        s = 0;
        x.clear();
        x.resize(V + 1, vector<int>(V + 1, 0));
        a.clear();
        d.clear();
        d.resize(V + 1, 0);
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            x[u][v] = x[v][u] = 1;
        }
        countdeg();
        sort(a.begin(), a.end(), cmp);
        for (auto i : a)
        {
            int u = i.second;
            if (d[u])
                continue;
            d[u] = 1;
            s++;
            for (int v = 1; v <= V; v++)
                if (x[u][v] == 0)
                    d[v] = 1;
        }
        if (s <= M)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
 

// File: DSA09029 - ĐƯỜNG ĐI HAMILTON.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> x[100];
int n, m;
bool ok;
vector<bool> a;
void dfs(int s, int k)
{
    for (int v : x[s])
    {
        if (a[v] == 0)
            continue;
        if (k == n)
        {
            ok = 1;
            return;
        }
        a[v] = 0;
        dfs(v, k + 1);
        a[v] = 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < 100; i++)
            x[i].clear();
        ok = 0;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            x[u].push_back(v);
            x[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            a.clear();
            a.resize(100, 1);
            dfs(i, 1);
            if (ok)
            {
                cout << 1 << endl;
                break;
            }
        }
        if (!ok)
            cout << 0 << endl;
    }
}
 

// File: DSA09030 - ĐỒ THỊ HAI PHÍA.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, u, v, ok;
vector<int> check;
vector<vector<int>> a;
void dfs(int u)
{
    for (auto v : a[u])
    {
        if (check[u] == check[v])
        {
            ok = 0;
            return;
        }
        else if (!check[v])
        {
            check[v] = 3 - check[u];
            dfs(v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ok = 1;
        a.clear();
        a.resize(n + 1);
        check.clear();
        check.resize(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!check[i])
            {
                check[i] = 1;
                dfs(i);
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA09032 - KẾT BẠN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int a[100005], t[100005];
int find(int u)
{
    if (t[u] == u)
        return u;
    t[u] = find(t[u]);
    return t[u];
}
void merge(int u, int v)
{
    int pu = find(u);
    int pv = find(v);
    if (pu == pv)
        return;
    else
        t[pu] = pv;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            a[i] = 0;
            t[i] = i;
        }
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            merge(x, y);
        }
        for (int i = 1; i <= n; i++)
        {
            t[i] = find(t[i]);
            a[t[i]]++;
        }
        cout << *max_element(a + 1, a + n + 1) << endl;
    }
}
 

// File: DSA09033 - MẠNG XÃ HỘI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y, ok = 1;
        cin >> n >> m;
        vector<vector<int>> a(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
        {
            for (auto x : a[i])
            {
                if (a[i].size() != a[x].size())
                {
                    ok = 0;
                    cout << "NO" << endl;
                    break;
                }
            }
            if (!ok)
                break;
        }
        if (ok)
            cout << "YES" << endl;
    }
}
 

// File: DSA09034 - ĐẾM SỐ AO.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, dx, dy, s = 0;
char a[105][105];
int rx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int ry[] = {1, 0, -1, 1, -1, 0, 1, -1};
void dfs(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        dx = x + rx[i];
        dy = y + ry[i];
        if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && a[dx][dy] == 'W')
        {
            a[dx][dy] = '.';
            dfs(dx, dy);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin.ignore(0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 'W')
            {
                a[i][j] = '.';
                dfs(i, j);
                s++;
            }
        }
    }
    cout << s;
}

// File: DSA09037 - HỌP MẶT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k, n, m, u, v, s = 0;
    cin >> k >> n >> m;
    vector<vector<int>> a(n + 1);
    int b[k];
    vector<int> c(n + 1, 0);
    for (int i = 0; i < k; i++)
        cin >> b[i];
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
    }
    for (int i = 0; i < k; i++)
    {
        queue<int> q;
        int check[n + 1] = {};
        q.push(b[i]);
        check[b[i]] = 1;
        while (q.size())
        {
            u = q.front();
            c[u]++;
            q.pop();
            for (auto v : a[u])
            {
                if (!check[v])
                {
                    q.push(v);
                    check[v] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (c[i] == k)
            s++;
    cout << s;
}
 

// File: DSA10001 - TÌM ĐƯỜNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int gx[] = {1, -1, 0, 0};
int gy[] = {0, 0, 1, -1};
int gh[] = {1, 2, 3, 4};
struct point
{
    int x, y, h, s;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, ok = 0;
        cin >> n >> m;
        cin.ignore();
        char a[n + 1][m + 1];
        point st, ed, k;
        queue<point> q;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 'S')
                {
                    st.x = i;
                    st.y = j;
                }
                else if (a[i][j] == 'T')
                {
                    ed.x = i;
                    ed.y = j;
                }
            }
        }
        k = st;
        k.s = 0;
        for (int i = 0; i < 4; i++)
        {
            k.x += gx[i];
            k.y += gy[i];
            k.h = gh[i];
            if (k.x >= 1 && k.x <= n && k.y >= 1 && k.y <= m && a[k.x][k.y] == '.')
                q.push(k);
            k.x -= gx[i];
            k.y -= gy[i];
        }
        while (q.size())
        {
            st = q.front();
            q.pop();
            if (st.x == ed.x && st.y == ed.y)
            {
                ok = 1;
                break;
            }
            k = st;
            for (int i = 0; i < 4; i++)
            {
                k.h = st.h;
                k.s = st.s;
                k.x += gx[i];
                k.y += gy[i];
                if (st.h != gh[i])
                {
                    k.h = gh[i];
                    k.s++;
                }
                if (k.x >= 1 && k.x <= n && k.y >= 1 && k.y <= m && k.s <= 2 && a[k.x][k.y] != '*')
                    q.push(k);
                k.x -= gx[i];
                k.y -= gy[i];
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA10003 - KIỂM TRA CHU TRÌNH SỬ DỤNG DISJOIN SET.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, x, y, ok;
vector<int> svs;
vector<bool> check;
vector<vector<int>> a;
void BFS(int k)
{
    check[k] = 0;
    for (auto i : a[k])
    {
        if (check[i])
        {
            svs[i] = k;
            BFS(i);
        }
        else if (i != svs[k])
        {
            ok = 1;
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ok = 0;
        a.clear();
        svs.clear();
        check.clear();
        a.resize(n + 1);
        svs.resize(n + 1, -1);
        check.resize(n + 1, 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
            if (check[i] && !ok)
                BFS(i);
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 

// File: DSA10004 - ĐƯỜNG ĐI VÀ CHU TRÌNH EULER VỚI ĐỒ THỊ VÔ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, v, s = 0;
        cin >> n >> m;
        vector<vector<int>> a(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
            if (a[i].size() % 2 == 0)
                s++;
        if (s == n)
            cout << 2 << '\n';
        else if (s == n - 2)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}
 

// File: DSA10005 - CHU TRÌNH EULER TRONG ĐỒ THỊ CÓ HƯỚNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, v, ok = 1;
        cin >> n >> m;
        int a[n + 1] = {};
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            a[u]++;
            a[v]--;
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != 0)
            {
                ok = 0;
                cout << 0 << endl;
                break;
            }
        }
        if (ok)
            cout << 1 << endl;
    }
}
 

// File: DSA10006 - CÂY KHUNG CỦA ĐỒ THỊ THEO THUẬT TOÁN DFS.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, x, y;
        cin >> n >> m >> u;
        vector<pair<int, int>> v;
        vector<vector<int>> a(n + 1);
        vector<int> check(n + 1, 0);
        for (int i = 1; i <= m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        stack<int> st;
        st.push(u);
        check[u] = 1;
        while (st.size())
        {
            u = st.top();
            st.pop();
            for (auto i : a[u])
            {
                if (!check[i])
                {
                    check[i] = 1;
                    v.push_back({u, i});
                    st.push(u);
                    st.push(i);
                    break;
                }
            }
        }
        if (v.size() == n - 1)
            for (auto i : v)
                cout << i.first << " " << i.second << endl;
        else
            cout << "-1" << endl;
    }
}
 

// File: DSA10007 - CÂY KHUNG CỦA ĐỒ THỊ THEO THUẬT TOÁN BFS.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, x, y;
        cin >> n >> m >> u;
        vector<pair<int, int>> v;
        vector<vector<int>> a(n + 1);
        vector<int> check(n + 1, 0);
        for (int i = 1; i <= m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        queue<int> q;
        q.push(u);
        check[u] = 1;
        while (q.size())
        {
            u = q.front();
            q.pop();
            for (auto i : a[u])
            {
                if (!check[i])
                {
                    check[i] = 1;
                    q.push(i);
                    v.push_back({u, i});
                }
            }
        }
        if (v.size() == n - 1)
            for (auto i : v)
                cout << i.first << " " << i.second << endl;
        else
            cout << "-1" << endl;
    }
}
 

// File: DSA10011 - DI CHUYỂN TRÊN BẢNG SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
	int x, y, s;
};
struct cmp
{
	bool operator()(struct data a, struct data b)
	{
		return a.s > b.s;
	}
};
int rx[] = {1, -1, 0, 0};
int ry[] = {0, 0, 1, -1};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int a[n + 1][m + 1], check[n + 1][m + 1] = {};
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				cin >> a[i][j];
		}
		struct data u, v;
		priority_queue<struct data, vector<struct data>, cmp> q;
		q.push({1, 1, a[1][1]});
		while (q.size())
		{
			u = q.top();
			q.pop();
			if (u.x == n && u.y == m)
			{
				cout << u.s << endl;
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				v.x = u.x + rx[i];
				v.y = u.y + ry[i];
				v.s = u.s + a[v.x][v.y];
				if (v.x >= 1 && v.x <= n && v.y >= 1 && v.y <= m && !check[v.x][v.y])
				{
					check[v.x][v.y] = 1;
					q.push(v);
				}
			}
		}
	}
}
 

// File: DSA11001 - CÂY BIỂU THỨC 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool Var(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, k;
        cin >> s;
        stack<string> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (Var(s[i]))
                st.push(string(1, s[i]));
            else
            {
                k = st.top();
                st.pop();
                k = s[i] + k;
                k = st.top() + k;
                st.pop();
                st.push(k);
            }
        }
        cout << st.top() << endl;
    }
}
 

// File: DSA11002 - CÂY BIỂU THỨC 2.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool Op(string s)
{
    if (s == "+" || s == "-" || s == "*" || s == "/")
        return 1;
    return 0;
}
int so(string s)
{
    int n = 0;
    for (int i = 0; i < s.length(); i++)
        n = n * 10 + s[i] - '0';
    return n;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y, k;
        cin >> n;
        cin.ignore();
        string s, a;
        getline(cin, s);
        queue<int> st;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                if (a.size() > 0)
                    st.push(so(a));
                a = "";
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9')
            {
                a = s[i] + a;
                continue;
            }
            x = st.front();
            st.pop();
            y = st.front();
            st.pop();
            if (s[i] == '*')
                k = y * x;
            if (s[i] == '/')
                k = y / x;
            if (s[i] == '+')
                k = y + x;
            if (s[i] == '-')
                k = y - x;
            st.push(k);
        }
        cout << st.front() << endl;
    }
}
 

// File: DSA11003 - DUYỆT CÂY 1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int find(int n, int x, int in[])
{
    for (int i = 0; i < n; i++)
        if (in[i] == x)
            return i;
    return -1;
}
void Try(int n, int in[], int pre[])
{
    int k = find(n, pre[0], in);
    if (k != 0)
        Try(k, in, pre + 1);
    if (k != n - 1)
        Try(n - k - 1, in + k + 1, pre + k + 1);
    cout << pre[0] << " ";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int in[n], pre[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> pre[i];
        Try(n, in, pre);
        cout << endl;
    }
}
 

// File: DSA11005 - DUYỆT CÂY 2.cpp
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node
{
    int val;
    Node *left, *right;
};
Node *createNode(int x)
{
    Node *k = new Node;
    k->val = x;
    k->left = k->right = NULL;
    return k;
}
Node *buildTree(int n, int *inorder, int *levelorder, int st, int e)
{
    if (n > 0)
    {
        Node *root = createNode(levelorder[0]);
        int idx = -1;
        unordered_map<int, int> m;
        for (int i = st; i <= e; ++i)
        {
            if (inorder[i] == levelorder[0])
            {
                idx = i;
                break;
            }
            m[inorder[i]]++;
        }
        int L[m.size()], R[e - st - m.size()], l, r;
        l = r = 0;
        for (int i = 1; i < n; ++i)
        {
            if (m[levelorder[i]])
                L[l++] = levelorder[i];
            else
                R[r++] = levelorder[i];
        }
        root->left = buildTree(idx - st, inorder, L, st, idx - 1);
        root->right = buildTree(e - idx, inorder, R, idx + 1, e);
        return root;
    }
    return NULL;
}
void postOrder(Node *root)
{
    if (root->left != NULL)
        postOrder(root->left);
    if (root->right != NULL)
        postOrder(root->right);
    cout << root->val << ' ';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int inorder[n], levelorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> levelorder[i];
        Node *root = buildTree(n, inorder, levelorder, 0, n - 1);
        postOrder(root);
        cout << endl;
    }
}

// File: DSAKT012 - ĐỔI TIỀN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, k, a[35], b[35], ss, mi, ok;
void Try(int x)
{
    for (int i = b[x - 1] + 1; i <= n; i++)
    {
        b[x] = i;
        if (x == k)
        {
            int s = 0;
            for (int j = 1; j <= k; j++)
                s += a[b[j]];
            if (s == ss)
            {
                ok = 1;
                mi = k;
                return;
            }
        }
        else
            Try(x + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    a[0] = ok = 0;
    mi = 50;
    cin >> n >> ss;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        k = i;
        Try(1);
        if (ok == 1)
            break;
    }
    if (ok == 0)
        cout << -1;
    else
        cout << mi;
}
 

// File: DSAKT053 - SỐ NGUYÊN LỚN.cpp
#include <bits/stdc++.h>
using namespace std;
int LCS(string s1, string s2)
{
    int F[s1.size() + 1][s2.size() + 1] = {};
    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            if (s1[i] == s2[j])
                F[i + 1][j + 1] = F[i][j] + 1;
            else
                F[i + 1][j + 1] = max(F[i][j + 1], F[i + 1][j]);
        }
    }
    return F[s1.size()][s2.size()];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        cout << LCS(a, b) << endl;
    }
}
 

// File: DSAKT055 - BÀI TOÁN CÁI TÚI 0-1.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int a[n], b[n];
		vector<vector<int>> l(n, vector<int>(m + 1, 0));
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		for (int i = 0; i < n; i++)
			for (int j = 1; j <= m; j++)
			{
				if (i > 0)
				{
					if (a[i] <= j)
						l[i][j] = max(l[i - 1][j], l[i - 1][j - a[i]] + b[i]);
					else
						l[i][j] = l[i - 1][j];
				}
				else if (a[i] <= j)
					l[i][j] = b[i];
			}
		cout << l[n - 1][m] << endl;
	}
}
 

// File: DSAKT110 - NHÀ KHÔNG KỀ NHAU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 3], f[n + 3] = {};
        for (int i = 3; i <= n + 2; i++)
        {
            cin >> a[i];
            f[i] = max(f[i - 2], f[i - 3]) + a[i];
        }
        cout << max(f[n + 2], f[n + 1]) << endl;
    }
}
 

// File: DÃY CON CÓ K PHẦN TỬ TĂNG DẦN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[k + 1], b[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= k; i++)
            a[i] = i;
        while (1)
        {
            for (int i = 1; i <= k; i++)
                cout << b[a[i]] << " ";
            cout << endl;
            int ok = 0;
            for (int i = k; i >= 1; i--)
            {
                if (a[i] != n - k + i)
                {
                    ok = 1;
                    a[i]++;
                    for (int j = i + 1; j <= k; j++)
                        a[j] = a[j - 1] + 1;
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        cout << endl;
    }
}
 

// File: DÃY CON CÓ TỔNG BẰNG S.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, ans = 1e9;
long long s, a[35];
void Try(int pos, int m, long long d)
{
    if (d == s)
    {
        ans = min(ans, m);
        return;
    }
    for (int i = pos + 1; i <= n; i++)
        if (d + a[i] <= s && m < ans)
            Try(i, m + 1, d + a[i]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Try(0, 0, 0);
    if (ans == 1e9)
        cout << -1;
    else
        cout << ans;
}
 

// File: DÃY CON CÓ TỔNG LẺ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[20];
vector<int> x;
vector<vector<int>> ans;
map<vector<int>, int> m;
void Try(int k, int s)
{
    for (int i = k + 1; i <= n; i++)
    {
        Try(i, s);
        x.push_back(a[i]);
        if ((s + a[i]) % 2 == 1)
        {
            if (m[x] == 0)
            {
                m[x]++;
                ans.push_back(x);
            }
        }
        Try(i, s + a[i]);
        x.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        m.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        Try(0, 0);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
}
 

// File: DÃY CON CÓ TỔNG NGUYÊN TỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[20];
vector<int> x;
vector<vector<int>> ans;
map<vector<int>, int> m;
bool nto(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}
void Try(int k, int s)
{
    for (int i = k + 1; i <= n; i++)
    {
        Try(i, s);
        x.push_back(a[i]);
        if (nto(s + a[i]))
        {
            if (m[x] == 0)
            {
                m[x]++;
                ans.push_back(x);
            }
        }
        Try(i, s + a[i]);
        x.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        m.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        Try(0, 0);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
}
 

// File: DÃY CON LIÊN TIẾP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n], m = 0, s = 0, ans = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m = max(m, a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == m)
            s++;
        else
            s = 0;
        ans = max(ans, s);
    }
    cout << ans;
}
 

// File: DÃY CON TĂNG DẦN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[25];
string k;
vector<int> x;
vector<string> v;
vector<vector<int>> ans;
void Try(int posa)
{
    for (int i = posa + 1; i <= n; i++)
    {
        if (a[i] > a[posa])
        {
            x.push_back(a[i]);
            if (x.size() > 1)
                ans.push_back(x);
            Try(i);
            x.erase(x.end() - 1, x.end());
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Try(0);
    for (int i = 0; i < ans.size(); i++)
    {
        k = "";
        for (int j = 0; j < ans[i].size(); j++)
        {
            k += to_string(ans[i][j]);
            k += " ";
        }
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}
 

// File: DÃY SỐ ĐẸP.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b, c, k, ans = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 1; i < n; i++)
        {
            b = min(a[i], a[i - 1]);
            c = max(a[i], a[i - 1]);
            k = log2(c / b);
            if (pow(2, k) * b == c && k > 0)
                k--;
            ans += k;
        }
        cout << ans << endl;
    }
}

// File: GHÉP CHỮ CÁI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[100];
bool check()
{
    for (int i = 2; i <= n - 1; i++)
        if ((a[i] == 1 || a[i] == 5) && 
        (a[i - 1] != 1 && a[i - 1] != 5) && 
        (a[i + 1] != 1 && a[i + 1] != 5))
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char c;
    cin >> c;
    n = c - 'A' + 1;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    while (1)
    {
        if (check())
        {
            for (int i = 1; i <= n; i++)
                cout << (char)(a[i] + 'A' - 1);
            cout << endl;
        }
        int ok = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a + i + 1, a + n + 1);
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > a[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (ok == 0)
            break;
    }
}
 

// File: HOÁN VỊ CÁC CHỮ SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int to_int(string s)
{
    int a = 0;
    for (int i = 0; i < s.size(); i++)
    {
        a = a * 10 + s[i] - '0';
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    int a[n + 1], MIN = 1e9;
    vector<string> b(m);
    vector<string> c;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        b[i] = "0" + b[i];
    }
    for (int i = 1; i <= n; i++)
        a[i] = i;
    while (1)
    {
        c.clear();
        for (int i = 0; i < m; i++)
        {
            string x = b[i];
            for (int j = 1; j <= n; j++)
                x[j] = b[i][a[j]];
            c.push_back(x);
        }
        sort(c.begin(), c.end());
        MIN = min(MIN, to_int(c[c.size() - 1]) - to_int(c[0]));
        int ok = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a + i + 1, a + n + 1);
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > a[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (ok == 0)
            break;
    }
    cout << MIN;
}
 

// File: HOÁN VỊ DÃY SỐ.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
        cin >> b[i];
    }
    sort(b + 1, b + n + 1);
    while (1)
    {
        for (int i = 1; i <= n; i++)
            cout << b[a[i]] << " ";
        cout << endl;
        int ok = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a + i + 1, a + n + 1);
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > a[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (ok == 0)
            break;
    }
}
 

// File: HOÁN VỊ NGƯỢC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<vector<int>> b;
        for (int i = 1; i <= n; i++)
            a[i] = i;
        while (1)
        {
            b.push_back(a);
            int ok = 0;
            for (int i = n - 1; i >= 1; i--)
            {
                if (a[i] < a[i + 1])
                {
                    ok = 1;
                    sort(a.begin() + i + 1, a.end());
                    for (int j = i + 1; j <= n; j++)
                        if (a[j] > a[i])
                        {
                            swap(a[i], a[j]);
                            break;
                        }
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        for(int i=1;i<=n;i++) cout<<b[b.size()-1][i];
        for(int i=b.size()-2;i>=0;i--){
        	cout<<",";
        	for(int j=1;j<=n;j++) cout<<b[i][j];
		}
		cout<<endl;
    }
}
 

// File: LIỆT KÊ TỔ HỢP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, x;
    cin >> n >> k;
    int a[k + 1];
    vector<int> b;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        m[x]++;
    }
    b.push_back(0);
    for (auto i : m)
        b.push_back(i.first);
    n = b.size() - 1;
    for (int i = 1; i <= k; i++)
        a[i] = i;
    while (1)
    {
        for (int i = 1; i <= k; i++)
            cout << b[a[i]] << " ";
        cout << endl;
        int ok = 0;
        for (int i = k; i >= 1; i--)
        {
            if (a[i] != n - k + i)
            {
                ok = 1;
                a[i]++;
                for (int j = i + 1; j <= k; j++)
                    a[j] = a[j - 1] + 1;
                break;
            }
        }
        if (ok == 0)
            break;
    }
}
 

// File: LIỆT KÊ XÂU KÝ TỰ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char c;
    int n, k;
    cin >> c >> k;
    n = c - 'A' + 1;
    int a[k + 1];
    for (int i = 1; i <= k; i++)
        a[i] = 1;
    while (1)
    {
        for (int i = 1; i <= k; i++)
            cout << (char)('A' + a[i] - 1);
        cout << endl;
        int ok = 0;
        for (int i = k; i >= 1; i--)
        {
            if (a[i] != n)
            {
                ok = 1;
                a[i]++;
                for (int j = i + 1; j <= k; j++)
                    a[j] = a[i];
                break;
            }
        }
        if (ok == 0)
            break;
    }
}
 

// File: LŨY THỪA MA TRẬN 4.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    long long x[10][10];
};
int n;
long long mod = 1000000007;
struct data operator*(struct data a, struct data b)
{
    struct data xx;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            xx.x[i][j] = 0;
            for (int k = 0; k < n; k++)
                xx.x[i][j] = (xx.x[i][j] + (a.x[i][k] * b.x[k][j]) % mod) % mod;
        }
    }
    return xx;
};
struct data poww(struct data a, long long k)
{
    if (k == 1)
        return a;
    if (k % 2 == 1)
        return a * poww(a, k - 1);
    struct data xx = poww(a, k / 2);
    return xx * xx;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long k, s = 0;
        cin >> n >> k;
        struct data a;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a.x[i][j];
        a = poww(a, k);
        for (int i = 0; i < n; i++)
        {
            s += a.x[0][i];
            s %= mod;
        }
        cout << s << endl;
    }
}
 

// File: LŨY THỪA MA TRẬN 5.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    long long x[10][10];
};
int n;
long long mod = 1000000007;
struct data operator*(struct data a, struct data b)
{
    struct data xx;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            xx.x[i][j] = 0;
            for (int k = 0; k < n; k++)
                xx.x[i][j] = (xx.x[i][j] + (a.x[i][k] * b.x[k][j]) % mod) % mod;
        }
    }
    return xx;
};
struct data poww(struct data a, long long k)
{
    if (k == 1)
        return a;
    if (k % 2 == 1)
        return a * poww(a, k - 1);
    struct data xx = poww(a, k / 2);
    return xx * xx;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long k, s = 0;
        cin >> n >> k;
        struct data a;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a.x[i][j];
        a = poww(a, k);
        for (int i = 0; i < n; i++)
        {
            s += a.x[n - 1][i];
            s %= mod;
        }
        cout << s << endl;
    }
}
 

// File: LŨY THỪA MA TRẬN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    long long x[10][10];
};
int n;
long long mod = 1000000007;
struct data operator*(struct data a, struct data b)
{
    struct data xx;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            xx.x[i][j] = 0;
            for (int k = 0; k < n; k++)
                xx.x[i][j] = (xx.x[i][j] + (a.x[i][k] * b.x[k][j]) % mod) % mod;
        }
    }
    return xx;
};
struct data poww(struct data a, long long k)
{
    if (k == 1)
        return a;
    if (k % 2 == 1)
        return a * poww(a, k - 1);
    struct data xx = poww(a, k / 2);
    return xx * xx;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long k, s = 0;
        cin >> n >> k;
        struct data a;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a.x[i][j];
        a = poww(a, k);
        for (int i = 0; i < n; i++)
        {
            s += a.x[n - i - 1][i];
            s %= mod;
        }
        cout << s << endl;
    }
}
 

// File: MIN VÀ MAX.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long s = 0;
    cin >> n;
    vector<int> a(n), l(n), r(n);
    stack<int> b, c;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        while (!b.empty() && a[i] <= a[b.top()])
            b.pop();
        if (b.empty())
            l[i] = 0;
        else
            l[i] = b.top() + 1;
        b.push(i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!c.empty() && a[i] <= a[c.top()])
            c.pop();
        if (c.empty())
            r[i] = n - 1;
        else
            r[i] = c.top() - 1;
        c.push(i);
    }
    for (int i = 0; i < n; i++)
        s = max(s, (long long)a[i] * (r[i] - l[i] + 1));
    cout << s;
}
 

// File: MÃ SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<vector<int>> v1, v2;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
        b[i] = 1;
    }
    while (1)
    {
        v1.push_back(a);
        int ok = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a.begin() + i + 1, a.end());
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > a[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (ok == 0)
            break;
    }
    while (1)
    {
        v2.push_back(b);
        int ok = 0;
        for (int i = n; i >= 1; i--)
        {
            if (b[i] != n)
            {
                ok = 1;
                b[i]++;
                for (int j = i + 1; j <= n; j++)
                    b[j] = 1;
                break;
            }
        }
        if (ok == 0)
            break;
    }
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v2.size(); j++)
        {
            for (int k = 1; k <= n; k++)
                cout << (char)(v1[i][k] + 'A' - 1);
            for (int k = 1; k <= n; k++)
                cout << v2[j][k];
            cout << endl;
        }
    }
}
 

// File: NGƯỜI DU LỊCH.cpp
#include <bits/stdc++.h>
using namespace std;
int n, a[20], b[20], c[20][20], ans = 1e9, s = 0;
vector<int> as;
void Try(int x, vector<int> k)
{
    for (int i = 2; i <= n; i++)
    {
        if (!b[i])
        {
            a[x] = i;
            b[i]++;
            s += c[a[x - 1]][i];
            k.push_back(i);
            if (x == n && s + c[i][1] < ans)
            {
                ans = s + c[i][1];
                as = k;
            }
            else if (s < ans && x < n)
                Try(x + 1, k);
            s -= c[a[x - 1]][i];
            b[i]--;
            k.pop_back();
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
        }
    }
    a[1] = b[1] = 1;
    as.push_back(1);
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    Try(2, as);
    cout << "(";
    for (auto i : as)
        cout << i << ",";
    cout << 1 << ")" << endl;
    cout << ans;
}

// File: PHÁT LỘC.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
void Try(string s)
{
    int k = s.size();
    if (n == k)
    {
        if (s[n - 1] == '6')
            cout << s << endl;
        return;
    }
    if (s[k - 1] == '8')
        Try(s + "6");
    else
    {
        if (k < 4)
            Try(s + "6");
        else if (s[k - 2] == '8' || s[k - 3] == '8')
            Try(s + "6");
        Try(s + "8");
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    Try("8");
}
 

// File: PHẦN TỬ LỚN NHẤT TRONG DÃY CON.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        deque<int> d;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            while (d.size() && a[d.back()] <= a[i])
                d.pop_back();
            d.push_back(i);
            while (d.size() && d.front() <= i - k)
                d.pop_front();
            if (i >= k - 1)
                cout << a[d.front()] << " ";
        }
        cout << endl;
    }
}
 

// File: PTIT125D - Di chuyển ăn cỏ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, u, v, ans, a[6][6];
int rx[] = { 1, -1, 0, 0 };
int ry[] = { 0, 0, 1, -1 };
void Try(int x, int y, int s) {
	if (x == 5 && y == 5 && s + n == 25) {
		ans++;
		return;
	}
	for (int i = 0;i < 4;i++) {
		int xx = x + rx[i];
		int yy = y + ry[i];
		if (xx >= 1 && xx <= 5 && yy >= 1 && yy <= 5 && a[xx][yy] == 0) {
			a[xx][yy] = 1;
			Try(xx, yy, s + 1);
			a[xx][yy] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	a[1][1] = 1;
	for (int i = 0;i < n;i++) {
		cin >> u >> v;
		a[u][v] = 1;
	}
	Try(1, 1, 1);
	cout << ans;
}
 

// File: QUÂN VUA TRÊN BÀN CỜ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    int x, y, s;
};
int rx[] = {1, 1, -1, -1, 0, 0, 1, -1};
int ry[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    struct data u, v, ed;
    queue<struct data> q;
    int check[9][9] = {};
    cin >> u.x >> u.y >> ed.x >> ed.y;
    u.s = 0;
    q.push(u);
    while (q.size())
    {
        u = q.front();
        q.pop();
        if (u.x == ed.x && u.y == ed.y)
        {
            cout << u.s;
            return 0;
        }
        v.s = u.s + 1;
        for (int i = 0; i < 8; i++)
        {
            v.x = u.x + rx[i];
            v.y = u.y + ry[i];
            if (v.x >= 1 && v.x <= 8 && v.y >= 1 && v.y <= 8 && !check[v.x][v.y])
            {
                check[v.x][v.y]++;
                q.push(v);
            }
        }
    }
}
 

// File: SẮP XẾP CHẴN LẺ.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, posl = 0, posc = 0;
    cin >> n;
    vector<int> pl, l, c;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x % 2 == 1)
        {
            l.push_back(x);
            pl.push_back(i);
        }
        else
            c.push_back(x);
    }
    sort(c.begin(), c.end());
    sort(l.begin(), l.end(), greater<int>());
    for (int i = 0; i < n; i++)
    {
        if (posl < pl.size() && i == pl[posl])
            cout << l[posl++] << " ";
        else
            cout << c[posc++] << " ";
    }
}

// File: SẮP XẾP QUÂN HẬU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n = 8, ans;
int c1[20], c2[20], c3[20], a[10][10];
void Try(int x, int s)
{
    if (x == n + 1)
    {
        ans = max(ans, s);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (c1[i] == 0 && c2[i + x] == 0 && c3[x - i + n] == 0)
        {
            c1[i] = c2[i + x] = c3[x - i + n] = 1;
            Try(x + 1, s + a[x][i]);
            c1[i] = c2[i + x] = c3[x - i + n] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        ans = 0;
        for (int i = 0; i < 20; i++)
            c1[i] = c2[i] = c3[i] = 0;
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
                cin >> a[i][j];
        }
        Try(1, 0);
        cout << "Test " << k << ": " << ans << endl;
    }
}
 

// File: SỐ 2 ƯU THẾ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool check(string s)
{
    int d = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '2')
            d++;
    if (d > s.size() / 2)
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string u, v;
    vector<string> a;
    queue<string> q;
    q.push("1");
    q.push("2");
    a.push_back("2");
    while (q.size())
    {
        u = q.front();
        q.pop();
        if (check(u))
            a.push_back(u);
        if (a.size() == 1005)
            break;
        q.push(u + '0');
        q.push(u + '1');
        q.push(u + '2');
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}
 

// File: SỐ CẶP BẠN TỐT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, ans = 0;
    cin >> n >> k;
    vector<string> s(n + 1);
    vector<vector<int>> f(n + 1, vector<int>(30, 0));
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        f[i] = f[i - 1];
        f[i][s[i].size()]++;
    }
    for (int i = 1; i <= n; i++)
        ans += f[i - 1][s[i].size()] - f[max(i - k - 1, 0)][s[i].size()];
    cout << ans;
}
 

// File: SỐ LỘC PHÁT.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, s = 0;
        cin >> n;
        queue<string> dq;
        dq.push("6");
        dq.push("8");
        cout << pow(2, n) << endl;
        while (dq.size())
        {
            string k = dq.front();
            if (k.size() == n)
                cout << k << " ";
            dq.pop();
            if (k.size() != n)
            {
                dq.push(k + "6");
                dq.push(k + "8");
            }
        }
        cout << endl;
    }
}
 

// File: SỐ THỨ TỰ HOÁN VỊ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[10], b[10];
bool check()
{
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int p = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            a[i] = i;
            cin >> b[i];
        }
        while (++p)
        {
            if (check())
            {
                cout << p << endl;
                break;
            }
            for (int i = n - 1; i >= 1; i--)
            {
                if (a[i] < a[i + 1])
                {
                    sort(a + i + 1, a + n + 1);
                    for (int j = i + 1; j <= n; j++)
                    {
                        if (a[j] > a[i])
                        {
                            swap(a[i], a[j]);
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
}
 

// File: SỐ THỨ TỰ TỔ HỢP.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, k, a[15], b[15];
bool check()
{
    for (int i = 1; i <= k; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int p = 0;
        cin >> n >> k;
        for (int i = 1; i <= k; i++)
        {
            a[i] = i;
            cin >> b[i];
        }
        while (++p)
        {
            if (check())
            {
                cout << p << endl;
                break;
            }
            for (int i = k; i >= 1; i--)
            {
                if (a[i] != n - k + i)
                {
                    a[i]++;
                    for (int j = i + 1; j <= k; j++)
                        a[j] = a[j - 1] + 1;
                    break;
                }
            }
        }
    }
}
 

// File: SỐ XA CÁCH.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, check[15];
void Try(string s)
{
    int k = s.size();
    if (k == n)
        cout << s << endl;
    for (int i = 1; i <= n; i++)
        if (k == 0 || (!check[i] && abs(s[k - 1] - '0' - i) != 1))
        {
            check[i] = 1;
            Try(s + to_string(i));
            check[i] = 0;
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        Try("");
    }
}
 

// File: THI ĐẤU ĐỐI KHÁNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    long long a[n + 1], b[m + 1], f[n + 1][m + 1][k + 1] = {}, mod = 1e9 + 9;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] > b[j])
                f[i][j][1] = 1;
            else
                f[i][j][1] = 0;
        }
    }
    for (int p = 1; p <= k; p++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                f[i][j][p] += f[i - 1][j][p] + f[i][j - 1][p] - f[i - 1][j - 1][p];
                if (a[i] > b[j])
                    f[i][j][p] += f[i - 1][j - 1][p - 1];
                f[i][j][p] %= mod;
            }
        }
    }
    while (f[n][m][k] < 0)
        f[n][m][k] += mod;
    cout << f[n][m][k];
}
 

// File: THÁP HÀ NỘI.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void Tower(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << a << " -> " << c << endl;
        return;
    }
    Tower(n - 1, a, c, b);
    Tower(1, a, b, c);
    Tower(n - 1, b, a, c);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char a = 'A', b = 'B', c = 'C';
    int n;
    cin >> n;
    Tower(n, a, b, c);
}
 

// File: TN05009 - CHU TRÌNH THEO DFS.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, v, ok = 0;
        cin >> n >> m;
        vector<int> ans;
        vector<int> check(n + 1);
        vector<int> pre(n + 1, 0);
        vector<vector<int>> a(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
            sort(a[i].begin(), a[i].end());
        stack<int> st;
        st.push(1);
        check[1] = 1;
        while (st.size())
        {
            u = st.top();
            st.pop();
            for (auto i : a[u])
            {
                if (i == 1 && pre[u] != 1)
                {
                    ok = u;
                    break;
                }
                if (!check[i])
                {
                    pre[i] = u;
                    check[i] = 1;
                    st.push(u);
                    st.push(i);
                    break;
                }
            }
            if (ok)
                break;
        }
        if (ok)
        {
            while (pre[ok])
            {
                ans.push_back(ok);
                ok = pre[ok];
            }
            cout << 1 << " ";
            for (int i = ans.size() - 1; i >= 0; i--)
                cout << ans[i] << " ";
            cout << 1;
        }
        else
            cout << "NO";
        cout << endl;
    }
}
 

// File: TRÒ CHƠI CARO “NGANG”.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
char c;
int n;
string s;
bool check()
{
    int dc = 0, dd = 0, fc = 0, fd = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == c)
        {
            dc++;
            dd = 0;
        }
        else
        {
            dc = 0;
            dd++;
        }
        fc = max(fc, dc);
        fd = max(fd, dd);
    }
    if (fc > fd && fc >= 5)
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> c;
        s = "";
        for (int i = 0; i < n; i++)
            s += 'O';
        while (1)
        {
            int ok = 0;
            if (check())
                cout << s << endl;
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] != 'X')
                {
                    ok = 1;
                    s[i] = 'X';
                    for (int j = i + 1; j < n; j++)
                        s[j] = 'O';
                    break;
                }
            }
            if (!ok)
                break;
        }
        cout << endl;
    }
}
 

// File: TRÒ CHƠI VỚI CÁC CON SỐ.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, check[15];
void Try(string s)
{
    int k = s.size();
    if (k == n)
        cout << s << endl;
    for (int i = 1; i <= n; i++)
        if (k == 0 || (!check[i] && abs(s[k - 1] - '0' - i) != 1))
        {
            check[i] = 1;
            Try(s + to_string(i));
            check[i] = 0;
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        Try("");
    }
}
 

// File: TÁCH NHÓM TỐI ƯU.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, ans = 1;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 1; i < n; i++)
        if (a[i] > a[i - 1] + k)
            ans++;
    cout << ans;
}
 

// File: TÍCH CHỮ SỐ.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        stack<int> st;
        for (int i = 9; i >= 2; i--)
        {
            while (n % i == 0)
            {
                st.push(i);
                n /= i;
            }
        }
        if (n > 1)
            cout << -1 << endl;
        else
        {
            while (st.size())
            {
                cout << st.top();
                st.pop();
            }
            cout << endl;
        }
    }
}

// File: TỔ HỢP “NGƯỢC”.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(k + 1);
        vector<vector<int>> v;
        for (int i = 1; i <= k; i++)
            a[i] = i;
        while (1)
        {
            v.push_back(a);
            int ok = 0;
            for (int i = k; i >= 1; i--)
            {
                if (a[i] != n - k + i)
                {
                    ok = 1;
                    a[i]++;
                    for (int j = i + 1; j <= k; j++)
                        a[j] = a[j - 1] + 1;
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        for (int i = v.size() - 1; i >= 0; i--)
        {
            for (int j = 1; j <= k; j++)
                cout << v[i][j] << " ";
            cout << endl;
        }
    }
}
 

// File: TỔNG CÁC SỐ TỰ NHIÊN.cpp

// File: ĐẶT TÊN.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string x;
    vector<string> a;
    map<string, int> m;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        m[x]++;
    }
    for (auto i : m)
        a.push_back(i.first);
    n = a.size();
    a.insert(a.begin(), 1, "");
    int dd[k + 1];
    for (int i = 1; i <= k; i++)
        dd[i] = i;
    while (1)
    {
        for (int i = 1; i <= k; i++)
            cout << a[dd[i]] << " ";
        cout << endl;
        int ok = 0;
        for (int i = k; i >= 1; i--)
        {
            if (dd[i] != n - k + i)
            {
                ok = 1;
                dd[i]++;
                for (int j = i + 1; j <= k; j++)
                    dd[j] = dd[j - 1] + 1;
                break;
            }
        }
        if (ok == 0)
            return 0;
    }
}
 

// File: ĐẾM SỐ VẬT CẢN TRÊN MÊ CUNG.cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, s = 0;
char a[1000][1000];
int rx[] = {1, -1, 0, 0};
int ry[] = {0, 0, 1, -1};
void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int dx = x + rx[i];
        int dy = y + ry[i];
        if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && a[dx][dy] == '#')
        {
            a[dx][dy] = '.';
            dfs(dx, dy);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin.ignore();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '#')
            {
                a[i][j] = '.';
                s++;
                dfs(i, j);
                cout << endl;
            }
        }
    }
    cout << s;
}
 

