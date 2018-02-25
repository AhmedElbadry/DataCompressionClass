#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //bool flag = 0;
    //stack <string> st;
    bitset<3> three;
    bitset<6> six;
    bitset<8> eight;
    string s,t1,t0;
    vector <string> first,second,thirdones,thirdzeros,third;
    //vector <int> third0[10000], third1[10000];
    unordered_map <char , int> m;
    int p = 1, c1 , c0, /*ma1 = 0, ma0 = 0,tmp0 = 0 , tmp1 = 0 ,*/ c;
    unsigned int mi;

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

    //for(auto it : second)
    //    cout<<it<<endl;

    //3rd step
    for(int i = 0 ; i < (int)second.size() ; i++){
        if(i){
            six = m['\n'];
            t1 = t0 = six.to_string() ;
        }else{
            t1 = t0 = "";
        }

        c1 = c0 = 0;
        for(int j = 0 ; j < (int)second[i].size() ; j++){

            if(second[i][j] == '0'){
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
                //ma1 = max(ma1 , c1);
                //third1[i].push_back(c1);
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
                //ma0 = max(ma0 , c0);
                //third0[i].push_back(c0);
            }
        }
        /*for(auto it : third1[i])
            cout<<it<<" ";
        cout<<endl;
        for(auto it : third0[i])
            cout<<it<<" ";
        cout<<endl<<endl;*/
        //thirdones.push_back(t1);
        //thirdzeros.push_back(t0);

        mi = min(second[i].size() , min(t0.size() , t1.size()));

        if(mi == second[i].size())
            third.push_back("00" + second[i]);
        else if(mi == t1.size())
            third.push_back("01" + t1);
        else
            third.push_back("11" + t0);
        //cout<<third[i]<<endl;
    }

    //last step
    for(int i = 0 ; i<(int)third.size() ; i++){
        cout<<(int)third[i].size() % 6;
        for(int j = 0 ; j < (int)third[i].size() ;){
            c = 0;
            for(int k = (1LL<<min(5 , ((int)third[i].size() - j - 1))) ; k ; k/=2 , j++)
                c += k * (third[i][j] == '1');
            if(c > 9)
                cout<<(char)(c - 10 + 33);
            else
                cout<<c;
        }
    }

    return 0;
}
