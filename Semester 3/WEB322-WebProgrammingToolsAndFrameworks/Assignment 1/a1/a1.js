/*********************************************************************************
*  WEB322 – Assignment 1
*  I declare that this assignment is my own work in accordance with Seneca Academic Policy.  
*  No part of this assignment has been copied manually or electronically from any other source
*  (including web sites) or distributed to other students.
* 
*  Name: Sampreet Klair, Student ID: 145031225, Date: January 22nd, 2024
*
********************************************************************************/ 

const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Do you wish to process a File (f) or directory (d): ', (answer) => {
  if (answer.toLowerCase() === 'f') {
    rl.question('File: ', (fileName) => {
      processFile(fileName);
      rl.close();
    });
  } else if (answer.toLowerCase() === 'd') {
    rl.question('Directory: ', (dirName) => {
      processDirectory(dirName);
      rl.close();
    });
  } else {
    console.log('Invalid Selection');
    rl.close();
  }
});

function processFile(fileName) {
  fs.readFile(fileName, 'utf8', (err, data) => {
    if (err) {
      console.log(`Error reading file: ${err.message}`);
    } else {
      const cleanData = data.toString().replace(/\s+/g, ' ');
      const charCount = cleanData.length;
      const wordCount = cleanData.replace(/[^\w\s\']/g, '').split(' ').filter(Boolean).length;
      const longestWord = cleanData.replace(/[^\w\s\']/g, '').split(' ').reduce((longest, word) => word.length > longest.length ? word : longest, '');
      console.log(`Number of Characters (including spaces): ${charCount}`);
      console.log(`Number of Words: ${wordCount}`);
      console.log(`Longest Word: ${longestWord}`);
    }
  });
}

function processDirectory(dirName) {
  fs.readdir(dirName, (err, files) => {
    if (err) 
    {
      console.log(`Error reading directory: ${err.message}`);
    } else 
    {
      if (files.length === 0) 
      {
        console.log('Directory is empty.');
      } 
      else {
        const sortedFiles = files.sort((a, b) => b.localeCompare(a));
        console.log('Files (reverse alphabetical order): ' + sortedFiles.join(', '));
      }
    }
  });
}

function getWordFrequency(text) {
  const words = text.replace(/[^\w\s\']/g, '').split(' ').filter(Boolean);
  const frequency = {};
  words.forEach((word) => {
    frequency[word] = (frequency[word] || 0) + 1;
  });

  return frequency;
}