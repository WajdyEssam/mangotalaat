
CREATE TABLE users (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	username TEXT,
	password TEXT,
	register_time DATETIME
);

INSERT INTO users(username, password, register_time) values("admin", "123", "Thu Jul 26 14:08:49 2012");
INSERT INTO users(username, password, register_time) values("user", "123", "Thu Jul 26 10:08:49 2012");

CREATE TABLE events_logging (
	id INTEGER PRIMARY KEY AUTOINCREMENT, 
	user_id INTEGER,
	event_time DATETIME,
	event_type INTEGER
);

CREATE TABLE system_checkout (
	id INTEGER PRIMARY KEY AUTOINCREMENT, 
	checkout_time DATATIME
);

INSERT INTO system_checkout(checkout_time) values("Thu Jul 26 14:08:49 2012");

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
INSERT INTO item_size(arabic_name, english_name) values("ساده", "Normal");
INSERT INTO item_size(arabic_name, english_name) values("فواكه", "Fruits");
INSERT INTO item_size(arabic_name, english_name) values("توت", "Berries");

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
	arabic_name TEXT,
	english_name TEXT
);

INSERT INTO orders_type(description) values("Cash", "كاش");
INSERT INTO orders_type(description) values("Cupon", "كوبون");
INSERT INTO orders_type(description) values("Discount", "خصم");
INSERT INTO orders_type(description) values("Free", "مجاني");

CREATE TABLE orders (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	order_time DATETIME,
	order_type_id INTEGER,
	cash INTEGER,
	discount INTEGER,
	total_cash INTEGER,
	is_cancelled INTEGER
);

CREATE TABLE order_details(
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	order_id INTEGER,
	item_detial_id INTEGER,
	quantity INTEGER,
	components_ids TEXT,
	additionals_ids TEXT, 
	sugar INTEGER,
	cash INTEGER
);

CREATE TABLE order_canceled (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	order_id INTEGER,
	cancel_time DATETIME
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

INSERT INTO items(arabic_name, english_name, categories_id) values("كوكتيل كويتي", "Kuwaiti Cocktail", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("كوكتيل طبيعي", "Natural Cocktail", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("إمبراطور", "Emperor", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("ندى الشام", "Nada Al-Sham", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("شامي", "Shami", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("عوار القلب", "3war Qalb", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("أخو عزيز", "Akho Aziz", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("جعيص", "Go3ai9", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("حسون", "7soon", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("شحليلة", "Shahleela", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("فورتي", "Fruity", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("بوبو", "Bobo", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("نصرواي", "Nasrawi", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("إيزي", "Easy", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("ولمنة", "Walamenna", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("مناي", "Munaya", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("المنتخب السعودي", "Saudi National Team", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("سموزي", "Smozy", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("سلم", "Sallem", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("بكزبني", "Bugs Bunny", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("بلاك بيري", "BlackBerry", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("ميمي", "Meme", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("إمبراطور الشام", "Emperor of Melon", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("فورسيزونز", "4 Seasons", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("سفن آب", "7 UP", 2);
INSERT INTO items(arabic_name, english_name, categories_id) values("كوكتيل خاص", "Special Cocktail", 2);

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

INSERT INTO items(arabic_name, english_name, categories_id) values("فور آند وان", "4 & 1", 4);
INSERT INTO items(arabic_name, english_name, categories_id) values("أروما", "Arima", 4);
INSERT INTO items(arabic_name, english_name, categories_id) values("بيناكولادا", "Pina Colada", 4);
INSERT INTO items(arabic_name, english_name, categories_id) values("هاواي", "Hawaii", 4);
INSERT INTO items(arabic_name, english_name, categories_id) values("أناناس مكس", "Pineapple Mix", 4);
INSERT INTO items(arabic_name, english_name, categories_id) values("جريب أواي", "Grape Away", 4);
INSERT INTO items(arabic_name, english_name, categories_id) values("دايت لاي", "Diet Lay", 4);
INSERT INTO items(arabic_name, english_name, categories_id) values("4 * 4", "4 * 4", 4);
INSERT INTO items(arabic_name, english_name, categories_id) values("مكس", "Mix", 4);
INSERT INTO items(arabic_name, english_name, categories_id) values("دريم", "Dream", 4);
INSERT INTO items(arabic_name, english_name, categories_id) values("توتو", "Tutu", 4);
INSERT INTO items(arabic_name, english_name, categories_id) values("الغدير", "Al-Ghadeer", 4);

INSERT INTO items(arabic_name, english_name, categories_id) values("ريد بول رمان", "Red Bull Pomegranate", 5);
INSERT INTO items(arabic_name, english_name, categories_id) values("ريد بول فراولة", "Red Bull Strawberry", 5);
INSERT INTO items(arabic_name, english_name, categories_id) values("ريد بول ليمون", "Red Bull Lemon", 5);
INSERT INTO items(arabic_name, english_name, categories_id) values("ريد بول توت", "Red Bull Barries", 5);
INSERT INTO items(arabic_name, english_name, categories_id) values("ريد بول كرز", "Red Bull Cherries", 5);
INSERT INTO items(arabic_name, english_name, categories_id) values("ريد بول مكس", "Red Bull Mix", 5);
INSERT INTO items(arabic_name, english_name, categories_id) values("ريد بول هلالي - سلاش", "Red Bull Hilaly - Slash", 5);

INSERT INTO items(arabic_name, english_name, categories_id) values("أبيض", "White", 6);
INSERT INTO items(arabic_name, english_name, categories_id) values("وردي", "Pink", 6);
INSERT INTO items(arabic_name, english_name, categories_id) values("مكس", "Mix", 6);

INSERT INTO items(arabic_name, english_name, categories_id) values("مانجو", "Mango", 7);
INSERT INTO items(arabic_name, english_name, categories_id) values("فروالة", "Strawberry", 7);
INSERT INTO items(arabic_name, english_name, categories_id) values("شوكولاته", "Chocolate", 7);
INSERT INTO items(arabic_name, english_name, categories_id) values("فستق", "Pistachio", 7);
INSERT INTO items(arabic_name, english_name, categories_id) values("ليمون", "Lemon", 7);
INSERT INTO items(arabic_name, english_name, categories_id) values("فانيلا", "Vanilla", 7);

INSERT INTO items(arabic_name, english_name, categories_id) values("شوكولاته", "Chocolate", 8);
INSERT INTO items(arabic_name, english_name, categories_id) values("فانيلا", "Vanilla", 8);
INSERT INTO items(arabic_name, english_name, categories_id) values("فرواله", "Strawberry", 8);
INSERT INTO items(arabic_name, english_name, categories_id) values("سنيكرز", "Snickers", 8);
INSERT INTO items(arabic_name, english_name, categories_id) values("كيندر", "Kinder", 8);
INSERT INTO items(arabic_name, english_name, categories_id) values("مالتيزرز", "Maltesers", 8);
INSERT INTO items(arabic_name, english_name, categories_id) values("أوريو", "Oreo", 8);
INSERT INTO items(arabic_name, english_name, categories_id) values("كيت كات", "Kit Kat", 8);
INSERT INTO items(arabic_name, english_name, categories_id) values("فليك", "Flake", 8);

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


INSERT INTO item_details(item_id, size_id, price)  values(30, 1, 5);
INSERT INTO item_details(item_id, size_id, price)  values(30, 2, 8);
INSERT INTO item_details(item_id, size_id, price)  values(30, 4, 12);
INSERT INTO item_details(item_id, size_id, price)  values(31, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(31, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(31, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(32, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(32, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(32, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(33, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(33, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(33, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(34, 1, 6);
INSERT INTO item_details(item_id, size_id, price)  values(34, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(34, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(35, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(35, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(35, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(36, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(36, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(36, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(37, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(37, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(37, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(38, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(38, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(38, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(39, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(39, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(39, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(40, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(40, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(40, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(41, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(41, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(41, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(42, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(42, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(42, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(43, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(43, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(43, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(44, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(44, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(44, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(45, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(45, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(45, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(46, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(46, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(46, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(47, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(47, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(47, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(48, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(48, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(48, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(49, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(49, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(49, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(50, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(50, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(50, 4, 18);
INSERT INTO item_details(item_id, size_id, price)  values(51, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(51, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(51, 4, 18);
INSERT INTO item_details(item_id, size_id, price)  values(52, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(52, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(52, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(53, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(53, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(53, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(54, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(54, 4, 13);
INSERT INTO item_details(item_id, size_id, price)  values(55, 1, 0);
INSERT INTO item_details(item_id, size_id, price)  values(55, 2, 0);
INSERT INTO item_details(item_id, size_id, price)  values(55, 4, 0);


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

INSERT INTO item_details(item_id, size_id, price)  values(72, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(72, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(72, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(73, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(73, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(73, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(74, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(74, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(74, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(75, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(75, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(75, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(76, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(76, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(76, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(77, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(77, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(77, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(78, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(78, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(78, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(79, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(79, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(79, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(80, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(80, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(80, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(81, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(81, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(81, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(82, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(82, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(82, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(83, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(83, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(83, 4, 16);

INSERT INTO item_details(item_id, size_id, price)  values(84, 3, 13);
INSERT INTO item_details(item_id, size_id, price)  values(84, 4, 19);
INSERT INTO item_details(item_id, size_id, price)  values(85, 3, 13);
INSERT INTO item_details(item_id, size_id, price)  values(85, 4, 19);
INSERT INTO item_details(item_id, size_id, price)  values(86, 3, 13);
INSERT INTO item_details(item_id, size_id, price)  values(86, 4, 19);
INSERT INTO item_details(item_id, size_id, price)  values(87, 3, 13);
INSERT INTO item_details(item_id, size_id, price)  values(87, 4, 19);
INSERT INTO item_details(item_id, size_id, price)  values(88, 3, 13);
INSERT INTO item_details(item_id, size_id, price)  values(88, 4, 19);
INSERT INTO item_details(item_id, size_id, price)  values(89, 3, 13);
INSERT INTO item_details(item_id, size_id, price)  values(89, 4, 19);
INSERT INTO item_details(item_id, size_id, price)  values(90, 3, 16);
INSERT INTO item_details(item_id, size_id, price)  values(90, 4, 23);

INSERT INTO item_details(item_id, size_id, price)  values(91, 9, 15);
INSERT INTO item_details(item_id, size_id, price)  values(91, 10, 20);
INSERT INTO item_details(item_id, size_id, price)  values(91, 11, 24);
INSERT INTO item_details(item_id, size_id, price)  values(92, 9, 18);
INSERT INTO item_details(item_id, size_id, price)  values(92, 10, 23);
INSERT INTO item_details(item_id, size_id, price)  values(92, 11, 26);
INSERT INTO item_details(item_id, size_id, price)  values(93, 9, 17);
INSERT INTO item_details(item_id, size_id, price)  values(93, 10, 22);
INSERT INTO item_details(item_id, size_id, price)  values(93, 11, 25);


INSERT INTO item_details(item_id, size_id, price)  values(94, 1, 4);
INSERT INTO item_details(item_id, size_id, price)  values(94, 3, 8);
INSERT INTO item_details(item_id, size_id, price)  values(95, 1, 4);
INSERT INTO item_details(item_id, size_id, price)  values(95, 3, 8);
INSERT INTO item_details(item_id, size_id, price)  values(96, 1, 4);
INSERT INTO item_details(item_id, size_id, price)  values(96, 3, 8);
INSERT INTO item_details(item_id, size_id, price)  values(97, 1, 4);
INSERT INTO item_details(item_id, size_id, price)  values(97, 3, 8);
INSERT INTO item_details(item_id, size_id, price)  values(98, 1, 4);
INSERT INTO item_details(item_id, size_id, price)  values(98, 3, 8);
INSERT INTO item_details(item_id, size_id, price)  values(99, 1, 4);
INSERT INTO item_details(item_id, size_id, price)  values(99, 3, 8);


INSERT INTO item_details(item_id, size_id, price)  values(100, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(100, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(100, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(101, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(101, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(101, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(102, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(102, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(102, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(103, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(103, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(103, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(104, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(104, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(104, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(105, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(105, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(105, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(106, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(106, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(106, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(107, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(107, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(107, 4, 16);
INSERT INTO item_details(item_id, size_id, price)  values(108, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(108, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(108, 4, 16);

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
INSERT INTO components(arabic_name, english_name) values("رقي مع القطع", "Watermelon - Pieces");
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


CREATE TABLE additionals (
	id INTEGER PRIMARY KEY AUTOINCREMENT, 
	arabic_name TEXT,
	english_name TEXT,
	price INTEGER
);

INSERT INTO additionals(arabic_name, english_name, price) values("ايس كريم", "Ice cream", 1);
INSERT INTO additionals(arabic_name, english_name, price) values("مكسرات", "Mocasrat", 1);
INSERT INTO additionals(arabic_name, english_name, price) values("صوص فروالة", "Strawberry Soce", 1);
INSERT INTO additionals(arabic_name, english_name, price) values("صوص شوكولاته", "Chocolate Soce", 1);