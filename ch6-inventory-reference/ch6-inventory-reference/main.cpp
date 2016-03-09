#include <iostream>
#include <string>
#include <vector>

using namespace std;

string& refToElement(vector<string>& inventory, int i);

int main() {
  vector<string> inventory;

  inventory.push_back("sword");
  inventory.push_back("armor");
  inventory.push_back("shield");

  //displays string that the returned reference refers to
  cout << "sending the returned reference to cout: \n";
  cout << refToElement(inventory, 0) << "\n\n";

  // assign one refenrece to another -- inexpensiveness assignment
  cout << "assigning the returned reference to another reference. \n";
  string& rStr = refToElement(inventory, 1);
  cout << "sending the new reference to cout: \n";
  cout << rStr << "\n\n";

  // altering the string object through a returned reference
  cout << "Altering an object through a returned reference.\n";
  rStr = "Healing Potion";
  cout << "Sending the altered object to cout: \n";
  cout << inventory[1] << endl;

  return 0;
}

string& refToElement(vector<string>& vec, int i) {
  return vec[i];
}