#include <iostream>
#include <string>
#include <map>

int main(int argc, char* argv[])
{
	typedef std::multimap<std::string, std::string>::iterator iterator;
	std::multimap<std::string, std::string> dns_container;

	dns_container.insert(std::make_pair("hello", "hello@sina.cn"));
	dns_container.insert(std::make_pair("jcheng", "jchenglau@163.com"));
	dns_container.insert(std::make_pair("jcheng", "emptylau@sina.com"));
	dns_container.insert(std::make_pair("jcheng", "jchenglau@sina.cn"));

	for (auto itr: dns_container ) {
		std::cout << itr.first << '\t' << itr.second << std::endl;
	}
	
	auto key = "jcheng";

	puts("---------------------------");
	
	std::cout <<  "count: " << dns_container.count(key) << std::endl;

	puts("---------------------------");
	std::pair<iterator, iterator> dns_serach_tmp;
	dns_serach_tmp = dns_container.equal_range(key);
	for (iterator iter = dns_serach_tmp.first; iter != dns_serach_tmp.second; ++iter){
		std::cout << key << '\t' << iter->second << std::endl;
	}

	puts("--------------------------");
	iterator iter = dns_container.find(key);
	if (iter != dns_container.end()){
		std::cout << key << '\t' << iter->second << std::endl;
	}
	
	puts("--------------------------");

	
	auto lowerbound = dns_container.lower_bound(key);
	iterator upperbound = dns_container.upper_bound(key);
	for (auto iter = lowerbound; iter != upperbound; ++iter) {
		std::cout << key << '\t' << iter->second << std::endl;
	}

	return 0;
}
