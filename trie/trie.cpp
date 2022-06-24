#include "trie.h"

#include <queue> // For BFS implementation

/// Constructors

trie_t::trie_t()
    : _size(0)
    , _endCnt(0)
{}

trie_t::~trie_t() = default;

trie_t::trie_t(const trie_t& other) = default;

trie_t& trie_t::operator =(const trie_t& other) = default;

/// Modifier methods

void trie_t::insert(const std::string& str)
{
  trie_t* root = this;

  for (const char& c : str)
  {
    ++root->_size;

    auto itChild = root->_descendantsDict.find(c);
    if (itChild == root->_descendantsDict.end() )
      itChild = root->_descendantsDict.insert( std::make_pair( c, trie_t() ) ).first;

    root = &itChild->second;
  }

  ++root->_size;
  ++root->_endCnt;
}

void trie_t::clear()
{
  _size   = 0;
  _endCnt = 0;
  _descendantsDict.clear();
}

bool trie_t::erase(const std::string& str)
{
  std::vector<trie_t*> path;
  path.push_back(this);

  for (const char& c: str)
  {
    auto itChild = path.back()->_descendantsDict.find(c);
    if ( itChild == path.back()->_descendantsDict.end() )
      return false;

    path.push_back(&itChild->second);
  }

  if (!path.back()->_endCnt)
    return false;

  --path.back()->_endCnt;
  --path.back()->_size;

  path.pop_back();

  for ( ; !path.empty(); path.pop_back() )
  {
    --path.back()->_size;

    auto itChild = path.back()->_descendantsDict.find( str[path.size() - 1] );
    if (!itChild->second._size)
      path.back()->_descendantsDict.erase(itChild);
  }

  return true;
}

/// Lookup methods

bool trie_t::find(const std::string& str) const
{
  auto tmpRoot = _reach(str);
  return tmpRoot && tmpRoot->_endCnt > 0;
}

size_t trie_t::count_with_prefix(const std::string& prefix) const
{
  auto tmpRoot = _reach(prefix);
  return tmpRoot ? tmpRoot->_size : 0;
}

/// Access operator

std::string trie_t::operator [](size_t index) const
{
  assert(index < _size);

  const trie_t* root = this;
  std::string result;

  while (root)
  {
    if (index < root->_endCnt)
      break;
    index -= root->_endCnt;

    auto tmp = root;
    root = nullptr;

    for (const auto& [c, next]: tmp->_descendantsDict)
    {
      if (index < next._size)
      {
        root = &next;
        result += c;
        break;
      }

      index -= next._size;
    }
  }

  return result;
}

/// Cast method

std::vector<std::string> trie_t::to_vector() const
{
  std::vector<std::string> result(_size);
  std::queue<std::pair<const trie_t&, size_t>> q;

  for ( q.emplace(*this, 0); !q.empty(); q.pop() )
  {
    auto [tmp, idBegin] = q.front();
    idBegin += tmp._endCnt;

    for (const auto& [c, next_root]: tmp._descendantsDict)
    {
      q.emplace(next_root, idBegin);

      for (size_t i = 0; i < next_root._size; ++i)
        result[idBegin++] += c;
    }
  }

  return result;
}

/// Getters

size_t trie_t::size() const { return _size; }

bool trie_t::empty() const { return !_size; }

/// Other methods

void trie_t::swap(trie_t& other)
{
  std::swap(_size,            other._size);
  std::swap(_endCnt,          other._endCnt);
  std::swap(_descendantsDict, other._descendantsDict);
}

const trie_t* trie_t::_reach(const std::string& str) const
{
  const trie_t* root = this;

  for (const char& c: str)
  {
    auto itChild = root->_descendantsDict.find(c);
    if ( itChild == root->_descendantsDict.end() )
      return nullptr;

    root = &itChild->second;
  }

  return root;
}
