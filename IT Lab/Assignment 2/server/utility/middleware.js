const jwt=require('jsonwebtoken');
require('dotenv').config();


module.exports.authCheck=async function(req,res,next){
    try{
        const secret=process.env.SECRET;
        if(!req.cookies.jwt){
            return res.redirect("/");
        }
        const user=jwt.verify(req.cookies.jwt,secret);
        req.authorized=true;
        req.user=user;
        // console.log("req.user",req.user);
        // console.log("user",user);
        next();
    }
    catch(err){
        res.clearCookie("jwt");
        return res.redirect("/");
    }
}