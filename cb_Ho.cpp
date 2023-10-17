// Start of baitapnho.cpp 
#include <bits/stdc++.h>
using namespace std;

main () {
	int n;
	cin >> n;
	int S=0, i=0;
	if (i<=n) {
		S=S+i;
		i++;
	} 
	cout << S;
}
//n=3;
//i i i i
//0 1 2 3

// End of baitapnho.cpp 

// Start of biendoihauto-tiento.cpp 
#include <bits/stdc++.h>
using namespace std;
string s;
bool is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
void solve() {
	stack <string> st;
	for (int i=0; i<s.size(); i++) {
		if (!is_operator(s[i])) st.push(string(1,s[i]));
		else {
			string s1=st.top(); st.pop();
			string s2=st.top(); st.pop();
			string temp=s[i] + s2 + s1;
			st.push(temp);
		}
	}
	cout << st.top() << endl;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		solve();
	}
}


//(A+B)
//(C-D)
//temp=(A+B)
//s1=C
//s2=D
//A
//B


// End of biendoihauto-tiento.cpp 

// Start of biendoihauto-trungto.cpp 
#include <bits/stdc++.h>
using namespace std;
string s;
bool is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
void solve() {
	stack <string> st;
	for (int i=0; i<s.size(); i++) {
		if (!is_operator(s[i])) st.push(string(1,s[i]));
		else {
			string s1=st.top(); st.pop();
			string s2=st.top(); st.pop();
			string temp="(" + s2 + s[i] + s1 + ")";
			st.push(temp);
		}
	}
	cout << st.top() << endl;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		solve();
	}
}


//(A+B)
//(C-D)
//temp=(A+B)
//s1=C
//s2=D
//A
//B


// End of biendoihauto-trungto.cpp 

// Start of biendoiS-T.cpp 
#include <bits/stdc++.h>
using namespace std;
int s, t; 
int solve () {
	queue <pair <int,int>> q;
	set <int> se;
	se.insert(s);
	q.push({s,0});
	while (!q.empty()) {
		pair <int,int> top=q.front();
		q.pop();
		if (top.first==t) return top.second;
		if (top.first*2==t || top.first-1==t) return top.second+1;
		if (se.find(top.first*2)==se.end() && top.first<t) {
			q.push({top.first*2, top.second+1});
			se.insert(top.first*2);
		}
		if (se.find(top.first-1)==se.end() && top.first>1) {
			q.push({top.first-1, top.second+1});
			se.insert(top.first-1);
		}
	}
}
main () {
	int T;
	cin >> T;
	while (T--) {
		cin >> s >> t;
		cout << solve() << endl;
	}
}

// End of biendoiS-T.cpp 

// Start of biendoitiento-hauto.cpp 
#include <bits/stdc++.h>
using namespace std;
string s;
bool is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
void solve() {
	stack <string> st;
	for (int i=s.size()-1; i>=0; i--) {
		if (!is_operator(s[i])) st.push(string(1,s[i]));
		else {
			string s1=st.top(); st.pop();
			string s2=st.top(); st.pop();
			string temp=s1 + s2+ s[i];
			st.push(temp);
		}
	}
	cout << st.top() << endl;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		solve();
	}
}


//(A+B)
//(C-D)
//temp=(A+B)
//s1=C
//s2=D
//A
//B


// End of biendoitiento-hauto.cpp 

// Start of biendoitiento-trung to.cpp 
#include <bits/stdc++.h>
using namespace std;
string s;
bool is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
void solve() {
	stack <string> st;
	for (int i=s.size()-1; i>=0; i--) {
		if (!is_operator(s[i])) st.push(string(1,s[i]));
		else {
			string s1=st.top(); st.pop();
			string s2=st.top(); st.pop();
			string temp="(" + s1 + s[i] + s2 + ")";
			st.push(temp);
		}
	}
	cout << st.top() << endl;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		solve();
	}
}


//(A+B)
//(C-D)
//temp=(A+B)
//s1=C
//s2=D
//A
//B


// End of biendoitiento-trung to.cpp 

// Start of biendoitrungtohauto.cpp 
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return 0;
}

string infixToPostfix(const string& expression) {
    string result;
    stack<char> st;

    for (char ch : expression) {
        if (isalnum(ch))
            result += ch;
        else if (ch == '(')
            st.push(ch);
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // X�a d?u '(' kh?i stack
        } else {
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    cin.ignore(); // X�a d?u newline sau khi d?c T

    while (T--) {
        string exp;
        getline(cin, exp); // Nh?p bi?u th?c trung t?

        string postfix_exp = infixToPostfix(exp);
        cout << postfix_exp << endl;
    }

    return 0;
}


// End of biendoitrungtohauto.cpp 

// Start of biendoitrungtohauto_.cpp 
#include <bits/stdc++.h>
using namespace std;
string s;
int check(char c) {
	if (c=='+'|| c=='-') return 1;
	if (c=='*'|| c=='/') return 2;
	if (c=='^') return 3;
	return 0;
}
void solve () {
	stack <char> st;
	string res="";
	for (int i=0; i<s.size(); i++) {
		if (isalpha(s[i])) res+=s[i];
		else if (s[i]=='(') st.push(s[i]);
		else if (s[i]==')') {
			while (!st.empty() && st.top()!='(') {
				res+=st.top();
				st.pop();
			}
			st.pop();
		} else {
			while (!st.empty() && check(st.top())>=check(s[i])) {
				res +=st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while (!st.empty()) {
		if (st.top()!='(') res+=st.top();
		st.pop();
	}
	cout << res << endl;
}
main () {
	int t;
	cin >> t;
	 while (t--) {
	 	cin >> s;
	 	solve();
	 }
}

// End of biendoitrungtohauto_.cpp 

// Start of bieuthuctanggiam.cpp 
#include <bits/stdc++.h>
using namespace std;
string s;
void solve () {
	s=' '+s;
	stack <int> st;
	for (int i=1; i<=s.size(); i++) {
		if (s[i]=='D') st.push(i);
		else {
			cout << i; 
			while (!st.empty()){
				cout << st.top();
				st.pop();
			}
		}
	}
	cout << endl;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		solve();
	}
}

// End of bieuthuctanggiam.cpp 

// Start of bieuthuctoan hoc.cpp 
#include <bits/stdc++.h>
using namespace std;
int a[101], OK, B[101];
void Try (int i, int s) {
	if (OK) return;
	if (s==23 && i==5) {
		OK=1;
		return;
	}
	for (int j=0; j<5; j++) {
		if (!B[j]) {
			B[j]=1;
			Try(i+1, s*a[j]);
			Try(i+1, s+a[j]);
			Try(i+1, s-a[j]);
			B[j]=0;
		}
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		for (int i=0; i<5; i++) cin >> a[i];
		OK=0;
		for (int i=0; i<5; i++) {
			B[i]=1;
			Try(1,a[i]);
			B[i]=0;
		}
		if (OK) cout << "YES";
		else cout << "NO";
		cout <<endl;
	}
}

// End of bieuthuctoan hoc.cpp 

// Start of bieuthuctuongduong.cpp 
#include <bits/stdc++.h>
using namespace std;
string s;
void solve () {
	stack <char> st;
	for (int i=0; i<s.size(); i++) {
		if (s[i]=='(') {
			if (s[i-1]=='+' || s[i-1]=='-') st.push(s[i-1]);
		}
		if (!st.empty() && st.top()=='-') {
			if (s[i]=='+') s[i]='-';
			else if (s[i]=='-') s[i]='+';
		}
		if (s[i]==')' && !st.empty()) st.pop();
	}
	for (int i=0; i<s.size(); i++) {
		if (s[i]!='(' && s[i]!=')') cout << s[i];
	}
	cout << endl;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		solve();
	}
}

// End of bieuthuctuongduong.cpp 

// Start of BobasobangK.cpp 
#include <bits/stdc++.h>
using namespace std;
main () {
	int t;
	cin >> t;
	while (t--) {
		int n, K;
		cin >> n >> K;
		int a[n], kt=0;
		for (int i=0; i<n; i++) cin >> a[i];
		sort (a,a+n);
		for (int i=0; i<n-2; i++) {
			int j=i+1;
			int k=n-1;
			while (j<k){
				if (a[i]+a[j]+a[k] == K) {
					kt=1;
					break;
				}
				else if (a[i] + a[j] + a[k] < K) j++;
				else k--;
			}
		}
		if (kt) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

// End of BobasobangK.cpp 

// Start of Bobasocotongnhohonk.cpp 
#include <bits/stdc++.h>
using namespace std;
main () {
	int t;
	cin >> t;
	while (t--) {
		int n, K;
		cin >> n >> K;
		long long a[n], count=0;
		for (int i=0; i<n; i++) cin >> a[i];
		sort (a,a+n);
		for (int i=0; i<n-2; i++) {
			int j=i+1;
			int k=n-1;
			while (j<k){
				if (a[i]+a[j]+a[k] < K) {
					count += k-j;
					j++;
				}
				else k--;
			}
		}
		cout << count << endl;
	}
}

// End of Bobasocotongnhohonk.cpp 

// Start of BT1.cpp 
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) { //O(t)
        int a, b;
        cin >> a >> b;
        
        int gcd = a, num=b;
        while ( num > 0) { //O(max(a,b))
            int temp = gcd % num;
			gcd = num;
			num = temp;
        }
        long long lcm = (a * b )/ gcd;  
        cout << gcd << " " << lcm << endl;
    }
    return 0;
}
// Do phuc tap thuat toan: O(t*log(min(a,b)))




// End of BT1.cpp 

// Start of BT2.cpp 
#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) { //O(T)
        int n;
        cin >> n;
        int firstDigit, lastDigit;
		lastDigit = n % 10;
    	while (n >= 10) { //O(log(n))
        	n /= 10;
    	}
    	firstDigit = n;
    	if (firstDigit == lastDigit) cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
// Do phuc tap thuat toan: O(T*log(n))





// End of BT2.cpp 

// Start of BT3.cpp 
#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) { //O(T)
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) { //O(n)
            cin >> arr[i];
        }
		int left = 0, check=1, right = n - 1;
   		while (left < right) { // O(n)
        	if (arr[left] != arr[right]) {
        		check=0;
        		break;
			}
        	left++;
        	right--;
    	}
        if (check) cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
// Do phuc tap thuat toan O(T*n)



// End of BT3.cpp 

// Start of BT4.cpp 
#include <iostream>
using namespace std;
main(){
	int t,n, test=0;
	cin >> t;
	while(t--){ // O(t)
		cin >> n;
        int i=2, dem=0;
        cout << "Test " << test+1 << ": " ;
		while (n>1){  //O(log(n))
	    	if (n%i==0){
	        	n/=i;
	        	dem++;
        	}
        	else {
      	    	i++;
		    	dem=0;
	    	}
	    	if (dem!=0&&(n%i)!=0) {
	        	cout << i << "("  << dem  << ")"<< " ";
	    	}
    	}
    	test++;
		cout << endl;
	}
}
// Do phuc tap: O(t*log(n))



// End of BT4.cpp 

// Start of BT5.cpp 
#include <iostream>
using namespace std;

int main() {
    string operation;
    getline(cin, operation); 

    int a = operation[0] - '0';  
    int b = operation[4] - '0'; 
    int c = operation[8] - '0'; 

    if (a + b == c) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
// Do phuc tap thuat toan O(1)  
  
  

// End of BT5.cpp 

// Start of BT6.cpp 
#include <iostream>
#include <string>
using namespace std;
int main() {
    int T;
    cin >> T; 
    cin.ignore(); 
    while (T--) { // O(T)
        string num;
        getline(cin, num);
        int n = num.length();
    	bool isIncreasing = true;
    	bool isDecreasing = true;
    	int i, j;
    	for (i = 0; i < n - 1; i++) { // O(n)
        	if (num[i] > num[i + 1]) {
            	isIncreasing = false;
            	break;
        	}
    	}
   		
    	for (j = 0; j < n - 1; j++) { // O(n)
        	if (num[j] < num[j + 1]) {
            	isDecreasing = false;
            	break;
        	}
    	}
    	if (isIncreasing || isDecreasing) {
        	cout <<  "YES";
    	} else {
        	cout << "NO";
    	}
        cout << endl;
    }
}
// Do phuc tap: O(T*n)




// End of BT6.cpp 

// Start of BT7.cpp 
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) { // O(N)
        string hoTen;
        getline(cin, hoTen);
		stringstream ss(hoTen);
    	string word;
   		string result;
    	while (ss >> word) {
        	word[0] = toupper(word[0]);
        	for (int i = 1; i < word.length(); i++) {
            	word[i] = tolower(word[i]);
        	}
        	result += word + " ";
    	}
    	if (!result.empty()) {
        	result.erase(result.length() - 1);
    	}
        cout << result << endl;
    }
    return 0;
}

// End of BT7.cpp 

// Start of BT7_2.cpp 
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();
    while (N--) { // O(N)
        string hoTen;
        getline(cin, hoTen);
        hoTen[0]= toupper(hoTen[0]);
        for (int j=1; j < hoTen.size(); j++) { //O(n) n la do dai xau hoTen
        	if (isspace(hoTen[j-1])) hoTen[j]=toupper(hoTen[j]);
        	else hoTen[j]=tolower(hoTen[j]);
		}
		cout << hoTen << endl;
    }
}
//Do phuc tap thuat toan: O(N*n)



// End of BT7_2.cpp 

// Start of BT8.cpp 
#include <iostream>
#include <cstring>
#include <ctype.h>
using namespace std;
void chuanHoa(char s[]){
	char ds[100][50], c[50]=""; int d=0,i;
    char *p=strtok(s," ");
    
    while (p!=NULL){ // O(n) n la do dai xau s
    	p[0]=toupper(p[0]);
    	for ( i=1;i<strlen(p);i++)  p[i]=tolower(p[i]);
    	strcpy(ds[d++],p);
		p=strtok(NULL," ");
	}
	for (i=1;i<d;i++) { // O(n)
		cout << ds[i];
	    if (i<d-1) printf(" ");
	}
	strcpy (c, ds[0]);
	for ( i=0; i< strlen(c); i++) c[i]=toupper (c[i]); //O(n)
	cout <<", " << c << endl;
}
int main () {
	int t;
	cin >> t;
	while (t--) { //O(t)
		cin.ignore();
		char s[101];
		cin.get(s,100);
		chuanHoa(s);
	}
}
// Do phuc tap thuat toan O(t*n)



// End of BT8.cpp 

// Start of BT9.cpp 
#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin, s); 
    int count =0;
    for (int i=1; i< s.size()-1; i++) {
    	if (s[i]!=s[i-1] && s[i]!= s[i+1]) count ++;
	}
	cout << count/2

}


// End of BT9.cpp 

// Start of BT9_2.cpp 
#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
    getline(cin, s); 
	int count = 0;
	for (int i = 0; i < s.size() - 1; i++) { //O(n) n la do dai xau s
		int p = 0, arr[200] = { 0 };
		for (int j = i + 1; j < s.size(); j++) { //O(n)
			if (s[i] == s[j]) {
				p = j;
			}
		}
		if (p == 0 || p == i + 1) continue;
		for (int j = i + 1; j < p; j++) { //O(n)
			arr[s[j]]++;
		}
		for (int j = 'A'; j <= 'Z'; j++) { //O(1)
			if (arr[j] == 1) count++;
		}
	}
	cout <<  count / 2 << endl;
	return 0;
}
// do phuc tap O(n^2)



// End of BT9_2.cpp 

// Start of BTudsxc.cpp 
#include <iostream>
#include <vector>
#include <algorithm>

// H�m s?p x?p ch?n
std::vector<int> sortDigits(std::vector<long long>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(arr[i], arr[min_idx]);
    }

    std::vector<int> result;
    for (long long num : arr) {
        while (num > 0) {
            int digit = num % 10;
            result.push_back(digit);
            num /= 10;
        }
    }
    
    return result;
}

int main() {
    int T;
    std::cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        std::cin >> n;

        std::vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }

        std::vector<int> result = sortDigits(arr);

        for (int digit : result) {
            std::cout << digit << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

// End of BTudsxc.cpp 

// Start of cautrucdulieuhangdoi.cpp 
#include <bits/stdc++.h>
using namespace std;
main () {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		queue <int> q;
		while (n--) {
			int ask;
			cin >> ask;
			switch (ask) {
				case 1: cout << q.size () << endl;
						break;
				case 2: if (q.empty()) cout << "YES"; 
						else cout << " NO";
						cout << endl;
						break;
				case 3: int temp; 
						cin >> temp; q.push(temp); break;
				case 4: if (!q.empty()) q.pop(); break;
				case 5: if (q.empty()) cout << "-1" << endl;
						else cout << q.front() << endl; break;
				case 6: if (q.empty()) cout << "-1" << endl;
						else cout << q.back() << endl; 
						break;
			}
		}
	}
}

// End of cautrucdulieuhangdoi.cpp 

// Start of cautrucdulieuhangdoi2.cpp 
#include <bits/stdc++.h>
using namespace std;
main () {
	int Q;
	cin >> Q;
	cin.ignore();
	queue <int> q;
	while (Q--) {
		string s;
		cin >> s;
		if (s=="PUSH") {
			int n;
			cin >> n;
			q.push(n);
		}
		if (s=="POP") {
			if (!q.empty()) q.pop();
		}
		if (s== "PRINTFRONT") {
			if (!q.empty()) cout << q.front() << endl;
			else cout << "NONE" << endl;
		}
	}
}

// End of cautrucdulieuhangdoi2.cpp 

// Start of CHATGPT-DSA06007_sap-xep-day-con-lien-tuc.cpp 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find_sorted_subarray(int n, vector<int> A) {
    vector<int> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    int L = -1, R = -1;
    for (int i = 0; i < n; i++) {
        if (A[i] != sorted_A[i]) {
            L = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (A[i] != sorted_A[i]) {
            R = i;
            break;
        }
    }

    cout << L+1 << " " << R+1 << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        find_sorted_subarray(n, A);
    }

    return 0;
}

// End of CHATGPT-DSA06007_sap-xep-day-con-lien-tuc.cpp 

// Start of CHATGPTdemcap.cpp 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countPairs(vector<int>& X, vector<int>& Y) {
    int n = X.size();
    int m = Y.size();

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (X[i] == 0) {
            continue;  // Ignore zero
        }

        for (int j = 0; j < m; j++) {
            if (X[i] > Y[j]) {
                count++;
            } else {
                break;  // Stop checking further elements in Y[]
            }
        }
    }

    return count;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<int> X(n);
        for (int i = 0; i < n; i++) {
            cin >> X[i];
        }

        vector<int> Y(m);
        for (int i = 0; i < m; i++) {
            cin >> Y[i];
        }

        int result = countPairs(X, Y);
        cout << result << endl;
    }

    return 0;
}

// End of CHATGPTdemcap.cpp 

// Start of chenhlechnhonhat.cpp 
#include <bits/stdc++.h>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, MIN=1e9;
		cin >> n;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		sort (a, a+n);
		for (int i=0; i<n-1; i++) {
			MIN= min(MIN,a[i+1]-a[i]);
		}
		cout << MIN << endl;
	}
}

// End of chenhlechnhonhat.cpp 

// Start of chiamang.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, k, a[21], sum, check[21], OK;
void Try (int cursum, int count) {
	if (count==k) {
		OK=1;
		return;
	}
	if (OK) return;
	for (int j=1; j<=n; j++) {
		if (!check[j]) {
			check[j]=1;
			if (cursum==sum) Try(0,count+1);
			else if (cursum<sum) Try(cursum+a[j],count);
				else return;
		}
		check[j]=0;
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		OK=0, sum=0;
		for (int i=1; i<=n; i++) {
			cin >> a[i];
			sum+=a[i];
		}
		if (sum%k!=0) cout << OK << endl; 
		else {
			sum/=k;
			Try(0,0);
			cout << OK << endl;
		}	
	}
}

// End of chiamang.cpp 

// Start of combined.cpp 

// End of combined.cpp 

// Start of CTDL_005_xoa-du-lieu-trong-ds-lkdon.cpp 
#include<bits/stdc++.h>
using namespace std;
main () {
	int n,k;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) cin >> a[i];
	cin >> k;
	for (int i=0; i<n; i++) {
		if (a[i]!=k) cout << a[i] << " ";
	}
}

// End of CTDL_005_xoa-du-lieu-trong-ds-lkdon.cpp 

// Start of CTDL_006_loc-du-lieu-trung-trong-dslk-don.cpp 
#include <bits/stdc++.h>
using namespace std;
main () {
	int n, i;
	cin >> n;
	int a[n];
	set <int> s;
	for (i=0; i<n; i++) {
		cin >> a[i];
		int k=s.size();
		s.insert(a[i]);
		if (k<s.size()) cout << a[i] << " ";
	}
}

// End of CTDL_006_loc-du-lieu-trung-trong-dslk-don.cpp 

// Start of daotu.cpp 
#include <bits/stdc++.h>
using namespace std;
main () {
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		string s;
		getline (cin, s);
		stringstream ss(s);
		string token;
		stack <string> st;
		while (ss >> token) {
			st.push(token);
		}
		while (!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}
}

// End of daotu.cpp 

// Start of datten-1.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, k, C[100];
string x[100], c;
set <string> s;
void in() {
	for (int i=1; i<=k; i++) cout << x[C[i]] << " ";
	cout << endl;
}
void Try(int i, int m) {
	for (int j=C[i-1]+1; j<=m-k+i; j++) {
		C[i]=j;
		if (i==k) in();
		else Try(i+1,m);
	}
}
main () {
	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> c;
		s.insert(c);
	}
	C[0]=0;
	int j=1, m=s.size();
	for (string i:s) {
		x[j++]=i;
	}
	Try(1,m);
}

// End of datten-1.cpp 

// Start of datten-2.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, C[30], OK, k;
void in() {
	for (int i=1; i<=k; i++) {
		cout << (char)(64 + C[i]);
	}
	cout << endl;
}
void sinh() {
	int i=k;
	while (C[i]==n-k+i) i--;
	if (i==0) OK=1;
	else {
		C[i]++;
		for (int j=i+1; j<=k; j++) C[j] = C[j-1]+1;
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		OK=0;
		for (int i=1; i<=k; i++) C[i]=i;
		while (!OK) {
			in();
			sinh();
		}
	}
}

// End of datten-2.cpp 

// Start of daycontangdainhatquyhoacdong.cpp 
#include <iostream>
#include <vector>
using namespace std;

// H�m d? quy d? t�m d�y con tang d�i nh?t k?t th�c t?i v? tr� i
int longestIncreasingSubsequenceRecursive(vector<int>& A, int N, int i, int& max_length) {
    if (i == 0) {
        return 1;
    }

    int current_length = 1;

    for (int j = 0; j < i; ++j) {
        if (A[i] > A[j]) {
            int subsequence_length = longestIncreasingSubsequenceRecursive(A, N, j, max_length) + 1;
            current_length = max(current_length, subsequence_length);
        }
    }

    max_length = max(max_length, current_length);
    return current_length;
}

int longestIncreasingSubsequence(vector<int>& A, int N) {
    int max_length = 1;
    longestIncreasingSubsequenceRecursive(A, N, N - 1, max_length);
    return max_length;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int result = longestIncreasingSubsequence(A, N);
    cout << result << endl;

    return 0;
}

// End of daycontangdainhatquyhoacdong.cpp 

// Start of daycontangdan.cpp 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_increasing(const vector<int>& subset) {
    for (int i = 0; i < subset.size() - 1; ++i) {
        if (subset[i] >= subset[i + 1]) {
            return false;
        }
    }
    return true;
}

void find_subsets(const vector<int>& a, int n, int start, vector<int>& subset) {
    if (subset.size() >= 2 && is_increasing(subset)) {
        for (int i = 0; i < subset.size(); ++i) {
            cout << subset[i] << " ";
        }
        cout << endl;
    }

    for (int i = start; i < n; ++i) {
        subset.push_back(a[i]);
        find_subsets(a, n, i + 1, subset);
        subset.pop_back();
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end()); // S?p x?p d�y a d? in ra theo th? t? t? di?n

    vector<int> subset;
    find_subsets(a, n, 0, subset);

    return 0;
}


// End of daycontangdan.cpp 

// Start of daycontongbangK.cpp 
#include <bits/stdc++.h> 
using namespace std;
int n, k, a[11], b[11], OK, sum;
void out(int j) {
	cout << "[";
	for (int i=1; i<j-1; i++) cout << b[i] << " ";
	cout << b[j-1] << "] ";
}
void Try(int i, int sum, int s ) {
	if (sum==k) {
		OK=1;
		out (i);
		return;
	}
	for (int j=s; j<=n; j++) {
		sum+=a[j];
		b[i]=a[j];
		if (sum<=k) Try(i+1, sum, j+1);
		sum-=a[j];
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		OK=0;
		for (int i=1; i<=n; i++) cin >> a[i];
		sort (a+1, a+n+1);
		Try(1,0,1);
		if (!OK) cout << "-1";
		cout << endl;
	} 
}

// End of daycontongbangK.cpp 

// Start of dayngoacdungdainhat.cpp 
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


// End of dayngoacdungdainhat.cpp 

// Start of Dayso-1.cpp 
#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> v(11);
void out () {
	cout << "[";
	for (int i=0; i<v.size()-1; i++) cout << v[i] << " ";
	cout << v[v.size()-1] << "]" << endl;
}
void solve() {
	while (v.size()>1) {
		for (int i=0; i<v.size()-1; i++) {
			v[i]=v[i]+v[i+1];
		}
		v.pop_back();  //xoa phan tu cuoi cung cua mang
		out();
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		v.resize(n); //dung khi v da bi pop.back het sach sau 1 lan test
		for (int i=0; i<v.size(); i++) cin >> v[i];
		out();
		solve();
	}
}

// End of Dayso-1.cpp 

// Start of dayso-2.cpp 
#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> v(11);
vector <vector <int>> res;
void out () {
	for (int i=res.size()-1; i>=0; i--) {
		cout << '[';
		for (int j=0; j<res[i].size()-1; j++) cout << res[i][j] << ' ';
		cout << res[i].back() << ']'<<' ' ;
	}
	cout << endl;
}
void solve() {
	while (v.size()>1) {
		for (int i=0; i<v.size()-1; i++) {
			v[i]=v[i]+v[i+1];
		}
		v.pop_back();  //xoa phan tu cuoi cung cua mang
		res.push_back(v);
	}
	out();
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		res.clear();
		v.resize(n); //dung khi v da bi pop.back het sach sau 1 lan test
		for (int i=0; i<v.size(); i++) cin >> v[i];
		res.push_back(v);
		solve();
	}
}

// End of dayso-2.cpp 

// Start of demcap(somu).cpp 
#include <iostream>
#include <vector>
#include <cmath>

int countPairs(std::vector<int>& X, std::vector<int>& Y, int n, int m) {
    std::vector<int> countX(1001, 0); // T?o m?ng countX[] d? luu s? l?n xu?t hi?n c?a t?ng ph?n t? trong X[]
    std::vector<int> countY(1001, 0); // T?o m?ng countY[] d? luu s? l?n xu?t hi?n c?a t?ng ph?n t? trong Y[]

    for (int i = 0; i < n; i++) {
        countX[X[i]]++;
    }

    for (int j = 0; j < m; j++) {
        countY[Y[j]]++;
    }

    int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pow(X[i], Y[j]) > pow(Y[j], X[i])) {
                result += countY[Y[j] + 1];
            }
        }

        if (X[i] == 0) {
            continue;
        }

        if (X[i] == 1) {
            result += countY[0];
        } else {
            result += countY[0] + countY[1];
        }
    }

    return result;
}

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> X(n);
        for (int i = 0; i < n; i++) {
            std::cin >> X[i];
        }

        std::vector<int> Y(m);
        for (int i = 0; i < m; i++) {
            std::cin >> Y[i];
        }

        int result = countPairs(X, Y, n, m);
        std::cout << result << std::endl;
    }

    return 0;
}

// End of demcap(somu).cpp 

// Start of demcap.cpp 
#include <bits/stdc++.h>
using namespace std;
main () {
	int t;
	cin >> t;
	while (t--) {
		int n, K;
		cin >> n >> K;
		int a[n], count=0;
		for (int i=0; i<n; i++) cin >> a[i];
		sort (a,a+n);
		int l=0, r=0;
	    while (r<n) {
	   		if (a[r]-a[l] < K){
	   			count += r-l;
	   			r++;
		    }
		    else l++;
	    }
		cout << count << endl;
	}
}

// End of demcap.cpp 

// Start of demcap_somu.cpp 
#include <bits/stdc++.h>
using namespace std;
int cnt[5];
int count (int y[], int m, int x) {
	if (x==0) return 0;
	if (x==1) return cnt[0];
	long long res=cnt[0] + cnt[1];
	auto it = upper_bound(y, y+m, x);
	res +=(y+m)-it;
	if (x==2) res-=(cnt[4]+cnt[3]);
	if (x==3) res+=cnt[2];
	return res;
} 
main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int a[n], b[m];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		for (int i=0; i<m; i++) {
			cin >> b[i];
			if (b[i] <= 4) cnt[b[i]] ++;
		};
		long long ans=0;
		sort(b,b+n)	;
		for (int x:a) {
			ans+=count (b,m,x);
		}
		cout << ans << endl;
		memset (cnt, 0, sizeof(cnt));
	}
}

// End of demcap_somu.cpp 

// Start of demsodaungoacdoichieu.cpp 
#include <bits/stdc++.h>
using namespace std;
main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		stack <char> st;
		int dem=0;
		for (int i=0; i<s.size(); i++) {
			if (s[i]!=')') st.push(s[i]);
			else {
				if (st.empty()) {
					st.push('(');
					dem ++;
				}else {
					st.pop();
				}
			}
		}
		cout << dem + st.size()/2 << endl;
	}
}

// End of demsodaungoacdoichieu.cpp 

// Start of dichuyentrongmatran.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, m, a[101][101], dem;
void Try (int i, int j) {
	if (i==n && j==m) {   // neu thoa man dieu kien dung
		dem++; // giai quyet truong hop suy bien
		return; 
	}
	if (i+1<=n) Try(i+1, j); // goi ham de quy neu thoa man dieu kien
	if (j+1<=m) Try(i, j+1); // // goi ham de quy neu thoa man dieu kien
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		dem=0;
		for (int i=1; i<=n ;i++)
			for (int j=1; j<=m; j++)
				cin >> a[i][j];
		Try(1,1);
		cout << dem << endl;
	}
}



// End of dichuyentrongmatran.cpp 

// Start of dichuyentrongmecung.cpp 
#include <bits/stdc++.h>
using namespace std;
int n;
bool a[11][11], OK;
string s;
void Try(int x, int y) {
	if (x==n && y==n) {
		cout << s << " ";
		OK=1;
		return;
	}
	if (a[x+1][y]) {
		s+='D';
		Try(x+1, y);
		s.erase(s.size()-1);
	}
	if (a[x][y+1]) {
		s+='R';
		Try(x, y+1);
		s.erase(s.size()-1);
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		OK=0;
		s="";
		for (int i=1; i<=n; i++) 
			for (int j=1; j<=n; j++) 
				cin >> a[i][j];
		if (a[1][1]==0) {
			cout << -1 << endl;
			continue;
		}
		Try (1,1);
		if (!OK) cout << -1;
		cout << endl;
	}
}

// End of dichuyentrongmecung.cpp 

// Start of dichuyentrongmecung2.cpp 
#include <bits/stdc++.h>
using namespace std;
int n;
bool a[11][11], OK, check[11][11];
string s;
void Try(int x, int y) {
	if (x==n && y==n) {
		cout << s << " ";
		OK=1;
		return;
	}
	check[x][y]=1;
	if (x<n && a[x+1][y]==1 && check[x+1][y]==0) {
		s+="D";
		Try(x+1,y);
		s.erase(s.size()-1);	
	}
	if (y>=1 && a[x][y-1]==1 && check[x][y-1]==0) {
		s+="L";
		Try(x,y-1);
		s.erase(s.size()-1);
	}
	if (y<n && a[x][y+1]==1 && check[x][y+1]==0) {
		s+="R";
		Try(x,y+1);
		s.erase(s.size()-1);	
	}
	if (x>=1 && a[x-1][y]==1 && check[x-1][y]==0) {
		s+="U";
		Try(x-1,y);
		s.erase(s.size()-1);	
	}
	check[x][y]=0;
}
main() {
	int t; 
	cin >> t;
	while (t--) {
		cin >> n;
		OK=0;
		for (int i=1; i<=n; i++) 
			for (int j=1; j<=n; j++)
				cin >> a[i][j];
		if (!a[1][1]) {
			cout << "-1" << endl;
			continue;
		}
		Try(1,1);
		if (!OK) cout << -1;
		cout << endl;
	}
}

// End of dichuyentrongmecung2.cpp 

// Start of diemcanbang.cpp 
#include <bits/stdc++.h>
using namespace std;
main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n], sum=0, leftSum=0, kt=0;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			sum+=a[i];
		}
		for (int i=0; i<n; i++) {
			sum-=a[i];
			if (sum==leftSum) {
				cout << i+1 << endl;
				kt=1;
				break;
			}
			else leftSum+=a[i];
		}
		if (!kt) cout << "-1" << endl;
	}
}

// End of diemcanbang.cpp 

// Start of doichocacchuso.cpp 
#include <bits/stdc++.h>
using namespace std;
main () {
	int t, k; 
	string s;
	cin >> t;
	while (t--) {
		cin >> k >> s;
		for (int i=0; i<k && i< s.size(); i++) {
			int MAX=i, j=s.size();
			while (j-->i) {
				if (s[j]>s[MAX]) MAX=j;
			}
			if (MAX!=i) swap(s[i],s[MAX]);
			else k++;
		}
		cout << s << endl;
	}
}

// End of doichocacchuso.cpp 

// Start of doitien.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, s, kq=1000, a[40];
void Try(int i, int sum, int x) {
	if (sum>s || x>kq) return;
	if (i==n) {
		if (sum==s) {
			kq=min(kq,x);
		}
		return;
	}
	Try(i+1, sum, x);
	Try(i+1, sum+a[i], x+1);
}
main () {
	cin >> n >> s;
	for (int i=0; i<n; i++) cin >> a[i];
	Try(0,0,0);
	if (kq==1000) cout <<"-1";
	else cout << kq;
}

// End of doitien.cpp 

// Start of DSA06001_sap-xep-xen-ke.cpp 
#include <bits/stdc++.h>
using namespace std;
void nhap (int a[], int n) {
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
}
void sort_ ( int a[], int n) {
	sort (a, a+n);
	int m=0, j=n;
	for (int i=0; i<n; i++) {
		if (i % 2 == 0) {
			j--;
			cout << a[j] << " ";
		}
		else {
			m++;
			cout << a[m-1] << " ";
		}
	}
}
main () {
	int n, t, a[1000];
	cin >> t;
	while (t--) {
		cin >> n;
		nhap (a, n);
		sort_(a,n);
		cout << endl;
	}
}

// End of DSA06001_sap-xep-xen-ke.cpp 

// Start of DSA06002_sap-xep-theo-gia-tri-tuyet-doi.cpp 
#include <bits/stdc++.h>
using namespace std;
void nhap (int a[], int n) {
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
}
void sort_(int a[], int n, int X) {
	vector <pair <int, int>> v (n);
	for (int i=0; i<n; i++) {
		v[i].first = abs(a[i]-X);
		v[i].second=i;
	}
	sort (v.begin(), v.end());
	for (int i=0; i<n; i++) {
		cout << a[v[i].second] << " ";
	}
}
main () {
	int n, t, X;
	cin >> t;
	while (t--) {
		cin >> n >> X;
		int a[n];
		nhap (a, n);
		sort_(a,n,X);
		cout << endl;
	}
}

// End of DSA06002_sap-xep-theo-gia-tri-tuyet-doi.cpp 

// Start of DSA06003_doi-cho-it-nhat.cpp 
#include <bits/stdc++.h>
using namespace std;
void nhap (int a[], int n) {
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
}
void sort_(int a[], int n){
    int i, j, t, kt, MIN=1e9;
    for(i=0; i<n-1; i++){
        int count=1;
        for(j=0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                t=a[j]; a[j]=a[j+1]; a[j+1]=t;
                kt=1;
            }
        }
        if(kt==0) break;
        count ++;
    }
    MIN=min(count,MIN);
    cout << MIN << endl;
}
//void sort_(int a[], int n) {
//	int s=0;
//	for (int i=0; i<n-1; i++) {
//		int k=i;
//		for (int j=i+1; j<n; j++) {
//			if (a[j]<a[k]) k=j;
//		}
//		if (k!=i) {
//			s++;
//			swap(a[i],a[k]);
//		}
//	}
//	cout << s;
//}
main () {
	int n, t, a[1000];
	cin >> t;
	while (t--) {
		cin >> n;
		nhap (a, n);
		sort_(a,n);
		cout << endl;
	}
}

// End of DSA06003_doi-cho-it-nhat.cpp 

// Start of DSA06004_Hop-va-giao-cua-hai-day-so-1.cpp 
#include <bits/stdc++.h>
using namespace std;
main () {
	int n, t, a[100000], b[100000], m, i;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		set <int> inter;
		set <int> uni;
		int k=-1;
		for (i=0; i<n; i++) {
			cin >> a[i];
			uni.insert(a[i]);
		}
		for (i=0; i<m; i++) {
			cin >> b[i];
			uni.insert(b[i]);
			if (n+i-uni.size() != k) {
				inter.insert(b[i]);
				k++;
			}
		}
		for ( int x: uni) cout << x << " ";
		cout << endl;
		for ( int x: inter) cout << x << " ";
		cout << endl;
	}
}

// End of DSA06004_Hop-va-giao-cua-hai-day-so-1.cpp 

// Start of DSA06004_Hop-va-giao-cua-hai-day-so-1_cach2.cpp 
#include <bits/stdc++.h>
using namespace std;
main () {
	int n, t, m, i, x;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		map <int, int> a,b,c;
		for (i=0; i<n; i++) {
			cin >> x;
			a[x]++;
			b[x]++;
		}
		for (i=0; i<m; i++) {
			cin >> x;
			c[x]++;
			b[x]++;
		}
		for ( auto i: b) cout << i.first << " ";
		cout << endl;
		for ( auto i: a) {
			if (c[i.first] > 0) cout << i.first << " ";
		}
		cout << endl;
	}
}

// End of DSA06004_Hop-va-giao-cua-hai-day-so-1_cach2.cpp 

// Start of DSA06006_sap-xep-012.cpp 
#include <bits/stdc++.h> 
using namespace std;
main () {
	int n, t, x;
	cin >> t;
	while (t--) {
		cin >> n;
		int a[3]={};
		for (int i=0; i<n; i++) {
			cin >> x;
			a[x]++;
		}
		for (int i=0; i<3; i++) {
			for (int j=0; j<a[i]; j++){
				cout << i << " ";
			}
		}
		cout << endl;
	}
}

// End of DSA06006_sap-xep-012.cpp 

// Start of DSA06007_sap-xep-day-con-lien-tuc.cpp 
#include <bits/stdc++.h>
using namespace std;
void nhap (vector <int> &A, int n) {
	for (int i=0; i<n; i++) {
		cin >> A[i];
	}
}
void sort_ ( int n, vector <int> &A) {
	vector <int> B = A;
	sort (B.begin(), B.end());
	int L=0, R=0;
	for (int i=0; i<n; i++) {
		if (A[i]!=B[i]) {
			L=i+1;
			break;
		}
	}
	for (int i=n-1; i>=0; i--) {
		if (A[i]!=B[i]) {
			R=i+1;
			break;
		}
	}
	cout << L << " " << R << endl;
}
main () {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector <int> A(n);
		nhap (A,n);
		sort_ (n,A);
	}
}

// End of DSA06007_sap-xep-day-con-lien-tuc.cpp 

// Start of DSA06009_cap-so-tong-bang-k.cpp 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a[100000], k, dem=0;
        map <int, int> x;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            x[a[i]]++;
        }
        for (auto i : x) {
        	if (i.first*2==k) dem+=i.second*(i.second-1);
        	else dem+=i.second*x[k-i.first];
        }
        cout << dem/2<<endl;
    }
    return 0;
}

// End of DSA06009_cap-so-tong-bang-k.cpp 

// Start of DSA06010_sap-xep-chu-so.cpp 
#include <bits/stdc++.h> 
using namespace std;
main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n; 
		string x;
		int b[10]={};
		for (int i=0; i<n; i++) {
			cin >> x;
			for (int j=0; j<x.size(); j++) {
				b[x[j]-'0']++;
			}
		}
		for (int i=0; i<10; i++) if (b[i]>0) cout << i << " ";
		cout << endl;
	}
}

// End of DSA06010_sap-xep-chu-so.cpp 

// Start of DSA06011_tong-gan-0-nhat.cpp 
#include <bits/stdc++.h>
using namespace std;
main () {
	int t;
	cin >> t;
	while (t--) {
		int n; 
		cin>> n;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		int min=a[0] + a[1];
		for (int i=0; i<n-1; i++) {
			for (int j=i+1; j<n; j++) {
				if (abs(a[i]+a[j])< abs(min))
				min = a[i] + a[j];
			}
		}
		cout << min << endl;
	}
}

// End of DSA06011_tong-gan-0-nhat.cpp 

// Start of DSA06012_phan-tu-lon-nhat.cpp 
#include <bits/stdc++.h>
using namespace std;
main () {
	int t;
	cin >> t;
	while (t--) {
		int n,k; 
		cin >> n >> k;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		sort (a,a+n);
		for (int i=n-1;i>n-k-1; i--) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}

// End of DSA06012_phan-tu-lon-nhat.cpp 

// Start of DSA06013_so-lan-xuat-hien.cpp 
#include <bits/stdc++.h>
using namespace std;
void nhap ( int a[], int n) {
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
}
int a[1000000];
int main () {
	int n, t, k, sum;
	cin >> t;
	while (t--) {
		sum=0;
		cin >> n >> k;
		nhap (a, n);
		for (int i=0; i<n; i++){
			if (a[i]==k) sum++;
		}	
		if (sum == 0) cout << "-1\n" ; else cout << sum << endl;
	}
}

// End of DSA06013_so-lan-xuat-hien.cpp 

// Start of DSA06014_tong-cap-so-nguyen-to.cpp 
#include <bits/stdc++.h>
using namespace std;
int checkNT (int a) {
	if (a<2) return 0;
	for (int i=2; i<= sqrt(a); i++) {
		if (a%i==0) return 0;
	}
	return 1;
}
main() {
	int t;
	cin >> t;
	while (t--) {
		int n, KT=0;
		cin >> n;
		for (int i=1; i<=n/2; i++) {
			if (checkNT(i) && checkNT (n-i)) {
				KT=1;
				cout << i << " " << n-i << endl;
				break;
			}
		}
		if (KT==0) cout << -1 << endl;
	}
}

// End of DSA06014_tong-cap-so-nguyen-to.cpp 

// Start of DSA06016_tich-lon-nhat-nho-nhat.cpp 
#include <bits/stdc++.h> 
using namespace std;
main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m, maxA=INT_MIN, minB=INT_MAX, x;
		cin >> n >> m;
		for (int i=0; i<n; i++) {
			cin >> x;
			maxA = max(maxA, x);
		}
		for (int i=0; i<m; i++) {
			cin >> x;
			minB = min(minB, x);
		}
		cout << (long long) maxA*minB << endl;
	}
}

// End of DSA06016_tich-lon-nhat-nho-nhat.cpp 

// Start of DSA06017_tron-hai-day.cpp 
#include <bits/stdc++.h> 
using namespace std;
main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector <int> a(n+m);
		for (int i=0; i<m+n; i++) {
			cin >> a[i];
		}
		sort (a.begin(), a.end());
		for (int i=0; i<m+n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}

// End of DSA06017_tron-hai-day.cpp 

// Start of DSA06018_bosungphantu.cpp 
#include <bits/stdc++.h> 
using namespace std;
main () {
	int t;
	cin >> t;
	while (t--) {
		int n, sum=0;
		cin >> n;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		sort (a,a+n);
		for (int i=1; i<n; i++) {
			if (a[i]!=a[i-1]) sum+=a[i]-a[i-1]-1;
		}
		cout << sum << endl;
	}
}

// End of DSA06018_bosungphantu.cpp 

// Start of DSA06019_sapxeptheosolanxuathien.cpp 
#include <bits/stdc++.h> 
using namespace std;
map <int, int> m;
bool cmp (int a, int b) {
	if (m[a]!=m[b]) return m[a]>m[b];
	else return a<b;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
			m[a[i]]++;
		}
		sort (a, a+n, cmp);
		for (int x:a) cout << x << " ";
		cout << endl;
		m.clear();
	}
}

// End of DSA06019_sapxeptheosolanxuathien.cpp 

// Start of DSA06020_timkiem.cpp 
#include <bits/stdc++.h>
using namespace std;
void nhap ( int a[], int n) {
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
}
void xuli ( int a[], int n, int x ){
	int kt=0;
	for (int i=0; i<n; i++){
		if (a[i]==x) {
			kt=1;
			break;
		}
	}
	if (!kt) cout << "-1" ;
	else cout << "1" ;	
}
int a[1000000];
int main (){
	int t, n, x;
	cin >> t;
	while (t--){
		cin >> n >> x;
		nhap (a, n);
		xuli (a, n, x);
		cout << endl;
	}
}

// End of DSA06020_timkiem.cpp 

// Start of DSA06021_timkiemtrongdaysapxepvong.cpp 
#include <bits/stdc++.h>
using namespace std;
int binary_search (int a[], int n, int x) {
	int l=0,r=n-1;
	while (l<=r) {
		int mid = (l+r)/2;
		if (a[mid]==x) return mid+1;
		if (a[mid]<=a[r]) {
			if (x>a[mid]&& x<=a[r]) l=mid+1;
			else r=mid-1;
		} else {
			if (x>=a[l] && x<a[mid]) r=mid-1;
			else l=mid+1;
		}
	}
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		cout << binary_search(a, n, x) << endl;
	}
}

// End of DSA06021_timkiemtrongdaysapxepvong.cpp 

// Start of DSA06022_sonhonhatvanhothuhai.cpp 
#include <bits/stdc++.h>
using namespace std;
void nhap ( int a[], int n) {
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
}
void findSmallestNumbers (int a[], int n) {
	int smallest = INT_MAX, secondSmallest = INT_MAX;
	for (int i=0; i<n; i++) {
		if (a[i] < smallest) {
			secondSmallest = smallest;
			smallest = a[i];
		}
		else if (a[i] < secondSmallest && a[i] != smallest) {
			secondSmallest = a[i];
		}
	}
	if (secondSmallest == INT_MAX) cout << "-1" << endl;
	else cout << smallest << " " << secondSmallest << endl;
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n; 
		int a[n];
		nhap (a,n);
		findSmallestNumbers (a,n);
	}
}

// End of DSA06022_sonhonhatvanhothuhai.cpp 

// Start of fibonacciSearch.cpp 
#include <bits/stdc++.h>
using namespace std;
int fibonacciSearch(int arr[], int target, int n) {
    int fib2 = 0; int fib1 = 1;  int fib = fib1 + fib2;  
    while (fib < n) {
        fib2 = fib1;  fib1 = fib;
        fib = fib1 + fib2;
    }
    int offset = -1;
    while (fib > 1) {
        int i = min(offset + fib2, n - 1);
        if (arr[i] < target) {
            fib = fib1; fib1 = fib2;
            fib2 = fib - fib1; offset = i;
        }
 		else if (arr[i] > target) {
            fib = fib2; fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
//      else  return i;
		else return 1;
    }
    if (fib1 == 1 && arr[offset + 1] == target) {
//        return offset + 1;
		  return 1;
    }
    return -1;
}

int main () {
	int t,n,x;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		int a[n];
		for (int i=0; i<n; i++) cin >> a[i];
		cout << fibonacciSearch(a,x,n) << endl;
	}
}




// End of fibonacciSearch.cpp 

// Start of Fibo_soxuathiennhieunhat.cpp 
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findFrequency(vector<int>& arr, int num) {
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == num) {
            count++;
        }
    }
    return count;
}

int findMajorityElement(vector<int>& arr) {
    int n = arr.size();
    int fib_minus_2 = 0;
    int fib_minus_1 = 1;
    int fib = fib_minus_1 + fib_minus_2;

    while (fib < n) {
        fib_minus_2 = fib_minus_1;
        fib_minus_1 = fib;
        fib = fib_minus_1 + fib_minus_2;
    }

    int index = -1;

    while (fib > 1) {
        int i = min(index + fib_minus_2, n - 1);

        if (arr[i] == arr[index]) {
            fib = fib_minus_1;
            fib_minus_1 = fib_minus_2;
            fib_minus_2 = fib - fib_minus_1;
        }
        else if (arr[i] < arr[index]) {
            fib = fib_minus_2;
            fib_minus_1 = fib_minus_1 - fib_minus_2;
            fib_minus_2 = fib - fib_minus_1;
        }
        else {
            index = i;
            fib = fib_minus_1;
            fib_minus_1 = fib_minus_2;
            fib_minus_2 = fib - fib_minus_1;
        }
    }

    int count = findFrequency(arr, arr[index]);

    if (count > n / 2) {
        return arr[index];
    }
    else {
        return -1;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        int result = findMajorityElement(A);
        if (result != -1) {
            cout << result << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}


// End of Fibo_soxuathiennhieunhat.cpp 

// Start of giaocuabadayso.cpp 
#include <bits/stdc++.h>
using namespace std;
void nhap (long long a[], int n) {
	for (int i=0; i<n; i++) cin >> a[i];
}
main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m, p;
		cin >> n >> m >> p;
		long long a[n], b[m], c[p];
		nhap(a,n); nhap(b,m); nhap(c,p);
		vector <long long> v;
		int i=0, j=0, k=0;
		while (i<n && j<m && k<p) {
			if (a[i]==b[j] && b[j]==c[k]) {
				v.push_back(a[i]);
				i++; j++; k++;
			}
			else if (a[i] <= b[j] && a[i] <= c[k]) i++;
			else if (b[j]<=a[i] && b[j]<=c[k]) j++;
			else k++;
		}
		if (v.size()==0) cout << "-1";
		else for (long long x:v) cout << x << " ";
		cout << endl;
	}
}

// End of giaocuabadayso.cpp 

// Start of giatrinhonhatcuaxau.cpp 
#include <bits/stdc++.h>
using namespace std;
int k;
string s;
void solve () {
	int f[26];
	memset (f, 0, sizeof(f));
	for (int i=0; i<s.size(); i++) f[s[i]-'A'] ++;
	sort(f,f+26, greater<int>()); // sapxepgiamdan
	priority_queue <long long> p;
	long long res=0;
	for (int i=0; i<26; i++) p.push(f[i]);
	while (!p.empty()) {
		long long temp=p.top();
		if (k) {
			p.pop();
			p.push(temp-1);
			k--;
		}
		else {
			res+=temp*temp;
			p.pop();
		}
	}
	cout << res <<endl;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> k >> s;
		solve();
	}
}

// End of giatrinhonhatcuaxau.cpp 

// Start of hahaha.cpp 
#include <bits/stdc++.h> 
using namespace std;
int n, OK, B[25]={0};
int check (int n, int B[]) {
	for (int i=1; i<n; i++) {
		if (B[i]==1 && B[i]==B[i+1]) return 0;
	}
	if (B[1]==0 || B[n]==1) return 0;
	return 1;
}
void in() {
	if (check(n,B)) {
		for (int i=1; i<=n; i++) {
			if (B[i]) cout << "H";
			else cout << "A";
		}
		cout << endl;
	}
}
void sinh () {
	int i=n;
	while (B[i]) {
		B[i]=0;
		i--;
	}
	if (i==0) OK=1;
	else B[i]=1;
}
main () {
	int t; 
	cin >> t;
	while (t--) {
		OK=0;
		cin >> n;
		while (!OK) {
			in();
			sinh();
	}
	}
}

// End of hahaha.cpp 

// Start of hangdoi2dau.cpp 
#include <bits/stdc++.h>
using namespace std;
main(){
    int Q,x;
    cin >> Q;
    string s;
    deque<int> dq;
    while (Q--) {
        cin >> s;
        if (s == "PUSHFRONT") {
            cin >> x;
            dq.push_front(x);
        }
        else if (s == "PRINTFRONT") {
            if (!dq.empty())
                cout << dq.front() << endl;
            else
                cout << "NONE" << endl;
        }
        else if (s == "POPFRONT") {
            if (!dq.empty())
                dq.pop_front();
        }
        else if (s == "PUSHBACK") {
            cin >> x;
            dq.push_back(x);
        }
        else if (s == "PRINTBACK") {
            if (!dq.empty())
                cout << dq.back() << endl;
            else
                cout << "NONE" << endl;
        }
        else if (s == "POPBACK") {
            if (!dq.empty())
                dq.pop_back();
        }
    }
}

// End of hangdoi2dau.cpp 

// Start of hinhchunhatlonnhat.cpp 
#include <bits/stdc++.h>
using namespace std;
main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		stack <long long> st;
		long long res=0;
		int i=0;
		while (i<n) {
			if (st.empty() || a[i]>=a[st.top()]) {
				st.push (i);
				i++;
			} else {
				int idx=st.top();
				st.pop();
				if (st.empty()) {
					res=max(res, i*a[idx]);
				} else {
					res = max(res, a[idx]*(i-st.top()-1));
				}
			}	
		}
		while (!st.empty()) {
			int idx=st.top();
			st.pop();
			if (st.empty()) {
				res=max(res, i*a[idx]);
			} else {
				res = max(res, a[idx]*(i-st.top()-1));
			}
		}
		cout << res << endl;
	}
}

// End of hinhchunhatlonnhat.cpp 

// Start of hoanvidayso.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, a[10000], OK=0;
void in() {
	for (int i=1; i<=n; i++) cout << a[i] << " ";
	cout << endl;
}
void sinh () {
	int i=n-1;
	while (a[i]>a[i+1]) i--;
	if (i==0) OK=1;
	else {
		int j=n;
		while (a[i]> a[j]) j--;
		swap (a[i], a[j]);
		int d=i+1, c=n;
		while (d<c) {
			swap (a[d], a[c]);
			d++; c--;
		}
	}
}
main () {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort (a,a+n);
	while (!OK) {
		in();
		sinh();
	}
}

// End of hoanvidayso.cpp 

// Start of hoanviketiep.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, a[1000];
void sinh () {
	int i=n-1;
	while (a[i]>a[i+1]) i--;
	if (i==0) {
		for (int i=1; i<=n; i++) cout << i << " ";
	}
	else {
		int j=n;
		while (a[i]> a[j]) j--;
		swap (a[i], a[j]);
		int d=i+1, c=n;
		while (d<c) {
			swap (a[d], a[c]);
			d++; c--;
		}
		for (int i=1; i<=n; i++) cout << a[i] << " ";
	}
	cout << endl;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=1; i<=n; i++) {
			cin >> a[i];
		}
		sinh ();
	}
}

// End of hoanviketiep.cpp 

// Start of hoanvinguoc.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, a[1000], OK;
void in() {
	for (int i=1; i<=n; i++) cout << a[i];
	cout << " ";
}
void sinh () {
	int i=n-1;
	while (i>0 && a[i]<a[i+1]) i--;
	if (i==0) OK=1;
	else {
		int j=n; 
		while (a[j]>a[i]) j--;
		swap (a[i], a[j]);
		int d=i+1, c=n;
		while (d<c) {
			swap (a[d], a[c]);
			d++; c--;
		}
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		OK=0;
		for (int i=1; i<=n; i++) a[i]=n-i+1;
		while (!OK){
			in ();
			sinh();
		}
		cout <<endl;
	}
}

// End of hoanvinguoc.cpp 

// Start of hoanvitiepstheocuachuoiso.cpp 
#include <bits/stdc++.h> 
using namespace std;
int d;
string s;
void sinh () {
	int n=s.size()-1;
	int i=n-1;
	while (s[i]>=s[i+1]) i--; // so sau be hon so truoc
	if (i==-1) cout << "BIGGEST" << endl;
	else {
		int j=n;
		while (s[j]<=s[i]) j--;
		swap(s[i],s[j]);
		int l=i+1, r=n;
		while (l<r) {
			swap(s[l], s[r]);
			l++; r--;
		}
		cout << s << endl;
	}
}
main () {
	int t; 
	cin >> t;
	while (t--) {
		cin >> d >> s;
		cout << d << " ";
		sinh();
	}
}

// End of hoanvitiepstheocuachuoiso.cpp 

// Start of hoanvitieptheocuachuoiso.cpp 
#include <bits/stdc++.h> 
using namespace std;
string a;
void sinh() {
	int n=a.size()-1;
	int i=n-1;
	while (a[i]>=a[i+1]) i--;
	if (i==-1) {
		cout << "BIGGEST";
	}
	else {
		int j=n;
		while (a[j]<=a[i]) j--;
		swap(a[j],a[i]);
		int d=i+1, c=n;
		while (d<c) {
			swap(a[d],a[c]);
			d++; c--;
		}
		cout << a;
	}
}
main () {
	int t, i;
	cin >> t;
	while (t--) {
		cin >> i >> a;
		cout << i << " ";
		sinh();
		cout << endl;
	}
}

// End of hoanvitieptheocuachuoiso.cpp 

// Start of hoanvixaukitu.cpp 
#include <bits/stdc++.h>
using namespace std;
int check[15];
string s, x[15];
void out (int n) {
	for (int i=0; i<n; i++) {
		cout << x[i];
	}
	cout << " ";
}
void Try(int i, int n) {
	for (int j=0; j<n; j++) {
		if (!check[j]) {
			x[i]=s[j];
			check[j]=1;
			if (i==n-1) out(n);
			else Try(i+1,n);
			check[j]=0;
		}
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		Try(0, s.size());
		cout << endl;
	}
}

// End of hoanvixaukitu.cpp 

// Start of huhu.cpp 
#include <iostream>
using namespace std;

int insertionSortSwaps(int arr[], int n) {
    int count = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            count++;
            j--;
        }
        arr[j + 1] = key;
    }
    return count;
}

int main() {
    int T;
    cin >> T; // �?c s? lu?ng b? test T

    while (T--) {
        int n, X;
        cin >> n >> X; // �?c s? ph?n t? c?a m?ng n v� gi� tr? X (kh�ng s? d?ng trong thu?t to�n n�y)

        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; // �?c c�c ph?n t? c?a m?ng
        }

        int swaps = insertionSortSwaps(arr, n); // G?i h�m insertionSortSwaps d? t�nh s? ph�p d?i ch? �t nh?t
        cout << swaps << endl;
    }

    return 0;
}

// End of huhu.cpp 

// Start of interpolationSearch.cpp 
#include <bits/stdc++.h>
using namespace std;
int interpolationSearch(int arr[], int target, int low, int high) {
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target)
                return low;
            return -1;
        }
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high]-arr[low]);
        if (arr[pos] == target)
            return 1;
        if (arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}
int main () {
	int t,n,x;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		int a[n];
		for (int i=0; i<n; i++) cin >> a[i];
		cout << interpolationSearch(a,x,0,n-1) << endl;
	}
}


// End of interpolationSearch.cpp 

// Start of khoangcachnhohonk.cpp 
#include <iostream>
#include <algorithm>
using namespace std;

int merge(int arr[], int left, int mid, int right, int k) {
    int count = 0;
    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (j <= right && arr[j] - arr[i] < k) {
            count += (mid - i + 1);
            j++;
        }
    }
    return count;
}

int mergeSortAndCount(int arr[], int left, int right, int k) {
    int count = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        count += mergeSortAndCount(arr, left, mid, k);
        count += mergeSortAndCount(arr, mid + 1, right, k);
        count += merge(arr, left, mid, right, k);

        inplace_merge(arr + left, arr + mid + 1, arr + right + 1);
    }
    return count;
}

int countPairsWithDifferenceLessThanK(int arr[], int n, int k) {
    sort(arr, arr + n);
    return mergeSortAndCount(arr, 0, n - 1, k);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int result = countPairsWithDifferenceLessThanK(arr, n, k);
        cout << result << endl;
    }

    return 0;
}

// End of khoangcachnhohonk.cpp 

// Start of khoangcachxanhat.cpp 
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		pair<int, int> a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
			a[i].second = i;
		}
		sort(a, a + n);
		int ans = -1, Min = a[0].second, k = a[0].first;
		for (int i = 1; i < n; i++) {
			if (a[i].first > k)
				ans = max(ans, a[i].second - Min);
			if (Min > a[i].second) {
				Min = a[i].second;
				k = a[i].first;
			}
		}
		cout << ans << endl;
	}
}
//first		34 8 10 3 2 80 30 33 1
//second	0  1 2  3 4 5  6  7  8 
//		f s	
//	0	1 8
//	1	2 4
//	2	3 3
//	3	8 1
//	4	10 2
//	5	30 6
//	6	33 7
//	7	34 0
//	8	80 5

//		ans=-1; Min=8; k=1
//		i=1: (2>k=1) ans= max(-1,4-8)=-1 (8>4) min=4, k=2
//		i=2: (3>k=2) ans= max(-1,3-4)=-1 (4>3) min=3, k=3

// End of khoangcachxanhat.cpp 

// Start of khoangcachxanhat_chatgpt.cpp 
#include <bits/stdc++.h>
using namespace std;
int findMaxDifference(vector<int>& A, int N) {
    int maxDiff = INT_MIN;
    int startIndex = 0;
    int endIndex = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[j] > A[i] && (j - i) > maxDiff) {
                maxDiff = j - i;
                startIndex = i;
                endIndex = j;
            }
        }
    }
	if (maxDiff==INT_MIN) return -1;
    return maxDiff;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        int result = findMaxDifference(A, N);
        cout << result << endl;
    }
    return 0;
}

// End of khoangcachxanhat_chatgpt.cpp 

// Start of kiemtrabieuthucsohoc.cpp 
#include <bits/stdc++.h>
using namespace std;
void solve() {
		string str;
		cin.ignore();
		getline(cin, str);
		stack <char> s;
		bool check;
		for (int i=0; i<str.length(); i++) {
			if (str[i]!=')') s.push(str[i]);
			else {
				check=0;
				while (s.size()!=0) {
					char c=s.top();
					s.pop();
					if (c=='(') break;
					if (c=='+' || c=='-' || c=='*' || c=='/') check=1;
				}
				if (check==0) {
					cout << "Yes" << endl;
					return;
				}
			}
		}
		cout <<"No" << endl;
}
main () {
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		solve();
	}
}

// End of kiemtrabieuthucsohoc.cpp 

// Start of kiemtradayngoacdung.cpp 
#include <bits/stdc++.h>
using namespace std;
string s;
int solve() {
    stack <char> st;
	for (char x: s) {
		if (x=='(' || x=='{'|| x=='[') st.push(x);
		else {
			if (x==')') {
				if (!st.empty() && st.top()=='(') {
					st.pop();
				}
				else {
					return 0;
				}
			}
			else if (x==']') {
				if (!st.empty() && st.top()=='[') {
					st.pop();
				}
				else {
					return 0;
				}
			} else {
				if (!st.empty() && st.top()=='{') {
					st.pop();
				}
				else {
					return 0;
				}
			}			
		}
	}
	if (!st.empty()) return 0;
	return 1;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		if (solve()) cout << "YES"; else cout << "NO";
		cout << endl;
	}
}

// End of kiemtradayngoacdung.cpp 

// Start of lietketohop.cpp 
#include <bits/stdc++.h>
using namespace std;
int OK=0, C[35], a[1000], n, k;
set <int> s;
void in () {
	for (int i=1; i<=k; i++) cout << a[C[i]] << " ";
	cout << endl;
}
void sinh (int m) {
	int i, j;
	i=k;
	while (C[i]==m-k+i) i--;
	if (i == 0) OK=1;
	else {
		C[i]++;
		for ( j=i+1; j<=k; j++) C[j]=C[j-1]+1;
	}
}
main () {
	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	for (int i=1; i<=k; i++) {
		C[i]=i;
	}
	int j=0;
	for (int x:s) {
		j++;
		a[j]= x;
	}
	while (!OK) {
		in();
		sinh(j);
	}
}

// End of lietketohop.cpp 

// Start of lietkexaukitu.cpp 
#include <bits/stdc++.h>
using namespace std;
char c;
int k, n, A[30];
void in () {
	for (int i=1; i<=k; i++) cout << (char) (A[i]+ 64);
	cout << endl;
}
void Try(int i, int x) {
	for (int j=x; j<=n; j++) {
		A[i]=j;
		if (i==k) in();
		else Try(i+1, j);
	}
}
main () {
	cin >> c >> k;
	n = (int)c -'A'+1;
	Try(1,1);
}

// End of lietkexaukitu.cpp 

// Start of lietkexaunhiphan.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, OK=0, B[25]={0};
void in () {
	for (int i=1; i<=n; i++) cout << B[i] << " ";
	cout << endl;
}
void Try(int i) {
	for (int j=0; j<=1; j++) {
		B[i]=j;
		if (i==n) {
			in();
		}
		else {
			Try(i+1);
		}
	}
}
main () {
	cin >> n;
	Try(1);
}

// End of lietkexaunhiphan.cpp 

// Start of loctrung.cpp 
#include <iostream>
#include <unordered_set>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};


void insert(Node*& first, int value) {
    Node* newNode = new Node(value);
    if (!first) {
        first = newNode;
    } else {
        Node* temp = first;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void filterDuplicates(Node*& first) {
    unordered_set<int> uniqueValues;
    Node* current = first;
    Node* prev = nullptr;

    while (current) {
        if (uniqueValues.find(current->data) == uniqueValues.end()) {
            uniqueValues.insert(current->data);
            prev = current;
            current = current->next;
        } else {
            Node* temp = current;
            current = current->next;
            prev->next = current;
            delete temp;
        }
    }
}

void printLinkedList(Node* first) {
    Node* current = first;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << std::endl;
}

int main() {
    Node* first = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        insert(first, value);
    }

    filterDuplicates(first);
    printLinkedList(first);

    Node* temp;
    while (first) {
        temp = first;
        first = first->next;
        delete temp;
    }

    return 0;
}


// End of loctrung.cpp 

// Start of luachontoiuu.cpp 
#include <bits/stdc++.h> 
using namespace std;
struct task {
	int start, finish;
} a[100005];
bool cmp (task x, task y ){
	return x.finish < y.finish;
}
main () {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> a[i].start;
			cin >> a[i].finish;
		}
		sort (a, a+n, cmp);
		int i=0, d=1;
		for (int j=1; j<n; j++) {
			if (a[j].start >= a[i].finish) {
				i=j; d++;
			}
		}
		cout << d << endl;
	}
}

// End of luachontoiuu.cpp 

// Start of magray2.cpp 
#include <bits/stdc++.h> 
using namespace std;
main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		string b=" ";
		b=s[0];
		for (int i=1; i<s.size(); i++) {
			if (b[i-1]!=s[i]) b+="1";
			else b+="0";
		}
		cout << b << endl;
	}
}

// End of magray2.cpp 

// Start of magray3.cpp 
#include <bits/stdc++.h> 
using namespace std;
main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		string b=" ";
		b=s[0];
		for (int i=1; i<s.size(); i++) {
			if (s[i-1]!=s[i]) b+="1";
			else b+="0";
		}
		cout << b << endl;
	}
}

// End of magray3.cpp 

// Start of mayATM.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, k, OK=0, MIN=1000;
void in (int a[], int B[]) {
	int i,tong=0;
	for (i=1; i<=n; i++) {
		tong+=a[i]*B[i];
	}
	if (tong == k) {
		int d=0;
		for (i=1; i<=n; i++) if (B[i]==1) d++;
		MIN=min(d,MIN);
	}
}
void sinh (int a[], int B[]) {
	int i=n;
	while (B[i]) {
		B[i]=0; i--;
	}
	if (i==0) OK=1;
	else B[i]=1;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		int a[n], B[n];
		for (int i=1; i<=n; i++) cin >> a[i];
		while (!OK) {
			in(a,B);
			sinh (a,B);
		}
		cout << MIN << endl;		
	}
}

// End of mayATM.cpp 

// Start of nganxep1.cpp 
#include <bits/stdc++.h>
using namespace std;
stack <int> s;
string st;
int n;
void show() {
	stack <int> p=s;
	vector <int> a;
	while (!p.empty()) {
		a.push_back(p.top());
		p.pop();
	}
	for (int i=a.size()-1; i>=0; i--) cout << a[i] << " ";
	cout <<endl;
}
main () {
	while (1) {
		cin >> st;
		if (st=="push") {
			cin >> n; 
			s.push(n);
		}
		else if (st=="pop") s.pop();
		else if (st=="show") show();
		if (s.size()==0) {
			cout << "empty";
			break;
		}
	}
}

// End of nganxep1.cpp 

// Start of nganxep2.cpp 
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, n;
    string s;
    cin >> t;
    stack <int> st;
    while (t--){
        cin >> s;
        if (s == "PUSH"){
            cin >> n;
            st.push(n);
        }
        else if (s == "POP"){
            if (!st.empty())
                st.pop();
        }
        else if (s == "PRINT"){
            if (!st.empty())
                cout << st.top() << endl;
            else
                cout << "NONE" << endl;
        }
    }
}

// End of nganxep2.cpp 

// Start of nguoidulichj.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, C[20][20], B[20], A[20],cmin=1e9, fopt=1e9, cost;
void Try(int i) {
	for (int j=2; j<=n; j++) {
		if (!B[j]) {
			B[j]=1;
			A[i]=j;
			cost+= C[A[i-1]][A[i]];
			if (i==n) {
				int v=cost+C[A[n]][A[1]];
				fopt=min(v,fopt);
			}
			else if (cost+cmin*(n-i+1) < fopt) Try(i+1);
			B[j]=0;
			cost-=C[A[i-1]][A[i]];
		}
		
	}
}
main () {
	cin >> n;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cin >> C[i][j];
			if (i!=j) cmin=min(cmin, C[i][j]);
		}
	}
	A[1]=1;
	Try(2);
	cout << fopt;
}

// End of nguoidulichj.cpp 

// Start of Noisuy_soxuathiennhieunhat.cpp 
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

// End of Noisuy_soxuathiennhieunhat.cpp 

// Start of phantichso1.cpp 
#include <bits/stdc++.h> 
using namespace std;
int n, a[11];
void in (int m) {
	cout << "(";
	for (int i=1; i<m; i++) cout << a[i] << " ";
	cout << a[m] << ") ";
}
void Try(int i, int k, int sum) {
	for (int j=k; j>=1; j--) { //for ( j =<kha nang 1>; j <=n; j++ ){
		if (sum+j<=n) {       // if (<chap nhan kha nang j>) 
			a[i]=j;			// X[i] = <kha nang j>;
			if (sum+j==n) in(i);  // if ( i ==n) Result();
			else Try(i+1, j, sum+j); // else Back-Track(i+1);
		}
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		Try(1,n,0);
		cout << endl;
	}
}



// End of phantichso1.cpp 

// Start of phantichso2.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, a[11];
vector <vector<int>> res;
void solve(int n) {
	vector <int> temp;
	for (int i=1; i<=n; i++) temp.push_back(a[i]);
	res.push_back(temp);
}
void Try(int i, int sum, int k) {
	for (int j=k; j>0; j--) {
		if (sum+j<=n) {
			a[i]=j;
			if (sum+j==n) solve(i);
			else Try(i+1, sum+j, j);
		}
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		res.clear();
		cin >> n;
		Try(1,0,n);
		cout << res.size() << endl;
		for (int i=0; i<res.size(); i++) {
			cout <<"(";
			for (int j=0; j<res[i].size()-1; j++) {
				cout << res[i][j]<< " ";
			}
			cout << res[i][res[i].size()-1] << ") ";
		}
		cout << endl;
	}
}

// End of phantichso2.cpp 

// Start of phantulonnhatphantunhonhat.cpp 
#include <bits/stdc++.h>
using namespace std;
main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		multiset <int> ms;
		for (int i=0; i<n; i++) cin >> a[i];
		for (int i=0; i<k; i++) ms.insert(a[i]);
		for (int i=k; i<n; i++) {
			cout << *ms.rbegin() << " ";
			ms.erase(ms.find(a[i-k]));
			ms.insert(a[i]);
		}
		cout << *ms.rbegin() << endl;
	}
}

// End of phantulonnhatphantunhonhat.cpp 

// Start of phantulonnhat_QS.cpp 
#include <bits/stdc++.h>
using namespace std;
void quickSort(int a[], int l, int r){
	int p = a[(l+r)/2];
	int i = l, j = r;
	while (i < j){
		while (a[i] < p){
			i++;
		}
		while (a[j] > p){
			j--;
		}
		if (i <= j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (i < r){
		quickSort(a, i, r);
	}
	if (l < j){
		quickSort(a, l, j);
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		int n,k; 
		cin >> n >> k;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		quickSort(a,0,n-1);
		for (int i=n-1;i>n-k-1; i--) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}

// End of phantulonnhat_QS.cpp 

// Start of phatloc.cpp 
#include <bits/stdc++.h> 
using namespace std;
int n, B[15]={0}, KT=0;
int check () {
	if (B[1]==0 || B[n] == 1) return 0;
	for (int i=1; i<n-1; i++) {
		if (B[i]==1 && B[i+1]==1) return 0;
		int j=i, d=0;
		while (B[j]==0 && j<=n) {
			d++;
			j++;
			if (d>3) return 0;
		}
	}
	return 1;
}
void in() {
	if (check()) {
		for (int i=1; i<=n; i++) {
			if (B[i]==1) cout << "8";
			else cout << "6";
		}
		cout << endl;
	}
}
void sinh() {
	int i=n;
	while (B[i]) {
		B[i]=0;
		i--;
	}
	if (i==0) KT=1;
	else B[i]=1;
}
main () { 
	cin >> n;
	while (!KT) {
		in();
		sinh ();
	}
}

// End of phatloc.cpp 

// Start of sapxepchanle.cpp 
#include <bits/stdc++.h> 
using namespace std;
int n;
vector <int> v, u;
void solve( int a[]) {
	for (int i=0; i<n; i++) {
		if (i%2==0) v.push_back(a[i]);
		else u.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	sort(u.begin(), u.end());
	int j=-1, k=-1;
	for (int i=0; i<n; i++) {
		if (i%2==0) {
			j++;
			cout << v[j] << " ";
		}
		else {
			k++;
			cout << u[u.size()-k-1] << " ";
		}
	}
}
main () {
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) cin >> a[i];
	solve(a);
}

// End of sapxepchanle.cpp 

// Start of sapxepchen.cpp 
#include<bits/stdc++.h>
using namespace std;
void nhapmang(int a[], int n){
    for(int i=0;i<n;i++) cin >> a[i];
}
void in(int a[], int n){
    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;
}
void sapxep(int a[], int n){
    int i,j,t;
    for(i=0; i<n; i++){
        t=a[i]; j=i-1;
        while(a[j]>t && j>=0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = t;
        cout << "Buoc " << i << ": "; in(a,i+1);
    }
}
main(){
    int a[100],n;
    cin >> n;
    nhapmang(a,n);
    sapxep(a,n);
}

// End of sapxepchen.cpp 

// Start of sapxepchon.cpp 
#include<bits/stdc++.h>
using namespace std;
void nhap(int a[],int n){
    for(int i=0;i<n;i++) cin >> a[i];
}
void in(int a[],int n){
    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << endl;
}
void sapxep(int a[],int n){
    int i,j,m,t;
    for(i=0;i<n-1;i++){
        m=i;
        for(j=i+1;j<n;j++)
            if(a[j]<a[m]) m = j;

        t=a[m]; a[m]=a[i]; a[i]=t;

        cout << "Buoc " << i+1 << ": "; 
		in(a,n);
    }
}
main(){
    int a[100],n;
    cin >> n;
    nhap(a,n);
    sapxep(a,n);
}

// End of sapxepchon.cpp 

// Start of sapxepchuso_sapxepchen.cpp 
#include <bits/stdc++.h> 
using namespace std;
void sapxep(int a[], int n){
    int i,j,t;
    for(i=0; i<n; i++){
        t=a[i]; j=i-1;
        while(a[j]>t && j>=0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = t;
    }
}
main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n; 
		string x;
		int b[10]={}, a[10], k=0;
		for (int i=0; i<n; i++) {
			cin >> x;
			for (int j=0; j<x.size(); j++) {
				if (b[x[j] -'0']==0) a[k++] = x[j]-'0';
				b[x[j]-'0']++;
			}
		}
		sapxep(a, k);
		for (int i=0; i<k ;i++) cout << a[i] << " ";
		cout << endl;
	}
}

// End of sapxepchuso_sapxepchen.cpp 

// Start of sapxepchuso_sapxepchon.cpp 
#include <bits/stdc++.h> 
using namespace std;
void sapxep(int a[],int n){
    int i,j,m,t;
    for(i=0;i<n-1;i++){
        m=i;
        for(j=i+1;j<n;j++)
            if(a[j]<a[m]) m = j;
        swap(a[i],a[m]);  
    }
}
main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n; 
		string x;
		int b[10]={}, a[10], k=0;
		for (int i=0; i<n; i++) {
			cin >> x;
			for (int j=0; j<x.size(); j++) {
				if (b[x[j] -'0']==0) a[k++] = x[j]-'0';
				b[x[j]-'0']++;
			}
		}
		sapxep(a, k);
		for (int i=0; i<k ;i++) cout << a[i] << " ";
		cout << endl;
	}
}

// End of sapxepchuso_sapxepchon.cpp 

// Start of sapxepcongviec1.cpp 
#include <bits/stdc++.h>
using namespace std;
struct task {
	int start, finish;
} a[1005];
bool cmp ( task x, task y) {
	return x.finish < y.finish;
}
main () {
	int n, t, i, j, d;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i=0; i<n; i++) cin >> a[i].start;
		for (i=0; i<n; i++) cin >> a[i].finish;
		sort (a, a+n, cmp);
		i=0; d=1;
		for (j=1; j<n; j++) {
			if (a[j].start>=a[i].finish) {
				i=j; d++;
			}
		}
		cout << d << endl;
	}
}

// End of sapxepcongviec1.cpp 

// Start of sapxepcongviec2.cpp 
#include <bits/stdc++.h>
using namespace std;
int main()
{
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
                    cout << a[i].first;
                    d++;
                    check[j] = 1;
                    break;
                }
            }
        }
//        cout << d << " " << ans << endl;
    }
}

// End of sapxepcongviec2.cpp 

// Start of sapxepcongviec2_.cpp 
#include <bits/stdc++.h>
using namespace std;
struct task {
	int start, finish;
} a[1005];
bool cmp ( task x, task y) {
	return x.finish > y.finish;
}
main () {
	int n, t, x;
	cin >> t;
	while (t--) {
		cin >> n;
		int check[1005]={0};
		for (int i=0; i<n; i++) {
			cin >> x >> a[i].start >> a[i].finish;
		}
		sort (a, a+n, cmp);
		int s=0, d=0;
		for (int i=0; i<n; i++) {
			for (int j=min(n, a[i].start); j>=1; j--) {
				if (!check[j]) {
					s+=a[i].finish;
					d++;
					check[j]=1;
					break;
				}
			}

		}
		cout << d << " " << s << endl;
	}
}

// End of sapxepcongviec2_.cpp 

// Start of Sapxepdoichotructiep.cpp 
#include<bits/stdc++.h>
using namespace std;
void nhap(int a[],int n){
    for(int i=0;i<n;i++) cin >> a[i];
}
void in(int a[],int n){
    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << endl;
}
void sapxep(int a[],int n){
	for (int i=0;i<n-1;i++){
	    for (int j=i+1;j<n;j++){
		    if (a[i]>a[j]){
			    int tg=a[i];
			    a[i]=a[j];
			    a[j]=tg;
		    }
	    }
	    cout << "Buoc " << i+1 << ": ";
	    in(a,n);
    }
}
main (){
	int n,a[100];
	cin >> n;
	nhap(a,n);
	sapxep(a,n);
}

// End of Sapxepdoichotructiep.cpp 

// Start of sapxepnoibot.cpp 
#include<bits/stdc++.h>
using namespace std;
void nhap(int a[], int n){
    for(int i=0; i<n; i++) cin >> a[i];
} 
void in(int a[], int n){
    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;
}
void sapxep(int a[], int n){
    int i, j, t, kt;
    for(i=0; i<n-1; i++){
        kt=0;
        for(j=0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                t=a[j]; a[j]=a[j+1]; a[j+1]=t;
                kt=1;
            }
        }
        if(kt==0) break;
        cout << "Buoc " << i+1 << ": "; in(a,n);
    }
}
main(){
    int a[100], n;
    cin >> n;
    nhap(a,n);
    sapxep(a,n);
}

// End of sapxepnoibot.cpp 

// Start of sapxepquahau1.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, cot[100], d1[100], d2[100], a[100], dem;
void Try (int i) {
	for (int j=1; j<=n; j++) {  //for ( j =<kha nang 1>; j <=n; j++ ){
		if (cot[j] && d1[i-j+n] && d2[i+j-1]) {  // if (<chap nhan kha nang j>) 
			a[i]=j; // X[i] = <kha nang j>;
			cot[j] = d1[i-j+n] = d2[i+j-1] = 0;  // mang danh dau
			if (i==n) dem ++; // if ( i ==n) Result();
			else Try(i+1);   // else Back-Track(i+1);
			cot[j] = d1[i-j+n] = d2[i+j-1] = 1; // tra ve mang danh dau gia tri ban dau
		}
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		dem=0;
		for (int i=1; i<=100; i++) cot[i]=d1[i]=d2[i]=1;
		Try(1);
		cout << dem << endl;
	}
}



// End of sapxepquahau1.cpp 

// Start of sapxepquanhau2.cpp 
#include <bits/stdc++.h>
using namespace std;
int MAX, dem, a[100], A[100][100], d1[100], cot[100], d2[100];
void solve () {
	dem=0;
	for (int i=1; i<=8; i++) dem+=A[i][a[i]];
	MAX=max(dem, MAX);
}
void Try(int i){
	for (int j=1; j<=8; j++) {
		if (cot[j] && d1[j] && d2[j]) {
			a[i]=j;
			cot[j]=d1[i-j+8]=d2[i+j-1]=0;
			if (i==8) solve();
			else Try(i+1);
			cot[j]=d1[i-j+8]=d2[i+j-1]=1;
		}	
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		MAX=0;
		for (int i=1; i<=8; i++)
			for (int j=1; j<=8; j++)
				cin >> A[i][j];
		for (int i=1; i<=100; i++) cot[i]=d1[i]=d2[i]=1;
		Try(1);
		cout << MAX << endl;
	}
}

// End of sapxepquanhau2.cpp 

// Start of sinhhoanvi.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, A[11], check[11];
void in() {
	for (int i=1; i<=n; i++) cout << A[i];
	cout << " ";
}
void Try(int i) {
	for (int j=1; j<=n; j++) {
		if (!check[j]) {
			A[i]=j;
			check[j]=1;
			if (i==n) in();
			else Try(i+1);
			check[j]=0;
		}
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		check[11]={0};
		cin >> n;
		Try(1);
		cout << endl;
	}
}

// End of sinhhoanvi.cpp 

// Start of sinhtohop.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, k, x[11];
void in() {
	for (int i=1; i<=k; i++) cout << x[i];
	cout << " ";
}
void Try(int i) {
	for (int j= x[i-1]+1; j<=n-k+i; j++) {
		x[i]=j;
		if (i==k) in();
		else Try(i+1);
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		x[0]=0;
		cin >> n >> k;
		Try(1);
		cout << endl;
	}
}

// End of sinhtohop.cpp 

// Start of so0vaso9.cpp 
#include <bits/stdc++.h>
using namespace std;
long long n;
void solve1() {	
	queue <long long> q;
	q.push(9);
	while (1) {
		if (q.front()%n==0) {
			cout << q.front();
			break;
		} else {
			q.push(q.front()*10);
			q.push(q.front()*10+9);	
			q.pop();
		}
	}	
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		solve1();
		cout << endl;
	}
}

// End of so0vaso9.cpp 

// Start of soBDN1.cpp 
#include <bits/stdc++.h>
using namespace std;
long long n;
void solve1() {	
	queue <long long> q;
	q.push(1);
	int res=0;
	while (1) {
		long long top=q.front();
		if (top<=n) res++;
		else break;
		q.pop();
		q.push(top*10);
		q.push(top*10+1);
	}	
	cout << res << endl;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		solve1();
	}
}

// End of soBDN1.cpp 

// Start of soBDN2.cpp 
#include <bits/stdc++.h>
using namespace std;
int n;
void solve1() {	
	queue <long long> q;
	q.push(1);
	while (1) {
		long long top=q.front();
		if (top%n==0) {
			cout << top << endl;
			break;
		}
		q.pop();
		q.push(top*10);
		q.push(top*10+1);
	}	
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		solve1();
	}
}

// End of soBDN2.cpp 

// Start of sodautienbilaplai.cpp 
#include <bits/stdc++.h>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, kt=0;
		cin >> n;
		int a[n];
		unordered_map <int, int> p;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			p[a[i]]++;
		}
		for (int i=0; i<n; i++) {
			if (p[a[i]]>1) {
				cout << a[i] << " ";
				kt=1;
				break;
			}
		}
		if (!kt) cout << "NO";
		cout << endl;
	}
}

// End of sodautienbilaplai.cpp 

// Start of solanquayvong.cpp 
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n], count=0;
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		for (int i=1; i<n; i++) {
			if (a[i]<a[i-1]) {
				count=i;
				break;
			}
		}
		cout << count << endl;
	}
}

// End of solanquayvong.cpp 

// Start of solocphat1.cpp 
#include <bits/stdc++.h>
using namespace std;
int n;
void solve1() {	
	vector <string> v;
	queue <string> q;
	q.push("6");
	q.push("8");
	while (1) {
		string top=q.front();
		v.push_back(top);
		q.pop();
		if (top.size() <n) {
			q.push(top+"6");
			q.push(top+"8");
		}
		else break;
	}	
	while (q.size()) {
		v.push_back(q.front());
		q.pop();
	}
	for (int i=v.size()-1; i>=0; i--) cout << v[i] << " ";
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		solve1();
		cout << endl;
	}
}

// End of solocphat1.cpp 

// Start of solocphat2.cpp 
#include <bits/stdc++.h>
using namespace std;
int n;
void solve1() {	
	vector <string> v;
	queue <string> q;
	q.push("6");
	q.push("8");
	while (1) {
		string top=q.front();
		v.push_back(top);
		q.pop();
		if (top.size() <n) {
			q.push(top+"6");
			q.push(top+"8");
		}
		else break;
	}	
	while (q.size()) {
		v.push_back(q.front());
		q.pop();
	}
	cout << v.size() << endl;
	for (int i=0; i< v.size(); i++) cout << v[i] << " ";
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		solve1();
		cout << endl;
	}
}

// End of solocphat2.cpp 

// Start of solocphat3.cpp 
#include <bits/stdc++.h>
using namespace std;
int n;
void solve1() {	
	vector <string> v;
	queue <string> q;
	q.push("6");
	q.push("8");
	while (1) {
		string top=q.front();
		v.push_back(top);
		q.pop();
		if (top.size() <n) {
			q.push(top+"6");
			q.push(top+"8");
		}
		else break;
	}	
	while (q.size()) {
		v.push_back(q.front());
		q.pop();
	}
	cout << v.size() << endl;
	for (int i=v.size()-1; i>=0; i--) cout << v[i] << " ";
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		solve1();
		cout << endl;
	}
}

// End of solocphat3.cpp 

// Start of sonhiphantu1denN.cpp 
#include <bits/stdc++.h>
using namespace std;
int n;
//vector <string> v;
//void solve() {
//	
//	queue <string> q;
//	q.push("1");
//	v.push_back("1");
//	while (v.size()<10000) {
//		string top=q.front();
//		v.push_back(top+"0");
//		v.push_back(top+"1");
//		q.pop();
//		q.push(top+"0");
//		q.push(top+"1");
//	}
//	for (int i=0; i<n; i++) cout << v[i] << " ";
//	
//}
void solve1() {	
	queue <string> q;
	q.push("1");
	for (int i=1; i<=n; i++) {
		string top=q.front();
		cout << top << " ";
		q.pop();
		q.push(top+"0");
		q.push(top+"1");
	}	
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		solve1();
		cout << endl;
	}
}

// End of sonhiphantu1denN.cpp 

// Start of sonhonhatcoNuocso.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, p[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
long long res;
void Try(int i, long long ali, long long temp) {
	if (ali>n) return;
	if (ali==n) res=min(temp,res);
	for (int j=1;; j++) {
		if (temp*p[i]>res) break;
		temp*=p[i];
		Try (i+1, ali*(j+1), temp);
	}
}
main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		res=1e18;
		Try(0,1,1);
		cout << res << endl;
	}
}

// End of sonhonhatcoNuocso.cpp 

// Start of sosanhbieuthuc.cpp 
#include <bits/stdc++.h>
using namespace std;
string s1,s2;
string solve (string s) {
	stack <char> st;
	for (int i=0; i<s.size(); i++) {
		if (s[i]=='(') {
			if (s[i-1]=='+' || s[i-1]=='-') st.push(s[i-1]);
		}
		if (!st.empty() && st.top()=='-') {
			if (s[i]=='+') s[i]='-';
			else if (s[i]=='-') s[i]='+';
		}
		if (s[i]==')' && !st.empty()) st.pop();
	}
	string res="";
	for (int i=0; i<s.size(); i++) {
		if (s[i]!='(' && s[i]!=')') res+= s[i];
	}
	return res;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> s1 >> s2;
		if (solve(s1)==solve(s2)) cout <<"YES";
		else cout <<  "NO";
		cout << endl;
	}
}

// End of sosanhbieuthuc.cpp 

// Start of sothutuhoanvi.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, a[15], dem, C[15], OK;
int check () {
	for (int i=1; i<=n; i++) {
		if (a[i]!=C[i]) return 0;
	}
	return 1;
}
void sinh () {
	int i=n-1;
	while (C[i]>C[i+1]) i--;
	if (i==0) OK=1;
	else {
		int j=n;
		while (C[i]> C[j]) j--;
		swap (C[i], C[j]);
		int d=i+1, c=n;
		while (d<c) {
			swap (C[d], C[c]);
			d++; c--;
		}
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		OK=0, dem=0;
		for (int i=1; i<=n; i++) {
			cin >> a[i];
			C[i]=i;
		}
		while (!OK) {
		    dem ++;
			if (check()) {
				cout << dem << endl;
				break;
			}
			sinh ();
		}
	}
}

// End of sothutuhoanvi.cpp 

// Start of sothututohop.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, OK, dem, k, C[35], A[35];
void sinh () {
	int i, j;
	i=k;
	while (C[i]==n-k+i) i--;
	if (i == 0 ) OK=1;
	else {
		C[i]++;
		for (j=i+1; j<=k; j++) C[j]=C[j-1]+1;
	}
}
int kiemtra () {
	for (int i=1; i<=k; i++) {
		if (A[i]!=C[i]) return 0;
	}
	return 1;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k; OK=0, dem=0;
		for (int i=1; i<=k; i++) {
			cin >> A[i];
			C[i]=i;
		}
		while (!OK) {
			dem++;
			if (kiemtra()) {
				cout << dem << endl;
				break;
			}
			sinh ();
		}		
	}
}

// End of sothututohop.cpp 

// Start of soxacach.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, a[11], check[11];
void in() {
	for (int i=1; i<n; i++) {
		if (abs(a[i]-a[i+1])==1) return;
	}
	for (int i=1; i<=n; i++ ) {
		cout << a[i];
	}
	cout << endl;
}
//void Try (int i) {
//	if (i>n) in();
//	else {
//		for (int j=1; j<=n; j++) {
//			if (!check[j]) {
//				a[i]=j;
//				check[j]=1;
//				Try(i+1);
//				check[j]=0;
//			}
//		}
//	}
//}
void Try (int i) {
	for (int j=1; j<=n; j++) {
		if (!check[j]) {
			a[i]=j;
			check[j]=1;
			if (i==n) in();
			else Try(i+1);
			check[j]=0;
		}
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		Try(1);
		cout <<" ";
	}
}

// End of soxacach.cpp 

// Start of soxuathiennhieunhat.cpp 
#include <bits/stdc++.h>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, count=-1e9, MAX;
		cin >> n;
		int a[n];
		unordered_map <int, int> p;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			p[a[i]]++;
		}
		for (int i=0; i<n; i++) {
			if (p[a[i]]>n/2 && p[a[i]]> count) {
				count=max(count, p[a[i]]);
				MAX=a[i];
			}
		}
		if (count!=-1e9) cout << MAX; 
		else cout << "NO";
		cout << endl;
	}
}

// End of soxuathiennhieunhat.cpp 

// Start of tapconbangnhau.cpp 
#include <bits/stdc++.h>
using namespace std;
int sum, n, a[105];
string OK;
void Try(int i, int cursum) {
	if (OK=="YES") return;
	if (2*cursum==sum) {
		OK="YES";
		return;
	}
	if (i<n) {
		if (2*(cursum + a[i])<= sum) Try(i+1, cursum+a[i]);
		Try(i+1, cursum);
	}
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		OK="NO";
		sum=0;
		for (int i=1; i<=n; i++ ) {
			cin >> a[i];
			sum+=a[i];
		}
		if (sum % 2 == 0) Try(0,0);
		cout << OK << endl;	
	}
}

// End of tapconbangnhau.cpp 

// Start of tapconketiep.cpp 
#include <bits/stdc++.h> 
using namespace std;
int n, k, C[1000];
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i=1; i<=k; i++) cin >> C[i];	
		int i=k;
		while (C[i]==n-k+i) i--; 
		if (i==0) {
			for (int j=1; j<=k; j++) C[j]=C[j-1]+1;
		}
		else {
			C[i]++;
			for (int j=i+1; j<=k; j++) C[j]=C[j-1]+1;
		}
		for (int i=1; i<=k; i++) cout << C[i] << " ";
		cout << endl;
	}
}

// End of tapconketiep.cpp 

// Start of tapconlienkephiatruoc.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, k, C[1000];
void sinh () {
	int i=k;
	while (C[i]-C[i-1]==1 && i>=0) i--;
	if (i==0) {
		for (int j=1; j<=k; j++ ) C[j]=n-k+j;
		for (int j=1; j<=k; j++) cout << C[j] << " ";
	}
	else {
		C[i]--;
		for (int j=i+1; j<=k; j++) C[j]=n-k+j;
		for (int j=1; j<=k; j++) cout << C[j] << " ";
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i=1; i<=k; i++) cin >> C[i];
		sinh();
		cout << endl;
	}
}

// End of tapconlienkephiatruoc.cpp 

// Start of taphop.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, k, s, res, a[21], check[21];
void Try(int i, int sum) {
	for (int j=a[i-1]+1; j<=n-k+i; j++) {
		if (!check[j]) {
			check[j]=1;
			a[i]=j;
			sum+=a[i];
			if (i==k) {
				if (sum==s) res++;
			}
			else Try(i+1, sum);
			check[j]=0;
			sum-=a[i];
		}
	}
}
main () {
	while (1) {
		res=0;
		cin >> n >> k >> s;
		if (n==0 && k==0 && s==0) return 0;
		else Try(1,0);
		cout << res << endl;
	}
}

// End of taphop.cpp 

// Start of Tapquansu.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, k, C[45];
set <int> s;
void sinh () {
	int i, j;
	i=k;
	while (i>0 && C[i]==n-k+i) i--;
	if (i == 0 ) {
		cout << k;
	}
	else {
		C[i]++;
		for (j=i+1; j<=k; j++) C[j]=C[j-1]+1;
		for (int i=1; i<=k; i++) s.insert (C[i]);
		cout << s.size()-k;

	}
}
main () {
	int t,i;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for ( i=1; i<=k; i++)  {
			cin >> C[i];
			s.insert (C[i]);
		}
		sinh ();
		s.clear();
		cout << endl;		
	}
}

// End of Tapquansu.cpp 

// Start of ternarySearch.cpp 
#include <bits/stdc++.h>
using namespace std;
int ternaryI(int a[], int target, int n) 
{
    int l = 0;
    int r = n-1;
    while( r-l>=0 ) {
        int partiton = (r-l)/3;
        int mid1 = l + partiton;
        int mid2 = r - partiton;
        if ( target == a[mid1])
            return 1;
        else if ( target == a[mid2]) 
 		    return 1;
        else if ( target < a[mid1] ) 
            r = mid1-1;
        else if ( target > a[mid2] )
            l = mid2+1;
        else {
            l = mid1+1;
            r = mid2-1;
        } 
    }
    return -1;
}
int main () {
	int t,n,x;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		int a[n];
		for (int i=0; i<n; i++) cin >> a[i];
		cout << ternaryI(a,x,n) << endl;
	}
}


// End of ternarySearch.cpp 

// Start of thaphanoi.cpp 
#include <bits/stdc++.h>
using namespace std;
int n;
void in(char a, char c) {
	cout << a << " -> " << c << endl;
}
void Try(int i, int a, int b, int c) {
	if (i==1)  // neu thoa man dieu kien dung
		in(a,c); // giai quyet truong hop suy bien
	else {  // neu khong thoa man dieu kien dung
		Try(i-1, a, c, b); // goi ham de quy
		in(a,c); // hau xu li ham de quy
		Try(i-1, b, a, c); // tiep tuc goi de quy
	}
}
main() {
	cin >> n;
	char a='A', b='B', c='C';
	Try (n, a, b, c);
}



// End of thaphanoi.cpp 

// Start of Thuattuansinh.cpp 
#include <bits/stdc++.h> 
using namespace std;
int n, OK=0, B[25]={0};
int check (int n, int B[]) {
	int l=1, r=n;
	while (l<r) {
		if (B[l]!=B[r]) return 0;
		l++; r--;
	}
	return 1;
}
void in() {
	if (check(n,B)) {
		for (int i=1; i<=n; i++) cout << B[i] << " ";
		cout << endl;
	}
}
void sinh () {
	int i=n;
	while (B[i]) {
		B[i]=0;
		i--;
	}
	if (i==0) OK=1;
	else B[i]=1;
}
//0 0 0 0
//0 0 0 1
//0 0 1 0
//0 0 1 1
main () {
	cin >> n;
	while (!OK) {
		in();
		sinh();
	}
}

// End of Thuattuansinh.cpp 

// Start of timsoKthoamandieukien.cpp 
#include <bits/stdc++.h>
using namespace std;
int r, l;
int check (int n) {
	priority_queue <int> pq;
	while (n) {
		pq.push(n%10);
		n/=10;
	}
	int temp=0;
	if (pq.top() > 5) return 0;
	else {
		temp=pq.top();
		pq.pop();
	}
	while (!pq.empty()) {
		if (pq.top() > 5) return 0;
		if (pq.top()==temp) return 0;
		temp=pq.top();
		pq.pop();
	}
	return 1;
}
void solve () {
	int res=0;
	for (int i=l; i<=r; i++) {
		if (check(i)) res++;
	}
	cout << res << endl;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> l >> r;
		solve();
	}
}

// End of timsoKthoamandieukien.cpp 

// Start of tinhgiatribieuthuc-hauto.cpp 
#include <bits/stdc++.h>
using namespace std;
string s;
bool is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int cal (int a, int b, char x) {
	if (x=='+') return a+b;
	if (x=='-') return a-b;
	if (x=='*') return a*b;
	if (x=='/') return a/b;
}
void solve() {
	stack <int> st;
	for (int i=0; i<s.size(); i++) {
		if (!is_operator(s[i])) st.push(s[i]-'0');
		else {
			int s1=st.top(); st.pop();
			int s2=st.top(); st.pop();
			int temp= cal(s2,s1, s[i]);
			st.push(temp);
		}
	}
	cout << st.top() << endl;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		solve();
	}
}

// End of tinhgiatribieuthuc-hauto.cpp 

// Start of tinhgiatribieuthuc-tiento.cpp 
#include <bits/stdc++.h>
using namespace std;
string s;
bool is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int cal (int a, int b, char x) {
	if (x=='+') return a+b;
	if (x=='-') return a-b;
	if (x=='*') return a*b;
	if (x=='/') return a/b;
}
void solve() {
	stack <int> st;
	for (int i=s.size(); i>=0; i--) {
		if (!is_operator(s[i])) st.push(s[i]-'0');
		else {
			int s1=st.top(); st.pop();
			int s2=st.top(); st.pop();
			int temp= cal(s1,s2, s[i]);
			st.push(temp);
		}
	}
	cout << st.top() << endl;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		solve();
	}
}

// End of tinhgiatribieuthuc-tiento.cpp 

// Start of tohopcotongsobangX.cpp 
#include <bits/stdc++.h> 
using namespace std;
int n, x, OK, a[100], b[100];
vector <vector <int>> res;
void solve (int n) {
	vector <int> temp;
	for (int i=1; i<n; i++) temp.push_back(b[i]);
	res.push_back (temp);
}
void Try(int i, int sum, int cur) {
	if (sum==x) {
		solve(i);
		OK=1;
		return;
	}
	for (int j=cur; j<=n; j++) {
		sum+=a[j];
		b[i]=a[j];
		if (sum<=x) Try(i+1, sum, j);
		sum-=a[j];
	}
}
main () {
	int t;
	cin >> t;
	while (t--) {
		res.clear();
		cin >> n >> x;
		for (int i=1; i<=n; i++) cin >> a[i];
		OK=0;
		sort (a+1, a+n+1);
		Try(1,0,1);
		if (!OK) cout << "-1";
		else {
		    cout << res.size() << " ";
    		for (int i=0; i<res.size(); i++) {
    			cout << "{";
    			for (int j=0; j < res[i].size()-1; j++) {
    				cout << res[i][j] << " ";
    			}
    			cout << res[i][res[i].size()-1] << "} ";
    		}
		}
		cout << endl;
	}
}

// End of tohopcotongsobangX.cpp 

// Start of tohoptieptheo.cpp 
#include <bits/stdc++.h>
using namespace std;
main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		set <int> s;
		for (int i=1; i<=k; i++) {
			cin >> a[i];
			s.insert(a[i]);
		}
		int i=k;
		while (n-k+i==a[i]) i--;
		if (i==0) {
			cout << k;
		}
		else {
			a[i]++;
			for (int j=i+1; j<=k; j++) {
				a[j]=a[j-1]+1;
			}
			for (int j=1; j<=k; j++) s.insert(a[j]);
			cout << s.size()-k;
		}
		cout << endl;
	}
}

// End of tohoptieptheo.cpp 

// Start of Tongdaycon=K.cpp 
#include <bits/stdc++.h> 
using namespace std;
int n, K, OK=0, B[25]={0}, dem=0;
void xuly(int a[]) {
	int sum=0;
	for (int i=1; i<=n; i++ ) {
		sum+=a[i]*B[i];
	}
	if (sum==K) {
		dem++;
		for (int i=1; i<=n; i++) if (B[i]==1) cout << a[i]<< " ";
		cout << endl;
	}
}
void sinh () {
	int i=n;
	while (B[i]) {
		B[i]=0;
		i--;
	}
	if (i==0) OK=1;
	else B[i]=1;
}
main () {
	cin >> n >> K;
	int a[n];
	for (int i=1; i<=n; i++) cin >> a[i];
	while (!OK) {
		xuly(a);
		sinh();
	}
	cout << dem << endl;
}

// End of Tongdaycon=K.cpp 

// Start of xauABcododaiN.cpp 
#include <bits/stdc++.h> 
using namespace std;
int n, B[15]={0}, KT;
void in() {
	for (int i=1; i<=n; i++) {
		if (B[i]==1) cout << "B";
		else cout << "A";
	}
	cout << " ";
}
void sinh() {
	int i=n;
	while (B[i]) {
		B[i]=0;
		i--;
	}
	if (i==0) KT=1;
	else B[i]=1;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		KT=0; 
		cin >> n;
		while (!KT) {
			in();
			sinh ();
		}
		cout << endl;
	}
}

// End of xauABcododaiN.cpp 

// Start of xauABdacbiet.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, k, OK=0, B[25]={0};
vector <string> v;
void xuly () {
	string s={};
	for (int i=1; i<=n; i++) {
		if (B[i]==0) s+='A';
		else s+='B';
	}
	v.push_back(s);
}
int check () {
	int i, d, sum=0;
	for (i=1; i<=n; i++) {
		int j=i;
		d=0;
		while (B[j]==0 && j<=n) {
			d++; j++;
			if (d>k) return 0;
		}
		if (d==k) sum++;
	}
	if (sum==1) return 1;
	return 0;
}
void sinh () {
	int i=n;
	while (B[i]) {
		B[i]=0; i--;
	}
	if (i==0) OK=1;
	else B[i]=1;
}
main () {
	cin >> n >> k;
	while (!OK) {
		if (check ()) xuly();
		sinh ();
	}
	cout << v.size() << endl;
	for (int i=0; i<v.size(); i++) cout << v[i]<< endl;
}


// End of xauABdacbiet.cpp 

// Start of xaunhiphancokbit.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, k, B[20]={0}, OK;
void in() {
	for (int i=1; i<=n; i++) {
		cout << B[i];
	}
	cout << endl;
}
int check () {
	int d=0, i;
	for (i=1; i<=n; i++) d+=B[i];
	return (d==k);
}
void sinh() {
	int i=n;
	while (B[i]) {
		B[i]=0; i--;
	}
	if (i==0) OK=1;
	else B[i]=1;
}
main () {
	int t; 
	cin >> t;
	while (t--) {
		cin >> n >> k;
		OK=0;
		while (!OK) {
			if (check())in();
			sinh();
		}

	}
}

// End of xaunhiphancokbit.cpp 

// Start of xaunhiphancoKbit1.cpp 
#include <bits/stdc++.h>
using namespace std;
int n, k, OK=0, B[25]={0};
void in () {
	for (int i=1; i<=n; i++) {
		cout << B[i];
	}
	cout << endl;
}
int check () {
	int d=0, i;
	for (i=1; i<=n; i++) d+=B[i];
	return (d==k);
}
void sinh () {
	int i=n;
	while (B[i]) {
		B[i]=0; i--;
	}
	if (i==0) OK=1;
	else B[i]=1;
}
main () {
	int t;
	cin >> t;
	while (t--) {
		OK=0;
		cin >> n >> k;
		while (!OK) {
			if (check ()) in();
			sinh ();
		}
	}
}


// End of xaunhiphancoKbit1.cpp 

// Start of Xaunhiphanketiep.cpp 
#include <bits/stdc++.h>
using namespace std;
main () {
	int t, i;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		i=s.size()-1;
		while (i>=0 && s[i]=='1') {
			s[i]='0'; i--;
		}
		if (i>=0) s[i] ='1';
		cout << s << endl;
	}
}

// End of Xaunhiphanketiep.cpp 

// Start of Xaunhiphantruoc.cpp 
#include <bits/stdc++.h>
using namespace std;
main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int i=s.size()-1;
		while (s[i]=='0') {
			s[i]='1'; i--;
		}
		if (i>=0) s[i] = '0';
		cout << s;
	}
}
//010011
//010100

// End of Xaunhiphantruoc.cpp 

// Start of xoaphantutrongDSLKdon.cpp 
#include <iostream>

using namespace std;

// �?nh nghia c?u tr�c c?a m?t node trong danh s�ch li�n k?t don
struct Node {
    int data;
    Node* next;
};

// H�m t?o m?t node m?i v?i gi� tr? du?c cung c?p v� con tr? next tr? d?n nullptr
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// H�m ch�n m?t node m?i v�o d?u danh s�ch li�n k?t
void insertAtBeginning(Node*& first, int value) {
    Node* newNode = createNode(value);
    newNode->next = first;
    first = newNode;
}

// H�m x�a t?t c? c�c ph?n t? c� gi� tr? b?ng x v� tr? v? s? lu?ng c�c ph?n t? d� x�a
int deleteValue(Node*& first, int x) {
    int deletedCount = 0;

    Node* current = first;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->data == x) {
            Node* temp = current;
            current = current->next;
            delete temp;
            deletedCount++;
            if (previous != nullptr) {
                previous->next = current;
            } else {
                first = current;
            }
        } else {
            previous = current;
            current = current->next;
        }
    }

    return deletedCount;
}

// H�m li?t k� c�c ph?n t? c�n l?i trong danh s�ch li�n k?t
void printList(Node* first) {
    Node* current = first;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}

// H�m gi?i b�i to�n
void solve() {
    int n;
    cin >> n;

    Node* first = nullptr;

    // �?c d? li?u v� ch�n c�c ph?n t? v�o danh s�ch li�n k?t
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertAtBeginning(first, value);
    }

    int x;
    cin >> x;

    // X�a c�c ph?n t? c� gi� tr? b?ng x v� l?y s? lu?ng c�c ph?n t? d� x�a
    int deletedCount = deleteValue(first, x);

    // In danh s�ch c�n l?i sau khi d� x�a
    printList(first);
    cout << endl;

    // Gi?i ph�ng b? nh?
    while (first != nullptr) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }
}

int main() {
    solve();
    return 0;
}


// End of xoaphantutrongDSLKdon.cpp 

