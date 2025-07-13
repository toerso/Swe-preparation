/*Given a dictionary of words sorted in non-decreasing order. Ex. [”a”, “ac”, “b”, … “o”, “p”, … “x”, “y”, “z”].
Due to some malfunction, the dictionary has become like this [“p”, … “x”, “y”, “z”, ”a”, “ac”, “b”, … “o” ].
Now write a program to search for a word in the dictionary so that the search complexity is same as the original dictionary.*/


#include <iostream>
#include <vector>
#include <string>

bool search(std::vector<std::string>& dict, std::string needle) {
   int lo = 0, hi = dict.size() - 1;

   while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;

      if (dict[mid] == needle) return true;

      if (dict[lo] <= dict[mid]) {
         if (dict[lo] <= needle and dict[mid] > needle) hi = mid - 1;
         else lo = mid + 1;
      }else {
         if (dict[mid] < needle and dict[hi] >= needle) lo = mid += 1;
         else hi = mid - 1;
      }
   }

   return false;
}

int main() {
   std::vector<std::string> dict = {"p", "q", "r", "s", "x", "y", "z", "a", "ac", "b", "c", "d", "e", "f", "o"};
   std::cout << search(dict, "ad") << "\n";

   return 0;
}
