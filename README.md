# BDJSONParser
The C++ Class BDJSONParser can parser a string that is a standard grammar's JSON char string.

This class purpose is parsering a json string without third part librarys or reduce other dependences in C++ development environment.

But the code does not have to undergo a rigorous testing!

The following is a test.

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
