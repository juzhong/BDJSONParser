//
//  BDJSONParser.cpp
//  MyFuctionTest
//
//  Created by juzhong on 16/2/19.
//  Copyright © 2016年 HUANG BINGDONG. All rights reserved.
//

#include "BDJSONParser.hpp"
#include <iostream>


void BDJSONParserTest()
{
    std::string jsonString ="{\"1\":\"1TB:,VCX90\",\"2\":\"78hjk====--:-,90\",\"3\":\"L1234890\",\"4\":\"GBFD\",\"5\":{\"6\":\"dfop90\",\"7\":[{\"8\":\"klll90\"},{\"9\":\"ghhj290\"}]}}";
    BDJSONParser P(jsonString);
    std::cout<<P["1"]<<std::endl;
    std::cout<<P["2"]<<std::endl;
    std::cout<<P["3"]<<std::endl;
    std::cout<<P["4"]<<std::endl;
    std::cout<<P["5"]<<std::endl;
    std::cout<<P["6"]<<std::endl;
    std::cout<<P["7"]<<std::endl;
    std::cout<<P["8"]<<std::endl;
    std::cout<<P["9"]<<std::endl;
}

void BDJSONParserTest2()
{
    std::string jsonString ="{\"name\": \"中国\",\"province\": [{\"name\": \"黑龙江\",\"cities\": {\"city\": [\"哈尔滨\", \"大庆\"]}}, {\"name\": \"广东\",\"cities\": {\"city\": [\"广州\", \"深圳\", \"珠海\"]}}, {\"name\": \"台湾\",\"cities\": {\"city\": [\"台北\", \"高雄\"]}}, {\"name\": \"新疆\",\"cities\": {\"city\": [\"乌鲁木齐\"]}}]}";
    BDJSONParser P(jsonString);
    std::cout<<P["name"]<<std::endl;
    std::cout<<P["province"]<<std::endl;
    std::cout<<P["cities"]<<std::endl;
    std::cout<<P["city"]<<std::endl;
}


