
CREATE TABLE users (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	username TEXT,
	password TEXT,
	register_time TEXT
);

CREATE TABLE item_size (
	id 	INTEGER PRIMARY KEY AUTOINCREMENT,
	arabic_name TEXT,
	english_name TEXT
);

INSERT INTO item_size(arabic_name, english_name) values("صغير", "small");
INSERT INTO item_size(arabic_name, english_name) values("وسط", "medium");
INSERT INTO item_size(arabic_name, english_name) values("كبير", "large");
INSERT INTO item_size(arabic_name, english_name) values("جامبو", "jambo");
INSERT INTO item_size(arabic_name, english_name) values("طبق", "dish");

CREATE TABLE categories (
	id 	INTEGER PRIMARY KEY AUTOINCREMENT,
	arabic_name TEXT,
	english_name TEXT
);

INSERT INTO categories(arabic_name, english_name) values("العصائر الطازجة", "Fresh JUICES");
INSERT INTO categories(arabic_name, english_name) values("الكوكتيلات", "Cocktails");
INSERT INTO categories(arabic_name, english_name) values("الأطباق المميزة", "Special Dishes");
INSERT INTO categories(arabic_name, english_name) values("سبيشال كوكتيل", "Speical Cocktial");
INSERT INTO categories(arabic_name, english_name) values("ريد بول", "Red Bull");
INSERT INTO categories(arabic_name, english_name) values("فروزون يوغورت", "Frozen Yogurt");
INSERT INTO categories(arabic_name, english_name) values("آيس كريم", "Ice Cream");
INSERT INTO categories(arabic_name, english_name) values("ميلك شيك", "Milk Shake");

CREATE TABLE orders_type (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	description TEXT
);

INSERT INTO orders_type(description) values("Cash");
INSERT INTO orders_type(description) values("Cupon");
INSERT INTO orders_type(description) values("Discount");

CREATE TABLE orders (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	order_time NUMERIC,
	order_type_id INTEGER,
	discount INTEGER,
	total_cash INTEGER,
	is_cancelled INTEGER
);

CREATE TABLE order_details(
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	item_id INTEGER,
	quantity INTEGER,
	arabic_description TEXT,
	english_description TEXT
);

CREATE TABLE order_canceled (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	order_id INTEGER,
	cancel_time NUMERIC
);

CREATE TABLE items (
	id 	INTEGER PRIMARY KEY AUTOINCREMENT,
	arabic_name TEXT,
	english_name TEXT,
	categories_id INTEGER,
	size_id INTEGER,
	price INTEGER
);

CREATE TABLE components (
	id 	INTEGER PRIMARY KEY AUTOINCREMENT,
	arabic_name TEXT,
	english_name TEXT
);

CREATE TABLE item_components (
	id 	INTEGER PRIMARY KEY AUTOINCREMENT,
	item_id INTEGER, 
	component_id INTEGER
);