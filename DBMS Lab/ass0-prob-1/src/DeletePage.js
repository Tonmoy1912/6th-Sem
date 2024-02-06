import React, { useState } from 'react';
import { useRecoilState } from 'recoil';
import { studentsAtom } from './store/studentAtom';
import { departmentsAtom } from './store/departmentAtom';

export default function SearchPage() {
    const [students,setStudents]=useRecoilState(studentsAtom);
    const [departments,setDepartments]=useRecoilState(departmentsAtom);
    const [student,setStudent]=useState(null);
    const [data,setData]=useState("");
    function clickHandler(){
        const s=students.find(x=>x.roll==data);
        // console.log(s);
        // console.log(students)
        if(!s){
            alert("No student found");
            return ;
        }
        let l=students.filter(s=>s.roll!=data);
        setStudents([...l]);
        alert("Deleted");
    }
    function getDepartmentName(code,departments){
        return departments.find(x=>x.code==code).name;
    }
  return (
    <div className='flex flex-col items-center gap-5 '>
        <h1 className='text-2xl p-3 text-center'>Delete page</h1>
        <input type="text" placeholder='Enter roll' value={data} onChange={(e)=>{setData(e.target.value)}} className='border border-black'/>
        <button className='p-1 bg-blue-800 text-white' onClick={clickHandler} >Delete</button>
        
    </div>
  )
}
