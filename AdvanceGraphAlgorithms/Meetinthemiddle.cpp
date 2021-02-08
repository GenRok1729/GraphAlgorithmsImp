vector<int> v1;
        vector<int> v2;
        
        int n = nums.size()/2;
        
        for(int i = 0;i < n;i++)
        {
            v1.push_back(nums[i]);
        }
        
        for(int i = n;i < nums.size();i++)
        {
            v2.push_back(nums[i]);
        }
        
        int n1 = v1.size();
        
        vector<int> suma;
        for(int i = 0;i < (1 << n1);i++)
        {
            
            int sum = 0 ;
            //cout << sum << i << '\n';
            for(int j = 0;j  < n1;j++)
            {
                if(i & (1 << j))
                {
                      sum += v1[j];
                }
            }
            //cout << sum << '\n';
            suma.push_back(sum);
        }
        
        //cout << 10000;
        
        int n2 = v2.size();
        vector<int> sumb;
        for(int i = 0;i < (1 << n2);i++)
        {
            
            int sum = 0 ;
            //cout << sum << i << '\n';
            for(int j = 0;j  < n2;j++)
            {
                if(i & (1 << j))
                {
                      sum += v2[j];
                }
            }
            //cout << sum << '\n';
            sumb.push_back(sum);
        }
        
        
        //cout << 1000;
        
        sort(suma.begin(),suma.end());
        
        sort(sumb.begin(),sumb.end());
        
        int t = suma.size();
        
        int mini = INT_MAX;
        
        //cout <<  t;
        
        int ans = (int)1e9;
        
        
        
        for(int i = 0;i < t;i++)
        {
            int tofind = goal - suma[i];            
            auto itr  = lower_bound(sumb.begin(), sumb.end(), tofind);
            if(itr != sumb.end())ans = min(ans, abs(*itr - tofind));
            if(itr != sumb.begin())
            {   itr--;
            }
            ans = min(ans, abs(*itr - tofind));
        }
        
        return ans;
//https://leetcode.com/problems/closest-subsequence-sum/
