var express = require('express');
var app = express();

var staticDir = require('path').join(__dirname,'/static');
app.use(express.static(staticDir));

app.get('/hack', function (req, res) {
	res.sendFile("./static/html/index.html",{root: "./"});
})

app.get('/', function (req, res) {
	res.set("Content-Type","text/html");
	res.sendFile("./static/html/hack.txt",{root: "./"});
})

var server = app.listen(8080, function () {
 	var host = server.address().address
 	var port = server.address().port
 	console.log('Example app listening at http://%s:%s', host, port)
});
