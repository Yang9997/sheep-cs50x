# finance

## 1. sqlite语法相关
```sql
-- sum这种函数可以指定名字 as
select symbol, sum(shares) as sharesSum from share where user_id = 3;
-- insert：autoincrement自动升序生成或者key primary从1开始的主键，这种可以不自己插，让它自己生成
insert into share (user_id, symbol, price, shares) values (4, “GOOGL”, 32000, 3);
-- update
update users set cash = 100000 where id = 5;
-- order by：可以指定多个字段，多个升序降序，注意指定的先后顺序
select symbol, price, shares, created_at from share where user_id = ? order by symbol asc, created_at desc;
-- create：1. if not exists 2. integer text integer real datetime 3. foreign key 只有一个外键也得有()
create table if not exists share(
                id integer primary key autoincrement,
                user_id integer not null,
                symbol text not null,
                price real not null,
                shares integer not null,
                created_at datetime not null default current_timestamp,
                foreign key (user_id) references users(id))
-- 聚合函数类似sum(shares)不能放在where里
-- where：分组前过滤普通行
-- having：分组之后过滤聚合结果，要和group by配合使用
select symbol from share where user_id = 4 group by symbol having sum(shares) > 0;
```

## 2. session相关
1. session["user_id"]而非session["username"]。应用中一般使用id作为唯一识别，虽然题里面说了姓名唯一，但最好还是用id。


## * debug相关
1. flask后端代码如何debug？只能看terminal吗？
    - 在cs50里面c怎么调试python就怎么调试，毕竟都是在vscode里面。比如print，比如debug，。基本上都是看终端

