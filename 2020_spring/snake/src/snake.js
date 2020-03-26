import p5 from 'p5'
const p = new p5();
export default class Snake {
    constructor() {
        this.x = 0;
        this.y = 0;
        this.width = 10;
        this.xSpeed = 1;
        this.ySpeed = 0;
    }
    update () {
        this.x += this.xSpeed;
    }

    draw () {
        p.fill (255);
        p.rect(this.x, this.y, this.width, this.width);
    }

}
