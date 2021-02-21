// Interview bit
int Solution::fibsum(int a) {
    
    int dp[65];
    int ans=0;
    dp[0] =1;dp[1] =1;
    for(int i =2;i<=60;i++) dp[i] = dp[i-1]+dp[i-2];
     for(int i =1;i<=60;i++) if(a == dp[i]) return 1;;
   
    for(int i =60;i>=1;i--){
        
        while(a >= dp[i]){
            ans++;
            
            a -= dp[i];
            i--;
        }
    }
   return ans;
  
}
