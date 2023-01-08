#ifndef OOP_CASE_H
#define OOP_CASE_H
#include "Component.h"

enum Case_colors {red,black,white,blue, grey, silver,yellow};

class Case:public Component{
    int case_weight;
    int case_fans;
    bool case_LED_light;
    Case_colors case_colors;
    void print(std::ostream& out) override;

public:

    Case(const string& _brand,const string &_name,float _price,bool _gaming,
         int _case_weight,int _case_fans,bool _case_LED_light,Case_colors _case_colors);

    std::shared_ptr<Component> clone()override;
    float get_market_price()override;
    int get_product_warranty() override;


};


#endif
