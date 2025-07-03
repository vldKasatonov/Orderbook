#include "Order.h"
#include <stdexcept>

Order::Order(int user_id, int amount, int price, bool side)
	: user_id(user_id), amount(amount), price(price), side(side) {
	if (user_id <= 0) {
		throw std::invalid_argument("Invalid order: user_id must be positive");
	}
	if (amount <= 0) {
		throw std::invalid_argument("Invalid order: amount must be positive");
	}
	if (price <= 0) {
		throw std::invalid_argument("Invalid order: price must be positive");
	}
}

int Order::get_user_id() const {
	return user_id;
}

int Order::get_amount() const {
	return amount;
}

int Order::get_price() const {
	return price;
}

bool Order::get_side() const {
	return side;
}
