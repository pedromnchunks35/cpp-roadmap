#include <iostream>
#include <memory>
#include <vector>
class Object
{
public:
    Object(std::string name, int size)
    {
        this->name = name;
        this->size = size;
    }
    ~Object()
    {
        std::cout << "Destroyed" << "\n";
    }
    void printObject()
    {
        std::cout << "name: " << name << " size: " << size << "\n";
    }
    std::string *getName()
    {
        return &name;
    }
    int *getSize()
    {
        return &size;
    }

private:
    std::string name;
    int size;
};
class Person
{
public:
    ~Person()
    {
        std::cout << "Person is destroyed" << "\n";
    }
    void addObj(Object &object)
    {
        objList.push_back(std::make_unique<Object>(object));
    }

    void addObj(Object &&object)
    {
        objList.push_back(std::make_unique<Object>(object));
    }
    void removeObj(Object &object)
    {
        for (auto obj = objList.begin(); obj != objList.end(); obj++)
        {
            Object *realObj = obj->get();
            if ((*realObj->getName()) == (*object.getName()) && (*realObj->getSize()) && (*object.getSize()))
            {
                std::cout << "Im deleting a object..";
                obj = objList.erase(obj);
                break;
            }
        }
    }

    void printList()
    {
        for (auto it = objList.begin(); it != objList.end(); it++)
        {
            it->get()->printObject();
        }
    }

private:
    std::vector<std::unique_ptr<Object>> objList;
};

int main()
{
    Person person;
    Object obj1("Pedro", 2);
    Object obj2("Elsa", 2);
    Object obj3("Hello", 1213);
    Object obj4("End", 999);
    person.addObj(obj1);
    person.addObj(obj2);
    person.addObj(obj3);
    person.addObj(obj4);
    person.addObj(Object("Carol", 22));
    person.printList();
    person.removeObj(obj2);
    std::cout << "********************" << "\n";
    person.printList();
}