#include<bits/stdc++.h>
using namespace std;
// Interface for 2D shapes
class shape{
public:
    virtual double area()=0;
    virtual  double value()=0;
};
class square:public shape{
private:
    double side;
public:
    square(double s){
        side=s;
    }
    double area() override{
        return side*side;
    }
    double value() override{
        throw logic_error("Value not applicable for 2D shape");

    }
};
class rectangle:public shape{
    private:
    double length,width;
    public:
    rectangle(double l,double b):length(l),width(b){}
    double area() override{
        return length*width;
       
    };
    double value() override{
        throw logic_error("Value not applicable for 2D shape");
    }
};
 class cube:public shape{
    private:
    double side;
    public:
    cube(double s):side(s){}
    double area() override{
        return 6*side*side;
       
    };
    double value() override{
        return side*side*side;
    }
 };
int main(){
    shape*squ=new square(29);
    shape*rect=new rectangle(10,20);
    shape*cub=new cube(30);
    cout<<"the area of squre"<<squ->area()<<endl;
    cout<<"the area of rectangle"<<rect->area()<<endl;
    cout<<"the area of cube"<<cub->area()<<endl;
    cout<<"the value of cube"<<cub->value()<<endl;
    try{
        cout<<"Area of Square: "<<squ->value()<<endl;
    }catch(logic_error& e){
        cout<<"this the error"<<e.what()<<endl;
    }
};