#include "phpx.h"
#include "cppjieba/Jieba.hpp"
#include <iostream>

using namespace php;
using namespace std;

struct PHPJiebaObject
{
    cppjieba::Jieba* jieba;
};

#define RESOURCE_NAME  "PHPJieba"
#define PROPERTY_NAME  "ptr"

static void PHPJiebaObjectResDtor(zend_resource *res)
{
    PHPJiebaObject *jb = static_cast<PHPJiebaObject *>(res->ptr);
//    efree(jb->jieba);
    efree(jb);
}

PHPX_METHOD(PHPJieba, __construct)
{
    string dict = args[0].toString();
    string hmm = args[1].toString();
    string user_dict = args[2].toString();
    string idf = args[3].toString();
    string stop_word = args[4].toString();

    PHPJiebaObject *object = (PHPJiebaObject *)emalloc(sizeof(PHPJiebaObject));
    cppjieba::Jieba jieba(dict, hmm, user_dict, idf, stop_word);
    object->jieba = &jieba;

    vector<string> words;
    object->jieba->Cut("上海公园吃炸鸡", words, true);
    for (int i = 0; i < words.size(); ++i)
    {
        cout << words[i] << endl;
    }

    _this.oSet(PROPERTY_NAME, RESOURCE_NAME, object);
    // _this.store(object);
}

PHPX_METHOD(PHPJieba, cut)
{
    vector<string> words;
    string s;
    bool hmm = true;

    s = args[0].toString();
    if(args.count() > 1){
        hmm = args[1].toBool();
    }

    PHPJiebaObject *object = _this.oGet<PHPJiebaObject>(PROPERTY_NAME, RESOURCE_NAME);
    // PHPJiebaObject *object = _this.fetch<PHPJiebaObject>();

    object->jieba->Cut(s, words, hmm);
//    for (int i = 0; i < words.size(); ++i)
//    {
//        cout << words[i] << endl;
//    }
//    jieba->Cut(s, words, hmm);
//    object->jieba->Cut(s, words, hmm);
//
//    Array arr(retval);
//
//    for (int i = 0; i < words.size(); ++i)
//    {
//        arr.append(words[i]);
//    }
}

PHPX_FUNCTION(jieba_hello)
{
    retval = "Hello World";
//    vector<string> words;
//    string s;
//    s = args[0].toString();
//    jieba.Cut(s, words, true);
//
//    Array arr(retval);
//
//	for (int i = 0; i < words.size(); ++i)
//	{
//	    arr.append(words[i]);
//	}
}

PHPX_EXTENSION()
{
    Extension *extension = new Extension("jieba", "0.0.1");

    extension->onStart = [extension]() noexcept {
        extension->registerConstant("JIEBA_VERSION", 10001);

        Class *c = new Class("PHPJieba");
        c->addMethod(PHPX_ME(PHPJieba, __construct), CONSTRUCT);
        c->addMethod(PHPX_ME(PHPJieba, cut), PUBLIC);
        extension->registerClass(c);
        extension->registerResource(RESOURCE_NAME, PHPJiebaObjectResDtor);
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
