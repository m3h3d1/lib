typedef int64_t ll;
typedef uint64_t ull;

ull mul(ull a, ull b, ull M) {
    ll r = a * b - M * ull(1.L / M * a * b);
    return r + M * ((r < 0) - (r >= (ll) M));
}
ull mow(ull x, ull e, ull M) {
    ull r = 1;
    for (; e; x = mul(x, x, M), e >>= 1)
        if (e & 1) r = mul(r, x, M);
    return r;
}

bool isPrime(ull n) {
    if (n < 2 or n % 6 % 4 != 1) return (n | 1) == 3;
    static const ull A[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
    ull s = __builtin_ctzll(n - 1), d = n >> s;
    for (const ull& a: A) {
        ull p = mow(a % n, d, n), i = s;
        while (p != 1 and p != n - 1 and a % n != 0 and i--)
            p = mul(p, p, n);
        if (p != n - 1 and i != s) return false;
    }
    return true;
}

ull pollard(ull n) {
    static mt19937_64 mt((unsigned)chrono::system_clock::now().time_since_epoch().count());
    static ull c = 1;
    auto f = [&](ull x) { return mul(x, x, n) + c; };
    ull x = 0, y = 0, t = 40, p = 2, q, i = 2;
    while (t++ % 30 or gcd(p, n) == 1) {
        if (x == y) c = mt() % (n - 1) + 1, y = f(x = ++i);
        if (q = mul(p, (x > y ? x - y : y - x), n)) p = q;
        x = f(x); y = f(f(y));
    }
    return gcd(p, n);
}

void factor(ull n, vector<ull>& f) {
    if (n == 1) return;
    if (isPrime(n)) {
        f.push_back(n);
        return;
    }
    ull x = pollard(n);
    factor(x, f);
    factor(n / x, f);
    return;
}