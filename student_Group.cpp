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
    clear();
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

bool student_Group::search(student_member* member){
    memberNode* current = head;
    while (current != nullptr)
    {
      if(current->data == member){
          return true;
      }
      current = current->next;
    }
    return false;
}   

bool student_Group::remove(student_member* member){
if (!search(member)){
    return false;
} 

memberNode* current = head;
memberNode* previous = nullptr;

while (current != nullptr && current->data != member)
{
    previous = current;
    current = current->next;
}

if (current == nullptr){
    return false;
    
}
if (current == head){
    head = head->next;
    if (tail == current){
        tail = nullptr;
    }
}
else if(current == tail){
    tail = previous;
    previous->next = nullptr;
}
else{
    previous->next = current->next;
    
}
delete current;
return true;
}

void student_Group::clear(){
    memberNode* current = head;
    while (current != nullptr)
    {
        memberNode* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}
bool student_Group::insertAfter(student_member* newMember, student_member* afterMember){
    if (!search(afterMember)){
        return false;
    }
    memberNode* current = head;
    while (current != nullptr && current->data != afterMember)
    {
        current = current->next;
    }
    memberNode* newNode = new memberNode(newMember);
    newNode->next = current->next;
    current->next = newNode;
    if (current == tail){
        tail = newNode;
    }
    return true;
}

bool student_Group::insertBefore(student_member* newMember, student_member* beforeMember){
    if (!search(beforeMember)){
        return false;
    }
   if (head->data == beforeMember){
       memberNode* newNode = new memberNode(newMember);
       newNode->next = head;
       head = newNode;
       return true;
   }
    memberNode* current = head;
    while (current->next != nullptr && current->next->data != beforeMember)
    {
        current = current->next;
    }
    memberNode* newNode = new memberNode(newMember);
    newNode->next = current->next;
    current->next = newNode;
    return true;
}
