/*
 * You are running a website, and you are trying to keep track of how much
 * money you make per day from advertising.
 *
 * Declare an advertising struct that keeps track of how many ads you've shown
 * to readers, what percentage of ads were clicked on by users, and how much
 * you earned on average from each ad that was clicked.
 *
 * Read in values for each of these fields from the user. Pass the advertising
 * struct to a function that prints each of the values and then calculates how
 * much you made that day (multiply all 3 fields together)
*/
#include <iostream>

struct AdStats
{
	int ads_shown{};
	double percent_ads_clicked{};
	double avg_earned_per_click{};
};

AdStats askAdStats()
{
	AdStats as{};

	std::cout << "# ads shown?: ";
	std::cin >> as.ads_shown;

	std::cout << "% of ads clicked?: ";
	std::cin >> as.percent_ads_clicked;

	std::cout << "Avg earned per click?: $";
	std::cin >> as.avg_earned_per_click;

	return as;
}

float calculateDayRevenue(AdStats as)
{
	return as.ads_shown
		* (as.percent_ads_clicked / 100.0)
		* as.avg_earned_per_click;
}
void printAdStatsAndDayRevenue(AdStats as)
{
	std::cout << "\n=========== TODAY'S REVENUE: ===========\n";
	std::cout << "# ads shown: " << as.ads_shown << '\n';
	std::cout << "% of ads clicked: " << as.percent_ads_clicked << '\n';
	std::cout << "Avg earned per click: $" << as.avg_earned_per_click << '\n';
	std::cout << "\nTotal revenue for day: $" << calculateDayRevenue(as) << '\n';
	std::cout << "========================================\n";
}

int main()
{
	AdStats adstats{ askAdStats() };
	printAdStatsAndDayRevenue(adstats);

	return 0;
}
