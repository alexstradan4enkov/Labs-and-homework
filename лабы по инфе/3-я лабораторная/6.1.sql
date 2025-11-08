SELECT 
    products.name,
    SUM(order_items.quantity) as total_sold
FROM products
JOIN order_items ON products.id = order_items.product_id
JOIN orders ON order_items.order_id = orders.order_id
WHERE orders.order_date BETWEEN '2025-11-08' AND '2025-11-10'
GROUP BY products.id, products.name
ORDER BY total_sold DESC;