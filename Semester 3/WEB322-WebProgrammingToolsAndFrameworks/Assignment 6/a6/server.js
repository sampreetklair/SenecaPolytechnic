/********************************************************************************
* WEB322 – Assignment 06
*
* I declare that this assignment is my own work in accordance with Seneca's
* Academic Integrity Policy:
*
* https://www.senecacollege.ca/about/policies/academic-integrity-policy.html
**
* Published URL: https://lego-a6.cyclic.app/
********************************************************************************/

const legoData = require("./modules/legoSets");
const express = require('express');
var path = require('path');
const app = express();

const Sequelize = require('sequelize');
const authData = require('./modules/auth-service.js');
const clientSessions = require('client-sessions');


const HTTP_PORT = process.env.PORT || 8080;


app.use(express.static('public'));
app.use(express.urlencoded({ extended: true }));
app.set('view engine', 'ejs');

app.use(clientSessions({
      cookieName: 'session', 
      secret: 'o6LjQ5EVNC28ZgK64hDELM18ScpFQr', 
      duration: 5 * 60 * 1000, 
      activeDuration: 1000 * 60, 
    })
);

app.use((req, res, next) => {
  res.locals.session = req.session;
  next();
});

function ensureLogin(req, res, next) {
  if (!req.session.user) {
    res.redirect('/login');
  } else {
    next();
  }
}



app.get('/', (req, res) => {
  res.render('home');
});

app.get('/about', (req, res) => {
  res.render('about');
});




app.get('/login', (req, res) => {
  res.render('login');
});

app.post('/login', (req, res) => {
  req.body.userAgent = req.get('User-Agent');
  
  authData.checkUser(req.body)
    .then((user) => {
      req.session.user = {
        userName: user.userName, 
        email: user.email, 
        loginHistory: user.loginHistory 
      }

      res.redirect('/lego/sets');
    })
    .catch((err) => {
      res.render('login', { errorMessage: err, userName: req.body.userName });
    });
});

app.get('/register', (req, res) => {
  res.render('register');
});

app.post('/register', async (req, res) => {
  authData.registerUser(req.body)
    .then(() => {
      res.render('register', { successMessage: "User created" });
    })
    .catch((err) => {
      res.render('register', { errorMessage: err, userName: req.body.userName });
    });
});

app.get('/logout', (req, res) => {
  req.session.reset();
  res.redirect('/');
});

app.get('/userHistory', ensureLogin, (req, res) => {
  res.render('userHistory');
});

app.get("/lego/sets", async (req,res)=>{    
  try {
    if (req.query.theme) {
      let sets = await legoData.getSetsByTheme(req.query.theme);
      if (sets.length > 0) {
        res.render("sets",{sets: sets});
      }
      else {
        res.render('404', {message: "I'm Sorry, there are no sets with that theme"})
      }
    }
    else {
      let sets = await legoData.  getAllSets();
      res.render("sets",{sets: sets});
    }
  } catch(err) {
    res.render('404', {message: err});
  }
});

app.get("/lego/sets/:id", async (req,res)=>{
  try{
    let set = await legoData.getSetByNum(req.params.id);
    res.render("set", {set: set});
  }catch(err){
    res.render('404', {message: err});
  }
});

app.get("/lego/addSet", ensureLogin, async (req,res)=>{
  try{
    let themeData = await legoData.getAllThemes();
    res.render("addSet", {theme: themeData});
  }catch(err){
    res.render('404', {message: err});
  }
});

app.post("/lego/addSet", ensureLogin, async (req,res)=>{
  try{
    legoData.addSet(req.body)
    .then(() => {
      console.log("Set Added");
      res.redirect("/lego/sets");
    })
    .catch((err) => {
      res.render('500', { message: `I'm sorry, but we have encountered the following error: ${err}` });
    });
  }catch(err){
    res.render('404', {message: err});
  }
});

app.get("/lego/editSet/:id", ensureLogin, async (req,res)=>{
  try{
    let setData = await legoData.getSetByNum(req.params.id);
    let themes = await legoData.getAllThemes();
    res.render("editSet", {set: setData, themes: themes});
  }catch(err){
    res.render('404', {message: err});
  }
});

app.post("/lego/editSet", ensureLogin, async (req,res)=>{
  try{
    legoData.editSet(req.body.set_num, req.body)
    .then(() => {
      console.log("Set Edited");
      res.redirect("/lego/sets");
    })
    .catch((err) => {
      res.render('500', { message: `I'm sorry, but we have encountered the following error: ${err}` });
    });
  }catch(err){
    res.render('404', {message: err});
  }
});

app.get("/lego/deleteSet/:num", ensureLogin, async (req,res)=>{
  try{
    legoData.deleteSet(req.params.num)
    .then(() => {
      console.log("Set Deleted");
      res.redirect("/lego/sets");
    })
    .catch((err) => {
      res.render('500', { message: `I'm sorry, but we have encountered the following error: ${err}` });
    });
  }catch(err){
    res.render('404', {message: err});
  }
});


app.use((req, res) => {
  res.status(404).render('404', {message: "I'm Sorry, we're unable to find the page you were looking for"})
});

legoData.initialize()
  .then(authData.initialize)
  .then(function () {
    app.listen(HTTP_PORT, function () {
      console.log(`app listening on:  http://localhost:${HTTP_PORT}`);
    });
  }).catch(function (err) {
    console.log(`unable to start server: ${err}`);
  });