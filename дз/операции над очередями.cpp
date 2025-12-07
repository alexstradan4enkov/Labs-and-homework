#include <iostream>
#include <queue>
#include <string>
#include <vector>

// 1)

// функция добавления человека в очередь
void addToQueue(std::queue<std::string>& queue, const std::string& person) {
    queue.push(person);
    std::cout << person << " встал(а) в очередь." << std::endl;
}

// функция обработки первого человека в очереди
void processQueue(std::queue<std::string>& queue) {
    if (queue.empty()) {
        std::cout << "Очередь пуста. Некого обрабатывать." << std::endl;
        return;
    }

    std::string person = queue.front();
    queue.pop();
    std::cout << person << " обслужен(а) и покинул(а) очередь." << std::endl;
}

//2)

// функция добавления события в очередь
void addEvent(std::queue<std::string>& eventQueue, const std::string& event) {
    eventQueue.push(event);
    std::cout << "Добавлено событие: " << event << std::endl;
}

// функция обработки событий из очереди
void processEvents(std::queue<std::string>& eventQueue) {
    if (eventQueue.empty()) {
        std::cout << "Очередь событий пуста." << std::endl;
        return;
    }

    std::string event = eventQueue.front();
    eventQueue.pop();
    std::cout << "Обрабатывается событие: " << event << std::endl;
}

//3)

// структура для хранения информации о заказе
struct Order {
    std::string customerName;
    std::vector<std::string> items;

    // конструктор для удобного создания заказов
    Order(const std::string& name, const std::vector<std::string>& orderItems)
        : customerName(name), items(orderItems) {
    }

    // метод для вывода информации о заказе
    void print() const {
        std::cout << "Заказ от: " << customerName << std::endl;
        std::cout << "Товары: ";
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << items[i];
            if (i < items.size() - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }
};

// функция добавления заказа в очередь
void addOrder(std::queue<Order>& orderQueue, const Order& newOrder) {
    orderQueue.push(newOrder);
    std::cout << "Заказ добавлен в очередь: ";
    newOrder.print();
}

// функция обработки заказа из очереди
void processOrder(std::queue<Order>& orderQueue) {
    if (orderQueue.empty()) {
        std::cout << "Очередь заказов пуста." << std::endl;
        return;
    }

    Order order = orderQueue.front();
    orderQueue.pop();
    std::cout << "Обрабатывается заказ: ";
    order.print();
}

// 

int main() {
    std::cout << "первая задача" << std::endl;
    std::queue<std::string> shopQueue;

    addToQueue(shopQueue, "Иван");
    addToQueue(shopQueue, "Мария");
    addToQueue(shopQueue, "Алексей");

    processQueue(shopQueue);
    processQueue(shopQueue);
    processQueue(shopQueue);
    processQueue(shopQueue); // Попытка обработать пустую очередь

    std::cout << "\n вторая задача" << std::endl;
    std::queue<std::string> eventQueue;

    addEvent(eventQueue, "Запрос на авторизацию от клиента 192.168.1.1");
    addEvent(eventQueue, "Запрос данных от пользователя user123");
    addEvent(eventQueue, "Ошибка соединения с базой данных");

    processEvents(eventQueue);
    processEvents(eventQueue);
    processEvents(eventQueue);
    processEvents(eventQueue); // Попытка обработать пустую очередь

    std::cout << "\n третья задача" << std::endl;
    std::queue<Order> orderQueue;

    // создаем несколько заказов
    Order order1("Петров Иван", { "Ноутбук", "Мышка", "Чехол" });
    Order order2("Сидорова Анна", { "Книга", "Ручка" });
    Order order3("Кузнецов Сергей", { "Телефон", "Наушники", "Зарядное устройство", "Чехол" });

    // добавляем заказы в очередь
    addOrder(orderQueue, order1);
    addOrder(orderQueue, order2);
    addOrder(orderQueue, order3);

    // обрабатываем заказы
    processOrder(orderQueue);
    processOrder(orderQueue);
    processOrder(orderQueue);
    processOrder(orderQueue); // попытка обработать пустую очередь

    return 0;
}
