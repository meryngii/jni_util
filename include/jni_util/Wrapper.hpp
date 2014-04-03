
#ifndef JNI_UTIL_WRAPPER_HPP
#define JNI_UTIL_WRAPPER_HPP

#include "Exception.hpp"
#include <utility>

namespace jni_util
{

template <typename T>
class Wrapper
{
public:
    explicit Wrapper(JNIEnv* env, jobject objj)
        : env_(env), objj_(objj)
    {
        assert(env_ != nullptr);
        assert(objj_ != nullptr);
    }
    Wrapper(const Wrapper&) = default;
    
    Wrapper& operator = (const Wrapper&) = default;
    
    T& get() const {
        T* ptr = getPointer();
        if (!ptr) {
            throw std::runtime_error("Uninitialized native object was used!");
        }
        
        return *ptr;
    }
    
    template <typename... Args>
    void create(Args&&... args) const {
        destroy(); // delete if an object exists
        setPointer(new T(std::forward(args)...));
    }
    
    void destroy() const {
        delete getPointer();
        setPointer(nullptr);
    }
    
    // Pointer Operations
    
    T* getPointer() const {
        return reinterpret_cast<T*>(env_->GetLongField(objj_, getFieldID(objj_)));
    }
    
    void setPointer(T* ptr) const { 
        env_->SetLongField(objj_, getFieldID(objj_), reinterpret_cast<jlong>(ptr));
    }
    
private:
    jfieldID getFieldID(jobject objj) const {
        if (!classj_) {
            classj_ = env_->GetObjectClass(objj_);
            checkException(env_);
        }
        
        if (!fieldID_) {
            fieldID_ = env_->GetFieldID(classj_, "mHandle", "J");
            checkException(env_);
        }
        
        return fieldID_;
    }

private:
    JNIEnv* env_;
    jobject objj_;
    static jclass classj_;
    static jfieldID fieldID_;
};

template <typename T>
jclass Wrapper<T>::classj_ = nullptr;

template <typename T>
jfieldID Wrapper<T>::fieldID_ = nullptr;

}

#endif

