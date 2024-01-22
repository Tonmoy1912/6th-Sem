const fs=require('fs');
const userpath="./public/storage/users.json";
const imagepath="./public/storage/images.json";
const textpath="./public/storage/texts.json";


function addUser(email,password){
    let users=fs.readFileSync(userpath,"utf-8");
    users=JSON.parse(users);
    users[email]=password;
    fs.writeFileSync(userpath,JSON.stringify(users));
}

function getUserPassword(email){
    let users=fs.readFileSync(userpath,"utf-8");
    users=JSON.parse(users);
    // console.log(users);
    return users[email];
    // fs.writeFileSync(userpath,JSON.stringify(users));
}

function addImage(email,url){
    let images=fs.readFileSync(imagepath,"utf-8");
    images=JSON.parse(images);
    if(!images[email]){
      images[email]=[];  
    }
    images[email].push(url);
    fs.writeFileSync(imagepath,JSON.stringify(images));
}

function addText(email,text){
    let texts=fs.readFileSync(textpath,"utf-8");
    texts=JSON.parse(texts);
    if(!texts[email]){
      texts[email]=[];  
    }
    texts[email].push(text);
    fs.writeFileSync(textpath,JSON.stringify(texts));
}

function getImage(email){
    let images=fs.readFileSync(imagepath,"utf-8");
    images=JSON.parse(images);
    if(!images[email]){
        return [];
    }
    return images[email];
    // if(!images[email]){
    //   images[email]=[];  
    // }
    // images[email].push(url);
    // fs.writeFileSync(imagepath,JSON.stringify(images));
}

function getText(email){
    let texts=fs.readFileSync(textpath,"utf-8");
    texts=JSON.parse(texts);
    if(!texts[email]){
        return [];
    }
    return texts[email];
    // if(!texts[email]){
    //   texts[email]=[];  
    // }
    // texts[email].push(text);
    // fs.writeFileSync(textpath,JSON.stringify(texts));
}

module.exports={
    addUser,
    getUserPassword,
    addImage,
    getImage,
    addText,
    getText
};