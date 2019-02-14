List* take(int n, List *lptr)
{
    List *new = NULL;
    if(n) {
        new = cons(head(lptr), take(n-1, tail(lptr)));
    } 
    return new;

    /*
    判斷 n 的值決定是否繼續
    利用 cons 搭配 take 的遞迴呼叫  建構出回傳的 list
    */
}

List* drop(int n, List *lptr)
{
    List *new = lptr;
    if(n){
        new = drop(n-1, tail(lptr));
    }
    return new;
    /*
    判斷 n 的值決定是否繼續
    利用 cons 搭配 drop 的遞迴呼叫  建構出回傳的 list
    */

}
Pair* split_at(int n, List *lptr)
{
    Pair *p;
    Atom a;

    p = (Pair*)malloc(sizeof(Pair));
    a.dtype = 3;

    a.lst = take(n, lptr);
    p->left = copy_atom(&a);

    a.lst = drop(n, lptr);
    p->right = copy_atom(&a);
    /* 參考 pair_list 的寫法
    利用 take 和 drop 還有 copy_atom
    做出 split_at
    */


    return p;
}
