//   Crayondeng 
//   CSDN 
//   https://blog csdn net/crayondeng/article/details/24853471 
#include <iostream>
#include "03_singleton.h"

using namespace std;

BSingleton BSingleton::m_data;

BSingleton::BSingleton()
{
    str = new string("hello world");
    cout<<"BSingleton constructor!"<<endl;
}
