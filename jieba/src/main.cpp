#include "phpx.h"
#include "cppjieba/Jieba.hpp"
#include <iostream>

using namespace php;
using namespace std;

//string dict = "/Users/limx/Applications/GitHub/limingxinleo/phpx-jieba-ext/dict";
string dict = "/dict";
cppjieba::Jieba jieba(
    dict + "/jieba.dict.utf8",
    dict + "/hmm_model.utf8",
    dict + "/user.dict.utf8",
    dict + "/idf.utf8",
    dict + "/stop_words.utf8"
);

PHPX_METHOD(PHPJieba, cut)
{
    vector<string> words;
    string s;
    bool hmm = true;

    s = args[0].toString();
    if(args.count() > 1){
        hmm = args[1].toBool();
    }

    jieba.Cut(s, words, hmm);

    Array arr(retval);

    for (int i = 0; i < words.size(); ++i)
    {
        arr.append(words[i]);
    }
}

PHPX_METHOD(PHPJieba, cutAll)
{
    vector<string> words;
    string s;

    s = args[0].toString();

    jieba.CutAll(s, words);

    Array arr(retval);

    for (int i = 0; i < words.size(); ++i)
    {
        arr.append(words[i]);
    }
}

PHPX_METHOD(PHPJieba, cutForSearch)
{
    vector<string> words;
    string s;

    s = args[0].toString();

    jieba.CutAll(s, words);

    Array arr(retval);

    for (int i = 0; i < words.size(); ++i)
    {
        arr.append(words[i]);
    }
}

PHPX_METHOD(PHPJieba, insertUserWord)
{
    vector<string> words;
    string s;

    s = args[0].toString();

    jieba.InsertUserWord(s);
}

PHPX_EXTENSION()
{
    Extension *extension = new Extension("jieba", "0.0.3");

    extension->onStart = [extension]() {
        extension->registerConstant("JIEBA_VERSION", 10001);

        Class *c = new Class("PHPJieba");
        c->addMethod(PHPX_ME(PHPJieba, cut), STATIC);
        c->addMethod(PHPX_ME(PHPJieba, cutAll), STATIC);
        c->addMethod(PHPX_ME(PHPJieba, cutForSearch), STATIC);
        c->addMethod(PHPX_ME(PHPJieba, insertUserWord), STATIC);
        extension->registerClass(c);
    };

    extension->info({"jieba support", "enabled"},
                    {
                        {"version", extension->version},
                        {"author", "limingxinleo <l@hyperf.io>"},
                        {"date", "2020-06-13"},
                    });

    return extension;
}
