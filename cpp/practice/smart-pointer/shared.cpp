#include <iostream>
#include <memory>
#include <string>

// shared_ptr 特性测试
int main(int argc, char* argv[]){

	// 引用测试
	std::shared_ptr<int> pNum(new int);
	std::cout << "pNum: refs " << pNum.use_count() << " "
		<< "unique " << pNum.unique() 
		<< std::endl;

	std::shared_ptr<int> p2 = pNum;
	std::cout << "pNum: refs " << pNum.use_count() << " "
		<< "unique " << pNum.unique() 
		<< std::endl;

	// 空值测试
	std::shared_ptr<std::string> pstr;
	std::shared_ptr<std::string> pstr1(nullptr);
	std::cout << "pstr use_count " << pstr.use_count() << " unique " << pstr.unique() << std::endl;
	std::cout << "pstr1 use_count " << pstr1.use_count() << " unique " << pstr1.unique() << std::endl;

	// 唯一性测试
	std::shared_ptr<float> fvalue(new float(10));
	std::cout << "fvalue unique " << fvalue.unique() << " value:" << *fvalue << std::endl;
	auto fcpy = fvalue;
	std::cout << "fvalue unique " << fvalue.unique() << " value:" << *fvalue << std::endl;

	// 移动语义测试    注意：move 后 fvalue 为 空了
	auto fcpy2 = std::move(fvalue);
	if (!fvalue){
		std::cout << "fvalue is nullptr -> because useed std::move" << std::endl;
	}
	else{
		std::cout << "fvalue unique " << fvalue.unique() << " value:" << *fvalue << std::endl;
	}

	struct C {
		int* data;	
	};

	// aliasing  构造测试
	// 管理shared_ptr 对象的部分数据，达到共同管理的目的
	std::shared_ptr<C> obj(new C);
	(*obj).data = new int;
	std::shared_ptr<int> pobj(obj, obj->data);
	*pobj = 10;
	
	auto pobj1 = pobj;
	auto obj1 = obj;

	std::cout << "pobj: " << *pobj << std::endl;
	std::cout << "use count: obj " << obj.use_count() 
		<< " obj1 " << obj1.use_count()
		<< " pobj " << pobj.use_count()
		<< " pobj1 " << pobj1.use_count() 
		<< std::endl;

	return 0;
}


