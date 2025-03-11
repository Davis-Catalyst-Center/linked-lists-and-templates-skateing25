#include <iostream>
#include "student_Group.hpp"

using namespace std;


int main() {
  student_Group Group;
 student_member* member1 = new student_member("John", 1);
  std:: cout << "Is the group empty" << (Group.isEmpty() ? "yes" : "no") << std:: endl;
 Group.addMember(member1);
  cout << member1;
  cout << "hi";
  return 0;
}