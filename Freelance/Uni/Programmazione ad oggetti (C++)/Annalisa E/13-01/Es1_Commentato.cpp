#include <iostream>
#include <vector>
using namespace std;

class QString {
private:
	string q;
public:
	QString(const char* str) { q = str;}	
};

class QPaintDevice {
private:
	int h, w;
public:
	virtual ~QPaintDevice(){}
	
	int height() const {return h;}
	int width() const {return w;}
	
	QPaintDevice(int a=40, int l=40): h(a), w(l){}
};

class QWidget : public QPaintDevice {
private:
	bool focus;
public:
	bool hasFocus() const {return focus;}
	void clearFocus() {focus = false;}
	
	QWidget(int a=40, int l=40, bool f=true): QPaintDevice(a,l), focus(f){}
};

class QAbstractButton : public QWidget {
private:
	QString ettichetta;
public:
	void setText(const QString& s) {
		ettichetta = s;
	}
	
	QAbstractButton(int a=40, int l=40, bool f=true, QString e=" "): QWidget(a, l, f), ettichetta(e){}
};

vector<QAbstractButton*> fun(const vector<QPaintDevice*>& v){
    vector<QAbstractButton*> ret;
    for(auto it = v.begin(); it != v.end(); ++it){
        if(dynamic_cast<QWidget*>(*it) && (dynamic_cast<QWidget*>(*it))->height() > 50 && (dynamic_cast<QWidget*>(*it))->width() > 50){
            throw QString("TooBig");
        }
        if(dynamic_cast<QWidget*>(*it)->hasFocus()){
            dynamic_cast<QWidget*>(*it)->clearFocus();
        }
        if(dynamic_cast<QAbstractButton*>(*it)){
            dynamic_cast<QAbstractButton*>(*it)->setText("Pulsante");
            ret.push_back(dynamic_cast<QAbstractButton*>(*it));
        }
    }
    return ret;
}