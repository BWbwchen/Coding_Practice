Pair* unzip(List *lptr)
{
    Atom *h;
    Pair *p, *newp;
    List *l1, *l2;
    if (lptr==NULL) {
        newp = pair_list(NULL, NULL);
        return newp;
    }

    h = head(lptr); // // 取出 lptr 的開頭第一個 atom
    p = unzip(lptr->next); // 利用 unzip 對剩下的 lptr 遞迴繼續處理
    l1 = cons(h->pair->left, p->left->lst); // 兩個 lists 分別來自兩個 cons
    l2 = cons(h->pair->right, p->right->lst); // 一個 cons 組合左邊的 list 另一個組合右邊的 list
    newp = pair_list(l1, l2); // // 利用 pair_list 從兩個 lists 產生新的 pair
    free_list(l1);
    free_list(l2);
    free_pair(p);
    return newp;
}
