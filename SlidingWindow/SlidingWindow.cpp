/*Step1: Have a counter or hash-map to count specific array input and keep on increasing the window toward right using outer loop.
Step2: Have a while loop inside to reduce the window side by sliding toward right. Movement will be based on constraints of problem. Go through few examples below
Step3: Store the current maximum window size or minimum window size or number of windows based on problem requirement.*/

=======================================================================================================================================================

class Solution {
		public:
			int longestOnes(vector<int>& A, int K) {
				
				int count = 0, i = 0, j = 0;
				int res = INT_MIN;
				
				for (i = 0; i < A.size(); i++) {
					if (A[i] == 0) count++;  /* have some hashmap or counter */
					
					/* Loop inside for to reduce the window size based on constraint */
					while (count > K && j < A.size()) {
						if (A[j] == 0)
							count--;
						j++;
					}
					
					/* get the maximum value of the window which satisfies the constraint */
					res = max(res, i-j+1);
				}
				
				return res == INT_MIN ? ((count <= K) ? A.size() : 0) : res;
			}
		};
    
    //Counter Based 
    
    ==========================================================================================================================================================
    
    class Solution {
		public:
			int numberOfSubstrings(string s) {
				
				int n = s.length();
				
				vector<int>count = {0, 0, 0};
				int i = 0, j = 0, res = 0, ans = 0;
				
				for (i = 0; i < n; i++) {
					count[s[i]-'a']++;     /* have some hashmap or counter */
					
					/* Loop inside for to reduce the window size based on constraint */
					while (j < n && count[0] && count[1] && count[2]) {
						ans++;
						count[s[j]-'a']--;
						j++;
					}
					
					/* Count number of substrings */
					res += ans;
				}
				
				return res;
			}
};

//HahMap Based Implementation 

=================================================================================================================================================================

int n = tree.size();
				unordered_map<int, int>hm;
				
				int i = 0, j = 0, res = 0;
				for (i = 0; i < n; i++) {
                    
					hm[tree[i]]++; /* have some hashmap or counter */
					
					/* Loop inside for to reduce the window size based on constraint */
					while (j < n && hm.size() > 2) {
						hm[tree[j]]--;
						if (hm[tree[j]] == 0)
							hm.erase(tree[j]);
						j++;
                        
					}
					/* get the maximum value of the window which satisfies the constraint */
					res = max(res, i-j+1);
				}

				return res;
        
 ===============================================================================================================================================================
    
