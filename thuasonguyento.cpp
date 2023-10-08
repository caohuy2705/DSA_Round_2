#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        cout<<"Test "<<i<<": ";
        for(int j=2;j<=n;j++)
        {
            int cnt=0;
            while(n%j==0)
            {
                cnt++;
                n/=j;
            }
            if(cnt) cout<<j<<"("<<cnt<<") ";
        }
        cout<<endl;
    }
    return 0;
}