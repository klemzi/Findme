# Findme
Connected people, fast search!


Saftey! Safety! Safety!, we all want to feel protected. Nigeria is growing gradually in technology, however with so many system not yet in place like street CCTV, AI traffic control, connected things & people, and  so on, we want to feel safe.
I lost someone very close last year but i didn't get to know on time, and i have heard and read of situations whereby people involved in accidents died due to late arrivals of medical services. Events like Accidents, people who need immediate medical attention, robberies, kidnappings, and riot information are critical information that needs fast response. How to go about getting these kind of information fast and also increase the response time was how Findme came up.

Findme connects people. This solution alerts security agents,hospitals in case of accidents ,and also send the location of the victim to the closest relatives stored on the database. No matter were it happens, Findme's job is get help closest to you. let's say for instance an accident occurs and two or three passengers has this, with just a press the closest emergency unit is alerted and while the unit is trying to validate those three passenger phones are ringing. People who are there to help can pick this calls and even get told what to do till medical services arrives. This solution will definately safe lives, and also reduce the response time of sercurity services.

Findme me is a device with a button with two states. the first state (double press) handles security treat, by sending first a help message to security services closest to you via email and sms, then updates your location with time to enable them track you using a map. The device also sends message to your closest relatives and tweets it so that your friends can see. Findme will get help!

The second state (long press), health attention. sends an alert message to the closest emergency unit and also alerts your close relatives.

![Findme Architecture](https://drive.google.com/open?id=1WirrCvcFrlwaprVZ6fJOmZZr1Ud5Hjl0)

This solution was built using Azure cloud services, and data stored is used for reporting. Power BI is used to create reports, with insights like areas which has the high number of security treats. it is also used for live map visuals to aid near real time tracking.

## Device
1. Adafruit Feather HUZZAH
2. Push button
3. GPS
4. Lion battery

## Azure cloud services 
1. IoT Hub - Gateway with routing capabilities
2. Service Bus queues - feed into logic apps
3. Logic apps - emails, tweets, and sms
4. Stream analytics - streams location to power BI
5. Cosmos db - History reports / database
6. Azure functions - serverless functions used for certain tasks

## Reporting
1. Power BI
