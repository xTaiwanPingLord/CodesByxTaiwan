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

# OOP
## [Lambda expressions(c++)](https://en.cppreference.com/w/cpp/language/lambda)
`[capture list] (params list) mutable exception-> return type { function body }`
`[capture list] (params list) {function body;}` compiler set return type automatically



> [] don't capture anything
> [a] capture **a** 
> [&] capture everthing needed (by refrence)
> [=] capture everthing needed (by value)
> [=, &a] capture a by refrence and everything else by value
> [this] (in class) capture current class variables and functions by reference
> [*this] same but by value

auto function = 

# Fun
- [如何写出无法维护的代码](https://coolshell.cn/articles/4758.html)
- [五种应该避免的代码注释](https://coolshell.cn/articles/2746.html)
- [如何加密/混乱C源代码](https://coolshell.cn/articles/933.html)
- 