#include <iostream>
#include <string.h>
// sha系列 哈希算法都包含该头文件
#include <openssl/sha.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>	// 将秘钥写文件的时候
#include <string>
#include <openssl/aes.h>
extern "C"
{
#include <openssl/applink.c> // 编译的时候将applinc.c包含进去参与编译
};

using namespace std;

void sha1Test()
{
	// 1. 初始化
	SHA_CTX ctx;
	SHA1_Init(&ctx);
	// 2. 添加数据
	SHA1_Update(&ctx, "hello", strlen("hello"));
	SHA1_Update(&ctx, ", world", strlen(", world"));
	// 3. 哈希计算
	unsigned char* md = new unsigned char[SHA_DIGEST_LENGTH];
	char* res = new char[SHA_DIGEST_LENGTH*2 + 1];
	SHA1_Final(md, &ctx);
	// 4. 格式转换
	for (int i = 0; i < SHA_DIGEST_LENGTH; ++i)
	{
		sprintf(&res[i * 2], "%02x", md[i]);
	}
	cout << "sha1: " << res << endl;
}

// 生成rsa密钥对
void generateRsaKey()
{
	// 1. 创建rsa变量
	RSA* rsa = RSA_new();
	// 1.5 创建bignum对象, 并初始化
	BIGNUM* e = BN_new();
	BN_set_word(e, 12345);
	// 2. 生成密钥对 -> 密钥对在内存中
	RSA_generate_key_ex(rsa, 1024, e, NULL);
	// 3. 将密钥对写入到磁盘
#if 1
	// 公钥
	RSA* pubKey = RSAPublicKey_dup(rsa);
	// 私钥
	RSA* priKey = RSAPrivateKey_dup(rsa);
#endif
#if 0
	FILE* fp = fopen("public.pem", "w");
	PEM_write_RSAPublicKey(fp, rsa);
	fclose(fp);
	// 写私钥
	fp = fopen("private.pem", "w");
	PEM_write_RSAPrivateKey(fp, rsa, NULL, NULL, 0, NULL, NULL);
	fclose(fp);
#else
	BIO* bio = BIO_new_file("public-1.pem", "w");
	PEM_write_bio_RSAPublicKey(bio, rsa);
	// 释放资源
	BIO_free(bio);
	bio = BIO_new_file("private-1.pem", "w");
	PEM_write_bio_RSAPrivateKey(bio, rsa, NULL, NULL, 0, NULL, NULL);
	BIO_free(bio);
#endif
}

// 公钥加密
string encryptPublicKey()
{
	// 1. 准备要加密数据
	string text = "让编程改变世界...";
	// 2. 准备秘钥 -> 公钥
	// 从磁盘文件读秘钥
	// 使用bio的方式
	BIO* bio = BIO_new_file("public-1.pem", "r");
	RSA* pubKey = RSA_new();
	if (PEM_read_bio_RSAPublicKey(bio, &pubKey, NULL, NULL) == NULL)
	{
		cout << "读公钥失败了..." << endl;
		return string();
	}
	BIO_free(bio);
	// 3. 加密 -> 密文
	// 数据被加密之后, 长度和秘钥长度相同
	// 通过函数计算秘钥长度
	int keyLen = RSA_size(pubKey);
	char *buf = new char[keyLen];
	// 返回值就是密文长度
	int len = RSA_public_encrypt(text.size(), (const unsigned char*)text.data(), 
		(unsigned char*)buf, pubKey, RSA_PKCS1_PADDING);
	// 4. 将密文返回
	cout << "加密之后的数据: " << buf << endl;
	cout << "加密之后的数据长度: " << len << endl;
	return string(buf, len);
}

// 私钥解密
string decryptPrivateKey(string str)
{
	// 1. 准备秘钥 ->私钥
	// 从磁盘文件读秘钥
	// 使用bio的方式
	BIO* bio = BIO_new_file("private-1.pem", "r");
	RSA* priKey = RSA_new();
	if (PEM_read_bio_RSAPrivateKey(bio, &priKey, NULL, NULL) == NULL)
	{
		cout << "读私钥失败..." << endl;
		return string();
	}
	BIO_free(bio);
	// 解密 -> 明文
	// 数据被加密之后, 长度和秘钥长度相同
	// 通过函数计算秘钥长度
	int keyLen = RSA_size(priKey);
	char *buf = new char[keyLen];
	// 返回值是解密之后的数据长度 == 原始数据长度
	int len = RSA_private_decrypt(str.size(), (const unsigned char*)str.data(),
		(unsigned char*)buf, priKey, RSA_PKCS1_PADDING);
	// 4. 将明文返回
	cout << "buf: " << buf << endl;
	return string(buf, len);
}

// 签名和验证签名
void rsaSigAndVerfiy()
{
	// 1. 签名数据
	string text = "让编程改变世界...";
	// 2. 秘钥
	RSA* pubKey = RSA_new();
	RSA* priKey = RSA_new();
	BIO* pubBio = BIO_new_file("public.pem", "r");
	PEM_read_bio_RSAPublicKey(pubBio, &pubKey, NULL, NULL);
	BIO_free(pubBio);
	BIO* prilBio = BIO_new_file("private.pem", "r");
	PEM_read_bio_RSAPrivateKey(prilBio, &priKey, NULL, NULL);
	BIO_free(prilBio);
	// 3. 签名
	int len = RSA_size(priKey);
	unsigned int outLen = 0;
	unsigned char* out = new unsigned char[len];
	RSA_sign(NID_sha1, (const unsigned char*)text.data(), text.size(), 
		out, &outLen, priKey);
	// 要给到用户的数据
	string sigbuf((char*)out, outLen);

	// 4. 验证签名
	int ret = RSA_verify(NID_sha1, (const unsigned char*)text.data(), text.size(),
		(const unsigned char*)sigbuf.data(), sigbuf.size(), pubKey);
	cout << "ret : " << ret << endl;
}

// 测试对称加密
void aesCBCCrypto()
{
	// 1. 准备数据
	const char* pt = "AES是一套对称密钥的密码术，目前已广泛使用，用于替代已经不够安全的DES算法。所谓对称密钥，就是说加密和解密用的是同一个密钥，消息的发送方和接收方在消息传递前需要享有这个密钥。和非对称密钥体系不同，这里的密钥是双方保密的，不会让任何第三方知道。对称密钥加密法主要基于块加密，选取固定长度的密钥，去加密明文中固定长度的块，生成的密文块与明文块长度一样。显然密钥长度十分重要，块的长度也很重要。如果太短，则很容易枚举出所有的明文 - 密文映射；如果太长，性能则会急剧下降。AES中规定块长度为128 bit，而密钥长度可以选择128, 192或256 bit 。暴力破解密钥需要万亿年，这保证了AES的安全性。";
	// 2. 准备秘钥
	const char* key = "1234567887654321";
	// 3. 初始化秘钥
	AES_KEY encKey;
	AES_set_encrypt_key((const unsigned char*)key, 128, &encKey);
	// 4. 加密
	// 计算长度
	int length = 0;
	int len = strlen((char*)pt) + 1;
	if (len % 16 != 0)
	{
		length = ((len / 16) + 1) * 16;
	}
	else
	{
		length = len;
	}
	unsigned char* out = new unsigned char[length];
	unsigned char ivec[AES_BLOCK_SIZE];
	memset(ivec, 9, sizeof(ivec));
	// 密文存储在out中
	AES_cbc_encrypt((const unsigned char*)pt, out, length, &encKey, ivec, AES_ENCRYPT);

	// 5. 解密
	unsigned char* data = new unsigned char[length];
	AES_KEY deckey;
	memset(ivec, 9, sizeof(ivec));
	AES_set_decrypt_key((const unsigned char*)key, 128, &deckey);
	AES_cbc_encrypt(out, data, length, &deckey, ivec, AES_DECRYPT);
	// 6. 打印
	cout << "还原的数据: " << data << endl;

	delete[]out;
	delete[]data;
}

int main()
{
//	sha1Test();
//	generateRsaKey();

	//string str = encryptPublicKey();
	//string str1 = decryptPrivateKey(str);
	//cout << "解密数据: " << str1 << endl;
	//	rsaSigAndVerfiy();
	aesCBCCrypto();

	return 0;
}