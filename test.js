const nameDiv = document.getElementById('name');

function randomPosition() {
    const screenWidth = window.innerWidth;
    const screenHeight = window.innerHeight;
    const x = Math.floor(Math.random() * (screenWidth - nameDiv.clientWidth));
    const y = Math.floor(Math.random() * (screenHeight - nameDiv.clientHeight));
    
    nameDiv.style.left = `${x}px`;
    nameDiv.style.top = `${y + 50}px`; // Adjusting to avoid the error message
}

setInterval(randomPosition, 3000); // Change position every 3 seconds

function goHome() {
    window.location.href = '/'; // Replace with the actual home page URL
}
