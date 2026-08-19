-- limit
select * from people limit 10;
select * from shows limit 10;

select * from genres;


select * from genres where genre = "Comedy" limit 10;

select * from shows where id = 626124;

select title
from shows
where id in (
    select show_id
    from genres
    where genre = "Comedy"
)
limit 10;

select title
from shows
where id in (
    select show_id
    from genres
    where genre = "Comedy"
)
order by title limit 10;

select title from shows where id in
    (select show_id from stars where person_id =
        (select id from people where name = "Steve Carell"));


-- join
-- 临时组表
select * from shows
    join ratings on shows.id = ratings.show_id
    where title = "The Office";

select title from people
    join stars on people.id = stars.person_id
    join shows on stars.show_id = shows.id
    where name = "Steve Carell";

select title from people, stars, shows
where people.id = stars.person_id
and stars.show_id = shows.id
and name = "Steve Carell";

select * from people where name like "Steve C%";

-- index
-- 优化后索引
create index title_index on shows(title);
select * from shows where title = "The Office";
