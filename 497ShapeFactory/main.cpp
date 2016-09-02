#include <iostream>

using namespace std;

class Shape {
public:
    virtual void draw() const=0;
};

class Rectangle: public Shape {
    virtual void draw() const {
        cout << " ---- " << endl
             << "|    |" << endl
             << " ---- " << endl;
    }
};

class Square: public Shape {
    virtual void draw() const {
        cout << " ---- " << endl
             << "|    |" << endl
             << "|    |" << endl
             << " ---- " << endl;
    }
};

class Triangle: public Shape {
    virtual void draw() const {
        cout << "  /\\  " << endl
             << " /  \\ " << endl
             << "/____\\" << endl; 
    }
};

class ShapeFactory {
public:
    /**
     * @param shapeType a string
     * @return Get object of type Shape
     */
    Shape* getShape(string& shapeType) {
        Shape* obj = NULL;
        if (shapeType == "Rectangle") {
            obj = new Rectangle();
        } else if (shapeType == "Square") {
            obj = new Square();
        } else if (shapeType == "Triangle") {
            obj = new Triangle();
        }
        return obj;
    }
};

int main() {
    return 0;
}
