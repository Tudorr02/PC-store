
#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H

#include<stdexcept>
#include <iostream>

class error_app :public std::runtime_error{

    using std::runtime_error::runtime_error;
};

class input_error: public error_app{

public:
    explicit input_error(const std::string & txt):error_app(txt){
        std::cout<<"<!><!><!>INPUT ERROR ";
    }
};


class constructor_error: public input_error{
public:
    explicit constructor_error(const std::string& error_text,const std::string & input):input_error(error_text){
        std::cout<<"-> Construcor error : \n";
        std::cout<<"- Your input : ["<<input<<"] ,";
    }

    explicit constructor_error(const std::string& error_text,const int & input):input_error(error_text){
        std::cout<<"-> Construcor error : \n";
        std::cout<<"- Your input : ["<<input<<"] ,";
    }

    explicit constructor_error(const std::string& error_text):input_error(error_text){
        std::cout<<"-> Construcor error : \n";
    }


};

class deposit_error:public error_app{

public:
    explicit deposit_error(const std::string & text):error_app(text){
        std::cout<<"-> Deposit error :\n- ";
    }
};



#endif
