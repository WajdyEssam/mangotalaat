
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
INSERT INTO item_size(arabic_name, english_name) values("جالون 1 لتر", "Gallon 1L");
INSERT INTO item_size(arabic_name, english_name) values("جالون 5 لتر", "Gallon 5L");
INSERT INTO item_size(arabic_name, english_name) values("جالون 10 لتر", "Gallon 10L");

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
	categories_id INTEGER
);

INSERT INTO items(arabic_name, english_name, categories_id) values("مانجو - طلعت", "Mano - Talaat", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("فراولة - طلعت", "Strawberry - Talaat", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("مانجو - مثلج", "Mano - Iced", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("فراولة - مثلج", "Strawberry - Iced", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("برتقال", "Orange", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("جزر", "Carrot", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("ليمون", "Lemon", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("ليمون بالنعناع", "Lemon With Mint", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("موز بالحليب", "Banana With Milk", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("تفاح", "Apple", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("أناناس", "Pineapple", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("خوخ", "Peach", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("أفوكادو", "Avocado", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("تين شوكي", "Prickly Pear", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("كيوي", "Kiwi", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("عنب", "Grapes", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("جريب فروت", "GrapeFruit", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("جوافه", "Guava", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("شمام", "Melon", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("بطيخ", "Watermelon", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("توت", "Berries", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("رمان", "Pomegranate", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("جرجير", "Watercress", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("قصب سكر", "Sugar Cane", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("كركديه", "Roselle", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("فيمتو", "Vimto", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("الشايب -بيذان", "Al-Shayep - Bizan", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("سلاش توت", "Berries Slash", 1);
INSERT INTO items(arabic_name, english_name, categories_id) values("سلاش فراولة", "Strawberry Slash", 1);

INSERT INTO items(arabic_name, english_name, categories_id) values("طبق كويتي", "Kuwaiti Dish", 3);
INSERT INTO items(arabic_name, english_name, categories_id) values("طبق طلعت", "Talaat Dish", 3);
INSERT INTO items(arabic_name, english_name, categories_id) values("أمازون", "Amazon", 3);
INSERT INTO items(arabic_name, english_name, categories_id) values("بنانا سبليت", "Banana Split", 3);
INSERT INTO items(arabic_name, english_name, categories_id) values("كورن فليكس", "Corn Flakes", 3);
INSERT INTO items(arabic_name, english_name, categories_id) values("جاكو وويف", "Jaco Wave", 3);
INSERT INTO items(arabic_name, english_name, categories_id) values("شاكو ماني", "Chackomani", 3);
INSERT INTO items(arabic_name, english_name, categories_id) values("كيك بالآيس كريم", "Ice Cream Cake", 3);
INSERT INTO items(arabic_name, english_name, categories_id) values("لولو", "Lulu", 3);
INSERT INTO items(arabic_name, english_name, categories_id) values("موكا", "Mocha", 3);
INSERT INTO items(arabic_name, english_name, categories_id) values("صمدي", "Samadi", 3);
INSERT INTO items(arabic_name, english_name, categories_id) values("فخفخينا", "Fakhfakhina", 3);
INSERT INTO items(arabic_name, english_name, categories_id) values("خلطة رجيم", "Diet Mix", 3);
INSERT INTO items(arabic_name, english_name, categories_id) values("براوني", "Brownie", 3);
INSERT INTO items(arabic_name, english_name, categories_id) values("هاي أناناس", "High Pineapple", 3);
INSERT INTO items(arabic_name, english_name, categories_id) values("الطبق الأحمر", "Red Dish", 3);

CREATE TABLE item_details (
	id 	INTEGER PRIMARY KEY AUTOINCREMENT,
	item_id INTEGER,
	size_id INTEGER,
	price INTEGER
);

INSERT INTO item_details(item_id, size_id, price) values(1, 1, 8);
INSERT INTO item_details(item_id, size_id, price) values(1, 2, 13);
INSERT INTO item_details(item_id, size_id, price) values(1, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(2, 1, 8);
INSERT INTO item_details(item_id, size_id, price) values(2, 2, 13);
INSERT INTO item_details(item_id, size_id, price) values(2, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(3, 1, 5);
INSERT INTO item_details(item_id, size_id, price)  values(3, 2, 8);
INSERT INTO item_details(item_id, size_id, price)  values(3, 4, 12);
INSERT INTO item_details(item_id, size_id, price)  values(4, 1, 5);
INSERT INTO item_details(item_id, size_id, price)  values(4, 2, 8);
INSERT INTO item_details(item_id, size_id, price)  values(4, 4, 12);
INSERT INTO item_details(item_id, size_id, price)  values(5, 1, 5);
INSERT INTO item_details(item_id, size_id, price)  values(5, 2, 9);
INSERT INTO item_details(item_id, size_id, price)  values(5, 4, 13);
INSERT INTO item_details(item_id, size_id, price)  values(6, 1, 5);
INSERT INTO item_details(item_id, size_id, price)  values(6, 2, 9);
INSERT INTO item_details(item_id, size_id, price)  values(6, 4, 13);
INSERT INTO item_details(item_id, size_id, price)  values(7, 1, 5);
INSERT INTO item_details(item_id, size_id, price)  values(7, 2, 9);
INSERT INTO item_details(item_id, size_id, price)  values(7, 4, 13);
INSERT INTO item_details(item_id, size_id, price)  values(8, 1, 5);
INSERT INTO item_details(item_id, size_id, price)  values(8, 2, 9);
INSERT INTO item_details(item_id, size_id, price)  values(8, 4, 13);
INSERT INTO item_details(item_id, size_id, price)  values(9, 1, 5);
INSERT INTO item_details(item_id, size_id, price)  values(9, 2, 8);
INSERT INTO item_details(item_id, size_id, price)  values(9, 4, 12);
INSERT INTO item_details(item_id, size_id, price)  values(10, 1, 6);
INSERT INTO item_details(item_id, size_id, price)  values(10, 2, 9);
INSERT INTO item_details(item_id, size_id, price)  values(10, 4, 13);
INSERT INTO item_details(item_id, size_id, price)  values(11, 1, 6);
INSERT INTO item_details(item_id, size_id, price)  values(11, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(11, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(12, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(12, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(12, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(13, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(13, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(13, 4, 18);
INSERT INTO item_details(item_id, size_id, price)  values(14, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(14, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(14, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(15, 1, 6);
INSERT INTO item_details(item_id, size_id, price)  values(15, 2, 12);
INSERT INTO item_details(item_id, size_id, price)  values(15, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(16, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(16, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(16, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(17, 1, 6);
INSERT INTO item_details(item_id, size_id, price)  values(17, 2, 12);
INSERT INTO item_details(item_id, size_id, price)  values(17, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(18, 1, 6);
INSERT INTO item_details(item_id, size_id, price)  values(18, 2, 12);
INSERT INTO item_details(item_id, size_id, price)  values(18, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(19, 1, 6);
INSERT INTO item_details(item_id, size_id, price)  values(19, 2, 12);
INSERT INTO item_details(item_id, size_id, price)  values(19, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(20, 1, 6);
INSERT INTO item_details(item_id, size_id, price)  values(20, 2, 12);
INSERT INTO item_details(item_id, size_id, price)  values(20, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(21, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(21, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(21, 4, 18);
INSERT INTO item_details(item_id, size_id, price)  values(22, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(22, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(22, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(23, 1, 6);
INSERT INTO item_details(item_id, size_id, price)  values(23, 2, 12);
INSERT INTO item_details(item_id, size_id, price)  values(23, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(24, 1, 6);
INSERT INTO item_details(item_id, size_id, price)  values(24, 2, 9);
INSERT INTO item_details(item_id, size_id, price)  values(24, 4, 13);
INSERT INTO item_details(item_id, size_id, price)  values(25, 1, 4);
INSERT INTO item_details(item_id, size_id, price)  values(25, 2, 6);
INSERT INTO item_details(item_id, size_id, price)  values(25, 4, 9);
INSERT INTO item_details(item_id, size_id, price)  values(26, 1, 3);
INSERT INTO item_details(item_id, size_id, price)  values(26, 2, 6);
INSERT INTO item_details(item_id, size_id, price)  values(26, 4, 9);
INSERT INTO item_details(item_id, size_id, price)  values(27, 1, 5);
INSERT INTO item_details(item_id, size_id, price)  values(27, 2, 9);
INSERT INTO item_details(item_id, size_id, price)  values(27, 4, 13);
INSERT INTO item_details(item_id, size_id, price)  values(28, 1, 4);
INSERT INTO item_details(item_id, size_id, price)  values(28, 2, 9);
INSERT INTO item_details(item_id, size_id, price)  values(28, 4, 13);
INSERT INTO item_details(item_id, size_id, price)  values(29, 1, 4);
INSERT INTO item_details(item_id, size_id, price)  values(29, 2, 9);
INSERT INTO item_details(item_id, size_id, price)  values(29, 4, 13);


INSERT INTO item_details(item_id, size_id, price)  values(56, 5, 16);
INSERT INTO item_details(item_id, size_id, price)  values(57, 5, 16);
INSERT INTO item_details(item_id, size_id, price)  values(58, 5, 17);
INSERT INTO item_details(item_id, size_id, price)  values(59, 5, 16);
INSERT INTO item_details(item_id, size_id, price)  values(60, 5, 7);
INSERT INTO item_details(item_id, size_id, price)  values(61, 5, 14);
INSERT INTO item_details(item_id, size_id, price)  values(62, 5, 14);
INSERT INTO item_details(item_id, size_id, price)  values(63, 5, 12);
INSERT INTO item_details(item_id, size_id, price)  values(64, 5, 17);
INSERT INTO item_details(item_id, size_id, price)  values(65, 5, 13);
INSERT INTO item_details(item_id, size_id, price)  values(66, 5, 10);
INSERT INTO item_details(item_id, size_id, price)  values(67, 5, 10);
INSERT INTO item_details(item_id, size_id, price)  values(68, 5, 13);
INSERT INTO item_details(item_id, size_id, price)  values(69, 5, 12);
INSERT INTO item_details(item_id, size_id, price)  values(70, 5, 16);
INSERT INTO item_details(item_id, size_id, price)  values(71, 5, 12);

CREATE TABLE components (
	id 	INTEGER PRIMARY KEY AUTOINCREMENT,
	arabic_name TEXT,
	english_name TEXT
);

INSERT INTO components(arabic_name, english_name) values("مانجو", "Mango");
INSERT INTO components(arabic_name, english_name) values("فروالة", "Strawberry");
INSERT INTO components(arabic_name, english_name) values("موز بالحليب", "Banana Milk");
INSERT INTO components(arabic_name, english_name) values("موز", "Banana");
INSERT INTO components(arabic_name, english_name) values("فانيليا", "Vanilla");
INSERT INTO components(arabic_name, english_name) values("حليب", "Milk");
INSERT INTO components(arabic_name, english_name) values("جزر", "Carrots");
INSERT INTO components(arabic_name, english_name) values("برتقال", "Orange");
INSERT INTO components(arabic_name, english_name) values("آيس كريم", "Ice cream");
INSERT INTO components(arabic_name, english_name) values("تفاح", "Apple");
INSERT INTO components(arabic_name, english_name) values("عصير رقي مع القطع", "Watermelon Juice with Pieces");
INSERT INTO components(arabic_name, english_name) values("توت", "Barries");
INSERT INTO components(arabic_name, english_name) values("أناناس", "Pinapple");
INSERT INTO components(arabic_name, english_name) values("خوخ", "Peach");
INSERT INTO components(arabic_name, english_name) values("كيوي", "Kiwi");
INSERT INTO components(arabic_name, english_name) values("تفاح أخضر", "Green Apple");
INSERT INTO components(arabic_name, english_name) values("جوز هند", "Coconut");
INSERT INTO components(arabic_name, english_name) values("أفوكادو", "Avocado");
INSERT INTO components(arabic_name, english_name) values("شمام", "Melon");
INSERT INTO components(arabic_name, english_name) values("ليمون", "Lemon");
INSERT INTO components(arabic_name, english_name) values("رمان", "Pomegranate");
INSERT INTO components(arabic_name, english_name) values("مكس", "Mix");

CREATE TABLE item_components (
	id 	INTEGER PRIMARY KEY AUTOINCREMENT,
	item_id INTEGER, 
	component_id INTEGER
);