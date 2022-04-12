/**
 * Implementasi Binary Search Tree (ADT: BST)
 * yakni BST yang tidak menyimpan key duplikat (unique key)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 29 Februrari 2019
 * Struktur Data 2020
 * 
 * Implementasi untuk Bahasa C
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    long key;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */

BSTNode* __bst__createNode(long value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value, int* levelPtr) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key){
        *levelPtr = *levelPtr + 1;
        root->left = __bst__insert(root->left, value, levelPtr);
    }
    else if (value > root->key){
        *levelPtr = *levelPtr + 1;
        root->right = __bst__insert(root->right, value, levelPtr);
    }
    return root;
}

BSTNode* __bst__search(BSTNode *root, long value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

BSTNode* __bst__remove(BSTNode *root, long value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = __bst__remove(root->right, value);
    else if (value < root->key) 
        root->left = __bst__remove(root->left, value);
    else {
        
        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%ld ", root->key);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%ld ", root->key);
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%ld ", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, long value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

int bst_insert(BST *bst, int value) {
    int level = 0;
    int* levelPtr = &level;
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value, levelPtr);
        bst->_size++;
    }

    return level;
}

void bst_remove(BST *bst, long value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}

long getLevelUtil(BSTNode *node,
                 long data, long level)
{
    if (node == NULL)
        return 0;
 
    if (node->key == data)
        return level;
 
    long downlevel = getLevelUtil(node->left,
                                 data, level+1);
    if (downlevel != 0)
        return downlevel;
 
    downlevel = getLevelUtil(node->right,
                             data, level+1);
    return downlevel;
}
 
/* Returns level of given data value */
long getLevel(BSTNode *node, long data)
{
    return getLevelUtil(node,data,1);
}
 
int main()
{
    BST set;
    bst_init(&set);

    long Q;
    scanf("%ld", &Q);

    long A[Q];
    long ram[Q];
    int index;
    for(index=0;index<Q;index++){
        ram[index] = 0;
    }

    long i, x, y, j = 0, level;
    long maxlevel = 0;
    for(i=0;i<Q;i++){
        scanf("%ld%ld", &x, &y);
        if(x == 1){
            level = bst_insert(&set, y);
            
            ram[level] += y;
            if(level>maxlevel) maxlevel = level;
        } else {
            A[j] = y;
            if(y <= maxlevel){
            printf("Level %ld: %ld\n", A[j], ram[A[j]]);
            } else {
                printf("GG EZ\n");
            }
            
            j++;
        }

    }
    
    
    //for(i=0;i<j;i++){
    //    printf("%d", ram[A[i]+1]);
    //}
    
     //printf("%d", ram[A[2]]);

    

    
    
    return 0;
}