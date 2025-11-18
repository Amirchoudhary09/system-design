#include<bits/stdc++.h>
using namespace std;
class product{
    public:
    string name;
    double price;
    product(string n, double p){
        name = n;
        price = p;
    }

};
class shopingCart{
    private:
    vector<product*> products;
    public:
    void addproduct(product*p){
        products.push_back(p);
    }
    vector<product*> getproducts(){
        return products;
    }
    double calculatetotal(){
        int total=0;
        for(auto p:products){
            total +=p->price;
        }
        return total;
    }
};

class printer{
    private:
  shopingCart* cart;
  public:
   void print(shopingCart*cart){
    this->cart=cart;
    cout<<"Products in cart:\n";
    for(auto p:cart->getproducts()){
      cout<<p->name<<" - $"<<p->price<<"\n";
    }
    cout<<"Total: $"<<cart->calculatetotal()<<"\n";
   }

};
class savedb{
    private:
    shopingCart* cart;
    public:
    savedb(shopingCart*cart){
        this->cart=cart;
    }
    void save(){
        cout<<"saving to database\n";
    }
};
int main(){
    shopingCart*Cart=new shopingCart();
    Cart->addproduct(new product("Laptop",999.99));
    Cart->addproduct(new product("Mouse",25.50));
    printer*printcart=new printer();
    printcart->print(Cart);
    savedb*savecart=new savedb(Cart);
    savecart->save();
    return 0; 

}