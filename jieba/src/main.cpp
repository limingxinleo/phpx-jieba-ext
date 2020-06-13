#include "phpx.h"
#include "cppjieba/Jieba.hpp"
#include <iostream>

using namespace php;
using namespace std;

const char* const DICT_PATH = "../dict/jieba.dict.utf8";
const char* const HMM_PATH = "../dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "../dict/user.dict.utf8";
const char* const IDF_PATH = "../dict/idf.utf8";
const char* const STOP_WORD_PATH = "../dict/stop_words.utf8";

cppjieba::Jieba jieba(DICT_PATH,
    HMM_PATH,
    USER_DICT_PATH,
    IDF_PATH,
    STOP_WORD_PATH);

PHPX_FUNCTION(jieba_hello)
{
    vector<string> words;
    string s;
    s = args[0].toString();
    jieba.Cut(s, words, true);

    Array arr(retval);

	for (int i = 0; i < words.size(); ++i)
	{
	    arr.append(words[i]);
	}
}

PHPX_EXTENSION()
{
    Extension *extension = new Extension("jieba", "0.0.1");

    extension->onStart = [extension]() noexcept {
        extension->registerConstant("JIEBA_VERSION", 10001);
    };

    //extension->onShutdown = [extension]() noexcept {
    //};

    //extension->onBeforeRequest = [extension]() noexcept {
    //    cout << extension->name << "beforeRequest" << endl;
    //};

    //extension->onAfterRequest = [extension]() noexcept {
    //    cout << extension->name << "afterRequest" << endl;
    //};

    extension->info({"jieba support", "enabled"},
                    {
                        {"version", extension->version},
                        {"author", "limingxinleo <l@hyperf.io>"},
                        {"date", "2020-06-13"},
                    });
    extension->registerFunction(PHPX_FN(jieba_hello));

    return extension;
}
