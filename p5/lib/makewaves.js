function setup() {
  createCanvas(windowWidth, windowHeight);
  background(255, 255, 255);
}

function draw() {
  stroke(0, 0, 0);
  clear();
  for (const x of Array(windowWidth).keys()) {
    ellipse(x, 150 * sin(x / 20 - millis() / 150) + windowHeight / 2, 2);
  }
}
