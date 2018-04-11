 

packet App_pck {
    char data[];
}

packet IP_pck {
	int destIp;
	int srcIP;
	short reserved1;
	short length;
	short id;
	short fregOffset;
	char TTL;
	char protocol;
	short checksum;
}

packet Eth_pck {
	string srcMac;
	string destMac;
	short length;
}

packet ARP {
	char type;
	string srcMac;
	string destMac;
	int srcIP;
	int destIP;     
}