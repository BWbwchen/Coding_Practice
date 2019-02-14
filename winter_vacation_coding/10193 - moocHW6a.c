List* zip(List *lptr1, List *lptr2)
{
    Atom a;
    List *l1, *l2;

    if ( (lptr1&&lptr2) == 0 ) { // lptr1 或 lptr2 兩者有一個是 NULL
        return NULL;
    } else {
        a.pair = (Pair *)malloc (sizeof(Pair )); // malloc 取得一塊 Pair 空間
        a.pair->left = copy_atom(lptr1->data); // 利用  copy_atom  複製 lptr1 的開頭第一個 atom
        a.pair->right = copy_atom(lptr2->data); // 利用  copy_atom  複製 lptr2 的開頭第一個 atom
        a.dtype = 2;
        l1 = zip(lptr1->next, lptr2->next); // 利用 zip 處理剩下的 lists  (提示: 用遞迴)
        l2 = cons(&a, l1); // 利用 cons 造出新的 list
        free_pair(a.pair);
        free_list(l1);
        return l2;
    }
}
