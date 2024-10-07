list<QFrame*> fun(vector<QWidget*>& v) {
    list<QFrame*> l;
    for(auto it = v.begin(); it != v.end(); ++it){
        QLabel *ql = dynamic_vast<QLabel*>(*it);
        if(ql){
            ql->setLineWidth(9);
            ql->setWordWrap(false);
        }
        QLCDNumber *qln = dynamic_vast<QLCDNumber*>(*it);
        if(qln){
            qln->setDigitCount(2);
        }
        QFrame *pqf = dynamic_cast<QFrame*>(*it);
        QSplitter *pqs = dynamic_cast<QSplitter*>(*it);

        if(pqf && !pqs && pqf->heigthForWidth(8) < 16){
            l.push_back(pqf);
        }
    }
    return l;
}