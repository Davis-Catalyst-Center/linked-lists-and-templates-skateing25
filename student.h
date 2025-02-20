#include <string>
class student {
private:
std::string name; 
  int age;
char grades;
public:
 student(std::string n, int a, char b) : name(n), age(a), grades(b) {};
friend std::ostream& operator<<(std::ostream& os, const student& p); 


};
std::ostream& operator<<(std::ostream& os, const student& p) {
    os << "Name: " << p.name << ", Age: " << p.age << ", Grades: " << p.grades;



    return os;
}