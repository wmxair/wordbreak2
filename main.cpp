#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> sol;
        string tmp;

        helper(s,wordDict,0,sol,tmp);
        return sol;
    }

    void helper(string s, vector<string>& wordDict,int start,vector<string> &sol,string &tmp){
        if(start>=s.size()-1 &&tmp!="" ){
            sol.push_back(tmp);
            return;
        }


        string t;

        vector<string>::iterator x;
        for(int i=start;i<s.size();i++){
            //s.str(start,i)is in Dict
            x=find(wordDict.begin(),wordDict.end(),s.substr(start,i-start+1));
            if(x!=wordDict.end()){
                cout<<"the"<<start<<"and"<<i<<"being"<<endl;
                t=tmp;
                cout<<"old t"<<t<<endl;
                t=t+' '+s.substr(start,i-start+1);
                cout<<"new t"<<t<<endl;
                helper(s,wordDict,i+1,sol,t);
            }
        }

    }
};

int main(){
        vector<string> D;
        string s;

        s="ab";

        //["cat","cats","and","sand","dog"]
        D.push_back("a");
        D.push_back("b");
        //D.push_back("and");
        //D.push_back("sand");
        //D.push_back("dog");



        Solution thes;
        vector<string> d;
        d=thes.wordBreak(s,D);

        for(int i=0;i<d.size();i++)
                cout<<d[i]<<endl;

        return 0;
}
