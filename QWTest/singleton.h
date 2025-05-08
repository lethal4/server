#ifndef SINGLETON_H
#define SINGLETON_H
#include "global.h"
//模板类
template <typename T>
class singleton{
protected:
    singleton()=default;
    //删除拷贝构造
    singleton(const singleton<T>&) = delete;
    //删除拷贝赋值
    singleton &operator = (const singleton<T>& st) =delete;
    //智能指针
    static std::shared_ptr<T> instance;
public :
    static std::shared_ptr<T> getInstance(){
        //最安全的方式,不存在多个线程竞争.
        //once_flag仅仅调用构造函数一次,即该函数第一次被调用的时候;
        static std::once_flag sFlag;
        std::call_once(sFlag,[&](){
            //make_shared无法访问受到保护的构造函数,new可以在内部直接调用
            //所以这里使用new
            instance = std::shared_ptr<T>(new T);
        });
        return instance;
    }

    void printAddress()
    {
        std::cout<<instance.get()<<std::endl;
    }

     //析构
    ~singleton(){
        std::cout << "this is  singleton destruct"<<std:: endl;
    }
};

template <typename T>
//初始化instance为空指针
std::shared_ptr<T> singleton<T>::instance =nullptr;

#endif // SINGLETON_H
