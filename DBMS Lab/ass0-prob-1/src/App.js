import { useState } from "react";
import AddPage from "./AddPage";
import DeletePage from "./DeletePage";
import EditPage from "./EditPage";
import SearchPage from "./SearchPage";
import DisplayPage from "./DisplayPage";


function App() {
  const [page,setPage]=useState("Display");
  return (
    <div>
      <nav className="h-8 flex justify-around bg-blue-500 text-white mb-8">
          <button onClick={()=>{setPage("Display")}} >Display</button>
          <button onClick={()=>{setPage("Add")}} >Add</button>
          <button  onClick={()=>{setPage("Edit")}}>Edit</button>
          <button onClick={()=>{setPage("Delete")}}>Delete</button>
          <button onClick={()=>{setPage("Search")}}>Search</button>
      </nav>
      {page=="Display" && <DisplayPage/>}
      {page=="Add" && <AddPage/>}
      {page=="Edit" && <EditPage/>}
      {page=="Delete" && <DeletePage/>}
      {page=="Search" && <SearchPage/>}
    </div>
  )
}

export default App;
