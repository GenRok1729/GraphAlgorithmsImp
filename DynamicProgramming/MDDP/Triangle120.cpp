class Solution {
    int m,n;
public:
    
    vector<vector<int>> dp;
    
    int recurs(vector<vector<int>>& triangle,int i,int j)
    {
        if(i == m-1)
            return triangle[i][j];
        
        if(dp[i][j]!=INT_MAX)
            return dp[i][j];
        
        //J will never cross i 
        
        //cout << m;
        //cout << i << j << '\n';
        
        int way1 = recurs(triangle,i+1,j);
        int way2 = recurs(triangle,i+1,j+1);
        //  Base case here 
        int ans = triangle[i][j] + min(way1,way2);
        
        return dp[i][j] = ans;
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        m = triangle.size();
        n = triangle[m-1].size();
        int i = 0,j = 0;
        dp.resize(n+1,vector<int> (n+1,INT_MAX));
        return recurs(triangle,i,j);   
    }
    
};

==================================================================================================================================================================

class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        
        int n = t.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
        //There u fing for first try to find for above cases as u cannot find them u will move than eventualyy to find the base one 
        
        //In this case complete opposite here as we know we have to move from least possible test case to highest possible one we do that 
        
        for(int j = 0;j < n;j++)
        {
            dp[n-1][j] = t[n-1][j]; 
        }
        for(int i = n-2;i >= 0;i--)
        {
            for(int j = 0;j <= i;j++)//There will be only 1 columns in ith row 
            {
                dp[i][j] = t[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        
        return dp[0][0];
        
    }
};

//Bottom up
