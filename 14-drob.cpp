#include "14-drob.h"

using namespace std;

/*
Rational::Rational (int ch1, int zn1) {
    ch = ch1;
    if (zn1 != 0) {
        zn = zn1;
        long int tmp = NOD(ch, zn);
        if (tmp > 1) {
            ch /= tmp;
            zn /= tmp;
        }
    }
    else {
        throw "Can not take zero as znamenatel";
    }
}
*/

Rational::Rational (int ch1, int zn1) {
    if (zn1 == 0){
        throw "division by zero";
    }
    try{
        ch = ch1;
        zn = zn1;
        long int tmp = NOD(ch, zn);
        if (tmp > 1) {
            ch /= tmp;
            zn /= tmp;
        }    
    }
    catch(const char* exception){
        cerr << "Error: " << exception << std::endl;
    }
    ch = ch1;
    if (zn1 != 0) {
        zn = zn1;
        long int tmp = NOD(ch, zn);
        if (tmp > 1) {
            ch /= tmp;
            zn /= tmp;
        }
    }
}

Rational::Rational (float k) {
    k = (long int) (k * 100000000);
    *this = Rational(k, 100000000);
}

Rational Rational::operator * (Rational &q) {
    Rational q2 (this->ch * q.ch, this->zn * q.zn);
    return q2;
}

Rational Rational::operator + (Rational &q) {
    Rational q2 (this->ch * q.zn + q.ch * this->zn, this->zn * q.zn);
    return q2;
}

long int Rational::NOD(long int a, long int b) {
    if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;
    if (a > b)
        return NOD(a % b, b);
    return NOD(a, b % a);
}

void Rational::print(int form) {
    if (form == 1) {
        cout << ch << "/" << zn << endl;
    }
    else if (form == 2) {
        if (ch >= zn) {
            cout << ch / zn << " ";
            cout << ch % zn << "/" << zn << endl;
        }
        else {
            cout << ch << "/" << zn << endl;
        }
    }
}

int main() {
    Rational q1 (1.6);
    Rational q2 (0.5);
    Rational q3;
    q1.print();
    q2.print();
    q3 = q1 * q2;
    q3.print();
    q3 = q1 + q2;
    q3.print();

}



