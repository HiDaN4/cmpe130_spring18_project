var express = require('express');
var router = express.Router();

var tradesMap = new Map();
const client = require('../lib/hitbtc-client');

getCurrenciesMapPromise = function() {
  return new Promise(function(resolve, reject){
    client.getCurrenciesMap(function(err, data) {
      if(data != null)
        resolve(data);

      else
        reject(data);
    });
  });
}

/* GET home page. */
router.get('/', function(req, res, next) {
  var currenciesPromise = getCurrenciesMapPromise();
  currenciesPromise.then(function(data){
  
    return new Promise(function(resolve, reject) {
      var currencies = new Map();
      data.forEach(function(value, currency, map) {
        let symbol = currency;
        let name = value.get('fullName');
    
        currencies.set(symbol, name);
      })
  
      resolve(currencies);
    })
  }).then(currenciesMap => res.render('index', { title: 'Kryptos' , hasResult: false, currenciesMap: currenciesMap, tradesMap: tradesMap})).catch(error => console.log(error));


  ;
});

module.exports = router;
