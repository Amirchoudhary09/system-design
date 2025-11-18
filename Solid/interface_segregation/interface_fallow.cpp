#include<bits/stdc++.h>
using namespace std;
// Interface for 2D shapes
class shape2D{
public:
    virtual double area()=0;

};
class shape3D{
    public:
    virtual double area()=0;
    virtual double volume()=0;
};
class square:public shape2D{
private:
    double side;
public:
    square(double s){
        side=s;
    }
    double area() override{
        return side*side;
    }
    
};
class rectangle:public shape2D{
    private:
    double length,width;
    public:
    rectangle(double l,double b):length(l),width(b){}
    double area() override{
        return length*width;
       
    };
   
};
 class cube:public shape3D{
    private:
    double side;
    public:
    cube(double s):side(s){}
    double area() override{
        return 6*side*side;
       
    };
    double volume() override{
        return side*side*side;
    }
 };
 int main(){
    shape2D*squ=new square(29);
    shape2D*rect=new rectangle(10,20);
    shape3D*cub=new cube(30);
    cout<<"the area of squre:-"<<squ->area()<<endl;
    cout<<"the area of rectangle:-"<<rect->area()<<endl;
    cout<<"the area of cube:-"<<cub->area()<<endl;
    cout<<"the volume of cube:-"<<cub->volume()<<endl;
 }