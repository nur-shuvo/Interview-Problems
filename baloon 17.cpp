#include<bits/stdc++.h>
using namespace std;
int n,bal[500],dp[500][500];

int solve()
{
    for(int len=1;len<=n;len++){
//            i- suru
//            j- sesh
        for(int i=0;i<=n-len;i++){
            int j = i + len - 1;
            for(int mid=i;mid<=j;mid++){
                int left = 1;
                int right = 1;

                if(i!=0) left = bal[i-1];
                if(j!=n-1) right = bal[j+1];

                int before, after; before = after = 0;

                if(i!=mid) before = dp[i][mid-1];
                if(j!=mid) after =  dp[mid+1][j];

                dp[i][j] = max(dp[i][j], before+after+(left*right*bal[mid]));

            }
        }
    }
    return dp[0][n-1];
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>bal[i];
    cout<<solve()<<endl;
}
