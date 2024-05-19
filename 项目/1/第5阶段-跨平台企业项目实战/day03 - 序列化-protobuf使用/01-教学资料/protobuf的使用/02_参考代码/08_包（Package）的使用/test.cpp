#include "addressbook.pb.h"
#include <iostream>
#include <fstream>
using namespace std;


void set_addressbook()
{
	tutorial::AddressBook obj;
	
	tutorial::Person *p1 = obj.add_people(); //新增加一个Person
	p1->set_name("mike");
	p1->set_id(1);
	p1->set_email("mike@qq.com");
	
	tutorial::Person::PhoneNumber *phone1 = p1->add_phones(); //增加一个phone
	phone1->set_number("110");
	phone1->set_type(tutorial::Person::MOBILE);
	
	tutorial::Person::PhoneNumber *phone2 = p1->add_phones(); //增加一个phone
	phone2->set_number("120");
	phone2->set_type(tutorial::Person::HOME);
	
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
	tutorial::AddressBook obj;
	fstream input("./pb.xxx", ios::in|ios::binary);  
    obj.ParseFromIstream(&input);  //反序列化
	input.close(); //关闭文件
	
	for (int i = 0; i < obj.people_size(); i++) 
	{
		const tutorial::Person& person = obj.people(i);//取第i个people
		cout << "第" << i+1 << "个信息\n";
		cout << "name = " << person.name() << endl;
		cout << "id = " << person.id() << endl;
		cout << "email = " << person.email() << endl;
		
		for (int j = 0; j < person.phones_size(); j++) 
		{
			const tutorial::Person::PhoneNumber& phone_number = person.phones(j);

			switch (phone_number.type()) 
			{
			case tutorial::Person::MOBILE:
				cout << "  Mobile phone #: ";
				break;
			case tutorial::Person::HOME:
				cout << "  Home phone #: ";
				break;
			case tutorial::Person::WORK:
				cout << "  Work phone #: ";
				break;
			}
		  
			cout << phone_number.number() << endl;
		}
		cout << endl;
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
