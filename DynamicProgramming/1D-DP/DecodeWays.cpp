




class Solution {
public:
    int numDecodings(string s) {
        
        int  noofdeco = 0;
        noofdeco = recurs(s,0);
        return noofdeco;
        
    }
    
    //here we are recursing on which we are recursing the length or pointer which we are present initially we were at 0
    
    int recurs(string s,int pos)
    {
        if(pos == s.size())
            return 1;//reached end of thr stringwhy no of decod == 1
        if(s[pos]== '0')
            return 0;//s there is no encoding possible for 0
        if(pos == s.size()-1)
            return 1;  //Why 
        
        string b  = s.substr(pos,2);//From this position starting consider next two elements
        
        int way1 = recurs(s,pos+1);
        
        int way2 = 0;
        
        if(stoi(b) <= 26 &&  stoi(b) > 0)
            way2 = recurs(s,pos+2);
        
        //cout << way1  << way2 << pos + 1 << pos + 2  <<  '\n';
        
        return way1+way2;
        
    }
    
    //TC - 2^n 
    //SC - n
    
};


====================================================================================================================================================




int numDecodings(string s) {
        vector<int> hg(s.size()+1,0);
        int ans=0;
        ans = recur(s,0,hg);
        return ans;
    }
    int recur(string s, int pos, vector<int>& hg){
        if(pos==s.size())return 1;
        if(s[pos]=='0')return 0;
        if(pos==s.size()-1)return 1;
        if(hg[pos]>0)return hg[pos];
        string b = s.substr(pos,2);
        
        int way1 = recur(s,pos+1,hg);
        int way2=0;
        if(stoi(b)<=26&&stoi(b)>0){
            way2 = recur(s,pos+2,hg);
        }
        hg[pos]= way1+way2;
        return hg[pos];
    }




//Doubt 





























==================================================================================================================================================================

int numDecodings(string s){
    
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        if(s[0] == '0')
            dp[1] = 0;
        else
            dp[1] = 1;
        for(int i = 2;i <= n;i++)
        {
            int way1,way2;
            if(s[i-1] == '0')
                way1 = 0;
            else 
                way1 = dp[i-1];
            if(stoi(s.substr(i-2,2)) <= 26 && stoi(s.substr(i-2,2)) > 0 && s[i-2] != '0')
                way2 = dp[i-2];
            else 
                way2 = 0;
            
            dp[i] = way1 + way2;
        }
        
        return dp[n];
    }
    
    
    TC - o(n)
    Space - O(n)
    
   ------------------------------------------------------------------------------------------------------------------------------------------------------------
