//   Crayondeng 
//   CSDN 
//   https://blog csdn net/crayondeng/article/details/24853471 
#include <iostream>
#include "04_singleton.h"

using namespace std;

BSingleton* BSingleton::m_data = nullptr;
int BSingleton::flag = 1;

BSingleton::BSingleton()
{
    cout << "BSingleton constructor!" << endl;
}
