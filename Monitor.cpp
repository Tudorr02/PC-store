
#include "Monitor.h"
#include "exceptions.h"


Monitor::Monitor(const string &_brand, const string &_name, float _price, bool _gaming, int inch, int wei) :
        Component(_brand, _name, _price, _gaming), inches(inch), weight(wei) {


    ID_product.insert(0, "MN");

    if (inch < 10 || inch > 35)
        throw constructor_error_invalid_attribute(
                "The size of the monitor can't be smaller than 10 inches or bigger than 34 inches");

    if (wei < 1000 || wei > 3000)
        throw constructor_error_invalid_attribute(
                "The weight of the monitor can't be smaller than 1000 or bigger than 3000 ");


}

float Monitor::get_market_price() {
    return get_price() * float(2.8);
}

int Monitor::get_product_warranty() {
    int manufacturer_warranty = 3;
    return warranty + manufacturer_warranty;
}

std::shared_ptr<Component> Monitor::clone() {

    return std::make_shared<Monitor>(*this);
}

void Monitor::print(std::ostream &out) {

    out << "Inches: " << inches << "\n";
    out << "Weight:  " << weight << "\n";
}