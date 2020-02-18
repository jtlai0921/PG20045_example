//-----------------------------------------------------------------------//
//    ���`���X�g�E�m�[�h�N���X�i�������j                      "list.c"   //
//-----------------------------------------------------------------------//

#include    <string.h>

#include    "list.h"

//--- �R���X�g���N�^ ---//
List::List(void)
{
    top = bottom = new Node;
}

//--- �f�X�g���N�^ ---//
List::~List(void)
{
    Clear();    
    delete top;
}

//--- ���X�g�̖����v�f�ւ̃|�C���^ ---//
Node* List::Bottom(void) const
{
    if (top == bottom)
        return (NULL);
    else {
        Node*  ptr = top;
        while (ptr->next != bottom)
            ptr = ptr->next;
        return (ptr);
    }
}

//--- ���X�g�̐擪�ɗv�f��ǉ� ---//
List& List::Insert(Node* x)
{
    Node*  ptr = top;
    top = x;
    top->next = ptr;
    return (*this);
}

//--- ���X�g�����̗v�f���폜 ---//
List& List::Remove(void)
{
    if (top == bottom)
        ;
    else if (top->next == bottom)
        Delete();
    else {
        Node*  now = top;
        Node*  pre;
        while (now->next != bottom) {
            pre = now;
            now = now->next;
        }
        pre->next = bottom;
        delete now;
    }
    return (*this);
}

//--- ���X�g���̑S�v�f���폜 ---//
List& List::Clear(void)
{
    Node*  ptr = top;
    while (ptr != bottom) {
        Node*  next = ptr->next;
        delete ptr;
        ptr = next;
    }
    top = bottom;
    return (*this);
}
