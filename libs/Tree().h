#ifndef TREE_H_T
#define TREE_H_T

#include <algorithm>
#include <conio.h>
#include "Tree.h"

///=====================================================
///===========================================BinaryTree

template<class T>
BinaryTree<T>::BinaryTree()
{
    parent = nullptr;
    value = nullptr;
    sxChild = nullptr;
    dxChild = nullptr;
}
template<class T>
BinaryTree<T>::BinaryTree(T newData)
{
    parent = nullptr;
    setValue(newData);
    sxChild = nullptr;
    dxChild = nullptr;
}
template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& origin)
{
    *this = origin;
}
template<class T>
bool BinaryTree<T>::operator==(const BinaryTree<T>& origin)
{
    static bool verdict = true;
    static int depth = 0;

    auto verdicter = [&](bool decision)->bool
    {
        verdict = decision;
        depth--;
        return verdict;
    };

    if(depth == 0)
        verdict = true;

    depth++;
    if(verdict == false)
        return verdicter(verdict);

    if(this->isNull() != origin.isNull())
        return verdicter(false);
    else if(this->isNull() && origin.isNull())
        return verdicter(true);

    if(this->getValue() != origin.getValue())
        return verdicter(false);

    if(this->hasSx() == origin.hasSx())
        *this->getSx() == *origin.getSx();
    else
        return verdicter(false);

    if(this->hasDx() == origin.hasDx())
        *this->getDx() == *origin.getDx();
    else
        return verdicter(false);

    depth--;
    return verdict;
}
template<class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& origin)
{
    if(!origin.getParent())
    {
        if(*this == origin)
            return *this;

        this->~BinaryTree();
        if(origin.isNull())
            return *this;

        this->setValue(origin.getValue());
    }

    return this->operatorEqual(origin);
}
template<class T>
BinaryTree<T>& BinaryTree<T>::operatorEqual(const BinaryTree<T>& origin) //SUPPORTO PER SOPRA
{
    this->parent = origin.parent;
    if(origin.hasSx())
    {
        this->setSx(origin.getSx()->getValue());
        *this->sxChild = *origin.sxChild;
    }
    if(origin.hasDx())
    {
        this->setDx(origin.getDx()->getValue());
        *this->dxChild = *origin.dxChild;
    }

    return *this;
}
template<class T>
std::ostream& operator<<(std::ostream& os, const BinaryTree<T>& origin)
{
    origin.fullPrint();
    return os;
}

///Getters

template<class T>
BinaryTree<T>* BinaryTree<T>::getParent() const
{
    return parent;
}
template<class T>
T BinaryTree<T>::getValue() const
{
    if(isNull())
        throw dataException();
    return *value;
}
template<class T>
BinaryTree<T>* BinaryTree<T>::getSx() const
{
    return sxChild.get();
}
template<class T>
BinaryTree<T>* BinaryTree<T>::getDx() const
{
    return dxChild.get();
}
template<class T>
BinaryTree<T>* BinaryTree<T>::getSibling() const
{
    if(parent)
        if(isSx())
            return parent->getDxChild();
        else
            return parent->getSxChild();
    else
        return nullptr;
}
template<class T>
int BinaryTree<T>::getHeight()
{
    int currHeight = 0;
    int maxHeight = 0;
    return getHeight(currHeight, maxHeight);
}
template<class T>
int BinaryTree<T>::getHeight(int& currHeight, int&maxHeight)
{
    if(hasSx())
    {
        currHeight++;
        if(currHeight > maxHeight)
            maxHeight = currHeight;
        getSx()->getHeight(currHeight, maxHeight);
        currHeight--;
    }
    if(hasDx())
    {
        currHeight++;
        if(currHeight > maxHeight)
            maxHeight = currHeight;
        getDx()->getHeight(currHeight, maxHeight);
        currHeight--;
    }

    return maxHeight;
}
template<class T>
int BinaryTree<T>::getWidth()
{
    int height = getHeight()+1;
    int* levels = new int[height];
    for(int i = 0; i < height; i++)
        levels[i] = 0;

    levels[0] = 1;
    int level = 0;

    getWidth(levels, level);

    int mx = 0;
    for(int i = 0; i < height; i++)
        if(levels[i] > mx)
            mx = levels[i];

    delete[] levels;
    return mx;
}
template<class T>
void BinaryTree<T>::getWidth(int* levels, int& level)
{
    if(hasSx())
    {
        level++;
        levels[level]++;
        getSx()->getWidth(levels, level);
        level--;
    }
    if(hasDx())
    {
        level++;
        levels[level]++;
        getDx()->getWidth(levels, level);
        level--;
    }
}

///State monitors

template<class T>
bool BinaryTree<T>::isNull() const
{
    if( (this == nullptr) || !value )
        return true;
    return false;
}
template<class T>
bool BinaryTree<T>::isLeaf() const
{
    if(sxChild || dxChild)
        return false;
    return true;
}
template<class T>
bool BinaryTree<T>::isSx() const
{
    if(parent && parent->getSxChild() == this)
        return true;
    return false;
}
template<class T>
bool BinaryTree<T>::isDx() const
{
    if(parent && parent->getDxChild() == this)
        return true;
    return false;
}
template<class T>
bool BinaryTree<T>::hasParent() const
{
    if(parent->isNull())
        return false;
    return true;
}
template<class T>
bool BinaryTree<T>::hasSx() const
{
    if(sxChild->isNull())
        return false;
    return true;
}
template<class T>
bool BinaryTree<T>::hasDx() const
{
    if(dxChild->isNull())
        return false;
    return true;
}

///Setters

template<class T>
void BinaryTree<T>::setParent(BinaryTree<T>* newParent)
{
    parent = newParent;
}
template<class T>
void BinaryTree<T>::setValue(T newData)
{
    value.reset(new T(newData));
}
template<class T>
void BinaryTree<T>::setSx(BinaryTree<T>* newSx)
{
    sxChild.reset(newSx);
}
template<class T>
void BinaryTree<T>::setDx(BinaryTree<T>* newDx)
{
    dxChild.reset(newDx);
}
template<class T>
void BinaryTree<T>::setSx(T newSx)
{
    BinaryTree<T>* soonSx = new BinaryTree(newSx);
    soonSx->setParent(this);
    sxChild.reset(soonSx);
}
template<class T>
void BinaryTree<T>::setDx(T newDx)
{
    BinaryTree<T>* soonDx = new BinaryTree(newDx);
    soonDx->setParent(this);
    dxChild.reset(soonDx);
}

///Doers

template<class T>
void BinaryTree<T>::remove(BinaryTree<T>* toRemove)
{
    if(!toRemove->isNull())
    {
        toRemove->parent = nullptr;
        toRemove->~BinaryTree();
    }
}
template<class T>
void BinaryTree<T>::fullPrint() const
{
    static int depth = 0;
    for(int i = 0; i < depth*2; i++)
        std::cout << " ";

    if(!isNull())
        std::cout << "->" << getValue() << std::endl;
    else
        std::cout << "->" << std::endl;

    depth++;
    if(!isNull())
    {
        if(hasSx())
            getSx()->fullPrint();
        else
        {
            BinaryTree<T> temp;
            temp.fullPrint();
        }

        if(hasDx())
            getDx()->fullPrint();
        else
        {
            BinaryTree<T> temp;
            temp.fullPrint();
        }
    }
    depth--;
}

template<class T>
void BinaryTree<T>::print() const
{
    static int depth = 0;
    for(int i = 0; i < depth*2; i++)
        std::cout << " ";
    std::cout << "->" << getValue() << std::endl;

    depth++;
    if(hasSx())
        getSx()->print();
    if(hasDx())
        getDx()->print();
    depth--;
}

///=====================================================
///=================================================Tree

template<class T>
Tree<T>::Tree()
{
    parent = nullptr;
    holdingNode = nullptr;
    value = nullptr;
}
template<class T>
Tree<T>::Tree(T newData)
{
    parent = nullptr;
    holdingNode = nullptr;
    setValue(newData);
}
template<class T>
Tree<T>::Tree(const Tree<T>& origin)
{
    *this = origin;
}
template<class T>
bool Tree<T>::operator==(const Tree<T>& origin)
{
    bool verdict = true;
    //bool thisNull = this->isNull();
    //bool origNull = origin.isNull();
    return this->operatorEqualEqual(verdict, origin);
}
template<class T>
bool Tree<T>::operatorEqualEqual(bool& verdict, const Tree<T>& origin)
{
    if(verdict == false)
        return verdict;

    //bool thisNull = this->isNull();
    //bool origNull = origin.isNull();
    int itLens =this->children.getLen();
    int orLens = origin.children.getLen();

    if(this->isNull() != origin.isNull())
        return verdict = false;
    else if(!this->isNull() && !origin.isNull())
        if(this->getValue() != origin.getValue())
            return verdict = false;

    if(this->children.getLen() != origin.children.getLen())
        return verdict = false;

    Tree<T>* iter = getFirstSon();
    Tree<T>* origIter = origin.getFirstSon();
    while(!iter->isNull())
    {
         verdict = iter->operatorEqualEqual(verdict,*origIter);
         iter = iter->getProxSib();
         origIter = origIter->getProxSib();
    }
    return verdict;
}
template<class T>
Tree<T>& Tree<T>::operator=(const Tree<T>& origin)
{
    if(!(*this == origin) && (!origin.isNull()))
    {
        this->~Tree();
        this->setValue(origin.getValue());
    }
    if(!origin.isNull())
        return this->operatorEqual(origin);
    else
    {
        children = List<std::shared_ptr<Tree<T>>>();
        parent = nullptr;
        holdingNode = nullptr;
        value.reset();
        return *this;
    }
}
template<class T>
Tree<T>& Tree<T>::operatorEqual(const Tree<T>& origin)
{
    for(Node<std::shared_ptr<Tree<T>>>* x = origin.getChildren().getFirst(); !x->isNull(); x = x->getProx())
        this->appendChild(x->getData()->getValue());

    Tree<T>* iter = this->getFirstSon();
    Tree<T>* origIter = origin.getFirstSon();
    while(!iter->isNull())
    {
        *iter = *origIter;
        iter = iter->getProxSib();
        origIter = origIter->getProxSib();
    }

    return *this;
}
template<class T>
std::ostream& operator<<(std::ostream& os, const Tree<T>& origin)
{
    origin.print();
    return os;
}

///Getters

template<class T>
Tree<T>* Tree<T>::getParent() const
{
    return parent;
}
template<class T>
Node<std::shared_ptr<Tree<T>>>* Tree<T>::getHoldingNode() const
{
    return holdingNode;
}
template<class T>
T Tree<T>::getValue() const
{
    if(isNull())
        throw dataException();
    return *value;
}
template<class T>
List<std::shared_ptr<Tree<T>>>& Tree<T>::getChildren() const
{
    return children;
}
template<class T>
Tree<T>* Tree<T>::getProxSib() const
{
    if(holdingNode->getProx())
    {
        Tree<T>* nextMaybe = holdingNode->getProx()->getData().get();
        if(nextMaybe->isNull())
            return nullptr;
        else
            return nextMaybe;
    }
    else
        return nullptr;
}
template<class T>
Tree<T>* Tree<T>::getPrexSib() const
{
    if(holdingNode->getPrex())
    {
        Tree<T>* nextMaybe = holdingNode->getPrex()->getData().get();
        if(nextMaybe->isNull())
            return nullptr;
        else
            return nextMaybe;
    }
    else
        return nullptr;
}
template<class T>
Tree<T>* Tree<T>::getFirstSon() const
{
    if(children.getFirst())
        return children.getFirst()->getData().get();
    else
        return nullptr;
}
template<class T>
Tree<T>* Tree<T>::getLastSon() const
{
    if(children.getFinish())
        return children.getFinish()->getData().get();
    else
        return nullptr;
}

///Hasers

template<class T>
bool Tree<T>::isNull() const
{
    if( (this == nullptr) || !value )
        return true;
    return false;
}
template<class T>
bool Tree<T>::hasParent() const
{
    if(parent->isNull())
        return false;
    return true;
}
template<class T>
bool Tree<T>::hasChildren() const
{
    if(children.isEmpty())
        return false;
    return true;
}
template<class T>
bool Tree<T>::hasPrexSib() const
{
    if(getPrexSib())
        return true;
    return false;
}
template<class T>
bool Tree<T>::hasProxSib() const
{
    if(getProxSib())
        return true;
    return false;
}


///Setters

template<class T>
void Tree<T>::setParent(Tree<T>* newParent)
{
    parent = newParent;
}
template<class T>
void Tree<T>::setHoldingNode(Node<std::shared_ptr<Tree<T>>>* newHoldingNode)
{
    holdingNode = newHoldingNode;
}
template<class T>
void Tree<T>::setValue(T newData)
{
    value.reset(new T(newData));
}
template<class T>
void Tree<T>::setChildren(List<std::shared_ptr<Tree<T>>> newChildren)
{
    children.~List();
    children = newChildren;
}

///Doers

template<class T>
void Tree<T>::appendChild(T newData)
{
    Node<std::shared_ptr<Tree<T>>>* placeInList = children.appendRet(std::shared_ptr<Tree<T>>(new Tree<T>(newData)));
    placeInList->getData()->parent = this;
    placeInList->getData()->holdingNode = placeInList;
}
template<class T>
void Tree<T>::pushChild(T newData)
{
    Node<std::shared_ptr<Tree<T>>>* placeInList = children.pushRet(std::shared_ptr<Tree<T>>(new Tree<T>(newData)));
    placeInList->getData()->parent = this;
    placeInList->getData()->holdingNode = placeInList;
}
template<class T>
void Tree<T>::remove(Tree<T>* toRemove)
{
    if(toRemove != nullptr)
    {
        if(toRemove->hasParent())
            toRemove->getParent()->getChildren().remove(toRemove->getHoldingNode());
        toRemove->~Tree();
    }
}
template<class T>
void Tree<T>::print() const
{
    static int depth = 0;
    for(int i = 0; i < depth*2; i++)
        std::cout << " ";

    if(!isNull())
        std::cout << "->" << this->getValue() << std::endl;
    else
        std::cout << "->" << std::endl;

    Node<std::shared_ptr<Tree<T>>>* iter = children.getFirst();
    while(!iter->isNull())
    {
        depth++;
        iter->getData()->print();
        iter = iter->getProx();
        depth--;
    }
}

///=====================================================
///==============================================SrcTree

template<class R, class T>
BinSrcTree<R,T>::BinSrcTree()
{
    parent = nullptr;
    key = nullptr;
    value = nullptr;
    sxChild = nullptr;
    dxChild = nullptr;
}
template<class R, class T>
BinSrcTree<R,T>::BinSrcTree(R newKey, T newValue)
{
    parent = nullptr;
    setKey(newKey);
    setValue(newValue);
    sxChild = nullptr;
    dxChild = nullptr;
}
template<class R, class T>
BinSrcTree<R,T>::BinSrcTree(const BinSrcTree<R,T>& origin)
{
    *this = origin;
}
template<class R, class T>
bool BinSrcTree<R,T>::operator==(const BinSrcTree<R,T>& origin)
{
    static bool verdict = true;
    static int depth = 0;

    auto verdicter = [&](bool decision)->bool
    {
        verdict = decision;
        depth--;
        return verdict;
    };

    if(depth == 0)
        verdict = true;

    depth++;
    if(verdict == false)
        return verdicter(verdict);

    if(this->isNull() != origin.isNull())
        return verdicter(false);
    else if(this->isNull() && origin.isNull())
        return verdicter(true);

    if(this->getValue() != origin.getValue())
        return verdicter(false);

    if(this->hasSx() == origin.hasSx())
        *this->getSx() == *origin.getSx();
    else
        return verdicter(false);

    if(this->hasDx() == origin.hasDx())
        *this->getDx() == *origin.getDx();
    else
        return verdicter(false);

    depth--;
    return verdict;
}
template<class R, class T>
BinSrcTree<R,T>& BinSrcTree<R,T>::operator=(const BinSrcTree<R,T>& origin)
{
    if(!origin.getParent())
    {
        if(*this == origin)
            return *this;

        this->~BinSrcTree();
        if(origin.isNull())
            return *this;

        this->setKey(origin.getKey());
        this->setValue(origin.getValue());
    }

    return this->operatorEqual(origin);
}
template<class R, class T>
BinSrcTree<R,T>& BinSrcTree<R,T>::operatorEqual(const BinSrcTree<R,T>& origin) //SUPPORTO PER SOPRA
{
    this->parent = origin.parent;
    if(origin.hasSx())
    {
        this->setSx(origin.getSx()->getKey(), origin.getSx()->getValue());
        *this->sxChild = *origin.sxChild;
    }
    if(origin.hasDx())
    {
        this->setDx(origin.getDx()->getKey(), origin.getDx()->getValue());
        *this->dxChild = *origin.dxChild;
    }

    return *this;
}
template<class R, class T>
std::ostream& operator<<(std::ostream& os, const BinSrcTree<R,T>& origin)
{
    origin.fullPrint();
    return os;
}
/// Getters

template<class R, class T>
BinSrcTree<R,T>* BinSrcTree<R,T>::getParent() const
{
    return parent;
}
template<class R, class T>
R BinSrcTree<R,T>::getKey() const
{
    if(isNull())
        throw dataException();
    return *key;
}
template<class R, class T>
T BinSrcTree<R,T>::getValue() const
{
    if(isNull())
        throw dataException();
    return *value;
}
template<class R, class T>
BinSrcTree<R,T>* BinSrcTree<R,T>::getSx() const
{
    return sxChild.get();
}
template<class R, class T>
BinSrcTree<R,T>* BinSrcTree<R,T>::getDx() const
{
    return dxChild.get();
}
template<class R, class T>
BinSrcTree<R,T>* BinSrcTree<R,T>::getSibling() const
{
    if(hasParent())
        if(isSx())
            return parent->getDxChild();
        else
            return parent->getSxChild();
    else
        return nullptr;
}

///State monitors

template<class R, class T>
bool BinSrcTree<R,T>::isNull() const
{
    if( (this == nullptr) || !value )
        return true;
    return false;
}
template<class R, class T>
bool BinSrcTree<R,T>::isLeaf() const
{
    if(sxChild || dxChild)
        return false;
    return true;
}
template<class R, class T>
bool BinSrcTree<R,T>::isSx() const
{
    if(parent && parent->getSx() == this)
        return true;
    return false;
}
template<class R, class T>
bool BinSrcTree<R,T>::isDx() const
{
    if(parent && parent->getDx() == this)
        return true;
    return false;
}
template<class R, class T>
bool BinSrcTree<R,T>::hasParent() const
{
    if(parent->isNull())
        return false;
    return true;
}
template<class R, class T>
bool BinSrcTree<R,T>::hasSx() const
{
    if(sxChild->isNull())
        return false;
    return true;
}
template<class R, class T>
bool BinSrcTree<R,T>::hasDx() const
{
    if(dxChild->isNull())
        return false;
    return true;
}

template<class R, class T>
BinSrcTree<R,T>* BinSrcTree<R,T>::getMin()
{
    if(!hasSx())
        return this;
    else
        return getSx()->getMin();
}
template<class R, class T>
BinSrcTree<R,T>* BinSrcTree<R,T>::getMax()
{
    if(!hasDx())
        return this;
    else
        return getDx()->getMax();
}
template<class R, class T>
BinSrcTree<R,T>* BinSrcTree<R,T>::getSuccessor()
{
    if(hasDx())
        return getDx()->getMin();
    else
    {
        BinSrcTree<R,T>* crawler = this;
        while(!crawler->isSx())
        {
            if(crawler->isNull() || !crawler->hasParent())
                return nullptr;

            crawler = parent;
        }
        return crawler->parent;
    }
}
template<class R, class T>
BinSrcTree<R,T>* BinSrcTree<R,T>::getPredecessor()
{
    if(hasSx())
        return getSx()->getMax();
    else
    {
        BinSrcTree<R,T>* crawler = this;
        while(!crawler->isDx())
        {
            if(crawler->isNull() || !crawler->hasParent())
                return nullptr;

            crawler = parent;
        }
        return crawler->parent;
    }
}
template<class R, class T>
int BinSrcTree<R,T>::getHeight()
{
    int currHeight = 0;
    int maxHeight = 0;
    return getHeight(currHeight, maxHeight);
}
template<class R, class T>
int BinSrcTree<R,T>::getHeight(int& currHeight, int&maxHeight)
{
    if(hasSx())
    {
        currHeight++;
        if(currHeight > maxHeight)
            maxHeight = currHeight;
        getSx()->getHeight(currHeight, maxHeight);
        currHeight--;
    }
    if(hasDx())
    {
        currHeight++;
        if(currHeight > maxHeight)
            maxHeight = currHeight;
        getDx()->getHeight(currHeight, maxHeight);
        currHeight--;
    }

    return maxHeight;
}
template<class R, class T>
int BinSrcTree<R,T>::getWidth()
{
    int height = getHeight()+1;
    int* levels = new int[height];
    for(int i = 0; i < height; i++)
        levels[i] = 0;

    levels[0] = 1;
    int level = 0;

    getWidth(levels, level);

    int mx = 0;
    for(int i = 0; i < height; i++)
        if(levels[i] > mx)
            mx = levels[i];

    delete[] levels;
    return mx;
}
template<class R, class T>
void BinSrcTree<R,T>::getWidth(int* levels, int& level)
{
    if(hasSx())
    {
        level++;
        levels[level]++;
        getSx()->getWidth(levels, level);
        level--;
    }
    if(hasDx())
    {
        level++;
        levels[level]++;
        getDx()->getWidth(levels, level);
        level--;
    }
}

///Setters

template<class R, class T>
void BinSrcTree<R,T>::setParent(BinSrcTree<R,T>* newParent)
{
    parent = newParent;
}
template<class R, class T>
void BinSrcTree<R,T>::setKey(R newKey)
{
    key.reset(new R(newKey));
}
template<class R, class T>
void BinSrcTree<R,T>::setValue(T newData)
{
    value.reset(new T(newData));
}
template<class R, class T>
void BinSrcTree<R,T>::setSx(BinSrcTree<R,T>* newSx)
{
    sxChild.reset(newSx);
}
template<class R, class T>
void BinSrcTree<R,T>::setDx(BinSrcTree<R,T>* newDx)
{
    dxChild.reset(newDx);
}
template<class R, class T>
void BinSrcTree<R,T>::setSx(R key, T newSx)
{
    BinSrcTree<R,T>* soonSx = new BinSrcTree(key, newSx);
    soonSx->setParent(this);
    sxChild.reset(soonSx);
}
template<class R, class T>
void BinSrcTree<R,T>::setDx(R key, T newDx)
{
    BinSrcTree<R,T>* soonDx = new BinSrcTree(key, newDx);
    soonDx->setParent(this);
    dxChild.reset(soonDx);
}

///Doers

template<class R, class T>
void BinSrcTree<R,T>::insert(R key, T value)
{
    if(key >= getKey())
    {
        if(getDx()->isNull())
            setDx(key, value);
        else
            this->dxChild->insert(key, value);
    }
    else
    {
        if(getSx()->isNull())
            setSx(key, value);
        else
            this->sxChild->insert(key, value);
    }
}
template<class R, class T>
void BinSrcTree<R,T>::insert(BinSrcTree<R,T> toInsert)
{
    insert(toInsert.getKey(), toInsert.getValue());
}
template<class R, class T>
BinSrcTree<R,T>* BinSrcTree<R,T>::findByKey(R key)
{
    if(isNull())
        return nullptr;

    if(key == getKey())
        return this;
    else
        if(key >= getKey())
            return getDx()->findByKey(key);
        else
            return getSx()->findByKey(key);
}
template<class R, class T>
void BinSrcTree<R,T>::remove()
{
    if(!hasParent())
        return;

    if(isLeaf())
    {
        if(isSx())
            parent->getSx()->value.reset();
        else
            parent->getDx()->value.reset();
    }
    else if(hasSx() && !hasDx())
    {
        if(isSx())
            parent->sxChild = std::move(sxChild);
        else
            parent->dxChild = std::move(sxChild);
    }
    else if(!hasSx() && hasDx())
    {
        if(isSx())
            parent->sxChild = std::move(dxChild);
        else
            parent->dxChild = std::move(dxChild);
    }
    else if(hasSx() && hasDx())
    {
        BinSrcTree<R,T>* dxMin = getDx()->getMin();
        setKey(dxMin->getKey());
        setValue(dxMin->getValue());
        dxMin->remove();
    }
}
template<class R, class T>
void BinSrcTree<R,T>::fullPrint() const
{
    static int depth = 0;
    for(int i = 0; i < depth*2; i++)
        std::cout << " ";

    if(!this->isNull())
        std::cout << "->" << "(" << getKey() << ")" << " " << this->getValue() <<  std::endl;
    else
        std::cout << "->" << std::endl;

    depth++;
    if(!this->isNull())
    {
        if(this->hasSx())
            this->getSx()->fullPrint();
        else
        {
            BinSrcTree<R,T> temp;
            temp.fullPrint();
        }

        if(this->hasDx())
            this->getDx()->fullPrint();
        else
        {
            BinSrcTree<R,T> temp;
            temp.fullPrint();
        }
    }
    depth--;
}

template<class R, class T>
void BinSrcTree<R,T>::print() const
{
    static int depth = 0;
    for(int i = 0; i < depth*2; i++)
        std::cout << " ";
    std::cout << "->" << "(" << getKey() << ")" << " " << this->getValue() <<  std::endl;

    depth++;
    if(this->hasSx())
        this->getSx()->print();
    if(this->hasDx())
        this->getDx()->print();
    depth--;
}

#endif // TREE_H_T

