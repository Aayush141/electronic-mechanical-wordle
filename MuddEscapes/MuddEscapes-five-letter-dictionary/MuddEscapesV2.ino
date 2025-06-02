// Assuming potentiometers are connected to pins 14 and 15
// Reminder - 1 is V, 2 is port, 3 is ground (on potentiometer). Pin 3 should be at the top in the box.

const int potPin1 = 15;
const int potPin2 = 16;
const int potPin3 = 17;
const int potPin4 = 19;
const int potPin5 = 20;

const int greenLEDs[5] = {12, 9, 7, 6, 3}; // Green LEDs on even pins
const int yellowLEDs[5] = {10, 8, 7, 5, 1}; // Yellow LEDs on odd pins

// Define the letter range. Can be replaced with any 10 letters.
String letters = "adehmnorst"; 
String correctWord = "drama"; 

String myArray[278] = {"added", "adder", "adore", "adorn", "aeons", "ahead", "amass", "amend", "antes", "areas", "arena", "armed", "aroma", "arose", "arson", "ashen", "ashes", "asses", "asset", "aster", "atoms", "atone", "attar", "dames", "dared", "dares", "darts", "dated", "dates", "deans", "dears", "death", "deeds", "deems", "demon", 
"dense", "dents", "deter", "doers", "domed", "domes", "donor", "dooms", "doors", "dosed", "doses", "doted", "dotes", "drama", "drams", "dread", "dream", "dress", "drone", "dross", "earns", "earth", "eased", "eases", "eaten", "eater", "ended", "enter", "erase", "erred", "error", "ether", "hands", "harem", "hares", "harms", "harsh", "harts", "haste", "hated", "hater", "heads", "heard", "hears", "heart", "heath", "heats", "heeds", "herds", "heron", "heros", "hoard", "homes", "hoods", "hoots", "horde", "horns", "horse", "hosts", "madam", "mamma", "manes", "manna", "manor", "manse", "mares", "marsh", "marts", "mason", "masts", "mated", "mates", "means", "meant", "meats", "meets", "memes", "mends", "meres", "mesas", "meted", "meter", "moans", "moats", "modem", "modes", "momma", "month", "moods", "moons", "moors", "moose", "mores", "motes", "moths", "motor", "motto", "named", "names", "nears", "needs", "nests", "nomad", "noose", "north", "nosed", "noses", "noted", "notes", "oases", "oaten", "oaths", "odder", "omens", "onset", "order", "other", "otter", "rarer", "rares", "rated", "rates", "reads", "reams", "rears", "reeds", "rends", "rents", "reset", "rests", "roads", "roams", "roars", "roast", "roman", "rooms", "roost", "roots", "roses", "sands", "saner", "sated", "seams", "seats", "sedan", "seeds", "seems", "seers", "semen", "sends", "sense", "shade", "shame", "shams", "share", "shear", "sheds", "sheen", 
"sheer", "sheet", "shoes", "shone", "shoon", "shoot", "shore", "shorn", "short", "shots", "shred", "smart", "smash", "smear", "smote", "snare", "sneer", "snore", "snort", "soars", "sooth", "sores", "sorts", "stand", "stare", "stars", "start", "state", "stead", "steam", "steed", "steer", "stems", "stern", "stone", "stood", "store", "storm", "tamed", "tamer", "tares", "tarts", "taste", "teams", "tears", "tease", "teems", "teens", "teeth", "tends", "tenet", "tenor", "tense", "tenth", "tents", "terms", "terse", "tests", "theme", "there", "these", "thorn", "those", "three", "throe", "toads", "toast", "tomes", "toned", "tones", "tooth", "torso", "torts", "totem", "trade", "trams", "trash", "tread", "treat", "treed", "trees", "trend", "tress", "troth", "trots"};

String myArray2[379] = {"aahs", "adam", "adds", "ados", "aeon", "ahem", "amah", "amen", "ammo", "ands", "anna", "anne", "anno", "anon", "ante", "ants", "area", "ares", "arms", "arse", "arts", "asea", "assn", "asst", "atma", "atom", "attn", "dada", "dado", "dads", "dame", "damn", "dams", "dana", "dane", "dare", "darn", "dart", "dash", "data", "date", "dead", "dean", "dear", "deed", "deem", "deer", "dees", "demo", "dens", "dent", "derm", "dodo", "doer", "does", "dome", "doms", "dona", "done", "dons", "doom", "door", "dorm", "dors", "dose", "doss", "dost", "dote", "doth", "dots", "dram", "drat", "earn", "ears", "ease", "east", "eats", "edam", "edda", "eden", "ends", "eons", "eras", "erat", "erne", "erns", "eros", "errs", "erst", "eses", "esse", "etna", "hahs", "hams", "hand", "hard", "hare", "harm", "hart", "hash", "hast", "hate", "hath", "hats", "head", "hear", "heat", "heed", "heme", "hems", "hens", "herd", "here", "hero", "herr", "hers", "hest", "hoar", "hods", "hoed", "hoer", "hoes", "home", "homo", "hone", "hood", "hoot", "hora", "horn", "hors", "hose", "host", "hots", "made", "mads", "mama", "mane", "mans", "mare", "mars", "mart", "mash", "mass", "mast", "mate", "math", "mats", "matt", "mead", "mean", "meas", "meat", "meed", "meet", "memo", "mend", "mens", "mere", "mesa", "mesh", "mess", "meta", "mete", "moan", "moas", "moat", "mode", "modo", "mods", "moms", "mono", "mons", "mood", "moon", "moor", "moos", "moot", "more", "morn", "mort", "moss", "most", "mote", "moth", "mots", "name", "nard", "nasa", "nato", "near", "neat", "need", "neon", "nerd", "ness", "nest", "nets", "noah", "node", "nods", "noes", "nome", "noms", "none", "noon", "norm", "nose", "nosh", "nota", "note", "nots", "oars", "oath", "oats", "odds", "odes", "odor", "ohed", "ohms", "omen", "ones", "onto", "oohs", "ordo", "ores", "orth", "orts", "otto", "rads", "rams", "rand", "rant", "rara", "rare", "rase", "rash", "rata", "rate", "rats", "read", "ream", "rear", "redo", "reds", "reed", "rems", "rend", "reno", "rent", "rest", "retd", "rhea", "road", "roam", "roan", "roar", "rode", "rods", "roes", "rome", "roms", "rood", "room", "root", "rosa", "rose", "rote", "roto", "rots", "same", "sand", "sane", "sans", "sash", "sass", "sate", "seam", "sear", "seas", "seat", "seed", "seem", "seen", "seer", "sees", "send", "sent", "sera", "sere", "sets", "shad", "shah", "sham", "shat", "shed", "shes", "shmo", "shod", "shoe", "shoo", "shot", "snot", "soar", "soda", "sods", "soma", "some", "sons", "soon", "soot", "sore", "sort", "sots", "star", "stat", "stem", "stet", "stoa", "tads", "tame", "tams", "tans", "taos", "tare", "tarn", "taro", "tars", "tart", "tass", "tate", "tats", "team", "tear", "teas", "teat", "teds", "teed", "teem", "teen", "tees", "tend", "tens", "tent", "term", "tern", "terr", "test", "than", "that", "thee", "them", "then", "thor", "thro", "toad", "toed", "toes", "tome", "toms", "tone", "tons", "toot", "tora", "tore", "torn", "toro", "tors", "tort", "tosh", "toss", "tost", "tote", "toto", "tots", "tram", "tree", "trod", "trot", "tsar"};

void setup() {
  Serial.begin(9600);

  bool found = isStringInArray(correctWord, myArray, 278);

  for(int i = 0; i < 5; i++) {
    pinMode(greenLEDs[i], OUTPUT);
    pinMode(yellowLEDs[i], OUTPUT);
  }
  
  if (found) {
    Serial.println("woohoo! is in the array!!");
  } else {
    Serial.println("is NOT in the array");
  }
}

void loop() {

  resetLEDs();

  int potValue1 = analogRead(potPin1);  //or A0
  int potValue2 = analogRead(potPin2);
  int potValue3 = analogRead(potPin3);
  int potValue4 = analogRead(potPin4);
  int potValue5 = analogRead(potPin5);
  

  // Calculate which letter each potentiometer is pointing to
  char letter1 = getLetter(potValue1);
  char letter2 = getLetter(potValue2);
  char letter3 = getLetter(potValue3);
  char letter4 = getLetter(potValue4);
  char letter5 = getLetter(potValue5);

  // Concatenate the letters into a single string
  String combinedLetters = String(letter1) + String(letter2) + String(letter4) + String(letter5);

  // Print the combined letters for debugging
  Serial.print("Combined letters: ");
  Serial.println(combinedLetters);

  // Check if the combined string is a particular string
  if (combinedLetters == correctWord) {
    Serial.println("CORRECT!");
  } else {
    Serial.println("nope");
    Serial.println(potValue2);
  }

  bool isValid = isStringInArray(combinedLetters, myArray2, 379);
  if (isValid) {
    Serial.println("it's in there doe");
    for(int i = 0; i < 5; i++) {
      if(combinedLetters[i] == correctWord[i]) {
        // Correct letter in the correct position - turn the green LED on
        digitalWrite(greenLEDs[i], HIGH);
      } else if (correctWord.indexOf(combinedLetters[i]) != -1) {
        // Correct letter but in the wrong position - turn the yellow LED on
        digitalWrite(yellowLEDs[i], HIGH);
      }
      // If none of the above, the LED stays off
    }
  }

  delay(500); // Delay for a half-second
}


char getLetter(int value) {
  int index; // Declare the index variable
  if (value < 20) index = 0;
  else if (value < 150) index = 1;
  else if (value < 250) index = 2;
  else if (value < 380) index = 3;
  else if (value < 555) index = 4;
  else if (value < 720) index = 5;
  else if (value < 830) index = 6;
  else if (value < 935) index = 7;
  else if (value < 1005) index = 8;
  else index = 9;  // Assumes any value above 850 corresponds to the last index

  return letters.charAt(index);  // Return the character at the calculated index
}

// Function to check if a string is in the array
bool isStringInArray(String target, String array[], int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    if (array[i] == target) {
      return true; // Found the string
    }
  }
  return false; // Did not find the string
}

void resetLEDs() {
  // Turn all LEDs off
  for(int i = 0; i < 5; i++) {
    digitalWrite(greenLEDs[i], LOW);
    digitalWrite(yellowLEDs[i], LOW);
  }
}



