#define NDEBUG

// #define TEST_1
// #define TEST_2
 #define TEST_3
// #define TEST_4
// #define TEST_5

#include "./vector.hpp"

void print(const dia::Vector& x) {
    std::cout << "dia::Vector(size = " << x.size() << ")" << std::endl;

    for (size_t i = 0; i < x.size(); i ++) {
        std::cout << x[i] << " ";
    }

    std::cout << std::endl;
}

dia::Vector makeVector() {
    dia::Vector v;
    v.push(10);
    v.push(20);
    v.push(30);
    return v;
}

int main() {

    #ifdef TEST_1
    { // Vector with default capacity
        dia::Vector x;

        x.push(1);
        x.push(2);
        x.push(3);
        x.push(4);
        print(x);
    }
    #endif

    #ifdef TEST_2
    { // Vector with 0 capacity
        dia::Vector x(0);

        x.push(1);
        x.push(2);
        x.push(3);
        x.push(4);

        print(x);

        x.pop();
        x.pop();

        print(x);

        x.pop();
        x.pop();

        print(x);

        x.pop();
    }
    #endif

    #ifdef TEST_3
    {
        dia::Vector x;

        x.push(1);
        x.push(2);
        x.push(3);
        x.push(4);
        print(x);

        dia::Vector y(x);
        print(y);

        dia::Vector b;
        b = x;
        print(b);

        dia::Vector z(std::move(dia::Vector()));

        dia::Vector j;
        j = std::move(dia::Vector());
    }
    #endif

    #ifdef TEST_4
    {
        dia::Vector a;
        a.push(1);
        a.push(2);
        a.push(3);

        {
            dia::Vector b(a);
        }

        print(a);
        a.push(4);
    }
    #endif

    #ifdef TEST_5
    {
        dia::Vector v;
        v = makeVector();
    }
    #endif

    return 0;
}
