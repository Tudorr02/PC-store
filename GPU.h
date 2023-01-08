
#ifndef OOP_GPU_H
#define OOP_GPU_H

#include "Component.h"
#include<vector>

using std::vector;
enum GPU_Series {GTX_1000,GTX_1600,GTX_2000,GTX_3000,GTX_4000,RX_500,RX_5000,RX_6000};
enum GPU_Memory_Type {GDDR3,GDDR5,GDDR6,GDDR6X};
enum Ports {VGA,DVI,HDMI,DisplayPort};//// pentru GPU si monitor

class GPU:public Component{

    int gpu_memory_size;
    GPU_Memory_Type gpu_memory_type;
    GPU_Series gpu_series;
    vector<Ports> gpu_ports;
    int fans;
    void print(std::ostream& out) override;

public:

    GPU(const string& _brand,const string &_name,float _price,bool _gaming,
        int _gpu_memory_size, GPU_Memory_Type _gpu_memory_type, GPU_Series _gpu_series, vector<Ports>& _gpu_ports, int _fans);

    std::shared_ptr<Component> clone()override;
    float get_market_price() override;
    int get_product_warranty() override;


};


#endif
