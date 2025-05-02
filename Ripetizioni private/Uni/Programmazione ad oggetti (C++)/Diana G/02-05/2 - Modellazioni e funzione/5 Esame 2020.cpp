class Abs{};

template<class T1, class T2>
bool fun(T1* ptr, T2& ref){
    if(typeid(T1) == typeid(T2) &&
    dynamic_cast<Abs*>(*ptr) &&
    typeid(*ptr) == typeid(ref)
    ) return true;
    return false;
}