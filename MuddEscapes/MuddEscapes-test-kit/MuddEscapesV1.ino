// Assuming potentiometers are connected to pins 14 and 15
const int potPin1 = 14;
const int potPin2 = 15;

// Define the letter range. Can be replaced with any 10 letters.
String letters = "adehmnorst"; 
String correctWord = "dr"; 

String myArray[278] = {"added", "adder", "adore", "adorn", "aeons", "ahead", "amass", "amend", "antes", "areas", "arena", "armed", "aroma", "arose", "arson", "ashen", "ashes", "asses", "asset", "aster", "atoms", "atone", "attar", "dames", "dared", "dares", "darts", "dated", "dates", "deans", "dears", "death", "deeds", "deems", "demon", 
"dense", "dents", "deter", "doers", "domed", "domes", "donor", "dooms", "doors", "dosed", "doses", "doted", "dotes", "drama", "drams", "dread", "dream", "dress", "drone", "dross", "earns", "earth", "eased", "eases", "eaten", "eater", "ended", "enter", "erase", "erred", "error", "ether", "hands", "harem", "hares", "harms", "harsh", "harts", "haste", "hated", "hater", "heads", "heard", "hears", "heart", "heath", "heats", "heeds", "herds", "heron", "heros", "hoard", "homes", "hoods", "hoots", "horde", "horns", "horse", "hosts", "madam", "mamma", "manes", "manna", "manor", "manse", "mares", "marsh", "marts", "mason", "masts", "mated", "mates", "means", "meant", "meats", "meets", "memes", "mends", "meres", "mesas", "meted", "meter", "moans", "moats", "modem", "modes", "momma", "month", "moods", "moons", "moors", "moose", "mores", "motes", "moths", "motor", "motto", "named", "names", "nears", "needs", "nests", "nomad", "noose", "north", "nosed", "noses", "noted", "notes", "oases", "oaten", "oaths", "odder", "omens", "onset", "order", "other", "otter", "rarer", "rares", "rated", "rates", "reads", "reams", "rears", "reeds", "rends", "rents", "reset", "rests", "roads", "roams", "roars", "roast", "roman", "rooms", "roost", "roots", "roses", "sands", "saner", "sated", "seams", "seats", "sedan", "seeds", "seems", "seers", "semen", "sends", "sense", "shade", "shame", "shams", "share", "shear", "sheds", "sheen", 
"sheer", "sheet", "shoes", "shone", "shoon", "shoot", "shore", "shorn", "short", "shots", "shred", "smart", "smash", "smear", "smote", "snare", "sneer", "snore", "snort", "soars", "sooth", "sores", "sorts", "stand", "stare", "stars", "start", "state", "stead", "steam", "steed", "steer", "stems", "stern", "stone", "stood", "store", "storm", "tamed", "tamer", "tares", "tarts", "taste", "teams", "tears", "tease", "teems", "teens", "teeth", "tends", "tenet", "tenor", "tense", "tenth", "tents", "terms", "terse", "tests", "theme", "there", "these", "thorn", "those", "three", "throe", "toads", "toast", "tomes", "toned", "tones", "tooth", "torso", "torts", "totem", "trade", "trams", "trash", "tread", "treat", "treed", "trees", "trend", "tress", "troth", "trots"};


void setup() {
  Serial.begin(9600);
}

void loop() {
  int potValue1 = analogRead(potPin1);  //or A0
  int potValue2 = analogRead(potPin2);
  

  // Calculate which letter each potentiometer is pointing to
  char letter1 = getLetter(potValue1);
  char letter2 = getLetter(potValue2);

  // Concatenate the letters into a single string
  String combinedLetters = String(letter1) + String(letter2);

  // Print the combined letters for debugging
  Serial.print("Combined letters: ");
  Serial.println(combinedLetters);

  // Check if the combined string is a particular string
  if (combinedLetters == "dr") {
    Serial.println("CORRECT! DR");
  } else {
    Serial.println("nope");
  }

  delay(500); // Delay for a half-second
}

// Function to map potentiometer value to a letter
char getLetter(int value) {
  int index = value / 102; // Divide by 102 to get the index in the range 0-9
  if (index > 9) index = 9; // Ensure index is never out of bounds
  return letters.charAt(index);
}
