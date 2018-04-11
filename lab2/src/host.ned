

package lab2;

simple Application
{
    parameters:
        int datalen;
        double packGenTime;
    gates:
        inout IPcon;
}

simple IP
{
    parameters:
        int destIP;
        int srcIP;
    gates:
        inout appCon;
        inout ethCon;
}

simple Ethernet
{
    parameters:
        string srcMac;
        string destMac;

    gates:
        inout IPCon;
        inout switchCon;
}

module switch
{
    parameters:
        string asdac;
        string badfbadfb;

    gates:
        inout hostGate[4];
}

module Host
{
    gates:
        inout switchCon;
    submodules:
        app: Application;
        ipMod: IP;
        ethMod: Ethernet;
    connections:

}
module wirelessHost extends Host{
   parameters:
       int xcord = default(6);
       int ycord = default(6); 
}

network topology
{
    types:
        channel Channel extends ned.DelayChannel
        {
            delay = 100ms;
        }
    submodules:
        
        host0 : wirelessHost;
        hostMod[3] : Host;
        switchMod : switch;
        
        
    connections:
        
    	if(sqrt(pow(host0.xcord,2)+pow(host0.ycord,2)) < 5)
    	{
    		host0.switchCon <--> Channel <--> switchMod.hostGate++;
    	}
        hostMod[0].switchCon <--> Channel <--> switchMod.hostGate++;
        hostMod[1].switchCon <--> Channel <--> switchMod.hostGate++;
        hostMod[2].switchCon <--> Channel <--> switchMod.hostGate++;
        //hostMod[3].switchCon <--> Channel <--> switchMod.hostGate++;
}
