#include <iostream>
#include "student_Group.hpp"

using namespace std;


int main() {
  student_Group Group;
  student_member *member1 = new student_member("John", 1);
  student_member *member2 = new student_member("Jane", 2);
  student_member *member3 = new student_member("Mike", 3);
  student_member *member4 = new student_member("Sarah", 4);
  student_member *member5 = new student_member("Alex", 5);
  student_member *member6 = new student_member("Emily", 6);
  
  std::cout << "Is the Group empty? " << (Group.isEmpty() ? "Yes" : "No") << std::endl;
  std::cout << "Initial Group size: " << Group.size() << std::endl;
  std::cout << "Group content: " << Group.printGroup() << std::endl;

  // Add members to test
  Group.addMember(member1);
  Group.addMember(member2);
  Group.addMember(member3);
  Group.addMember(member4);
  
  std::cout << "\nAfter adding four members:" << std::endl;
  std::cout << Group.printGroup() << std::endl;
  std::cout << "Group size: " << Group.size() << std::endl;
  
  // Test search method
  std::cout << "\nSearch Tests:" << std::endl;
  std::cout << "Searching for member1: " << (Group.search(member1) ? "Found" : "Not Found") << std::endl;
  std::cout << "Searching for member5 (not in list): " << (Group.search(member5) ? "Found" : "Not Found") << std::endl;
  
  // Test insertAfter method
  std::cout << "\nInsert After Tests:" << std::endl;
  std::cout << "Inserting member5 after member2: " << (Group.insertAfter(member5, member2) ? "Success" : "Failed") << std::endl;
  std::cout << "Group after insertion:" << std::endl;
  std::cout << Group.printGroup() << std::endl;
  
  // Test insertBefore method
  std::cout << "\nInsert Before Tests:" << std::endl;
  std::cout << "Inserting member6 before member1 (head): " << (Group.insertBefore(member6, member1) ? "Success" : "Failed") << std::endl;
  std::cout << "Group after insertion:" << std::endl;
  std::cout << Group.printGroup() << std::endl;
  
  // Test remove method
  std::cout << "\nRemove Tests:" << std::endl;
  std::cout << "Removing member3: " << (Group.remove(member3) ? "Success" : "Failed") << std::endl;
  std::cout << "Group after removal:" << std::endl;
  std::cout << Group.printGroup() << std::endl;
  
  // Test removing head and tail
  std::cout << "Removing member6 (head): " << (Group.remove(member6) ? "Success" : "Failed") << std::endl;
  std::cout << "Removing member4 (tail): " << (Group.remove(member4) ? "Success" : "Failed") << std::endl;
  std::cout << "Group after head and tail removal:" << std::endl;
  std::cout << Group.printGroup() << std::endl;
  
  // Test clear method
  std::cout << "\nClear Test:" << std::endl;
  Group.clear();
  std::cout << "Group after clear:" << std::endl;
  std::cout << Group.printGroup() << std::endl;
  std::cout << "Is the Group empty? " << (Group.isEmpty() ? "Yes" : "No") << std::endl;
  
  // Clean up memory
  delete member1;
  delete member2;
  delete member3;
  delete member4;
  delete member5;
  delete member6;
  
  return 0;
}
