#include <bits/stdc++.h>
using namespace std;

vector<string> head;
vector<string> url;

void gen_head(string &str){
    head.push_back(str);
    return ;
}

string find_idnex(string &str){
    bool flag = false;
    string head;
    for(int i=0;i<str.length();i++){
        if(str[i]=='#')flag=true;
        if(flag) head+=str[i];
    }
    return head;
}

void url_gen(){
    for(auto &t:head){
        int start=0;
        stringstream ss;
        string url2="#";
        string tmp;
        ss<<t;
        ss>>tmp;
        start=tmp.length();
        for(int i=start+1;i<t.length();i++){
            if(t[i]==' ' && i!=t.length()-1) url2+='-';
            else if(t[i]==' ' && i==t.length()-1){
                break;
            }  
            else{
                if(t[i]!='(' && t[i]!=')' && t[i]!=':' && t[i]!='.'){
                    url2+=t[i];
                } 
            } 
        }
        url.push_back(url2);
    }
    return ;
}

void to_lowercase(){
    for(auto &t:url){
        for(int i=0;i<t.length();i++){
            if(t[i]>='A' && t[i]<='Z'){
                t[i]+=32;
            }
        }
    }
    return ;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    string str1;
    while(getline(cin,str1)){
        string str2;
        stringstream ss;
        ss << str1;
        string tmp;
        ss>>tmp;
        
        if(tmp=="#"||tmp=="##"||tmp=="###"||tmp=="####"||tmp=="#####"||tmp=="######"){
            str2=find_idnex(str1);
            gen_head(str2);
        } 
        else continue;
    }

    url_gen();
    to_lowercase();

    for(auto &t:url){cout<<t<<endl;}
    
    return 0;
}