 vector<int> res(n+1,0);
        
        
        for(auto &b:bookings)
        {
            res[b[0] - 1] += b[2];
            res[b[1]] -= b[2];
        }
        
        for(int i = 0;i < n;i++)
        {
            res[i] += res[i-1];
        }
        
        return {res.begin(),res.end()-1};


Original prefix sum easy but this onre what you have to do is that take each array and if u want to perform queries on them in a range 1 to 10 like sum then
forth 1st one do the sum and afterwards to the last one -10 so that while calculating thr prefix sum the sum gets vanished after the last number.
__________________________________________________________________________________________________________________________________________________________________
