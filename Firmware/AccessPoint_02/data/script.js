 // Get current sensor readings when the page loads
window.addEventListener('load', getReadings);
// Function to get current readings on the web page when it loads for the first time
function getReadings() {
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            var obj = JSON.parse(this.responseText);
            console.log(obj);
            document.getElementById("temp").innerHTML = obj.temperature;
            document.getElementById("hum").innerHTML = obj.humidity;
            document.getElementById("pres").innerHTML = obj.pressure;
        }
    };
    xhr.open("GET", "/readings", true);
        xhr.send();
    }

// Create an EventSource to respond to events
if (!!window.EventSource) {
    var source = new EventSource('/events');

    source.addEventListener('open', function(e) {
        console.log("Events Connected");
    }, false);

    source.addEventListener('error', function(e) {
        if (e.target.readyState != EventSource.OPEN) {
            console.log("Events Disconnected");
        }
    }, false);

    source.addEventListener('new_readings', function(e) {
        console.log("new_readings", e.data);
        var obj = JSON.parse(e.data);
        document.getElementById("temp").innerHTML = obj.temperature;
        document.getElementById("hum").innerHTML = obj.humidity;
        document.getElementById("pres").innerHTML = obj.pressure;
    }, false);
}