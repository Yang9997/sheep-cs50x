select distinct p.name from people p
join stars s1 on s1.person_id = p.id
join movies m1 on m1.id = s1.movie_id
join stars s2 on s2.movie_id = m1.id
join people p1 on p1.id = s2.person_id
where p1.name = 'Kevin Bacon' and p1.birth = 1958
and p.name != 'Kevin Bacon';
