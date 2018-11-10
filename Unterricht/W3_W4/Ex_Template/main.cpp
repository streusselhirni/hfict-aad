#include <iostream>

template<class T>
class ContainerNG {
public:
    T value;
    explicit ContainerNG(T v) : value(v) {}
};

class A {
private:
    int value;
public:
    A(int v) : value(v) {}
    friend std::ostream &operator<<(std::ostream &stream, const A& obj);
    bool operator>(const A &obj);
};

bool A::operator>(const A &obj) {
    return this->value > obj.value;
}

std::ostream &operator<<(std::ostream &stream, const A& obj) {
    return stream << obj.value;
}

template<class T>
T maxNumber(T m, T n) {
    if (n > m) return n;
    return m;
}

int main() {
    A obj1(20);
    A obj2(10);

    A obj3 = maxNumber<A>(obj1, obj2);

    std::cout << "Welches Objekt (" << obj1 << ", " << obj2 << ") ist größer? " << obj3 << std::endl;

    std::cout << "### ContainerNG ###" << std::endl;
    ContainerNG<int> C1(123);
    std::cout << "<int>: " << C1.value << std::endl;

    ContainerNG<float> C2(3.14159);
    std::cout << "float: " << C2.value << std::endl;

    ContainerNG<std::string> C3("Huch ein String");
    std::cout << "string: " << C3.value << std::endl;

    return 0;
}