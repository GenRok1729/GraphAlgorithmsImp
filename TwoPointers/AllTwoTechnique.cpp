int maximumUniqueSubarray(vector<int>& nums) {
        
       // 5 2 1 2 5 2 1 2 5 
         //           i j   
        
        set<int> s;
        int i = 0;
        int j = 0;
        int ans = INT_MIN;
        int sum = 0;
        while(i < nums.size() && j < nums.size())  //Main point is that you have two pointers both from start where the second ones go forward and forward untill t
        {                                          //the condition holds true and when ones it fails the i will be incremeneted untill that false becomes true 
            //j++;                                 //Be careful and write both i & j for while loop converts n^2 to 2n
            if(s.find(nums[j]) != s.end())
            {
                    s.erase(nums[i]);
                    sum = sum - nums[i];
                    i++;
            }
            else 
            {
                   sum += nums[j];
                   ans = max(ans,sum);
                   s.insert(nums[j]);
                   j++;
            }
        }
        
        return ans;
    }
    
   ===============================================================================================================================================================
   
   int minimumLength(string s) {
        
        int n = s.length();
        int i = 0;
        //cout << i;
        int j = n - 1;
        //cout << j;
        while(i < j && s[i] == s[j])  //In this case we start rom the two opposite ends and whenever our condition is true we decrement both sides 
        {                             //Either it may be only one time time or multiple times like in this question untill our condition again becomes true 
                                      //Be careful and write both i & j for while loop and also in inner loop still its O(n)
              char c = s[i];
              while(s[i] == c && i <= j) //Be Creful with inner loop while writing two pointers it boils down to n
                    i++;
              while(s[j] == c && j >= i)
                    j--;
                
        }
        
        
        
        return i > j ? 0 : j - i + 1;
    }
    
  ===============================================================================================================================================================
