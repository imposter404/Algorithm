const POPULATION_SIZE=100
const GENE="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890,.-;:_!\"#%&/()=?@${[]}"
const TARGET="GENETIC_ALGORITHM" 

function Mutated_Genes()
{
   return GENE[Math.floor(Math.random() * GENE.length)] 
}

function Create_Chromosome()
{
    let chromosome=""
    for(let i=0;i<TARGET.length;i++)
    {
        chromosome+=Mutated_Genes();
        // console.log(chromosome)
    }
    return chromosome;
}

function Fitness(e)
{
    let fitness=0;
    for(let i=0;i<e.length;i++)
    {
        if(e[i]!=TARGET[i]){
            fitness++
        }
    }
    return fitness;
}


function Mating(parent1,parent2)
{
    let childChromosome=""
    for(let i=0;i<parent1.length;i++)
    {
        let p=Math.random();
        if(p < 0.45)
        {
            childChromosome+=parent1[i]
        }
        else if(p < 0.90)
        {
            childChromosome+=parent2[i]
        }
        else{
            childChromosome+=Mutated_Genes()
        }
    }
    let temp={
        chromosome:"",
        fitness:""
    }
    temp.chromosome=childChromosome
    temp.fitness=Fitness(childChromosome)
    // console.log("temp",temp)
    return temp;
}



let newGeneration
let arr={
    population:[]
};
let generation=0;

function ZZ(){
    generation=0
    arr={population:[]};
    let found=false;
    let temp={
            chromosome:"",
            fitness:""
    }

    for(let i=0;i<POPULATION_SIZE;i++)
    {
        temp={chromosome:"",fitness:"" }

        temp.chromosome=Create_Chromosome();
        temp.fitness=Fitness(temp.chromosome);
        arr.population.push(temp)
    }
    kkk()
}


function kkk()
{
    let found=false;
    while(!found){
        arr.population.sort((a,b)=>{
            return a.fitness - b.fitness
        })

        if (arr.population[0].fitness === 0) { 
            found = true; 
            break; 
        } 

        newGeneration = []; 
    
        for(let i=0;i<Math.floor((10 * POPULATION_SIZE) / 100);i++)
        {
            newGeneration.push(arr.population[i])
        }

        for(let i=0;i<Math.floor((90 * POPULATION_SIZE) / 100);i++)
        {
            let parent1=arr.population[Math.floor(Math.random() * 50)]
            let parent2=arr.population[Math.floor(Math.random() * 50)]
            let offspring=Mating(parent1.chromosome,parent2.chromosome)
            newGeneration.push(offspring)
        }
        arr.population = [...newGeneration]; 
        console.log("Generation: " + generation                   + "\t" + 
                    "String: "     + arr.population[0].chromosome + "\t" + 
                    "Fitness: "    + arr.population[0].fitness); 
    
        generation++; 
    }
    console.log("Generation: " + generation                   + "\t" + 
                "String: "     + arr.population[0].chromosome + "\t" + 
                "Fitness: "    + arr.population[0].fitness); 
}





// Error on line 126
// Error fixed for line 126
// Finally working.....
// 
// FINALLY FUCKING DONE :)