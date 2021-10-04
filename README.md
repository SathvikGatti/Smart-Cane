# Smart-Cane
Smart Cane is a device that built based on IOT that is a visually impaired's friend, that helps him/her to walk with guidance.
#Brief Overview:
This was a project that I worked on with my friends in my second year, we thought of building this project with an intention to help blind people walk with ease. 
So smart cane is a device that we built based on IOT using ESP8266 micro-controller with wifi, Google Fire-base for cloud, and built an app with Kodular.
The device is attached on a blind's cane. The device is connected to an App that is installed in the blind man's phone through Firebase. So we set a 
specific threshold distance, so whenever there is an obstacle in front of a blind man, it is detected by means of ultrasonic sensors installed on the device. 
The ultrasonic sensors keep measuring the distance of any object infront of him in real time and when ever the distance is less than threshold, lets say 1meter, 
it will set an alarm in the blind's phone, which will send a voice signal to the blind via earphones saying "Too near". 
So that the blind man can change course or take action. 
Apart from this we had a unique security feature to help avoid miscreants taking advantage of a blind's disability to rob, harras. 
It also has a security button that the blind man can press whenver he/she feels need of help, when the SOS button is pressed, two things happen,
1. There is an immediate message sent to the blind's guardian which contains the co-ordinates of the blind's location in order to track him/her.
2.A direct call is made to pre-registered phone number which can be a guardian so that he can talk to them and express.

Hardware and Tech-stack involved:
Micro-controller: ESP_8266 Node MCU micorcontroller.
HC05 Ultransonic sensors.
Cloud: Google Firebase.
Language: C++ in Arduino IDE.
App: Kodular, version of MIT app invertor.
