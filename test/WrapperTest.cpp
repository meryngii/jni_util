
#include <jni.h>
#include <iostream>
#include <vector>

#include "jni_util.hpp"

class WrapperTest
{
public:
    WrapperTest() { std::cout << "WrapperTest constructed." << std::endl; }
    ~WrapperTest() { std::cout << "WrapperTest destructed." << std::endl; }

    void put(int x) { data_.push_back(x); }
    
    void show() {
        for (int x : data_)
            std::cout << x << " ";

        std::cout << std::endl;
    }
    
private:
    std::vector<int> data_;
};

extern "C" {

JNIEXPORT void JNICALL Java_WrapperTest_init
  (JNIEnv* env, jobject thisj)
{
    jni_util::convertException(env, [=] () {
        jni_util::Wrapper<WrapperTest>(env, thisj).create();
    });
}

JNIEXPORT void JNICALL Java_WrapperTest_put
  (JNIEnv* env, jobject thisj, jint x)
{
    jni_util::convertException(env, [=] () {
        auto& self = jni_util::Wrapper<WrapperTest>(env, thisj).get();
        self.put(x);
    });
}

JNIEXPORT void JNICALL Java_WrapperTest_show
  (JNIEnv* env, jobject thisj)
{
    jni_util::convertException(env, [=] () {
        jni_util::Wrapper<WrapperTest>(env, thisj).get().show();
    });
}

JNIEXPORT void JNICALL Java_WrapperTest_destroy
  (JNIEnv* env, jobject thisj, jstring strj)
{
    jni_util::convertException(env, [=] () {
        jni_util::Wrapper<WrapperTest>(env, thisj).destroy();
    });
}

}

