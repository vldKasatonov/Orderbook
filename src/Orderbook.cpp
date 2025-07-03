#include "Orderbook.h"
#include <algorithm>
#include <iostream>

bool Orderbook::SellOrdersComparator::operator()(const Order &a, const Order &b) const {
	return a.get_price() > b.get_price();
}

bool Orderbook::BuyOrdersComparator::operator()(const Order &a, const Order &b) const {
	return a.get_price() < b.get_price();
}

void Orderbook::match_orders() {
	while (!sell_orders.empty() && !buy_orders.empty()) {
		Order sell_order = sell_orders.top();
		Order buy_order = buy_orders.top();
		if (sell_order.get_price() <= buy_order.get_price()) {
			int match_amount = std::min(sell_order.get_amount(),
										buy_order.get_amount());
			int match_price = sell_order.get_price();
			transaction_history.emplace_back(sell_order.get_user_id(), match_amount,
											 match_price, SELL);
			sell_orders.pop();
			print_last_transaction();
			transaction_history.emplace_back(buy_order.get_user_id(), match_amount,
											 match_price, BUY);
			buy_orders.pop();
			print_last_transaction();
		} else {
			return;
		}
	}
}

void Orderbook::print_last_transaction() const {
	Order order = transaction_history.back();
	std::cout << "Balance change. user_id: " << order.get_user_id() << "\n";
	if (order.get_side() == SELL) {
		std::cout << "-" << order.get_amount() << " UAH\n"
				  << "+" << order.get_amount() * order.get_price() << " USD\n";
	} else {
		std::cout << "+" << order.get_amount() << " UAH\n"
				  << "-" << order.get_amount() * order.get_price() << " USD\n";
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
