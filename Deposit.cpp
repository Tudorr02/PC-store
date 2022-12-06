#include "Deposit.h"
#include "exceptions.h"

int Deposit::number_of_products=0;

bool Deposit::search_product_by_ID(const string& _id){

    int count=0;
    string name_of_product;
    try {
        if (_id.empty() || (int)_id.size()<7)
            throw input_error("invalid ID in search_product_by_ID method");


        for (const auto &item: this->components) {
            if (_id == item->get_ID_product()) {
                count++;
                if (name_of_product.empty())
                    name_of_product = item->get_name();
            }

        }
    } catch (input_error & e) {
        std::cout<<e.what()<<"\n";
    }


    std::cout<<"----------SEARCH---------------------------\n";
    std::cout<<"Details about product with ID ("<<_id<<") :\n";

    if(count>0){
        std::cout<<"Product name: "<<name_of_product<<"\n";
        std::cout<<"Products in deposit: "<<count<<"\n";
        std::cout<<"-------------------------------------------\n";
        return true;
    }
    else{
        std::cout<<"Product doesn't exit or it's out of stock :(\n";
        std::cout<<"-------------------------------------------\n";
        return false;
    }




}

void Deposit:: delete_product_by_ID(const string& _id, int count) {

    try {
        if(_id.empty() || (int)_id.size()<7)
            throw input_error("Invalid ID in delete_product_by_ID method");

        if(count<1)
            throw input_error(" count in delete_by_ID method can't be smaller than 1");
        int position = 0;
        int total_products_with_id = 0;
        int copy_count = count;
        vector<std::shared_ptr<Component>> temporary_copy = this->components;

        for (const auto &item: temporary_copy) {
            if (_id == item->get_ID_product()) {
                total_products_with_id++;
                if (count > 0) {
                    this->components.erase(this->components.begin() + position);
                    count--;
                    number_of_products--;
                }
            }
            position++;

        }
        if(total_products_with_id==0)
            throw input_error(" ID from the delete_product_by_ID is invalid.The product you are looking for doesn't exist in deposit");

        int difference;
        if(copy_count> total_products_with_id)
            difference=0;
        else
            difference=total_products_with_id-copy_count;

        std::cout << "Products left with ID " << _id << " :" << difference << "\n";
    } catch (input_error & e) {
        std::cout<<e.what()<<"\n";
    }
}




void Deposit::add_product(const std::shared_ptr<Component>& item){

    this->components.push_back(item);
    number_of_products++;
    std::cout<<"\n*** Item with ID "<<item->get_ID_product()<<" has been added to deposit!\n";
}

void Deposit::add_products(const vector<std::shared_ptr<Component>>& items){
    try {
        if(items.empty())
            throw input_error(" Empty vector from add_products method");
        this->components.insert(this->components.end(), items.begin(), items.end());

        for (const auto &item: items) {
            std::cout << "\n*** Item with ID " << item->get_ID_product() << " has been added to deposit!\n";
            number_of_products++;
        }
    } catch (input_error & e) {
        std::cout<<e.what()<<"\n";
    }
}

void Deposit:: show_products(){

    try {
        if(this->components.empty())
            throw deposit_error("Deposit is empty. Add some components before using deposit's methods!");
        for (const auto &item: this->components)
            std::cout << *item;
    } catch (deposit_error & e) {
        std::cout<<e.what()<<"\n";
    }

}

void Deposit::show_all_products(vector<Deposit> &deposits) {
    try {
        if(deposits.empty())
            throw deposit_error("Deposit vector is empty. Add some deposit type objects before using this method!");

        std::cout << "\n-----------ALL PRODUCTS-----------\n";
        std::unordered_map<std::string, int> appearance;
        for (const auto &deposit: deposits) {

            if(deposit.components.empty())
                throw deposit_error("Deposit is empty. Add some components before using deposit's methods!");

            for (const auto &component: deposit.components) {
                if (appearance[component->get_ID_product()] == 0) {
                    appearance[component->get_ID_product()]++;
                    std::cout << "** ID: " << component->get_ID_product() << " || Name : " << component->get_name()
                              << "\n"; ////

                }

            }
        }
    } catch (deposit_error & e) {
        std::cout<<e.what()<<"\n";
    }
}

string Deposit::promo_code_() {
    std::cout<<"***PROMO CODE : ";
    if(!this->components.empty()) {
        for (const auto &component: this->components) {
            std::shared_ptr<Component> test = std::dynamic_pointer_cast<Storage>(component);
            if (test != nullptr) {
                std::cout << component->promo_code_();
                return component->promo_code_();
            }
        }
    }
    std::cout<<"not found";
    return "not found";
}

int Deposit::get_number_of_products() {

    std::cout<<"!!!!Number of products  : "<<number_of_products<<"\n";
    return number_of_products;
}


Deposit::Deposit(const Deposit& other){

    for(const auto &item: other.components){
        this->components.push_back(item);
        number_of_products++;
    }

}
Deposit& Deposit:: operator=( Deposit other){

    if(this!= &other) {
        swap((*this), other);
        number_of_products += (int) other.components.size();
    }
    return (*this);
}

void swap(Deposit& d1, Deposit& d2){
    std::swap(d1.components,d2.components);
}
