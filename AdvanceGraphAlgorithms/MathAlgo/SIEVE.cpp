int n;
vector<int> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}

//O(n log(logn))
//Space O(n)

__________________________________________________________________________________________________________________________________________________________________

int n;
vector<char> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
//Further add why only till sqrt(n)

_________________________________________________________________________________________________________________________________________________________________

long long int fact(long long int n){
        if(n==1) return 1;
        return (n%m*fact(n-1)%m)%m;
    }
  
//To calculate factorial of a number 
