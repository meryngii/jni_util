
#ifndef JNI_UTIL_ARRAYACCESS_HPP
#define JNI_UTIL_ARRAYACCESS_HPP

#include <jni.h>
#include <cassert>

namespace jni_util
{

template <typename Elem>
struct ArrayFunctions;

template <>
struct ArrayFunctions<jboolean> {
    using Elem = jboolean;
    using jArray = jbooleanArray;
    static jArray NewArray(JNIEnv* env, jsize length) { return env->NewBooleanArray(length); }
    static Elem* GetArrayElements(JNIEnv* env, jArray arrayj, jboolean* isCopy) { return env->GetBooleanArrayElements(arrayj, isCopy); }
    static void ReleaseArrayElements(JNIEnv* env, jArray arrayj, Elem* elems, jint mode) { env->ReleaseBooleanArrayElements(arrayj, elems, mode); }
    static void GetArrayRegion(JNIEnv* env, jArray arrayj, jsize start, jsize, jsize len, Elem* buf) { env->GetBooleanArrayRegion(arrayj, start, len, buf); }
    static void SetArrayRegion(JNIEnv* env, jArray arrayj, jsize start, jsize, jsize len, Elem* buf) { env->SetBooleanArrayRegion(arrayj, start, len, buf); }
};

template <>
struct ArrayFunctions<jbyte> {
    using Elem = jbyte;
    using jArray = jbyteArray;
    static jArray NewArray(JNIEnv* env, jsize length) { return env->NewByteArray(length); }
    static Elem* GetArrayElements(JNIEnv* env, jArray arrayj, jboolean* isCopy) { return env->GetByteArrayElements(arrayj, isCopy); }
    static void ReleaseArrayElements(JNIEnv* env, jArray arrayj, Elem* elems, jint mode) { env->ReleaseByteArrayElements(arrayj, elems, mode); }
    static void GetArrayRegion(JNIEnv* env, jArray arrayj, jsize start, jsize, jsize len, Elem* buf) { env->GetByteArrayRegion(arrayj, start, len, buf); }
    static void SetArrayRegion(JNIEnv* env, jArray arrayj, jsize start, jsize, jsize len, Elem* buf) { env->SetByteArrayRegion(arrayj, start, len, buf); }
};

template <>
struct ArrayFunctions<jchar> {
    using Elem = jchar;
    using jArray = jcharArray;
    static jArray NewArray(JNIEnv* env, jsize length) { return env->NewCharArray(length); }
    static Elem* GetArrayElements(JNIEnv* env, jArray arrayj, jboolean* isCopy) { return env->GetCharArrayElements(arrayj, isCopy); }
    static void ReleaseArrayElements(JNIEnv* env, jArray arrayj, Elem* elems, jint mode) { env->ReleaseCharArrayElements(arrayj, elems, mode); }
    static void GetArrayRegion(JNIEnv* env, jArray arrayj, jsize start, jsize, jsize len, Elem* buf) { env->GetCharArrayRegion(arrayj, start, len, buf); }
    static void SetArrayRegion(JNIEnv* env, jArray arrayj, jsize start, jsize, jsize len, Elem* buf) { env->SetCharArrayRegion(arrayj, start, len, buf); }
};

template <>
struct ArrayFunctions<jshort> {
    using Elem = jshort;
    using jArray = jshortArray;
    static jArray NewArray(JNIEnv* env, jsize length) { return env->NewShortArray(length); }
    static Elem* GetArrayElements(JNIEnv* env, jArray arrayj, jboolean* isCopy) { return env->GetShortArrayElements(arrayj, isCopy); }
    static void ReleaseArrayElements(JNIEnv* env, jArray arrayj, Elem* elems, jint mode) { env->ReleaseShortArrayElements(arrayj, elems, mode); }
    static void GetArrayRegion(JNIEnv* env, jArray arrayj, jsize start, jsize, jsize len, Elem* buf) { env->GetShortArrayRegion(arrayj, start, len, buf); }
    static void SetArrayRegion(JNIEnv* env, jArray arrayj, jsize start, jsize, jsize len, Elem* buf) { env->SetShortArrayRegion(arrayj, start, len, buf); }
};

template <>
struct ArrayFunctions<jint> {
    using Elem = jint;
    using jArray = jintArray;
    static jArray NewArray(JNIEnv* env, jsize length) { return env->NewIntArray(length); }
    static Elem* GetArrayElements(JNIEnv* env, jArray arrayj, jboolean* isCopy) { return env->GetIntArrayElements(arrayj, isCopy); }
    static void ReleaseArrayElements(JNIEnv* env, jArray arrayj, Elem* elems, jint mode) { env->ReleaseIntArrayElements(arrayj, elems, mode); }
    static void GetArrayRegion(JNIEnv* env, jArray arrayj, jsize start, jsize, jsize len, Elem* buf) { env->GetIntArrayRegion(arrayj, start, len, buf); }
    static void SetArrayRegion(JNIEnv* env, jArray arrayj, jsize start, jsize, jsize len, Elem* buf) { env->SetIntArrayRegion(arrayj, start, len, buf); }
};

template <>
struct ArrayFunctions<jlong> {
    using Elem = jlong;
    using jArray = jlongArray;
    static jArray NewArray(JNIEnv* env, jsize length) { return env->NewLongArray(length); }
    static Elem* GetArrayElements(JNIEnv* env, jArray arrayj, jboolean* isCopy) { return env->GetLongArrayElements(arrayj, isCopy); }
    static void ReleaseArrayElements(JNIEnv* env, jArray arrayj, Elem* elems, jint mode) { env->ReleaseLongArrayElements(arrayj, elems, mode); }
    static void GetArrayRegion(JNIEnv* env, jArray arrayj, jsize start, jsize, jsize len, Elem* buf) { env->GetLongArrayRegion(arrayj, start, len, buf); }
    static void SetArrayRegion(JNIEnv* env, jArray arrayj, jsize start, jsize, jsize len, Elem* buf) { env->SetLongArrayRegion(arrayj, start, len, buf); }
};

template <>
struct ArrayFunctions<jfloat> {
    using Elem = jfloat;
    using jArray = jfloatArray;
    static jArray NewArray(JNIEnv* env, jsize length) { return env->NewFloatArray(length); }
    static Elem* GetArrayElements(JNIEnv* env, jArray arrayj, jboolean* isCopy) { return env->GetFloatArrayElements(arrayj, isCopy); }
    static void ReleaseArrayElements(JNIEnv* env, jArray arrayj, Elem* elems, jint mode) { env->ReleaseFloatArrayElements(arrayj, elems, mode); }
    static void GetArrayRegion(JNIEnv* env, jArray arrayj, jsize start, jsize, jsize len, Elem* buf) { env->GetFloatArrayRegion(arrayj, start, len, buf); }
    static void SetArrayRegion(JNIEnv* env, jArray arrayj, jsize start, jsize, jsize len, Elem* buf) { env->SetFloatArrayRegion(arrayj, start, len, buf); }
};

template <>
struct ArrayFunctions<jdouble> {
    using Elem = jdouble;
    using jArray = jdoubleArray;
    static jArray NewArray(JNIEnv* env, jsize length) { return env->NewDoubleArray(length); }
    static Elem* GetArrayElements(JNIEnv* env, jArray arrayj, jboolean* isCopy) { return env->GetDoubleArrayElements(arrayj, isCopy); }
    static void ReleaseArrayElements(JNIEnv* env, jArray arrayj, Elem* elems, jint mode) { env->ReleaseDoubleArrayElements(arrayj, elems, mode); }
    static void GetArrayRegion(JNIEnv* env, jArray arrayj, jsize start, jsize, jsize len, Elem* buf) { env->GetDoubleArrayRegion(arrayj, start, len, buf); }
    static void SetArrayRegion(JNIEnv* env, jArray arrayj, jsize start, jsize, jsize len, Elem* buf) { env->SetDoubleArrayRegion(arrayj, start, len, buf); }
};

template <typename Elem>
class CopiedArrayAccess
{
public:
    using Helper = ArrayFunctions<Elem>;
    using jArray = typename Helper::jArray;
    
    CopiedArrayAccess(JNIEnv* env, jArray arrayj, jint mode = 0)
        : env_(env), arrayj_(arrayj)
    {
        assert(env_ != nullptr);
        assert(arrayj_ != nullptr);
        
        elems_ = Helper::GetArrayElements(env_, arrayj_, &isCopy_);
    }
    CopiedArrayAccess(const CopiedArrayAccess&) = delete;
    
    ~CopiedArrayAccess() {
        if (elems_ != nullptr)
            Helper::ReleaseArrayElements(env_, arrayj_, elems_, mode_);
    }
    
    CopiedArrayAccess& operator = (const CopiedArrayAccess&) = delete;
    
    Elem* elements() const { return elems_; }
    
    jsize length() const {
        return env_->GetArrayLength(arrayj_);
    }
    
    jboolean isCopy() const { return isCopy_; }
    
private:
    JNIEnv* env_;
    jArray arrayj_;
    Elem* elems_;
    jboolean isCopy_;
    jint mode_;
};

template <typename Elem>
class RegionalArrayAccess
{
public:
    using Helper = ArrayFunctions<Elem>;
    using jArray = typename Helper::jArray;
    
    RegionalArrayAccess(JNIEnv* env, jArray arrayj)
        : env_(env), arrayj_(arrayj)
    {
        assert(env_ != nullptr);
        assert(arrayj_ != nullptr);
    }
    RegionalArrayAccess(const RegionalArrayAccess&) = delete;
    
    ~RegionalArrayAccess() { }
    
    Elem get(jsize index) const {
        Elem result;
        Helper::GetArrayRegion(env_, arrayj_, index, 1, &result);
        return result;
    }
    void set(jsize index, Elem val) {
        Helper::SetArrayRegion(env_, arrayj_, index, 1, &val);
    }
    
    jsize length() const { return env_->GetArrayLength(arrayj_); }
    
    RegionalArrayAccess& operator = (const RegionalArrayAccess&) = delete;
    
private:
    JNIEnv* env_;
    jArray arrayj_;
};

template <>
class RegionalArrayAccess<jobject>
{
public:
    using jArray = jobjectArray;
    using Elem = jobject;
    
    RegionalArrayAccess(JNIEnv* env, jArray arrayj)
        : env_(env), arrayj_(arrayj)
    {
        assert(env_ != nullptr);
        assert(arrayj_ != nullptr);
    }
    
    RegionalArrayAccess(const RegionalArrayAccess&) = delete;
    
    ~RegionalArrayAccess() { }
    
    Elem get(jsize index) const {
        return env_->GetObjectArrayElement(arrayj_, index);
    }
    void set(jsize index, jobject value) {
        env_->SetObjectArrayElement(arrayj_, index, value);
    }
    
    jsize length() const { return env_->GetArrayLength(arrayj_); }
    
private:
    JNIEnv* env_;
    jArray arrayj_;
};

}

#endif

