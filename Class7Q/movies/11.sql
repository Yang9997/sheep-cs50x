select m.title from movies m
join stars s on s.movie_id = m.id
join people p on p.id = s.person_id
join ratings r on m.id = r.movie_id
where p.name = 'Chadwick Boseman'
order by r.rating desc
limit 5;
