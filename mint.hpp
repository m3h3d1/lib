pragma once

template <class T, class Op = multiplies<T>>
T power(T a, long long n, Op op = Op(), T e = {1}) { // argument a in mint
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}
template <unsigned M> struct modular {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
  static constexpr unsigned mod = M;
  using m = modular;
  unsigned v;
  modular(long long x = 0) : v((x %= mod) < 0 ? x + mod : x) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m b) { if ((int)(v += b.v - mod) < 0) v += mod; return *this; }
  m& operator-=(m b) { if ((int)(v -= b.v) < 0) v += mod; return *this; }
  m& operator*=(m b) { v = (uint64_t)v * b.v % mod; return *this; }
  m& operator/=(m b) { return *this *= power(b, mod - 2); }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
  friend bool operator!=(m a, m b) { return a.v != b.v; }
  bool operator<(const modular &x) const {
    return v < x.v;
  } // To use std::map<modular, T>
  friend std::istream &operator>>(std::istream &is, modular &x) {
    long long t;
    return is >> t, x = modular(t), is;
  }
  friend std::ostream &operator<<(std::ostream &os, const modular &x) {
    return os << x.v;
  }
#pragma GCC diagnostic pop
};
// using mint = modular<998244353>;
// using mint = modular<1000000007>;