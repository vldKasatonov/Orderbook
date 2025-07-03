#include "Orderbook.h"
#include <iostream>

bool Orderbook::SellOrdersComparator::operator()(const Order &a, const Order &b) const {
	return a.get_price() > b.get_price();
}

bool Orderbook::BuyOrdersComparator::operator()(const Order &a, const Order &b) const {
	return a.get_price() < b.get_price();
}

void Orderbook::match_orders() {

}

void Orderbook::print_transaction() const {
	Order order = transaction_history.back();
	std::cout << "Balance change. user_id: " << order.get_user_id() << ", ";
	if (order.get_side()) {
		std::cout << "+" << order.get_amount() / order.get_price() << " USD";
	} else {
		std::cout << "-" << order.get_amount() * order.get_price() << " UAH";
	}
	std::cout << "\n";
}

void Orderbook::add_order(const Order &order) {
	if (order.get_side()) {
		sell_orders.push(order);
	} else {
		buy_orders.push(order);
	}
}
