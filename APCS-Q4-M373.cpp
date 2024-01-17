
#include<iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long k,n;
    cin>>n>>k;
    long long day[n];
    
    for(long long i=0;i<n;i++){
        cin>>day[i];
    }
    
    long long dp[n][k];
    
    dp[0][0] = day[0];
    
    for(long long i=1;i<n;i++){
        dp[0][i] = day[i];
        if(dp[0][i-1]>0){
            dp[0][i] += dp[0][i-1];
        }
    }

    for(long long j=1;j<n;j++){
        dp[j][0] = (day[j]>0)? day[j]:0;
        for(long long i=1;i<k;i++){
            if(dp[j][i]-day[j]>dp[0][i]){
                dp[j][i] =dp[j][i]-day[j];
            }
        }
    }
    
    long long high = 0;
    for(long long i=0;i<n;i++){
        if(dp[0][i] > high){
            high = dp[0][i];
        }
    }
    cout<<high;
}
