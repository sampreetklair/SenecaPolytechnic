const setData = require("../data/setData");
const themeData = require("../data/themeData");

let sets = [];

function initialize() {
  return new Promise((resolve, reject) => {
    try {
      setData.forEach((set) => {
        const themeObject = themeData.find((theme) => theme.id === set.theme_id);
        set.theme = themeObject ? themeObject.name : "Theme not Found";
        sets.push(set);
      });

      resolve();
    } catch (error) {
      reject(error);
    }
  });
}

function getAllSets() {
  return new Promise((resolve) => {
    resolve(sets);
  });
}

function getSetByNum(setNum) {
  return new Promise((resolve, reject) => {
    const foundSet = sets.find((set) => set.set_num === setNum);

    if (foundSet) {
      resolve(foundSet);
    } else {
      reject(`Not able to find lego set with set_num: ${setNum}`);
    }
  });
}

function getSetsByTheme(theme) {
  return new Promise((resolve, reject) => {
    const matchingSets = sets.filter((set) =>
      set.theme.toLowerCase().includes(theme.toLowerCase())
    );

    if (matchingSets.length > 0) {
      resolve(matchingSets);
    } else {
      reject(`Not able to find lego sets with theme: ${theme}`);
    }
  });
}

module.exports = { initialize, getAllSets, getSetByNum, getSetsByTheme };
