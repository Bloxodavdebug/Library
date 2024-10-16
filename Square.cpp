//#include <iostream>
//using namespace std;
//
//struct Point {
//    int x;
//    int y;
//};
//
//struct Rectangle {
//    Point bottomLeft;
//    Point topRight;
//    
//
//    void changeWidth(int delta) {
//        topRight.x += delta;
//    }
//
//    void changeHeight(int delta) {
//        topRight.y += delta;
//    }
//};
//
//int height(Rectangle point) {
//    return point.topRight.y - point.bottomLeft.y;
//}
//
//int width(Rectangle point) {
//    return point.topRight.x - point.bottomLeft.x;
//}
//
//int area(Rectangle r) {
//    return width(r) * height(r);
//}
//
//int perimetr(Rectangle r)
//{
//    return (width(r) + height(r)) *2;
//}
//
//void printPoint(const Point& point) {
//    cout << "(" << point.x << ", " << point.y << ")";
//}
//
//void print(Rectangle r) {
//    cout << "Bottom left :: ";
//    printPoint(r.bottomLeft);
//    cout << " Top right :: ";
//    printPoint(r.topRight);
//    cout << endl;
//}
//
//
//void changeH(Rectangle& r) 
//{
//    int delta;
//    cout << "Enter height+ --> "; cin >> delta;
//    r.topRight.y += delta;
//    print(r);
//}
//
//void changeW(Rectangle& r)
//{
//    int delta;
//    cout << "Enter width+ --> "; cin >> delta;
//    r.topRight.x += delta;
//    print(r);
//}
//
//void changeAll(Rectangle r)
//{
//    changeW(r);
//    changeH(r);
//}
//
//void moveX(Rectangle& r)
//{
//    int delta;
//    cout << "Enter X+ --> "; cin >> delta;
//    r.topRight.x += delta; r.bottomLeft.x += delta;
//    print(r);
//}
//
//void moveY(Rectangle& r)
//{
//    int delta;
//    cout << "Enter Y+ --> "; cin >> delta;
//    r.topRight.y += delta; r.bottomLeft.y += delta;
//    print(r);
//}
//
//void moveAll(Rectangle r)
//{
//    moveX(r);
//    moveY(r);
//}
//
//
//
//int main() {
//    Rectangle square{ {-2, -2}, {3,1} };
//    Point center;
//    /*cout << "Area: " << area(square) << endl;
//    cout << "Height: " << height(square) << endl;
//    cout << "Width: " << width(square) << endl;
//    cout << "Perimetr: " << perimetr(square) << endl;*/
//    //changeH(square);
//    //changeW(square);
//    //changeAll(square);
//    //moveY(square);
//    //moveAll(square);
//}

