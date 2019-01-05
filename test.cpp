#include<hash_map>
#include<queue>
#include<iostream>
using namespace std;

int main(void){
    hash_map<string,string>  hashmap;
    queue<string> que;
    hashmap["a"]="b,c";
    hashmap["b"]="c";
    hashmap["c"]="e";
    hashmap["d"]="b";
    hashmap["e"]="";
    que.push(hashmap["a"]);
    bool flag = false;
    while(que.size()){
        string temp = que.front();
        que.pop();
        if(temp == "d"){
            flag = true;
        }else{
            que.push(hashmap[temp]);
        }
        return  false;
    }
    if(flag==true){
        cout >> "ok";
    }
    else{
        cout >> "no";
    }
    system("pause");
    return 0;
}