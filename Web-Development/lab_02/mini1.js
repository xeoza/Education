var express 		= require('express'),
	app 			= express(),
	staticDir 		= require('path').join(__dirname,'/static'),
	expressLogging 	= require('express-logging'),
	logger			= require('logops');


app.use(express.static(staticDir));
app.use(expressLogging(logger));

app.get('/', function (req, res) {
	res.sendFile("./static/html/welcome_service1.html",{root: "./"});
})

app.get('/temp', function (req, res) {
	res.sendFile("./static/html/temp_service1.html",{root: "./"});
})

var server = app.listen(8003, function () {
 	var host = server.address().address
 	var port = server.address().port
 	console.log('Example app listening at http://%s:%s', host, port)
});
