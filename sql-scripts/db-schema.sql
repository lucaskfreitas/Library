pragma user_version = 1;

create table person
(
    id integer primary key autoincrement,
    is_author boolean,
    name nvarchar(100)
);

create table city
(
    id integer primary key autoincrement,
    name nvarchar(100)
);

create table publisher
(
    id integer primary key autoincrement,
    name nvarchar(100)
);

create table collection
(
    id integer primary key autoincrement,
    name nvarchar(100)
);

create table subject
(
    id integer primary key autoincrement,
    name nvarchar(100)
);

create table language
(
    id integer primary key autoincrement,
    name nvarchar(100)
);

create table record_type
(
    id integer primary key autoincrement,
    name nvarchar(100)
);

create table record
(
    id integer primary key autoincrement,
    title nvarchar(100),
    type_id integer,
    day integer,
    month integer,
    year integer,
    n_pages integer,
    volume integer,
    number integer,
    reference_number nvarchar(100),
    copies integer,
    obs nvarchar(500),
    borrowed boolean,
    borrowed_to integer,
    foreign key (type_id) references record_type (id)
    foreign key (borrowed_to) references person (id)
);

create table record_author
(
    record_id integer,
    author_id integer,
    foreign key (record_id) references record (id),
    foreign key (author_id) references person (id),
    primary key (record_id, author_id)
);

create table record_city
(
    record_id integer,
    city_id integer,
    foreign key (record_id) references record (id),
    foreign key (city_id) references city (id),
    primary key (record_id, city_id)
);

create table record_publisher
(
    record_id integer,
    publisher_id integer,
    foreign key (record_id) references record (id),
    foreign key (publisher_id) references publisher (id),
    primary key (record_id, publisher_id)
);

create table record_collection
(
    record_id integer,
    collection_id integer,
    foreign key (record_id) references record (id),
    foreign key (collection_id) references collection (id),
    primary key (record_id, collection_id)
);

create table record_subject
(
    record_id integer,
    subject_id integer,
    foreign key (record_id) references record (id),
    foreign key (subject_id) references subject (id),
    primary key (record_id, subject_id)
);

create table record_language
(
    record_id integer,
    language_id integer,
    foreign key (record_id) references record (id),
    foreign key (language_id) references language (id),
    primary key (record_id, language_id)
);
