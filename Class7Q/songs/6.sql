select s.name from songs s
join artists a on a.id = s.artist_id
where a.name like "%Post Malone%"
order by s.name;
