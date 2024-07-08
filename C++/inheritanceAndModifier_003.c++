#include<iostream>
using namespace std;

class acces_specifier_test{
    public:
        int public_var = 10;
    private:
        int private_var = public_var * 10;
    protected:
        int protected_var = private_var * 10;
    
    public:
        int get_protected_var();
        int get_private_var();
};

int acces_specifier_test :: get_protected_var(){
    return protected_var;
}

int acces_specifier_test :: get_private_var(){
    return private_var;
}

int main(){
    acces_specifier_test a;
    cout << "The value of public variable of the test "<< a.public_var << endl;
    cout << "The value of private variable of the test "<< a.get_private_var() << endl;
    cout << "The value of protected variable of the test "<< a.get_protected_var() << endl;
    return 0;
}
