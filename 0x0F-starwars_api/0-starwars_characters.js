#!/usr/bin/node

const request = require('request');
request.get(
  'http://swapi.co/api/films/' + process.argv[2],
  { json: true },
  function (error, response, body) {
    if (error) { return; }

    let index = 0;
    const names = [];
    const people = body.characters;

    const finish = function () {
      for (const name of names) { console.log(name); }
    };

    const loadPeople = function (error, response, body) {
      if (error) { return; }

      for (const character of body.results) {
        if (character.url === people[index]) {
          names.push(character.name);
          index++;
        }
      }
      if (body.next !== null && index < people.length) {
        request.get(body.next, { json: true }, loadPeople);
      } else {
        finish();
      }
    };

    request.get('http://swapi.co/api/people/', { json: true }, loadPeople);
  }
);
