# Word_Predicter_Cpp
 Program developed in C++ that will recommend new word to user based onfrequency of his previously entered words.
 
**Approach:**
This C++ program implements a real-time text input recommendation system based on the frequency of previously entered words. It provides word suggestions as the user types, allowing for efficient and personalized text input.

**Data Structure Usage:**
1. **Map (std::map):**
   - A map is employed to store the frequency of each entered word. The word serves as the key, and the associated value represents its occurrence count.
   - This allows for quick retrieval of word frequencies and efficient tracking of user input history.

2. **Vector (std::vector):**
   - A vector is utilized to store the entered words, maintaining the order in which they were typed.
   - Suggestions are generated based on the frequency of words in the map and displayed to the user.

**Intuition:**
1. **Input Handling:**
   - The program captures words entered by the user, stored in a vector (`vect`).
   - As each word is entered, the corresponding map (`map`) is updated to track its frequency.

2. **Suggestion Generation:**
   - Suggestions are dynamically generated based on the frequency of previously entered words.
   - The `Suggestions` function sorts words by frequency and provides the top suggestions, excluding repeated entries.

3. **User Interaction:**
   - The program continuously displays the entered words and offers suggestions.
   - Users can select suggestions using Ctrl + (A, B, C, D) or choose to skip a suggestion with Enter/Spacebar.
   - Pressing Esc exits the program.

**Usage:**
1. **Typing:**
   - Start typing words, pressing Enter instead of Spacebar when completing a word.
   - Suggestions will be displayed based on the frequency of previously entered words.

2. **Selection:**
   - Use Ctrl + (A, B, C, D) to select a suggestion.
   - Press Enter/Spacebar to skip a suggestion.

3. **Exit:**
   - Press Esc to exit the program.

**Example:**
   - The provided example showcases the program's functionality, providing real-time word suggestions based on the user's input history.

**Note:**
   - Ensure proper terminal support for special key inputs (Ctrl + A, B, C, D, Esc). The program uses the `conio.h` library for getch().

**Execution:**
   - Compile and run the program, then follow the on-screen instructions. Press Esc to exit when done.
