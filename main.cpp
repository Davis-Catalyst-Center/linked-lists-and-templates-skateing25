#include <iostream>
#include "student_Group.hpp"

using namespace std;


int main() {
  student_Group Group;
  student_member *member1 = new student_member("John", 1);
  student_member *member2 = new student_member("Jane", 2);
  student_member *member3 = new student_member("Mike", 3);
  student_member *member4 = new student_member("Sarah", 4);
  std::cout << "Is the Group empty " << (Group.isEmpty() ? "yes" : "no")
            << std::endl;
  std::cout << "Initial Group size: " << Group.size() << std::endl;
  std::cout << Group.printGroup() << std::endl;

  Group.addMember(member1);
  std::cout << "After adding one member:\n";
  std::cout << Group.printGroup() << std::endl;

  Group.addMember(member2);
  Group.addMember(member3);
  Group.addMember(member4);

       std::cout << "Final Group:\n";
       std::cout << Group.printGroup() << std::endl;

      std::cout << "Is the Group empty? " << (Group.isEmpty() ? "Yes" : "No")
       << std::endl; std::cout << "Final Group size: " << Group.size() <<
       std::endl;
    std::cout << "Deteleing the students" << std::endl;
        delete member1;
           delete member2;
           delete member3;
          delete member4;
     std::cout << "Is the Group empty? " << (Group.isEmpty() ? "Yes" : "No")
           << std::endl; std::cout << "Final Group size: " << Group.size() <<
           std::endl;
  return 0;
}
}