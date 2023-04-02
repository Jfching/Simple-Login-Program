#include <stdio.h>
#include <ctype.h>
#include <string.h>

//global variable labeling
    int a;
    int i;
    int checkin;
    int pcheckin;
    int console;
    char createusername[25];
    char createpassword[25];
    char username[25];
    char password[25];
    
//array for usernames/user inputted usernames    
    char userlist[10][25] = 
    {
     "panteater","qv"
    },uname[25];


//array for passwords/user inputted passwords
    char passlist[10][25] = 
    {
     "peter,","hellothere!"                        
    },pwrd[25];

//main menu
void menu ()
{
    
    printf("Welcome! \nIf you wish to sign up for an account, type in 1. \nIf you wish to login into your account, type in 2. \nTo quit, type in anything else. \nEnter: ");
    scanf("%d", &console);  // reads user input to determine whether login or sign up
    
}

//sign up menu
void signup()
{
    //determined from user input into console
    if (console == 1)
    {
        printf("\nIf you want to exit, input 0. \nPlease enter a username you want: ");
        
        
        //for(i = 0; i < 10; i++)
        
        //function to detect user input on creating a username
        scanf("%s", createusername);
        
        //printf("%s", userlist[4]);
        //printf("first character: %c ", createusername[0] );

                    //checking whether or not a username exists within the array
                for (i = 0; i < 10; i++)
                    {
                        if (strcmp(createusername, userlist[i]) == 0 )
                        {
                               pcheckin = 1;    //value returned when a username is equal to an existing one
                               break;
                        }
                    }
                    //provided there's no equal username, positive value is returned
                        if (pcheckin == 1)
                        {
                            printf("\nUsername already exists. \nPlease try again\n");
                            signup();
                            
                        }
                     //otherwise, the username is stored into the array for login
                        else
                        {
                            printf("You have successfully created a username");
                            strcpy(userlist[i], createusername);        //copies the user input string into the username array
                            
                            //printf("%s", userlist[i]);
                        }
                        
        //user inputs 0 to exit the login display back to the main menu
            if (createusername == 0)
            {
                main();
            }
        
        //asks user for creating a password after creating a username    
            else
            {
                printf("\nPlease enter a password you want: ");
                scanf("%s", passlist[i]);       //takes user input and stores it into the password array
                printf("\nPassword created successfully");
                printf("\nAccount has been created successfully.\nReturning to menu.\n");
                
                main();
                
            }
    }
    
}

//login menu
int login()
{
    //taken from user input from main menu console
     if (console == 2)
    {
        printf("\nPlease enter your username: ");
        scanf("%s", username);  //takes userinput for username for login
        
        for (i = 0; i < 10; i++)    //checking all 10 array spots if user inputted username exists
        {
            if (strcmp(username, userlist[i]) == 0 ) // function to check array
                {
                    checkin = 1;
                    break;
                }
        }
        
            if (checkin == 1) //if the previous function outputs a positive value,
            {
                printf("Please enter your password: ");
                scanf(" %s", password); //takes user input for password
                
                //used for next function to go through all 10 spots of array.
                for (i = 0; i < 10; i++)
                    {
                        if (strcmp(password, passlist[i]) == 0 )
                        {
                                pcheckin = 1;
                                break;
                        }
                    }
                    //when array outputs a positive value, log user in
                        if (pcheckin == 1)
                        {
                            printf("Hello! You have successfully logged in %s", username);
                            
                            return 0;
                        }
                     
                        else
                        {
                            printf("Password is incorrect");
                            
                            //loop for 3 attempts provided user inputs incorrect password
                            for ( a = 3; a >= 1; a--)
                            {
                                printf("\nPlease try again, %d attempts remaining\n", a);
                                printf("\nPlease enter your password: ");
                                scanf(" %s", password);     //user input for password
                                
                            
                                        
                                //used for next function for going through all 10 spots of array        
                                for (i = 0; i < 10; i++)
                                        {
                                            //used to check user inputted password with password array
                                        if (strcmp(password, passlist[i]) == 0 )
                                            {
                                                pcheckin = 1;
                                                break;
                                            }
                                        }
                                        
                                        
                                        //when array outputs a positive value, log user in
                                        if (pcheckin == 1)
                                        {
                                            printf("Hello! You have successfully logged in %s", username);
                                            
                                            return 0;
                                        }
                                        
                                        //used as a counter when all 3 attempts are used, return to menu
                                        if (a == 1)
                                        {
                                            printf("All three attempts have been used, returning to menu\n\n");
                                            main();
                                        }
                            }       
                    

                        }
                        
                        
            }
        
            else if (checkin == 0)
            {
                
            //    printf("\n%s", userlist[i]);
            //    printf("\n%s", passlist[i]);
                
                
                printf("\nUser does not exist");
                
                //for the 3 attempts in inputting an existing user
                        for ( a = 3; a >= 1; a--)
                            {
                                printf("\nPlease try again, %d attempts remaining\n", a);
                                printf("\nPlease enter your username: ");
                                scanf("%s", username);      //user input for username
                                //used for next function to go through all 10 spots of array
                                    for (i = 1; i < 10; i++)
                                        {
                                            //used to check user inputted username with username array
                                            if (strcmp(username, userlist[i]) == 0 )
                                            {
                                                        checkin = 1;
                                       
                                                        break;
                                            }
                                        }
                                        
                                        
                            
                    if (checkin == 1)
                        
                    {
                            printf("Please enter your password: ");
                            scanf(" %s", password);     //user input for password
                
                //used for the next function going through all 10 spots of an array
                    for (i = 0; i < 10; i++)
                    {
                        //checks for user input with password array and whether or not it matches
                        if (strcmp(password, passlist[i]) == 0 )
                        {
                                pcheckin = 1;
                                break;
                        }
                    }
                    //provided the array outputs a positive value.
                        if (pcheckin == 1)
                        {
                            printf("Hello! You have successfully logged in %s", username);
                            
                            return 0;
                        }
                        
                        else
                        {
                            printf("Password is incorrect");
                            
                            //loop regarding the 3 remaining attempts if user inputs incorrect password
                            for ( a = 3; a >= 1; a--)
                            {
                                printf("\nPlease try again, %d attempts remaining\n", a);
                                printf("\nPlease enter your password: ");
                                scanf(" %s", password);     //user input for password
                                    
                                    //checks through all 10 array spots for next function
                                    for (i = 0; i < 10; i++)
                                        {
                                            //checks user inputted password with password array, outputs a positive value if equal
                                        if (strcmp(password, passlist[i]) == 0 )
                                            {
                                                pcheckin = 1;
                                                break;
                                            }
                                        }
                                        //provided the array outputs a positive value, log in user
                                        if (pcheckin == 1)
                                        {
                                            printf("Hello! You have successfully logged in %s", username);
                                            
                                            return 0;
                                        }
                                        
                                        //checking if all attempts are used, if so, take user back to menu
                                        if (a == 1)
                                        {
                                            printf("All three attempts have been used, returning to menu\n\n");
                                            main();
                                        } 
                                    
                            }    
                                
                            
                            }
                            
                    }
                                        //checking if all attempts are used, if so, take user back to menu
                                        if (a == 1)
                                        {
                                            printf("All three attempts have been used, returning to menu\n\n");
                                            main();
                                        } 
                    
                            }
                        
                            
                
            
                            }
        
        //provided the array returns a positive value
            if (checkin == 1)
            {
                printf("Please enter your password: ");
                scanf(" %s", password);     //user input for password
                
                //function to check all array spots for next function
                for (i = 0; i < 10; i++)
                    {
                        //check user inputted string with password array
                        if (strcmp(password, passlist[i]) == 0 )
                        {
                                pcheckin = 1;
                                break;
                        }
                    }
                    //if array value outputs a positive value, log in the user
                        if (pcheckin == 1)
                        {
                            printf("Hello! You have successfully logged in %s", username);
                            
                            return 0;
                        }
                     
                        else
                        {
                            printf("Password is incorrect");
                            
                            //for loop for 3 attempts at the password
                            for ( i = 3; i >= 1; i--)
                            {
                                printf("\nPlease try again, %d attempts remaining\n", i);
                                printf("\nPlease enter your password: ");
                                scanf(" %s", password);     //user input for password
                                    
                                    //used to go through all 10 array spots for next function
                                    for (i = 0; i < 10; i++)
                                        {
                                            //function to check array for equal password
                                        if (strcmp(password, passlist[i]) == 0 )
                                            {
                                                pcheckin = 1;
                                                break;
                                            }
                                        }
                                        
                                        //if password is equal to one in array, log in
                                        if (pcheckin == 1)
                                        {
                                            printf("Hello! You have successfully logged in %s", username);
                                            
                                            return 0;
                                        }
                                
                                //return to main menu once all 3 attempts are used
                                    if (i == 1)
                                        {
                                            printf("All three attempts have been used, returning to menu\n\n");
                                            main();
                                         
                                        
                                        }    
                            }
                        }   
                            }   }
                            
                
            }

        
    



//where all the menu runs
int main()
{
    menu();
    signup();
    login();
    
    
    return 0;
}
