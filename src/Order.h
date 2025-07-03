#ifndef ORDER_H
#define ORDER_H

class Order {
private:
	int user_id;
	int amount;
	int price;
	bool side;
public:
	Order(int user_id, int amount, int price, bool side);

	int get_user_id() const;
	int get_amount() const;
	int get_price() const;
	bool get_side() const;
};

#endif
