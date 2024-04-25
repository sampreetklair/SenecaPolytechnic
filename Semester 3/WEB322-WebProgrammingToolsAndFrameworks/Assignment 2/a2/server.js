/********************************************************************************
*  WEB322 – Assignment 02
* 
*  I declare that this assignment is my own work in accordance with Seneca's
*  Academic Integrity Policy:
* 
*  https://www.senecacollege.ca/about/policies/academic-integrity-policy.html
* 
********************************************************************************/


const legoData = require("./modules/legoSets");
const express = require('express');
const app = express();


const HTTP_PORT = process.env.PORT || 8080;

legoData.initialize()
  .then(() => {
    app.get('/', (req, res) => {
      res.send('Assignment 2: Sampreet Klair - 145031225');
    });

    app.get('/lego/sets', (req, res) => {
        legoData.getAllSets()
          .then(allSets => res.json(allSets))
    });

    app.get('/lego/sets/num-demo', (req, res) => {
      const setNum = '41347-1'; 
      legoData.getSetByNum(setNum)
        .then((set) => {
          if (set) {
            res.json(set);
          } else {
            console.log('Lego set not found');
          }
        })
        .catch((error) => {
          console.log('Error getting lego set by number:', error);
          res('Error getting lego set by number:');
        });
    });

    app.get('/lego/sets/theme-demo', (req, res) => {
      const theme = 'friends'; 
      legoData.getSetsByTheme(theme)
        .then((sets) => {
          res.json(sets);
        })
        .catch((error) => {
          console.error('Error getting lego sets by theme:', error);
          res('Error getting lego set by theme:');
        });
    });

    app.listen(HTTP_PORT, () => {
      console.log(`Server listening on: ${HTTP_PORT}`);
    });
  })
  .catch((error) => {
    console.log('Error initializing Lego data:', error);
  });