#include "addressbook.pb.h"
#include <iostream>
using namespace std;

/*
//C数组的序列化和序列化API
//在/usr/local/include/google/目录下，查找包含"SerializeToArray"所有的文件，同时打印所在行
//sudo grep "SerializeToArray" -r /usr/local/include/google/ -n

	bool SerializeToArray(void* data, int size) const; //序列化
	bool ParseFromArray(const void* data, int size);   //反序列化
*/

char buf[1024];
int len;

void set_person()
{
	Person obj;
	obj.set_name("mike");
	obj.set_id(1);
	//obj.set_email("xxx@qq.com");
	*obj.mutable_email() = "xxx@qq.com";
	
	//长度
	len = obj.ByteSize(); //获取长度
	cout << "len = " << len << endl;
	
	//序列化，obj成员保存在buf中
	obj.SerializeToArray(buf, len);
}

void get_person()
{
	Person obj;
	obj.ParseFromArray(buf, len); //反序列化，buf的内容设置给obj的成员
	
	cout << "name = " << obj.name() << endl;
	cout << "id = " << obj.id() << endl;
	cout << "email = " << obj.email() << endl;
}

int main()
{
	// Verify that the version of the library that we linked against is
	// compatible with the version of the headers we compiled against.
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	
	set_person(); //序列化
	get_person(); //反序列化
	
	// Optional:  Delete all global objects allocated by libprotobuf.
	google::protobuf::ShutdownProtobufLibrary();
	
	return 0;
}
