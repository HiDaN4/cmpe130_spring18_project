var express = require('express');
var router = express.Router();

const client = require('../lib/hitbtc-client');
const mod = require('../lib/module');

var graphManager = new mod.GraphManagerInterface("HitBTC");

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
  var tradesMap = new Map();
  var hasResult = false;


  if(req.query.src && req.query.dest)
  {
    if (req.query.src == req.query.dest)
      console.log("Error: Src & Dest cannot be the same");

    else {
      
    }

  }

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

});

module.exports = router;
module.exports.graphManager = graphManager;