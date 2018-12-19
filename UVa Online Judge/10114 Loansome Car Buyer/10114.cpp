#include <cstdio>

void printAnswer(int complete_months)
{
    if (complete_months == 1)
        printf("1 month\n");
    else
        printf("%d months\n", complete_months);
}

int main(void)
{
    int duration, num_of_dep, month_num;
    double down_payment, amount_of_loan, dep_percent, dep_rate[101];

    while (scanf("%d %lf %lf %d", &duration, &down_payment, &amount_of_loan, &num_of_dep), duration > 0)
    {
        // initialize depreciation
        for (int i = 0; i < 101; i++)
        {
            dep_rate[i] = -1.0;
        }

        // depreciation input
        while (num_of_dep--)
        {
            scanf("%d %lf", &month_num, &dep_percent);
            dep_rate[month_num] = dep_percent;
        }

        int complete_months = 0;
        double current_dep_rate = dep_rate[0];
        double car_value = amount_of_loan + down_payment;
        car_value = car_value - car_value * current_dep_rate;
        double monthly_payment = amount_of_loan / duration;

        // calculate for 0 months
        if (amount_of_loan < car_value)
        {
            printAnswer(complete_months);
            continue;
        }

        // calculate for following months
        while (1)
        {
            if (dep_rate[++complete_months] > -0.5)
                current_dep_rate = dep_rate[complete_months];

            amount_of_loan -= monthly_payment;
            car_value = car_value - car_value * current_dep_rate;

            if (amount_of_loan < car_value)
            {
                printAnswer(complete_months);
                break;
            }
        }
    }
}