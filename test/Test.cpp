
#include <jni.h>
#include <iostream>

#include "jni_util.hpp"

extern "C" {

JNIEXPORT void JNICALL Java_Test_showString
  (JNIEnv* env, jobject thisj, jstring strj)
{
    jni_util::StringAccess str(env, strj);
    std::cout << str.pointer() << std::endl;
}

JNIEXPORT void JNICALL Java_Test_showIntArray
  (JNIEnv* env, jobject thisj, jintArray arrayj)
{
    jni_util::CopiedArrayAccess<jint> array(env, arrayj);
    
    auto* first = array.elements();
    auto* last  = first + array.length();
    
    std::for_each(first, last, [] (int x) {
        std::cout << x << std::endl;
    });
}

}

