var express 		= require('express'),
	app 			= express(),
	staticDir 		= require('path').join(__dirname,'/static'),
	api				= require('./api'),
	expressLogging 	= require('express-logging'),
	logger			= require('logops');


app.use(express.static(staticDir));
app.use("/api",api);
app.use(expressLogging(logger));

app.get('/hack', function (req, res) {
	res.sendFile("./static/html/index.html",{root: "./"});
})

app.get('/', function (req, res) {
	res.set("Content-Type","text/html");
	res.sendFile("./static/html/hack.txt",{root: "./"});
})

var server = app.listen(8001, function () {
 	var host = server.address().address
 	var port = server.address().port
 	console.log('Example app listening at http://%s:%s', host, port)
});
