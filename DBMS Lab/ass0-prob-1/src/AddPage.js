import React, { Fragment, useState } from 'react';
import { useRecoilState } from 'recoil';
import { studentsAtom } from './store/studentAtom';
import { departmentsAtom } from './store/departmentAtom';
import { rollAtom } from './store/uniqueRollAtom';

export default function AddPage() {
    const [students, setStudents] = useRecoilState(studentsAtom);
    const [departments, setDepartments] = useRecoilState(departmentsAtom);
    const [roll,setRoll]=useRecoilState(rollAtom);
    const [data,setData]=useState({name:"",phone:"",address:"",code:departments[0].code});
    function changeHandler(e){
        setData({...data,[e.target.name]:e.target.value});
    }
    function clickHandler(){
        console.log(data);
        setStudents([...students,{...data,roll:roll}]);
        setRoll(roll+1);//to keep the roll unique
        alert("Student added");
    }
    return (
        <Fragment>
            <h1 className='text-2xl p-3 text-center'>Add student</h1>
            <div className='bg-slate-400  flex flex-col gap-5 items-center mr-auto p-4'>
                <input type="text" placeholder='Name' name='name' value={data.name} onChange={changeHandler}/>
                <input type="text" placeholder='Address' name='address' value={data.address} onChange={changeHandler}/>
                <input type="text" placeholder='Phone' name='phone' value={data.phone} onChange={changeHandler}/>
                <select name="code" id="" value={data.code} onChange={changeHandler}>
                    {
                        departments.map((department) => {
                            return <option value={department.code} key={department.code}>{department.name}</option>
                        })
                    }
                 </select>
                 <button className='p-1 bg-blue-800 text-white' onClick={clickHandler} >Add</button>
            </div>
        </Fragment>
    )
}
