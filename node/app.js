const express = require("express");
const app = express();

app.get("/", function (req, res) {
    res.sendFile(__dirname + "/index.html");
});

app.use(express.static(__dirname + '/'));

app.listen(3000, '0.0.0.0');