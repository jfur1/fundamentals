#include <iostream>
using namespace std;

/* Demonstrating Encapsulation (hiding sensitive data from end users)
        Why Encapsulation?
            - Considered a good pracitce to declare class attributes as private (as often as you can). 
              This ensures better control over your data, because you (or others) can change one part of the code
              without affecting other parts.
            - Increased security over the data
*/
class Employee{
    private:
        int salary;

    public:
        void setSalary(int s){
            salary = s;
        }

        int getSalary(){
            return salary;
        }

};

/*
    Demonstrating Inhertience (inheriting attributes and methods from a parent class)
        - Derived Class (Child)
        - Base Class (Parent)
    To inherit from a class, we use a colon :
    In the following example, the Car class (child) inherits the attributes and methods from the Vehicle class,
    although there is no actual limit to the number of levels of inheritence
*/  
// Base Class
class Vehicle{
    public:
        string brand = "Ford";
        void honk(){
            cout << "Beep, beep!\n";
        }
};

// Derived Class
class Car : public Vehicle{
    public:
        string model = "Mustang";
};

/*
    Demonstrating Polymorphism -- An extension of ingeritence which allows us to perform one action in different ways
    Why Polymorphism?
        - Useful for code reusability. Allows us to reuse attributes and methods of an existing class when creating a new class
*/
class Animal{
    public:
        void animalSound(){
            cout << "The animal makes a sound.\n";
        }
};

class Pig : public Animal{
    public:
        void animalSound(){
            cout << "The pig says: oink oink\n";
        }
};

class Dog : public Animal{
    public:
        void animalSound(){
            cout << "The dog says: woof woof\n";
        }
};

int main(){
    // Encapsulation example -- access/modify private attribute using getter/setter
    Employee employeeObj;
    employeeObj.setSalary(50000);
    cout << employeeObj.getSalary()<< endl;

    // Inheritence Example -- Car class derived from Vehicle class
    Car myCar;
    myCar.honk();
    cout << myCar.brand + " " + myCar.model << endl;

    // Polymorphism example -- Create Pig and Dog objects, then override the animalSound() method
    Animal myAnimal;
    Pig myPig;
    Dog myDog;

    myAnimal.animalSound();
    myPig.animalSound();
    myDog.animalSound();

    return 0;
}