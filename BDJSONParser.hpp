//
//  BDJSONParser.hpp
//
//  Created by juzhong on 16/2/19.
//  Copyright © 2016年 HUANG BINGDONG. All rights reserved.
//

#ifndef BDJSONParser_hpp
#define BDJSONParser_hpp

#include <stdio.h>
#include <string>
#include <map>

#define CASE_NUM(x)             case (x):\
                                {\
                                    return _jsonString.substr(startPos,case_number(startPos)-startPos);\
                                }\
                                break;

class BDJSONParser
{
private:
    const std::string _jsonString;
    size_t _len;
    std::map<std::string,std::string> keyValues;
public:
    BDJSONParser(const std::string jsonString):_jsonString(jsonString){_len = _jsonString.length();};
    
    std::string operator [] (const std::string key)
    {
        std::string searchStr("\"");
        searchStr+=key;
        searchStr+="\":";
        size_t start = _jsonString.find(searchStr);
        return start==std::string::npos ? std::string():parserValue(start+3+key.length());
    }

    std::string parserValue(size_t startPos)//startPos为冒号后的第一个位置
    {
        using namespace std;
         char c = _jsonString.c_str()[startPos];
        switch (c) {
            case '"':
            {
                return _jsonString.substr(startPos+1,case_string(startPos)-startPos-1);
            }
                break;
                CASE_NUM('1')
                CASE_NUM('2')
                CASE_NUM('3')
                CASE_NUM('4')
                CASE_NUM('5')
                CASE_NUM('6')
                CASE_NUM('7')
                CASE_NUM('8')
                CASE_NUM('9')
                CASE_NUM('0')

            case 't':
            {
                return "true";
            }
                break;
            case 'f':
            {
                return "false";
            }
                break;
            case 'n':
            {
                return "null";
            }
                break;
            case ' ':
            {
                return parserValue(case_blank(startPos));
            }
                break;
            case '{':
            {
                return case_leftBrackets(startPos);
            }
                break;
            case '[':
            {
                return case_arraySign(startPos);
            }
                break;

                
            default:
                break;
        }
        
        return std::string();
        
    }
    size_t case_string(size_t pos)
    {
        return _jsonString.find('"', pos+1);
    }
    size_t case_number(size_t pos)
    {
        size_t t = _jsonString.find(',', pos+1);
        if (t == std::string::npos) {
            t = _jsonString.find('}', pos+1);
        }
        
        return t;
    }
    
    size_t case_blank(size_t pos)
    {
        size_t npos = pos;
        while (_jsonString[++npos]==' ');
        return npos;
    }
    
    std::string case_leftBrackets(size_t pos)
    {
        size_t npos = pos;
        size_t rightBracketCount= 0;
        size_t leftBracketCount = 1;
        bool stop=true;
        while (stop)
        {
            npos++;
            if (_jsonString[npos]=='{') {leftBracketCount++;}
            else if (_jsonString[npos]=='}') {
                rightBracketCount++;
                if (rightBracketCount == leftBracketCount) stop = false;
            }
        }
        return _jsonString.substr(pos,npos-pos+1);
    }
    
    std::string case_arraySign(size_t pos)
    {
        size_t npos = pos;
        size_t rightBracketCount= 0;
        size_t leftBracketCount = 1;
        bool stop=true;
        while (stop)
        {
            npos++;
            if (_jsonString[npos]=='[') {leftBracketCount++;}
            else if (_jsonString[npos]==']') {
                rightBracketCount++;
                if (rightBracketCount == leftBracketCount) stop = false;
            }
        }
        return _jsonString.substr(pos,npos-pos+1);
    }
 };

#endif /* BDJSONParser_hpp */
