#include "Orderbook.h"

bool Orderbook::SellOrdersComparator::operator()(const Order &a, const Order &b) const {
	return a.get_price() > b.get_price();
}

bool Orderbook::BuyOrdersComparator::operator()(const Order &a, const Order &b) const {
	return a.get_price() < b.get_price();
}

void Orderbook::match_orders() {

}

void Orderbook::add_order(const Order &order) {
	if (order.get_side()) {
		sell_orders.push(order);
	} else {
		buy_orders.push(order);
	}
}
