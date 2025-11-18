#include<bits/stdc++.h>
using namespace std;
class database{
    public:
    virtual void savedata(string data)=0;   
};
class mysql:public database{
    public:
    void savedata(string data) override{
        cout<<"data saved in mysql db:-"<<data<<endl;
    }
};
class mongo:public database{
    public:
    void savedata(string data) override{
        cout<<"data saved in mongo db:-"<<data<<endl;
    }
};
class client{
    private:
    database*data;
    public:
    client(database*data){
        this->data=data;
    }
    void storedata(string data){
        this->data->savedata(data);
    }
};
int main(){
    // mysql*mysqldb=new mysql();
    // client*cl=new client(mysqldb);
    // cl->storedata("amir");
    // mongo*mongodb=new mongo();
    // client*cl2=new client(mongodb);
    // cl2->storedata("choudhary");
    
    // with the object
     mysql mysqldb;
     mongo mongodb;
        client cl1(&mysqldb);
        client cl2(&mongodb);
        cl1.storedata("amir");
        cl2.storedata("choudhary");
}
