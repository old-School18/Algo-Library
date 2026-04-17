// Time Complexity => O(n log log n)
// Memory Complexity => O(n)
// Determine prime numbers from 1 to n.

void sieveOfEratosthenes(ll n)
{
    vector<char> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (ll i = 4; i <= n; i += 2) 
    {
        isPrime[i]=0;
    }
    for (ll i = 3; i * i <= n; i += 2)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j <= n; j += 2*i)
            {
                isPrime[j] = 0;
            }
        }
    }

    return;
}

-----------------------------------
Note:  
Use vector<char> for time efficiency and vector<bool> for memory efficiency. 
vector<bool> operates at bit level rather than bytes so 1 element will occupy only 1 bit instead of a byte that a typical boolean variables does. So, this is memory efficient
