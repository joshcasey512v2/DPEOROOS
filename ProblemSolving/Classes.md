# Classes & OOP
- A **class** is a blueprint for constructing a particular package of code and data.
- Each variable created according to the classes blueprint is known as an **object** of that class
- Code outside the class that uses it is known as a **client** of the class
- A **class declaration** names the class and lists all of the **members** or items inside the class.
- Each item is either a 
    - **Data Item:** Variable declared within the class
    - **Method / Member function:** Function delcared within the class 
- **Constructor:** A special function that has the same name as the class and is invoked implicitly when an object of the class is declared
- **Access Specifier:** Indicates what functions can access the member.
    - **Public:** Accessed by any code using the object
    - **Private:** Accessed only by the code inside the class
    - **Protected:** Similar to private except methods in subclasses can also reference them.
```c++
class Sample{       // 1
public:             // 2
    Sample();       // 3
    Sample(int num);// 4
    int doSomthing(double param); // 5
private:
    int data;
}
```

