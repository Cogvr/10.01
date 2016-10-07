//////////////////////////////////////////////////
// FileName : btree.h
// Version : 0.10
// Author : wanbiao
// Data : 2016-10-07
//////////////////////////////////////////////////
#include<iostream>
#include<bTree.h>

using namespace std;

//结点的数据类型
typedef char ElementType;

//回调函数：Visit() = PrintElement()
static void PrintElement(const ElementType& data)
{
	cout << data;
}

int main()
{
	BTNode<ElementType> *pRoot;
    BTNode<ElementType> *pLeftChild;
    BTNode<ElementType> *pRightChild;
    BTree<ElementType> btree;

    pRoot = new BTNode<ElementType>;
    if (NULL == pRoot)
        return EXIT_FAILURE;

    pLeftChild = new BTNode<ElementType>;
    if (NULL == pLeftChild)
        return EXIT_FAILURE;

    pRightChild = new BTNode<ElementType>;
    if (NULL == pRightChild)
        return EXIT_FAILURE;

    // 创建父亲结点
    pRoot->data = '+';
    pRoot->parent = NULL;
    pRoot->left = pLeftChild;
    pRoot->right = pRightChild;

    // 创建左儿子结点
    pLeftChild->data = 'a';
    pLeftChild->parent = pRoot;
    pLeftChild->left = NULL;
    pLeftChild->right = NULL;

    // 创建右儿子结点
    pRightChild->data = 'b';
    pRightChild->parent = pRoot;
    pRightChild->left = NULL;
    pRightChild->right = NULL;

    // 创建二叉树
    btree.AssignTo(pRoot);

    // 输出这棵二叉树
    cout << "   (" << btree.GetNodeData(btree.GetRoot()) << ")  " << endl;
    cout << "  /   \\ " << endl;
    cout << "(" << btree.GetNodeData(btree.GetLeftChild(btree.GetRoot()))
         << ")    (" << btree.GetNodeData(btree.GetRightChild(btree.GetRoot()))
         << ")" << endl << endl;

    cout << "这棵树的叶子数：" << btree.GetLeafCount() << endl;

    cout << "这棵树的深度是：" << btree.GetDepth() << endl;

    cout << "先序遍历：";
    btree.PreOrderTraverse(PrintElement);

    cout << endl << "中序遍历：";
    btree.InOrderTraverse(PrintElement);

    cout << endl << "后序遍历：";
    btree.PostOrderTraverse(PrintElement);

    cout << endl;

    return EXIT_SUCCESS;
}
