class Solution {
public:
    //Idea is to use KMP Longest Prefix Suffix table to match if one array is subarray of another array.
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        for(auto group : groups){
            int m = group.size();
            //Step-1 Generate LPS table
            vector<int>lps(m,0);
            int i = 1;
            int len = 0;
            while(i < m)
            {
                if(group[i] == group[len])
                {
                    lps[i] = len+1;
                    len+=1;
                    i+=1;
                }
                else 
                {
                    if(len != 0)
                    {
                        len = lps[len-1];
                    }
                    else 
                    {
                        lps[i] = 0;
                        i+=1;
                    }
                }
            }
            
            //https://www.youtube.com/watch?v=4jY57Ehc14Y code to explination kmp 
            
            //Step 2 - Matching
            int j = 0;
            while(index<n){
                if(nums[index]==group[j]){
                    j++;
                    index++;
                }
                if(j==m)
                    break;
                else
                 if(index <n && nums[index] != group[j]){
                    if(j >0){
                        j=lps[j-1];
                    }else{
                        index++;
                    }
                }
            }
            if(j != m)
                return false;
        }
        
        return true;
    }
};
