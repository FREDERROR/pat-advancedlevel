#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

int main(void){
    vector<float> v(1001,0);
    int n1;
    int cishu;
    float xishu;
    cin >> n1;
    for(int i=0; i<n1; i++){
        cin >> cishu >> xishu;
        v[cishu] = v[cishu]+xishu;
    }
    int n2;
    cin >> n2;
    for(int i=0; i<n2; i++){
        cin >> cishu >> xishu;
        v[cishu] = v[cishu] + xishu;
    }
    int cnt=0;
    for(int i=1000; i>=0; i--){
        if(v[i]!=0.0){
            cnt++;
        }
    }
    cout << cnt;
    for(int i=1000; i>=0; i--){
        if(v[i]!=0.0){
            printf(" %d %.1f",i,v[i]);
        }
    }
    system("pause");
    return 0;
}