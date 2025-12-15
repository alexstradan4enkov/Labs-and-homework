-- Таблицы измерений
CREATE TABLE products_dim (
    product_id INT PRIMARY KEY,
    product_name TEXT,
    category TEXT,
    price NUMERIC
);

CREATE TABLE customers_dim (
    customer_id INT PRIMARY KEY,
    customer_name TEXT,
    region TEXT
);

CREATE TABLE time_dim (
    time_id SERIAL PRIMARY KEY,
    year INT,
    quarter INT,
    month INT,
    day INT,
    day_of_week TEXT
);

-- Фактическая таблица
CREATE TABLE sales_fact (
    sale_id INT PRIMARY KEY,
    sale_date DATE,
    product_id INT REFERENCES products_dim(product_id),
    customer_id INT REFERENCES customers_dim(customer_id),
    quantity INT,
    amount NUMERIC
);

-- Индексы для ускорения запросов
CREATE INDEX idx_sales_fact_product ON sales_fact(product_id);
CREATE INDEX idx_sales_fact_customer ON sales_fact(customer_id);
CREATE INDEX idx_sales_fact_date ON sales_fact(sale_date);
CREATE INDEX idx_products_dim_category ON products_dim(category);
CREATE INDEX idx_customers_dim_region ON customers_dim(region);
