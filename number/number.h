#pragma once

#include <cstdint>
#include <iostream>

class number_t {
public:
  number_t();
  number_t(const number_t& other);
  number_t(int_fast64_t    num);   // NOLINT (suppress implicit conversion warning)

  number_t& operator =(const number_t& other);
  number_t& operator =(int_fast64_t    num);

  number_t& operator +=(const number_t& other);
  number_t& operator -=(const number_t& other);
  number_t& operator *=(const number_t& other);
  number_t& operator /=(const number_t& other);
  number_t& operator %=(const number_t& other);

  number_t& operator &=(const number_t& other);
  number_t& operator ^=(const number_t& other);
  number_t& operator |=(const number_t& other);
  number_t& operator <<=(const number_t& other);
  number_t& operator >>=(const number_t& other);

  explicit operator bool        () const;
  explicit operator int_fast64_t() const;
  explicit operator std::string () const;

  friend number_t operator +(const number_t& lhs, const number_t& rhs);
  friend number_t operator -(const number_t& lhs, const number_t& rhs);
  friend number_t operator *(const number_t& lhs, const number_t& rhs);
  friend number_t operator /(const number_t& lhs, const number_t& rhs);
  friend number_t operator %(const number_t& lhs, const number_t& rhs);

  friend number_t operator &(const number_t& lhs, const number_t& rhs);
  friend number_t operator ^(const number_t& lhs, const number_t& rhs);
  friend number_t operator |(const number_t& lhs, const number_t& rhs);

  friend number_t operator <<(const number_t& lhs, const number_t& rhs);
  friend number_t operator >>(const number_t& lhs, const number_t& rhs);

  number_t operator -() const;
  number_t operator +() const;
  number_t operator ~() const;
  number_t operator !() const;

  number_t& operator ++();
  number_t  operator ++(int);
  number_t& operator --();
  number_t  operator --(int);

  friend bool operator ==(const number_t& lhs, const number_t& rhs);
  friend bool operator !=(const number_t& lhs, const number_t& rhs);
  friend bool operator < (const number_t& lhs, const number_t& rhs);
  friend bool operator > (const number_t& lhs, const number_t& rhs);
  friend bool operator <=(const number_t& lhs, const number_t& rhs);
  friend bool operator >=(const number_t& lhs, const number_t& rhs);

  friend std::istream& operator >>(std::istream&, number_t&);
  friend std::ostream& operator <<(std::ostream&, const number_t&);

private:
  int_fast64_t _data;
};
