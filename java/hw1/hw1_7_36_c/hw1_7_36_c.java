import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
public class hw1_7_36_c
{
	public static void main(String[] args) {
		int accumulator = 0, operation, operand, temp, input, haltFlag = 0, index = 0;
		int[] memory = new int[30];
		File file = new File("hw1_7_36_c.sml");
		Scanner stdioScanner = new Scanner(System.in);

		memory[25] = 1;
		memory[26] = -1;

        try {
            // Create a fileScanner to read from the file
            Scanner fileScanner = new Scanner(file);

            // Read input until the end of the file
            while (fileScanner.hasNext()) {
                memory[index] = Integer.parseInt(fileScanner.nextLine());
				index++;
            }

            // Close the fileScanner
            fileScanner.close();
        } catch (FileNotFoundException e) {
            // Handle file not found exception
            System.out.println("File not found: " + e.getMessage());
        }		
		index = 0;
		while(haltFlag == 0){
			operation = memory[index];
			operand = operation%100;
			operation /= 100;
			switch (operation) {
				case 10:
					System.out.printf("read: ");
					memory[operand] = stdioScanner.nextInt();
					break;
				case 11:
					System.out.printf("write: %d\n", memory[operand]);
					break;
				case 20:
					accumulator = memory[operand];
					break;
				case 21:
					memory[operand] = accumulator;
					break;
				case 30:
					accumulator += memory[operand];
					break;
				case 31:
					accumulator -= memory[operand];
					break;
				case 32:
					accumulator /= memory[operand];
					break;
				case 33:
					accumulator *= memory[operand];
					break;
				case 40:
					index = operand - 1;
					break;
				case 41:
					if(accumulator < 0){
						index = operand - 1;
					}
					break;
				case 42:
					if(accumulator == 0){
						index = operand - 1;
					}					
					break;
				case 43:
					haltFlag=1;
					break;
				// more cases can be added as needed
				default:
					System.out.printf("operation %d is not provided!", operation);
					System.exit(1);	
			}
			index++;

		}
		// for(int tempc: memory){
		// 	System.out.printf("%d\n", tempc);
		// }
	
	}
}
