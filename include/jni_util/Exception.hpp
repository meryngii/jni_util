
#ifndef JNI_UTIL_EXCEPTION_HPP
#define JNI_UTIL_EXCEPTION_HPP

#include <jni.h>
#include <cassert>
#include <exception>
#include <stdexcept>

namespace jni_util
{

class JavaException : public std::exception { };

template <typename Func>
inline void convertException(JNIEnv* env, Func func) noexcept
{
    try {
        func();
    } catch (JavaException& e) {
        return;
    } catch (std::exception& e) {
        jclass classj = env->FindClass("Ljava/lang/RuntimeException:");
        if (classj == nullptr)
            return;
        
        env->ThrowNew(classj, e.what());
        env->DeleteLocalRef(classj);
    }
}

inline void checkException(JNIEnv* env)
{
    if (env->ExceptionOccurred())
        throw JavaException();
}

}

#endif

