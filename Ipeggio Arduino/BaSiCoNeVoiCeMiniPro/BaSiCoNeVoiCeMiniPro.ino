// This function will be automatically called when a NoteOn is received.
// It must be a void-returning function with the correct parameters,
// see documentation here: 
#include <MIDI.h>
////https://github.com/FortySevenEffects/arduino_midi_library
using namespace midi;
 const int buttonPin2   = 8;     ////Van 4 
 const int ledPin = 13; 
boolean buttonState2 = HIGH;
boolean LastbuttonState2 = LOW;
  boolean closE = LOW;
  int velVal = 102;
   int count = 0;
   int count1 = 0;
   int count2 = 0;
  int count3 = 0;
  int count4 = 0;
   int COUNT =0;
    int CC64val = 0;
 int old_CC64val = 0;
  int countTime = 0;
  int countTime2 = 0;
int countP = 0;
int countPP = 0;
int RRReset = 16;
int range2 = 0;
int aNote = 53;
int bNote = 53;
int cNote = 41;
int dNote = 53;
int eNote = 56;
int fNote = 41;
int gNote = 53;
int hNote = 56;
int soundingNote = 0;
int previousNote = 0;
boolean noteArray[128] = {}; 
 boolean noteArrayB[128] = {}; 
 boolean noteArrayC[128] = {}; 
 boolean noteArrayD[128] = {}; 
boolean noteArrayZ[128] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}; 
///noteArray +u  
boolean playA [16] = {};
boolean playB [16] = {};
boolean playC [16] = {};
boolean playD [16] = {};
boolean playE [16] = {};
boolean playF [16] = {};
boolean playG [16] = {};
boolean playH [16] = {};
  MIDI_CREATE_INSTANCE(HardwareSerial, Serial, MIDIaaa)

void setup() {
   pinMode(buttonPin2, INPUT);
      pinMode(7,OUTPUT); 
     digitalWrite(7, HIGH);
   pinMode(ledPin, OUTPUT);      
 // Initiate MIDI communications, listen to all channels
      MIDIaaa.begin(MIDI_CHANNEL_OMNI);    
      MIDIaaa.turnThruOff();
   
   MIDIaaa.setHandleNoteOn(HandleNoteOn);
   MIDIaaa.setHandleControlChange(HandleControlChange);
     MIDIaaa.setHandleStart(HandleStartA);
   MIDIaaa.setHandleClock(HandleClock);
  }       
 
  void loop() {
      MIDIaaa.read();
     readPins();
   }
  
    void newWay(int ve)
  {velVal = ve;
      MIDIaaa.sendControlChange(7,velVal,2);   
      }

  void HandleNoteOn(unsigned char channel, unsigned char pitch, unsigned char velocity) { 
  if (velocity == 0) {}
  if (channel == 1) {
    if ((count > 93) || (count < 3))  {
   countTime = 0;
 doArp(pitch);}
 else if ((count > 3) && (count < 9)){
     countTime = 1;
  doArp(pitch);}
   else if ((count > 9) && (count < 15)){
    countTime = 2;
 doArp(pitch);  }
  else if ((count > 15) && (count < 21)){
     countTime = 3;
 doArp(pitch);  }
  else  if ((count > 21) && (count < 27)){
     countTime = 4;
 doArp(pitch);  }
 else if ((count > 27) && (count < 33)){
     countTime = 5;
 doArp(pitch);  }
  else if ((count > 33) && (count < 39)){
     countTime = 6;
 doArp(pitch);  }
  else if ((count > 39) && (count < 45)){
     countTime = 7;
 doArp(pitch);  }
   else  if ((count > 45) && (count < 51)){
    countTime = 8;
 doArp(pitch);  }
  else if ((count > 51) && (count < 57)){
     countTime = 9;
 doArp(pitch);  }
  else if ((count > 57) && (count < 63)){
     countTime = 10;
 doArp(pitch);  }
  else if ((count > 63) && (count < 69)){
    countTime = 11;
 doArp(pitch);  }
  else  if ((count > 69) && (count < 75)){
      countTime = 12;
 doArp(pitch);  }
   else if ((count > 75) && (count < 81)){
     countTime = 13;
 doArp(pitch);  }
  else if ((count > 81) && (count < 87)){
    countTime = 14;
 doArp(pitch);  }
   else if ((count > 87) && (count < 93)){
     countTime = 15;
 doArp(pitch);  }
   }
     if (channel ==3) {
     newWay(velocity);
       switch(count1)   {
      case 0: aNote = pitch - 12;
        break;
     case 1: bNote = pitch - 12;
       break;
   case 2: cNote = pitch - 12;
     break;
   case 3: dNote = pitch - 12;
    break;
   case 4: eNote = pitch - 12;
   break;
   case 5: fNote = pitch - 12;
   break;
  case 6: gNote = pitch - 12;
   break;
   case 7: hNote = pitch - 12;
  break;
   }
    count1++;
    if (count1 > 7)
    count1 = 0;
     }
      if(channel == 10)   {
    if (velocity != 0) {
        switch (pitch) {
      ///STORE
      case 52:  
         storeA();
         break;
      case 49:  
         storeB();
         break;
        case 48:  
         storeC();
         break;
     
          ///RESTORE
       case 38:  
          REstoreA();
           break;
       case 41:  
          REstoreB();
         break;
       case 53:  
          REstoreC();
           break;
             }
        }
      }
      }
      
      void doArp(int pi)    {
    switch (countP)   {
  case  0:
   aNote = pi;
   whereA();
   break;
  case 1:
  if (aNote == pi){
   countP = 0;
   whereA();   }
   else   {
   bNote = pi;
   countP = 1;
   whereB();   }
   break;
       case 2:
   if (aNote == pi){
   countP = 1;
   whereA();}
   else if (bNote == pi){
   countP = 1;
   whereB();  }
   else   {
   cNote = pi;
   countP = 2;
   whereC();  }
   break;
      case 3:
  if (aNote == pi){
   countP = 2;
   whereA();}
   else if (bNote == pi){
   countP = 2;
   whereB();  }
   else if (cNote == pi) {
   countP = 2;
   whereC();  }
    else   {
   dNote = pi;
   countP = 3;
   whereD();  }
  break;
        case 4:
   if (aNote == pi){
   countP = 3;
   whereA();}
   else if (bNote == pi){
   countP = 3;
   whereB();  }
   else if (cNote == pi) {
   countP = 3;
   whereC();  }
    else if (dNote == pi) {
   countP = 3;
   whereD();  }
   else   {
   eNote = pi;
   countP = 4;
   whereE();  }
  break;
         case 5:
   if (aNote == pi){
   countP = 4;
   whereA();}
   else if (bNote == pi){
   countP = 4;
   whereB();  }
   else if (cNote == pi) {
   countP = 4;
   whereC();  }
    else if (dNote == pi) {
   countP = 4;
   whereD();  }
    else if (eNote == pi) {
   countP = 4;
   whereE();  }
    else   {
   fNote = pi;
   countP = 5;
   whereF();  }
  break;
         case 6:
   if (aNote == pi){
   countP = 5;
   whereA();}
   else if (bNote == pi){
   countP = 5;
   whereB();  }
   else if (cNote == pi) {
   countP = 5;
   whereC();  }
    else if (dNote == pi) {
   countP = 5;
   whereD();  }
    else if (eNote == pi) {
   countP = 5;
   whereE();  }
    else if (fNote == pi) {
   countP = 5;
   whereF();  }
  else   {
   gNote = pi;
   countP = 6;
   whereG();  }
  break;
      case 7:
   if (aNote == pi){
   countP = 6;
   whereA();}
   else if (bNote == pi){
   countP = 6;
   whereB();  }
   else if (cNote == pi) {
   countP = 6;
   whereC();  }
    else if (dNote == pi) {
   countP = 6;
   whereD();  }
    else if (eNote == pi) {
   countP = 6;
   whereE();  }
   else if (fNote == pi) {
   countP = 6;
   whereF();  }
   else if (gNote == pi) {
   countP = 6;
   whereG();  }
   else if (hNote == pi) {
   countP = 7;
   whereH();  }
   else   {
   if(!closE) {
  hNote = pi;
   countP = 7;
   whereH(); 
    closE = HIGH; }
    else {}
     }
   break;
     }
      countP++;
    if (countP > 7)
    countP = 7;
  }   
    
   void whereA()  {
   playA[countTime]=HIGH;
     }

      void whereB()  {
   playB[countTime]=HIGH;
    }

       void whereC()  {
   playC[countTime]=HIGH;
       }

      void whereD()  {
   playD[countTime]=HIGH;
       }

    void whereE()  {
   playE[countTime]=HIGH;
       }
    
     void whereF()  {
   playF[countTime]=HIGH;
      }
    
    void whereG()  {
   playG[countTime]=HIGH;
      }
   
   void whereH()  {
   playH[countTime]=HIGH;
      }
  
    void doARPEG(int co)    {
     if ((playA[co] == HIGH) && (aNote != 0)) {
      soundingNote = aNote;
    MIDIaaa.sendNoteOn(previousNote, 0, 1);
    MIDIaaa.sendNoteOn(soundingNote, velVal, 1);
       previousNote = soundingNote; 
      }    
      if ((playB[co] == HIGH)&& (bNote != 0)) {
      soundingNote = bNote;
    MIDIaaa.sendNoteOn(previousNote, 0, 1);
    MIDIaaa.sendNoteOn(soundingNote, velVal, 1);
       previousNote = soundingNote; 
      }    
         if ((playC[co] == HIGH)&& (cNote != 0)) {
      soundingNote = cNote;
   MIDIaaa.sendNoteOn(previousNote, 0, 1);
    MIDIaaa.sendNoteOn(soundingNote, velVal, 1);
       previousNote = soundingNote; 
      }    
     if ((playD[co] == HIGH)&& (dNote != 0)) {
      soundingNote = dNote;
    MIDIaaa.sendNoteOn(previousNote, 0, 1);
    MIDIaaa.sendNoteOn(soundingNote, velVal, 1);
       previousNote = soundingNote; 
      }    
     if ((playE[co] == HIGH)&& (eNote != 0)) {
      soundingNote = eNote;
    MIDIaaa.sendNoteOn(previousNote, 0, 1);
    MIDIaaa.sendNoteOn(soundingNote, velVal, 1);
       previousNote = soundingNote; 
      }    
     if ((playF[co] == HIGH)&& (fNote != 0)) {
      soundingNote = fNote;
    MIDIaaa.sendNoteOn(previousNote, 0, 1);
    MIDIaaa.sendNoteOn(soundingNote, velVal, 1);
       previousNote = soundingNote; 
      }    
     if ((playG[co] == HIGH)&& (gNote != 0)) {
      soundingNote = gNote;
    MIDIaaa.sendNoteOn(previousNote, 0, 1);
    MIDIaaa.sendNoteOn(soundingNote, velVal, 1);
       previousNote = soundingNote; 
      }    
     if ((playH[co] == HIGH)&& (hNote != 0)) {
      soundingNote = hNote;
    MIDIaaa.sendNoteOn(previousNote, 0, 1);
    MIDIaaa.sendNoteOn(soundingNote, velVal, 1);
       previousNote = soundingNote; 
      }    
    }
   
     void HandleControlChange (unsigned char channel, unsigned char number, unsigned char value) {
      if(number == 64)    {
        if (value > 0)   {
     CC64val = HIGH;
        digitalWrite(ledPin, HIGH);
   }
       else { 
         CC64val = LOW;
        digitalWrite(ledPin, LOW);
   }
   ///   if((CC64val == HIGH) && (old_CC64val == LOW))
      
      if((CC64val == LOW) && (old_CC64val == HIGH)) {
        setZero();
        count1 = 0;
        count4 = 0;
      }
          old_CC64val = CC64val;
     }
    }
       
          void HandleClock ()   {
      // MIDIaaa.sendRealTime(Clock);
     //  midiB.sendRealTime(Clock);
      if (count % 6 == 0)
     clockCount();
     count++;
  if (count == 91)
    doDo () ;
    //  if ((count == 91) && (!buttonState1))  
    //    goSTATE = !goSTATE;
   //   if ((count == 94)&&(goSTATE == HIGH))
  ///    doREstore();
    if (count == 95)
    MIDIaaa.sendNoteOn(55,34,2); 
    if (count > 95){
  /////  if (!buttonState1) 
   MIDIaaa.sendNoteOn(55,55,2);
  count = 0;
     }
    }
   
    void HandleStartA ()   {
          count2 = 0; 
        count = 0;        
         }
      
   void doDo ()   {
     int Temp1; 
   //int Temp2; 
   //int Temp3;
     int RRR = random (0,13);
     
      switch (RRReset){
       case 0:
         MIDIaaa.sendControlChange(16,63,2);   
        break;
            case 1:
       aNote = aNote - 12;
       MIDIaaa.sendControlChange(16,28,2);   
         break;
            case 2:
       bNote = Temp1;
        MIDIaaa.sendControlChange(16,55,2);   
        break;
            case 3:
       MIDIaaa.sendControlChange(16,34,2);   
          break;
            case 4:
      playB[2] == HIGH;
        playB[4] == HIGH;
        playB[6] == HIGH;
         playB[8] == HIGH;
       MIDIaaa.sendControlChange(16,45,2);   
        break;
            case 5:
           MIDIaaa.sendControlChange(16,70,2);   
         break;
            case 6:
        MIDIaaa.sendControlChange(16,31,2);   
        break;
            case 7:
       MIDIaaa.sendControlChange(16,82,2);   
        break;
            case 8:
       bNote = bNote - 12;
       MIDIaaa.sendControlChange(16,39,2);   
         break;
            case 9:
       playA[8] == LOW;
        playA[9] == LOW;
       playA[10] == LOW;
          MIDIaaa.sendControlChange(16,41,2);   
        break;
            case 10:
       MIDIaaa.sendNoteOn(22, 68, 2);
      break;
            case 11:
       MIDIaaa.sendNoteOn(24, 78, 2);
           break;
            case 12:
       dNote = dNote - 12;
        MIDIaaa.sendNoteOn(25, 48, 2);
     break;
            case 13:
       MIDIaaa.sendNoteOn(23, 68, 2);
     break;   
            case 16:
           break;   
          } 
 
  switch (RRR){
       case 0:
       break;
            case 1:
       aNote = aNote + 12;
       break;
            case 2:
         Temp1 = bNote;   
       bNote = 0;
       break;
            case 3:
      break;
            case 4:
       playB[2] == LOW;
        playB[4] == LOW;
        playB[6] == LOW;
         playB[8] == LOW;
      break;
            case 5:
      break;
            case 6:
       break;
            case 7:
    
      break;
            case 8:
       bNote = bNote + 12;
       break;
            case 9:
       playA[8] == HIGH;
         playA[9] == HIGH;
       playA[10] == HIGH;
    break;
            case 10:
       break;
            case 11:
      break;
            case 12:
       dNote = dNote + 12;
       break;
            case 13:
        break;   
     } 
     RRReset = RRR;
   }
   
   void setZero() {
    aNote = 0;
   bNote = 0;
   cNote = 0;
  dNote = 0;
  eNote = 0;
   fNote = 0;
  gNote = 0;
   hNote = 0;
     count1 = 0;
     countP=0;
     closE = LOW;
   }
  
   void clockCount()    {
       switch(count2)   {
case 0:
 doARPEG(count2);
  break;
   
   case 1:
      doARPEG(count2);
   break;
case 2:
     doARPEG(count2);
  break;
 case 3:
    doARPEG(count2);
 break;
 case 4:
   doARPEG(count2);
   break;
 case 5:
    doARPEG(count2);
 break;
 case 6:
 doARPEG(count2);
  break;
 case 7:
    doARPEG(count2);
  break;
 case 8:
    doARPEG(count2);
  break;
 case 9:
    doARPEG(count2);
 break;
 case 10:
    doARPEG(count2);
 break;
 case 11:
     doARPEG(count2);
 break;
  case 12:
       doARPEG(count2);
 break;
    case 13:
     doARPEG(count2);
  break;
   case 14:
    doARPEG(count2);
break;
   case 15:
       doARPEG(count2);
 break;
     }
          count2++;
         if (count2 > 15)
         count2 = 0; 
        }
     
      void readPins()    {   
         buttonState2 = digitalRead(buttonPin2);
  if ((buttonState2 == HIGH) && (LastbuttonState2 ==  LOW)){       
        digitalWrite(ledPin, HIGH); 
  } 
  else if ((buttonState2 == LOW) && (LastbuttonState2 ==  HIGH)) {
     MIDIaaa.sendControlChange(123,127,1);    //CCNUMBER  Value  CC channel
      digitalWrite(ledPin, LOW);
    countP=0;
  closE = LOW;
   delay(13);
   REstoreZZZ(); 
   }
   else {} 
    LastbuttonState2 = buttonState2;
   }

void storeA()  {
   for (int i = 0; i < 16; i++)  {
    noteArray[i] = playA[i]; 
  }
   for (int i = 0; i < 16; i++)  {
    noteArray[i +16] = playB[i]; 
   }
    for (int i = 0; i < 16; i++)  {
    noteArray[i +32] = playC[i]; 
  }
 for (int i = 0; i < 16; i++)  {
    noteArray[i +48] = playD[i]; 
  }
 for (int i = 0; i < 16; i++)  {
    noteArray[i +64] = playE[i]; 
  }
 for (int i = 0; i < 16; i++)  {
    noteArray[i + 80] = playF[i]; 
   }
 for (int i = 0; i < 16; i++)  {
    noteArray[i +96] = playG[i]; 
    }
 for (int i = 0; i < 16; i++)  {
    noteArray[i +112] = playH[i]; 
    }
    }
 

void storeB()  {
   for (int i = 0; i < 16; i++)  {
    noteArrayB[i] = playA[i]; 
  }
   for (int i = 0; i < 16; i++)  {
    noteArrayB[i +16] = playB[i]; 
   }
    for (int i = 0; i < 16; i++)  {
    noteArrayB[i +32] = playC[i]; 
  }
 for (int i = 0; i < 16; i++)  {
    noteArrayB[i +48] = playD[i]; 
  }
 for (int i = 0; i < 16; i++)  {
    noteArrayB[i +64] = playE[i]; 
  }
 for (int i = 0; i < 16; i++)  {
    noteArrayB[i + 80] = playF[i]; 
   }
 for (int i = 0; i < 16; i++)  {
    noteArrayB[i +96] = playG[i]; 
    }
 for (int i = 0; i < 16; i++)  {
    noteArrayB[i +112] = playH[i]; 
    }
   }
 
void storeC()  {
   for (int i = 0; i < 16; i++)  {
    noteArrayC[i] = playA[i]; 
  }
   for (int i = 0; i < 16; i++)  {
    noteArrayC[i +16] = playB[i]; 
   }
    for (int i = 0; i < 16; i++)  {
    noteArrayC[i +32] = playC[i]; 
  }
 for (int i = 0; i < 16; i++)  {
    noteArrayC[i +48] = playD[i]; 
  }
 for (int i = 0; i < 16; i++)  {
    noteArrayC[i +64] = playE[i]; 
  }
 for (int i = 0; i < 16; i++)  {
    noteArrayC[i + 80] = playF[i]; 
   }
 for (int i = 0; i < 16; i++)  {
    noteArrayC[i +96] = playG[i]; 
    }
 for (int i = 0; i < 16; i++)  {
    noteArrayC[i +112] = playH[i]; 
    }
  }
 

void storeD()  {
   for (int i = 0; i < 16; i++)  {
    noteArrayD[i] = playA[i]; 
  }
   for (int i = 0; i < 16; i++)  {
    noteArrayD[i +16] = playB[i]; 
   }
    for (int i = 0; i < 16; i++)  {
    noteArrayD[i +32] = playC[i]; 
  }
 for (int i = 0; i < 16; i++)  {
    noteArrayD[i +48] = playD[i]; 
  }
 for (int i = 0; i < 16; i++)  {
    noteArrayD[i +64] = playE[i]; 
  }
 for (int i = 0; i < 16; i++)  {
    noteArrayD[i + 80] = playF[i]; 
   }
 for (int i = 0; i < 16; i++)  {
    noteArrayD[i +96] = playG[i]; 
    }
 for (int i = 0; i < 16; i++)  {
    noteArrayD[i +112] = playH[i]; 
    }
  }

 void REstoreA()  {
   for (int i = 0; i < 16; i++)  {
    playA[i]  = noteArray[i]; 
  }
   for (int i = 0; i < 16; i++)  {
    playB[i]  = noteArray[i + 16]; 
  }
 for (int i = 0; i < 16; i++)  {
    playC[i]  = noteArray[i + 32]; 
  }
 for (int i = 0; i < 16; i++)  {
    playD[i]  = noteArray[i + 48]; 
  }
 for (int i = 0; i < 16; i++)  {
    playE[i]  = noteArray[i + 64]; 
  }
 for (int i = 0; i < 16; i++)  {
    playF[i]  = noteArray[i + 80]; 
  }
 for (int i = 0; i < 16; i++)  {
    playG[i]  = noteArray[i + 96]; 
  }
 for (int i = 0; i < 16; i++)  {
    playH[i]  = noteArray[i + 112]; 
  }
 }
 void REstoreB()  {
   for (int i = 0; i < 16; i++)  {
    playA[i]  = noteArrayB[i]; 
  }
   for (int i = 0; i < 16; i++)  {
    playB[i]  = noteArrayB[i + 16]; 
  }
 for (int i = 0; i < 16; i++)  {
    playC[i]  = noteArrayB[i + 32]; 
  }
 for (int i = 0; i < 16; i++)  {
    playD[i]  = noteArrayB[i + 48]; 
  }
 for (int i = 0; i < 16; i++)  {
    playE[i]  = noteArrayB[i + 64]; 
  }
 for (int i = 0; i < 16; i++)  {
    playF[i]  = noteArrayB[i + 80]; 
  }
 for (int i = 0; i < 16; i++)  {
    playG[i]  = noteArrayB[i + 96]; 
  }
 for (int i = 0; i < 16; i++)  {
    playH[i]  = noteArrayB[i + 112]; 
  }
 }
 
 void REstoreC()  {
   for (int i = 0; i < 16; i++)  {
    playA[i]  = noteArrayC[i]; 
  }
   for (int i = 0; i < 16; i++)  {
    playB[i]  = noteArrayC[i + 16]; 
  }
 for (int i = 0; i < 16; i++)  {
    playC[i]  = noteArrayC[i + 32]; 
  }
 for (int i = 0; i < 16; i++)  {
    playD[i]  = noteArrayC[i + 48]; 
  }
 for (int i = 0; i < 16; i++)  {
    playE[i]  = noteArrayC[i + 64]; 
  }
 for (int i = 0; i < 16; i++)  {
    playF[i]  = noteArrayC[i + 80]; 
  }
 for (int i = 0; i < 16; i++)  {
    playG[i]  = noteArrayC[i + 96]; 
  }
 for (int i = 0; i < 16; i++)  {
    playH[i]  = noteArrayC[i + 112]; 
  }
 }
 void REstoreD()  {
   for (int i = 0; i < 16; i++)  {
    playA[i]  = noteArrayD[i]; 
  }
   for (int i = 0; i < 16; i++)  {
    playB[i]  = noteArrayD[i + 16]; 
  }
 for (int i = 0; i < 16; i++)  {
    playC[i]  = noteArrayD[i + 32]; 
  }
 for (int i = 0; i < 16; i++)  {
    playD[i]  = noteArrayD[i + 48]; 
  }
 for (int i = 0; i < 16; i++)  {
    playE[i]  = noteArrayD[i + 64]; 
  }
 for (int i = 0; i < 16; i++)  {
    playF[i]  = noteArrayD[i + 80]; 
  }
 for (int i = 0; i < 16; i++)  {
    playG[i]  = noteArrayD[i + 96]; 
  }
 for (int i = 0; i < 16; i++)  {
    playH[i]  = noteArrayD[i + 112]; 
  }
  }
  
 void REstoreZZZ()  {
  setZero();
   for (int i = 0; i < 16; i++)  {
    playA[i]  = noteArrayZ[i]; 
  }
   for (int i = 0; i < 16; i++)  {
    playB[i]  = noteArrayZ[i + 16]; 
  }
 for (int i = 0; i < 16; i++)  {
    playC[i]  = noteArrayZ[i + 32]; 
  }
 for (int i = 0; i < 16; i++)  {
    playD[i]  = noteArrayZ[i + 48]; 
  }
 for (int i = 0; i < 16; i++)  {
    playE[i]  = noteArrayZ[i + 64]; 
  }
 for (int i = 0; i < 16; i++)  {
    playF[i]  = noteArrayZ[i + 80]; 
  }
 for (int i = 0; i < 16; i++)  {
    playG[i]  = noteArrayZ[i + 96]; 
  }
 for (int i = 0; i < 16; i++)  {
    playH[i]  = noteArrayZ[i + 112]; 
  }
 }
 
