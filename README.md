---
title: Implementation of IoT report
tags: Implementation of IoT class
---
{%hackmd theme-dark %}
# Rehab Robot for Parkinson's Disease Using the Concept of Push Hand.

## Motivation
- To make an open sourced IoT device that can solve/help problems in our daily life.
    - In this case, to make robot that can help Parkinson's disease patients to rehab, borrowing idea from push-han

### What is Push-hands/推手 and why ? 
- Two-person training routines practiced in Internal Chinese Martial Arts, like Taichi
- In individuals with mild to moderate Parkinson disease, Tai Chi was shown to be a potentially effective meditation technique that may slow down disease progression. 


### Hardware I Used.
- Chassis...Base of this robot is a 4WD Mecanum wheel robot car chassis kit, which was supplied by the professor. 
- Arduino UNO...For the brain, originally, I tried Raspberry Pi, however, I discovered it is unnecessary, due to the fact it is not required to handle data(read and save sensor value, or data analysis), so I switched to Arduino Uno. It is simple, but it has enough ports for this project.
- Servo Motors...This chassis included servo motors, which can control rotation very precisely. 
- 18650 Battery...To use 4 of 12V servo motors, it requires 3 18650 batteries in series.
- Moebius 4 channel motor driver...It is possible to wire up all 4 servo motors, however, it will be too many wires, and if there are hardware failures, it makes it difficult to find the error, because of too many points to be checked. This shield solves almost everything.
- FSR sensor...It is used to check whether a patient is applying correct pressure or not.
- Speaker...To improve UI, and to give feedback. In practice mode, it is used to inform pressure is not applied enough. 
- 16x2 LCD...Displays menu, and score.
- Resistors...Mostly used for pull-up.
- LED...Used to check power coming to the breadboard.
- Pole...Scavenged from the broom I'm using, used to hold an FSR sensor.
- L shape bracket...To hold the pole vertically.


## Software Flow Chart


### General FLowchart
```flow
st=>start: Start
e=>end: End

op1=>operation: Wait
op2=>operation: Set Up(Speed, Mode, Duration)
op3=>operation: Move
op4=>operation: Report Result
op5=>operation: Easter Egg

cond1=>condition: Start pressed ?
cond2=>condition: Easter Egg ?
cond3=>condition: Process complete and over ?
cond4=>condition: Runtime system check ok ?

io1=>inputoutput: Read & Store Data
io2=>inputoutput: Control motor
io3=>inputoutput: Read tilt sensor, pressure sensor, etc...


st->op1->cond2
cond2(no)->cond1
cond2(yes)->op5(left)->op1
cond1(no)->op1
cond1(yes)->op2->op3->op4->e
```
### Flowchart in detail
#### Set Up(Spped, Mode, Duration)
```flow
s=>start: Start was pressed
e=>end: To "Move Function"

op1=>operation: Display speed menu
op2=>operation: Change and display mode
op3=>operation: Display mode menu
op4=>operation: Change and display speed
op5=>operation: Display duration menu
op6=>operation: Change and display duration

cond1=>condition: Ok pressed ?
cond2=>condition: "-" pressed ?
cond3=>condition: "+" pressed ?
cond4=>condition: Ok pressed ?
cond5=>condition: "-" pressed ?
cond6=>condition: "+" pressed ?
cond7=>condition: Ok pressed ?
cond8=>condition: "-" pressed ?
cond9=>condition: "+" pressed ?

s->op1->cond1
cond1(no)->cond2
cond2(no)->cond3
cond2(yes)->op2
cond3(yes)->op2(right)->cond1
cond3(no)->cond1
cond1(yes)->cond4

cond4(no)->cond5
cond5(no)->cond6
cond5(yes)->op4
cond6(yes)->op4(right)->cond4
cond6(no)->cond4
cond4(yes)->cond7

cond7(no)->cond8
cond8(no)->cond9
cond8(yes)->op6
cond9(yes)->op6(right)->cond7
cond9(no)->cond7
cond7(yes)->e



```
#### Move part and report result
```flow
s=>start: From "Set up"
e=>end: End of program

op1=>operation: Move based on RNG and position
op2=>operation: score++
op3=>operation:
op4=>operation:
op5=>operation:
op6=>operation:
op7=>operation:
op8=>operation:


cond1=>condition: Gone through duration ?
cond2=>condition: Is it test mode ?
cond3=>condition: Hand contact ?
cond4=>condition: Hand contact ?
cond5=>condition: Is it test mode ?
cond6=>condition:

io1=>inputoutput: Buzz
io2=>inputoutput: Display score
io3=>inputoutput: Display end message
io4=>inputoutput: End tone buzz

s->cond1(no)->cond2
cond2(no)->cond3
cond3(no)->io1(top)->cond3
cond3(yes)->op1
cond2(yes)->cond4(yes)->op2->op1
cond4(no)->op1(left)->cond1
cond1(yes)->cond5
cond5(yes)->io2->io4
cond5(no)->io3->io4
io4->e
```
---

## Circuit Diagram for UI
![](https://i.imgur.com/8LiCBHl.png)

## How to use
![](https://i.imgur.com/ySplENg.jpg)

1. Turn on the machine by shifting the switch on the shield on top of Arduino uno.
2. After turning on the device, the LCD lights up, and it will wait until the "OK/Start" button is pressed.
![](https://i.imgur.com/U3ED7P6.jpg)
3. After pressing start, it changes to speed selection. Change speed mode "Fast" or "Slow" by pressing "-" and "+" button, then press "OK/Start" button to confirm.
![](https://i.imgur.com/lER0v4b.jpg)
4. Now, choose mode "Practice" or "Test". Difference is "Test" gives you a score, but "Practice" doesn't, and it won't move until your hands apply proper pressure to the sensor. Change mode by pressing "-" and "+" button, press "OK/Start" button to confirm.
![](https://i.imgur.com/ghQ1zHk.jpg)
5. Choose duration by pressing "-" and "+" button, press "OK/Start " button to confirm. Duration is multiple of 5.
![](https://i.imgur.com/fVT56Of.jpg)

6. Then, it waits until you press the "OK/Start" button, press for about 1 sec, it needs to press longer than others as a safety feature.
![](https://i.imgur.com/iM7G4A9.jpg)

7. And count down starts with buzz sound.
![](https://i.imgur.com/cGaFioU.jpg)
8. After high buzz sound, machine starts moving. If you choose "Practice" mode, if your hand is not applying enough pressure, it won't move and it will tell you by making buzz.
![](https://i.imgur.com/vPzAkcB.jpg)
9. Gone through all steps, it gives you score out of 100 if you choose "Test" mode.
![](https://i.imgur.com/15OIwqu.jpg)
↑End screen of "Test" mode ↓End screen of "Practice"
![](https://i.imgur.com/S4dS2N8.jpg)
10. And goves back to 1.

## Difficulty
### Hardware
- Motor...Because the motor does not have enough torque at low rpm, trying to move the machine slowly causes the machine to drift.
- Arduino...It is not catastrophic, however, because the interrupt pin was occupied by a shield, I could not make the hand detecting function I wanted to make.
### Software
- Motor control...I have to use a library for shield, which was provided by the company. Example code they included was not precise enough for me. Also, only code I found was from the company, I could not find others using.


## Summery
### Is it useful ?
Straight answer is "NO".
### Reason

- Machine is unbalanced...As you can see from the picture below, the machine itself has a really big lever ratio. Which causes the machine to lift when using, and due to the long pole, when it starts to move and stop, the pole wobbles due to inertia, which causes the machine to drift.
![](https://i.imgur.com/HW820mO.jpg)
- Motor calibration...Motor is not strong enough for this application, and the machine can't find where it is. 


#### Attempted Solution
- Balance of machine...This could not be fixed by software, so I tried a hardware approach.
    - Lowering the motor axis than instruction suggested. This was not enough.
![](https://i.imgur.com/ZMqLXcy.jpg)
<- Original as instruction suggested
    Modified->
    - Hanging heavy thing from front of machine (I hanged motor using other L-shape bracket) but that did not work either, because when machine move, the bracket flexes up-and down made vibration, which caused the machine to bounce like low rider, and drifts all over the place.
    - I also added weight around the center of the machine, but at the weight it's effective, it was too heavy for the motor to move the machine.
- Motor calibration...I previously had experience with a similar machine, but that machine had a distance sensor and wall to calibrate and position itself, but for this case, I could not find a solution for the machine to tell where it is. I tried the GPS module, but it was not sufficient. I tried to make it as slow as possible, however, due to motor's power charactarisctice, it was difficult to be slow and accuarat at the same time. For example, if I try to run the motor with PWM 400, machine drifts right when it starts moving. I tried to fix this issue by pulse wave method. As seen in graph below, first I run the motor with 1000 PWM, then gradually decrease it to 600(Blue line area), and then PWM 600 for 200ms or so, then 400 PWM for 500ms or so. And repeat. I tried so many variation, but combination of PWM 600 and 400 was the setup that can be slow and accurate. 
![](https://i.imgur.com/RNucjf3.jpg)

#### Possible solution
- Machine with a larger surface or heavier and lower center of gravity, which decreases the lever ratio.
- Motor with more torque even at low rpm.
- Compass module to tell whether a machine is drifting or not.
- Replacement of FSR sensor to other. Sensors that don't need to make physical contact might be more suitable for this case.
#### Total failure ?
NO.
Machine itself didn't work as intended, but I learned a couple of things.
1. Servo motors...I never used them before, and it was very difficult in the beginning, especially when I was trying to calibrate from nothing.
2. Menu function...Previous Arduino, or other IoT project was very bare, it screamed "Engineering sample", but for this case, the user was ordinary people who most of them don't have computer background, which I have to implement user friendly features.
3. Dream and reality...All of the IoT projects so far, software never went against hardware or I never encountered hardware limitation, but for the first time, I encountered such a case. Software exceeded hardware. Such as weak motor, balance of machine. The code, software worked as I intended, but the hardware didn't, it was the case "Reality could not catch up with dream".
Those 3 cases are what was new for me and what I learned.
## Reference
- https://www.ajmc.com/view/work-exposure-to-paraquat-not-associated-with-increased-risk-of-parkinson-disease-mortality