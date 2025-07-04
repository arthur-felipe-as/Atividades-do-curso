#include <iostream>
using namespace std;

int mdc1(int a, int b){
    int mdc = a, aux;
    if(a > b){
        aux = a;
        while(b != 0){
            a = b;
            b = aux%b;
            aux = a;
            cout << "MDC de " << a << " " << b << endl;
        }
        mdc = aux;
    }
    
    if(a < b){
        aux = b;
        while(a != 0){
            b = a;
            a = aux%a;
            aux = b;
            cout << "MDC de " << b  << " " << a << endl;
        }
        mdc = aux;

    }
    return mdc;
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << mdc1(a,b) << endl;
    return 0;
}