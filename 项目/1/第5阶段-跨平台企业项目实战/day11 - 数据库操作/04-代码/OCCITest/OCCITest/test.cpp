#include <iostream>
#include <occi.h>
using namespace std;
using namespace oracle::occi;

int main()
{
	// 初始化连接环境
	Environment* env = Environment::createEnvironment();
	// 根据环境对象, 创建一个连接数据库服务器的实例
	// 参数: 用户名->oracle数据库用户名, 密码, 连接串
	// 连接串(oracle服务器地址): IP:端口/实例名
	// 192.168.21.23:1521/orcl
	Connection* conn = env->createConnection("scott", "tiger", "192.168.237.166:1521/orcl");
	// 主要的业务逻辑 -> 数据库操作-> 使用sql语句
	// 创建能够操作sql的对象
	Statement* st = conn->createStatement();
	// 给st对象指定要操作的sql语句
	// 假设要查询
	string sql = "slect * from dept";
	// 知识设置, 没有查询
	st->setSQL(sql);
	// 执行sql语句
	// 返回ResultSet对象, 这个类中保存了查询到的结果
	ResultSet* result =  st->executeQuery(); 
	// 遍历结果集, 使用next()
	while (result->next())
	{
		// 将当前记录的字段值取出
		// 看数据库表的设计 -> 需要要知道每个字段对应的数据类型
		// 取值的方法: get数据类型(字段在数据表中的位置[从1开始算]);
		cout << "no: " << result->getInt(1) << ","
			<< "name: " << result->getString(2) << ","
			<< "location: " << result->getString(3) << endl;
	}
	// 关闭查询的结果集 -> 释放资源closeResult
	st->closeResultSet(result);
	// 数据库插入
	sql = "insert into dept values(33, '索隆', '和之国')";
	st->setSQL(sql);
	// 获取事务模式是否开启
	bool bl = st->getAutoCommit();
	cout << "bl: " << bl << endl;	// 这个值默认是false
	// 开启事务
	// st->setAutoCommit(true);
	int ret = st->executeUpdate();
	cout << "insert return value: " << ret << endl;
	if (ret <= 0)
	{
		// 操作失败
		// 状态回滚 -> rollback, 由数据库实例对象调用
		conn->rollback();
	}
	else
	{
		conn->commit();
	}


	// 销毁statment对象
	conn->terminateStatement(st);
	// 销毁连接对象
	env->terminateConnection(conn);
	// 释放创建的环境对象
	Environment::terminateEnvironment(env);

	return 0;
}