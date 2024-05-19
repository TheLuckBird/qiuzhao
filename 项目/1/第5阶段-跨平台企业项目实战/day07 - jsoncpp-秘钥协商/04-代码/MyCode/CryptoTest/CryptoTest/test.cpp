#include <iostream>
#include "Hash.h"
#include <string>
#include "RsaCrypto.h"
#include "AesCrypto.h"
using namespace std;


void hashTest()
{
	Hash md5(HashType::T_MD5);
	md5.addData("hello");
	md5.addData(", ");
	md5.addData("world");
	string rs = md5.result();
	cout << "md5: " << rs << endl;

	Hash sha1(HashType::T_SHA1);
	sha1.addData("hello, world");
	rs = sha1.result();
	cout << "sha1: " << rs << endl;

	Hash sha224(HashType::T_SHA224);
	sha224.addData("hello, world");
	rs = sha224.result();
	cout << "sha224: " << rs << endl;

	Hash sha256(HashType::T_SHA256);
	sha256.addData("hello, world");
	rs = sha256.result();
	cout << "sha256: " << rs << endl;

	Hash sha384(HashType::T_SHA384);
	sha384.addData("hello, world");
	rs = sha384.result();
	cout << "sha384: " << rs << endl;

	Hash sha512(HashType::T_SHA512);
	sha512.addData("hello, world");
	rs = sha512.result();
	cout << "sha512: " << rs << endl;
}

int main()
{
	string text = "注意上面A的构造函数，在参数列表后和初始化列表前增加了try关键字，然后构造函数就被分割为了两部分，前面是初始化，后面是初始化时的错误处理。需要指出的是，catch块里面捕获到的异常不能被忽略，即catch块中必须有一个throw语句重新抛出异常，如果没有，则默认会将原来捕获到的异常重新抛出，这和一般的行为是不同的。例如下面代码运行可以发现A会将捕获到的异常原封不动抛出";
	string key = "12345678abcdefgh";
	try {
		AesCrypto aes(key);
		cout << "源数据 :" << text << endl;
		string ret = aes.aesCBCEncrypt(text);
		ret = aes.aesCBCDecrypt(ret);
		cout << "解密数据: " << ret << endl;
	}
	catch(exception e)
	{
		cout << "exception: " << e.what() << endl;
	}

#if 1
	hashTest();
	Cryptographic crypto;
	crypto.generateRsakey(2048);

	string str = "让编程改变世界 - good good study, day day up!!!";
	cout << "原始数据: " << str << endl;
	str = crypto.rsaPubKeyEncrypt(str);
	cout << "加密数据: " << str << endl;
	str = crypto.rsaPriKeyDecrypt(str);
	cout << "解密数据: " << str << endl;

	string sign = crypto.rsaSign(str);
	bool bl = crypto.rsaVerify(str, sign);
	cout << "verify: " << bl << endl;
#endif
	return 0;
}