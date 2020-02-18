//-----------------------------------------------------------------------//
//    線形リスト・ノードクラス（実現部）                      "list.c"   //
//-----------------------------------------------------------------------//

#include    <string.h>

#include    "list.h"

//--- コンストラクタ ---//
List::List(void)
{
    top = bottom = new Node;
}

//--- デストラクタ ---//
List::~List(void)
{
    Clear();    
    delete top;
}

//--- リストの末尾要素へのポインタ ---//
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

//--- リストの先頭に要素を追加 ---//
List& List::Insert(Node* x)
{
    Node*  ptr = top;
    top = x;
    top->next = ptr;
    return (*this);
}

//--- リスト末尾の要素を削除 ---//
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

//--- リスト中の全要素を削除 ---//
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
