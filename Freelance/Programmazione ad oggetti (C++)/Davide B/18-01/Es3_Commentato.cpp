list <QCheckBox> fun<const QWidget*>& vec, const QSize &sz){
    list <QCheckBox> ret;
    for(auto it = vec.begin(); it != v.end(); ++it){
    //for(const QWidget*>::iterator it = v.begin())
        QAbstractSlider *qa = dynamic_cast <QAbstractSlider*>(const_cast<QWidget*>(*it));
        if(qa){
            QSlider *qs = dynamic_cast <QSlider*>(const_cast<QWidget*>(*it));
            if(qs){
                if(qs->size() != sz){
                    qs->resize(sz);
                    qs->setSliderDown(true);
                }
            }
            else{
                qs->resize(sz);
            }
        }
        QAbstractButton *qab = dynamic_cast <QAbstractButton*>(const_cast<QWidget*>(*it));
        if(qab){
            if(qab->isDown()){
                QCheckbox *qcb = dynamic_cast <QCheckbox*>(const_cast<QWidget*>(*it));
                if(qcb) ret.push_back(qcb);
                delete qab;
                it = vec.erase(it);
            }
        }
        return ret;
    }
}