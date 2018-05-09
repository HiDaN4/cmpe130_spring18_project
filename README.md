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

## Building
### Automatic Build Script
Building the C++ project source code into a Node.js interface module requires multiple steps. This build procedure is simplified by running the build script in the project's parent directory: `build.sh`
To build the module, simply run the following command: `bash build.sh`

The following list describes the separate steps necessary to manually build the interface module:
1. Run `make` in `c++` directory
2. Run `npm run compile` in `nodejs` directory
3. Move built Node.js module from `nodejs/build/Release/module.node` to `nodejs/lib/module.node`

_See below for detailed information for each step and related issues_

### C++

The Node.js module requires to be linked against a static library of the project's c++ code. In order to create this static library, navigate to the `c++` directory and run `make`. This will build the project's static library into its required location: `nodejs/lib/libproject.a`

### Node.js

The Node.js backend interfaces with the C++ code through a module, `GraphManagerModule`. The `GraphManagerModule` contains the `GraphManagerInterface` which provides an interface between the Node.js backend and the C++ project code. To build this module simply navigate to the `nodejs` directory in your terminal and run the following command: 

`npm run compile`
The module will be built in the `nodejs/build/Release` directory with the filename: `module.node`. This file must be moved to the `nodejs/lib` directory before starting the Node.js server.

#### Known Issues

The package `gyp` requires Python versions: `v2.5.0 <= Python Version < v3.0.0`, so running the previous command may not work if you have multiple versions of python installed, i.e. `python3` and `python2.7`. Specify an alternative python version to use that fits the version requirement in the following build command: 

`npm run compile --python=<python>`

*Where:* `<python>` is the python executable; i.e `python2.7`

## Authors
* Antonio Bares
* Hashim Shah
* Dmitry Sokolov
