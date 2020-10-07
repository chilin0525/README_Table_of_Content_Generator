#include <bits/stdc++.h>
# define TAB "    "
using namespace std;

vector<string> head;
vector<string> url;
vector<string> title;
vector<pair<string,int> > rec;

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

void title_gen(){
    for(int i=0;i<head.size();i++){
        stringstream ss;
        string tmp,tmpTitle;
        ss<<head[i];
        ss>>tmp;
        if(tmp=="#"){
            tmpTitle.assign(head[i],2,head[i].size()-2);
            rec.push_back(make_pair(tmpTitle,1));
        }
        else if(tmp=="##"){
            tmpTitle.assign(head[i],3,head[i].size()-3);
            rec.push_back(make_pair(tmpTitle,2));
        }
        else if(tmp=="###"){
            tmpTitle.assign(head[i],4,head[i].size()-4);
            rec.push_back(make_pair(tmpTitle,3));
        }
        else if(tmp=="####"){
            tmpTitle.assign(head[i],5,head[i].size()-5);
            rec.push_back(make_pair(tmpTitle,4));
        }
        else if(tmp=="#####"){
            tmpTitle.assign(head[i],6,head[i].size()-6);
            rec.push_back(make_pair(tmpTitle,5));
        }
        else if(tmp=="######"){
            tmpTitle.assign(head[i],7,head[i].size()-7);
            rec.push_back(make_pair(tmpTitle,6));
        }
        title.push_back(tmpTitle);
    }
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
    title_gen();
    to_lowercase();

    cout<<"================Table of Content================"<<'\n'<<'\n';

    for(int i=0;i<title.size();i++){
        if(rec[i].second==1){
            cout<<"* ["<<rec[i].first<<"]("<<url[i]<<")"<<endl;
        }
        else if(rec[i].second==2){
            cout<<TAB<<"* "<<"["<<rec[i].first<<"]("<<url[i]<<")"<<endl;
        }
        else if(rec[i].second==3){
            cout<<TAB<<TAB<<"* "<<"["<<rec[i].first<<"]("<<url[i]<<")"<<endl;
        }
        else if(rec[i].second==4){
            cout<<TAB<<TAB<<TAB<<"* "<<"["<<rec[i].first<<"]("<<url[i]<<")"<<endl;
        }
        else if(rec[i].second==5){
            cout<<TAB<<TAB<<TAB<<TAB<<"* "<<"["<<rec[i].first<<"]("<<url[i]<<")"<<endl;
        }
        else{
            cout<<TAB<<TAB<<TAB<<TAB<<TAB<<"* "<<"["<<rec[i].first<<"]("<<url[i]<<")"<<endl;
        }
    }
    cout<<endl;
    cout<<"[Created By README_Table_of_Content_Generator By Chilin😎️😎️😎️](https://github.com/chilin0525/README_Table_of_Content_Generator)"<<endl;

    
    return 0;
}