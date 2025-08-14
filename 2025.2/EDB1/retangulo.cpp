using value_type = int; 

struct Ponto{
    value_type x, y;
};

struct Retangulo{
    Ponto origem;
    value_type largura, altura;
    Retangulo(){
        origem.x = 0;
        origem.y = 0;
        largura = 0;
        altura = 0;
    };

};

bool p_contido_em_r(Retangulo r,Ponto p){
    bool intervalox = false, intervaloy = false; 
    if(r.origem.x <= p.x && p.x <= r.origem.x+r.largura){
        intervalox = true;
    }
    if(r.origem.y <= p.y && p.y <= r.origem.y+r.altura){
        intervaloy = true;
    }
    if(intervalox && intervaloy){
        return true;
    }
    return false;
}

int main(){





    return 0;
}