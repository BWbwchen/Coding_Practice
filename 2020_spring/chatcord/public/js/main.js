const chatForm = document.getElementById('chat-form');
const chatMessages = document.querySelector('.chat-messages');
const roomName = document.getElementById('room-name');
const userList = document.getElementById('users');
const socket = io();

// get username and room from URL
const {username, room} = Qs.parse(location.search, {
    ignoreQueryPrefix: true
});

// Join chatroom
socket.emit('joinroom', {username, room});


// get room and users info
socket.on('roomUsers', ({room, users}) => {
    outputRoomName(room);
    outputUsers(users);
});


// handle server's message event 
socket.on('message', message => {
    console.log(message);
    // draw the message from server (everybody's message) 
    outputMessage(message);

    // receive the message and scroll to bottom
    chatMessages.scrollTop = chatMessages.scrollHeight;
});


// submit message 
chatForm.addEventListener('submit', (e) => {
    // remove default move
    e.preventDefault();

    const msg = e.target.elements.msg.value;

    // send message to server 
    socket.emit('chatMessage', msg);

    // clean the input
    e.target.elements.msg.value = '';
    e.target.elements.msg.focus();
});

// output message to DOM
function outputMessage (msg) {
    // in chat.html every message is belong to a div class name
    // message
    const div = document.createElement('div');
    div.classList.add('message');
    div.innerHTML = `<p class="meta">${msg.username} <span>${msg.time}</span></p>
    <p class="text">
       ${msg.text} 
    </p>`;
    document.querySelector('.chat-messages').appendChild(div);
}

// Add  now room name 
function outputRoomName (room) {
    roomName.innerText = room;
}

// Add  now all user name 
function outputUsers (users) {
    userList.innerHTML = `
        ${users.map(user => `<li>${user.username}</li>`).join('')}
    `;
}