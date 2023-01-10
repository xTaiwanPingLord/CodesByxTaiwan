#pragma region some_def
#include <bits/stdc++.h>
using namespace std;

#ifdef FMT_DEBUG
#define FMT_HEADER_ONLY
#include <fmt/include/fmt/core.h>
#else
namespace fmt
{
    void format(...) { return; };
    void print(...) { return; };
    void join(...) { return; };
};
#endif

template <typename T>
inline T ReadOne()
{
    T temp;
    std::cin >> temp;
    return temp;
}
#pragma endregion some_def

int main()
{
    cout << "yes" << endl;
    fmt::print("YES");

    string test = ReadOne<string>();
    cout << test;
}