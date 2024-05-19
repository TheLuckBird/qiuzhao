create database if not exists scott character set utf8;

use scott;

create table bonus
(
  ename VARCHAR(10),
  job   VARCHAR(9),
  sal   int,
  comm  int
);

create table dept
(
  deptno int not null,
  dname  VARCHAR(14),
  loc    VARCHAR(13)
);
alter table dept
  add constraint PK_DEPT primary key (deptno);

create table emp
(
  empno    int not null,
  ename    VARCHAR(10),
  job      VARCHAR(9),
  mgr      int,
  hiredate DATE,
  sal      int,
  comm     int,
  deptno   int
)
;
alter table emp
  add constraint PK_EMP primary key (EMPNO);
alter table emp
  add constraint FK_DEPTNO foreign key (DEPTNO)
  references dept (DEPTNO);


create table salgrade
(
  grade int,
  losal int,
  hisal int
)
;


insert into dept (deptno, dname, loc)
values (10, 'ACCOUNTING', 'NEW YORK'),
(20, 'RESEARCH', 'DALLAS'),
(30, 'SALES', 'CHICAGO'),
(40, 'OPERATIONS', 'BOSTON');

insert into emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7369, 'SMITH', 'CLERK', 7902, '1980-12-17', 800, null, 20),
(7499, 'ALLEN', 'SALESMAN', 7698, '1981-02-20', 1600, 300, 30),
(7521, 'WARD', 'SALESMAN', 7698, '1981-02-22', 1250, 500, 30),
(7566, 'JONES', 'MANAGER', 7839, '1981-04-02', 2975, null, 20),
(7654, 'MARTIN', 'SALESMAN', 7698, '1981-09-28', 1250, 1400, 30),
(7698, 'BLAKE', 'MANAGER', 7839, '1981-05-01', 2850, null, 30),
(7782, 'CLARK', 'MANAGER', 7839, '1981-06-09', 2450, null, 10),
(7788, 'SCOTT', 'ANALYST', 7566, '1987-04-19', 3000, null, 20),
(7839, 'KING', 'PRESIDENT', null, '1981-11-17', 5000, null, 10),
(7844, 'TURNER', 'SALESMAN', 7698, '1981-09-08', 1500, 0, 30),
(7876, 'ADAMS', 'CLERK', 7788, '1987-05-23', 1100, null, 20),
(7900, 'JAMES', 'CLERK', 7698, '1981-12-03', 950, null, 30),
(7902, 'FORD', 'ANALYST', 7566, '1981-12-03', 3000, null, 20),
(7934, 'MILLER', 'CLERK', 7782, '1982-01-23', 1300, null, 10);

insert into salgrade (grade, losal, hisal)
values (1, 700, 1200),
(2, 1201, 1400),
(3, 1401, 2000),
(4, 2001, 3000),
(5, 3001, 9999);

