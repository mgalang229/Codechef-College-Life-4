#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		long long items, eggs, chocolates, omeletteCost, milkshakeCost, cakeCost;
		cin >> items >> eggs >> chocolates >> omeletteCost >> milkshakeCost >> cakeCost;
		// create an 'ans' variable to get the minimum price (if it's possible)
		long long ans = 1e18;
		for (int cakes = 0; cakes <= items; cakes++) {
			// check if the eggs or chocolates cannot accommodate the creation of cakes
			if (eggs < cakes || chocolates < cakes) {
				break;
			}
			// this is the equation for the finding the number of omelettes that can be made
			// that are dependent on the numer of cakes that will be created
			long long omelettes = (eggs - cakes) / 2;
			// this is the equation for the finding the number of milkshakes that can be made
			// that are dependent on the numer of cakes that will be created
			long long milkshakes = (chocolates - cakes) / 3;
			// if the total number of cakes, omelettes, and milkshakes cannot accommodate
			// the total number of items needed, then skip this iteration
			if (cakes + omelettes + milkshakes < items) {
				continue;
			}
			// set two variables to store the number of omelettes or milkshakes
			// that will be ordered based on their costs that are also dependent
			// on the number of cakes that will be created
			long long omelettesReq = 0;
			long long milkshakesReq = 0;
			if (omeletteCost < milkshakeCost) {
				// if the cost of the omelettes are less than the cost of the milkshakes
				// then prioritize on making the number of omelettes NEEDED or the number 
				// of omelettes AVAILABLE
				omelettesReq = min(items - cakes, omelettes);
				// then, the number of milkshakes depends on the value left after
				// subtracting the number of omelettes created
				milkshakesReq = items - cakes - omelettesReq;
			} else {
				// if the cost of the milkshakes are less than the cost of the omelettes
				// then prioritize on making the number of milkshakes NEEDED or the number 
				// of milkshakes AVAILABLE
				milkshakesReq = min(items - cakes, milkshakes);
				// then, the number of omelettes depends on the value left after
				// subtracting the number of milkshakes created
				omelettesReq = items - cakes - milkshakesReq;
			}
			// this is the equation for getting the final price of every iteration (combination)
			// get the sum of the product of the numbers of each item and its corresponding cost
			long long price = cakes * cakeCost + omelettesReq * omeletteCost + milkshakesReq * milkshakeCost;
			// store in the 'ans' variable the minimum price that a combination of orders can produce
			// and at the same time accommodating the number of items needed
			ans = min(ans, price);
		}
		// if the 'ans' variable is still equal to the maximum value of a long long integer,
		// then print '-1', otherwise print the value of 'ans'
		cout << (ans == 1e18 ? -1 : ans) << '\n';
	}
	return 0;
}
