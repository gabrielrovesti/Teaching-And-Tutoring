#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;
 
template<class Functor>
vector<int> find_template(const vector<int>& v, Functor t) {
    vector<int> r;
    for(auto it = v.begin(); it != v.end(); it++) {
        if(t(*it))
            r.push_back(*it);
        
    }
    return r;
}
 
unsigned int find_1(const vector<int>& v, int k) {
    vector<int> w = find_template(v, [v,k] (int n) {return n>k;} );
    return w.size();
}
 
vector<int> find_2(const vector<int>& v, int k) {
    cout<<"dim"<<v.size()<<endl;
    return find_template(v, [v, k] (int n) {return n<v.size();});
}
 
int main() {
    vector<int> v1 = {3,6,4,6,2,5,-2,4,2}; 
    vector<int> v2 = {-2,-6,4,4,2,5,0,4,2,3,2,0};
 
    cout << find_2(v1).size(); cout << endl; //dim9 8
    cout << find_2(v2).size(); cout << endl; //dim12 10
}


