#include<bits/stdc++.h>
#include "ProductCatalog.h"
using namespace std;

class Cart
{
private:
    map<int, int> cart_items;
    
public:
    Cart(/* args */);
    ~Cart();
    void add_to_cart(int, int);
    void remove_from_cart(int, int);
    double get_cart_total();
    void clear_cart();

    map<int,int> getCart() const {
		return this->cart_items;
	}
};

void Cart :: add_to_cart(int product_id, int quantity){
    map<int, int> :: iterator it = this->cart_items.begin();
    for ( ;  it!= this->cart_items.end(); it++){
        //checking if the product is Already Present
        if(it->first == product_id){
            it->second += quantity;
            return;
        }
    }
    // if not present just create a new key
    this->cart_items[product_id] = quantity;
}

void Cart :: remove_from_cart(int product_id, int quantity){
    map<int, int> :: iterator it = this->cart_items.begin();
    for ( ;  it!= this->cart_items.end(); it++){
        if(it->first == product_id){
            //if previous quantity is greater than new quantity
            if(it->second <= quantity){
                this->cart_items.erase(it);
            }
            else{
                it->second -= quantity;
            }
            return;
        }
    }
    cout << "\tERROR\n";
}

double Cart :: get_cart_total(){
    double totalPrice = 0;
    map<int, int> :: iterator it = this->cart_items.begin();
    for ( ;  it!= this->cart_items.end(); it++){
        //getiing the particular product object according to product Id
        Product p = ProductCatalog().searchProduct(it->first);
        //calculating the totalprice from Product class
        if(p.getId()!=0 && p.get_total_price(it->second) != -1){
            totalPrice += p.get_total_price(it->second);
        }
    }
    return totalPrice;
}

void Cart :: clear_cart(){
    //Removing all elements from Cart
    this -> cart_items.clear();
}

Cart::Cart(/* args */)
{
}

Cart::~Cart()
{
}
