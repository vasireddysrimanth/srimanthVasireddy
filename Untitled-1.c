#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store network interface details
typedef struct {
    char interfaceName[20];
    char ipAddress[16];
    char subnetMask[16];
    char gateway[16];
} NetworkInterface;

// Function to configure a network interface
void configureInterface(NetworkInterface *iface) {
    printf("Configuring Interface: %s\n", iface->interfaceName);
    printf("IP Address: %s\n", iface->ipAddress);
    printf("Subnet Mask: %s\n", iface->subnetMask);
    printf("Gateway: %s\n", iface->gateway);
    printf("Configuration Applied Successfully!\n");
}

// Function to validate the configuration
int validateConfiguration(NetworkInterface *iface) {
    // Check for valid IP (basic validation)
    if (strchr(iface->ipAddress, '.') == NULL) {
        printf("Error: Invalid IP Address format.\n");
        return 0;
    }
    if (strchr(iface->subnetMask, '.') == NULL) {
        printf("Error: Invalid Subnet Mask format.\n");
        return 0;
    }
    if (strchr(iface->gateway, '.') == NULL) {
        printf("Error: Invalid Gateway format.\n");
        return 0;
    }
    printf("Validation Successful for Interface: %s\n", iface->interfaceName);
    return 1;
}

int main() {
    NetworkInterface iface;

    // Prompt user for network configuration details
    printf("Enter Interface Name: ");
    scanf("%s", iface.interfaceName);

    printf("Enter IP Address: ");
    scanf("%s", iface.ipAddress);

    printf("Enter Subnet Mask: ");
    scanf("%s", iface.subnetMask);

    printf("Enter Gateway: ");
    scanf("%s", iface.gateway);

    // Apply configuration
    configureInterface(&iface);

    // Validate configuration
    if (validateConfiguration(&iface)) {
        printf("Network Interface %s is ready to use.\n", iface.interfaceName);
    } else {
        printf("Configuration for Interface %s is invalid. Please retry.\n", iface.interfaceName);
    }

    return 0;
}
