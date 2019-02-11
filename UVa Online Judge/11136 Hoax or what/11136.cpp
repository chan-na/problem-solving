#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    multiset<int> urn;

    int numOfDays;
    while (cin >> numOfDays, numOfDays != 0)
    {
        urn.clear();

        int k;
        int bill;
        int highestBill;
        int lowestBill;
        long long promotionFee = 0LL;
        for (int i = 0; i < numOfDays; ++i)
        {
            cin >> k;
            while (k--)
            {
                cin >> bill;
                urn.insert(bill);
            }

            auto it = urn.begin();
            lowestBill = *it;
            urn.erase(it);

            it = urn.end();
            --it;
            highestBill = *it;
            urn.erase(it);

            promotionFee += highestBill - lowestBill;
        }

        cout << promotionFee << '\n';
    }

    return 0;
}