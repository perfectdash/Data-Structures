#include <bits/stdc++.h>
using namespace std;

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