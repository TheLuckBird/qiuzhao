#include "addressbook.pb.h"
#include <iostream>
using namespace std;


//bool SerializeToString(string* output) const;  
//bool ParseFromString(const string& data); 

string str; //全局变量

void set_person()
{
	Person obj;
	obj.set_name("mike");
	obj.set_id(1);
	obj.set_email("xxx@qq.com");
	//*obj.mutable_email() = "xxx@qq.com";
	
	obj.SerializeToString(&str);	//序列化，obj成员的内容设置给str
}

void get_person()
{
	Person obj;
	obj.ParseFromString(str); //反序列化, str内容设置给obj的成员
	
	cout << "name = " << obj.name() << endl;
	cout << "id = " << obj.id() << endl;
	cout << "email = " << *obj.mutable_email() << endl;
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
