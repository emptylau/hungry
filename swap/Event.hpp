#ifndef _EVENT_HPP_
#define _EVENT_HPP_

#include <mutex>
#include <functional>
#include <memory>
#include <map>

#define MAX_EVENT_ALLOC_ID 0xFFFFFFFF

template <class Signature>
class CEventItemMap{

public:
	struct MapItem{
		unsigned int key;
		MapItem* next;
		std::function<Signature> object;

		MapItem(unsigned int key_, std::function<Signature> object_) { 
            key = key_; 
            object = object_; 
            next = NULL;
        }
	};

	CEventItemMap(){
		m_pHead = NULL;
		m_nNext = NULL;
		m_nSize = 0; 
	}

	~CEventItemMap(){
		clear();
	}

	unsigned int size() {
		return m_nSize;
	}

	std::function<Signature>* find(unsigned int key){
		MapItem* item = m_pHead;
		while(item){
			if(item->key == key){
				return item->object;
			}
			item = item->next;
		}
		return 0;
	}

	template<class Function>
	unsigned int add(const Function& obj){
		
		if(m_nNext == MAX_EVENT_ALLOC_ID){
			m_nNext = 0;
		}
		unsigned int id = ++m_nNext;
		MapItem* item = new MapItem(id, obj);
		item->next = m_pHead;
		m_pHead = item;
		++m_nSize;
		return id;
	}

	bool remove(unsigned int key){
		MapItem* item = m_pHead;
		MapItem* pre_item = 0;
		while(item){
			if(item->key == key){
				if(pre_item){
					pre_item->next = item->next;					
				}
				else{
					m_pHead = item->next;
				}
				delete item;
				--m_nSize;
				return true;
			}
			pre_item = item;
			item = item->next;
		}
		return false;
	}

#if 0
	template<class Function>
	bool remove(const Function& object){
		MapItem* item = m_pHead;
		MapItem* pre_item = 0;
		while(item){
			if(item->object == object){
				if(pre_item){
					pre_item->next = item->next;					
				}
				else{
					m_pHead = item->next;
				}
				delete item;
				--m_nSize;
				return true;
			}
			pre_item = item;
			item = item->next;
		}
		return false;
	}
#endif //! c++11 不支持

	void clear(){
		MapItem* item = m_pHead;
		while(item){
			MapItem* nextitem = item->next;
			delete item;
			item = nextitem;
		}
		m_pHead = 0;
		m_nSize = 0;
		m_nNext = 0;
	}
	
	std::map<unsigned int, std::function<Signature> > get_map(void){
		std::map<unsigned int, std::function<Signature> > map;
		MapItem* item = m_pHead;
		while(item){
			map[item->key] = item->object;
			item = item->next;
		}
		return map;
	}

private:
	MapItem*  m_pHead;
	unsigned int m_nSize;
	unsigned int m_nNext;
};

class IEvent: public std::enable_shared_from_this<IEvent>
{
public:
	virtual void Disconnect(unsigned int id) = 0;
};

class CEventListener
{
public:
	CEventListener(void) {
		m_nId = 0;
	}
	CEventListener(unsigned int id, std::weak_ptr<IEvent> event) {
		m_nId = id;
		m_pEvent = event;
	}
	~CEventListener(void) {}

	// 拷贝构造;
	CEventListener(const CEventListener& event_listener) {
		m_nId = event_listener.m_nId;
		m_pEvent = event_listener.m_pEvent;
	}

	// 赋值操作;
	void operator=(const CEventListener& event_listener) {
		m_nId = event_listener.m_nId;
		m_pEvent = event_listener.m_pEvent;
	}

	// 注销监听;
	void Disconnect(void) {

		// 无效句柄;
		if(m_nId == 0) {
			return;
		}

		// 获取事件并进行注销;
		std::shared_ptr<IEvent> event = m_pEvent.lock();
		if(event) {
			event->Disconnect(m_nId);
		}
		m_pEvent.reset();
	}

private:
	unsigned int m_nId;
	std::weak_ptr<IEvent> m_pEvent;
};

class CDummyMutex
{
public:
	void lock(void) {}
	bool try_lock(void) { return true; }
	void unlock(void) {}
};

template<typename Signature, class Mutex = CDummyMutex>
class CEventImpl : public IEvent
{
public:
	CEventImpl(void) {
		// m_nNext = 0;
	}
	~CEventImpl(void) {
	}

	// 监听事件;
	template<class Function> 
	CEventListener Connect(const Function& callback) { 

		unsigned int id = _Connect(callback);
		if(id != 0) {
			return CEventListener(id, std::weak_ptr<IEvent>(shared_from_this()));
		}
		return CEventListener(); 
	}

	// 撤销监听;
	void Disconnect(unsigned int id) {

		_Disconnect(id);
	}

	// 撤销监听;
	template<class Function>
	void Disconnect(const Function& callback) {

		_Disconnect(callback);
	}

	// 撤销所有监听;
	void DisconnectAll(void) {

		_DisconnectAll();
	}

	// 运行事件;
	void operator()(void) { 

		std::map<unsigned int, std::function<Signature> > function_map = _GetFunctionMap();

		// 遍历运行事件;
		auto iter = function_map.begin();
		while(iter != function_map.end()) {

			std::function<Signature> callback = iter->second;
			if(callback) {
				callback();
			}
			++iter;
		}
	}

	template<class T1>
	void operator()(T1 t1) { 

		std::map<unsigned int, std::function<Signature> > function_map = _GetFunctionMap();

		// 遍历运行事件;
		auto iter = function_map.begin();
		while(iter != function_map.end()) {

			std::function<Signature> callback = iter->second;
			if(callback) {
				callback(t1);
			}
			++iter;
		}
	}

	template<class T1, class T2>
	void operator()(T1 t1, T2 t2) { 

		std::map<unsigned int, std::function<Signature> > function_map = _GetFunctionMap();

		// 遍历运行事件;
		auto iter = function_map.begin();
		while(iter != function_map.end()) {

			std::function<Signature> callback = iter->second;
			if(callback) {
				callback(t1, t2);
			}
			++iter;
		}
	}

	template<class T1, class T2, class T3>
	void operator()(T1 t1, T2 t2, T3 t3) { 

		std::map<unsigned int, std::function<Signature> > function_map = _GetFunctionMap();

		// 遍历运行事件;
		auto iter = function_map.begin();
		while(iter != function_map.end()) {

			std::function<Signature> callback = iter->second;
			if(callback) {
				callback(t1, t2, t3);
			}
			++iter;
		}
	}

	template<class T1, class T2, class T3, class T4>
	void operator()(T1 t1, T2 t2, T3 t3, T4 t4) { 

		std::map<unsigned int, std::function<Signature> > function_map = _GetFunctionMap();

		// 遍历运行事件;
		auto iter = function_map.begin();
		while(iter != function_map.end()) {

			std::function<Signature> callback = iter->second;
			if(callback) {
				callback(t1, t2, t3, t4);
			}
			++iter;
		}
	}

	template<class T1, class T2, class T3, class T4, class T5>
	void operator()(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5) { 

		std::map<unsigned int, std::function<Signature> > function_map = _GetFunctionMap();

		// 遍历运行事件;
		auto iter = function_map.begin();
		while(iter != function_map.end()) {

			std::function<Signature> callback = iter->second;
			if(callback) {
				callback(t1, t2, t3, t4, t5);
			}
			++iter;
		}
	}

	template<class T1, class T2, class T3, class T4, class T5, class T6>
	void operator()(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6) { 

		std::map<unsigned int, std::function<Signature> > function_map = _GetFunctionMap();

		// 遍历运行事件;
		auto iter = function_map.begin();
		while(iter != function_map.end()) {

			std::function<Signature> callback = iter->second;
			if(callback) {
				callback(t1, t2, t3, t4, t5, t6);
			}
			++iter;
		}
	}

	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
	void operator()(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6, T7 t7) { 

		std::map<unsigned int, std::function<Signature> > function_map = _GetFunctionMap();

		// 遍历运行事件;
		auto iter = function_map.begin();
		while(iter != function_map.end()) {

			std::function<Signature> callback = iter->second;
			if(callback) {
				callback(t1, t2, t3, t4, t5, t6, t7);
			}
			++iter;
		}
	}

	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
	void operator()(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6, T7 t7, T8 t8) { 

		std::map<unsigned int, std::function<Signature> > function_map = _GetFunctionMap();

		// 遍历运行事件;
		auto iter = function_map.begin();
		while(iter != function_map.end()) {

			std::function<Signature> callback = iter->second;
			if(callback) {
				callback(t1, t2, t3, t4, t5, t6, t7, t8);
			}
			++iter;
		}
	}

	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9>
	void operator()(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6, T7 t7, T8 t8, T9 t9) { 

		std::map<unsigned int, std::function<Signature> > function_map = _GetFunctionMap();

		// 遍历运行事件;
		auto iter = function_map.begin();
		while(iter != function_map.end()) {

			std::function<Signature> callback = iter->second;
			if(callback) {
				callback(t1, t2, t3, t4, t5, t6, t7, t8, t9);
			}
			++iter;
		}
	}

	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10>
	void operator()(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6, T7 t7, T8 t8, T9 t9, T10 t10) { 

		std::map<unsigned int, std::function<Signature> > function_map = _GetFunctionMap();

		auto iter = function_map.begin();
		while(iter != function_map.end()) {

			std::function<Signature> callback = iter->second;
			if(callback) {
				callback(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10);
			}
			++iter;
		}
	}

	int NumListeners(){
		std::unique_lock<Mutex> lock(m_mutex);
		return m_functor_map.size();
	}

protected:
	template<class Function>
	unsigned int _Connect(const Function& callback) {

		std::unique_lock<Mutex> lock(m_mutex);
		return m_functor_map.add(callback);
	}

	void _Disconnect(unsigned int id) {

		std::unique_lock<Mutex> lock(m_mutex);
		m_functor_map.remove(id);
	}

	template<class Function>
	void _Disconnect(const Function& callback) {

		std::unique_lock<Mutex> lock(m_mutex);
		m_functor_map.remove(callback);
	}

	void _DisconnectAll(void) {

		std::unique_lock<Mutex> lock(m_mutex);
		m_functor_map.clear();
	}

	std::map<unsigned int, std::function<Signature> > _GetFunctionMap(void) {

		std::unique_lock<Mutex> lock(m_mutex);

		return m_functor_map.get_map();
	}
	Mutex m_mutex; // 数据锁;
	CEventItemMap< Signature > m_functor_map;
};

template<typename Signature, class EventImpl>
class CEventBase
{
public:
	CEventBase(void) : m_pImpl(new EventImpl) {}
	~CEventBase(void) {}

	template<class Function>
	CEventListener Connect(const Function& callback) { 
		return m_pImpl->Connect(callback);
	}

	void Disconnect(unsigned int id) {
		m_pImpl->Disconnect(id);
	}

	template<class Function>
	void Disconnect(Function callback) {
		m_pImpl->Disconnect(callback);
	}

	void DisconnectAll(void) {
		m_pImpl->DisconnectAll();
	}

	int NumListeners(){
		return m_pImpl->NumListeners();
	}

	template<class Function>
	void operator+=(const Function& callback) {
		Connect(callback);
	}

	template<class Function>
	void operator-=(const Function& callback) {
		Disconnect(callback);
	}

	void operator()(void) { 
		(*m_pImpl)();
	}

	template<class T1>
	void operator()(T1 t1) { 
		(*m_pImpl)(t1);
	}

	template<class T1, class T2>
	void operator()(T1 t1, T2 t2) { 
		(*m_pImpl)(t1, t2);
	}

	template<class T1, class T2, class T3>
	void operator()(T1 t1, T2 t2, T3 t3) { 
		(*m_pImpl)(t1, t2, t3);
	}

	template<class T1, class T2, class T3, class T4>
	void operator()(T1 t1, T2 t2, T3 t3, T4 t4) { 
		(*m_pImpl)(t1, t2, t3, t4);
	}

	template<class T1, class T2, class T3, class T4, class T5>
	void operator()(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5) { 
		(*m_pImpl)(t1, t2, t3, t4, t5);
	}

protected:
	std::shared_ptr<EventImpl> m_pImpl;
};

// 非线程安全
template<typename Signature>
class CEvent : public CEventBase<Signature, CEventImpl<Signature> >
{
public:
};


// 线程安全
template<typename Signature>
class CEventS : public CEventBase<Signature, CEventImpl<Signature, std::mutex> >
{
public:

};

#endif // !_EVENT_HPP_

