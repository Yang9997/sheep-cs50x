select p.name
from people p
join stars s, movies m on m.id = s.movie_id and p.id = s.person_id
where m.title = "Toy Story";
