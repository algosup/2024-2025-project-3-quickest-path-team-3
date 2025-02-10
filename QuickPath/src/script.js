document.addEventListener("DOMContentLoaded", () => {
  const sourceInput = document.getElementById("source");
  const destinationInput = document.getElementById("destination");
  const getPathButton = document.querySelector(".get-path");
  const jsonSwitch = document.getElementById("json");
  const xmlSwitch = document.getElementById("xml");
  const resultContainer = document.getElementById("result-container");

  // Restrict input to integers only
  function allowOnlyIntegers(event) {
    event.target.value = event.target.value.replace(/\D/g, "");
  }

  sourceInput.addEventListener("input", allowOnlyIntegers);
  destinationInput.addEventListener("input", allowOnlyIntegers);

  // UI Logic for format selection
  jsonSwitch.addEventListener("click", () => {
    jsonSwitch.classList.add("active");
    xmlSwitch.classList.remove("active");
  });

  xmlSwitch.addEventListener("click", () => {
    xmlSwitch.classList.add("active");
    jsonSwitch.classList.remove("active");
  });

  getPathButton.addEventListener("click", () => {
    const source = sourceInput.value.trim();
    const destination = destinationInput.value.trim();
    const format = jsonSwitch.classList.contains("active") ? "json" : "xml";

    if (!source || !destination) {
      alert("Please enter valid integers for both source and destination.");
      return;
    }

    // **START BOTH API CALL AND CAR ANIMATION SIMULTANEOUSLY**
    const apiPromise = fetch(`http://localhost:18080/quickestpath?source=${source}&destination=${destination}&format=${format}`)
      .then(response => {
        if (!response.ok) throw new Error("Path not found");
        return response.text(); // Handle JSON or XML
      })
      .then(data => {
        if (format === "json") {
          displayResult(JSON.parse(data), format);
        } else {
          displayResult(data, format);
        }
      })
      .catch(error => {
        alert(error.message);
      });

    // **DO NOT WAIT FOR API – Start the Car Animation Immediately**
    animateCar();

    // **Allow API and Animation to Run in Parallel**
    Promise.all([apiPromise]).then(() => {
      console.log("API call completed while animation was running.");
    });
  });

  function animateCar() {
    const car = document.getElementById("car");
    const sourceRect = sourceInput.getBoundingClientRect();
    const destinationRect = destinationInput.getBoundingClientRect();

    car.style.display = "block";
    car.style.position = "absolute";
    car.style.left = `${sourceRect.left + sourceRect.width / 2 - 20}px`;
    car.style.top = `${sourceRect.top + 50}px`;

    let positionX = sourceRect.left + sourceRect.width / 2 - 20;
    let positionY = sourceRect.top + 50;
    const targetX = destinationRect.left + destinationRect.width / 2 - 20;
    const targetY = destinationRect.top + 50;
    const speed = 1;

    const interval = setInterval(() => {
      if (
        Math.abs(positionX - targetX) < speed &&
        Math.abs(positionY - targetY) < speed
      ) {
        clearInterval(interval);
        setTimeout(() => {
          car.style.display = "none";
        }, 250);
      } else {
        positionX += (targetX - positionX) * 0.05;
        positionY += (targetY - positionY) * 0.05;
        car.style.left = `${positionX}px`;
        car.style.top = `${positionY}px`;
      }
    }, 25);
  }

  function displayResult(data, format) {
    resultContainer.innerHTML = "";
    resultContainer.style.display = "block";

    let result = "";

    if (format === "json") {
      result = JSON.stringify(data, null, 2);
    } else if (format === "xml") {
      result = formatXml(data);
    }

    resultContainer.textContent = result;
  }

  function formatXml(xml) {
    return xml.replace(/></g, ">\n<"); // Simple XML formatting
  }
});
