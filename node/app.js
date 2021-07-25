var express = require('express');
var http = require('http');
var path = require('path');
var reload = require('reload');
const chokidar = require('chokidar');

var app = express();

var publicDir = path.join(__dirname, 'public');

app.set('port', process.env.PORT || 3000);
app.use(express.static('public'));

app.get('/', function (req, res) {
  res.sendFile(path.join(publicDir, 'index.html'));
})

var server = http.createServer(app);

const watcher = chokidar.watch('public/line.txt', {
  ignored: /(^|[\/\\])\../,
  persistent: true
});

reload(app).then(function (reloadReturned) {
	server.listen(app.get('port'), function () {
		console.log('Web server listening on port ' + app.get('port'));
		watcher.on('change', function(path){ 
			reloadReturned.reload();
		})
	})
}).catch(function (err) {
	console.error('Reload could not start, could not start server/sample app', err);
})
