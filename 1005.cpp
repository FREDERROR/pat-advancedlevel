#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(void){
    string s;
    cin >> s;
    int sum=0;
    for(int i=0; i<s.length(); i++){
        sum +=s[i]-'0';
    }
    string ssum = to_string(sum);
    string num[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    for(int i=0; i<ssum.length(); i++){
        if(i==0){
            cout << num[ssum[i]-'0'];
        }
        else{
            cout << " " << num[ssum[i]-'0'];
        }
        
    }
    system("pause");
    return 0;
}