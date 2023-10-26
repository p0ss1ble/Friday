#include <iostream>
#include <fstream>

using namespace std;

class CRectangleClass{
    private:
    double x1, y1, x2, y2;

    public:
    CRectangleClass(double x1, double y1, double x2, double y2): x1(x1), y1(y1), x2(x2), y2(y2)
    {}

    //we need to see the intersection
    bool Intersect(CRectangleClass& second){
        return not(x1 > second.x2 || x2 < second.x1 || y1 > second.y2 || y2 < second.y1);
    }
};


int main() {
    ifstream file("coordinates.txt"); // открываем файл для чтения
    double x1, y1, x2, y2;
    file >> x1 >> y1 >> x2 >> y2; // читаем координаты первого прямоугольника
    CRectangleClass rectangle1(x1, y1, x2, y2); // создаем первый прямоугольник
    file >> x1 >> y1 >> x2 >> y2;
    CRectangleClass rectangle2(x1, y1, x2, y2);

    file.close();

    if(rectangle1.Intersect(rectangle2)){
        cout << "Rectangles intersect" << "\n";
    }
    else{
        cout << "Rectangles don't intersect" << "\n";
    }
    return 0;
}