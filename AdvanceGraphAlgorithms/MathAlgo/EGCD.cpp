int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

//https://leetcode.com/problems/greatest-common-divisor-of-strings/
//https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/ learning gcd of a number and 0 is number itself, and gcd of a number and 1 is 1
//https://leetcode.com/problems/water-and-jug-problem/(Pending)
//https://leetcode.com/problems/nth-magical-number/(Excellent Qyestion Must Do)

______________________________________________________________________________________________________________________________________________________________

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

_______________________________________________________________________________________________________________________________________________________________

int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}
______________________________________________________________________________________________________________________________________________________________
