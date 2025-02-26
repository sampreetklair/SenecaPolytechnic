/********************************************************************************
*  WEB322 – Assignment 03
* 
*  I declare that this assignment is my own work in accordance with Seneca's
*  Academic Integrity Policy:
* 
*  https://www.senecacollege.ca/about/policies/academic-integrity-policy.html
* 
*  Published URL: https://lego-a3.cyclic.app/
********************************************************************************/


const legoData = require("./modules/legoSets");
const express = require('express');
const app = express();
app.use(express.static('public'));
const path = require("path");
const port = 8080;

legoData.initialize().then(() => {
  console.log("sets initialized!");
});

app.use(express.static("public")); 

app.get('/', (req, res) => {
  console.log("serving html file: ", path.join(__dirname, '/views/home.html'))
  res.sendFile(path.join(__dirname, '/views/home.html'));
});

app.get('/about', (req, res) => {
  res.sendFile(path.join(__dirname, '/views/about.html'));
});

app.get("/lego/sets", (req, res) => {
  const theme = req.query.theme;
  if (theme) {
    legoData.getSetsByTheme(theme)
      .then((sets) => res.status(200).send(sets))
      .catch((error) => res.status(404).send({ message: error }));
  } else {
    legoData.getAllSets()
      .then((sets) => res.status(200).send(sets))
      .catch((error) => res.status(404).send({ message: error }));
  } 
});

app.get("/lego/sets/num-demo", (req, res) => {
  const userNum = req.params.num;
  legoData.getSetByNum(userNum)
    .then((foundSet) => {
      if (foundSet) {
        res.status(200).send(foundSet);
      } else {
        res.status(404).send("Set not found");
      }
    })
    .catch((error) => res.status(404).send({ message: error }));
});

app.get("/lego/sets/:num", (req, res) => {
  const userNum = req.params.num;
  console.log("user enters: ", userNum);
  legoData
    .getSetByNum(userNum)
    .then((foundSet) => res.status(200).send(foundSet))
    .catch((error) => res.status(404).send("404", { message: error }));
});

app.use((req, res) => {
  res.status(404).sendFile(path.join(__dirname, '/views/404.html'));
});

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`);
});