#include <iostream>
using namespace std;

bool sinal_resto(int num, int den, int q){
    if((num - (den * q)) < 0){
        return false;
    }
    return true;
}
int div_1(int num,int den){
    bool parou = false;
    int i = 0;
    int q = 0; 
    do{
        parou = true;
        if(num > 0){
            if(den * i <= num){
                q = i;
                (den > 0) ? i++ : i--;
                parou = false;
            }
            else{
                if(sinal_resto(num, den, q) == false){
                    (den > 0) ? q++ : q--;
                }
                return q;
            }
        }
        if(num < 0){
            if(den * i >= num){
                q = i;
                (den > 0) ? i-- : i++;
                parou = false;
            }
            else{
                if(sinal_resto(num, den, q) == false){
                    (den > 0) ? q-- : q++;
                }
                return q;
            }
        }
    }while(parou == false);
    
    return q;
}

int mod_1(int num, int den){
    int r = num - den * div_1(num, den);
    return r;
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << mod_1(a,b) << endl;
    return 0;
}



