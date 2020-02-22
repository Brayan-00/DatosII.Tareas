//
// Created by brayanrv on 21/2/20.
//

#include "Json.h"
#include <iostream>
#include "../../Library/rapidjson/document.h"
#include "../../Library/rapidjson/writer.h"
#include "../../Library/rapidjson/stringbuffer.h"

using namespace rapidjson;

int main() {
    // 1. Parse a JSON string into DOM.
    const char *json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d;
    d.Parse(json);

    // 2. Modify it by DOM.
    Value &s = d["stars"];
    s.SetInt(s.GetInt() + 1);

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    std::cout << buffer.GetString() << std::endl;
    return 0;

}

/*
public int createJson(){
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d;
    d.Parse(json);

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    std::cout << buffer.GetString() << std::endl;
    return 0;
}
 */