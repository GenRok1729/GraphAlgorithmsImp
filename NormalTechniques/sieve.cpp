// Function to check if a number
// is prime or not.
bool is_prime(int n)
{
    if (n <= 1)
        return 0;
 
    for (int i = 2; i * i <= n; i++) {
 
        // If n has any factor other than 1,
        // then n is non-prime.
        if (n % i == 0)
            return 0;
    }
 
    return 1;
