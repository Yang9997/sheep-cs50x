-- csv导成db
-- -- 创建一个sql数据库
-- sqlite3 favorites.csv
-- -- 将sqlite3设置为csv模式
-- .mode csv
-- -- 从csv文件导入数据
-- .import favorites.csv favorites
-- -- 查看数据库
-- .schema

select * from favorites;
select problem from favorites where language = "Python";
select count(problem) from favorites where language = "Python";

-- CRUD
-- 1. create： create insert
-- create db
-- -- sqlite不需要显式创建数据库，下面这种话会报错，它是mysql可有的语句
-- create database namedb;
-- create table
drop table if exists namelist;
create table namelist
(
    StudentName varchar(255),
    Birth varchar(255),
    City varchar(255)
);
-- insert：
insert into namelist(StudentName, Birth, City) values ("Yang9997", "20020305", "BeiJing");
insert into namelist(StudentName, Birth, City) values("ZhangSan", "20010530", "ChangChun");
-- 2. read： select
select * from namelist;
-- 3. update
update namelist set city = "SongYuan" where StudentName = "Yang9997";
-- 4. delete:
delete from namelist where StudentName = "ZhangSan";

select * from namelist;

-- more
select count(language) from favorites;
select distinct(language) from favorites;
select count(distinct(language)) from favorites;
-- where 添加布尔表达式过滤数据
-- like 模糊匹配
-- order by 对结果进行排序
-- limit 限制结果数量
-- group by 将结果分组
-- 1. where
select count(*) from favorites where language = "C";
select count(*) from favorites where language = "C" and problem = "Mario";
-- 2. like
-- % >=0; _ ==1
select language from favorites where language like '%th%';
-- 3. order by
-- SELECT column1, column2
-- FROM table_name
-- ORDER BY column1 [ASC|DESC], column2 [ASC|DESC];
-- 4. limit
-- 获取前n行 5
select language from favorites limit 5;
-- 跳过m行后获取n行 11-15 没那么多的话有多少显示多少，比如这里只有2行
select language from favorites limit 5 offset 10;
-- 5. group by
-- 临时表计数
select language, count(*) from favorites group by language;
-- 优化排序
select language, count(*) from favorites group by language order by count(*);
