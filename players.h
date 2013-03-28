

#include <monopoly.h>
#include <string>
#include <vector>

class players{
 public:
  players();  
  void printCash();
  void addCash(int);
  void useCash();
  bool inJail();
  void setName(string);
  string getName();
  bool isComputer();
  void addProperties(std::string);//add each property to the property
  
 private:
  int cash; 
  std::string Name;
  std::vector<std::string> properties;
  int position;
  ]
