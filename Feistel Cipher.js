let str="ABCD"
let key=[]
let n=16
let encrypt=""
let decrypt=""

function Encrypt(){
    for(let i=0;i<n;i++){
        let temp=[]
        for(j=0;j<Math.floor(str.length/2);j++)
        {
            temp.push(Math.floor(Math.random()*100))
        }
        key.push(temp);
    }
    let L1,R1,K1,F1=[]
    L1=str.slice(0,Math.floor(str.length/2)).split("").map((char)=>{
        return char.charCodeAt(0)
    })
    R1=str.slice(Math.floor(str.length/2),str.length).split("").map((char)=>{
        return char.charCodeAt(0)
    })

    for(let i=0;i<n;i++)
    {
        let temp=[...R1];
        F1=[]
        for(j=0;j<R1.length;j++)
        {
            F1.push(R1[j]^key[i][j])
        }   
        for(j=0;j<R1.length;j++)
        {
            R1[j]=F1[j]^L1[j]
        }   
        L1=temp
    }
    let text=L1.concat(R1)
    for(i=0;i<text.length;i++)
    {
        encrypt+=String.fromCharCode(text[i]);
    }
}


