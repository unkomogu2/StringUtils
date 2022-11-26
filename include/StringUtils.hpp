#pragma once

#include <string>
#include <vector>

inline char toLower(char c) { return 'A' <= c && c <= 'Z' ? c + 'a' - 'A' : c; }
inline char toUpper(char c) { return 'a' <= c && c <= 'z' ? c - 'a' - 'A' : c; }
inline bool isAlpha(char c) {
  return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}
inline bool isNonZeroDigit(char c) { return '1' <= c && c <= '9'; }
inline bool isDigit(char c) { return '0' == c || isNonZeroDigit(c); }
inline bool isCR(char c) { return c == '\r'; }
inline bool isLF(char c) { return c == '\n'; }
inline bool isCrlf(char c) { return isCR(c) || isLF(c); }
inline bool isSpace(char c) { return c == ' ' || c == '\t'; }
inline bool isLetter(char c) { return isAlpha(c) || isDigit(c) || c == '_'; }

std::vector<std::string> split(const std::string& s, const std::string& d) {
  if (s.empty()) return {};
  auto ret = std::vector<std::string>{};
  size_t p1 = 0, p2 = std::string::npos;
  while ((p2 = s.find(d, p1)) != std::string::npos) {
    ret.emplace_back(s.begin() + p1, s.begin() + p2);
    p1 = p2 + d.size();
  }
  ret.emplace_back(s.begin() + p1, s.end());
  return ret;
}

std::string extensionOf(const std::string& path) {
  auto v = split(path, ".");
  if (v.empty()) return "";
  return v.back();
}

std::string toLower(const std::string& s) {
  auto ret = std::string{};
  for (const auto c : s) ret += toLower(c);
  return ret;
}

std::string toUpper(const std::string& s) {
  auto ret = std::string{};
  for (const auto c : s) ret += toUpper(c);
  return ret;
}

std::string trimLeft(const std::string& s) {
  auto first = s.begin(), last = s.end();
  while (isSpace(*first) && first != last) {
    ++first;
  }
  return {first, last};
}

std::string trimRight(const std::string& s) {
  auto first = s.begin(), last = first + s.size() - 1;
  while (isSpace(*last) && first != last) {
    --last;
  }
  return {first, last + 1};
}

std::string trim(const std::string& s) { return trimLeft(trimRight(s)); }

std::string repeat(char c, size_t n) { return std::string(n, c); }