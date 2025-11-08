CREATE TABLE products (
	id INT PRIMARY KEY,
	name VARCHAR(100) NOT FULL,
	price FLOAT
);
CREATE TABLE orders (
	order_id INT PRIMARY KEY,
	order_date DATE
);
CREATE TABLE order_items (
	order_item_id INT PRIMARY KEY,
	order_id INT,
	product_id INT,
	quantity INT,
	total_price FLOAT,
	FOREIGN KEY (order_id) REFERENCES orders(order_id),
	FOREIGN KEY (product_id) REFERENCES products(id)
);