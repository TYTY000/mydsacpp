#include "MyString.h"
using namespace std;

MyString:: MyString(){
  str = "";
}

MyString:: ~MyString(){
  str = "";
}

MyString:: MyString(const MyString &str){
  this->str = str.toString();
}

MyString:: MyString(const char* str){
  std::string r = "";
  while(*str != '\0'){
    r += *str;
  }
  this->str = r;
}

MyString:: MyString(std::string str){
  this->str = str;
}

std::string MyString:: toString() const{
  return str;
}

int MyString:: length() const{
  return this->str.length();
}

MyString MyString:: substr(int start, int n) const{
  assert( start < this->str.length());
  n = (n == std::string::npos)? this->str.length() - start : n; 
  return substr(start, n);
}

MyString & MyString::operator=(const MyString &string){
  if (this != &string){
    this->str = string.str;
  }
  return *this;
}

MyString MyString::operator+(const MyString &string) const{
  MyString str1(*this);
  str1 += string;
  return str1;
}

MyString & MyString::operator+=(const MyString &string){
  this->str += string.str;
  return *this;
}

char & MyString:: operator[](int n){
  assert(n < str.length());
  return str[n];
}  

bool operator==(const MyString &str1, const MyString &str2){
  return str1.str == str2.str;
}

bool operator!=(const MyString &str1, const MyString &str2){
  return str1.str != str2.str;
}

bool operator<=(const MyString &str1, const MyString &str2){
  return str1.str <= str2.str;
}

bool operator>=(const MyString &str1, const MyString &str2){
  return str2.str <= str1.str;
}

bool operator>(const MyString &str1, const MyString &str2){
  return str1.str > str2.str;
}

bool operator<(const MyString &str1, const MyString &str2){
  return str2.str < str1.str;
}

std::ostream & operator<<(std::ostream &os, MyString & string){
  os << string.toString();
  return os;
}
