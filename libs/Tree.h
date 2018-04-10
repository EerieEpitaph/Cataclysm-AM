#ifndef TREE_H
#define TREE_H

#include "../ExtraExceptions/ExtraExceptions.h"
#include "../LinkedList/LinkedList.h"
#include <memory>

///MEMO: 10 GENNAIO SECONDO ESONERO
template<class T>
class BinaryTree
{
    private:
        BinaryTree<T>* parent;
        std::unique_ptr<T> value;
        std::unique_ptr<BinaryTree<T>> sxChild;
        std::unique_ptr<BinaryTree<T>> dxChild;

    public:
        BinaryTree();
        BinaryTree(T newData);
        BinaryTree(const BinaryTree<T>& origin);
        bool operator==(const BinaryTree<T>& origin);
        BinaryTree<T>& operator=(const BinaryTree<T>& origin);
        BinaryTree<T>& operatorEqual(const BinaryTree<T>& origin); //SUPPORTO PER OPERATOR=

        BinaryTree<T>* getParent() const;
        T getValue() const;
        BinaryTree<T>* getSx() const;
        BinaryTree<T>* getDx() const;
        BinaryTree<T>* getSibling() const;
        int getHeight();
        int getHeight(int& currHeight, int&maxHeight);
        int getWidth();
        void getWidth(int* levels, int& level);

        bool isNull() const;
        bool isLeaf() const;
        bool isSx() const;
        bool isDx() const;
        bool hasParent() const;
        bool hasSx() const;
        bool hasDx() const;

        void setParent(BinaryTree<T>* newParent);
        void setValue(T newData);
        void setSx(BinaryTree<T>* newSx);
        void setDx(BinaryTree<T>* newDx);
        void setSx(T newSx);
        void setDx(T newDx);

        void remove(BinaryTree<T>* toRemove);
        void fullPrint() const;
        void print() const;
};
template<class T>
std::ostream& operator<<(std::ostream& os, const BinaryTree<T>& origin);

template<class T>
class Tree
{
    private:
        Tree<T>* parent;
        Node<std::shared_ptr<Tree<T>>>* holdingNode;
        std::unique_ptr<T> value;
        mutable List<std::shared_ptr<Tree<T>>> children;

    public:
        Tree();
        Tree(T newData);
        Tree(const Tree<T>& origin);
        bool operator==(const Tree<T>& origin);
        bool operatorEqualEqual(bool& verdict, const Tree<T>& origin);
        Tree<T>& operator=(const Tree<T>& origin);
        Tree<T>& operatorEqual(const Tree<T>& origin);

        Tree<T>* getParent() const;
        Node<std::shared_ptr<Tree<T>>>* getHoldingNode() const;
        T getValue() const;
        List<std::shared_ptr<Tree<T>>>& getChildren() const;
        Tree<T>* getProxSib() const;
        Tree<T>* getPrexSib() const;
        Tree<T>* getFirstSon() const;
        Tree<T>* getLastSon() const;

        bool isNull() const;
        bool hasParent() const;
        bool hasChildren() const;
        bool hasPrexSib() const;
        bool hasProxSib() const;

        void setParent(Tree<T>* newParent);
        void setHoldingNode(Node<std::shared_ptr<Tree<T>>>* newHoldingNode);
        void setValue(T newValue);
        void setChildren(List<std::shared_ptr<Tree<T>>> newChildren);

        void appendChild(T newData);
        void pushChild(T newData);
        void remove(Tree<T>* toRemove);
        void print() const;
};
template<class T>
std::ostream& operator<<(std::ostream& os, const Tree<T>& origin);

template<class R, class T>
class BinSrcTree
{
    private:
        BinSrcTree<R,T>* parent;
        std::unique_ptr<R> key;
        std::unique_ptr<T> value;
        std::unique_ptr<BinSrcTree<R,T>> sxChild;
        std::unique_ptr<BinSrcTree<R,T>> dxChild;

    public:
        BinSrcTree();
        BinSrcTree(R key, T newData);
        BinSrcTree(const BinSrcTree<R,T>& origin);
        bool operator==(const BinSrcTree<R,T>& origin);
        BinSrcTree<R,T>& operator=(const BinSrcTree<R,T>& origin);
        BinSrcTree<R,T>& operatorEqual(const BinSrcTree<R,T>& origin); //SUPPORTO PER OPERATOR=

        BinSrcTree<R,T>* getParent() const;
        R getKey() const;
        T getValue() const;
        BinSrcTree<R,T>* getSx() const;
        BinSrcTree<R,T>* getDx() const;
        BinSrcTree<R,T>* getSibling() const;

        BinSrcTree<R,T>* getMin();
        BinSrcTree<R,T>* getMax();
        BinSrcTree<R,T>* getSuccessor();
        BinSrcTree<R,T>* getPredecessor();
        int getHeight();
        int getHeight(int& currHeight, int&maxHeight);
        int getWidth();
        void getWidth(int* levels, int& level);

        bool isNull() const;
        bool isLeaf() const;
        bool isSx() const;
        bool isDx() const;
        bool hasParent() const;
        bool hasSx() const;
        bool hasDx() const;

        void setParent(BinSrcTree<R,T>* newParent);
        void setKey(R newKey);
        void setValue(T newData);
        void setSx(BinSrcTree<R,T>* newSx);
        void setDx(BinSrcTree<R,T>* newDx);
        void setSx(R key, T newSx);
        void setDx(R key, T newDx);

        void insert(R key, T value);
        void insert(BinSrcTree<R,T> toInsert);
        BinSrcTree<R,T>* findByKey(R key);
        void remove();
        void fullPrint() const;
        void print() const;
};
template<class R, class T>
std::ostream& operator<<(std::ostream& os, const BinSrcTree<R,T>& origin);

#include "Tree().h"
#endif // TREE_H
