# Team Project for CMPE 130 class Spring 2018.

## Abstract
Maximizing profit in cryptocurrency trading is difficult without factoring in transaction fees and exchange prices between each crypto and fiat currency. Traders usually forget to factor in the associated fees when trading.

In order to maximize realized gains, it is important to factor in the associated costs of exchanging each currency pair and find the optimal set of exchanges. There are currently no applications that provide the best crypto-trading route to maximize gains. We aim to create a solution that will obtain the current prices of currency pairs and provide the user an optimal route to convert his/her cryptocurrency to fiat currency. The project will implement an all-pairs shortest-path algorithm in order to determine the best set of trades. Each currency pair will be represented by nodes in a graph. In order to obtain current exchange prices, constant polling will be done from the exchanges’ APIs; such as from Binance or GDAX. Data regarding relevant currency-pairs and exchange prices will be sorted using QuickSort.

## Design

### Data Structures and Algorithms
* Graphs
* Traversals
* All-Pair Shortest-Path Algorithm
* QuickSort


### First step: Diagrams

Class diagram for Graph class:
![uml diagram for Graph class](images/classes_uml_diagram.png?raw=true)

Diagrams can be found on [LucidChart](https://www.lucidchart.com/invitations/accept/923e3f12-93bf-4315-af38-f11a078edaf6)
tur

## Authors
* Antonio Bares
* Hashim Shah
* Dmitry Sokolov
