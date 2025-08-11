#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int a1,b1,a2,b2;
        cin>>a1>>b1>>a2>>b2;
        
        int req=5*a2 + b2;
        int init=5*a1 + b1;
        int diff= req-init;
        
        if(diff%6!=0){
            cout<<"NO"<<endl;
        }
        else{
            while(diff){
                a1=a1-1;
                b1=b1-1;
                diff=diff-6;
            }
        }
        
        if(a2!=a1){
            if(a2>a1){
                a1+=(a2-a1);
                b1-=(a2-a1)*5;
            }
            else if(a1>a2){
                a1-=(a1-a2);
                b1+=(a1-a2)*5;
            }
        }
        if(b1==b2){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
