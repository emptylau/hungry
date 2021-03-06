#ifndef _EVENT_H_
#define _EVENT_H_

#include <memory>
#include <functional>

typedef unsigned int EventKey;
const EventKey EVENT_KEY_INVALID=0x0;
const EventKey EVENT_MAX_KEY = 0xFFFFFFFF;

template <typename Signature> class CEventList;

class CEventListener {
public:
    CEventListener(EventKey key, IEvent event)
        :m_key(key), m_pEvent(event) {

    }

    bool DisConnect(){
        if (!m_pEvent && EVENT_KEY_INVALID != key) 
            return m_pEvent.DisConnect(key);
        return false;
    }

private:
    EventKey m_key;
    std::weak_ptr<IEvent> m_pEvent;
};

//事件
template <typename Signature>
struct CEventBase {
    CEventBase<Signature>* prev;
    CEventBase<Signature>* next;
    EventKey key;
    std::function<Signature> obj;

    CEventBase(){
        prev = next = NULL;
        key = EVENT_KEY_INVALID;
    }
};

template <typename Signature>
class CEventList {
public:
    CEventList()
        :m_key_next(0)
         ,m_nCount(0) {

    }

    ~CEventList(){
        CEventBase<Signature>* temp = NULL;
        auto iter = m_pListHead;
        while (NULL != iter){
            temp = iter;
            iter = iter->next;
            delete temp;
            temp = NULL;
        }
        m_pListHead = NULL;
    }


    EventKey Add(Signature obj){
        
        auto iter = m_pListHead;
        while (NULL != iter){
            if (obj == iter->obj){
                return iter->key;
            }

            iter = iter->next;
        }

        CEventBase<Signature>* base = new CEventBase<Signature>;
        if (NULL == base){
            return EVENT_KEY_INVALID;
        }

        base->key = getNextKey();
        base->obj = obj;

        base->next = m_pListHead;
        if (NULL != m_pListHead){
            m_pListHead->prev = base;
        } 
        m_pListHead = base;

        ++m_nCount;
    }

    bool Remove(Signature obj){
        auto iter = find(obj);
        return Remove(iter);
    }

    bool Remove(EventKey key){
        auto iter = find(key);
        return Remove(iter);
    }

    unsigned Count(){
       return m_nCount; 
    }

    CEventBase<Signature>* getHead(){
        return m_pListHead;
    }

private:
    EventKey getNextKey(){
        if (EVENT_MAX_KEY == m_key_next){
            m_key_next = 0;
        }

        return ++m_key_next;
    }

    CEventBase<Signature>* find(EventKey key){
        auto iter = m_pListHead;
        while (NULL != iter){
            if (key == iter->key){
                return iter;
            }
            iter = iter->next;
        }

        return NULL;
    }

    CEventBase<Signature>* find(Signature obj){
        auto iter = m_pListHead;
        while (NULL != iter){
            if (obj == iter->obj){
                return iter;
            }
            iter = iter->next;
        }

        return NULL;
    }

    bool Remove(CEventBase<Signature>* pBase){

        if (NULL != pBase){
            if (pBase == m_pListHead){
                m_pListHead = pBase ->next;
                m_pListHead->prev = NULL;

                delete pBase;
                pBase = NULL;
            } else {
                auto temp = pBase;
                if (NULL != pBase->prev){
                    pBase->prev->next = pBase->next;
                }
                if (NULL != pBase->next){
                    pBase->next->prev = pBase->prev;
                }

                delete temp;
                temp = NULL;
            }

            --m_nCount;
        }

        return true;
    }


private:
    CEventBase<Signature>* m_pListHead;

    EventKey m_key_next;
    unsigned int m_nCount;
};

class IEvent: public enable_shared_from_this<IEvent>{
public:
   virtual CEventListener Connect(const Signature& ) = 0;
   virtual void DisConnect(EventKey key) = 0; 

};

#endif //!_EVENT_H_
