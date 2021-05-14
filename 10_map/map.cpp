/*
*  
*  adadda
*/

#include<iostream>
#include<map>

using namespace std;
struct student{
    string name;
    int age;
};

int main(void)
{
    std::map<string,student *> mStudent;
    const string zs = "zhangsan";
    const string ls = "lisi";
    student s1,s2;
    
    s1.name = "zhangsan";
    s1.age = 22;
    mStudent[zs] = &s1;

    s2.name = "zhangsan";
    s2.age = 22;
    mStudent[ls] = &s2;

    cout<<mStudent.count(ls)<<endl;

    cout<<"name is "<<mStudent[zs]->name<<endl;
    cout<<"age is "<<mStudent[zs]->age<<endl;

    return 0;
}