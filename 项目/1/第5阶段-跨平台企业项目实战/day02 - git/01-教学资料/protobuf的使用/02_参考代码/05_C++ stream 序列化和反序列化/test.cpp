#include "addressbook.pb.h"
#include <iostream>
#include <fstream>
using namespace std;


//bool SerializeToOstream(ostream* output) const;  
//bool ParseFromIstream(istream* input);  

void set_person()
{
	Person obj;
	obj.set_name("mike");
	obj.set_id(1);
	obj.set_email("xxx@qq.com");
	//*obj.mutable_email() = "xxx@qq.com";
	
	fstream output("pb.xxx",ios::out|ios::trunc|ios::binary);
	
	bool flag =  obj.SerializeToOstream(&output);//序列化
	if( !flag )
	{
      cerr << "Failed to write file." << endl;
      return;
    }
	
	output.close();//关闭文件
}

void get_person()
{
	Person obj;
	fstream input("./pb.xxx", ios::in|ios::binary);  
    obj.ParseFromIstream(&input);  //反序列化
	input.close(); //关闭文件
	
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
