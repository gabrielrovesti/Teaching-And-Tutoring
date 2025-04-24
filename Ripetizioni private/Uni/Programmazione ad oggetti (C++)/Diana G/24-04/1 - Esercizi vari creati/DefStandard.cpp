// Ridefinire il distruttore della classe DataBlock in modo che gestisca correttamente la memoria allocata

// (1)

class DataBlock {
    private:
        int size;
        double* values;
    public:
    // Distruttore
    ~DataBlock(){
        delete[] values;
    }   
    // Copia profonda
    DataBlock(const DataBlock& data){
        size = data.size;
        values = data.values;
    }
    // Alternativa - lista di inizializzazione (:)

    DataBlock(const DataBlock& data): size(data.size), 
    values(data.values != nullptr ? new double(*data.values) : nullptr) {};

    // Costruttore standard
    DataBlock(int sz, double* val): size(sz), values(val) {};

    // Assegnazione standard
    DataBlock& operator=(const DataBlock& data){
        // se stessa area di memoria
        if(this != &data){
            size = data.size;
            values = data.values;
        }
        return *this;
    }

    // Operatore di diversità (uguaglianza stessa roba)
    bool operator!=(const DataBlock& data){
        if(data.size != size && values != data.values) return true;
        return false;
    }
};

// Classe astratta = Virtuale pura (Gerarchia)
class BaseProcessor {
    protected:
        DataBlock data;
        virtual void preprocess() = 0; // virtuale puro = da ridefinire (per forza!) nelle sottoclassi
    public:
        virtual ~BaseProcessor() {}
        virtual void process() = 0;
};

class StatisticalProcessor: virtual public BaseProcessor {
    protected:
        double mean;
        double variance;
    public:
        StatisticalProcessor();
        void preprocess() override;
        virtual double getMean() const;
        double getVariance() const{
            return variance;
        }
};

class RegressionProcessor: virtual public BaseProcessor {
    protected:
        double slope;
        double intercept;
    public:
        RegressionProcessor();
        void preprocess() override;
        virtual double predict(double x) const;
};

class AdvancedProcessor: public StatisticalProcessor, public
RegressionProcessor {
private:
    bool normalized;
    DataBlock* extraData;
public:
    AdvancedProcessor(bool norm = false);
    AdvancedProcessor(const AdvancedProcessor& other);

    // distruttore
    ~AdvancedProcessor(){
        delete[] extraData;
    }

    // assegnazione standard
    AdvancedProcessor& operator=(const AdvancedProcessor& adv){
        // standard
        StatisticalProcessor::operator=(adv);
        RegressionProcessor::operator=(adv);
        // parametri
        normalized = adv.normalized;
        extraData = adv.extraData;
        // return
        return *this;
    }

    // process
    void process(){
        StatisticalProcessor* sp = dynamic_cast<StatisticalProcessor*>(this);
        if(sp) sp->preprocess();

        RegressionProcessor* rp = dynamic_cast<RegressionProcessor*>(this);
        if(rp) rp->preprocess();

        double slope = rp->predict(20);
        double intercept = rp->predict(30);

        if(sp->getVariance() < 1.0){
            normalized = true;
        }
    }
    /*
    Implementare il metodo process() della classe AdvancedProcessor in modo che
    1. chiami entrambe preprocess() delle classi base, 2. calcoli slope e intercept basandosi sui dati
    3. imposti normalized a true se la varianza è minore di 1.0.
    */

    // clonazione polimorfa
    virtual AdvancedProcessor* clone() const{
        return new AdvancedProcessor(*this);
    }

};

// Logica della cancellazione profonda = se non ridefinito, si va a costruire, altrimenti rendiamoci la vita agevole - distruggi();

class Lista{
    class Nodo{
        int info;
        Nodo* next;
    };
    static void distruggi(){}
};

// static = oggetti che restano sempre con stesso valore e vengono cancellati per ultimi

class Bolletta{
    Lista lista;

    ~Bolletta(){
        distruggi();
    }
};