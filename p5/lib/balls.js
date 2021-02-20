// state
let circleX1 = 0;
let circleY1 = 0;
let circleX2 = 0;
let circleY2 = 0;
let xSpeed1 = 2;
let ySpeed1 = -2;
let xSpeed2 = 2;
let ySpeed2 = -2;

function setup() {
  createCanvas(800, 800);
}

function draw() {
  // clear out old frames
	background(20,135,235,55)
// draw current frame based on state
  circle(circleX1, circleY1, 5);
  circle(circleX2,circleY2,5)

  // modify state
  circleX1 = circleX1 + xSpeed1*random(1);
  circleY1 = circleY1 + ySpeed1*random(1);
  circleX2= circleX2 + xSpeed2*random(1);
  circleY2= circleY2 + ySpeed2*random(1);

  //bounce off left and right
  if(circleX1< 0 || circleX1> width) {
    xSpeed1 = xSpeed1 * -1;
  }

  // bounce off top and bottom
  if(circleY1< 0 || circleY1> height) {
    ySpeed1 = ySpeed1 * -1;
  }
  if(circleX2< 0 || circleX2> width) {
    xSpeed2 = xSpeed2 * -1;
  }

  // bounce off top and bottom
  if(circleY2 < 0 || circleY2 > height) {
    ySpeed2 = ySpeed2 * -1;
  }
}
