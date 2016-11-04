#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>

#include <android/log.h>

const char* LOG_TAG = "test";

class Test
{
public:
    Test();
    virtual ~Test();
    
public:
    void run();
    
private:
    void test_vector();
    void test_map();
    void test_string();
};

Test::Test()
{
    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "Test constructor.");
}

Test::~Test()
{
    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "Test destructor.");
}

void Test::run()
{
    this->test_vector();
    this->test_map();
    this->test_string();
}

void Test::test_vector()
{
    std::vector<std::string> v;
    v.push_back("Hello,World!");
    v.push_back("C++ STL!");
    std::vector<std::string>::const_iterator it = v.begin();
    while(it != v.end())
    {
        __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "%s", it->c_str());
        it++;
    }
}

void Test::test_map()
{
    std::map<int,int> v;
    v[0] = 1;
    v[1] = 2;
    std::map<int, int>::const_iterator it = v.begin();
    while (it != v.end())
    {
        __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "key:%d,value:%d", it->first, it->second);
    }
}

void Test::test_string()
{
    std::string a = "Hello";
    std::string b = "Good morning";
    std::string c = "Goog night";
    std::string d = a + b + c;
    d += "Hello";
    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "%s", d.c_str());
}



void test()
{
    Test* t = new Test();
    t->run();
    delete t;
}