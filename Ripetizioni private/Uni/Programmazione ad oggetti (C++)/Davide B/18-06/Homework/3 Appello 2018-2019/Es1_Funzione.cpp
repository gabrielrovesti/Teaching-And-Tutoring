#include <vector>
#include <QAbstractButton>
#include <QAbstractSlider>
#include <QCheckBox>
#include <QPushButton>
#include <QScrollBar>
#include <QSlider>
#include <QWidget>

using namespace std;

//Versione 1
vector<QAbstractButton*> fun(const vector<QWidget*>& lst, const QSize& sz, vector<const QWidget*>& w) {
    vector<QAbstractButton*> v;
    for(auto it=lst.begin(); it!=lst.end(); ++it) {
        if(*it!=nullptr && (*it)->sizeHint()==sz) {
            w.push_back(*it);
        }
        else if(*it!=nullptr && (*it)->sizeHint()!=sz && dynamic_cast<QAbstractSlider*>(*it)==nullptr) {
            delete *it;
            lst.erase(it);
        }
        else if(*it!=nullptr && (*it)->sizeHint()!=sz && dynamic_cast<QAbstractSlider*>(*it)!=nullptr) {
            if(dynamic_cast<QCheckBox*>(*it)!=nullptr || dynamic_cast<QPushButton*>(*it)!=nullptr) {
                v.push_back(dynamic_cast<QAbstractButton*>(*it));
                lst.erase(it);
            }
        }
    }
    return v;
}

//Versione 2
vector<QAbstractButton*> fun(list<QWidget*>&q, const QSize& sz, vector <const QWidget*>& v){
   vector<QAbstractButton*> v;
   list<QWidget*>::iterator it = q.begin();

   for(; it!=v.end(); ++it){
       if(*it && (*it)->sizeHint() == size) v.push_back((*it)->clone());
       QAbstractSlider *s=dynamic_cast<QWidget*>(*it);
       if((*it) && !s && (*it)->sizeHint() == s){
            delete *it; 
            it = q.erase(it);
       }
       if((*it) && dynamic_cast<QCheckBox*>(*it) || dynamic_cast<QPushButton*>(*it)){
           v.push_back(static_cast<QAbstractButton*>(*it));
           it=q.erase(it);
       }
   }
   return v;
}