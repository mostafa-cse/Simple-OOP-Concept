
<!DOCTYPE html>
<html lang="en">
<body>

<h1>OOP and Relationship Concepts in C++</h1>

<p>This document explains key Object-Oriented Programming (OOP) properties and relationship concepts in C++ with examples, explanations, and summaries.</p>

<hr/>

<h2>🧩 1. Encapsulation</h2>

<h3>Definition</h3>
<p>Encapsulation means binding data and methods into a single unit (class) and controlling access using access modifiers.</p>

<h3>How it Works?</h3>
<p>Internal data is marked <code>private</code> or <code>protected</code>. Access is provided by <code>public</code> methods (setters/getters).</p>

<h3>Example</h3>

<pre><code class="language-cpp">
class Employee {
private:
    string name;
    int id;
    double salary;

public:
    Employee(string n, int i, double s) : name(n), id(i), salary(s) {}

    void setSalary(double s) { if(s > 0) salary = s; }
    double getSalary() { return salary; }

    string getName() const { return name; }
    int getId() const { return id; }

    void showInfo() {
        cout &lt;&lt; "Name: " &lt;&lt; name &lt;&lt; ", ID: " &lt;&lt; id &lt;&lt; ", Salary: $" &lt;&lt; salary &lt;&lt; endl;
    }
};
</code></pre>

<h3>Explanation</h3>
<p>Internal values can’t be changed directly; only through public functions ensuring control, security, and validation.</p>

<h3>Conclusion</h3>
<p>Encapsulation hides data, allowing controlled access and modification to protect object integrity.</p>

<hr/>

<h2>🎩 2. Abstraction</h2>

<h3>Definition</h3>
<p>Abstraction means showing only essential information and hiding internal implementations (via abstract classes).</p>

<h3>How it Works?</h3>
<p>Using pure virtual functions to ensure only the interface is visible; subclasses implement hidden details.</p>

<h3>Example</h3>

<pre><code class="language-cpp">
class PaymentMethod {
public:
    virtual void pay(double amount) = 0;
};

class CreditCard : public PaymentMethod {
public:
    void pay(double amount) override {
        cout &lt;&lt; "Paid $" &lt;&lt; amount &lt;&lt; " by Credit Card." &lt;&lt; endl;
    }
};
</code></pre>

<h3>Explanation</h3>
<p>Clients don’t see how paying works, only that it works via the <code>pay()</code> method.</p>

<h3>Conclusion</h3>
<p>Abstraction helps reduce complexity by hiding how things are done and only exposing what is necessary.</p>

<hr/>

<h2>🏛️ 3. Inheritance</h2>

<h3>Definition</h3>
<p>Inheritance allows a class to derive properties and methods from another class, promoting reusability.</p>

<h3>How it Works?</h3>
<p>A child class uses the base class’s public/protected members unless overridden.</p>

<h3>Example</h3>

<pre><code class="language-cpp">
class Vehicle {
protected:
    string brand;
    int year;

public:
    Vehicle(string b, int y) : brand(b), year(y) {}
};

class Car : public Vehicle {
    int seats;
public:
    Car(string b, int y, int s) : Vehicle(b, y), seats(s) {}
};
</code></pre>

<h3>Explanation</h3>
<p>Car inherits brand/year from Vehicle and adds new properties. This avoids code duplication.</p>

<h3>Conclusion</h3>
<p>Inheritance helps you build new classes quickly using existing, tested code.</p>

<hr/>

<h2>🌀 4. Polymorphism</h2>

<h3>Definition</h3>
<p>Polymorphism allows objects to take many forms while sharing a common interface.</p>

<h3>How it Works?</h3>
<p>Implemented via <code>virtual</code> functions (Run-time) or overloaded methods (Compile-time).</p>

<h3>Example</h3>

<pre><code class="language-cpp">
class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() override { cout &lt;&lt; "Drawing Circle" &lt;&lt; endl; }
};
</code></pre>

<h3>Explanation</h3>
<p>Different shapes implement the same <code>draw()</code> behavior in different ways.</p>

<h3>Conclusion</h3>
<p>Polymorphism provides flexibility and interface-driven development using shared methods.</p>

<hr/>

<h1>🔗 Relationship Concepts in OOP</h1>

<h2>🤝 1. Association</h2>

<h3>Definition</h3>
<p>A general relationship where objects use each other but are logically independent.</p>

<h3>Example</h3>

<pre><code class="language-cpp">
class Teacher {
    string name;
public:
    Teacher(string n) : name(n) {}
};

class School {
public:
    void assignTeacher(Teacher* t) {
        cout &lt;&lt; "Assigned: " &lt;&lt; t-&gt;getName() &lt;&lt; endl;
    }
};
</code></pre>

<h3>Conclusion</h3>
<p>Association connects objects that operate together, but don’t depend on each other’s existence.</p>

<hr/>

<h2>🧱 2. Aggregation</h2>

<h3>Definition</h3>
<p>“Has-a” relationship where one class contains another without owning its lifecycle.</p>

<h3>Example</h3>

<pre><code class="language-cpp">
class Department {
    vector&lt;Student*&gt; students;
public:
    void addStudent(Student* s) { students.push_back(s); }
};
</code></pre>

<h3>Conclusion</h3>
<p>Students can exist outside the department—a weak relationship that promotes flexibility.</p>

<hr/>

<h2>🏗️ 3. Composition</h2>

<h3>Definition</h3>
<p>Strong ownership relationship where the contained object’s lifecycle is tied to the parent.</p>

<h3>Example</h3>

<pre><code class="language-cpp">
class Car {
    Engine engine;
public:
    Car(int hp) : engine(hp) {}
};
</code></pre>

<h3>Conclusion</h3>
<p>When the Car is destroyed, so is its Engine. Composition ensures tight coupling.</p>

<hr/>

<h2>🔄 4. Dependency</h2>

<h3>Definition</h3>
<p>One class depends on another temporarily—e.g., as a method parameter or local variable.</p>

<h3>Example</h3>

<pre><code class="language-cpp">
class Logger {
public:
    void log(string msg) { cout &lt;&lt; "Log: " &lt;&lt; msg &lt;&lt; endl; }
};

class Payment {
public:
    void process(Logger& logger) {
        logger.log("Payment processed");
    }
};
</code></pre>

<h3>Conclusion</h3>
<p>Used for temporary interaction—ideal for modular, loosely coupled designs.</p>

<hr/>
</body>
</html>
