#ifndef _SINGLE_H_
#define _SINGLE_H_

template <typename T>
class Single{
public:
	Single() = default;
		
private:
	Single(const T&) = delete;
	T& operator=(const T&) = delete;

public:
	static T* getInstance(){
		static T sIntace;
		return &sIntace;
	};
};

#endif // !_SINGLE_H_
