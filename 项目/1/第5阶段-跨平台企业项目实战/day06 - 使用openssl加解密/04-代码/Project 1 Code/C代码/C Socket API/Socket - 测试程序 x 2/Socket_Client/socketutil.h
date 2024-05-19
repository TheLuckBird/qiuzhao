
// socketutil.h

#ifndef _socketutil_H_
#define _socketutil_H_

#ifdef __cplusplus
extern 'C'
{
#endif

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

// ����I/OΪ������ģʽ
void activate_nonblock(int fd);

// ����I/OΪ����ģʽ
void deactivate_nonblock(int fd);

// ����ʱ��⺯��������������
int read_timeout(int fd, unsigned int wait_seconds);

// д��ʱ��⺯��, ������д����
int write_timeout(int fd, unsigned int wait_seconds);

// ����ʱ��accept
int accept_timeout(int fd, struct sockaddr_in *addr, unsigned int wait_seconds);

// �����ӳ�ʱ��connect����
int connect_timeout(int fd, struct sockaddr_in *addr, unsigned int wait_seconds);

// ÿ�δӻ������ж�ȡn���ַ�
ssize_t readn(int fd, void *buf, size_t count);

// ÿ����������д��n���ַ�
ssize_t writen(int fd, const void *buf, size_t count);

// ����ڴ滺�����е��ֽ���, ������ȡ����(�������е����ݲ������)
ssize_t recv_peek(int sockfd, void *buf, size_t len);

// ÿ�ζ�һ��
ssize_t readline(int sockfd, void *buf, size_t maxline);


#ifdef __cpluspluse
}
#endif


#endif /* _SYS_UTIL_H_ */
