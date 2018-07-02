//#include <jni.h>
//#include <string>
//
//#include <stdlib.h>
//#include "markdown2json/Parser.hpp"
//#include "wstring_utils.hpp"
//#include "json2markdown/Json2MarkdownParser.hpp"
//
//extern "C"
//JNIEXPORT jstring JNICALL
//Java_com_bytedance_ee_bear_creation_util_MarkdownJsonConverter_markdown2json(JNIEnv *env, jclass type,
//                                                                           jstring markdown_) {
//    const char *markdown = env->GetStringUTFChars(markdown_, 0);
//
//    std::string ret = Sunset::markdown_to_json(markdown);
//
//    env->ReleaseStringUTFChars(markdown_, markdown);
//
//    return env->NewStringUTF(ret.c_str());
//}
//
//extern "C"
//JNIEXPORT jstring JNICALL
//Java_com_bytedance_ee_bear_creation_util_MarkdownJsonConverter_json2markdown(JNIEnv *env, jclass type,
//                                                                           jstring jsonStr_) {
//    const char *jsonStr = env->GetStringUTFChars(jsonStr_, 0);
//
//    std::string ret = Sunset::json_to_markdown(jsonStr);
//
//    env->ReleaseStringUTFChars(jsonStr_, jsonStr);
//
//    return env->NewStringUTF(ret.c_str());
//}
