#include "Orderbook.h"
#include <iostream>

bool Orderbook::SellOrdersComparator::operator()(const Order &a, const Order &b) const {
	return a.get_price() > b.get_price();
}

bool Orderbook::BuyOrdersComparator::operator()(const Order &a, const Order &b) const {
	return a.get_price() < b.get_price();
}

void Orderbook::match_orders() {
	while (!sell_orders.empty() && !buy_orders.empty()) {

	}
}

void Orderbook::print_last_transaction() const {
	Order order = transaction_history.back();
	std::cout << "Balance change. user_id: " << order.get_user_id() << "\n";
	if (order.get_side() == SELL) {
		std::cout << "-" << order.get_amount() * order.get_price() << " UAH\n"
				  << "+" << order.get_amount() / order.get_price() << " USD\n";
	} else {
		std::cout << "+" << order.get_amount() * order.get_price() << " UAH\n"
				  << "-" << order.get_amount() / order.get_price() << " USD\n";
	}
}

void Orderbook::add_order(const Order &order) {
	if (order.get_side() == SELL) {
		sell_orders.push(order);
	} else {
		buy_orders.push(order);
	}
	match_orders();
}
