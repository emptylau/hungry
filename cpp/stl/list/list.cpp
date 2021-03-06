#include <ctype.h>
#include <iostream>
#include <string>
#include <list>

/*
 * list 测试
 * list支持通用的迭代器和拷贝赋值构造、大小操作、转置等方法。
 * 但是不支持find方法
 *
 * 特色: front() / back()  / pop_front() / pop_back() 
 *		insert erase() 这两个函数都是要对位置进行操作的
 *	
 *
 * 注意：pop_front 一个空的链表，会抛出异常
 */

int main(int argc, char* argv[])
{
	clock_t tick = clock();

	std::list<std::string> names_list({"jcheng", "empty", "hello"});
	names_list.push_back("push_back");

	std::list<std::string>::iterator iter = names_list.begin();
	for (; iter != names_list.end(); ++iter){
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	std::list<std::string> value_list(10, "abc");
	for (auto itr: value_list){
		std::cout << itr << " ";
	}
	std::cout << std::endl;

	int sequeue_nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};	
	std::list<int> num_list(sequeue_nums, sequeue_nums + 10);
	for (auto itr = num_list.begin(); itr != num_list.end(); ++itr){
		std::cout << *itr << " ";
	}
	std::cout << std::endl;

	std::list<char> alph_list;
	for (char ch = 'a'; ch <= 'z'; ++ch){
		alph_list.push_back(ch);
	}

	std::list<char> ralph_list(alph_list);
	ralph_list.reverse();
	auto itr = ralph_list.rbegin();
	for (; itr != ralph_list.rend(); ++itr){
		std::cout << *itr << " ";
	}
	std::cout << std::endl;

	for (auto& itr: ralph_list){
		itr = toupper(itr);
	}

	for (auto itr: ralph_list){
		std::cout << itr << " ";
	}
	std::cout << std::endl;
/*
	while(!alph_list.empty()){
		std::cout << alph_list.front() << " ";
		alph_list.pop_front();
	}
	std::cout << std::endl;
*/
	alph_list.remove('a');
	alph_list.pop_front();
	//alph_list.erase('c');
	alph_list.remove_if([](const char value){
			if (value > 'c' && value < 'h')
				return true;
			return false;
		});

	std::list<char> seq_list(alph_list.begin(), alph_list.end());
	seq_list.insert(seq_list.end(), 3, 'A');
	seq_list.insert(seq_list.end(), alph_list.begin(), alph_list.end());

	for (auto itr: seq_list){
		std::cout << itr << " ";
	}
	std::cout << std::endl;

	std::cout << "ticks: " << clock() - tick << std::endl;

	return 0;
}

