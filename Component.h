
#ifndef OOP_COMPONENT_H
#define OOP_COMPONENT_H

#include <string>
#include <memory>
#include<iostream>

using std::string;



class Component{

private:
    string brand;
    string name;
    float price;
    bool gaming;

    virtual void print(std::ostream& out)=0;

protected:
    string create_ID(const string& brand, const string &name, bool gaming);
    int warranty;
    string ID_product= create_ID(this->brand,this->name,this->gaming);
    Component(const string& _brand,const string &_name,float _price,bool _gaming);

public:

    virtual std::shared_ptr<Component> clone()=0;
    virtual ~Component()=default;
    virtual float get_market_price()=0;
    virtual int get_product_warranty()=0;


    friend const std::ostream & operator<<(  std::ostream& out, Component & component);
    [[nodiscard]] string get_name() const ;
    [[nodiscard]] float get_price() const ;
    [[nodiscard]] bool get_gaming_condition() const;
    string get_brand();
    void change_price(float new_price);


    string get_ID_product();



};




#endif
