import React, { useRef, useState } from 'react';
import { useRecoilState } from 'recoil';
import { studentsAtom } from './store/studentAtom';
import { departmentsAtom } from './store/departmentAtom';
let n = 5;

export default function DisplayPage() {
    const [students, setStudents] = useRecoilState(studentsAtom);
    const [departments,setDepartments]=useRecoilState(departmentsAtom);
    // const n=useRef(0);
    const [curWindow, setCurWindow] = useState(students.slice(0, 5));
    function next() {
        setCurWindow(students.slice(n, n + 5));
        n = n + 5;
    }
    function prev() {
        // if(n>=students.length){
        //     n-=10;
        // }
        n -= 10;
        setCurWindow(students.slice(n, n + 5));
        n += 5;
    }
    function getDepartmentName(code,departments){
        return departments.find(x=>x.code==code).name;
    }
    return (
        <div className='flex flex-col items-center gap-5 '>
            <h1 className='text-2xl p-3 text-center'>Display page</h1>
            {
                curWindow.map(student => {
                    return (
                        <p className='bg-blue-300 text-black p-2'>
                            Name: {student.name} | Roll: {student.roll} | Department: {getDepartmentName(student.code, departments)} | Address: {student.address}
                        </p>
                    )
                })
            }
            <div className=' w-10/12 flex justify-between'>
                <button className={`p-1 ${n<=5?"bg-blue-500":"bg-blue-800"} text-white`} onClick={prev} disabled={n<=5}>Prev</button>
                <button className={`p-1 ${n>=students.length?"bg-blue-500":"bg-blue-800"} text-white`} onClick={next} disabled={n>=students.length}>Next</button>
            </div>
        </div>
    )
}
