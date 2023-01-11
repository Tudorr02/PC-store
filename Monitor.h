
#ifndef OOP_MONITOR_H
#define OOP_MONITOR_H

#include "Component.h"

class Monitor : public Component {

private:
    int inches;
    int weight;

    void print(std::ostream &out) override;

public:

    Monitor(const string &_brand, const string &_name, float _price, bool _gaming, int inch, int wei);

    std::shared_ptr<Component> clone() override;

    float get_market_price() override;

    int get_product_warranty() override;


};


#endif //OOP_MONITOR_H
