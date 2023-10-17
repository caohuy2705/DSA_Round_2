#include<bits/stdc++.h>
#include<stack>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--) {
		string s;
		cin>>s;
		stack<int>nx;
		nx.push(-1);
		int count=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='(') nx.push(i);
			else {
				nx.pop();
				if(nx.size()>0){
					count=max(count,i-nx.top());
				}
				if(nx.empty()) nx.push(i);
			}
		}
		cout<<count<<endl;
	}
}

