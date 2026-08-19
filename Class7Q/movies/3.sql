create index year_index on movies(year);
select title from movies where year >= 2008 order by upper(title);
