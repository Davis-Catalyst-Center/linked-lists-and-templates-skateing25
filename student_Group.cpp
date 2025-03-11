#include "student_Group.hpp"
#include <iostream>

student_member::student_member(std::string name, int id) : name(name), id(id) { }

std::string student_member::getName() const{
    return name;
}
int student_member ::getId() const {
    return id;
}

std::ostream& operator<<(std::ostream& os, const student_member& member) {
    os << "Name: " << member.name << ", ID: " << member.id;
    return os;
}

student_Group::student_Group() : head(nullptr),
tail(nullptr){}

student_Group::~student_Group(){
    memberNode* current = head;
    while (current != nullptr)
    {
        memberNode* next = current->next;

        delete current;
        current = next;
    }
    
}
bool student_Group::isEmpty() {
    return head == nullptr;
}

int student_Group::size(){
    int count =0;
    memberNode* current = head;

    while (current!= nullptr)
    {
      count++;
      current = current->next;
    }
  return count;  
}
void student_Group::addMember(student_member* member){
    memberNode* newNode = new memberNode(member);
    if(isEmpty()){
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
}
std::string student_Group::printGroup(){
    std::stringstream ss;

    if(isEmpty()){
        ss<<"is empty";
        return ss.str();
    }
    ss<< "";
    ss << "-------------\n";

    memberNode* current = head;
    int index = 1;
    while (current != nullptr)
    {
      ss << index << ". " << *(current->data) << "\n";
      current = current->next;
      index++;
    }
    return ss.str();
}