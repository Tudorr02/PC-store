#include "CPU.h"
#include "exceptions.h"

CPU::CPU(const string& _brand,const string &_name,float _price,bool _gaming,
         int _cpu_cores,int _cpu_threads,int _cpu_frequency,CPU_Socket _cpu_socket, CPU_Series _cpu_series ):
        Component(_brand,_name,_price,_gaming),
        cpu_cores(_cpu_cores),cpu_threads(_cpu_threads),cpu_frequency(_cpu_frequency),cpu_socket(_cpu_socket),cpu_series(_cpu_series){

    ID_product.insert(0,"CP");

    if(_cpu_cores<0 || _cpu_cores >24 || _cpu_cores%2!=0)
        throw constructor_error("cpu_cores can't be negative/ bigger than 24 / odd number ",_cpu_cores);

    if(_cpu_threads<0 || _cpu_threads >48 || _cpu_threads%2!=0)
        throw constructor_error("cpu_threads can't be negative/ bigger than 48 / odd number ",_cpu_threads);

    if(_cpu_frequency<0 || _cpu_frequency>15)
        throw constructor_error("cpu_frequency can't be negative / bigger than 15",_cpu_frequency);


}

std::shared_ptr<Component> CPU::clone() {return std::make_shared<CPU>(*this);}

float CPU::get_market_price() {return get_price()* float (1.3);}
int CPU::get_product_warranty() {
    int manufacturer_warranty=7;
    return warranty+manufacturer_warranty;
}

void CPU::print(std::ostream & out) {
    out<<"->Number of cores : "<<this->cpu_cores<<"\n";
    out<<"->Number of threads : "<<this->cpu_threads<<"\n";
    out<<"->Frequency : "<< this->cpu_frequency<<" MHz\n";
    out<<"->Socket : ";
    switch (this->cpu_socket) {

        case CPU_Socket::LGA_1700 :out<<"LGA 1700"; break;
        case CPU_Socket::LGA_1151 : out<<"LGA 1151";break;
        case CPU_Socket::LGA_1200 : out<<"LGA 1200"; break;
        case CPU_Socket::AM4 : out<<"AM4";break;

    }
    out<<"\n";
    out<<"->Series : ";
    switch (this->cpu_series) {

        case CPU_Series::Intel_I7 :out<<"Intel I7"; break;
        case CPU_Series::Intel_I3 :out<<"Intel I3"; break;
        case CPU_Series::Intel_I5 :out<<"Intel I5"; break;
        case CPU_Series::Intel_I9 :out<<"Intel I9"; break;
        case CPU_Series::Intel_Celeron: out<<"Intel Celeron"; break;
        case CPU_Series::Intel_Pentium :out<<"Intel Pentium";break;
        case CPU_Series::AMD_Ryzen_3 :out<<"AMD Ryzen 3"; break;
        case CPU_Series::AMD_Ryzen_5 :out<<"AMD Ryzen 5"; break;
        case CPU_Series::AMD_Ryzen_7 :out<<"AMD Ryzen 7"; break;
        case CPU_Series::AMD_Ryzen_9 :out<<"AMD Ryzen 9"; break;

    }

    out<<"\n";
}

string CPU::promo_code_() {return "";}