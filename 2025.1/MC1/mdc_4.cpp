#include <iostream>
using namespace std;

void mdc2(int a, int b, int res[]){
    int ain = a, bin = b;
    int aux = a, s0 = 1, t0 = 0, s1 = 0, t1 = 1, s, t;
        while(b != 0){
            int q = a/b;
            s = s0 - s1 * q;
            t = t0 - t1 * q;
            s0 = s1;
            s1 = s;
            t0 = t1;
            t1 = t;
            a = b;
            b = aux%b;
            aux = a;
            if(b != 0){
                cout << ain  << " * " << s << " + " << bin << " * " << t << " = " << b << endl;
                res[1] = s;
                res[2] = t;
            }
        }
        res[0] = aux;
    return;
}

int main(){
    int a, b, res[3]; //Array que conterá o mdc, s e t, respectivamente
    cin >> a >> b;
    mdc2(a, b, res);
    cout << "MDC = " << res[0] << " s = " << res[1] << " t = " << res[2] << endl;
    return 0;
}