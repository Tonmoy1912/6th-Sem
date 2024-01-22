const express=require('express');
const cors=require('cors');
const multer=require('multer');
// const bodyParser=require('body-parser');
const path=require('path');
const expressLayouts=require('express-ejs-layouts');
const cookieParser = require('cookie-parser');
const jwt=require('jsonwebtoken');
require('dotenv').config();
const middleware=require("./utility/middleware");
const fs=require('fs');
const db=require("./utility/db")




const port=8000;
const secret=process.env.SECRET;


const app=express();
app.use(express.json());
app.use(express.urlencoded());
app.use(cookieParser());
app.use(cors());
app.use(expressLayouts);
app.use(express.static('public'));
// app.use(bodyParser());


app.set('views',path.join(__dirname,'views'));
app.set('view engine','ejs');


// Set the storage engine
const storage = multer.diskStorage({
    destination: function (req, file, cb) {
        cb(null, './public/images/');  // Uploads will be stored in the 'uploads' directory
    },
    filename: function (req, file, cb) {
        cb(null, file.fieldname + '-' + Date.now() + path.extname(file.originalname));
    }
});

// Initialize Multer with the storage engine
const upload = multer({ storage: storage });

//........................................page request.........................
//register page
app.get("/",function(req,res){
    res.render("register.ejs",{signin:req.authorized});
});

app.get("/file-upload-page",middleware.authCheck,function(req,res){
    
    res.render("file_upload_page.ejs",{signin:req.authorized});
});

app.get("/text-upload-page",middleware.authCheck,function(req,res){
    
    res.render("text_upload_page.ejs",{signin:req.authorized});
});

app.get("/file-show-page",middleware.authCheck,function(req,res){
    // const images=["/images/myImage-1705932093864.png"]
    const images=db.getImage(req.user.email);
    // console.log("images",images);
    res.render("file_show_page.ejs",{images,signin:req.authorized});
});

app.get("/text-show-page",middleware.authCheck,async function(req,res){
    // const textdb=fs.readFileSync("./public/storage/texts.json","utf-8");
    // console.log(JSON.parse(textdb)["tonmoy"]);
    // const texts=["nice text 1","nice text 1","nice text 1","nice text 1","nice text 1","nice text 1","nice text 1"];
    const texts=db.getText(req.user.email);
    res.render("text_show_page.ejs",{texts,signin:req.authorized});
});


//....................api.........................
app.post('/upload-image',middleware.authCheck, upload.single('myImage'), (req, res) => {
    // Multer has added the 'file' object to the request
    const file = req.file;
    
    if (!file) {
        return res.status(400).send("No file uploaded");
    }

    // You can access file properties like file.path, file.filename, etc.
    // Perform additional actions (e.g., save the file path in a database)

    // res.send('File uploaded!');
    // return res.status(200).json({ok:true,message:"File uploaded successfully"});
    // console.log("file",file);
    const filepath=`/images/${file.filename}`;
    db.addImage(req.user.email,filepath);
    return res.redirect("/file-show-page")
});

app.post("/upload-text",middleware.authCheck,function(req,res){
    // console.log(req.body);
    db.addText(req.user.email,req.body.text);
    res.redirect("/text-show-page");
});

app.get("/logout",function(req,res){
    res.clearCookie("jwt");
    res.redirect("/");
});

app.post("/register",async function(req,res){
    // console.log(req.body);
    const password=db.getUserPassword(req.body.email);
    if(password){
        if(password!=req.body.password){
            return res.send("wrong password")
        }
    }
    else{
        db.addUser(req.body.email,req.body.password);
    }
    const token= jwt.sign({email:req.body.email},secret);
    res.cookie("jwt",token);
    res.redirect("/text-show-page");
})

app.listen(port,function(err){
    if(!err){
        console.log(`The server is running on port ${port}`);
    }
    else{
        console.log(`Error: ${err.message}`);
    }
})