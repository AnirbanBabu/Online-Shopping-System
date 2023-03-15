#include<bits/stdc++.h>
#include "Product.h"
using namespace std;

class ProductCatalog
{
private:
    static int randomId;
    static map<int, Product> products;
public:
    ProductCatalog();
    ~ProductCatalog();

    void add_product(string, string, double, int);
    void load_stock(int, int);
    Product searchProduct(int);
    void printCatalog();
    void changeQuantity(int, int);
};
// Initialize static variables
int ProductCatalog :: randomId = 101;
map<int, Product> ProductCatalog :: products;

void ProductCatalog :: add_product(string name, string description, double price, int quantity){
    // Crating a temporary object and Pushing into the Hashmap
    Product tempObj(this->randomId, name,description,price, quantity);
    this->products[this->randomId] = tempObj;
    //Increasing the product id one by one
    this->randomId++;
}

void ProductCatalog :: load_stock(int productId, int quantiity){
    map<int, Product> :: iterator it = this->products.begin();
    for ( ;  it!= this->products.end(); it++){
        if(it->first == productId){
            it->second.setQuantity(it->second.getQuantity() + quantiity);
            return;
        }
    }
    cout << "\t ERROR \n";
}


Product ProductCatalog :: searchProduct(int id){
    map<int, Product> :: iterator it = this->products.begin();
    for ( ;  it!= this->products.end(); it++){
        if(it->first == id){
            return it->second;
        }
    }
    return Product();
}

void ProductCatalog :: printCatalog(){
    bool flag = true;
    map<int, Product> :: iterator it = this->products.begin();
    for ( ;  it!= this->products.end(); it++){
        if(it->first == it->second.getId()){
            it->second.printDetails();
            cout<<endl;
            flag = false;
        }
    }
    if(flag){
        cout <<"No product available\n";
    }
}

void ProductCatalog :: changeQuantity(int id, int qty){
    this->products[id].setQuantity(this->products[id].getQuantity()- qty);
}

ProductCatalog::ProductCatalog()
{
}

ProductCatalog::~ProductCatalog()
{
}
