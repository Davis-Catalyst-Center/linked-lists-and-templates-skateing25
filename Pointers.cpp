#include <iostream>
#include <string>
#include "student.h"
using namespace std;




int main() {
 student* student1 = new student("John", 20, 'A');
  cout << *student1 << endl;
  cout << student1;
  return 0;
}