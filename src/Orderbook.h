#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "Order.h"
#include <queue>
#include <vector>

enum Side {
	SELL = 1,
	BUY = 0
};

class Orderbook {
private:
	class SellOrdersComparator {
		public:
			bool operator()(const Order &a, const Order &b) const;
	};
	class BuyOrdersComparator {
		public:
			bool operator()(const Order &a, const Order &b) const;
	};

	std::priority_queue<Order, std::vector<Order>, SellOrdersComparator> sell_orders;
	std::priority_queue<Order, std::vector<Order>, BuyOrdersComparator> buy_orders;
	std::vector<Order> transaction_history;

public:
	void match_orders();
	void print_last_transaction() const;
	void add_order(const Order &order);
};

#endif
