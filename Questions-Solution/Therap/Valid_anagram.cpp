#include <iostream>
#include <array>
#include <algorithm>
#include <string>

bool isAnagram(std::string& s, std::string& t) {
   int n = s.size(), m = t.size();

   if (std::abs(n - m) > 1) return false;

   std::array<int, 26> freq;
   freq.fill(0);

   if (m > n) swap(s, t);

   for (char ch: s) {
      freq[ch - 'a']++;
   }

   for (char ch: t) {
      if (--freq[ch - 'a'] < 0) return false;
   }

   return true;
}

int main() {
   std::string s = "anagram", t = "nagrama";

   std::cout << isAnagram(s, t) << "\n";

   return 0;
}
