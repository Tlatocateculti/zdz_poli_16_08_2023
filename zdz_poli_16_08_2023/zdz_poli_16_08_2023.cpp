// zdz_poli_16_08_2023.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

namespace moja {
    int a = 15;
    double b = -.2;

    class A {

    public:
        double a = -.6;
    };
}

class A {
public:
    virtual string info() { return "Jestem klasą A"; };
};

class B : public virtual A {
    //public:
    //    string info() { return "Jestem klasą B"; };
};

class E : public virtual A {

};

class C : public B, public E {
    //public:
       // string info() { return "Jestem klasą C"; };
};


class Punkt {
    double x, y;
    
public:
    Punkt() {};
    Punkt(double x, double y) : x(x), y(y) {}
    double getX() { return x;  }
    double getY() { return y; }
    string getXY() {
        stringstream ss;
        ss << "P(" << x << "," << y << ")";
        return ss.str();
    }
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
};

class Figura {
    Punkt* punkty;
    int index;
public:
    Figura() { 
        punkty = new Punkt();
        index = 0; }


   // string pokazPunkty();
    void wstawPunkt(Punkt p) {
        Punkt* tmp = new Punkt[index + 1];
        for (int i = 0; i < index; i++) {
            tmp[i] = punkty[i];
        }
        tmp[index++] = p;
        punkty = tmp;
    };
    //double obwod();
    double pole() { cout << "FIGURA\n" << punkty[2].getXY() << "\n"; return 0; };

    string getXY(int i) {
        return punkty[i].getXY();
    }
};

class Kwadrat : public Figura {

public:
    Kwadrat(Punkt* p) {
        for (int i = 0; i < 4; i++) {
            wstawPunkt(p[i]);
        }
    };
    double pole() { cout << "KWADRAT\n" << getXY(2) << "\n"; return 0; };
};


class Prostokat : public Figura {
public:
    Prostokat(Punkt* p) {
        for (int i = 0; i < 4; i++) {
            wstawPunkt(p[i]);
        }
    };
    double obwod() {
        cout << "PROSTOKAT\n" << getXY(2) << "\n"; return 0;
    }
};

int main()
{
    Punkt p[4] = { Punkt(0,0), Punkt(0,1), Punkt(1,0), Punkt(1,1) };
    
   Kwadrat *kw = new Kwadrat(p);
   
   Figura fig = static_cast<Figura>(*kw);
   fig.pole();
   kw->pole();
   //f.
   //Prostokat* p = f;

   Prostokat kw2 = reinterpret_cast<Prostokat&>(fig);

   kw2.obwod();

   /*A a;
    B b;
    C c;

    cout << a.info() << "\n" << "\n" << c.info() << "\n";*/

    //Działanie na przestrzeniach 
    //int a = -100;
    //double b = 12.5;
    //using namespace moja;
    //moja::A klasa;
    
    
    //Działanie na plikach - zapis i odczyt
    /*
    ofstream plik("plik.txt");
    plik << "To jest nowa zawartość.\n" << "Nowa linia pliku\n" << "i kolejna\n\n" << "KONIEC!";
    plik.close();

    ifstream czytaj("plik.txt");
    
    string str;
    while (!czytaj.eof()) {
        string tmp;
        getline(czytaj, tmp);
        //czytaj >> tmp;
        str += tmp + "\n";
    }

    std::cout << str << "\n";*/
}
