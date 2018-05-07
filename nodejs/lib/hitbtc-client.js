// hitbtc-client.js
// hitbtc-client Module
// Author: Antonio G. Bares Jr.

const request = require('request');
const fs = require('fs');

const apiUrl = "https://api.hitbtc.com/";


exports.getCurrencies = function(_callback) {

    const options = {
       url: apiUrl + "api/2/public/currency",
       method: 'GET',
       json: true
    }

   request(options, function(err, res, body) {
        if (err)
            _callback(err, null);
         else
            _callback(null, body);
   });
}

exports.getCurrenciesMap = function (_callback) {

    exports.getCurrencies(function(err, data) {
        if (!err)
        {
            var currencies = new Map();
            for (i in data)
            {
                let currencyData = new Map();

                for (j in data[i])
                {
                    if (j != "id")
                        currencyData.set(j, data[i][j]);
                }

                currencies.set(data[i]['id'], currencyData);
            }

            _callback(null, currencies);
        }
        else
            _callback(err, null);
    });
}

exports.getSymbols = function(_callback) {
    const options = {
        url: apiUrl + "api/2/public/symbol",
        method: 'GET',
        json: true
    }

    request(options, function(err, res, body) {
        if (err)
            _callback(err, null);
        else
            _callback(null, body);
    })
}

exports.getSymbolsMap = function(_callback) {

    exports.getSymbols(function(err, data) {
        if (!err)
        {
            var symbols = new Map();
            for (i in data)
            {
                let symbolData = new Map();

                for (j in data[i])
                {
                    if (j != "id")
                        symbolData.set(j, data[i][j]);
                }

                symbols.set(data[i]['id'], symbolData);
            }

            _callback(null, symbols);
        }
        else
            _callback(err, null);
    });
}

getTickers = function(_callback) {

    const options = {
        url: apiUrl + "api/2/public/ticker",
        method: 'GET',
        json: true
    }

    request(options, function(err, res, body) {
        if (err)
            _callback(err, null);
        else
            _callback(null, body);
    })
}

exports.getTickersMap = function(_callback) {
    getTickers(function(err, data) {
        if(!err)
        {
            exports.getSymbolsMap(function(err, symbols) {
                if (!err)
                {
                    var tickers = new Map();
                    for (i in data)
                    {
                        let tickerData = new Map();
                        tickerData.set("baseCurrency", symbols.get(data[i]["symbol"]).get("baseCurrency"));
                        tickerData.set("quoteCurrency", symbols.get(data[i]["symbol"]).get("quoteCurrency"));

                        for (j in data[i])
                        {
                            if (j != 'symbol')
                                tickerData.set(j, data[i][j]);
                        }
                        tickers.set(data[i]['symbol'], tickerData);
                    }

                    _callback(null, tickers);
                }
                else
                    _callback(err, null);
            });

        }
        else
            _callback(err, null);

    });
}

exports.writeNewCurrencyDataToFile = function(filename, _callback) {
    exports.getTickersMap(function(err, data) {
        if(!err)
        {
            data.forEach(function(tickerData, symbol) {

                // console.log(tickerData.get('quoteCurrency'));
                // console.log(tickerData.get('baseCurrency'));
                // console.log(tickerData.get('last'));

                // console.log('\n');
                let dataToWrite = `${tickerData.get('quoteCurrency')},${tickerData.get('baseCurrency')},${tickerData.get('last')}\n`;

                fs.appendFile(filename, dataToWrite, function(err) {
                    if(err)
                        _callback(err);
                })
            });

            _callback(null);
        }
        else
            _callback(err);

    });
}