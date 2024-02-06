import React, { Fragment, useState } from 'react';
import { useRecoilState } from 'recoil';
import { studentsAtom } from './store/studentAtom';
import { departmentsAtom } from './store/departmentAtom';

export default function SearchPage() {
    const [students, setStudents] = useRecoilState(studentsAtom);
    const [departments, setDepartments] = useRecoilState(departmentsAtom);
    const [student, setStudent] = useState(null);
    const [data, setData] = useState("");
    const [editedData, setEditedData] = useState(null);
    function clickHandler() {
        const s = students.find(x => x.roll == data);
        // console.log(s);
        // console.log(students)
        if (!s) {
            alert("No student found");
            return;
        }
        setStudent({ ...s });
        setEditedData({ ...s });
    }
    function getDepartmentName(code, departments) {
        return departments.find(x => x.code == code).name;
    }
    function changeHandler(e) {
        setEditedData({ ...editedData, [e.target.name]: e.target.value });
    }
    function clickHandler2(){
        // console.log(editedData);
        const l=students.map(s=>{return s.roll==editedData.roll?{...editedData}:s;})
        setStudents([...l]);
        alert("Edited");
    }
    return (
        <div className='flex flex-col items-center gap-5 '>
            <h1 className='text-2xl p-3 text-center'>Edit page</h1>
            <input type="text" placeholder='Enter roll' value={data} onChange={(e) => { setData(e.target.value) }} className='border border-black' />
            <button className='p-1 bg-blue-800 text-white' onClick={clickHandler} >Search</button>
            {student &&
                <Fragment>
                <div className='bg-blue-300 text-black p-2 flex flex-col items-center gap-2'>
                    Name: 
                    <input type="text" placeholder='Name' name='name' value={editedData.name} onChange={changeHandler} />
                    Roll: 
                    <input type="text" value={editedData.roll} disabled={true} />
                    Address: 
                    <input type="text" placeholder='Address' name='address' value={editedData.address} onChange={changeHandler} />
                    Phone:
                    <input type="text" placeholder='Phone' name='phone' value={editedData.phone} onChange={changeHandler} />
                    Department:
                    <select name="code" id="" value={editedData.code} onChange={changeHandler}>
                        {
                            departments.map((department) => {
                                return <option value={department.code} key={department.code}>{department.name}</option>
                            })
                        }
                    </select>
                </div>
                <button className='p-1 bg-blue-800 text-white' onClick={clickHandler2} >Edit</button>
                </Fragment>
            }
        </div>
    )
}
