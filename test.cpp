#include <iostream>
using std::endl;
using std::cout;


template <class T>
class MyArray
{
    public:
        MyArray();  
        MyArray(int length);
        MyArray(MyArray<T> &arr);      
        int Getmaxsize();   //获取容量
        int Getlength();    //获取长度
        void AddElem(T val); //尾部添加
        void DelElem();      //尾部删除
        void ExtendArr(int length); //扩展
        MyArray<T>& operator=(MyArray<T> &arr);
        T& operator[](int i);
    private:
        T *data;        //数据
        int maxsize;    //容量
        int length;     //长度
};

/*
----------------------------------------------------------
*/

template <class T>
MyArray<T>::MyArray()   //默认长度为0
{
    this->length = 0;
    this->maxsize = 0;
}

template <class T>
MyArray<T>::MyArray(int length)
{
    this->data = new T[length];
    this->maxsize = length;
    this->length = 0;
}

template <class T>
MyArray<T>::MyArray(MyArray<T> &arr)
{
    this->data = new T[arr.maxsize];
    this->length = arr.length;
    this->maxsize = arr.maxsize;
    for (int i = 0; i < maxsize; i++)
    {
        this->data[i] = arr.data[i];
    }
}

template <class T>
int MyArray<T>::Getmaxsize()
{
    return this->maxsize;
}

template <class T>
int MyArray<T>::Getlength()
{
    return this->length;
}

template <class T>  
void MyArray<T>::AddElem(T val)
{
    if (this->maxsize <= this->length)
    {
        ExtendArr(10);
    }
    this->data[this->length] = val;
    length++;
}

template <class T> 
void MyArray<T>::ExtendArr(int length)
{
    T *temp = this->data;
    this->data = new T[this->maxsize + length];
    for (int i = 0; i < this->maxsize; i++)
    {
        this->data[i] = temp[i];
    }
    this->maxsize += length;
    delete[] temp;
}

template <class T>
MyArray<T>& MyArray<T>::operator=(MyArray<T> &arr)
{
    this->data = new T[arr.maxsize];
    this->length = arr.length;
    this->maxsize = arr.maxsize;
    for (int i = 0; i < maxsize; i++)
    {
        this->data[i] = arr.data[i];
    }
    return *this;
}

template <class T>
void MyArray<T>::DelElem()
{
    delete this->data[(this->length) - 1];
    length--;
}

template <class T>
T& MyArray<T>::operator[](int i)
{
    return this->data[i];
}
