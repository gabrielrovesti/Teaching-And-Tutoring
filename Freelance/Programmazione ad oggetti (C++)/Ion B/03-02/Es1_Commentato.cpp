template<class T1, class T2>
bool Fun(T1* ptr, T2& ref){
    if(typeid(T1) == typeid(T2) &&
    typeid(*ptr) == typeid(ref) &&
    dynamic_cast<Abs*>(ptr))

    return true;

    else return false;
}