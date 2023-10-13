#pragma once
#include  <string>
#include <fstream>
#include <iostream>
using namespace std;
class Helper
{

public:
    Helper(){};
    static int char2Int(char c){return int(c) - 48;};
    static string formatHours(int value, string suffixe);
    static string formatDate(double s);
    static void waitForUserInput(){getchar();}
};

