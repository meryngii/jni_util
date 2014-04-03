
#ifndef JNI_UTIL_EXCEPTION_HPP
#define JNI_UTIL_EXCEPTION_HPP

#include <jni.h>
#include <cassert>
#include <exception>
#include <stdexcept>

namespace jni_util
{

class JavaException : public std::exception { };

inline void throwRuntimeException(JNIEnv* env, const char* what)
{
    jclass classj = env->FindClass("Ljava/lang/RuntimeException:");
    if (classj == nullptr)
        return;
    
    env->ThrowNew(classj, what);
    env->DeleteLocalRef(classj);
}

template <typename Func>
inline void convertException(JNIEnv* env, Func func) noexcept
{
    try {
        func();
    } catch (JavaException& e) {
        return;
    } catch (std::exception& e) {
        throwRuntimeException(env, e.what());
    } catch (...) {
        throwRuntimeException(env, "Unindentified exception thrown (not derived from std::exception)");
    }
}

inline void checkException(JNIEnv* env)
{
    if (env->ExceptionOccurred())
        throw JavaException();
}

}

#endif

