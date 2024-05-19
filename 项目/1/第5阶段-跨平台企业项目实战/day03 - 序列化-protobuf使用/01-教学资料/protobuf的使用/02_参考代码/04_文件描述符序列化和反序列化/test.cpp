#include "addressbook.pb.h"
#include <iostream>
using namespace std;

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
 
//bool SerializeToFileDescriptor(int file_descriptor) const;  
//bool ParseFromFileDescriptor(int file_descriptor); 

void set_person()
{
	Person obj;
	obj.set_name("mike");
	obj.set_id(1);
	obj.set_email("xxx@qq.com");
	//*obj.mutable_email() = "xxx@qq.com";
	
	//O_CREAT: 新建文件， O_TRUNC：清空文件，O_RDWR：读写
	int fd = open("./pb.xxx", O_CREAT|O_TRUNC|O_RDWR, 0644);  
    if(fd <= 0)
	{  
        perror("open");  
        exit(0); 
    }     
	
	obj.SerializeToFileDescriptor(fd);	//序列化，obj成员的内容写入fd所关联的文件中
	
	close(fd); //关闭文件
}

void get_person()
{
	int fd = open("./pb.xxx", O_RDONLY); //O_RDONLY： 只读方式
    if(fd <= 0)
	{  
        perror("open");  
        exit(0);  
    }  
	
	Person obj;
	obj.ParseFromFileDescriptor(fd); //反序列化, fd文件内容设置给obj的成员
	close(fd); //关闭文件
	
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
