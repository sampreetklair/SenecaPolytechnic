const mongoose = require("mongoose");
let Schema = mongoose.Schema;
const bcrypt = require("bcryptjs");
require("dotenv").config();

let userSchema = new Schema({
  userName: {
    type: String,
    unique: true,
  },
  password: String,
  email: String,
  loginHistory: [
    {
      dateTime: Date,
      userAgent: String,
    },
  ],
});

let User;

function initialize() {
  return new Promise(function (resolve, reject) {
    let db = mongoose.createConnection(`mongodb+srv://sklair2:<password>@cluster0.9re6qys.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0`);
    db.on("error", (err) => {
      reject(err);
    });
    db.once("open", () => {
      User = db.model("users", userSchema);
      resolve();
    });
  });
}

function registerUser(userData) {
  return new Promise(async (resolve, reject) => {
    if (userData.password != userData.password2) {
      reject("Passwords do not match");
    } else {
      bcrypt
        .hash(userData.password, 10)
        .then((hash) => {
          userData.password = hash;
          let newUser = new User(userData);
          newUser
            .save()
            .then(() => resolve())
            .catch((err) =>
              reject(`There was an error creating the user: ${err}`)
            );
        })
        .catch((err) => {
          console.log(err);
          reject("There was an error encrypting the password");
        });
    }
  });
}
function checkUser(userData) {
  return new Promise(async (resolve, reject) => {
    User.find({ userName: userData.userName })
      .exec()
      .then(async (users) => {
        if (users.length === 0) {
          reject(`Unable to find user: ${userData.userName}`);
        } else {
          bcrypt
            .compare(userData.password, users[0].password)
            .then(async (result) => {
              if (result) {
                if (users[0].loginHistory.length === 8) {
                  users[0].loginHistory.pop();
                }
                users[0].loginHistory.unshift({
                  dateTime: new Date().toString(),
                  userAgent: userData.userAgent,
                });

                await User.updateOne(
                  { userName: users[0].userName },
                  { $set: { loginHistory: users[0].loginHistory } }
                )
                  .exec()
                  .then(() => {
                    resolve(users[0]);
                  })
                  .catch((err) => {
                    console.log("ERROR: ", err.message);
                    reject(
                      `There was an error verifying the user: ${err.message}`
                    );
                  });
              } else {
                reject(`Incorrect Password for user: ${userData.userName}`);
              }
            })
            .catch((err) =>
              reject(`There was an error comparing passwords: ${err}`)
            );
        }
      })
      .catch((err) => {
        reject(`Unable to find user: ${userData.userName}`);
      });
  });
}

module.exports = {
  initialize,
  registerUser,
  checkUser,
};