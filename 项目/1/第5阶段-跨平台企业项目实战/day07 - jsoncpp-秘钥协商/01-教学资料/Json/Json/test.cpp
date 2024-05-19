#include <json.h>
#include <iostream>
#include <fstream>
using namespace Json;	// jsoncpp的命名空间
using namespace std;

void readJson()
{
	// 1. 将磁盘文件数据读出 -> string
	ifstream ifs("test.json");
	// 2. 将string -> Value 对象中
	Reader rd;
	Value root;
	rd.parse(ifs, root);
	// 3 打印输出
	// 遍历数组
	for (int i = 0; i < root.size(); ++i)
	{
		Value sub = root[i];
		if (sub.isInt())
		{
			cout << sub.asInt() << " ";
		}
		else if (sub.isDouble())
		{
			cout << sub.asDouble() << " ";
		}
		else if (sub.isBool())
		{
			cout << sub.asBool() << " ";
		}
		else if (sub.isString())
		{
			cout << sub.asString() << " ";
		}
		else if (sub.isArray())
		{
			// 继续遍历这个子数组
			for (int j = 0; j < sub.size(); ++j)
			{
				cout << sub[j].asString() << " ";
			}
			cout << endl;
		}
		else if (sub.isObject())
		{
			// 根据对象中的key, 打印value值
			cout << sub["name"].asString() << ", "
				<< sub["age"].asInt() << " ";
		}
	}
}

int main()
{
	// 组织数据, 并写入到磁盘文件
	// [12, 19.8, true, "hello", ["a", "b", "c"], {"name":"xiaoming"}, "age":12]
	Value v;
	v.append(Value(12));
	v.append(19.8);
	v.append(true);
	v.append("hello");

	// 创建一个数组对象 Value
	Value arr;
	arr.append("a");
	arr.append("b");
	arr.append("c");

	// 创建json对象 -> Value
	Value obj;
	obj["name"] = "xiaoming";
	obj["age"] = 12;

	v.append(arr);
	v.append(obj);
	// 将得到Value对象 v 格式化 -> string -> 写磁盘
	string st = v.toStyledString();
	cout << "v style: " << st << endl;
	FastWriter fw;
	string jsonText = fw.write(v);
	cout << "jsonText: " << jsonText << endl;

	// 创建写文件的流对象
	// ofstream of;
	// of.open("test.json");
	ofstream of("test.json");
	of << st;
	of.close();

	readJson();
}