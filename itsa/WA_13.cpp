#include <bits/stdc++.h>
using namespace std;

class card{
    public:
        char suit;
        int num;
};
int convertSuitToNum(char c){
    switch(c){
        case 'S':
            return 3;
        case 'H':
            return 2;
        case 'D':
            return 1;
        case 'C':
            return 0;
        default:
            return 0;
    }
}
int cmp(card* a, card* b){
    int tempA, tempB;
    if(convertSuitToNum(a->suit)>convertSuitToNum(b->suit)){
        return 1;
    }
    else if(convertSuitToNum(a->suit)==convertSuitToNum(b->suit)){
        if(a->num>b->num){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}

void split(vector<card*>& v, string str, string pattern){
    int begin=0;
    int end=str.find(pattern);
    string temp;
    while(end!=string::npos){
        if(end!=begin){//preventing consecutive occuence of pattern
            card* ptr=new card();
            ptr->suit=str.substr(begin, end)[0];
            ptr->num=stoi(&str.substr(begin, end)[1]);
            v.push_back(ptr);
        }
        begin=end+pattern.size();
        end=str.find(pattern, begin);
    }
    if(begin!=str.length()){
        card* ptr=new card();
        ptr->suit=str.substr(begin)[0];
        ptr->num=stoi(&str.substr(begin, end)[1]);
        v.push_back(ptr);
    }
    
}

int main(){
    int n;
    string str;
    string pattern=" ";
    vector <card*>v;
    card* ptr;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        v.clear();
        getline(cin, str, '\n');
        split(v, str, pattern);
        sort(v.begin(), v.end(),cmp);
        for(auto i:v){
            cout<<i->suit<<i->num<<" ";
            delete i;
        }    
        cout<<endl;
    }
}