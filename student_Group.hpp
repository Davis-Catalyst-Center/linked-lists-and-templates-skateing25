#ifndef STUDENT_GROUP_HPP
#define STUDENT_GROUP_HPP

#include <string>
#include <sstream>

class student_member{
private:
std::string name;
int id;

public:
student_member(std::string name, int id);
std::string getName() const;
int getId() const;

friend std::ostream& operator<<(std::ostream& os, const student_member& member);
};
struct memberNode
{
    student_member* data;
    memberNode* next;

    memberNode(student_member* member) : data(member), next(nullptr) {}
};
class student_Group{
private: 
memberNode* head;
memberNode* tail;

public:
student_Group();
~student_Group();

void addMember(student_member* member);
std::string printGroup();
bool  isEmpty();
int size();
};

#endif