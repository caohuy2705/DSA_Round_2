#include <iostream>
#include <algorithm>
using namespace std;

int mostFrequent(int* arr, int n) {
    // Bước 1: Sắp xếp mảng
    sort(arr, arr + n);

    // Bước 2: Tìm số có tần số xuất hiện lớn hơn N/2 lần
    int count = 1;
    int current_element = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] == current_element) {
            count++;
        } else {
            count = 1;
            current_element = arr[i];
        }

        if (count > n / 2) {
            return current_element;
        }
    }

    return -1; // Trả về -1 nếu không tìm thấy số nào thỏa yêu cầu
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int result = mostFrequent(arr, n);
        if (result != -1) {
            cout << result << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}


/* 
2
9
3 3 4 2 4 4 2 4 4
8
3 3 4 2 4 4 2 4

*/

/* ngoc mai
#include <bits/stdc++.h>
using namespace std;
int tkns(int a[],int x, int n){
	int low=0;
	int high=n-1;
	int mid;
	while ( a[low] <= x  &&  a[high] >= x){ 
    		if (a[high] - a[low] == 0)   return 1;
    		mid = low + ((x - a[low]) * (high - low)) / (a[high] - a[low]);
    		if (a[mid] < x) low = mid + 1;
    		else if (a[mid] > x)  high = mid - 1;
    		else    return 1;
	}
	if (a[low] == x)
    		return 1;
	return 0;

}


int tktt(int a[],int x, int n){
	for(int i=0;i<n;i++){
		if(x==a[i]) return 1;
	}
	return 0;
}
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a[n];
		int dem[100000]={0};
		int k=0;
		for(int i=0;i<n;i++) cin >>a[i];
		for(int i=0;i<n;i++){
			if(tkns(a,a[i],n)==1) dem[a[i]]++;
			if(dem[a[i]]>n/2) {
				k=1;
				cout<<a[i]<<endl;
				break;
			}
			
		}
		if(k==0)  cout<<"NO"<<endl;
		
	}
}

*/