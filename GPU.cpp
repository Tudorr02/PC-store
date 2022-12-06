#include "GPU.h"
#include "exceptions.h"

GPU::GPU(const string& _brand,const string &_name,float _price,bool _gaming,
         int _gpu_memory_size, GPU_Memory_Type _gpu_memory_type, GPU_Series _gpu_series, vector<Ports>& _gpu_ports, int _fans):
        Component(_brand,_name,_price,_gaming),
        gpu_memory_size(_gpu_memory_size),gpu_memory_type(_gpu_memory_type),gpu_series(_gpu_series),gpu_ports(_gpu_ports),fans(_fans){

    ID_product.insert(0,"GP");

    if(_gpu_memory_size<1 || _gpu_memory_size>32)
        throw constructor_error("gpu_memory_type can't be smaller than 1 /bigger than 32 ",_gpu_memory_size);

    if(_fans<1 || _fans>8)
        throw constructor_error("fans can't be smaller than 1 ",fans);

    if((int)_gpu_ports.size()==0 || (int)_gpu_ports.size()>8)
        throw constructor_error("Check the vector of ports for GPUs,it can't be empty /have more than 8 ports.");




}

std::shared_ptr<Component> GPU::clone() {return std::make_shared<GPU>(*this);}

float GPU::get_market_price() {return get_price()* float (1.2);}
int GPU::get_product_warranty() {
    int manufacturer_warranty=5;
    return warranty+manufacturer_warranty;
}

void GPU:: print(std::ostream& out) {
    out<<"->Memory : "<<this->gpu_memory_size<<" GB\n";
    out<<"->Memory type : ";

    switch (this->gpu_memory_type) {

        case GPU_Memory_Type::GDDR3 : out<<"GDDR3";break;
        case GPU_Memory_Type::GDDR5 : out<<"GDDR5";break;
        case GPU_Memory_Type::GDDR6 : out<<"GDDR6";break;
        case GPU_Memory_Type::GDDR6X : out<<"GDDR6X";break;

    }
    out<<"\n";
    out<<"->GPU Series : ";

    switch (this->gpu_series) {

        case GPU_Series::RX_500 : out<<"RX 500";break;
        case GPU_Series::RX_5000 : out<<"RX 5000"; break;
        case GPU_Series::RX_6000 : out<<"RX 6000"; break;
        case GPU_Series::GTX_1000 : out<<"GTX 1000"; break;
        case GPU_Series::GTX_1600: out<<"GTX 1600"; break;
        case GPU_Series::GTX_2000: out<<"GTX 2000"; break;
        case GPU_Series::GTX_3000: out<<"GTX 3000"; break;
        case GPU_Series::GTX_4000: out<<"GTX 4000"; break;

    }
    out<<"\n";
    out<<"->Ports : ";

    for(auto item : this->gpu_ports){
        if(item== Ports::DVI) out<<"-DVI-";
        if(item== Ports::DisplayPort)out<<"-DisplayPort-";
        if(item== Ports::HDMI)out<<"-HDMI-";
        if(item== Ports::VGA) out<<"-VGA-";
    }

    out<<"\n";
    out<<"->Fans : "<<this->fans<<"\n";

}

string GPU::promo_code_() {return "";}