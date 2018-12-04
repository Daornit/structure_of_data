var bird;
var pipes = [];
var score = 0;
function setup() {
  createCanvas(640, 480);
  bird = new Bird();
  pipes.push(new Pipe());
  textSize(20);
  textFont("Georgia");
}

function draw() {
  background(0);
  for (var i = pipes.length-1; i >= 0; i--) {

    pipes[i].show();
    pipes[i].update();

    if (pipes[i].hits(bird)) {
      console.log("HIT");
    }

    if (pipes[i].offscreen()) {
      pipes.splice(i, 1);
    }
  }

  bird.update();
  bird.show();

  if (frameCount % 75 == 0) {
    pipes.push(new Pipe());
    score++;
  }
  fill(50, 50, 50);
  rect(width-120, 25, 90, 60);
  dispScore(score);
}

function keyPressed() {
  if (key == ' ') {
    bird.up();
    //console.log("SPACE");
  }
}
function dispScore(sc){
  fill(250, 250, 250);
  text(sc, width-90, 60);
}
