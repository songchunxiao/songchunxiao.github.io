bool isPrime(int x){
    for (int i = 2; i <= (int)sqrt(x); i++)
        if (x % i == 0) return false;
    return true;
}
