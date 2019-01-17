#include <iostream>
#include <string>

struct A {

    std::string name;
    int wert;

    A (std::string name, int wert = 0) : name(name), wert(wert) {

    }

    A (const A &k) {
        std::cout << "Erteile kopie von " << k.name << "\n";
        name = "Kopie von " + k.name;
    }

    A& operator= (const int &i) {
        std::cout << name << " = " << i << "\n";
        wert = i;
        return *this;
    }

    A& operator= (const A &a) {
        std::cout << name << " = " << a.name << "\n";
        wert = a.wert;
        return *this;
    }


    A& operator<< (const A &a) {
        std::cout << name << " = " << a.name << "\n";
        wert = a.wert;
        return *this;
    }

    A& operator>> (const A &a) {
        std::cout << name << " = " << a.name << "\n";
        wert = a.wert;
        return *this;
    }

    void log() const {
        std::cout << name << ":" << wert << "\n";
    }
};
int main () {

        A a("a"), b("b",1), c ("c",2);
        a.log(); b.log(); c.log();      //  a:0 b:1 c:2

        a = b = c;
        a.log(); b.log(), c.log();      //  b=c a=b   a:2 b:2 c:2

        a = 4; b = 5; c = 6;
        a << b << c;
        a.log(); b.log(); c.log();      // a=4 b=5 c=6 a=b, a=c, a:6, b:5, c:6

        a = 7; b = 8; c = 9;
        a >> b >> c ;                   // lire ab links a=b a=c
        a.log(); b.log(); c.log();     // a=4 b=5 c=6
}                                        // a:4 b:8 c:9

/*a:0
b:1
c:2
b = c
a = b
a:2
a:2
c:2
a = 4
b = 5
c = 6
a = b
a = c
a:6
b:5
c:6
a = 7
b = 8
c = 9
a = b
a = c
a:9
b:8
c:9
*/