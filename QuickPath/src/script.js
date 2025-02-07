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
    const format = jsonSwitch.classList.contains("active") ? "JSON" : "XML";

    if (!source || !destination) {
      alert("Please enter valid integers for both source and destination.");
      return;
    }

    animateCar(() => {
      const travelTime = 1340;
      const nodePath = [
        1, 5, 7, 10, 8, 23, 25, 30, 35, 40, 45, 50, 72, 12, 123, 2830, 283,
        26738, 3802, 38930, 39489302, 8393, 83, 283, 2993, 382, 38002, 3893,
      ];
      displayResult(travelTime, nodePath, format);
    });
  });

  function animateCar(callback) {
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
          if (callback) callback();
        }, 250);
      } else {
        positionX += (targetX - positionX) * 0.05;
        positionY += (targetY - positionY) * 0.05;
        car.style.left = `${positionX}px`;
        car.style.top = `${positionY}px`;
      }
    }, 25);
  }

  function displayResult(travelTime, nodePath, format) {
    const resultContainer = document.getElementById("result-container");

    resultContainer.innerHTML = "";
    resultContainer.style.display = "block";

    let result = "";

    if (format === "JSON") {
      result = JSON.stringify(
        { travel_time: travelTime, node_path: nodePath },
        null,
        2
      );
    } else if (format === "XML") {
      result = `<result>\n  <travel_time>${travelTime}</travel_time>\n  <node_path>\n`;
      nodePath.forEach((node) => {
        result += `    <node>${node}</node>\n`;
      });
      result += `  </node_path>\n</result>`;
    }

    resultContainer.textContent = result;
  }
});
