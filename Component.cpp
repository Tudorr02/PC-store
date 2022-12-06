#include "Component.h"

#include <algorithm>
#include "exceptions.h"

Component::Component(const string &_brand,const string &_name,float _price,bool _gaming):brand(_brand),name(_name),price(_price),gaming(_gaming){

    warranty=1; ///1 an

    if(_brand.size()<2)
        throw constructor_error("brand should have at least 2 characters",_brand);

    if(_name.size()<4)
        throw constructor_error("name should have at least 4 characters",_name);

    if(_price<1)
        throw constructor_error("price can't be 0 or negative",(int)_price);


}

string Component::create_ID(const string &brand, const string& name, bool gaming){

    std::string new_ID;
    new_ID+= brand[0];
    new_ID+= brand[1];

    for(int i=0;i<4;i++){
        unsigned int x=(int)(name[i]);

        new_ID+=std::to_string((x<<1)%9);
    }

    if(gaming)new_ID+='G';
    else
        new_ID+="NG";

    std::transform(new_ID.begin(),new_ID.end(),new_ID.begin(),::toupper);

    return new_ID;

}

string Component::get_ID_product() {return this->ID_product;}


string Component:: get_name(){return this->name;}
float Component::get_price() const {return this->price;}
bool Component::get_gaming_condition() const{return this->gaming;}
string Component::get_brand(){return this->brand;}
void Component::change_price(float new_price){
    if(new_price>0)
        this->price= new_price;
    else
        std::cout<<" change_price failed, negative input!\n";
}


std::ostream &  operator<<( std::ostream& out, Component & component){

    out<<"\n-----------COMPONENT----------\n";
    out<<"->Brand : "<<component.brand<<"\n";
    out<<"->Name : "<<component.name<<"\n";
    out<<"->Price : "<<component.price<<" $\n";
    std::string text;
    if(component.gaming)
        text="true";
    else
        text="false";
    out<<"->Recommended for gaming: "<<text<<"\n";

    component.print(out);

    return out;
}