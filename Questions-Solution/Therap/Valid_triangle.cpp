//Given a 2D matrix where each row represents three sides of a triangle.
//Check if they form a valid triangle or not. Return an array containing “yes” or “no” representing the results of each row.

#include <iostream>
#include <vector>
#include <string>

int main(void) {
   std::vector<std::vector<int>> cord = {{3, 4, 5},
        {1, 10, 12},
        {5, 5, 5},
        {1, 2, 3},     // invalid: 1 + 2 == 3
        {7, 10, 5}};

   std::vector<std::string> ans;

   int n = cord.size();

   for (int i = 0; i < n; ++i) {
      int a = cord[i][0], b = cord[i][1], c = cord[i][2];

      if ((a + b > c) and  (a + c > b) and  (b + c > a)) ans.emplace_back("yes");
      else ans.emplace_back("no");
   }

   for (std::string& str: ans) std::cout << str << "\n";

   return 0;
}
