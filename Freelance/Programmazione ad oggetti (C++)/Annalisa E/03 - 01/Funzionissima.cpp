vector<QAbstractButton*> fun(list<QWidget*>& l, const QSize& sz) {
    vector<QAbstractButton*> v;

    for(auto it = l.begin(); it != l.end(); ++it){
        if((*it) && (*it)->sizeHint() == sz){
            l.push_back((*it)->clone());
        }
    }
    return v;
}