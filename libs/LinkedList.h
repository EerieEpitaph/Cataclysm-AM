#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define FIRST_POLICY 0
#define LAST_POLICY 1
#define GROUP_POLICY 2

#include <memory>
#include "../ExtraExceptions/ExtraExceptions.h"

template<typename T>
class LinkedList;

template<typename T>
class Node
{
    friend class LinkedList<T>;
    private:
        Node<T>* prex;
        std::unique_ptr<T> data;
        Node<T>* prox;

    public:
        Node();
        Node(T startData);
        Node(Node<T>* prex, T startData, Node<T>* prox);

        Node<T>* getPrex();
        T& getData();
        Node<T>* getProx();

        bool hasPrev();
        bool isNull();
        bool hasNext();

        void setPrex(Node<T>* newPrex);
        void setData(T newData);
        void setProx(Node<T>* newProx);
        void edit(T newData);

        void link(Node<T>* frontLink);
};

template<typename T>
class LinkedList
{
    protected:
        int len;
        Node<T>* startNode;
        Node<T>* finishNode;

    public:
        LinkedList();
        LinkedList(Node<T>* firstNode);
        LinkedList(const LinkedList<T>& from);
        bool operator==(const LinkedList<T>& origin);
        LinkedList<T>& operator=(const LinkedList<T>& origin);
        virtual ~LinkedList();

        int getLen() const;
        Node<T>* getFirst() const;
        Node<T>* getFinish() const;
        Node<T>* getNode(int position);

        void setLen(int newLen);
        void setFirst(Node<T>* newFirst);
        void setFinish(Node<T>* newFinish);

        void reverse();
        void remove(int position);
        void remove(Node<T>* toRemove);
        void removeData(T toRemove);
        void removeData(T toRemove, int policy);

        void print() const;
        bool isPalindrome();
        bool isEmpty() const;
        virtual bool contains(T toFind);
        int findPos(T toFind);
        int findPos(T toFind, int policy);
        Node<T>* findNode(T toFind);
        Node<T>* findNode(T toFind, int policy);

        void checkIntegrity();
};

template<class T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& origin);
template<class T>
std::ostream& operator<<(std::ostream& os, const std::unique_ptr<T>& origin);

template<typename T>
class List : public LinkedList<T>
{
    using LinkedList<T>::LinkedList;

    public:
        virtual void append(T data);
        virtual Node<T>* appendRet(T data);
        virtual void push(T data);
        virtual Node<T>* pushRet(T data);
        virtual void insert(T data, Node<T>* after);
        virtual void insert(T data, int position);
        void edit(T newData, int position);
        virtual void merge(LinkedList<T> toMerge);
};

template<typename T>
class ExclusiveList : public List<T>
{
    using LinkedList<T>::LinkedList;

    public:
        void append(T data);
        void push(T data);
        void insert(T data, int position);//TODO
        void merge(LinkedList<T> toMerge);
};

template<typename T>
class OrdList : public LinkedList<T>
{
    using LinkedList<T>::LinkedList;

    public:
        virtual void insert(T data);
        virtual void merge(LinkedList<T> toMerge);
};

template<typename T>
class ExclusiveOrdList : public LinkedList<T>
{
    using LinkedList<T>::LinkedList;

    public:
        void insert(T data);
        void merge(LinkedList<T> toMerge);
};
#include "LinkedList().h"
#endif
