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
  // var tradesMap = new Map();
  var tradesArray = new Array();
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

    if (req.query.src && req.query.dest && req.query.amount) {
      if (req.query.src == req.query.dest) {
        console.log("Error: Src & Dest cannot be the same");
        res.render('index', { title: 'Kryptos' , hasResult: false, currenciesMap: currenciesMap, tradesArray: tradesArray});
      } else if (isNaN(req.query.amount)) {
        console.log("Error: Amount must be a number");
        res.render('index', { title: 'Kryptos' , hasResult: false, currenciesMap: currenciesMap, tradesArray: tradesArray});
      }
      else {
       if (!currenciesMap.has(req.query.src) || !currenciesMap.has(req.query.dest)) {
         console.log("Src or Dest do not exist");
         res.render('index', { title: 'Kryptos' , hasResult: false, currenciesMap: currenciesMap, tradesArray: tradesArray});
       }
       else {
        const filename = `currency_data-${Date.now()}.csv`
        var writeDataPromise = writeNewCurrencyDataToFilePromise(filename);
  
        writeDataPromise.then(function() {
          graphManager.updateGraph(filename);
          tradesArray = graphManager.findBestExchangeRoute(req.query.src, req.query.dest);
          console.log(tradesArray);

          var calculatedSourceAmount = req.query.amount;
          var directSrcAmount = graphManager.getCostForExchange(req.query.src, req.query.dest) * req.query.amount;

          tradesArray.forEach(function(element) {
            let tradePair = element.split(',')
            calculatedSourceAmount *= tradePair[2];
          });

          if (calculatedSourceAmount > 10.0) {
            calculatedSourceAmount = calculatedSourceAmount.toFixed(4);
          }

          if (directSrcAmount > 10.0) {
            directSrcAmount = directSrcAmount.toFixed(4);
          }


          res.render('index', { title: 'Kryptos' , hasResult: true, currenciesMap: currenciesMap, tradesArray: tradesArray, src: req.query.src, dest: req.query.dest, srcAmount: calculatedSourceAmount , destAmount: req.query.amount, directSrcAmount: directSrcAmount});

        }).catch(error => console.log(error));
       }
      }
    } else {
      res.render('index', { title: 'Kryptos' , hasResult: false, currenciesMap: currenciesMap, tradesArray: tradesArray});
    }

  }).catch(error => console.log(error));

});

module.exports = router;
module.exports.graphManager = graphManager;