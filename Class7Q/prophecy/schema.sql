drop table if exists students;
drop table if exists societies;
drop table if exists society_distribution;

create table students (
    id integer,
    student_name text,
    primary key(id)
);

create table societies (
    id integer,
    house text unique,
    head text,
    -- 如果设置两个primary key的话会将这两个看成是一个，相当于insert的时候不能用其中一个作为判定，只能两个一起判定
    -- 比如1 name1，如果有个2 name1的话也是能插进来的，并不会单独判定name1在不在而是一起判定
    primary key(id)
);

create table society_distribution (
    student_id,
    house,
    primary key(student_id),
    -- 外键约束
    -- 外键引用必须是主键或者唯一键，students里的id是主键，societies里的house是唯一键，都可以
    foreign key (student_id) references students(id),
    foreign key (house) references societies(house)
);
