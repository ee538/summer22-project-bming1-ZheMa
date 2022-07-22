#include <iostream>
#include "src/lib/trojanmap.h"
#include "src/lib/mapui.h"
using namespace std;
// #define NCURSES

/*int main() {
  MapUI x;
  #ifdef NCURSES
    x.PlotMap();
    x.DynamicPrintMenu();
  #else
    x.PlotMap();
    x.PrintMenu();
  #endif
  return 0;
}*/

int main() {
  TrojanMap m;
  std::vector<std::string> Categories1;
  //m.CreateGraphFromCSVFile();

  auto result = m.FindClosestName("Rophs");
  //  Categories1 = m.GetAllCategories();
  //  for (auto &i : Categories1 )
  //  {
  //    std::cout << "Value of str is : " << i << std::endl;
  //  }
  

  return 0;
}
