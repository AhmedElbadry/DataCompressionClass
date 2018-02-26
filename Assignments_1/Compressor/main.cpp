#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    bitset<3> three;
    bitset<6> six;
    bitset<8> eight;
    string s,t1,t0,second,third;
    vector <string> first;
    unordered_map <char , int> m;
    int p = 1, c1 , c0, c;
    unsigned int mi;

    for(char i = 'a' ; i <= 'z' ; i++)
        m[i] = p++;
    for(char i = 'A' ; i <= 'Z' ; i++)
        m[i] = p++;

    m['<'] = p++;
    m['>'] = p++;
    m[' '] = p++;

    //1st step
    while(getline(cin , s)){
        if(s.empty())
            continue;
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

    //for(auto it : first)
    //    cout<<it<<endl;

    //2nd step
    second = "";
    for(int i = 0 ; i < (int)first.size() ; i++){
        if(!second.empty()){
            six = 57;
            second += six.to_string();
        }

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
        second += t1;
    }

    //for(auto it : second)
    //   cout<<it<<endl;

    //3rd step
    t1 = t0 = "";
    c1 = c0 = 0;
    for(int j = 0 ; j < (int)second.size() ; j++){
        if(second[j] == '0'){
            c0++;
            if(c1){
                t1 += '1';
                while(c1 >= 7){
                    three = 7;
                    t1 += three.to_string();
                    c1 -= 7;
                }
                three = c1;
                t1 += three.to_string();
                c1 = 0;
            }
            else
                t1 += '0';
        }
        else{
            c1++;
            if(c0){
                t0 += '1';
                while(c0 >= 7){
                    three = 7;
                    t0 += three.to_string();
                    c0 -= 7;
                }
                three = c0;
                t0 += three.to_string();
                c0 = 0;
            }
            else
                t0 += '0';
        }
    }

    if(c1){
        t1 += '1';
        while(c1 >= 7){
            three = 7;
            t1 += three.to_string();
            c1 -= 7;
        }
        three = c1;
        t1 += three.to_string();
        c1 = 0;
    }
    else
        t1 += '0';

    if(c0){
        t0 += '1';
        while(c0 >= 7){
            three = 7;
            t0 += three.to_string();
            c0 -= 7;
        }
        three = c0;
        t0 += three.to_string();
        c0 = 0;
    }
    else
        t0 += '0';

    mi = min(second.size() , min(t0.size() , t1.size()));

    if(mi == second.size())
        third = "00" + second;
    else if(mi == t1.size())
        third = "01" + t1;
    else
        third = "11" + t0;

    //for(auto it : third)
     //   cout<<it;

    //last step
    cout<<(((int)third.size() % 6) ? ((int)third.size() % 6) : 6);
    for(int j = 0 ; j < (int)third.size() ;){
        c = 0;
        for(int k = (1LL<<min(5 , ((int)third.size() - j - 1))) ; k ; k/=2 , j++)
            c += k * (third[j] == '1');

        c += 33;
        if(c >= 157)
            c += 5;
        cout<<(char)(c);
    }

    return 0;
}
