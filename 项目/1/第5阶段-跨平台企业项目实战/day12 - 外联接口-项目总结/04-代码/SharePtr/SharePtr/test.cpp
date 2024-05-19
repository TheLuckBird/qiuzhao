#include <iostream>
#include <memory>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A 对象被构造 -> No arg..." << endl;
	}
	A(string str)
	{
		cout << "A 对象被构造 -> string..." << endl;
	}
	A(int a)
	{
		cout << "A 对象被构造 -> int..." << endl;
	}
	~A()
	{
		cout << "A对象被析构了..." << endl;
	}
};

void initPtr()
{
	// 智能指针初始化 -> 方式1
	// 使用构造函数 -> 管理int;类型的地址
	shared_ptr<int> ptr(new int(100));
	shared_ptr<A> ptr1(new A(10));
	cout << ptr.use_count() << endl;

	// 第二种初始化方式
	// 通过 make_shared 创建一块内存(对我们隐藏的)
	// 将创建得到的内存交给智能指针去管理
	shared_ptr<int> ptr2 = make_shared<int>(10);
	// 如果管理的是一个类对象, 小括号中写构造对象需要的参数
	shared_ptr<A> ptr3 = make_shared<A>("hello");

	// 第三种方式: 直接赋值
	shared_ptr<int> ptr4 = ptr2;
}

void testSharedPtr()
{
	shared_ptr<A> ptr1 = make_shared<A>("hello");
	cout << "A 对象应用计数:" << ptr1.use_count() << endl;
	{
		shared_ptr<A> ptr2 = ptr1;
		cout << "A 对象应用计数:" << ptr1.use_count() << endl;
	}
	cout << "A 对象应用计数:" << ptr1.use_count() << endl;
}

void sharePtrOP()
{
	shared_ptr<int> ptr(new int(2), default_delete<int>());
	// 取出智能指针管理的内存地址
	int* a = ptr.get();
	cout << "int value: " << *a << endl;
	*a = 100;
	a = ptr.get();
	cout << "int value: " << *a << endl;

	// 解除对一块内存的管理
	shared_ptr<int> ptr1(new int(6));
	shared_ptr<int> ptr2 = ptr1;

	ptr1.reset(new int(8));

	shared_ptr<A> ptr4(new A(9));
	ptr4.reset(new A("hello"));
}

void sharPtrDeleteFunc()
{
	shared_ptr<int> ptr1(new int[10], [](int *array) {
		delete[]array;
	});
	shared_ptr<A> ptr2(new A[10], [](A* a) {
		delete []a;
	});
}

void initUniquePtr()
{
	// 构造函数
	unique_ptr<int> ptr1(new int(10));
	// unique_ptr<int> ptr2 = ptr1;	// 指针是独占的, 所有不能赋值
	// 使用make_unique
	unique_ptr<int> ptr2 = make_unique<int>(10);
	unique_ptr<A> ptr3 = make_unique<A>(10);

	// move 转移所有权
	// ptr1 丧失了对int型内存的管理和所有权 -> ptr1变成了空的共享指针
	unique_ptr<int> ptr4 = move(ptr1);

	unique_ptr<char> ptr5(new char[100]);
}

int main()
{
	// sharPtrDeleteFunc();
	sharePtrOP();
	// testSharedPtr();
	return 0;
}