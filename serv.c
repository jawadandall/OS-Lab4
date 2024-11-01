// #include <netinet/in.h> //structure for storing address information 
// #include <stdio.h> 
// #include <string.h>
// #include <stdlib.h> 
// #include <sys/socket.h> //for socket APIs 
// #include <sys/types.h> 
// #include "list.h"

// #define PORT 9001
// #define ACK "ACK"
  
// int main(int argc, char const* argv[]) 
// { 
  
// 	  int n, val, idx;
//     // create server socket similar to what was done in 
//     // client program 
//     int servSockD = socket(AF_INET, SOCK_STREAM, 0); 
  
//     // string store data to recv/send to/from client 
//     char buf[1024];
// 		char sbuf[1024];
//     char* token;

//     // define server address 
//     struct sockaddr_in servAddr; 
  
// 	  // list
// 		list_t *mylist;


//     servAddr.sin_family = AF_INET; 
//     servAddr.sin_port = htons(PORT); 
//     servAddr.sin_addr.s_addr = INADDR_ANY; 
  
//     // bind socket to the specified IP and port 
//     bind(servSockD, (struct sockaddr*)&servAddr, 
//          sizeof(servAddr)); 
  
//     // listen for connections 
//     listen(servSockD, 1); 
  
//     // integer to hold client socket. 
//     int clientSocket = accept(servSockD, NULL, NULL); 

//     mylist = list_alloc();  // create the list

//     while(1){
//         // recvs messages from client socket 
//         n = recv(clientSocket, buf, sizeof(buf), 0);
// 				buf[n] = '\0';

//         if(n > 0){
//             token = strtok(buf, " ");
    
// 						if(strcmp(token,"exit") == 0){
// 							  list_free(mylist);
// 							  exit(1);
// 						}
// 						else if(strcmp(token,"get_length") == 0){
// 								// Make a Call
// 								val = list_length(mylist);
// 								sprintf(sbuf,"%s%d", "Length = ", val);
// 						}
// 						else if(strcmp(token,"add_front") == 0){
// 							  token = strtok(NULL, " ");  // get next token (value)
// 								val = atoi(token);
// 								// Make a Call
// 								sprintf(sbuf,"%s%d", ACK, val);
// 								list_add_to_front(mylist,val);
// 						}
// 						else if(strcmp(token,"remove_position") == 0){
// 							  token = strtok(NULL, " ");
// 								idx = atoi(token);
// 								// Make a Call
// 								val = list_remove_at_index(mylist,idx);
// 								sprintf(sbuf,"%s%d", ACK, val);
// 						}
// 						else if(strcmp(token,"print") == 0){
// 							  sprintf(sbuf,"%s", listToString(mylist));
// 						}
// 						// ADD THE OTHER OPERATIONS


//                 // send's messages to client socket 
//             send(clientSocket, sbuf, sizeof(sbuf), 0);
//         }
// 				memset(buf, '\0', 1024);
//     }
  
//     return 0; 
// }


// //My code below
// #include <netinet/in.h> 
// #include <stdio.h> 
// #include <string.h>
// #include <stdlib.h> 
// #include <sys/socket.h> 
// #include <sys/types.h> 
// #include "list.h"
// #include <signal.h>
// #include <unistd.h> // For close function

// #define PORT 9001
// #define ACK "ACK"

// int servSockD;
// int clientSocket;
// list_t *mylist;

// // Signal handler for SIGINT (Ctrl+C)
// void handle_sigint(int sig) {
//     printf("\nShutting down server...\n");
//     list_free(mylist); // Free the linked list
//     close(clientSocket); // Close the client socket
//     close(servSockD); // Close the server socket
//     exit(0); // Exit gracefully
// }


// int main(int argc, char const* argv[]) { 
//     int n, val, idx;
//     servSockD = socket(AF_INET, SOCK_STREAM, 0); 
//     char buf[1024];
//     char sbuf[1024];
//     char* token;

//     struct sockaddr_in servAddr; 
//     mylist= list_alloc();

//     servAddr.sin_family = AF_INET; 
//     servAddr.sin_port = htons(PORT); 
//     servAddr.sin_addr.s_addr = INADDR_ANY; 
//     bind(servSockD, (struct sockaddr*)&servAddr, sizeof(servAddr)); 
//     listen(servSockD, 1); 
//     clientSocket = accept(servSockD, NULL, NULL); 

//     mylist = list_alloc();  
//     // Set up the signal handler
//     signal(SIGINT, handle_sigint);

//     while(1) {
//         n = recv(clientSocket, buf, sizeof(buf), 0);
//         buf[n] = '\0';

//         if(n > 0) {
//             token = strtok(buf, " ");
    
//             if(strcmp(token,"exit") == 0) {
//                 list_free(mylist);
//                 exit(1);
//             } else if(strcmp(token,"get_length") == 0) {
//                 val = list_length(mylist);
//                 sprintf(sbuf,"%s%d", "Length = ", val);
//             } else if(strcmp(token,"add_front") == 0) {
//                 token = strtok(NULL, " ");
//                 val = atoi(token);
//                 list_add_to_front(mylist, val);
//                 sprintf(sbuf,"%s%d", ACK, val);
//             } else if(strcmp(token,"remove_position") == 0) {
//                 token = strtok(NULL, " ");
//                 idx = atoi(token);
//                 val = list_remove_at_index(mylist, idx);
//                 sprintf(sbuf,"%s%d", ACK, val);
//             } else if(strcmp(token,"print") == 0) {
//                 sprintf(sbuf,"%s", listToString(mylist));
//             } else if(strcmp(token,"add_back") == 0) {
//                 token = strtok(NULL, " ");
//                 val = atoi(token);
//                 list_add_to_back(mylist, val);
//                 sprintf(sbuf,"%s%d", ACK, val);
//             } else if(strcmp(token,"remove_back") == 0) {
//                 val = list_remove_from_back(mylist);
//                 sprintf(sbuf,"%s%d", ACK, val);
//             } else if(strcmp(token,"remove_front") == 0) {
//                 val = list_remove_from_front(mylist);
//                 sprintf(sbuf,"%s%d", ACK, val);
//             } else if(strcmp(token,"add_at_index") == 0) {
//                 token = strtok(NULL, " ");
//                 val = atoi(token);
//                 token = strtok(NULL, " ");
//                 idx = atoi(token);
//                 list_add_at_index(mylist, val, idx);
//                 sprintf(sbuf,"%s%d at index %d", ACK, val, idx);
//             } else if(strcmp(token,"get_at_index") == 0) {
//                 token = strtok(NULL, " ");
//                 idx = atoi(token);
//                 val = list_get_elem_at(mylist, idx);
//                 sprintf(sbuf, "Value at index %d = %d", idx, val);
//             } else if(strcmp(token,"contains") == 0) {
//                 token = strtok(NULL, " ");
//                 val = atoi(token);
//                 sprintf(sbuf, "%s", list_is_in(mylist, val) ? "Value exists" : "Value does not exist");
//             } else if(strcmp(token,"index_of") == 0) {
//                 token = strtok(NULL, " ");
//                 val = atoi(token);
//                 idx = list_get_index_of(mylist, val);
//                 sprintf(sbuf, "Index of value %d = %d", val, idx);
//             }

//             send(clientSocket, sbuf, sizeof(sbuf), 0);
//         }
//         memset(buf, '\0', 1024);
//     }
  
//     return 0; 
// }


// #include <netinet/in.h> //structure for storing address information
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <sys/socket.h> //for socket APIs
// #include <sys/types.h>
// #include "list.h"

// #define PORT 9001
// #define ACK "ACK:" // Acknowledgment prefix for server responses

// int main(int argc, char const* argv[]) {
//     int n, val, idx;
//     // create server socket similar to what was done in
//     // client program
//     int servSockD = socket(AF_INET, SOCK_STREAM, 0);
    
//     // string store data to recv/send to/from client
//     char buf[1024];
//     char sbuf[1024];
//     char* token;
    
//     // define server address
//     struct sockaddr_in servAddr;
    
//     // list
//     list_t *mylist;

//     servAddr.sin_family = AF_INET;
//     servAddr.sin_port = htons(PORT);
//     servAddr.sin_addr.s_addr = INADDR_ANY;

//     // bind socket to the specified IP and port with error checking
//     if (bind(servSockD, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0) {
//         perror("Bind failed");
//         exit(1);
//     }

//     // listen for connections with status message
//     listen(servSockD, 1);
//     printf("Server listening on port %d...\n", PORT);

//     // integer to hold client socket
//     int clientSocket = accept(servSockD, NULL, NULL);
//     printf("Client connected!\n"); // Notify when client connects

//     mylist = list_alloc();  // create the list

//     while(1) {
//         // recvs messages from client socket
//         n = recv(clientSocket, buf, sizeof(buf), 0);
//         buf[n] = '\0';

//         if (n > 0) {
//             token = strtok(buf, " ");

//             // Handle exit command - cleanup and terminate
//             if (strcmp(token, "exit") == 0) {
//                 list_free(mylist);
//                 close(clientSocket);
//                 close(servSockD);
//                 printf("Server shutting down...\n");
//                 exit(0);
//             }
#include <netinet/in.h> //structure for storing address information
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h> //for socket APIs
#include <sys/types.h>
#include <signal.h> // for signal handling
#include "list.h"

#define PORT 9001
#define ACK "ACK:" // Acknowledgment prefix for server responses

// Global variables for cleanup in signal handler
static int servSockD = -1;
static int clientSocket = -1;
static list_t *mylist = NULL;

// Signal handler for graceful termination
void handle_sigint(int sig) {
    printf("\nReceived Ctrl-C (SIGINT). Cleaning up...\n");
    
    // Free the linked list if it exists
    if (mylist != NULL) {
        list_free(mylist);
        mylist = NULL;
    }
    
    // Close client socket if it's open
    if (clientSocket != -1) {
        close(clientSocket);
        clientSocket = -1;
    }
    
    // Close server socket if it's open
    if (servSockD != -1) {
        close(servSockD);
        servSockD = -1;
    }
    
    printf("Server shutdown complete.\n");
    exit(0);
}

int main(int argc, char const* argv[]) {
    int n, val, idx;
    
    // Set up signal handler for Ctrl-C
    struct sigaction sa;
    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Error setting up signal handler");
        exit(1);
    }
    
    // create server socket similar to what was done in
    // client program
    servSockD = socket(AF_INET, SOCK_STREAM, 0);
    
    // string store data to recv/send to/from client
    char buf[1024];
    char sbuf[1024];
    char* token;
    
    // define server address
    struct sockaddr_in servAddr;
    
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(PORT);
    servAddr.sin_addr.s_addr = INADDR_ANY;

    // bind socket to the specified IP and port with error checking
    if (bind(servSockD, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    // listen for connections with status message
    listen(servSockD, 1);
    printf("Server listening on port %d...\n", PORT);

    // integer to hold client socket
    clientSocket = accept(servSockD, NULL, NULL);
    printf("Client connected!\n"); // Notify when client connects

    mylist = list_alloc();  // create the list

    while(1) {
        // recvs messages from client socket
        n = recv(clientSocket, buf, sizeof(buf), 0);
        buf[n] = '\0';

        if (n > 0) {
            token = strtok(buf, " ");

            // Handle exit command - cleanup and terminate
            if (strcmp(token, "exit") == 0) {
                list_free(mylist);
                mylist = NULL;
                close(clientSocket);
                close(servSockD);
                printf("Server shutting down...\n");
                exit(0);
            }
            // Get length command - returns list length
            else if (strcmp(token, "get_length") == 0) {
                val = list_length(mylist);
                sprintf(sbuf, "Length = %d", val);
            }
            // Add to front command - adds value to list front
            else if (strcmp(token, "add_front") == 0) {
                token = strtok(NULL, " ");  // get next token (value)
                val = atoi(token);
                list_add_to_front(mylist, val);
                sprintf(sbuf, "%s %d added to front", ACK, val);
            }
            // Add to back command - adds value to list end
            else if (strcmp(token, "add_back") == 0) {
                token = strtok(NULL, " ");  // get next token (value)
                val = atoi(token);
                list_add_to_back(mylist, val);
                sprintf(sbuf, "%s %d added to back", ACK, val);
            }
            // Add at position command - adds value at specific index
            else if (strcmp(token, "add_position") == 0) {
                token = strtok(NULL, " ");  // get index
                idx = atoi(token);
                token = strtok(NULL, " ");  // get value
                val = atoi(token);
                list_add_at_index(mylist, val, idx);
                sprintf(sbuf, "%s %d added at position %d", ACK, val, idx);
            }
            // Remove from front command - removes and returns front element
            else if (strcmp(token, "remove_front") == 0) {
                val = list_remove_from_front(mylist);
                sprintf(sbuf, "%s %d removed from front", ACK, val);
            }
            // Remove from back command - removes and returns last element
            else if (strcmp(token, "remove_back") == 0) {
                val = list_remove_from_back(mylist);
                sprintf(sbuf, "%s %d removed from back", ACK, val);
            }
            // Remove at position command - removes and returns element at index
            else if (strcmp(token, "remove_position") == 0) {
                token = strtok(NULL, " ");
                idx = atoi(token);
                val = list_remove_at_index(mylist, idx);
                sprintf(sbuf, "%s %d removed from position %d", ACK, val, idx);
            }
            // Get element command - returns element at specified index
            else if (strcmp(token, "get") == 0) {
                token = strtok(NULL, " ");
                idx = atoi(token);
                val = list_get_elem_at(mylist, idx);
                if (val == -1) {
                    sprintf(sbuf, "Error: Invalid index");
                } else {
                    sprintf(sbuf, "Element at %d = %d", idx, val);
                }
            }
            // Print command - returns string representation of list
            else if (strcmp(token, "print") == 0) {
                sprintf(sbuf, "%s", listToString(mylist));
            }
            // Invalid command handler
            else {
                sprintf(sbuf, "Invalid command");
            }

            // send's messages to client socket
            send(clientSocket, sbuf, sizeof(sbuf), 0);
        }
        memset(buf, '\0', 1024);
    }

    return 0;
}

