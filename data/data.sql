
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

INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("مانجو - طلعت", "Mano - Talaat", 1, 1, 8);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("مانجو - طلعت", "Mano - Talaat", 1, 2, 13);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("مانجو - طلعت", "Mano - Talaat", 1, 4, 16);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("فراولة - طلعت", "Strawberry - Talaat", 1, 1, 8);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("فراولة - طلعت", "Strawberry - Talaat", 1, 2, 13);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("فراولة - طلعت", "Strawberry - Talaat", 1, 4, 16);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("مانجو - مثلج", "Mano - Iced", 1, 1, 5);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("مانجو - مثلج", "Mano - Iced", 1, 2, 8);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("مانجو - مثلج", "Mano - Iced", 1, 4, 12);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("فراولة - مثلج", "Strawberry - Iced", 1, 1, 5);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("فراولة - مثلج", "Strawberry - Iced", 1, 2, 8);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("فراولة - مثلج", "Strawberry - Iced", 1, 4, 12);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("برتقال", "Orange", 1, 1, 5);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("برتقال", "Orange", 1, 2, 9);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("برتقال", "Orange", 1, 4, 13);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("جزر", "Carrot", 1, 1, 5);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("جزر", "Carrot", 1, 2, 9);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("جزر", "Carrot", 1, 4, 13);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("ليمون", "Lemon", 1, 1, 5);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("ليمون", "Lemon", 1, 2, 9);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("ليمون", "Lemon", 1, 4, 13);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("ليمون بالنعناع", "Lemon With Mint", 1, 1, 5);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("ليمون بالنعناع", "Lemon With Mint", 1, 2, 9);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("ليمون بالنعناع", "Lemon With Mint", 1, 4, 13);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("موز بالحليب", "Banana With Milk", 1, 1, 5);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("موز بالحليب", "Banana With Milk", 1, 2, 8);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("موز بالحليب", "Banana With Milk", 1, 4, 12);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("تفاح", "Apple", 1, 1, 6);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("تفاح", "Apple", 1, 2, 9);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("تفاح", "Apple", 1, 4, 13);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("أناناس", "Pineapple", 1, 1, 6);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("أناناس", "Pineapple", 1, 2, 13);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("أناناس", "Pineapple", 1, 4, 16);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("خوخ", "Peach", 1, 1, 8);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("خوخ", "Peach", 1, 2, 13);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("خوخ", "Peach", 1, 4, 16);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("أفوكادو", "Avocado", 1, 1, 10);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("أفوكادو", "Avocado", 1, 2, 13);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("أفوكادو", "Avocado", 1, 4, 18);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("تين شوكي", "Prickly Pear", 1, 1, 8);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("تين شوكي", "Prickly Pear", 1, 2, 13);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("تين شوكي", "Prickly Pear", 1, 4, 16);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("كيوي", "Kiwi", 1, 1, 6);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("كيوي", "Kiwi", 1, 2, 12);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("كيوي", "Kiwi", 1, 4, 16);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("عنب", "Grapes", 1, 1, 10);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("عنب", "Grapes", 1, 2, 13);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("عنب", "Grapes", 1, 4, 16);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("جريب فروت", "GrapeFruit", 1, 1, 6);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("جريب فروت", "GrapeFruit", 1, 2, 12);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("جريب فروت", "GrapeFruit", 1, 4, 16);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("جوافه", "Guava", 1, 1, 6);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("جوافه", "Guava", 1, 2, 12);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("جوافه", "Guava", 1, 4, 16);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("شمام", "Melon", 1, 1, 6);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("شمام", "Melon", 1, 2, 12);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("شمام", "Melon", 1, 4, 16);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("بطيخ", "Watermelon", 1, 1, 6);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("بطيخ", "Watermelon", 1, 2, 12);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("بطيخ", "Watermelon", 1, 4, 16);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("توت", "Berries", 1, 1, 10);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("توت", "Berries", 1, 2, 13);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("توت", "Berries", 1, 4, 18);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("رمان", "Pomegranate", 1, 1, 8);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("رمان", "Pomegranate", 1, 2, 13);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("رمان", "Pomegranate", 1, 4, 16);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("جرجير", "Watercress", 1, 1, 6);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("جرجير", "Watercress", 1, 2, 12);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("جرجير", "Watercress", 1, 4, 16);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("قصب سكر", "Sugar Cane", 1, 1, 6);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("قصب سكر", "Sugar Cane", 1, 2, 9);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("قصب سكر", "Sugar Cane", 1, 4, 13);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("كركديه", "Roselle", 1, 1, 4);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("كركديه", "Roselle", 1, 2, 6);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("كركديه", "Roselle", 1, 4, 9);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("فيمتو", "Vimto", 1, 1, 3);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("فيمتو", "Vimto", 1, 2, 6);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("فيمتو", "Vimto", 1, 4, 9);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("الشايب -بيذان", "Al-Shayep - Bizan", 1, 1, 5);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("الشايب -بيذان", "Al-Shayep - Bizan", 1, 2, 9);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("الشايب -بيذان", "Al-Shayep - Bizan", 1, 4, 13);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("سلاش توت", "Berries Slash", 1, 1, 4);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("سلاش توت", "Berries Slash", 1, 2, 9);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("سلاش توت", "Berries Slash", 1, 4, 13);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("سلاش فراولة", "Strawberry Slash", 1, 1, 4);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("سلاش فراولة", "Strawberry Slash", 1, 2, 9);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("سلاش فراولة", "Strawberry Slash", 1, 4, 13);

INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("طبق كويتي", "Kuwaiti Dish", 3, 5, 16);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("طبق طلعت", "Talaat Dish", 3, 5, 16);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("أمازون", "Amazon", 3, 5, 17);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("بنانا سبليت", "Banana Split", 3, 5, 16);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("كورن فليكس", "Corn Flakes", 3, 5, 7);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("جاكو وويف", "Jaco Wave", 3, 5, 14);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("شاكو ماني", "Chackomani", 3, 5, 14);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("كيك بالآيس كريم", "Ice Cream Cake", 3, 5, 12);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("لولو", "Lulu", 3, 5, 17);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("موكا", "Mocha", 3, 5, 13);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("صمدي", "Samadi", 3, 5, 10);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("فخفخينا", "Fakhfakhina", 3, 5, 10);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("خلطة رجيم", "Diet Mix", 3, 5, 13);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("براوني", "Brownie", 3, 5, 12);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("هاي أناناس", "High Pineapple", 3, 5, 16);
INSERT INTO items(arabic_name, english_name, categories_id, size_id, price) values("الطبق الأحمر", "Red Dish", 3, 5, 12);

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