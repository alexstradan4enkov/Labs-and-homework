
-- Таблица товаров
CREATE TABLE products (
    id SERIAL PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    price DECIMAL(10, 2) NOT NULL,
    product_type VARCHAR(50) DEFAULT 'physical'
);

-- Таблица заказов
CREATE TABLE orders (
    order_id SERIAL PRIMARY KEY,
    order_date DATE NOT NULL DEFAULT CURRENT_DATE
);

-- Таблица позиций заказа
CREATE TABLE order_items (
    order_item_id SERIAL PRIMARY KEY,
    order_id INTEGER REFERENCES orders(order_id) ON DELETE CASCADE,
    product_id INTEGER REFERENCES products(id) ON DELETE CASCADE,
    quantity INTEGER NOT NULL CHECK (quantity > 0),
    total_price DECIMAL(10, 2) NOT NULL
);

-- Создаем индексы для ускорения
CREATE INDEX idx_order_date ON orders(order_date);
CREATE INDEX idx_product_id ON order_items(product_id);
CREATE INDEX idx_order_id ON order_items(order_id);

-- Тестовые данные
INSERT INTO products (name, price, product_type) VALUES
('Laptop', 50000.00, 'physical'),
('Keyboard', 1500.50, 'physical'),
('Windows 10 Pro', 8999.99, 'digital'),
('Book', 299.99, 'digital'),
('Headphones', 3500.00, 'physical');

INSERT INTO orders (order_date) VALUES
('2024-01-15'),
('2024-01-16'),
('2024-01-17');

INSERT INTO order_items (order_id, product_id, quantity, total_price) VALUES
(1, 1, 1, 50000.00),
(1, 3, 1, 8999.99),
(2, 2, 2, 3001.00),
(2, 5, 1, 3500.00),
(3, 4, 5, 1499.95);