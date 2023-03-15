#include<bits/stdc++.h>
#include "Customer.h"
using namespace std;

void printChoice();
double getprice();
int getId();
int getQuantity();
string validateMail();
double getBankbalance();


int main(){
    //Creating instance of Product Catalog
    ProductCatalog pobj; 
    // Customer user(123,"Anirban","anirban@sasken.com","West Bengal",15000.00);
    string name, email, address;
    double balance;
    
    int id,quantity=0,choice;
    string description;
    double price=0;

    cout<<"* * * Welcome to ONLINE SHOPPING SYSTEM * * *\n";
    //Reading customer details 
    cout<<"Please enter the following details:\nName: ";
    getline(cin, name);
    email = validateMail();
    cout<<"Address: ";
    getline(cin, name);
    balance = getBankbalance();
    //creating an instance of the Customer
    Customer user(1221,name,email,address,balance);
    
    while(true){
        //Everytime printing all the choice from different function
        printChoice();
        cin >> choice;
        while(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize> :: max(),'\n');
            cout <<"\tInvalid Input\n";
            printChoice();
            cin >> choice;
        }
        switch (choice)
        {
            case 1:
                pobj.printCatalog();
                break;
            
            case 2:
                cout<<("Product Name : ");
                getline(cin>>ws, name);
                cout<<("Description : ");
                getline(cin, description);
                
                price = getprice();
                quantity=getQuantity();
                pobj.add_product(name,description,price,quantity);
                break;
            case 3:
                id = getId();
                quantity = getQuantity();
                pobj.load_stock(id,quantity);
                break;
            case 4:
                id = getId();
                if(pobj.searchProduct(id).getId() != 0){
                    quantity = getQuantity();
                    user.add_to_cart(id,quantity);
                }
                else{
                    cout<< "Product is not Registered\n";
                }
                break;
            case 5:
                user.printCart();
                break;
            case 6:
                user.checkout();
                break;
            case 7:
                user.get_cart_total();
                break;
            case 8:
                cout << "Bank Balance: "<<user.getBankBalance()<<endl;
                break;
            case 9:
                id = getId();
                if(pobj.searchProduct(id).getId() != 0){
                    pobj.searchProduct(id).printDetails();
                }
                else{
                    cout <<"Incorrect Product Id\n";
                }
                break;
            case 10:
                cout << "Exit";
                return 0;
            default:
                cout << "Try Again\n"<<endl;
                break;
        }
        
    }
   return 0;

}

void printChoice(){
    cout<<"...\n";
    cout<<"Press 1. to Print the Product Catalog"<<endl;
    cout<<"Press 2. to Add a product"<<endl;
    cout<<"Press 3. to Load stock of a product"<<endl;
    cout<<"Press 4. to Add product to the cart"<<endl;
    cout<<"Press 5. Print cart"<<endl;
    cout<<"Press 6. Checkout cart"<<endl;
    cout<<"Press 7. Display the totl price of the cart"<<endl;
    cout<<"Press 8. Print bank balance"<<endl;
    cout<<"Press 9. Print details of a product"<<endl;
    cout<<"Press 10. to Exit\nYour Choice:\t"<<endl;
}
double getprice(){
    double price;
    cout<<("Price : ");
    cin>>price;
    while(cin.fail() || price<0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize> :: max(),'\n');
        cout <<"\tInvalid price || Enter again\n";
        cin >> price;
    }
    return price;
}
int getId(){
    int id;
    cout<<("Product Id: ");
    cin>>id;
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize> :: max(),'\n');
        cout <<"\tInvalid  id || Enter again\n";
        cin >> id;
    }
    return id;
}
int getQuantity(){
    int quantity;
    cout<<("Product Quantity: ");
    cin>>quantity;
    while(cin.fail() || quantity<=0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize> :: max(),'\n');
        cout <<"\tInvalid  quantity || Enter again\n";
        cin >> quantity;
    }
    return quantity;
}
string validateMail(){
    string mail;
    cout<<("Email: ");
    getline(cin, mail);
    const regex pattern(
        "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
  
    // Match the string pattern
    // with regular expression
    while(!regex_match(mail, pattern)){
        cout<<("Please enter correctly: \n");
        getline(cin, mail);
    }
    return mail;
}

double getBankbalance(){
    double balance;
    cout<<("Balance : ");
    cin>>balance;
    while(cin.fail() || balance<0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize> :: max(),'\n');
        cout <<"\tInvalid Balance || Enter again\n";
        cin >> balance;
    }
    return balance;
}