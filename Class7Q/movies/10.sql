select distinct p.name from people p
join directors d on d.person_id = p.id
join ratings r on d.movie_id = r.movie_id
where r.rating >= 9.0;
