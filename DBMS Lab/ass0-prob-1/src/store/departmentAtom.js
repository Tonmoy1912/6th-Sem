import { atom } from "recoil";

export const departmentsAtom=atom({
    key:"departmentAtom",
    default:[
        {
            name:"CSE",
            code:"1234"
        },
        {
            name:"IT",
            code:"2345"
        },
        {
            name:"EE",
            code:"3456"
        }
    ]
})