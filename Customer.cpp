#include "Customer.h"
#include "exceptions.h"

int Customer:: number_of_orders=0;

void Customer::market(vector<Deposit> &deposits) {
    Deposit::show_all_products(deposits);
}

int Customer:: get_number_of_orders(){
    return number_of_orders;
}

void Customer:: order(const string & _id,const vector<Deposit>& deposits){


    try {
        int count = 1;
        if(_id.size()<7 || _id.empty())
            throw input_error ( "invalid ID in Customer-> order method");

        if( deposits.empty())
            throw deposit_error (" Deposits from Customer-> order method are empty. Add some deposit type object before using the method!");

        for (auto deposit: deposits) {
            std::cout << "------>IN DEPOSIT " << count++ << "\n";
            if (deposit.search_product_by_ID(_id)) {
                number_of_orders++;
                int temp=1;
                deposit.delete_product_by_ID(_id,temp);
                std::cout << "**NEW ORDER : ITEM ID :" << _id << "\nNumber of orders is now " << number_of_orders
                          << "\n";
                break;
            }
        }
    }catch(input_error& e) {
        std::cout<<e.what()<<"\n";
    }catch (deposit_error& e) {
        std::cout<<e.what()<<"\n";
    }
}