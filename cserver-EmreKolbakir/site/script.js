const canvas = document.getElementById("starCanvas");
const ctx = canvas.getContext("2d");
canvas.width = window.innerWidth;
canvas.height = window.innerHeight;

let stars = [];
let movingStars = [];

function createStars(count) {
    for (let i = 0; i < count; i++) {
        stars.push({
            x: Math.random() * canvas.width,
            y: Math.random() * canvas.height,
            size: (Math.random() * 2 + 1) * 0.6
        });
        if (Math.random() > 0.9) {
            movingStars.push({
                x: Math.random() * canvas.width,
                y: Math.random() * canvas.height,
                size: (Math.random() * 2 + 1) * 0.7,
                speed: Math.random() * 0.5 + 0.2
            });
        }
    }
}

function moveStars() {
    for (let star of movingStars) {
        star.y += star.speed;
        if (star.y > canvas.height) {
            star.y = 0;
            star.x = Math.random() * canvas.width;
        }
    }
}

function drawStars() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    ctx.fillStyle = "#FFFFFF";
    for (let star of stars) {
        ctx.beginPath();
        ctx.arc(star.x, star.y, star.size, 0, Math.PI * 2);
        ctx.fill();
    }
    for (let star of movingStars) {
        ctx.beginPath();
        ctx.arc(star.x, star.y, star.size, 0, Math.PI * 2);
        ctx.fill();
    }
}

function animate() {
    moveStars();
    drawStars();
    requestAnimationFrame(animate);
}

createStars(550);
animate();