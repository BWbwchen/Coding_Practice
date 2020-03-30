const path = require('path');
const http = require('http');
const express = require('express');
const socketio = require('socket.io');
const formatMessage = require('./utils/message.js');
const {userJoin, getCurrentUser, userLeave, getRoomUsers} = require('./utils/users.js');



const app = express();
const server = http.createServer(app);
const io = socketio(server);

const PORT = 3000 || process.env.PORT;
const botName = 'Chat Bot';

// -------------------- main ------------------- //

// set static folder
// use what folder
app.use(express.static(path.join(__dirname, 'public')));

// run when client connection
io.on('connection',(socket) => {

    socket.on('joinroom', ({username, room}) => {
        const user = userJoin(socket.id, username, room);
        socket.join(user.room);

        // send welcome message 
        // emit to the user who connecting 
        socket.emit('message', formatMessage(botName, 'Welcome budy!'));

        // broadcase when a user connect
        // to everybody except the user who connecting
        socket.broadcast.to(user.room).emit(
            'message', formatMessage(botName, `${user.username} join the room`)
        );

        // send new users and room info
        io.to(user.room).emit('roomUsers', {
            room: user.room,
            users: getRoomUsers(user.room)
        });
    });


    // register a disconnect event handler who
    socket.on('disconnect', () => {
        const user = userLeave(socket.id);
        if (user) {
            // to all user , everybody
            io.to(user.room).emit('message', formatMessage(botName, `${user.username} have left the chat`));

            // send new users and room info
            io.to(user.room).emit('roomUsers', {
                room: user.room,
                users: getRoomUsers(user.room)
            });
        }

        
    });

    // listen for client chat message 
    socket.on('chatMessage', (msg) => {
        const user = getCurrentUser(socket.id);
        // send the message to everybody 
        io.to(user.room).emit('message',formatMessage(user.username, msg));
    });

});




server.listen(PORT, () => console.log(`listen on port  ${PORT}`));