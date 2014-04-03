
#ifndef JNI_UTIL_STRINGACCESS_HPP
#define JNI_UTIL_STRINGACCESS_HPP

#include <jni.h>
#include <cassert>

namespace jni_util
{

class StringAccess
{
public:
    StringAccess(JNIEnv* env, jstring strj)
        : env_(env), strj_(strj)
    {
        assert(env_ != nullptr);
        assert(strj_ != nullptr);
        
        str_ = env_->GetStringUTFChars(strj_, &isCopy_);
    }
    StringAccess(const StringAccess&) = delete;
    
    ~StringAccess() {
        if (str_ != nullptr)
            env_->ReleaseStringUTFChars(strj_, str_);
    }
    
    StringAccess& operator = (const StringAccess&) = delete;
    
    const char* pointer() const { return str_; }
    
    jboolean isCopy() { return isCopy_; }
    
private:
    JNIEnv* env_;
    jstring strj_;
    const char* str_;
    jboolean isCopy_;
};

}

#endif

