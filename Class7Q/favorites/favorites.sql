select * from shows order by title;

select * from shows where title like "%Brooklyn%" or title like "%99%" or title like "%B99%" order by title;
update shows set title = "Brooklyn Nine-Nine"
where title like "%Brooklyn%" or title like "%99%" or title like "%99%" or title like "%B99%";

select * from shows where title like "%Game%Thrones%" or title like "GoT";
update shows set title = "Game of Thrones"
where title like "%Game%Thrones" or title like "GoT";

select * from shows where title like "Grey%";
update shows set title = "Grey's Anatomy"
where title like "Grey%";

select * from shows where title like "%Always Sunny%" or title like "%Phil%";
update shows set title = "It's Always Sunny in Philadelphia"
where title like "%Always Sunny%" or title like "%Phil%";

select * from shows where title like '%Parks%Rec%' or title like '%Parks and Rec%';
update shows set title = "Parks and Recreation"
where title like '%Parks%Rec%' or title like '%Parks and Rec%';


