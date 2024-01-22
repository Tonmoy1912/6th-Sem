// import logo from './logo.svg';
// import './App.css';

const host="http://127.0.0.1:8000"

function App() {
  return (
    <div className="w-screen h-screen flex flex-col gap-8 justify-start items-center ">
      <form className="flex flex-col gap-3 justify-center items-center h-[60%] w-[70%] rounded-lg bg-slate-300"
        action={`${host}/upload` }method="post" enctype="multipart/form-data">
        <textarea name="" id="" cols="30" rows="10" placeholder="Enter the text"></textarea>
        <input type="file" name="file" />
        <button type="submit" className="p-2 bg-blue-600 rounded-lg">Upload</button>
      </form>
    </div>
  );
}

export default App;
