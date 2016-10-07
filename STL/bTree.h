//////////////////////////////////////////////////
// FileName : btree.h
// Version : 0.10
// Author : wanbiao
// Data : 2016-10-07
//////////////////////////////////////////////////
//#define MAX_TREE_SIZE 100 	//二叉树的最大结点数 
#include <crtdbg.h>
template<typename T>
class BTNode
{
public:
	T data;
	BTNode<T> *parent;
	BTNode<T> *left;
	BTNode<T> *right;

	//初始化结点
	BTNode(T newData,
		BTNode<T>* newParent,
		BTNode<T>* newLeft,
		BTNode<T>* newRight):
		data(newData),parent(newParent),left(newLeft),right(newRight)
	{
	} 	
};

template<typename T>
class BTree
{
protected:
	BTNode<T>* m_pNodeRoot;

public:
	BTree(BTNode<T> *initroot = NULL);
	~BTree();
	void AssignTo(BTNode<T> *p);
	void Copy(BTree<T> *p);

private:
	BTNode<T>* Copy(BTNode<T> *p);
	void DestroyNode(BTNode<T> *p);

	//前序遍历
	void PreOrderTraverse(
		const BTNode<T> *p,
		void (*visit)(const T &data)
		)const;
	//中序遍历
	void InOrderTraverse(
		const BTNode<T> *p,
		void (*visit)(const T &data)
		)const;
	//后序遍历
	void PostOrderTraverse(
		const BTNode<T> *p,
		void (*visit)(const T &data)
		)const;

	void GetNodesCount(const BTNode<T> *p,unsigned int* unCount) const;
	
	void GetLeafCount(const BTNode<T> *p,unsigned int* unCount) const;
public:
	T& GetNodeData(BTNode<T> *p);
	T GetNodeData(const BTNode<T> *p) const;
	void SetNodeData(BTNode<T> *p,const T &data);
	BTNode<T>*& GetRoot();
	BTNode<T>* GetRoot();
	BTNode<T>*&    GetParent(BTNode<T> *p);
    BTNode<T>*     GetParent(const BTNode<T> *p) const;
    BTNode<T>*&    GetLeftChild(BTNode<T> *p);
    BTNode<T>*     GetLeftChild(const BTNode<T> *p) const;
    BTNode<T>*&    GetRightChild(BTNode<T> *p);
    BTNode<T>*     GetRightChild(const BTNode<T> *p) const;
    BTNode<T>*&    GetLeftSibling(BTNode<T> *p);	//左兄弟结点
    BTNode<T>*     GetLeftSiblig(const BTNode<T> *p) const;
    BTNode<T>*&    GetRightSibling(BTNode<T> *p);	//右兄弟结点
    BTNode<T>*     GetRightSibling(const BTNode<T> *p) const;

public:
	int             IsEmpty() const;
    void            Destroy();
    void            PreOrderTraverse(void (*Visit)(const T &data)) const;
    void            InOrderTraverse(void (*Visit)(const T &data)) const;
    void            PostOrderTraverse(void (*Visit)(const T &data)) const;
    unsigned int    GetNodesCount() const; // Get how many nodes
    unsigned int    GetLeafCount() const;
    unsigned int    GetDepth() const;
    unsigned int    GetDepth(const BTNode<T> *p) const;    
};
template<typename T>
inline BTree<T>::BTree(BTNode<T> *initroot) 
: m_pNodeRoot(initroot)
{

}

template<typename T>
inline BTree<T>::~BTree()
{
	Destroy();
}

template<typename T>
inline void BTree<T>::AssignTo(BTNode<T> *p)
{
	m_pNodeRoot = p;
}

template<typename T>
inline void BTree<T>::Copy(BTree<T> &p)
{
	if(NULL != p.m_pNodeRoot){
		m_pNodeRoot = Copy(p.m_pNodeRoot);
	}
	else{
		m_pNodeRoot = NULL;
	}
}

template<typename T>
inline BTNode<T>* BTree<T>::Copy(BTNode<T> *p)
{
	if(p){
		BTNode<T> *pNewNode = new BTNode<T>;
		if(NULL == pNewNode){
			return NULL;
		}

		pNewNode->data = p->data;
		pNewNode->parent = p->parent;
		pNewNode->left = Copy(p->left);
		pNewNode->right = Copy(p->right);

		return pNewNode;
	}
	else{
		return NULL;	
	}
}

template<typename T>
BTNode<T>*& BTree<T>::GetLeftChild(BTNode<T> *p)
{
	return *(&(p->left));
}

template<typename T>
inline BTNode<T>* BTree<T>::GetLeftChild(const BTNode<T> *p) const
{
	return p->left;
}

template<typename T>
inline BTNode<T>*& BTree<T>::GetRightChild(BTNode<T> *p)
{
	return *(&(p->right));
}

template<typename T>
inline BTNode<T>* BTree<T>::GetRightChild(const BTNode<T> *p) const
{
	return p->right;
}

//左兄弟结点
template<typename T>
inline BTNode<T>*& BTree<T>::GetLeftSibling(BTNode<T> *p)
{
	if(p->parent){
		return *(&(p->parent->left));
	}
	else{
		return p->parent; //return NULL;
	}
}

template<typename T>
inline BTNode<T>* BTree<T>::GetLeftSiblig(const BTNode<T> *p) const
{
	if(p->parent){
		return p->parent->left;
	}
	else{
		return p->left;
	}
}

//右兄弟结点
template<typename T>
inline BTNode<T>*& BTree<T>::GetRightSibling(BTNode<T> *p)
{
	if(p->parent){
		return *(&(p->parent->right));
	}
	else{
		return p->parent; //return NULL;
	}
}

template<typename T>
inline BTNode<T>* BTree<T>::GetRightSibling(const BTNode<T> *p) const
{
	if(p->parent){
		return p->parent->right;
	}
	else{
		return p->right;
	}
}

template<typename T>
inline BTNode<T>*& BTree<T>::GetParent(BTNode<T> *p)
{
	return *(&(p->parent));
}

template<typename T>
inline BTNode<T>* BTree<T>::GetParent(const BTNode<T> *p) const
{
	return p->parent;
}

template<typename T>
inline T& BTree<T>::GetNodeData(BTNode<T> *p)
{
	return p->data;
}

template<typename T>
inline T BTree<T>::GetNodeData(const BTNode<T> *p) const
{
	return p->data;
}

template<typename T>
void BTree<T>::SetNodeData(BTNode<T> *p,const T &data)
{
	p->data = data;
}

template<typename T>
inline int BTree<T>::IsEmpty() const
{
	return NULL == m_pNodeRoot;
}

template<typename T>
inline BTNode<T>*& BTree<T>::GetRoot()
{
	return *(&(m_pNodeRoot));
}

template<typename T>
inline BTNode<T>* BTree<T>::GetRoot()
{
	return m_pNodeRoot;
}



template<typename T>
inline void BTree<T>::DestroyNode(BTNode<T> *p)
{
	if(p){
		DestroyNode(p->left);
		DestroyNode(p->right);
		delete p;
	}
}

template<typename T>
inline void BTree<T>::Destroy()
{
	DestroyNode(m_pNodeRoot);
	m_pNodeRoot = NULL;
}

//前序遍历
template<typename T>
void BTree<T>::PreOrderTraverse(void (*Visit)(const T &data)) const
{
	PreOrderTraverse(m_pNodeRoot,visit);
}

template<typename T>
inline void BTree<T>::PreOrderTraverse(const BTNode<T> *p,
	void (*visit)(const T &data)) const
{
	if(p){
		visit(p->data);
		PreOrderTraverse(p->left,visit);
		PreOrderTraverse(p->right,visit);
	}
}

template<typename T>
inline void BTree<T>::InOrderTraverse(void (*Visit)(const T &data)) const
{
	InOrderTraverse(m_pNodeRoot);	
}

//中序遍历
template<typename T>
inline void BTree<T>::InOrderTraverse(const BTNode<T> *p,
	void (*visit)(const T &data)) const
{
	if(p){
		InOrderTraverse(p->left,visit);
		Visit(p->data);
		InOrderTraverse(p->right,visit);
	}
}

//后序遍历
template<typename T>
inline void BTree<T>::PostOrderTraverse(void (*Visit)(const T &data)) const
{
	PostOrderTraverse(m_pNodeRoot);
}

template<typename T>
inline void BTree<T>::PostOrderTraverse(const BTNode<T> *p,void (*visit)(const T &data)) const
{
	if(p){
		PostOrderTraverse(p->left,visit);
		PostOrderTraverse(p->right,visit);
		visit(p->data);
	}
}

template<typename T>
inline unsigned int BTree<T>::GetNodesCount() const
{
	unsigned int unCount;
	GetNodesCount(m_pNodeRoot,&unCount);
	return unCount;
}

template<typename T>
inline void BTree<T>::GetNodesCount(const BTNode<T> *p,
	unsigned int* unCount) const
{
	unsigned int unLeftCount;
	unsigned int unRightCount;

	if(NULL == p){
		*unCount = 0;
	}
	else if((NULL == p->left) && (NULL == p->right)){
		*unCount = 1;
	}
	else{
		GetNodesCount(p->left,&unLeftCount);
		GetNodesCount(p->right,&unRightCount);
		*unCount = 1 + unLeftCount + unRightCount;
	}
}

template<typename T>
inline unsigned int BTree<T>::GetLeafCount() const
{
	unsigned int unCount = 0;
	GetLeafCount(m_pNodeRoot,&unCount);
	return unCount;
}

template<typename T>
inline void BTree<T>::GetLeafCount(const BTNode<T> *p,
	unsigned int* unCount) const
{
	if(p){
		//节点的左右结点都为空，则它为叶子节点
		if((NULL == p->left) && (NULL == p->right)){
			++(*unCount);
		}

		GetLeafCount(p->left,unCount);
		GetLeafCount(p->right,unCount);
	}
}

template<typename T>
inline unsigned int BTree<T>::GetDepth() const
{
	//根节点深度为0
	return GetDepth(m_pNodeRoot) - 1;
}

template<typename T>
inline unsigned int BTree<T>::GetDepth(const BTNode<T> *p) const
{
	unsigned int unDepthLeft;
	unsigned int unDepthRight;

	if(p){
		unDepthLeft = GetDepth(p->left);
		unDepthRight = GetDepth(p->right);

		return 1 + (unDepthLeft > unDepthRight ? unDepthLeft : unDepthRight);		
	}
	else{
		return 0;
	}
}