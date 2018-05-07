var express = require('express');
var router = express.Router();

const client = require('../lib/hitbtc-client');
const mod = require('../lib/module');

var graphManager = new mod.GraphManagerInterface("HitBTC");

getCurrenciesMapPromise = function() {
  return new Promise(function(resolve, reject) {
    client.getCurrenciesMap(function(err, data) {
      if (data != null)
        resolve(data);

      else
        reject(data);
    });
  });
}

writeNewCurrencyDataToFilePromise = function(filename) {
  return new Promise(function(resolve, reject) {
    client.writeNewCurrencyDataToFile(filename, function(err) {
      if (!err)
        resolve();
      else
        reject(err);
    })
  });
}


/* GET home page. */
router.get('/', function(req, res, next) {
  var tradesMap = new Map();
  var hasResult = false;

  var currenciesPromise = getCurrenciesMapPromise();
  currenciesPromise.then(function(data) {
    return new Promise(function(resolve, reject) {
      var currenciesMap = new Map();
      data.forEach(function(value, currency, map) {
        let symbol = currency;
        let name = value.get('fullName');
    
        currenciesMap.set(symbol, name);
      })
  
      resolve(currenciesMap);
    })
  }).then(function(currenciesMap) {

    if (req.query.src && req.query.dest) {
      if (req.query.src == req.query.dest) {
        console.log("Error: Src & Dest cannot be the same");
        res.render('index', { title: 'Kryptos' , hasResult: false, currenciesMap: currenciesMap, tradesMap: tradesMap});
      }
  
      else {
       if (!currenciesMap.has(req.query.src) || !currenciesMap.has(req.query.dest)) {
         console.log("Src or Dest do not exist");
         res.render('index', { title: 'Kryptos' , hasResult: false, currenciesMap: currenciesMap, tradesMap: tradesMap});
       }
       else {
        const currentTimeString = new Date().toLocaleTimeString();
        const filename = `currency_data-${currentTimeString}.csv`
        var writeDataPromise = writeNewCurrencyDataToFilePromise(filename);
  
        writeDataPromise.then(function() {
          let result = graphManager.findBestExchangeRoute(req.query.src, req.query.dest);
          console.log(result);

          res.render('index', { title: 'Kryptos' , hasResult: true, currenciesMap: currenciesMap, tradesMap: tradesMap});

        }).catch(error => console.log(error));
       }
      }
    } else {
      res.render('index', { title: 'Kryptos' , hasResult: false, currenciesMap: currenciesMap, tradesMap: tradesMap});
    }

  }).catch(error => console.log(error));

});

module.exports = router;
module.exports.graphManager = graphManager;