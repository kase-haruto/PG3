#include <iostream>
#include <type_traits>

template<typename T1, typename T2>
class Comparison{
public:
    Comparison() = default;
    ~Comparison() = default;

    // Minƒƒ\ƒbƒh‚ÅˆÙ‚È‚éŒ^“¯m‚ğ”äŠr
    auto Min(T1 val1, T2 val2) const;
};

template<typename T1, typename T2>
auto Comparison<T1, T2>::Min(T1 val1, T2 val2) const{
    using CommonType = typename std::common_type<T1, T2>::type;
    if (static_cast< CommonType >(val1) <= static_cast< CommonType >(val2)){
        return static_cast< CommonType >(val1);
    } else{
        return static_cast< CommonType >(val2);
    }
}


/////////////////////////////////////////////////////////////////////////////////////////
//                  main
/////////////////////////////////////////////////////////////////////////////////////////

int main(){
    int intVal = 2;
    float floatVal = 4.0f;
    double doubleVal = 1.0;

    // ˆÙ‚È‚é•û‚Å”äŠr
    Comparison<int, float> intFloatComparison;
    Comparison<float, double> floatDoubleComparison;
    Comparison<int, double> intDoubleComparison;

    std::cout << "int and float Min: " << intFloatComparison.Min(intVal, floatVal) << std::endl;
    std::cout << "float and double Min: " << floatDoubleComparison.Min(floatVal, doubleVal) << std::endl;
    std::cout << "int and double Min: " << intDoubleComparison.Min(intVal, doubleVal) << std::endl;

    // ƒvƒƒOƒ‰ƒ€‚ÌI—¹‘O‚Éˆê’â~
    std::cin.get();

    return 0;
}

