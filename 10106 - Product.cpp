#include<bits/stdc++.h>
using namespace std;

const int N     = 1005;

int A[N], B[N], C[N];
string s, t;
void reset(){
    for(int i=0;i<N; i++){
        A[i] = 0; B[i] = 0; C[i] = 0;
    }
}
void strToArray(string s, int A[]){
    for(int i=0; i<s.size(); i++){
        A[i] = s[i] - '0';
    }
}

void prod(){
    int k = 0;
    for(int i=0; i<s.size(); i++){
         k = i;
        for(int j=0; j<t.size(); j++){
            int product = A[i]*B[j];
            C[k] += product;
            C[k+1] += C[k] / 10;
            C[k] %= 10; k++;
        }
    }
}

void solve(int tc){
    while(cin >> s >> t){
        reset();
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        strToArray(s, A);
        strToArray(t, B);

        prod();

        int i=1000;
        while( i>= 0 && C[i] == 0) i--;
        if(i<0) {
            cout << "0\n";
            continue;
        }
        for(; i>=0; i--) cout << C[i];
        cout << endl;
    }
}

int32_t main(){
    int tc = 1;
    solve(tc);

    return 0;
}

