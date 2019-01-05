#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    int a,b;
    int fushuflag=0;
    vector<string> v;
    string ssum;
    cin >> a >> b;
    int sum = a+b;

    if(sum < 0) {
        fushuflag = 1;
        sum = 0-sum;
    }
    stringstream ss;
    ss << sum;
    ss >> ssum;
    ss.clear();
    if(ssum.length() <=3){
        if(fushuflag==1) cout << "-";
        cout << ssum<<endl;
    }else{
        int lasti;
        reverse(ssum.begin(),ssum.end());
        for(int i=0; ssum.length()-1-i >=3; i+=3){
            string temp = ssum.substr(i,3);
            v.push_back(temp);
            lasti = i;
        }
        string last = ssum.substr(lasti+3,ssum.length()-(lasti+3));
        v.push_back(last);
    }
    int flag=0;
    if(fushuflag==1) cout << "-";
    for(int i=v.size()-1; i>=0; i--){
        if(flag==1) cout<<",";
        reverse(v[i].begin(),v[i].end());
        cout << v[i];
        flag = 1;
    }
    system("pause");
    return 0;
}

/*#include <iostream>
#include<string>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    string s = to_string(a + b);
    int len = s.length();
    for (int i = 0; i < len; i++) {
        cout << s[i];
        if (s[i] == '-') continue;
        if ((i + 1) % 3 == len % 3 && i != len - 1) cout << ",";
    }
    system("pause");
    return 0;
}*/