/*  
  OpenMQTTGateway Addon  - ESP8266 or Arduino program for home automation 

   Act as a wifi or ethernet gateway between your 433mhz/infrared IR signal  and a MQTT broker 
   Send and receiving command by MQTT
 
    Output pin High or Low
  
    Copyright: (c)Florian ROBERT
    
    Contributors:
    - 1technophile
  
    This file is part of OpenMQTTGateway.
    
    OpenMQTTGateway is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenMQTTGateway is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifdef ZactuatorONOFF

void setupONOFF(){
  trc(F("ACTUATOR_ONOFF_PIN"));
  trc(String(ACTUATOR_ONOFF_PIN));
  //init
  pinMode(ACTUATOR_ONOFF_PIN, OUTPUT);
  trc(F("Set to OFF"));
  digitalWrite(ACTUATOR_ONOFF_PIN, LOW);
  trc(F("ZactuatorONOFF setup done "));
}

void MQTTtoONOFF(char * topicOri, char * datacallback){

  bool boolSWITCHTYPE;
  boolSWITCHTYPE = to_bool(datacallback);
  String topic = topicOri;
 
  if ((topic == subjectMQTTtoONOFF)){
    trc(F("MQTTtoONOFF"));
    trc(String(boolSWITCHTYPE));
    digitalWrite(ACTUATOR_ONOFF_PIN, boolSWITCHTYPE);
    boolean result = client.publish(subjectGTWONOFFtoMQTT, datacallback);// we acknowledge the sending by publishing the value to an acknowledgement topic
    if (result){
      trc(F("MQTTtoONOFF ack pub."));
      trc(String(datacallback));
    }
  }
}
#endif

