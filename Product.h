#include<bits/stdc++.h>
using namespace std;

class Product
{
private:
    int product_id=0,quantity=0;
    string product_name,description;
    double price=0;
public:

    Product(){}
    Product(int,string,string,double,int);
    ~Product();
    void printDetails();
    double get_total_price(int quantity){
        if(quantity > this->quantity){
            return -1;
        }
        return quantity*this->price;
    }

    int getId() const {
		return this->product_id;
	}

    double getPrice() const {
		return this->price;
	}

    int getQuantity() const {
		return this->quantity;
	}

	void setQuantity(int quantity) {
		this->quantity = quantity;
	}

};

void Product :: printDetails(){
    cout<<"\nProduct id => "<<this->product_id<<endl;
    cout<<"Name => "<<this->product_name<<endl;
    cout<<"Product Description => "<<this->description<<endl;
    cout<<"Price => "<<fixed << setprecision(2) << this->price <<" rs"<<endl;
    cout<<"Quantity => "<<this->quantity<<endl;
}

Product::Product(int id, string name, string description, double price, int quantity) :
product_id(id),product_name(name),description(description),price(price),quantity(quantity)
{
}

Product::~Product()
{
}
