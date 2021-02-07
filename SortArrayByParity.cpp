for (int i = 0, j = 1; j < A.size() && i < A.size();)
{ 
      if (A[i] % 2 == 0) 
        { i += 2; } 
      else if (A[j] % 2 == 1) 
        { j += 2; } 
     else 
        { swap(A[i], A[j]); }
        
} 


return A;
