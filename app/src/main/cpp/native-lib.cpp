#include <jni.h>
#include <string>
#include <android/log.h>
#define LOG_TAG "LOG_TEST"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROIF_LOG_ERROR,LOG_TAG,__VA_ARGS__)
extern "C"
JNIEXPORT jstring

JNICALL
Java_com_rong_openCV_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

//C/C++字符串转换JNI字符串
//newString函数是用来生成Unicode JNI字符的
//newStringUTF函数是用来生成UTF-8 JNI字符的
extern "C"
JNIEXPORT void
JNICALL
Java_com_rong_openCV_MainActivity_testJString(JNIEnv* env,jobject thiz,jstring jstr){
    char *str = "helloboy";
    jstring jstr2 = env->NewStringUTF(str);
    LOGI("string %s",str);
    const jchar *jchar2 = env ->GetStringChars(jstr,NULL);
    size_t len = env->GetStringLength(jstr);
    jstring jstr3 = env->NewString(jchar2,len);
}

//JNI字符串转换为c/c++字符串
//GetStringChars函数用来从jstring获取Unicode C/C++字符串
//GetStringUTFChars函数用来从jstring获取UTF-8 C/C++字符串
extern "C"
JNIEXPORT void
JNICALL
Java_com_rong_openCV_MainActivity_testJString1(JNIEnv* env,jobject thiz,jstring jstr){
    const char *str = env->GetStringUTFChars(jstr,NULL);
    LOGI("string %s",str);
    const jchar *jchar2 = env->GetStringChars(jstr,NULL);
}

//释放JNI字符串
// ReleaseStringChars函数用来释放Unicode C/C++字符串
//ReleaseStringUTFChars函数用来释放UTF-8 C/C++字符串
extern "C"
JNIEXPORT void
JNICALL
Java_com_rong_openCV_MainActivity_testReleaseJString(JNIEnv* env,jobject thiz,jstring jstr){
    const char *str = env->GetStringUTFChars(jstr,NULL);
    LOGI("string %s",str);
    env->ReleaseStringUTFChars(jstr,str);
    const jchar *jchar2 = env->GetStringChars(jstr,NULL);
    env->ReleaseStringChars(jstr,jchar2);
}

//JNI字符串截取
//GetStringRegion函数用来截取Unicode JNI字符串
// GetStringUTFRegion函数用来截取UTF-8 JNI字符串
extern "C"
JNIEXPORT void
JNICALL
Java_com_rong_openCV_MainActivity_testRegionJString(JNIEnv* env,jobject thiz,jstring jstr){
    const char *str = env->GetStringUTFChars(jstr,NULL);
    LOGI("string %s",str);
    char *subStr = new char;
    env->GetStringUTFRegion(jstr,0,3,subStr);
    env->ReleaseStringUTFChars(jstr,str);
    LOGI("string %s",subStr);
    const jchar *jchar2 = env->GetStringChars(jstr,NULL);
    jchar *subjchar = new jchar;
    env->GetStringRegion(jstr,0,3,subjchar);
    env->ReleaseStringChars(jstr,jchar2);
}

//获取JNI字符串的长度
//GetStringLength用来获取Unicode JNI字符串的长度
// GetStringUTFLength函数用来获取UTF-8 JNI字符串的长度
extern "C"
JNIEXPORT void
JNICALL
Java_com_rong_openCV_MainActivity_testLengthJString(JNIEnv* env,jobject thiz,jstring jstr){
    jsize len = env->GetStringLength(jstr);
    LOGI("Unicode string length %s",""+len);
    jsize len2 = env->GetStringUTFLength(jstr);
    LOGI("UTF-8 string length %s",""+len2);
}


