#include<bits/stdc++.h>
#include "Cart.h"
using namespace std;

class Customer
{
private:
    int customer_id;
    string name, email, address;
    double bankBalance;
    Cart my_cart;
public:
    Customer(int id, string name, string email, string address, double balance);
    ~Customer();
    void add_to_cart(int, int);
    void remove_from_cart(int, int);
    void get_cart_total();
    void printCart();

    bool checkout();

    double getBankBalance() const {
		return this->bankBalance;
	}
};

Customer::Customer(int id, string name, string email, string address, double balance):
customer_id(id), name(name), email(email), address(address), bankBalance(balance) 
{
}

Customer::~Customer()
{
}

void Customer::add_to_cart(int productId, int quantity){
    this->my_cart.add_to_cart(productId,quantity);
}
void Customer::remove_from_cart(int productId, int quantity){
    this->my_cart.remove_from_cart(productId,quantity);
}
void Customer::get_cart_total(){
        cout<< "Total Cart Value:  "<< my_cart.get_cart_total()<<endl;
}
bool Customer :: checkout(){
    // Checking if cart is empty !
    if(my_cart.getCart().empty()){
        cout << "No Items in the cart\n";
        return false;
    }
    
    double cartValue = my_cart.get_cart_total();
    if(cartValue <= this->bankBalance){
        bankBalance -= cartValue;

        map<int, int> cartObj = my_cart.getCart();
        
        map<int, int> :: iterator it = cartObj.begin();
        while (it!=cartObj.end())
        {
            // Reducing the quantity member of the original product Object
            // ProductCatalog temp;
            // temp.searchProduct(it->first).setQuantity(temp.searchProduct(it->first).getQuantity()-it->second);
            ProductCatalog().changeQuantity(it->first,it->second);
            it++;
        }
        my_cart.clear_cart();
        cout<<"Remaining Balance: "<<fixed << setprecision(2) <<bankBalance<<"rs.\n\tSuccess\n";
        return true;

    }
    cout << "\nERROR: Bank balance is insufficient\n";
    return false;
}
void Customer :: printCart(){
    map<int,int> cart = my_cart.getCart();
    if(cart.empty()){
        cout << "No Items in the cart\n";
        return;
    }
    map<int,int> :: iterator it=cart.begin();
    while(it!=cart.end()){
        cout<<"\nProduct id: "<<it->first;
        cout<<" ,  Quantity: "<<it->second<<endl;
        it++;
    }
}
