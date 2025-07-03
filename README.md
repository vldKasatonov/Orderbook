# Orderbook
<h3>Technical task for Distributed Lab</h3>
This project implements a digital order book for trading UAH as the base asset against USD as the quote asset.<br>
The order book facilitates asset exchange by matching buy and sell orders based on price.<br>
It maintains two sorted lists:<br>
Sell Orders: Users selling UAH, sorted from lowest to highest price.<br>
Buy Orders: Users buying UAH, sorted from highest to lowest price.<br>
<h3>How to Run</h3>
1. Clone repository to CLion.<br>
2. Run in IDE [Shift+F10].<br>
3. Enter orders until you get bored.<br>
4. View results.<br>
   <img src="resource/results.png">
<h3>Remark</h3>
I used a priority queue that performs the basic push and pop operations with O(log n) efficiency.<br>
Thanks to this, it determines whether there is a match of orders with O(1) efficiency.
