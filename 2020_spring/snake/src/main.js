import * as p5 from 'p5';

let s
const sketch = p5 => {
  // Variables scoped within p5
  const canvasWidth = 600;
  const canvasHeight = 600;
  // const d = new Star(500, 300, 4);

  // make library globally available
  //window.p5 = p5;
  let width = 30
  let food;
  let score = 0;
  let hscore = document.querySelector("h1");

  // Setup function
  // ======================================
  p5.setup = () => {
    let canvas = p5.createCanvas(canvasWidth, canvasHeight);
    s = new Snake();
    p5.frameRate(10);
    food = foodLocation();
  };

  // Draw function
  // ======================================
  p5.draw = () => {
    p5.background(51);

    s.death();
    if (s.eat(food) === true) {
      food = foodLocation();
      score++;
    }

    s.update();
    s.draw();

    // draw food
    p5.fill(255, 0, 0);
    p5.rect(food.x, food.y, width, width);
    hscore.textContent = "now length is : " + (score+1);
  };

  p5.keyPressed = () => {
    if (p5.keyCode ==  p5.UP_ARROW) {
      s.dir(0, -1);
    } else if (p5.keyCode ==  p5.DOWN_ARROW) {
      s.dir(0, 1);
    } else if (p5.keyCode ==  p5.RIGHT_ARROW) {
      s.dir(1, 0);
    } else if (p5.keyCode ==  p5.LEFT_ARROW) {
      s.dir(-1, 0);
    }
  }

  let foodLocation = () => {
    let col = Math.floor(canvasWidth/width);
    let row = Math.floor(canvasHeight/width);
    let pos = p5.createVector(Math.floor(p5.random(col))*width,
                              Math.floor(p5.random(row))*width);
    return pos;
  }

  class Snake {
    constructor() {
      this.x = -30;
      this.y = 0;
      this.xSpeed = 1;
      this.ySpeed = 0;
      this.total = 0;
      this.tail = [];
    }
    update () {
      // need check if it can go 
      for (let i = 0; i < this.tail.length - 1; ++i) {
        this.tail[i] = this.tail[i+1];
      }
      if (this.total >= 1) {
        this.tail[this.total-1] = p5.createVector(this.x, this.y);
      }

      this.x += this.xSpeed*width;
      this.y += this.ySpeed*width;
      //this.x = p5.constrain(this.x, 0, canvasWidth-width);
      //this.y = p5.constrain(this.y, 0, canvasHeight-width);
      console.log(this.x);
    }

    draw () {
      p5.fill (255);
      //console.log(this.tail);
      for (let i = 0; i < this.tail.length; ++i) {
        p5.rect(this.tail[i].x, this.tail[i].y, width, width);
      }
      p5.rect(this.x, this.y, width, width);
    }

    reset () {
      this.x = 0;
      this.y = 0;
      this.tail = [];
      this.total = 0;
      this.xSpeed = 1;
      this.ySpeed = 0;
      score = 0;
    }
    
    death () {

      if (0 > this.x || this.x > canvasWidth || 
          0 > this.y || this.y > canvasHeight) {
        this.reset();
      }

      for (let i = 0; i < this.tail.length; ++i) {
        if (this.tail[i].x === this.x &&
            this.tail[i].y === this.y) {
          this.reset();
          break;
        }
      }
    }

    dir (deltaX, deltaY) {
      // check if the dir is valid
      if (this.total !== 0 && (deltaX+this.xSpeed, deltaY+this.ySpeed) === (0, 0)) {
        this.xSpeed = this.xSpeed;
        this.ySpeed = this.ySpeed;
      } else {
        this.xSpeed = deltaX;
        this.ySpeed = deltaY;
      }
    }

    eat(pos) {
      let d = p5.dist(this.x, this.y, pos.x, pos.y);
      if (d < 1) {
        this.total++;
        return true;
      } else {
        return false;
      }
    }

  }

};

const P5 = new p5(sketch);