#ifndef _EVENTMANAGER_H_
#define _EVENTMANAGER_H_

#include "Event.h"

// 事件管理器实现
// 非线程安全
template <typename Signature>
class CEventImpl{
public:
    void Connect(Signature obj){
        m_Functor.Add(obj);
    }

    void DisConnect(Signature obj){
        m_Functor.Remove(obj);
    }

    void operator()(){
        auto iter = m_Functor.getHead();
        while (NULL != iter){
            (iter->obj)();
            iter = iter->next;
        }
    }

    template <typename p1> 
    void operator()(p1 arg1){
        auto iter = m_Functor.getHead();
        while (NULL != iter){
            (iter->obj)(arg1);
            iter = iter->next;
        }
    }

    template <typename p1, typename p2>
        void operator()(p1 arg1, p2 arg2){
            auto iter = m_Functor.getHead();
            while (NULL != iter){
                (iter->obj)(arg1, arg2);
                iter = iter->next;
            }
        }

    template <typename p1, typename p2, typename p3>
        void operator()(p1 arg1, p2 arg2, p3 arg3){
            auto iter = m_Functor.getHead();
            while (NULL != iter){
                (iter->obj)(arg1, arg2, arg3);
                iter = iter->next;
            }
        }

    template <typename p1, typename p2, typename p3, typename p4>
        void operator()(p1 arg1, p2 arg2, p3 arg3, p4 arg4){
            auto iter = m_Functor.getHead();
            while (NULL != iter){
                (iter->obj)(arg1, arg2, arg3, arg4);
                iter = iter->next;
            }
        }

    template <typename p1, typename p2, typename p3, typename p4, typename p5>
        void operator()(p1 arg1, p2 arg2, p3 arg3, p4 arg4, p5 arg5){
            auto iter = m_Functor.getHead();
            while (NULL != iter){
                (iter->obj)(arg1, arg2, arg3, arg4, arg5);
                iter = iter->next;
            }
        }

private:
    CEventList<Signature> m_Functor;
};


template <typename Signature>
class CEventImplSafe{
    // TODO: 线程安全的事件管理器

};


// 事件管理器
template <typename Signature, typename Implementation=CEventImpl<Signature>>
class CEvent: public IEvent<Signature> {
public:
    CEvent():impl(new Implementation){

    }

    ~CEvent(){

    }

    CEventListener Connect(Signature obj){
        unsigned int key = _Connect(obj);
        if (EVENT_KEY_INVALID == key){
            return CEventListener(EVENT_KEY_INVALID, std::weak_ptr<IEvent>());
        }

        return CEventListener(key, shared_from_this());
    }

    bool DisConnect(Signature obj){
       return _DisConnect(obj);
    }

    bool DisConnect(unsigned int key){
        return _DisConnect(key);
    }

    void DisConnectAll(){
        impl->DisConnectAll();
    }

    void operator+=(Signature obj){
        _Connect(obj);
    }

    void operator-=(Signature obj){
        _Disconnect(obj);
    }

    void operator()(){
        (*impl)();
    }

    template <typename p1> 
    void operator()(p1 arg1){
        (*impl)(arg1);
    }

    template <typename p1, typename p2>
        void operator()(p1 arg1, p2 arg2){
            (*impl)(arg1, arg2);
        }

    template <typename p1, typename p2, typename p3>
        void operator()(p1 arg1, p2 arg2, p3 arg3){
            (*impl)(arg1, arg2, arg3);
        }

    template <typename p1, typename p2, typename p3, typename p4>
        void operator()(p1 arg1, p2 arg2, p3 arg3, p4 arg4){
            (*impl)(arg1, arg2, arg3, arg4);
        }

    template <typename p1, typename p2, typename p3, typename p4, typename p5>
        void operator()(p1 arg1, p2 arg2, p3 arg3, p4 arg4, p5 arg5){
            (*impl)(arg1, arg2, arg3, arg4, arg5);
        }

private:
    unsigned int _Connect(const Signature& obj){
        return impl->Connect(obj);
    }

    bool _DisConnect(const Signature& obj){
       return impl->DisConnect(obj);
    }

    bool _DisConnect(unsigned int key){
        return impl->DisConnect(key);
    }
private:
    std::shared_ptr<Implementation> impl;
};

#endif // !_EVENTMANAGER_H_

