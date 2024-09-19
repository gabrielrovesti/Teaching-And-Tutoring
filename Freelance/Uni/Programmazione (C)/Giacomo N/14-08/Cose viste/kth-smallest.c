int kth-smallest(BST, k){
    if(BST == null) return NULL;
    
    int left = kth-smallest(BST->leftPtr, k);
    int right = kth-smallest(BST->rightPtr, k);
    if(left <= k){
        return kth-smallest(BST->leftPtr, k) + 1;
    }
    if(left == k || right == k)
        return BST->info

}