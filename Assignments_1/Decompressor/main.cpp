#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    bitset<8> eight;
    bitset<7> seven;
    bitset<6> six;
    bitset<3> three;
    bitset<2> two;
    stringstream ss;
    vector <string> first,second,third;
    string s, t;
    stack <string> st;
    unordered_map <int , char> m;
    char p = 'a';
    int c,mod;
    bool flag;

    for(int i = 1 ; i < 53 ; i++){
        m[i] = p;
        if(p == 'z'){
            p = 'A' - 1;
        }
        p++;
    }

    m[53] = '<';
    m[54] = '>';
    m[55] = ' ';

    //1st step
    while(getline(cin , s)){
        mod = s[0] - '0';
        t = "";
        for(int i = 1 ; i<(int)s.size() ; i++){
            c = s[i] - 33;
            if(c >= 157)
                c -= 5;
            for(int k = ((i+1 ==(int)s.size()) ? (1<<(mod-1)) : 32) ; k ; k/=2){
                if(c >= k){
                    t += '1';
                    c -= k;
                }
                else
                    t += '0';
            }
        }
        first.push_back(t);
    }

    //for(auto it : first)
    //    cout<<it<<endl;

    //2nd step
    for(int i = 0 ; i < (int)first.size() ; i++){
        t = "";
        ss.clear();
        ss<<first[i].substr(0,2);
        ss>>two;
        first[i] = first[i].substr(2);
        if(two == 0)
            t+=first[i];

        else{
            while(!first[i].empty()){
                if(first[i][0] == '1'){
                    first[i] = first[i].substr(1);
                    ss.clear();
                    ss<<first[i].substr(0,3);
                    ss>>three;
                    c = three.to_ulong();
                    while(three == 7){
                        first[i] = first[i].substr(3);
                        ss.clear();
                        ss<<first[i].substr(0,3);
                        ss>>three;
                        c += three.to_ulong();
                    }

                    first[i] = first[i].substr(3);
                    for(int i = 0 ; i<c ; i++)
                        t += (two == 1 ? '1' : '0');
                }
                else
                    first[i] = first[i].substr(1);
                if(!first[i].empty())
                t += (two == 1 ? '0' : '1');
            }
        }
        second.push_back(t);
    }

    //3rd step
    for(int i = 0 ; i < (int)second.size() ; i++){
        t = "";
        while(!second[i].empty()){
            ss.clear();
            ss<<second[i].substr(0,6);
            second[i] = second[i].substr(6);
            ss>>six;
            if(six == 57)
                t += "\n";
            else if(six == 56)
                t += "<>";
            else if(six == 0){
                ss.clear();
                ss<<second[i].substr(0,8);
                second[i] = second[i].substr(8);
                ss>>eight;
                t += ((char) eight.to_ulong());
            }
            else
                t += m[six.to_ulong()];
        }
        third.push_back(t);
    }

    //last step
    for(int i = 0 ; i < (int)third.size() ; i++){
        flag = 0;
        s = t = "";
        for(int j = 0 ; j < (int)third[i].size() ; j++){
            t += third[i][j];

            if(flag && third[i][j] != '>')
                s += third[i][j];

            else if(flag){
                flag = 0;
                if(s != "br")
                    st.push(s);
                s = "";
            }

            if(third[i][j] == '<' && third[i][j+1] == '>'){
                t += '/' + st.top() + '>';
                st.pop();
                j++;
            }

            else if(third[i][j] == '<')
                flag = 1;
        }
        cout<<t<<endl;
    }

    return 0;
}
