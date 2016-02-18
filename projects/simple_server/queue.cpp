#include <iostream>
#include <queue>
#include <cstring>

const int STRING_INIT_SIZE = 255;
class string{

	friend std::iostream& operator<<(std::iostream&, string&);
public:
	string(){};
	string(const char* str){
		memset(data_, 0, sizeof(data_));
		memcpy(data_, str, strlen(str));
	}

	string(string& str){
		memset(data_, 0, sizeof(data_));
		std::string data = str.data();
		strcpy(data_, data.c_str());
	}

	~string(){};

	const char* data(){
		return data_;
	}

private:
	char data_[STRING_INIT_SIZE];

};

std::iostream& operator<<(std::iostream& ios, string& str){
//	ios << str.data();
	return ios;
}

int main(int argc, char* argv[]){

	std::queue<string> process_queue;

	//process_queue.push("abc");
	//process_queue.push("456");

	string name("jchenglau");
	process_queue.push(name);
	string aliae("emptylau");
	process_queue.push(aliae);


	while(!process_queue.empty()){
		auto temp = process_queue.front();
//std::cout << process_queue.front() << std::endl;
		process_queue.pop();
	}

	return 0;
}
