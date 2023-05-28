#ifndef _MYSTRING_
#define _MYSTRING_

#include <string>
#include <iostream>
#include <cassert>

class MyString{
  private:
    std::string str;

  public:
    MyString();
    ~MyString();
    MyString(const MyString &str);
    MyString(const char* str);
    MyString(std::string str);
    std::string toString() const;
    int length() const;

    MyString substr(int start, int n) const;
    MyString operator+(const MyString &str) const;
    MyString & operator+=(const MyString &str);
    MyString & operator=(const MyString &str);
    
    char & operator[](int n);  // error
    
    friend bool operator==(const MyString &str1, const MyString &str2);
    friend bool operator!=(const MyString &str1, const MyString &str2);
    friend bool operator<=(const MyString &str1, const MyString &str2);
    friend bool operator>=(const MyString &str1, const MyString &str2);
    friend bool operator>(const MyString &str1, const MyString &str2);
    friend bool operator<(const MyString &str1, const MyString &str2);
    friend std::ostream & operator<<(std::ostream &os, MyString & str);
};

  bool operator==(const MyString &str1, const MyString &str2);
  bool operator!=(const MyString &str1, const MyString &str2);
  bool operator<=(const MyString &str1, const MyString &str2);
  bool operator>=(const MyString &str1, const MyString &str2);
  bool operator>(const MyString &str1, const MyString &str2);
  bool operator<(const MyString &str1, const MyString &str2);
  std::ostream & operator<<(std::ostream &os, MyString & str);
#endif
