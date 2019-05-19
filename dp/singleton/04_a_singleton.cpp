//   Crayondeng 
//   CSDN 
//   https://blog csdn net/crayondeng/article/details/24853471 
#include <iostream>
#include "04_singleton.h"

using namespace std;

ASingleton ASingleton::m_data;

ASingleton::ASingleton()
{
    cout << "ASingleton constructor!" << endl;
    BSingleton::getInstance()->do_something();
}
