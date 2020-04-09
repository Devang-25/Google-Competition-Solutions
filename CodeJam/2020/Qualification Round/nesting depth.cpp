//Sharma ji ka Ladka Code Karta h !!!

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        string str, ans;
        cin>>str;
        int n = str.length(), open = 0;
        for(int i=0; i<n; i++){
            int cnt = str[i]-'0';
            while(open>cnt){
                ans += ')';
                open--;
            }
            while(open<cnt){
                ans += '(';
                open++;
            }
            ans+=str[i];
        }
        while(open != 0){
            ans += ')';
            open--;
        }
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}