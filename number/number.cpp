#include "number.h"

/// 1. Constructors

number_t::number_t()
    : _data(0)
{}

number_t::number_t(const number_t& other) = default;

number_t::number_t(const int_fast64_t num)
    : _data(num)
{}

/// 2. Assignment operators

number_t& number_t::operator =(const number_t& other)
{
  if (this == &other)
    return *this;

  _data = other._data;
  return *this;
}
number_t& number_t::operator =(const int_fast64_t num)
{
  _data = num;
  return *this;
}

number_t& number_t::operator +=(const number_t& other)
{
  _data += other._data;
  return *this;
}
number_t& number_t::operator -=(const number_t& other)
{
  _data -= other._data;
  return *this;
}
number_t& number_t::operator *=(const number_t& other)
{
  _data *= other._data;
  return *this;
}
number_t& number_t::operator /=(const number_t& other)
{
  _data /= other._data;
  return *this;
}
number_t& number_t::operator %=(const number_t& other)
{
  _data %= other._data;
  return *this;
}

number_t& number_t::operator &=(const number_t& other)
{
  _data &= other._data;
  return *this;
}
number_t& number_t::operator ^=(const number_t& other)
{
  _data ^= other._data;
  return *this;
}
number_t& number_t::operator |=(const number_t& other)
{
  _data |= other._data;
  return *this;
}
number_t& number_t::operator <<=(const number_t& other)
{
  _data <<= other._data;
  return *this;
}
number_t& number_t::operator >>=(const number_t& other)
{
  _data >>= other._data;
  return *this;
}

/// 3. Cast operators

number_t::operator bool() const
{
  return static_cast<bool>(_data);
}

number_t::operator int_fast64_t() const
{
  return _data;
}

number_t::operator std::string() const
{
  return std::to_string(_data);
}

/// 4. Binary arithmetic and bitwise operators

number_t operator +(const number_t& lhs, const number_t& rhs)
{
  return lhs._data + rhs._data;
}
number_t operator -(const number_t& lhs, const number_t& rhs)
{
  return operator+( lhs._data, (-rhs._data) );
}
number_t operator *(const number_t& lhs, const number_t& rhs)
{
  return lhs._data * rhs._data;
}
number_t operator /(const number_t& lhs, const number_t& rhs)
{
  return lhs._data / rhs._data;
}
number_t operator %(const number_t& lhs, const number_t& rhs)
{
  return lhs._data % rhs._data;
}

number_t operator &(const number_t& lhs, const number_t& rhs)
{
  return lhs._data & rhs._data;
}
number_t operator ^(const number_t& lhs, const number_t& rhs)
{
  return lhs._data ^ rhs._data;
}
number_t operator |(const number_t& lhs, const number_t& rhs)
{
  return lhs._data | rhs._data;
}
number_t operator <<(const number_t& lhs, const number_t& rhs)
{
  return lhs._data << rhs._data;
}
number_t operator >>(const number_t& lhs, const number_t& rhs)
{
  return lhs._data >> rhs._data;
}

/// 5. Unary operators

number_t number_t::operator -() const
{
  return { -_data };
}
number_t number_t::operator +() const
{
  return *this;
}
number_t number_t::operator ~() const
{
  return { ~_data };
}
number_t number_t::operator !() const
{
  return { !_data };
}

/// 6. Increment and decrement operators

number_t& number_t::operator ++()
{
  ++_data;
  return *this;
}
number_t number_t::operator ++(int)
{
  number_t old = *this;
  ++_data;
  return old;
}
number_t& number_t::operator --()
{
  --_data;
  return *this;
}
number_t number_t::operator --(int)
{
  number_t old = *this;
  --_data;
  return old;
}

/// 7. Comparison operators

bool operator ==(const number_t& lhs, const number_t& rhs)
{
  return lhs._data == rhs._data;
}
bool operator !=(const number_t& lhs, const number_t& rhs)
{
  return !operator==(lhs, rhs);
}
bool operator <(const number_t& lhs, const number_t& rhs)
{
  return lhs._data < rhs._data;
}
bool operator >(const number_t& lhs, const number_t& rhs)
{
  return rhs._data < lhs._data;
}
bool operator <=(const number_t& lhs, const number_t& rhs)
{
  return !operator<(rhs, lhs);
}
bool operator >=(const number_t& lhs, const number_t& rhs)
{
  return !operator<(lhs, rhs);
}

/// 8. Stream insertion and extraction operators

std::istream& operator >>(std::istream& in, number_t& num)
{
  return in >> num._data;
}
std::ostream& operator <<(std::ostream& out, const number_t& num)
{
  return out << num._data;
}
