#include <iostream>

class ContoBancario{
    protected:
        double saldo;
    public:
        double deposita(double d){
            return d >=0 ? saldo += d : saldo; 
        }
        double preleva(double p){
            return p >=0 ? saldo -= p : saldo;
        }
        ContoBancario(double s = 0): saldo(s>=0 ? s : 0){} 
        double getSaldo() const {return saldo;} 
};

class ContoCorrente: public ContoBancario{
    private:
        static double spesaFissa;
    public:
        double deposita(double d){
            return ContoBancario::deposita(d - spesaFissa);
        }
        double preleva(double p){
            return ContoBancario::preleva(p + spesaFissa);
            //ritorno il saldo aggiornato dopo aver aggiunto la spesa fissa
        }
        ContoCorrente(double s = 0): ContoBancario(s){}
};

double ContoCorrente::spesaFissa = 1.0;

class ContoDiRisparmio: public ContoBancario{
    public:
        double preleva(double p){
            if(p <= getSaldo())
                return ContoBancario::preleva(p);
            else
                return getSaldo();
        }
        ContoDiRisparmio(double s = 0.0): ContoBancario(s){}
};

class ContoArancio: public ContoDiRisparmio{
    private:
        ContoCorrente& ContoDiAppoggio; 
    public:
    //Invariante (assunzione): saldo >=0
    double deposita(double d){
        if(d <= getSaldo() && d >= 0){
            ContoDiAppoggio.preleva(d);
            return ContoBancario::deposita(d);
        }
        else
            return getSaldo();
    }
    double preleva(double p){
       if(p >= 0){
            ContoDiAppoggio.deposita(p);
            return ContoBancario::preleva(p);
        }
        else
            return getSaldo();
    }
    ContoArancio(ContoCorrente& ap, double s = 0): ContoDiRisparmio(s), ContoDiAppoggio(ap){}
};

int main(){
    ContoCorrente cc(2000);
    ContoArancio ca(cc, 1500); 
    ca.deposita(350); ca.preleva(400); cc.preleva(150);
    std::cout<< cc.getSaldo() << std::endl;  //stampa: 1897
    std::cout<< ca.getSaldo() << std::endl;  //stampa: 1450
}


