#include <iostream>
#include "Orderbook.h"

Order read_order() {
	int user_id, amount, price;
	bool side;
	std::cin >> user_id >> amount >> price >> side;
	return {user_id, amount, price, side};
}

int main() {
	Orderbook orderbook;
	std::string choice;
	try {
		while (true) {
			std::cout << "Enter order[user_id, amount, price, side(0 for BUY, 1 for SELL)]:\n";
			Order order = read_order();
			orderbook.add_order(order);
			std::cout << "Enter \"exit\" if you want to quit:\n";
			std::cin >> choice;
			if (choice == "exit") {
				break;
			}
		}
	} catch (std::invalid_argument &e) {
		std::cout << e.what() << "\n";
	}
	return 0;
}
