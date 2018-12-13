def quick_pow(a, n, mod):
    ans = 1
    while(n!=0):
        if(n%2==1):
            ans = ans*a%mod
        a = a*a%mod
        n = n // 2
    return ans

if __name__ == '__main__':
    n, k, mod = raw_input().strip().split()
    n = long(n)
    k = long(k)
    mod = long(mod)
    print quick_pow(k, n, mod)

