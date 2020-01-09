#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    string t;
    int Size=0;
    for(int i=0;s[i];i++){
        if(s[i]==' ') continue;
        t.push_back(s[i]);
        Size++;
    }

    double root = sqrt(Size*1.0);
    int r,c;

    r = floor(root);
    c = ceil(root);

    if(r*c<Size){
        r = c;
    }
    string result;
    for(int i=0;i<c;i++){

        for(int j=i;j<Size;j+=c){
            result.push_back(t[j]);
        }
        result.push_back(' ');
    }

    return result;
}

int main()
{
//    ofstream fout(getenv("OUTPUT_PATH"));
//
//    string s;
//    getline(cin, s);
//
//    string result = encryption(s);
//
//    fout << result << "\n";
//
//    fout.close();
//
//    return 0;
}
