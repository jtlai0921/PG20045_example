//-------------------------------------------------------------------------//
//    線形リスト・ノードクラス（インタフェース部 ）            "list.h"    //
//------------------------------------------------------------------------//

//----- ノードクラス ---//
class Node {

    friend class List;

protected:
    Node*  next;                    // 後続ノードへのポインタ

public:
    Node(void) { next = NULL;}        // コンストラクタ
    Node* Next(void) const  { return (next); }    // 後続ノード
};

//--- 線形リストクラス ---//
class List {
private:
    Node*  top;                // 先頭ノードへのポインタ
    Node*  bottom;            // 末尾ダミーノードへのポインタ

public:
    List(void);              // コンストラクタ
    ~List(void);            // デストラクタ

    Node* Top(void) const { return ((top == bottom) ? NULL : top); }
    Node* Bottom(void) const;

    List& Insert(Node*);        // 先頭へのノード挿入
    List& Append(Node*);        // 末尾へのノード追加
    List& Delete(void);        // 先頭ノードの削除
    List& Remove(void);        // 末尾ノードの削除
    List& Clear(void);        // 全ノードの削除
};

//--- Typeのノード ---//
template <class Type>
class TypeNode : public Node {

    friend int kill(List& list, Type n)
    {
        if (list.Top() == NULL)
            return (0);                            // 空だと0を返却
        TypeNode<Type>* front = NULL;
        TypeNode<Type>* temp = (TypeNode<Type>*)list.Top();
        TypeNode<Type>* bottom = (TypeNode<Type>*)list.Bottom()->Next();
        while (temp != bottom) {
            if (*temp == n) {
                if (front == NULL)
                    list.Delete();
                else {
                    front->next = temp->next;
                    delete temp;
                }
                return (1);
            }
            front = temp;
            temp = (TypeNode<Type>*)temp->next;
        }
        return (0);                                // 無かったら0を返却
    }

private:
    Type    num;

public:
    TypeNode<Type>(Type n = 0) : num(n) { }            // コンストラクタ
    operator Type(void) const { return (num); }        // 変換
};
