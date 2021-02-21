int longestPalindromeSubseq(string str) {
            //tRY tHIS 
        int m= str.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,0));
        int maxlen=1;
        for(int len=1;len<=str.size();len++)
        {
            for(int start=0;start+len-1<str.size();start++)
            {
                int end=start+len-1;
                if(len==1)
                    dp[start][start]=1;
                else
                {
                    if(str[start]==str[end])
                    {
                        dp[start][end]= 2+ dp[start+1][end-1];
                        maxlen=max(maxlen,dp[start][end]);
                    }
                    else
                        dp[start][end]=max(dp[start+1][end],dp[start][end-1]);
                }
            }
        }
        return maxlen;
        
        
        
_______________________________________________________________________________________________________________________________________________________________
        
       int longestPalindromeSubseq(string s) {
            //thIS WORKS MOST OF  THE TIE IF NOT 
        string text1 = s;
        string text2 = string(s.rbegin(),s.rend()); 
        int l1 = text1.length();
        int l2  = text2.length();
        //Base contion in bottum up will become the first loops in these top down 
        vector<vector<int>> dp(l1+1,vector<int> (l2+1,0));
        
        for(int i = 0;i < l1+1;i++)
        {
            dp[i][0] = 0;
        }
        for(int i = 0;i < l2+1;i++)
        {
            dp[0][i] = 0;
        }
        
        for(int i = 1;i < l1+1;i++)
        {
            for(int j = 1;j < l2+1;j++)
            {
                if(text1[i-1] == text2[j-1])//We are doing for substrings in the larger picture remember that 
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[l1][l2];    
    }
     
        
        
