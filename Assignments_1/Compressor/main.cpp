#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //bool flag = 0;
    //stack <string> st;
    bitset<4> four;
    bitset<6> six;
    bitset<8> eight;
    string s,t1,t0;
    vector <string> first,second,third;
    unordered_map <char , int> m;
    int p = 1, c1 , c0;

    for(char i = 'a' ; i <= 'z' ; i++)
        m[i] = p++;
    for(char i = 'A' ; i <= 'Z' ; i++)
        m[i] = p++;

    m['<'] = p++;
    m['>'] = p++;
    m[' '] = p++;
    //m['\n'] = p++;

    //1st step
    while(getline(cin , s)){
        t1 = "";
        for(int i = 0 ; i < (int)s.size() ; i++){
            if(i && s[i] == '/' && s[i-1] == '<'){
                while(s[i] != '>')
                    i++;
            }
            t1 += s[i];
        }
        first.push_back(t1);
    }

    for(auto it : first)
        cout<<it<<endl;

    //2nd step
    for(int i = 0 ; i < (int)first.size() ; i++){
        t1 = "";
        for(int j = 0 ; j < (int)first[i].size() ; j++){
            if(first[i][j] == '<' && first[i][j+1] == '>'){
                six = p;
                t1 += six.to_string();
                j++;
            }
            else{
                six = m[first[i][j]];
                t1 += six.to_string();
                if(!m[first[i][j]]){
                    eight = (int) first[i][j];
                    t1 += eight.to_string();
                }
            }
        }
        second.push_back(t1);
    }

    for(auto it : second)
        cout<<it<<endl;

    //3rd step




    return 0;
}
