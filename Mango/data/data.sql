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
INSERT INTO item_size(arabic_name, english_name) values("جالون 1.5 لتر", "Gallon 1.5L");
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

CREATE TABLE sugars (
	id 	INTEGER PRIMARY KEY AUTOINCREMENT,
	arabic_name TEXT,
	english_name TEXT
);

INSERT INTO sugars(arabic_name, english_name) values("بدون", "Without");
INSERT INTO sugars(arabic_name, english_name) values("قليل", "Less");
INSERT INTO sugars(arabic_name, english_name) values("عادي", "Normal");
INSERT INTO sugars(arabic_name, english_name) values("زيادة", "More");

CREATE TABLE orders_type (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	arabic_name TEXT,
	english_name TEXT
);

INSERT INTO orders_type(arabic_name, english_name) values("كاش", "Cash");
INSERT INTO orders_type(arabic_name, english_name) values("كوبون", "Cupon");
INSERT INTO orders_type(arabic_name, english_name) values("خصم", "Discount");
INSERT INTO orders_type(arabic_name, english_name) values("مجاني", "Free");

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
	sugar_id INTEGER,
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

-- Fresh JUICES عصائر الطازجة
-- from id 1 to id 29
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

-- Cocktails الكوكتيلات
-- from id 30 to id 55
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

-- Special Dishes الأطباق المميزة
-- from id 56 to id 71
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

-- Speical Cocktial سبيشال كوكتيل
-- from id 72 to id 83
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

-- Red Bull ريد بول
-- from id 84 to id 90
INSERT INTO items(arabic_name, english_name, categories_id) values("ريد بول رمان", "Red Bull Pomegranate", 5);
INSERT INTO items(arabic_name, english_name, categories_id) values("ريد بول فراولة", "Red Bull Strawberry", 5);
INSERT INTO items(arabic_name, english_name, categories_id) values("ريد بول ليمون", "Red Bull Lemon", 5);
INSERT INTO items(arabic_name, english_name, categories_id) values("ريد بول توت", "Red Bull Barries", 5);
INSERT INTO items(arabic_name, english_name, categories_id) values("ريد بول كرز", "Red Bull Cherries", 5);
INSERT INTO items(arabic_name, english_name, categories_id) values("ريد بول مكس", "Red Bull Mix", 5);
INSERT INTO items(arabic_name, english_name, categories_id) values("ريد بول هلالي - سلاش", "Red Bull Hilaly - Slash", 5);

-- Frozen Yogurt فروزون يوغورت
-- from id 91 to id 93
INSERT INTO items(arabic_name, english_name, categories_id) values("أبيض", "White", 6);
INSERT INTO items(arabic_name, english_name, categories_id) values("وردي", "Pink", 6);
INSERT INTO items(arabic_name, english_name, categories_id) values("مكس", "Mix", 6);

-- Ice Cream آيس كريم
-- from id 94 to id 99
INSERT INTO items(arabic_name, english_name, categories_id) values("مانجو", "Mango", 7);
INSERT INTO items(arabic_name, english_name, categories_id) values("فروالة", "Strawberry", 7);
INSERT INTO items(arabic_name, english_name, categories_id) values("شوكولاته", "Chocolate", 7);
INSERT INTO items(arabic_name, english_name, categories_id) values("فستق", "Pistachio", 7);
INSERT INTO items(arabic_name, english_name, categories_id) values("ليمون", "Lemon", 7);
INSERT INTO items(arabic_name, english_name, categories_id) values("فانيلا", "Vanilla", 7);

-- Milk Shake ميلك شيك
-- from id 95 to id 108
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

-- Fresh JUICES عصائر الطازجة
-- item from id 1 to id 29
INSERT INTO item_details(item_id, size_id, price) values(1, 1, 8);
INSERT INTO item_details(item_id, size_id, price) values(1, 2, 13);
INSERT INTO item_details(item_id, size_id, price) values(1, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(1, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(1, 7, 60);
INSERT INTO item_details(item_id, size_id, price) values(2, 1, 8);
INSERT INTO item_details(item_id, size_id, price) values(2, 2, 13);
INSERT INTO item_details(item_id, size_id, price) values(2, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(2, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(2, 7, 60);
INSERT INTO item_details(item_id, size_id, price) values(3, 1, 5);
INSERT INTO item_details(item_id, size_id, price)  values(3, 2, 8);
INSERT INTO item_details(item_id, size_id, price)  values(3, 4, 12);
INSERT INTO item_details(item_id, size_id, price) values(3, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(3, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(4, 1, 5);
INSERT INTO item_details(item_id, size_id, price)  values(4, 2, 8);
INSERT INTO item_details(item_id, size_id, price)  values(4, 4, 12);
INSERT INTO item_details(item_id, size_id, price) values(4, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(4, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(5, 1, 5);
INSERT INTO item_details(item_id, size_id, price)  values(5, 2, 9);
INSERT INTO item_details(item_id, size_id, price)  values(5, 4, 13);
INSERT INTO item_details(item_id, size_id, price) values(5, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(5, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(6, 1, 5);
INSERT INTO item_details(item_id, size_id, price)  values(6, 2, 9);
INSERT INTO item_details(item_id, size_id, price)  values(6, 4, 13);
INSERT INTO item_details(item_id, size_id, price) values(6, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(6, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(7, 1, 5);
INSERT INTO item_details(item_id, size_id, price)  values(7, 2, 9);
INSERT INTO item_details(item_id, size_id, price)  values(7, 4, 13);
INSERT INTO item_details(item_id, size_id, price) values(7, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(7, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(8, 1, 5);
INSERT INTO item_details(item_id, size_id, price)  values(8, 2, 9);
INSERT INTO item_details(item_id, size_id, price)  values(8, 4, 13);
INSERT INTO item_details(item_id, size_id, price) values(8, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(8, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(9, 1, 5);
INSERT INTO item_details(item_id, size_id, price)  values(9, 2, 8);
INSERT INTO item_details(item_id, size_id, price)  values(9, 4, 12);
INSERT INTO item_details(item_id, size_id, price) values(9, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(9, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(10, 1, 6);
INSERT INTO item_details(item_id, size_id, price)  values(10, 2, 9);
INSERT INTO item_details(item_id, size_id, price)  values(10, 4, 13);
INSERT INTO item_details(item_id, size_id, price) values(10, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(10, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(11, 1, 6);
INSERT INTO item_details(item_id, size_id, price)  values(11, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(11, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(11, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(11, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(12, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(12, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(12, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(12, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(12, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(13, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(13, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(13, 4, 18);
INSERT INTO item_details(item_id, size_id, price) values(13, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(13, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(14, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(14, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(14, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(14, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(14, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(15, 1, 6);
INSERT INTO item_details(item_id, size_id, price)  values(15, 2, 12);
INSERT INTO item_details(item_id, size_id, price)  values(15, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(15, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(15, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(16, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(16, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(16, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(16, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(16, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(17, 1, 6);
INSERT INTO item_details(item_id, size_id, price)  values(17, 2, 12);
INSERT INTO item_details(item_id, size_id, price)  values(17, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(17, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(17, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(18, 1, 6);
INSERT INTO item_details(item_id, size_id, price)  values(18, 2, 12);
INSERT INTO item_details(item_id, size_id, price)  values(18, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(18, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(18, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(19, 1, 6);
INSERT INTO item_details(item_id, size_id, price)  values(19, 2, 12);
INSERT INTO item_details(item_id, size_id, price)  values(19, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(19, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(19, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(20, 1, 6);
INSERT INTO item_details(item_id, size_id, price)  values(20, 2, 12);
INSERT INTO item_details(item_id, size_id, price)  values(20, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(20, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(20, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(21, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(21, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(21, 4, 18);
INSERT INTO item_details(item_id, size_id, price) values(21, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(21, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(22, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(22, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(22, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(22, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(22, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(23, 1, 6);
INSERT INTO item_details(item_id, size_id, price)  values(23, 2, 12);
INSERT INTO item_details(item_id, size_id, price)  values(23, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(23, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(23, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(24, 1, 6);
INSERT INTO item_details(item_id, size_id, price)  values(24, 2, 9);
INSERT INTO item_details(item_id, size_id, price)  values(24, 4, 13);
INSERT INTO item_details(item_id, size_id, price) values(24, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(24, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(25, 1, 4);
INSERT INTO item_details(item_id, size_id, price)  values(25, 2, 6);
INSERT INTO item_details(item_id, size_id, price)  values(25, 4, 9);
INSERT INTO item_details(item_id, size_id, price) values(25, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(25, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(26, 1, 3);
INSERT INTO item_details(item_id, size_id, price)  values(26, 2, 6);
INSERT INTO item_details(item_id, size_id, price)  values(26, 4, 9);
INSERT INTO item_details(item_id, size_id, price) values(26, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(26, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(27, 1, 5);
INSERT INTO item_details(item_id, size_id, price)  values(27, 2, 9);
INSERT INTO item_details(item_id, size_id, price)  values(27, 4, 13);
INSERT INTO item_details(item_id, size_id, price) values(27, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(27, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(28, 1, 4);
INSERT INTO item_details(item_id, size_id, price)  values(28, 2, 9);
INSERT INTO item_details(item_id, size_id, price)  values(28, 4, 13);
INSERT INTO item_details(item_id, size_id, price) values(28, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(28, 7, 60);
INSERT INTO item_details(item_id, size_id, price)  values(29, 1, 4);
INSERT INTO item_details(item_id, size_id, price)  values(29, 2, 9);
INSERT INTO item_details(item_id, size_id, price)  values(29, 4, 13);
INSERT INTO item_details(item_id, size_id, price) values(29, 6, 20);
INSERT INTO item_details(item_id, size_id, price) values(29, 7, 60);

-- Cocktails الكوكتيلات
-- from id 30 to id 55
INSERT INTO item_details(item_id, size_id, price)  values(30, 1, 5);
INSERT INTO item_details(item_id, size_id, price)  values(30, 2, 8);
INSERT INTO item_details(item_id, size_id, price)  values(30, 4, 12);
INSERT INTO item_details(item_id, size_id, price) values(30, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(30, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(31, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(31, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(31, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(31, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(31, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(32, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(32, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(32, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(32, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(32, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(33, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(33, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(33, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(33, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(33, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(34, 1, 6);
INSERT INTO item_details(item_id, size_id, price)  values(34, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(34, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(34, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(34, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(35, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(35, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(35, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(35, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(35, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(36, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(36, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(36, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(36, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(36, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(37, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(37, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(37, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(37, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(37, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(38, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(38, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(38, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(38, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(38, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(39, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(39, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(39, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(39, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(39, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(40, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(40, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(40, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(40, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(40, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(41, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(41, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(41, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(41, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(41, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(42, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(42, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(42, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(42, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(42, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(43, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(43, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(43, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(43, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(43, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(44, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(44, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(44, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(44, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(44, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(45, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(45, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(45, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(45, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(45, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(46, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(46, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(46, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(46, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(46, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(47, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(47, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(47, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(47, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(47, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(48, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(48, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(48, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(48, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(48, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(49, 1, 7);
INSERT INTO item_details(item_id, size_id, price)  values(49, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(49, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(49, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(49, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(50, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(50, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(50, 4, 18);
INSERT INTO item_details(item_id, size_id, price) values(50, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(50, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(51, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(51, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(51, 4, 18);
INSERT INTO item_details(item_id, size_id, price) values(51, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(51, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(52, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(52, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(52, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(52, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(52, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(53, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(53, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(53, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(53, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(53, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(54, 2, 11);
INSERT INTO item_details(item_id, size_id, price)  values(54, 4, 13);
INSERT INTO item_details(item_id, size_id, price) values(54, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(54, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(55, 1, 0);
INSERT INTO item_details(item_id, size_id, price)  values(55, 2, 0);
INSERT INTO item_details(item_id, size_id, price)  values(55, 4, 0);
INSERT INTO item_details(item_id, size_id, price) values(55, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(55, 7, 90);

-- Special Dishes الأطباق المميزة
-- from id 56 to id 71
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

-- Speical Cocktial سبيشال كوكتيل
-- from id 72 to id 83
INSERT INTO item_details(item_id, size_id, price)  values(72, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(72, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(72, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(72, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(72, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(73, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(73, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(73, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(73, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(73, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(74, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(74, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(74, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(74, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(74, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(75, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(75, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(75, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(75, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(75, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(76, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(76, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(76, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(76, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(76, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(77, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(77, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(77, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(77, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(77, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(78, 1, 10);
INSERT INTO item_details(item_id, size_id, price)  values(78, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(78, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(78, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(78, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(79, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(79, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(79, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(79, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(79, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(80, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(80, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(80, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(80, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(80, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(81, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(81, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(81, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(81, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(81, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(82, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(82, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(82, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(82, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(82, 7, 90);
INSERT INTO item_details(item_id, size_id, price)  values(83, 1, 8);
INSERT INTO item_details(item_id, size_id, price)  values(83, 2, 13);
INSERT INTO item_details(item_id, size_id, price)  values(83, 4, 16);
INSERT INTO item_details(item_id, size_id, price) values(83, 6, 30);
INSERT INTO item_details(item_id, size_id, price) values(83, 7, 90);

-- Red Bull ريد بول
-- from id 84 to id 90
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

-- Frozen Yogurt فروزون يوغورت
-- from id 91 to id 93
INSERT INTO item_details(item_id, size_id, price)  values(91, 9, 15);
INSERT INTO item_details(item_id, size_id, price)  values(91, 10, 20);
INSERT INTO item_details(item_id, size_id, price)  values(91, 11, 24);
INSERT INTO item_details(item_id, size_id, price)  values(92, 9, 18);
INSERT INTO item_details(item_id, size_id, price)  values(92, 10, 23);
INSERT INTO item_details(item_id, size_id, price)  values(92, 11, 26);
INSERT INTO item_details(item_id, size_id, price)  values(93, 9, 17);
INSERT INTO item_details(item_id, size_id, price)  values(93, 10, 22);
INSERT INTO item_details(item_id, size_id, price)  values(93, 11, 25);

-- Ice Cream آيس كريم
-- from id 94 to id 99
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

-- Milk Shake ميلك شيك
-- from id 95 to id 108
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

-- components id from 1 to 24
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
INSERT INTO components(arabic_name, english_name) values("عنب", "Grapes");
INSERT INTO components(arabic_name, english_name) values("جوافه", "Guava");

-- this price for any compoenent, used in special cocktail
CREATE TABLE component_price (
	id 	INTEGER PRIMARY KEY AUTOINCREMENT,
	component_id INTEGER,
	size_id INTEGER,
	price INTEGER
);

INSERT INTO component_price(component_id, size_id, price)  values(1, 1, 8);
INSERT INTO component_price(component_id, size_id, price)  values(1, 2, 13);
INSERT INTO component_price(component_id, size_id, price)  values(1, 4, 16);
INSERT INTO component_price(component_id, size_id, price)  values(2, 1, 8);
INSERT INTO component_price(component_id, size_id, price)  values(2, 2, 13);
INSERT INTO component_price(component_id, size_id, price)  values(2, 4, 16);
INSERT INTO component_price(component_id, size_id, price)  values(3, 1, 5);
INSERT INTO component_price(component_id, size_id, price)  values(3, 2, 8);
INSERT INTO component_price(component_id, size_id, price)  values(3, 4, 12);
INSERT INTO component_price(component_id, size_id, price)  values(4, 1, 5);
INSERT INTO component_price(component_id, size_id, price)  values(4, 2, 8);
INSERT INTO component_price(component_id, size_id, price)  values(4, 4, 12);
INSERT INTO component_price(component_id, size_id, price)  values(5, 1, 5);
INSERT INTO component_price(component_id, size_id, price)  values(5, 2, 8);
INSERT INTO component_price(component_id, size_id, price)  values(5, 4, 12);
INSERT INTO component_price(component_id, size_id, price)  values(6, 1, 5);
INSERT INTO component_price(component_id, size_id, price)  values(6, 2, 8);
INSERT INTO component_price(component_id, size_id, price)  values(6, 4, 12);
INSERT INTO component_price(component_id, size_id, price)  values(7, 1, 5);
INSERT INTO component_price(component_id, size_id, price)  values(7, 2, 9);
INSERT INTO component_price(component_id, size_id, price)  values(7, 4, 13);
INSERT INTO component_price(component_id, size_id, price)  values(8, 1, 5);
INSERT INTO component_price(component_id, size_id, price)  values(8, 2, 9);
INSERT INTO component_price(component_id, size_id, price)  values(8, 4, 13);
INSERT INTO component_price(component_id, size_id, price)  values(9, 1, 5);
INSERT INTO component_price(component_id, size_id, price)  values(9, 2, 8);
INSERT INTO component_price(component_id, size_id, price)  values(9, 4, 12);
INSERT INTO component_price(component_id, size_id, price)  values(10, 1, 6);
INSERT INTO component_price(component_id, size_id, price)  values(10, 2, 9);
INSERT INTO component_price(component_id, size_id, price)  values(10, 4, 13);
INSERT INTO component_price(component_id, size_id, price)  values(11, 1, 8);
INSERT INTO component_price(component_id, size_id, price)  values(11, 2, 11);
INSERT INTO component_price(component_id, size_id, price)  values(11, 4, 16);
INSERT INTO component_price(component_id, size_id, price)  values(12, 1, 10);
INSERT INTO component_price(component_id, size_id, price)  values(12, 2, 13);
INSERT INTO component_price(component_id, size_id, price)  values(12, 4, 18);
INSERT INTO component_price(component_id, size_id, price)  values(13, 1, 6);
INSERT INTO component_price(component_id, size_id, price)  values(13, 2, 13);
INSERT INTO component_price(component_id, size_id, price)  values(13, 4, 16);
INSERT INTO component_price(component_id, size_id, price)  values(14, 1, 8);
INSERT INTO component_price(component_id, size_id, price)  values(14, 2, 13);
INSERT INTO component_price(component_id, size_id, price)  values(14, 4, 16);
INSERT INTO component_price(component_id, size_id, price)  values(15, 1, 6);
INSERT INTO component_price(component_id, size_id, price)  values(15, 2, 12);
INSERT INTO component_price(component_id, size_id, price)  values(15, 4, 16);
INSERT INTO component_price(component_id, size_id, price)  values(16, 1, 6);
INSERT INTO component_price(component_id, size_id, price)  values(16, 2, 9);
INSERT INTO component_price(component_id, size_id, price)  values(16, 4, 13);
INSERT INTO component_price(component_id, size_id, price)  values(17, 1, 5);
INSERT INTO component_price(component_id, size_id, price)  values(17, 2, 8);
INSERT INTO component_price(component_id, size_id, price)  values(17, 4, 12);
INSERT INTO component_price(component_id, size_id, price)  values(18, 1, 10);
INSERT INTO component_price(component_id, size_id, price)  values(18, 2, 13);
INSERT INTO component_price(component_id, size_id, price)  values(18, 4, 18);
INSERT INTO component_price(component_id, size_id, price)  values(19, 1, 6);
INSERT INTO component_price(component_id, size_id, price)  values(19, 2, 12);
INSERT INTO component_price(component_id, size_id, price)  values(19, 4, 16);
INSERT INTO component_price(component_id, size_id, price)  values(20, 1, 5);
INSERT INTO component_price(component_id, size_id, price)  values(20, 2, 9);
INSERT INTO component_price(component_id, size_id, price)  values(20, 4, 13);
INSERT INTO component_price(component_id, size_id, price)  values(21, 1, 8);
INSERT INTO component_price(component_id, size_id, price)  values(21, 2, 13);
INSERT INTO component_price(component_id, size_id, price)  values(21, 4, 16);
INSERT INTO component_price(component_id, size_id, price)  values(22, 1, 5);
INSERT INTO component_price(component_id, size_id, price)  values(22, 2, 8);
INSERT INTO component_price(component_id, size_id, price)  values(22, 4, 12);
INSERT INTO component_price(component_id, size_id, price)  values(23, 1, 10);
INSERT INTO component_price(component_id, size_id, price)  values(23, 2, 13);
INSERT INTO component_price(component_id, size_id, price)  values(23, 4, 16);
INSERT INTO component_price(component_id, size_id, price)  values(24, 1, 6);
INSERT INTO component_price(component_id, size_id, price)  values(24, 2, 12);
INSERT INTO component_price(component_id, size_id, price)  values(24, 4, 16);

CREATE TABLE item_components (
	id 	INTEGER PRIMARY KEY AUTOINCREMENT,
	item_id INTEGER, 
	component_id INTEGER
);

-- Components in Cocktails الكوكتيلات
-- from id 30 to id 55 - except 55 is special with no components
INSERT INTO item_components(item_id, component_id)  values(30,1);
INSERT INTO item_components(item_id, component_id)  values(30,2);
INSERT INTO item_components(item_id, component_id)  values(30,3);
INSERT INTO item_components(item_id, component_id)  values(31, 1);
INSERT INTO item_components(item_id, component_id)  values(31, 2);
INSERT INTO item_components(item_id, component_id)  values(31, 4);
INSERT INTO item_components(item_id, component_id)  values(32, 5);
INSERT INTO item_components(item_id, component_id)  values(32, 1);
INSERT INTO item_components(item_id, component_id)  values(32, 6);
INSERT INTO item_components(item_id, component_id)  values(33, 1);
INSERT INTO item_components(item_id, component_id)  values(33, 2);
INSERT INTO item_components(item_id, component_id)  values(33, 7);
INSERT INTO item_components(item_id, component_id)  values(33, 8);
INSERT INTO item_components(item_id, component_id)  values(33, 9);
INSERT INTO item_components(item_id, component_id)  values(34, 10);
INSERT INTO item_components(item_id, component_id)  values(34, 8);
INSERT INTO item_components(item_id, component_id)  values(34, 7);
INSERT INTO item_components(item_id, component_id)  values(35, 1);
INSERT INTO item_components(item_id, component_id)  values(35, 2);
INSERT INTO item_components(item_id, component_id)  values(35, 9);
INSERT INTO item_components(item_id, component_id)  values(36, 1);
INSERT INTO item_components(item_id, component_id)  values(36, 4);
INSERT INTO item_components(item_id, component_id)  values(36, 9);
INSERT INTO item_components(item_id, component_id)  values(37, 1);
INSERT INTO item_components(item_id, component_id)  values(37, 2);
INSERT INTO item_components(item_id, component_id)  values(37, 4);
INSERT INTO item_components(item_id, component_id)  values(37, 9);
INSERT INTO item_components(item_id, component_id)  values(38, 11);
INSERT INTO item_components(item_id, component_id)  values(39, 12);
INSERT INTO item_components(item_id, component_id)  values(39, 4);
INSERT INTO item_components(item_id, component_id)  values(39, 2);
INSERT INTO item_components(item_id, component_id)  values(40, 2);
INSERT INTO item_components(item_id, component_id)  values(40, 13);
INSERT INTO item_components(item_id, component_id)  values(40, 8);
INSERT INTO item_components(item_id, component_id)  values(40, 4);
INSERT INTO item_components(item_id, component_id)  values(41, 10);
INSERT INTO item_components(item_id, component_id)  values(41, 1);
INSERT INTO item_components(item_id, component_id)  values(41, 6);
INSERT INTO item_components(item_id, component_id)  values(42, 14);
INSERT INTO item_components(item_id, component_id)  values(42, 4);
INSERT INTO item_components(item_id, component_id)  values(42, 13);
INSERT INTO item_components(item_id, component_id)  values(42, 2);
INSERT INTO item_components(item_id, component_id)  values(43, 8);
INSERT INTO item_components(item_id, component_id)  values(43, 1);
INSERT INTO item_components(item_id, component_id)  values(43, 2);
INSERT INTO item_components(item_id, component_id)  values(43, 5);
INSERT INTO item_components(item_id, component_id)  values(44, 2);
INSERT INTO item_components(item_id, component_id)  values(44, 8);
INSERT INTO item_components(item_id, component_id)  values(44, 10);
INSERT INTO item_components(item_id, component_id)  values(44, 4);
INSERT INTO item_components(item_id, component_id)  values(45, 10);
INSERT INTO item_components(item_id, component_id)  values(45, 13);
INSERT INTO item_components(item_id, component_id)  values(45, 12);
INSERT INTO item_components(item_id, component_id)  values(45, 1);
INSERT INTO item_components(item_id, component_id)  values(46, 15);
INSERT INTO item_components(item_id, component_id)  values(46, 13);
INSERT INTO item_components(item_id, component_id)  values(46, 16);
INSERT INTO item_components(item_id, component_id)  values(47, 1);
INSERT INTO item_components(item_id, component_id)  values(47, 14);
INSERT INTO item_components(item_id, component_id)  values(47, 17);
INSERT INTO item_components(item_id, component_id)  values(47, 12);
INSERT INTO item_components(item_id, component_id)  values(48, 13);
INSERT INTO item_components(item_id, component_id)  values(48, 15);
INSERT INTO item_components(item_id, component_id)  values(49, 7);
INSERT INTO item_components(item_id, component_id)  values(49, 8);
INSERT INTO item_components(item_id, component_id)  values(49, 13);
INSERT INTO item_components(item_id, component_id)  values(50, 18);
INSERT INTO item_components(item_id, component_id)  values(50, 1);
INSERT INTO item_components(item_id, component_id)  values(50, 9);
INSERT INTO item_components(item_id, component_id)  values(50, 2);
INSERT INTO item_components(item_id, component_id)  values(51, 18);
INSERT INTO item_components(item_id, component_id)  values(51, 1);
INSERT INTO item_components(item_id, component_id)  values(51, 2);
INSERT INTO item_components(item_id, component_id)  values(51, 15);
INSERT INTO item_components(item_id, component_id)  values(52, 19);
INSERT INTO item_components(item_id, component_id)  values(52, 9);
INSERT INTO item_components(item_id, component_id)  values(53, 13);
INSERT INTO item_components(item_id, component_id)  values(53, 8);
INSERT INTO item_components(item_id, component_id)  values(53, 20);
INSERT INTO item_components(item_id, component_id)  values(53, 21);
INSERT INTO item_components(item_id, component_id)  values(54, 12);
INSERT INTO item_components(item_id, component_id)  values(54, 2);
INSERT INTO item_components(item_id, component_id)  values(54, 21);
INSERT INTO item_components(item_id, component_id)  values(54, 22);

-- Components in Speical Cocktial سبيشال كوكتيل
-- from id 72 to id 83
INSERT INTO item_components(item_id, component_id)  values(72, 1);
INSERT INTO item_components(item_id, component_id)  values(72, 24);
INSERT INTO item_components(item_id, component_id)  values(72, 2);
INSERT INTO item_components(item_id, component_id)  values(72, 15);
INSERT INTO item_components(item_id, component_id)  values(73, 4);
INSERT INTO item_components(item_id, component_id)  values(73, 8);
INSERT INTO item_components(item_id, component_id)  values(73, 2);
INSERT INTO item_components(item_id, component_id)  values(74, 13);
INSERT INTO item_components(item_id, component_id)  values(74, 6);
INSERT INTO item_components(item_id, component_id)  values(74, 17);
INSERT INTO item_components(item_id, component_id)  values(75, 4);
INSERT INTO item_components(item_id, component_id)  values(75, 21);
INSERT INTO item_components(item_id, component_id)  values(75, 6);
INSERT INTO item_components(item_id, component_id)  values(76, 13);
INSERT INTO item_components(item_id, component_id)  values(76, 21);
INSERT INTO item_components(item_id, component_id)  values(76, 6);
INSERT INTO item_components(item_id, component_id)  values(77, 23);
INSERT INTO item_components(item_id, component_id)  values(77, 24);
INSERT INTO item_components(item_id, component_id)  values(78, 10);
INSERT INTO item_components(item_id, component_id)  values(78, 19);
INSERT INTO item_components(item_id, component_id)  values(78, 13);
INSERT INTO item_components(item_id, component_id)  values(79, 8);
INSERT INTO item_components(item_id, component_id)  values(79, 13);
INSERT INTO item_components(item_id, component_id)  values(79, 24);
INSERT INTO item_components(item_id, component_id)  values(79, 1);
INSERT INTO item_components(item_id, component_id)  values(80, 1);
INSERT INTO item_components(item_id, component_id)  values(80, 2);
INSERT INTO item_components(item_id, component_id)  values(80, 4);
INSERT INTO item_components(item_id, component_id)  values(80, 24);
INSERT INTO item_components(item_id, component_id)  values(81, 3);
INSERT INTO item_components(item_id, component_id)  values(81, 19);
INSERT INTO item_components(item_id, component_id)  values(82, 21);
INSERT INTO item_components(item_id, component_id)  values(82, 24);
INSERT INTO item_components(item_id, component_id)  values(83, 1);
INSERT INTO item_components(item_id, component_id)  values(83, 2);
INSERT INTO item_components(item_id, component_id)  values(83, 12);
INSERT INTO item_components(item_id, component_id)  values(83, 9);

CREATE TABLE additionals (
	id INTEGER PRIMARY KEY AUTOINCREMENT, 
	arabic_name TEXT,
	english_name TEXT,
	price INTEGER
);

-- additionals id from 1 to 4
INSERT INTO additionals(arabic_name, english_name, price) values("ايس كريم", "Ice cream", 1);
INSERT INTO additionals(arabic_name, english_name, price) values("مكسرات", "Mocasrat", 1);
INSERT INTO additionals(arabic_name, english_name, price) values("صوص فروالة", "Strawberry Soce", 1);
INSERT INTO additionals(arabic_name, english_name, price) values("صوص شوكولاته", "Chocolate Soce", 1);