#include <fstream>
#include <iostream>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;
const char *tmp = nullptr;

char * test(/* const char* test */)
{
    ifstream jsonfile("language.json");
    json lang = json::parse(jsonfile);
    jsonfile.close();

    // cout << "parsed" << endl;
    string temp = lang["settings"]["func1"]["name"]["en-us"].get<string>();
    static char testx[80];
    strcpy(testx, temp.c_str());
    //testx  = (char *)temp.c_str();
    //cout << tmp << "    " << typeid(tmp).name() <<endl;
    // testx = temp.c_str();
    return testx;
}

string test3()
{
    ifstream jsonfile("language.json");
    json lang = json::parse(jsonfile);
    jsonfile.close();

    // cout << "parsed" << endl;
    string temp = lang["settings"]["func1"]["name"]["en-us"].get<string>();
    //const char* testx  = temp.c_str();
    //cout << tmp << "    " << typeid(tmp).name() <<endl;

    return temp;
}

string test2()
{
    ifstream jsonfile("language.json");
    json lang = json::parse(jsonfile);
    jsonfile.close();

    // cout << "parsed" << endl;
    string temp = lang["settings"]["func1"]["name"]["en-us"].get<string>();
    return temp;
}

int main()
{
    // const char tt[1000] = {""};
    // test();
    //test(&tt);
    cout << test();
    //const char *testchar = test();

    //cout << test() << "   char   " << &testchar << "   string   " << test2();
    return 0;
}