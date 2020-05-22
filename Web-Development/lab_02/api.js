var express = require('express'),
	bodyParser = require('body-parser'),
	app = express.Router(),
	jsonParser = bodyParser.json(),
	expressLogging 	= require('express-logging'),
	logger			= require('logops');

app.use(expressLogging(logger));

var phone_book = [];

function isIdValid(id){
	if (id == null) {
		return false;
	}
	for (let i = 0; i < phone_book.length; i++){
		if ( phone_book[i].id == id ){
			return false;
		}
	}
	return true;
}

function isNumberValid(number){
	return !(number == null || isNaN(Number(number)) || number.length != 11 || number.charAt(0) != '8');
}

function isNameValid(name){
	return !(name == null);
}

function isAddressValid(address){
	return !(address == null);
}

function isEntryValid(e){
	if (isIdValid(e.id, true) && isNumberValid(e.number) && isNameValid(e.name) && isAddressValid(e.address)){
		return true;
	}
	return false;
}

function addNewEntry(e){
	phone_book.push(e);
}

function getEntries(p){
	result = [];
	for (let i = 0; i < phone_book.length; i++){
		if ((p.id == null || p.id == phone_book[i].id) && 
			(p.number == null || p.number == phone_book[i].number) && 
			(p.name == null || p.name == phone_book[i].name) && 
			(p.address == null || p.address == phone_book[i].address)){
			result.push(phone_book[i])
		}
	}
	return result;
}

function changeEntry(params){
	for (let i = 0; i < phone_book.length; i++){
		if (phone_book[i].id == params.id){
			if (params.number != null){
				phone_book[i].number = params.number;
			}
			if (params.name != null){
				phone_book[i].name = params.name;
			}
			if (params.address != null){
				phone_book[i].address = params.address;
			}
		}
	}
}

function deleteEntry(params){
	 for (let i = 0; i < phone_book.length; i++){
		if (phone_book[i].id == params.id){
			phone_book.splice(i,1);
			i--;
		}
	}
}

app.get('/', jsonParser, function (req, res) {
	const params = req.body;
	var results = getEntries(params);
 	res.send('{'+JSON.stringify(results)+'}');
})
 
app.post('/', jsonParser, function (req, res) {
	const entry = req.body;
	if (isEntryValid(entry)){
		addNewEntry(entry)
		res.send(JSON.stringify(entry));
	} else {
		res.sendStatus(400);
	}
})
 
app.put('/', jsonParser, function (req, res) {
	const params = req.body;
	if (params.id == null) {
		res.sendStatus(400);
	} else if (params.number != null && !isNumberValid(params.number)){
		res.sendStatus(400);
	} else {
		result = changeEntry(params);
  		res.send('New data puted');
  	}
})
 
app.delete('/', jsonParser, function (req, res) {
	const params = req.body;
	if (params.id == null) {
		res.sendStatus(400);
	} else {
		deleteEntry(params);
  		res.send('Entry deleted');
  	}
})
 
module.exports = app;
