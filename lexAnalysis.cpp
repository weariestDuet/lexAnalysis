#include<bits/stdc++.h>

using namespace std;

map<string,string> rule={
    {"BEGIN","Begin"},
    {"END","End"},
    {"FOR","For"},
    {"IF","If"},
    {"THEN","Then"},
    {"ELSE","Else"},
    {":","Colon"},
    {"+","Plus"},
    {"*","Star"}
};

char s[10000001];

bool isDigit(char x){
    return(x>='0'&&x<='9');
}

bool isAlpha(char x){
    return (x>='a'&&x<='z')||(x>='A'&&x<='Z');
}

int main(){
    char c;
    string tmp;
    int len=0;

    while(~(c=getchar())){
        s[len++]=c;
    }

    for(int i=0;i<len;i++){
        tmp ="";
        if(isspace(s[i]))
            continue;

        if(isAlpha(s[i])){
            tmp+=s[i];
            while(isAlpha(s[i+1])||isDigit(s[i+1])){
                i++;
                tmp+=s[i];
            }

            if(rule.count(tmp)){
                cout<<rule[tmp]<<"\n";
            }
            else{
                cout<<"Ident("<<tmp<<')'<<"\n";
            }
        }
        else if(isDigit(s[i])){
            tmp+=s[i];
            while(isDigit(s[i+1])){
                i++;
                tmp+=s[i];
            }
            cout<<"Int("<<stoi(tmp)<<')'<<"\n";
        }
        else if(s[i]==':'){
            if(s[i+1]=='='){
                cout<<"Assign"<<"\n";
                i++;
            }
            else{
                cout<<"Colon"<<"\n";
            }
        }
        else if(s[i]=='+')
            cout<<"Plus"<<"\n";
        else if(s[i]=='*')
            cout<<"Star"<<"\n";
        else if(s[i]==',')
            cout<<"Comma"<<"\n";
        else if(s[i]=='(')
            cout<<"LParenthesis"<<"\n";
        else if(s[i]==')')
            cout<<"RParenthesis"<<"\n";
        else{
            cout<<"Unknown"<<"\n";
            break;
        }
    }

    return 0;
}
