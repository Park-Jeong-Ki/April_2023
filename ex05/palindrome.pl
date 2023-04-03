#!/usr/bin/perl  # This line specifies that the script should be run with Perl.

print "Enter a string: ";  # Asks the user to enter a string.

$input = <STDIN>;  # Reads a line of input from the user.
chomp($input);  # Removes the 개행 at the end of the input.

if ($input eq reverse $input)  # Checks if the input string is the same as its reverse.
{
    print("The string is a palindrome!\n");  # If it is, prints a message saying so.
}
else
{
    print("The string is not a palindrome.\n");  # If it isn't, prints a message saying so.
}
