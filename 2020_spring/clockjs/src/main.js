let hh = document.querySelector(".hour");
let mm = document.querySelector(".min");
let ss = document.querySelector(".sec");

const degree = 6;
setInterval(() => {
    let time = new Date();
    let hour = time.getHours()%12;
    let minute = time.getMinutes();
    let second = time.getSeconds();

    hh.style.transform = `rotate(${hour*30 + minute/2}deg)`;
    mm.style.transform = `rotate(${minute * degree}deg)`;
    ss.style.transform = `rotate(${second * degree}deg)`;
}, 1000);
