#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
    string name;
    double age;

public:
    Animal() : name(""), age(0.00) {}
    Animal(string nam, double ag) : name(nam), age(ag) {}

    string getName() const
    {
        return name;
    }

    double getAge() const
    {
        return age;
    }

    virtual void makeSound() {}
};

class Dog : public Animal
{
private:
    string sound;

public:
    Dog() : Animal() { sound = "Woof!"; }
    Dog(string nam, double ag) : Animal(nam, ag)
    {
        sound = "Woof!";
    }

    void makeSound() override
    {
        cout << sound << endl;
    }
};

class Cat : public Animal
{
private:
    string sound;

public:
    Cat() : Animal() { sound = "Meow!"; }
    Cat(string nam, double ag) : Animal(nam, ag)
    {
        sound = "Meow!";
    }

    void makeSound() override
    {
        cout << sound << endl;
    }
};

int main()
{
    Dog dog("Chesty", 4);

    cout << "Name: " << dog.getName() << endl;
    dog.makeSound();

    Cat cat("Jennifer", 5);

    cout << "Name: " << cat.getName() << endl;
    cat.makeSound();

    return 0;
}