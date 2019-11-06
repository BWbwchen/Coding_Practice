Atom* atom_toupper(Atom *a)
{
    Atom *b;
    b = copy_atom(a);
    int i;
    for(i = 0; b->str[i] != '\0'; ++i) b->str[i] = toupper(b->str[i]);
    return b;
}
Atom* atom_square(Atom *a)
{
    Atom *b;
    b = copy_atom(a);
    b->val = b->val * b->val;
    return b;
}
List* map(List *lptr, Atom* (*f)(Atom *))
{
    Atom *a;
    List *l1, *l2;
    if (lptr==NULL) return NULL;
    else {
        l1 = map(tail(lptr), f); /* 用遞迴的方式 利用 map 處理 list 剩下的部分   並且用 l1 指標  記住結果 */
        a = (*f)(head(lptr)); /* 把 lptr 開頭的 atom 代入 f  得到新的 atom */
        l2 = cons(a, l1); /* 接著再利用 cons 組合 處理過的頭跟尾 */
        free_atom(a);
        free_list(l1);
        return l2;
    }
}
