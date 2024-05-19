#include "addressbook.pb.h"
#include <iostream>
#include <fstream>
using namespace std;


void set_addressbook()
{
	AddressBook obj;
	
	Person *p1 = obj.add_people(); //新增加一个Person
	p1->set_name("mike");
	p1->set_id(1);
	p1->set_email("mike@qq.com");
	
	Person *p2 = obj.add_people(); //新增加一个Person
	p2->set_name("jiang");
	p2->set_id(2);
	p2->set_email("jiang@qq.com");
	
	Person *p3 = obj.add_people(); //新增加一个Person
	p3->set_name("abc");
	p3->set_id(3);
	p3->set_email("abc@qq.com");
	
	fstream output("pb.xxx",ios::out|ios::trunc|ios::binary);
	
	bool flag =  obj.SerializeToOstream(&output);//序列化
	if( !flag )
	{
      cerr << "Failed to write file." << endl;
      return;
    }
	
	output.close();//关闭文件
}

void get_addressbook()
{
	AddressBook obj;
	fstream input("./pb.xxx", ios::in|ios::binary);  
    obj.ParseFromIstream(&input);  //反序列化
	input.close(); //关闭文件
	
	for (int i = 0; i < obj.people_size(); i++) 
	{
		const Person& person = obj.people(i);//取第i个people
		cout << "第" << i+1 << "个信息\n";
		cout << "name = " << person.name() << endl;
		cout << "id = " << person.id() << endl;
		cout << "email = " << person.email() << endl << endl;
	}
}

int main()
{
	// Verify that the version of the library that we linked against is
	// compatible with the version of the headers we compiled against.
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	
	set_addressbook(); //序列化
	get_addressbook(); //反序列化
	
	// Optional:  Delete all global objects allocated by libprotobuf.
	google::protobuf::ShutdownProtobufLibrary();
	
	return 0;
}
