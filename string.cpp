#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    string s;
    cin>>s;

     string t;
        string vowels;
        for(int i=0;i<s.size();i++){
            if(tolower(s[i])=='a' || tolower(s[i])=='e' || tolower(s[i])=='i' || tolower(s[i])=='o' || tolower(s[i])=='u' ){
                vowels.push_back(s[i]);
                t.insert(t.begin()+i,'0');
            }
            else{
                t.insert(t.begin()+i,s[i]);
            }
        }
        sort(vowels.begin(),vowels.end());
        cout<<vowels<<endl;
        cout<<t<<endl;
        for(int i=0;i<t.size();i++){
            if(t[i]=='0') t.insert(t.begin()+i,vowels[i]);
        }
        cout<<t;
return 0;
}