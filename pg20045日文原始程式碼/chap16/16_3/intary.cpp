//----------------------------------------------------------------------------// 
//  �����z��N���X IntAry ��S�Łi�������j                  "intary.c"        // 
//----------------------------------------------------------------------------// 
                                                                                 
#include    "intary.h"                                                           
                                                                                 
int IntAry::counter = 0;                                                         
                                                                                 
//--- �R�s�[�R���X�g���N�^ ---//                                                 
IntAry::IntAry(const IntAry& x)                                                  
{                                                                                
    ptr = new int[x.size];                                                       
    size = x.size;                                                               
    for (int i = 0; i < size; i++)                                               
        ptr[i] = x.ptr[i];                                                       
    CntUp();                                                                     
}                                                                                
                                                                                 
//--- ������Z�q ---//                                                           
IntAry& IntAry::operator=(const IntAry& x)                                       
{                                                                               if (&x != this) {               // �������g�ւ͑�����Ȃ�                    
        delete[] ptr;                                                            
        ptr = new int[x.size];                                                   
        size = x.size;                                                           
        for (int i = 0; i < size; i++)                                           
            ptr[i] = x.ptr[i];                                                   
    }                                                                            
    return (*this);                                                              
}                                                                                
