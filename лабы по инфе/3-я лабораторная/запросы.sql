SELECT * FROM products;

SELECT * FROM order_items
WHERE order_id=2;

SELECT SUM(total_price) FROM order_items
WHERE order_id=3;

SELECT 
    orders.order_id,
    orders.order_date,
    SUM(order_items.total_price) as total_amount
FROM orders
JOIN order_items ON orders.order_id = order_items.order_id
WHERE orders.order_date BETWEEN '2025-11-09' AND '2025-11-10'
GROUP BY orders.order_id, orders.order_date
ORDER BY orders.order_date;