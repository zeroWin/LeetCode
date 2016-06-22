/**
 * 121. Best Time to Buy and Sell Stock
 * Say you have an array for which the ith element is the price of a given stock on day i.

 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 **/
#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize);
int main()
{
    printf("Hello world!\n");
    return 0;
}


int maxProfit(int* prices, int pricesSize) {
    int i;
    int preProfit = 0;
    int nowProfit = 0;
    for(i = pricesSize-1; i > 0; --i)
        prices[i] = prices[i] - prices[i - 1];
    prices[i] = 0;
    for(i = 0; i < pricesSize; ++i)
    {
        nowProfit += prices[i];
        if(nowProfit > preProfit)
            preProfit = nowProfit;
        if(nowProfit < 0)
            nowProfit = 0;
    }
    return preProfit;
}
