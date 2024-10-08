vector<QWidget> fun(const vector<const QPaintDevice*>& v){
    vector<QWidget> ret;

    for(auto it = v.begin(); it != v.end(); ++it){
        QWidget *q = dynamic_cast<QWidget*>(const_cast<QPaintDevice*>(*it));
        if(q && q->height() > 50){
            throw QString("TooBig");
        }
        
        if(q && q->height() <= 50
        && q->hasFocus()){
            q->clearFocus();
        }

        QAbstractButton *ab = dynamic_cast<QAbstractButton*>(const_cast<QPaintDevice*>(*it));
        if(ab){
            ab->setText("Pulsante");
        }

        if(q && !ab){
            ret.push_back(*q);
        }
    }

    return ret;
}