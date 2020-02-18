//----------------------------------------------------------------------------// 
//  整数配列クラス IntAry 第４版（実現部）                  "intary.c"        // 
//----------------------------------------------------------------------------// 
                                                                                 
#include    "intary.h"                                                           
                                                                                 
int IntAry::counter = 0;                                                         
                                                                                 
//--- コピーコンストラクタ ---//                                                 
IntAry::IntAry(const IntAry& x)                                                  
{                                                                                
    ptr = new int[x.size];                                                       
    size = x.size;                                                               
    for (int i = 0; i < size; i++)                                               
        ptr[i] = x.ptr[i];                                                       
    CntUp();                                                                     
}                                                                                
                                                                                 
//--- 代入演算子 ---//                                                           
IntAry& IntAry::operator=(const IntAry& x)                                       
{                                                                               if (&x != this) {               // 自分自身へは代入しない                    
        delete[] ptr;                                                            
        ptr = new int[x.size];                                                   
        size = x.size;                                                           
        for (int i = 0; i < size; i++)                                           
            ptr[i] = x.ptr[i];                                                   
    }                                                                            
    return (*this);                                                              
}                                                                                
