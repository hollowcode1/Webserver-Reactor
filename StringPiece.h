#pragma once
#include <string.h>
#include <iosfwd>
#include <string>

class StringPiece {

 public:
StringPiece()
    : ptr_(NULL), length_(0) { }
  StringPiece(const char* str)
    : ptr_(str), length_(static_cast<int>(strlen(ptr_))) { }
  StringPiece(const unsigned char* str)
    : ptr_(reinterpret_cast<const char*>(str)),
      length_(static_cast<int>(strlen(ptr_))) { }
  StringPiece(const std::string& str)
    : ptr_(str.data()), length_(static_cast<int>(str.size())) { }
  StringPiece(const char* offset, int len)
    : ptr_(offset), length_(len) { }


 std::string as_string() const {
    return std::string(data(), size());
  }
  const char* data() const { return ptr_; }
  int size() const { return length_; }
  
private:
  const char*   ptr_;
  int           length_;
  
};