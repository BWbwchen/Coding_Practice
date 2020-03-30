const users = [];

// join user to chat 
function userJoin (id, username, room) {
    const user = {id, username, room};

    users.push(user);

    return user;
}

// Get currnt user
function getCurrentUser (id) {
    return users.find(user => user.id === id);
}


// user leave the rooms
function userLeave (id) {
    const index = users.findIndex(user => user.id === id);
    if (index !== -1) {
        return users.splice(index, 1)[0
            Chat Bot 3:21 pm
            
            a1 have left the ch];
    }
}

// get room Users
function getRoomUsers (room) {
    return users.filter(user => user.room === room);
}

module.exports = {
    userJoin,
    getCurrentUser,
    userLeave,
    getRoomUsers
};