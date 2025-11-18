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
    
    public:
     virtual void save(shopingCart*Cart)=0;
};
class mysavedb:public savedb{
    private:
    shopingCart* cart;
    public:
    void save(shopingCart*cart) override{
        this->cart=cart;
        cout<<"saving to database\n";
    }
};
class filesavedb:public savedb{
    private:
    shopingCart* cart;
    public:
    void save(shopingCart*cart) override{
        this->cart=cart;
        cout<<"saving to file\n";
    }
};
 class mongo:public savedb{
    private:
    shopingCart* cart;
    public:
    void save(shopingCart*cart) override{
        this->cart=cart;
        cout<<"saving to json file\n";
    }
};

int main(){
    shopingCart*Cart=new shopingCart();
    Cart->addproduct(new product("Laptop",999.99));
    Cart->addproduct(new product("Mouse",25.50));
    printer*printcart=new printer();
    printcart->print(Cart);
    savedb*savecart=new mysavedb();
    savedb*filesavecart=new filesavedb();
    savedb*mongosavecart=new mongo();

    savecart->save(Cart);
    filesavecart->save(Cart);
    mongosavecart->save(Cart);
    return 0; 

}