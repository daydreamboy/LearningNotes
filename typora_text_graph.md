# Typora支持的图[^1]

[TOC]

## 1、时序图 (Sequence Diagrams)

```sequence
Alice->Bob: Hello Bob, how are you?
Note right of Bob: Bob thinks
Bob-->Alice: I am good thanks!
```

插件：https://github.com/bramp/js-sequence-diagrams

语法：https://bramp.github.io/js-sequence-diagrams/#syntax



## 2、流程图 (Flowcharts)

```flow
st=>start: Start
op=>operation: Your Operation
cond=>condition: Yes or No?
e=>end

st->op->cond
cond(yes)->e
cond(no)->op
```

插件：http://flowchart.js.org/



## 3、Mermaid

Mermaid插件：https://mermaid-js.github.io/mermaid/#/



###（1）时序图 (Sequence Diagrams)

```mermaid
%% Example of sequence diagram
  sequenceDiagram
    Alice->>Bob: Hello Bob, how are you?
    alt is sick
    Bob->>Alice: Not so good :(
    else is well
    Bob->>Alice: Feeling fresh like a daisy
    end
    opt Extra response
    Bob->>Alice: Thanks for asking
    end
```

###（2）流程图 (Flowcharts)

```mermaid
graph LR
A[Hard edge] -->B(Round edge)
B --> C{Decision}
C -->|One| D[Result one]
C -->|Two| E[Result two]
E --> F[End]
```
###（3）甘特图 (Gantt Charts)

```mermaid
%% Example with selection of syntaxes
        gantt
        dateFormat  YYYY-MM-DD
        title Adding GANTT diagram functionality to mermaid

        section A section
        Completed task            :done,    des1, 2014-01-06,2014-01-08
        Active task               :active,  des2, 2014-01-09, 3d
        Future task               :         des3, after des2, 5d
        Future task2               :         des4, after des3, 5d

        section Critical tasks
        Completed task in the critical line :crit, done, 2014-01-06,24h
        Implement parser and jison          :crit, done, after des1, 2d
        Create tests for parser             :crit, active, 3d
        Future task in critical line        :crit, 5d
        Create tests for renderer           :2d
        Add to mermaid                      :1d

        section Documentation
        Describe gantt syntax               :active, a1, after des1, 3d
        Add gantt diagram to demo page      :after a1  , 20h
        Add another diagram to demo page    :doc1, after a1  , 48h

        section Last section
        Describe gantt syntax               :after doc1, 3d
        Add gantt diagram to demo page      : 20h
        Add another diagram to demo page    : 48h
```

###（4）类图 (Class Diagrams)

```mermaid
classDiagram
      Animal <|-- Duck
      Animal <|-- Fish
      Animal <|-- Zebra
      Animal : +int age
      Animal : +String gender
      Animal: +isMammal()
      Animal: +mate()
      class Duck{
          +String beakColor
          +swim()
          +quack()
      }
      class Fish{
          -int sizeInFeet
          -canEat()
      }
      class Zebra{
          +bool is_wild
          +run()
      }
```

语法：https://mermaid-js.github.io/mermaid/#/classDiagram



#### a. 定义类

有两种方式，定义类

* 使用冒号`:`方式

```text
class BankAccount
BankAccount : +String owner
BankAccount : +BigDecimal balance
BankAccount : +deposit(amount)
BankAccount : +withdrawal(amount)
```



```mermaid
classDiagram
    class BankAccount
    BankAccount : +String owner
    BankAccount : +Bigdecimal balance
    BankAccount : +deposit(amount) 
    BankAccount : +withdrawl(amount)
```

* 使用大括号`{}`方式

```text
class BankAccount{
  +String owner
  +BigDecimal balance
  +deposit(amount) bool
  +withdrawl(amount)
}
```

```mermaid
classDiagram
class BankAccount{
  +String owner
  +BigDecimal balance
  +deposit(amount) bool
  +withdrawl(amount)
}
```

类图分为3个部分：

* 顶部部分：类名
* 中间部分：类的成员变量
* 底部部分：类的方法，一般需要一对括号表示这是个方法，而不是成员变量



#### b. 定义两个类的关系

| Type  | Description   |
| ----- | ------------- |
| <\|-- | Inheritance   |
| *--   | Composition   |
| o--   | Aggregation   |
| -->   | Association   |
| --    | Link (Solid)  |
| ..>   | Dependency    |
| ..\|> | Realization   |
| ..    | Link (Dashed) |

```mermaid
classDiagram
classA --|> classB : Inheritance
classC --* classD : Composition
classE --o classF : Aggregation
classG --> classH : Association
classI -- classJ : Link(Solid)
classK ..> classL : Dependency
classM ..|> classN : Realization
classO .. classP : Link(Dashed)
```





###（5）状态图 (State Diagrams)

```mermaid
stateDiagram
    [*] --> Still
    Still --> [*]

    Still --> Moving
    Moving --> Still
    Moving --> Crash
    Crash --> [*]
```

###（6）饼状图 (Pie Charts)

```mermaid
pie
    title Pie Chart
    "Dogs" : 386
    "Cats" : 85
    "Rats" : 150 
```


## References

[^1]:https://support.typora.io/Draw-Diagrams-With-Markdown/



