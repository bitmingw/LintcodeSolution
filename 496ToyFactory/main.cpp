#include <iostream>

using namespace std;

class Toy {
public:
    virtual void talk() const=0;
};

class Dog: public Toy {
    virtual void talk() const {
        cout << "Wow" << endl;
    }
};

class Cat: public Toy {
    virtual void talk() const {
        cout << "Meow" << endl;
    }
};

class ToyFactory {
public:
    /**
     * @param type a string
     * @return Get object of the type
     */
    Toy* getToy(string& type) {
        if (type == "Dog") {
            Toy* obj = new Dog();
            return obj;
        } else if (type == "Cat") {
            Toy* obj = new Cat();
            return obj;
        }
        return NULL;
    }
};

int main() {
    return 0;
}
