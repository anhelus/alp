L'architettura di Von Neumann venne inizialmente proposta nel 1945 da John Von Neumann.

Storicamente, esistono due tipi di architetture:

1. **fixed program computers**, il cui funzionamento è speicfico e non possono essere riprogrammati, come ad esempio le calcolatrici
2. **stored program computers**, il cui funzionamento può essere riprogrammato per effettuare diversi task differnti

I moderni computer sono ovviamente basati sul concetto di stored-program introdotto da John VOn Neumann. IN questo concetto, i programmi ed i dati sono memorizzati in uno spazio riservato chiamato *memoria*é Questa idea, all'ìepoca innovativa, implicava cheun comptuer costruito con l'archiettura di Von Neumann sarebbe stato molto più semplice da riprogrammare.

La struttura base 

The basic structure is like this, 



It is also known as ISA (Instruction set architecture) computer and is having three basic units:  

The Central Processing Unit (CPU) 
The Main Memory Unit 
The Input/Output Device Let’s consider them in detail.
         1. Central Processing Unit-

          The central processing unit is defined as the it is an electric circuit used for the executing the instruction of computer program.

          It has following major components:

          1.Control Unit(CU)

          2.Arithmetic and Logic Unit(ALU)

          3.variety of Registers

Control Unit – 
A control unit (CU) handles all processor control signals. It directs all input and output flow, fetches code for instructions, and controls how data moves around the system. 
Arithmetic and Logic Unit (ALU) – 
The arithmetic logic unit is that part of the CPU that handles all the calculations the CPU may need, e.g. Addition, Subtraction, Comparisons. It performs Logical Operations, Bit Shifting Operations, and Arithmetic operations. 


Figure – Basic CPU structure, illustrating ALU 

Registers – Registers refer to high-speed storage areas in the CPU. The data processed by the CPU are fetched from the registers. There are different types of registers used in architecture :-
Accumulator: Stores the results of calculations made by ALU. It holds the intermediate of arithmetic and logical operatoins.it act as  a temporary storage location or device.
Program Counter (PC): Keeps track of the memory location of the next instructions to be dealt with. The PC then passes this next address to the Memory Address Register (MAR). 
Memory Address Register (MAR): It stores the memory locations of instructions that need to be fetched from memory or stored in memory. 
Memory Data Register (MDR): It stores instructions fetched from memory or any data that is to be transferred to, and stored in, memory. 
Current Instruction Register (CIR): It stores the most recently fetched instructions while it is waiting to be coded and executed. 
Instruction Buffer Register (IBR): The instruction that is not to be executed immediately is placed in the instruction buffer register IBR. 
 
Buses – Data is transmitted from one part of a computer to another, connecting all major internal components to the CPU and memory, by the means of Buses. Types: 
Data Bus: It carries data among the memory unit, the I/O devices, and the processor. 
Address Bus: It carries the address of data (not the actual data) between memory and processor. 
Control Bus: It carries control commands from the CPU (and status signals from other devices) in order to control and coordinate all the activities within the computer.
Input/Output Devices – Program or data is read into main memory from the input device or secondary storage under the control of CPU input instruction. Output devices are used to output information from a computer. If some results are evaluated by the computer and it is stored in the computer, then with the help of output devices, we can present them to the user.
Von Neumann bottleneck – 
Whatever we do to enhance performance, we cannot get away from the fact that instructions can only be done one at a time and can only be carried out sequentially. Both of these factors hold back the competence of the CPU. This is commonly referred to as the ‘Von Neumann bottleneck’. We can provide a Von Neumann processor with more cache, more RAM, or faster components but if original gains are to be made in CPU performance then an influential inspection needs to take place of CPU configuration. 

This architecture is very important and is used in our PCs and even in Super Computers.




In a normal computer that follows von Neumann architecture, instructions, and data both are stored in the same memory. So same buses are used to fetch instructions and data. This means the CPU cannot do both things together (read the instruction and read/write data). Harvard Architecture is the computer architecture that contains separate storage and separate buses (signal path) for instruction and data. It was basically developed to overcome the bottleneck of Von Neumann’s Architecture. The main advantage of having separate buses for instruction and data is that the CPU can access instructions and read/write data at the same time. 

Structure of Harvard Architecture: 

Structure of Harvard Architecture
Structure of Harvard Architecture

Buses

Buses are used as signal pathways. In Harvard architecture, there are separate buses for both instruction and data. Types of Buses: 


Data Bus: It carries data among the main memory system, processor, and I/O devices. 
Data Address Bus: It carries the address of data from the processor to the main memory system. 
Instruction Bus: It carries instructions among the main memory system, processor, and I/O devices. 
Instruction Address Bus: It carries the address of instructions from the processor to the main memory system. 
Operational Registers

There are different types of registers involved in it which are used for storing addresses of different types of instructions. For example, the Memory Address Register and Memory Data Register are operational registers. 

Program Counter: It has the location of the next instruction to be executed. The program counter then passes this next address to the memory address register. 
Arithmetic and Logic Unit: The arithmetic logic unit is part of the CPU that operates all the calculations needed. It performs addition, subtraction, comparison, logical Operations, bit Shifting Operations, and various arithmetic operations. 
Control Unit:  The Control Unit is the part of the CPU that operates all processor control signals. It controls the input and output devices and also controls the movement of instructions and data within the system. 
Input/Output System: Input devices are used to read data into main memory with the help of CPU input instruction. The information from a computer as output is given through Output devices. The computer gives the results of computation with the help of output devices. 
 Features:

Separate memory spaces: In Harvard architecture, there are separate memory spaces for instructions and data. This separation ensures that the processor can access both the instruction and data memories simultaneously, allowing for faster and more efficient data retrieval.
Fixed instruction length: In Harvard architecture, instructions are typically of fixed length, which simplifies the instruction fetch process and allows for faster instruction processing.
Parallel instruction and data access: Since Harvard architecture separates the memory spaces for instructions and data, the processor can access both memory spaces simultaneously, allowing for parallel instruction and data processing.
More efficient memory usage: Harvard architecture allows for more efficient use of memory as the data and instruction memories can be optimized independently, which can lead to better performance.
Suitable for embedded systems: Harvard architecture is commonly used in embedded systems because it provides fast and efficient access to both instructions and data, which is critical in real-time applications.
Limited flexibility: The separate memory spaces in Harvard architecture limit the flexibility of the processor to perform certain tasks, such as modifying instructions at runtime. This is because modifying instructions requires access to the instruction memory, which is separate from the data memory.
Advantage of Harvard Architecture: 

Harvard architecture has two separate buses for instruction and data. Hence, the CPU can access instructions and read/write data at the same time. This is the major advantage of Harvard architecture. 

In practice, Modified Harvard Architecture is used where we have two separate caches (data and instruction). This is common and used in X86 and ARM processors.

Fast and efficient data access: Since Harvard architecture has separate memory spaces for instructions and data, it allows for parallel and simultaneous access to both memory spaces, which leads to faster and more efficient data access.
Better performance: The use of fixed instruction length, parallel processing, and optimized memory usage in Harvard architecture can lead to improved performance and faster execution of instructions.
Suitable for real-time applications: Harvard architecture is commonly used in embedded systems and other real-time applications where speed and efficiency are critical.
Security: The separation of instruction and data memory spaces can also provide a degree of security against certain types of attacks, such as buffer overflow attacks.
Disadvantages of Harvard Architecture:

Complexity: The use of separate memory spaces for instructions and data in Harvard architecture adds to the complexity of the processor design and can increase the cost of manufacturing.
Limited flexibility: Harvard architecture has limited flexibility in terms of modifying instructions at runtime because instructions and data are stored in separate memory spaces. This can make certain types of programming more difficult or impossible to implement.
Higher memory requirements: Harvard architecture requires more memory than Von Neumann architecture, which can lead to higher costs and power consumption.
Code size limitations: Fixed instruction length in Harvard architecture can limit the size of code that can be executed, making it unsuitable for some applications with larger code bases.