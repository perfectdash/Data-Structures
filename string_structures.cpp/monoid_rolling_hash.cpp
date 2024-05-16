#include <bits/stdc++.h>
using namespace std;

using u64 =unsigned long long;

struct modint61 {
  static constexpr bool is_modint = true;
  static constexpr long long mod = (1LL << 61) - 1;
  long long val;
  constexpr modint61(const long long val = 0) : val(val) {}
  bool operator<(const modint61 &other) const {
    return val < other.val;
  } // To use std::map
  bool operator==(const modint61 &p) const { return val == p.val; }
  bool operator!=(const modint61 &p) const { return val != p.val; }
  modint61 &operator+=(const modint61 &p) {
    if ((val += p.val) >= mod) val -= mod;
    return *this;
  }
  modint61 &operator-=(const modint61 &p) {
    if ((val += mod - p.val) >= mod) val -= mod;
    return *this;
  }
  modint61 &operator*=(const modint61 &p) {
    long long a = val, b = p.val;
    const long long MASK30 = (1LL << 30) - 1;
    const long long MASK31 = (1LL << 31) - 1;
    const long long MASK61 = (1LL << 61) - 1;
    long long au = a >> 31, ad = a & MASK31;
    long long bu = b >> 31, bd = b & MASK31;
    long long x = ad * bu + au * bd;
    long long xu = x >> 30, xd = x & MASK30;
    x = au * bu * 2 + xu + (xd << 31) + ad * bd;
    xu = x >> 61, xd = x & MASK61;
    x = xu + xd;
    if (x >= MASK61) x -= MASK61;
    val = x;
    return *this;
  }
  modint61 &operator/=(const modint61 &p) {
    *this *= p.inverse();
    return *this;
  }
  modint61 operator+(const modint61 &p) const { return modint61(*this) += p; }
  modint61 operator-(const modint61 &p) const { return modint61(*this) -= p; }
  modint61 operator*(const modint61 &p) const { return modint61(*this) *= p; }
  modint61 operator/(const modint61 &p) const { return modint61(*this) /= p; }
 
  modint61 inverse() const {
    long long a = val, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b), swap(u -= t * v, v);
    }
    return modint61(u);
  }
  modint61 pow(int64_t n) const {
    modint61 ret(1), mul(val);
    while (n > 0) {
      if (n & 1) ret = ret * mul;
      mul = mul * mul;
      n >>= 1;
    }
    return ret;
  }
  static constexpr long long get_mod() { return mod; }
};

struct RandomNumberGenerator {
   mt19937 mt;
 
  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
 
  long long operator()(long long a, long long b) {  // [a, b)
    uniform_int_distribution<long long> dist(a, b - 1);
    return dist(mt);
  }
 
  long long operator()(long long b) {  // [0, b)
    return (*this)(0, b);
  }
};



struct Monoid_Rolling_Hash {
  using value_type = pair<modint61, modint61>;
  using X = value_type;
 
  static u64& base() {
    static u64 x = 0;
    while (x == 0) {
      RandomNumberGenerator RNG;
      x = RNG(modint61::get_mod());
    }
    return x;
  }
  static X from_element(u64 x) { return {base(), x}; }
  static X op(X x, X y) { return {x.first * y.first, x.second * y.first + y.second}; }
  static constexpr X unit() { return {1, 0}; }
  static constexpr bool commute = false;
};


// pow of base, val
struct Monoid_Rolling_Hash {
  using value_type = pair<modint61, modint61>;
  using X = value_type;
 
  static u64& base() {
    static u64 x = 0;
    while (x == 0) {
      RandomNumberGenerator RNG;
      x = RNG(modint61::get_mod());
    }
    return x;
  }
  static X from_element(u64 x) { return {base(), x}; }
  static X op(X x, X y) { return {x.fi * y.fi, x.se * y.fi + y.se}; }
  static constexpr X unit() { return {1, 0}; }
  static constexpr bool commute = false;
};
#line 2 "/home/maspy/compro/library/ds/segtree.hpp"
 
template <class Monoid>
struct SegTree {
  using X = typename Monoid::value_type;
  using value_type = X;
  vector<X> dat;
  int n, log, size;
 
  SegTree() : SegTree(0) {}
  SegTree(int n) : SegTree(vector<X>(n, Monoid::unit())) {}
  SegTree(vector<X> v) : n(v.size()) {
    log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    dat.assign(size << 1, Monoid::unit());
    for (int i = 0; i < n; ++i) dat[size + i] = v[i];
    for (int i = size - 1; i >= 1; --i) update(i);
  }
 
  template <typename F>
  SegTree(int n, F f) : n(n) {
    log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    dat.assign(size << 1, Monoid::unit());
    for (int i = 0; i < n; ++i) dat[size + i] = f(i);
    for (int i = size - 1; i >= 1; --i) update(i);
  }
 
  void reset() { fill(all(dat), Monoid::unit()); }
 
  void set_all(const vector<X>& v) {
    dat.assign(size << 1, Monoid::unit());
    for (int i = 0; i < n; ++i) dat[size + i] = v[i];
    for (int i = size - 1; i >= 1; --i) update(i);
  }
 
  X operator[](int i) { return dat[size + i]; }
 
  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i + 1]); }
 
  void set(int i, const X& x) {
    assert(i < n);
    dat[i += size] = x;
    while (i >>= 1) update(i);
  }
 
  void multiply(int i, const X& x) {
    assert(i < n);
    i += size;
    dat[i] = Monoid::op(dat[i], x);
    while (i >>= 1) update(i);
  }
 
  X prod(int L, int R) {
    assert(L <= R);
    assert(R <= n);
    X vl = Monoid::unit(), vr = Monoid::unit();
    L += size, R += size;
    while (L < R) {
      if (L & 1) vl = Monoid::op(vl, dat[L++]);
      if (R & 1) vr = Monoid::op(dat[--R], vr);
      L >>= 1, R >>= 1;
    }
    return Monoid::op(vl, vr);
  }
 
  X prod_all() { return dat[1]; }
 
  template <class F>
  int max_right(F& check, int L) {
    assert(0 <= L && L <= n && check(Monoid::unit()));
    if (L == n) return n;
    L += size;
    X sm = Monoid::unit();
    do {
      while (L % 2 == 0) L >>= 1;
      if (!check(Monoid::op(sm, dat[L]))) {
        while (L < size) {
          L = 2 * L;
          if (check(Monoid::op(sm, dat[L]))) {
            sm = Monoid::op(sm, dat[L]);
            L++;
          }
        }
        return L - size;
      }
      sm = Monoid::op(sm, dat[L]);
      L++;
    } while ((L & -L) != L);
    return n;
  }
 
  template <class F>
  int min_left(F& check, int R) {
    assert(0 <= R && R <= n && check(Monoid::unit()));
    if (R == 0) return 0;
    R += size;
    X sm = Monoid::unit();
    do {
      --R;
      while (R > 1 && (R % 2)) R >>= 1;
      if (!check(Monoid::op(dat[R], sm))) {
        while (R < size) {
          R = 2 * R + 1;
          if (check(Monoid::op(dat[R], sm))) {
            sm = Monoid::op(dat[R], sm);
            R--;
          }
        }
        return R + 1 - size;
      }
      sm = Monoid::op(dat[R], sm);
    } while ((R & -R) != R);
    return 0;
  }
 
  // モノイドが可換なら、prod_{l<=i<r}A[i^x] が計算可能
  // https://codeforces.com/contest/1401/problem/F
  X Xor_prod(int l, int r, int xor_val) {
    assert(Monoid::commute);
    X x = Monoid::unit();
    for (int k = 0; k < log + 1; ++k) {
      if (l >= r) break;
      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++) ^ xor_val)]); }
      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r) ^ xor_val)]); }
      l /= 2, r /= 2, xor_val /= 2;
    }
    return x;
  }
 
  void debug() { print("segtree", dat); }
};