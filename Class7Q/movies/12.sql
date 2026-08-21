select m.title from movies m
join stars s1 on s1.movie_id = m.id
join people p1 on p1.id = s1.person_id
join stars s2 on s2.movie_id = m.id
join people p2 on p2.id = s2.person_id
where p1.name = "Bradley Cooper" and p2.name = "Jennifer Lawrence"
