#ifndef LINKEDLIST_T_H
#define LINKEDLIST_T_H

#include <typeinfo>
#include "LinkedList.h"

///=============================================================
///========================================================NODES
///===================================
///========================COSTR-DESTR

template<typename T>
Node<T>::Node()
{
    setPrex(NULL);
    data = NULL;
    setProx(NULL);
}

template<typename T>
Node<T>::Node(T startData)
{
    setPrex(NULL);
    setData(startData);
    setProx(NULL);
}

template<typename T>
Node<T>::Node(Node<T>* prex, T startData, Node<T>* prox)
{
    setPrex(prex);
    setData(startData);
    setProx(prox);
}

///===================================
///============================GET-SET

template<typename T>
Node<T>* Node<T>::getPrex()
{
    return prex;
}

template<typename T>
T& Node<T>::getData()
{
    if(isNull())
        throw dataException();
    return *data;
}

template<typename T>
Node<T>* Node<T>::getProx()
{
    return prox;
}

///

template<typename T>
bool Node<T>::hasPrev()
{
    if(getPrex() == NULL)
        return false;
    return true;
}

template<typename T>
bool Node<T>::isNull()
{
    if((this == NULL) || data == NULL)
        return true;
    return false;
}

template<typename T>
bool Node<T>::hasNext()
{
    if(getProx() == NULL)
        return false;
    return true;
}

///

template<typename T>
void Node<T>::setPrex(Node<T>* newPrex)
{
    prex = newPrex;
}

template<typename T>
void Node<T>::setData(T newData)
{
    data.reset(new T(newData));
}

template<typename T>
void Node<T>::setProx(Node<T>* newProx)
{
    prox = newProx;
}

template<typename T>
void Node<T>::edit(T newData)
{
    this->~Node();
    setData(newData);
}

///===================================
///============================OPERATS

template<typename T>
void Node<T>::link(Node<T>* frontLink)
{
    this->setProx(frontLink);
    frontLink->setPrex(this);
}

///=============================================================
///=================================================LINKED LISTS
///=====================================
///========================COMMON GROUND

template<typename T>
LinkedList<T>::LinkedList()
{
    setLen(0);
    setFirst(NULL);
    setFinish(NULL);
}

template<typename T>
LinkedList<T>::LinkedList(Node<T>* firstFirst)
{
    setLen(1);
    setFirst(firstFirst);
    setFinish(firstFirst);
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& from)
{
    Node<T>* temp;
    this->len = from.len;
    this->setFirst(NULL);
    this->setFinish(NULL);

    Node<T>* fromIter = from.getFirst();
    if(!fromIter->isNull())
    {
        temp = new Node<T>(fromIter->getData());
        this->setFirst(temp);
        this->setFinish(temp);
        fromIter = fromIter->getProx();
    }

    while(!fromIter->isNull())
    {
        temp = new Node<T>(fromIter->getData());
        this->getFinish()->link(temp);
        this->setFinish(temp);
        fromIter = fromIter->getProx();
    }
}

template<typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& origin)
{
    if(this->getLen() != origin.getLen())
        return false;

    Node<T>* thisIter = getFirst();
    Node<T>* originIter = origin.getFirst();

    while( !thisIter->isNull() )
    {
        if( !(thisIter->getData() == originIter->getData()) )
            return false;

        thisIter = thisIter->getProx();
        originIter = originIter->getProx();
    }

    return true;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& origin)
{
    if( !(*this == origin) )
    {
        this->~LinkedList();
        this->len = origin.len;
        this->startNode = NULL;
        this->finishNode = NULL;

        Node<T>* iter = origin.getFirst();

        if(!iter->isNull())
        {
            Node<T>* thisIter = new Node<T>(iter->getData());
            iter = iter->getProx();
            this->setFirst(thisIter);

            while( !iter->isNull() )
            {
                thisIter->link(new Node<T>(iter->getData()));
                iter = iter->getProx();
                thisIter = thisIter->getProx();
            }

            setFinish(thisIter);
        }
    }
    return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& origin)
{
    origin.print();
    return os;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* iter = getFirst();
    while(!iter->isNull())
    {
        Node<T>* nextIter = iter->getProx();
        iter->data.reset();
        delete iter;
        iter = nextIter;
    }
}

///===================================
///============================GET-SET

template<typename T>
int LinkedList<T>::getLen() const
{
    return len;
}

template<typename T>
Node<T>* LinkedList<T>::getFirst() const
{
    return startNode;
}

template<typename T>
Node<T>* LinkedList<T>::getFinish() const
{
    return finishNode;
}

template<typename T>
Node<T>* LinkedList<T>::getNode(int position)
{
    if( position >= len || position < 0 )
        return NULL;

    bool goAhead = true;
    if( position >= len/2 )
        goAhead = false;

    Node<T>* iter;
    if(goAhead)
    {
        iter = getFirst();
        for(int counter = 0; counter != position; counter++ )
            iter = iter->getProx();
    }
    else
    {
         iter = getFinish();
         for(int counter =  len-1; counter != position; counter-- )
            iter = iter->getPrex();
    }

    return iter;
}

template<typename T>
void LinkedList<T>::setLen(int newLen)
{
    len = newLen;
}

template<typename T>
void LinkedList<T>::setFirst(Node<T>* newFirst)
{
    startNode = newFirst;
}

template<typename T>
void LinkedList<T>::setFinish(Node<T>* newFinish)
{
    finishNode = newFinish;
}

///==========================================
///============================COMMON OPERATS

template<typename T>
void LinkedList<T>::reverse()
{
    Node<T>* leftIter = getFirst();
    Node<T>* rightIter = getFinish();

    while( leftIter != rightIter && rightIter->getProx() != leftIter )
    {
        T tempData = leftIter->getData();
        leftIter->edit( (T) rightIter->getData());
        rightIter->edit(tempData);

        leftIter = leftIter->getProx();
        rightIter = rightIter->getPrex();
    }
}

template<typename T>
void LinkedList<T>::remove(int position)
{
    Node<T>* temp = getNode(position);
    if(!temp->isNull())
        remove(temp);
}

template<typename T>
void LinkedList<T>::remove(Node<T>* toRemove)
{
    if(!isEmpty())
    {
        if(toRemove->getPrex()->isNull() && toRemove->getProx()->isNull())
        {
            setFirst(NULL);
            setFinish(NULL);
        }
        else if(toRemove->getPrex()->isNull() && !toRemove->getProx()->isNull())
        {
            setFirst(toRemove->getProx());
            getFirst()->setPrex(NULL);
        }
        else if(!toRemove->getPrex()->isNull() && toRemove->getProx()->isNull())
        {
            setFinish(toRemove->getPrex());
            getFinish()->setProx(NULL);
        }
        else
            toRemove->getPrex()->link(toRemove->getProx());

        delete toRemove;
        setLen(getLen()-1);
    }
}
template<typename T>
void LinkedList<T>::removeData(T toRemove)
{
    removeData(toRemove, FIRST_POLICY);
}

template<typename T>
void LinkedList<T>::removeData(T toRemove, int policy)
{
    Node<T>* iter;

    if(policy == FIRST_POLICY)
    {
        for(iter = getFirst(); (T) iter->getData() != toRemove; iter = iter->getProx() ){}
        remove(iter);
    }
    else if (policy == LAST_POLICY)
    {
        for(iter = getFinish(); (T) iter->getData() != toRemove; iter = iter->getPrex() ){}
        remove(iter);
    }
    else if (policy == GROUP_POLICY)
    {
        for(iter = getFirst(); !iter->isNull(); iter = iter->getProx() )
        {
            if( (T) iter->getData() == toRemove )
            {
                remove(iter);
                delete iter;
            }
        }
    }
}

template<typename T>
void LinkedList<T>::print() const
{
    std::cout << "{[";
    Node<T>* iter = getFirst();
    while( !iter->isNull() )
    {
        std::cout << iter->getData();
        iter = iter->getProx();
        if( !iter->isNull() )
            std::cout << ",";
    }
    std::cout << "] len=" << len << "}";
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
    if(getFirst()->isNull())
        return true;
    return false;
}

template<typename T>
bool LinkedList<T>::isPalindrome()
{
    Node<T>* leftIter = getFirst();
    Node<T>* rightIter = getFinish();

    while( leftIter != rightIter && rightIter->getProx() != leftIter )
    {
        if(leftIter->getData() != rightIter->getData())
            return false;

        leftIter = leftIter->getProx();
        rightIter = rightIter->getPrex();
    }

    return true;
}

template<typename T>
bool LinkedList<T>::contains(T toFind)
{
    int pos = 0;
    Node<T>* iter = getFirst();
    while( !iter->isNull() && pos < len )
    {
        if( (T) iter->getData() == toFind )
            return true;

        iter = iter->getProx();
        pos++;
    }

    return false;
}

template<typename T>
int LinkedList<T>::findPos(T toFind)
{
    int pos = 0;
    Node<T>* iter = getFirst();
    while( !iter->isNull() && pos < len )
    {
        if( (T) iter->getData() == toFind )
            return pos;

        iter = iter->getProx();
        pos++;
    }

    return -1;
}

template<typename T>
int LinkedList<T>::findPos(T toFind, int policy)
{
    if(policy == FIRST_POLICY)
    {
        find(toFind);
    }
    else
    {
        int pos = len-1;
        Node<T>* iter = getFinish();
        while( !iter->isNull() && pos > 0 )
        {
            if( (T) iter->getData() == toFind )
                return pos;

            iter = iter->getPrex();
            pos--;
        }

        return -1;
    }
}
template<typename T>
Node<T>* LinkedList<T>::findNode(T toFind)
{
    return findNode(toFind, FIRST_POLICY);
}
template<typename T>
Node<T>* LinkedList<T>::findNode(T toFind, int policy)
{
    if(policy == FIRST_POLICY)
    {
        Node<T>* iter = getFirst();
        while( !iter->isNull())
        {
            if( iter->getData() == toFind )
                return iter;

            iter = iter->getProx();
        }

        return nullptr;
    }
    else if(policy == LAST_POLICY)
    {
        int pos = len-1;
        Node<T>* iter = getFinish();
        while( !iter->isNull() && pos > 0 )
        {
            if( (T) iter->getData() == toFind )
                return iter;

            iter = iter->getPrex();
            pos--;
        }

        return nullptr;
    }
}

template<typename T>
void LinkedList<T>::checkIntegrity()
{
    int counter = 0;
    Node<T>* iter = getFirst();
    while(!iter->isNull())
    {
        std::cout << "Node " << counter << ": " << iter->getData() << std::endl;
        iter = iter->getProx();
        counter++;
    }
    std::cout << "Forward: OK with " << counter << " steps" << std::endl << std::endl;

    counter = 0;
    iter = getFinish();
    while(!iter->isNull())
    {
        std::cout << "Node " << counter << ": " << iter->getData() << std::endl;
        iter = iter->getPrex();
        counter++;
    }
    std::cout << "Backward: OK with " << counter << " steps" << std::endl << std::endl;

}

///==============================================================
///=================================================LIST SUBCLASS
///==========================================
///===================================OPERATS

template<typename T>
void List<T>::append(T data)
{
    Node<T>* newNode = new Node<T>(data);
    if(this->getFinish()->isNull())
        this->setFirst(newNode);
    else
        this->getFinish()->link(newNode);

    this->setFinish(newNode);
    this->setLen(this->getLen() + 1);
}
template<typename T>
Node<T>* List<T>::appendRet(T data)
{
    Node<T>* newNode = new Node<T>(data);
    if(this->getFinish()->isNull())
        this->setFirst(newNode);
    else
        this->getFinish()->link(newNode);

    this->setFinish(newNode);
    this->setLen(this->getLen() + 1);

    return this->getFinish();
}

template<typename T>
void List<T>::push(T data)
{
    Node<T>* newNode = new Node<T>(data);

    if(!this->getFirst()->isNull())
        newNode->link(this->getFirst());

    else
        this->setFinish(newNode);

    this->setFirst(newNode);
    this->setLen(this->getLen() + 1);
}
template<typename T>
Node<T>* List<T>::pushRet(T data)
{
    Node<T>* newNode = new Node<T>(data);

    if(!this->getFirst()->isNull())
        newNode->link(this->getFirst());

    else
        this->setFinish(newNode);

    this->setFirst(newNode);
    this->setLen(this->getLen() + 1);
    return newNode;
}

template<typename T>
void List<T>::insert(T data, Node<T>* after)
{
    Node<T>* newNode = new Node<T>(data);

    if(!after->getProx()->isNull())
        newNode->link(after->getProx());
    else
        this->setFinish(newNode);

    after->link(newNode);
    this->setLen(this->getLen() + 1);
}

template<typename T>
void List<T>::insert(T data, int position)
{
    if( position >= 0 && position <= this->getLen())
    {
        Node<T>* prev = this->getNode(position-1);

        if(prev == NULL)
            this->push(data);
        else
            insert(data, prev);
    }
}

template<typename T>
void List<T>::edit(T newData, int position)
{
    if(position == 0)
    {
        Node<T>* first = this->getFirst();
        Node<T>* secondOne = first->getProx();
        delete this->getFirst();
        if(!secondOne->isNull())
        {
            this->setFirst(new Node<T>(newData));
            this->getFirst()->setPrex(NULL);
            this->getFirst()->setProx(secondOne);
        }
        else
        {
            this->setFirst(new Node<T>(newData));
            this->getFirst()->setPrex(NULL);
            this->getFirst()->setProx(NULL);
        }
        return;
    }
    else if(position == LinkedList<T>::len - 1)
    {
        Node<T>* prevOne = LinkedList<T>::getFinish()->getPrex();
        delete LinkedList<T>::getFinish();

        this->setFinish( new Node<T>(newData) );
        prevOne->link(LinkedList<T>::getFinish());
        LinkedList<T>::getFinish()->setProx(NULL);
        return;
    }

    if( position >= LinkedList<T>::len || position < 0 )
    return;

    Node<T>* iter = LinkedList<T>::getFirst();
    for(int counter = 0; counter != position; counter++ )
        iter = iter->getProx();

    Node<T>* newNode = new Node<T>(newData);
    iter->getPrex()->link(newNode);
    newNode->link(iter->getProx());

    delete iter;
}

template<typename T>
void List<T>::merge(LinkedList<T> toMerge) ///MERGE AD CAVOLUM
{
    Node<T>* iter = toMerge.getFirst();
    while(!iter->isNull())
    {
        append( iter->getData() );
        iter = iter->getProx();
    }
}

///==============================================================
///====================================EXCLUSIVELIST SUB-SUBCLASS
///==========================================
///===================================OPERATS

template<typename T>
void ExclusiveList<T>::append(T data)
{
    if(!this->contains(data))
    {
        Node<T>* newNode = new Node<T>(data);
        if(LinkedList<T>::getFinish()->isNull())
            this->setFirst(newNode);

        else
            LinkedList<T>::getFinish()->link(newNode);

        LinkedList<T>::setFinish(newNode);
        LinkedList<T>::setLen(LinkedList<T>::getLen() + 1);
    }
}

template<typename T>
void ExclusiveList<T>::push(T data)
{
    if(!this->contains(data))
    {
        Node<T>* newNode = new Node<T>(data);

        if(!LinkedList<T>::getFirst()->isNull())
            newNode->link(LinkedList<T>::getFirst());

        else
            LinkedList<T>::setFinish(newNode);

        LinkedList<T>::setFirst(newNode);
        LinkedList<T>::setLen(LinkedList<T>::getLen() + 1);
    }
}

template<typename T>
void ExclusiveList<T>::insert(T data, int position)
{

}

template<typename T>
void ExclusiveList<T>::merge(LinkedList<T> toMerge)
{
    Node<T>* iter = toMerge.getFirst();
    while(!iter->isNull())
    {
        if(!this->contains(iter->getData()))
            append( iter->getData() );

        iter = iter->getProx();
    }
}

///==============================================================
///==============================================ORDLIST SUBCLASS
///==========================================
///===================================OPERATS

template<typename T>
void OrdList<T>::insert(T data)
{
    Node<T>* newNode = new Node<T>(data);
    Node<T>* iter = this->getFirst();

    if( this->len == 0 || data <= (T) iter->getData() )
    {
        if(this->len != 0)
            newNode->link(iter);
        else
            this->setFinish(newNode);

         this->setFirst(newNode);
         this->setLen(this->getLen() + 1);
         return;
    }

    while( !iter->isNull() && ( data > (T) iter->getData()))
        iter = iter->getProx();

    if( iter->isNull() )
    {
        this->getFinish()->link(newNode);
        this->setFinish(newNode);
    }
    else
    {
        iter->getPrex()->link(newNode);
        newNode->link(iter);
    }

    this->setLen(this->getLen() + 1);
}

template<typename T>
void OrdList<T>::merge(LinkedList<T> toMerge)
{
    Node<T>* iter = toMerge.getFirst();
    while(!iter->isNull())
    {
        insert( iter->getData() );
        iter = iter->getProx();
    }
}

///==============================================================
///================================EXCLUSIVE-ORD-LIST SUB-SUBCLASS

template<typename T>
void ExclusiveOrdList<T>::insert(T data)
{
    Node<T>* newNode = new Node<T>(data);
    Node<T>* prevIter = this->getFirst();
    Node<T>* iter = prevIter;

    if(this->isEmpty())
    {
        this->setFirst(newNode);
        this->setFinish(newNode);
        this->setLen(this->getLen()+1);
        return;
    }

    if( ( data < (T) this->getFirst()->getData()) ) //INIZIO LISTA
    {
        newNode->link(this->getFirst());
        this->setFirst(newNode);
        this->setLen(this->getLen()+1);
        return;
    }

    if( ( data > (T) this->getFinish()->getData()) ) //FINE LISTA
    {
        this->getFinish()->link(newNode);
        this->setFinish(newNode);
        this->setLen(this->getLen()+1);
        return;
    }

    while(!iter->isNull())
    {
        if( data == (T) iter->getData() )
            return;

        if( data > (T) prevIter->getData() && data < (T) iter->getData() )
        {
            prevIter->link(newNode);
            newNode->link(iter);
            this->setLen(this->getLen()+1);
            return;
        }

        prevIter = iter;
        iter = iter->getProx();
    }
}

template<typename T>
void ExclusiveOrdList<T>::merge(LinkedList<T> toMerge)
{
    Node<T>* iter = toMerge.getFirst();
    while(!iter->isNull())
    {
        insert( iter->getData() );
        iter = iter->getProx();
    }
}

#endif
