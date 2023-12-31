#include<bits/stdc++.h>
#define mod              1000000007
#define ll               long long
#define	p(x)             pair<x,x>
#define v(x)             vector<x>
#define tree             node*
#define sz(a)            a.size()
#define f                first
#define s                second
#define pb(a)            push_back(a)
#define pf(a)            push_front(a)
#define FOR(i,l,r)       for(int i=l;i<r;i++)
#define FORX(i,l,r,x)    for(int i=l;i<r;i+=x)
#define FORD(i,l,r)      for(int i=l;i>=r;i--)
#define correct(x,y,n,m) 0<=(x)&&(x)<(n)&&0<=(y)&&(y)<(m)
#define cin(M,n)         FOR(i,0,n)cin>>M[i]
#define cout(M,n)        FOR(i,0,n)cout<<M[i]<<" "
#define rs(M,x)          memset(M,x,sizeof(M))
#define reset()          FOR(i, 0, 1001)A[i].clear(),check[i]=false
#define faster()         cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()            int t; cin >> t; while (t--)
#define pq(x)            priority_queue<x>
#define neg_pq(x)        priority_queue<x, vector<x>, greater<x>>
#define all(M)           M.begin(),M.end()
using namespace std;


int n;
int M[20][20];
v(int) A[1001];
bool check[1001];
int res = INT_MAX;
void DFS(int u, int sum, int par, int count) {
	if (sum >= res)return;
	check[u] = true;
	for (auto x : A[u]) {
		if (!check[x])DFS(x, sum + M[u][x], u, count + 1);
		else if (x == 1 && x != par && count == n)res = min(res, sum + M[u][1]);
	}
	check[u] = false;
}

int main() {
	faster();
	cin >> n;
	FOR(i, 1, n + 1)FOR(j, 1, n + 1)cin >> M[i][j];
	FOR(i, 1, n + 1)FOR(j, 1, n + 1) if (i != j) A[i].pb(j);
	DFS(1, 0, 0, 1);
	cout << res << endl;
}

