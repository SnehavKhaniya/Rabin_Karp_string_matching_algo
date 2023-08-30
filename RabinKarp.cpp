#include <bits/stdc++.h>
using namespace std;

void RobinKarp(string t, string p){
    int d = 10;
    int q = 13;

    int n = t.size();
    int m = p.size();

    int ts = 0, ps = 0;
    for(int i = 0; i < m; ++i){
        /*
        ts += ((int)t[m - i - 1] - '0') * (int)pow(d, i);
        ps += ((int)p[m - i - 1] - '0') * (int)pow(d, i);
        */

        ts = d * ts + (t[i] - '0');
        ps = d * ps + (p[i] - '0');
        //cout << ts << "&" << ps << endl;
    }
    //cout << ts << "_" << ps << endl;

    int s = 0;
    do{
        //cout << "s = " << s << endl;
        
        if(ts % q == ps % q){
            int i = 0;
            while(i < m && t[s + i] == p[i]){
                i++;
            }
            
            if(i == m){
                cout << s << endl;
            }
            else{
                //cout << i << "_" << ts << endl;
                cout << s << " - spurious hit\n";
            }
        }
        
        ts = (ts -((int)t[s] - '0') * (int)pow(d, m - 1)) * d + ((int)t[s + m] - '0');
        /*
        cout << "num1 = " << (int)t[s] - '0' << endl;
        cout << "pow = " << pow(d, m - 1) << endl;
        cout << "num2 = " << (int)t[s + m] - '0' << endl;
        cout << "ts = " << ts << endl;
        */
        s++;
    }while(s <= n - m);
}

int main(){
    string text, pattern;

    cout << "Enter Number Text: ";
    cin >> text;

    cout << "Enter Number Pattern: ";
    cin >> pattern;

    RobinKarp(text, pattern);

    return 0;
}

//not working well in vs code
//try online compiler.................................
