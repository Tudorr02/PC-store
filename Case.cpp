#include "Case.h"
#include "exceptions.h"

Case::Case(const string& _brand,const string& _name,float _price,bool _gaming,
           int _case_weight,int _case_fans,bool _case_LED_light,Case_colors _case_colors):
        Component(_brand,_name,_price,_gaming),
        case_weight(_case_weight),case_fans(_case_fans),case_LED_light(_case_LED_light),case_colors(_case_colors){

    ID_product.insert(0,"CA");

    if(_case_weight<0 || _case_weight>4000)
        throw constructor_error_invalid_attribute("case_weight can't be negative or bigger than 4000",_case_weight);

    if(_case_fans<0 || _case_fans>12)
        throw constructor_error_invalid_attribute("case_fans can't be negative or bigger than 12",_case_fans);
}

std::shared_ptr<Component> Case::clone() {return std::make_shared<Case>(*this);}

float Case::get_market_price() { return get_price()* float(1.5);}
int Case::get_product_warranty() {
    int manufacturer_warranty=2;
    return warranty+manufacturer_warranty;
}
void Case:: print(std::ostream& out) {
    out << "->Weight : " << this->case_weight << " g\n";
    out << "->Number of fans : " << this->case_fans << "\n";
    out << "->LED Lights : ";
    if (this->case_LED_light)
        out << "true";
    else
        out << "false";
    out << "\n";
    out << "->Color : ";
    switch (this->case_colors) {

        case Case_colors::black :
            out << "black";
            break;
        case Case_colors::blue :
            out << "blue";
            break;
        case Case_colors::red :
            out << "red";
            break;
        case Case_colors::grey :
            out << "grey";
            break;
        case Case_colors::silver:
            out << "silver";
            break;
        case Case_colors::yellow :
            out << "yellow";
            break;
        case Case_colors::white :
            out << "white";
            break;

    }
    out << "\n";
}

