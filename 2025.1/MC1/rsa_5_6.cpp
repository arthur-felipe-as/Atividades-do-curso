#include <cstring>
#include <iostream>
#include <numeric> //Compilar usando o comando g++ -std=c++17 RSA1.cpp
#include <cmath>
using namespace std;




long long int* dec_bin(long long int n, long long int k){
    long long int *bin = new long long int[k];
    for(long long int i = 0; i < k; i++){
        bin[i] = n%2;
        n = n/2;
    }
    return bin;
}


long long int mod_exp(long long int b, long long int n, long long int m){
    long long int x = 1;
    long long int potencia = b%m;
    long long int k = log2(n+1)+1;
    long long int *bin = dec_bin(n, k);
    for(long long int i = 0; i < k; i++){
        if(bin[i] == 1){
            x = (x * potencia)%m;
        }
        potencia = (potencia * potencia)%m;
    }
    return x;
}

long long int t_bezout(long long int a, long long int b){
    long long int aux = a, t0 = 0, t1 = 1, t;
    long long int tfin;
        while(b != 0){
            long long int q = a/b;
            t = t0 - t1 * q;
            t0 = t1;
            t1 = t;
            a = b;
            b = aux%b;
            aux = a;
            if(b != 0){
                tfin = t;
            }
        }
    return tfin;
}

long long int find_d(long long int e, long long int tot){ // d*e = 1 mod tot
    long long int d = t_bezout(tot, e);
    if(d < 0){
        d += tot;
    }
    return d;
}



long long int find_e(long long int tot){
    long long int e;
    for (long long int i = 0; i < 5; i++){
        e = pow(2, pow(2,i)) + 1; //Primos de Fermat
        if(gcd(tot,e) == 1 and e < tot){
            return e;
        }
    }
    return 0;
}





long long int* encode(long long int n, long long int e, string m){
    int tamanho = m.length();
    long long int* c = new long long int[tamanho]; 
    for(long long int i = 0; i < tamanho; i++){
        c[i] = m[i];
        c[i] = mod_exp(c[i], e, n);
    }
    return c;
}

string decode(long long int n, long long int d, long long int* c_int, string c_char){
    string m;
    for(int i = 0; i < c_char.size(); i++){
        c_int[i] = mod_exp(c_int[i], d, n);
        
        m += c_int[i];
    }
    return m;
}

void rsa(long long int p,long long int q, string m){
    int tam = m.length();
    long long int *mensagem_int = new long long int[tam];
    long long int n = p * q;
    cout << "n = " << n << endl;

    long long int tot = (p-1) * (q-1);
    cout << "tot = " << tot << endl;

    long long int e = find_e(tot);
    cout << "e = " << e << endl;

    long long int d = find_d(e, tot);
    cout << "d = " << d << endl;

    mensagem_int = encode(n, e, m);
    for(int i = 0; i < tam; i++){
        cout << mensagem_int[i] << " ";
    }
    cout << endl;

    cout << decode(n, d, mensagem_int, m) << endl;

}


int main(){
    long long int p, q;
    string mensagem;
    cin >> p >> q;
    getline(cin, mensagem);
    rsa(p,q,mensagem);
    
    return 0;
}