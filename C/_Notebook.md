[C++ 11/14/17/20 比較](https://www.jianshu.com/p/8c4952e9edec)

# Coding rule (Google)
[By google](https://tw-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/formatting.html)
- #define and const `THENAME`
- class `TheName` and function `TheName();`
- 取值和設值函式則要求與變數名匹配 `set_my_exciting_member_variable();`
- variable, namespace, enum `the_name`
- variable in class `the_name_`
- 80 chars per line


# Variables and Operator
> int: -2^31 ~ 2^31 - 1
> long long: -2^63 ~ 2^63 - 1
> char
> float (do not use plz)
> double
> long double
> bool

- Cast type: `(float)intVariable`
- Set float percision: `#include <iomanip> ... setprecision(n);`
- Float comparison: `兩變數相減 差 < 10^-9`
- 
- Modular calculation: ` % `
- i++ vs ++i: `先做i 後+ / 先+後i`
- XOR: ` ^ ` | Power: `math.h and pow(x,y)`

# if else/ switch

- if ( init; condition ) //c++17
- a = 10 ? doWhenTrue() : doWhenFalse();
- switch(expression){
    case constant-expression :
       statement(s);
    default : 
        statement(s);  }

# String and char array

- [ios::sync_with_stdio(0), cin.tie(0);](https://liam.page/2016/11/19/the-speed-of-reading-files-in-Cpp/#std-cin-%E5%81%9A%E4%BA%86%E5%93%AA%E4%BA%9B%E9%A2%9D%E5%A4%96%E7%9A%84%E5%B7%A5%E4%BD%9C)
- prevent using `endl;`


