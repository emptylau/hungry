#ifndef _ENTRY_H_
#define _ENTRY_H_

template <typename T>
class Entry{

public:
	Entry():m_id(T()){
	}

	explicit Entry(const T& id)
		:m_id(id){
	} 

	Entry(const Entry& entry){
		if (this != &entry){
			this->m_id = entry.m_id;
		}
	}

	bool operator<(const Entry& other) const {
		return m_id < other.m_id;
	}

	bool operator<(Entry& other){
		return m_id < other.m_id;
	}

public:
	const T& get_id(void){
		return m_id;
	};

	const T& get_id(void) const {
		return m_id;
	}

private:
	T m_id;
};


#endif
