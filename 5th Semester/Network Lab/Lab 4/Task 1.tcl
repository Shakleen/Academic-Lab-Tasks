#Create a simulator object
set ns [new Simulator]

#Open the All trace file
set namfile [open out.nam w]
set f [open out.tr w]
$ns trace-all $f
$ns namtrace-all $namfile

#Create 11 nodes
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]
set n7 [$ns node]
set n8 [$ns node]
set n9 [$ns node]
set n10 [$ns node]
set n11 [$ns node]

#Create links between the nodes and orient them properly
$ns duplex-link $n1 $n2 1Mb 20ms DropTail
$ns duplex-link-op $n1 $n2 orient right-up

$ns duplex-link $n1 $n3 1Mb 20ms DropTail
$ns duplex-link-op $n1 $n3 orient right-down

$ns duplex-link $n2 $n4 1Mb 20ms DropTail
$ns duplex-link-op $n2 $n4 orient right-up

$ns duplex-link $n3 $n5 1Mb 20ms DropTail
$ns duplex-link-op $n3 $n5 orient right-up

$ns duplex-link $n3 $n6 1Mb 20ms DropTail
$ns duplex-link-op $n3 $n6 orient right-down

$ns duplex-link $n4 $n7 1Mb 20ms DropTail
$ns duplex-link-op $n4 $n7 orient right-up

$ns duplex-link $n4 $n8 1Mb 20ms DropTail
$ns duplex-link-op $n4 $n8 orient right-down

$ns duplex-link $n5 $n9 1Mb 20ms DropTail
$ns duplex-link-op $n5 $n9 orient right

$ns duplex-link $n6 $n10 1Mb 20ms DropTail
$ns duplex-link-op $n6 $n10 orient right-up

$ns duplex-link $n6 $n11 1Mb 20ms DropTail
$ns duplex-link-op $n6 $n11 orient right-down

#Set Queue Size to default size
$ns queue-limit $n1 $n2 50
$ns queue-limit $n1 $n3 50
$ns queue-limit $n2 $n4 50
$ns queue-limit $n3 $n5 50
$ns queue-limit $n3 $n6 50
$ns queue-limit $n4 $n7 50
$ns queue-limit $n4 $n8 50
$ns queue-limit $n5 $n9 50
$ns queue-limit $n6 $n10 50
$ns queue-limit $n6 $n11 50

# ##############################
# Setting up TCP connection 1
set TCP1 [new Agent/TCP]
$ns attach-agent $n7 $TCP1
set SINK1 [new Agent/TCPSink]
$ns attach-agent $n11 $SINK1
$ns connect $TCP1 $SINK1
$TCP1 set fid_ 0

# Setup a FTP over TCP connection
set FTP1 [new Application/FTP]
$FTP1 attach-agent $TCP1

# Setup Start and end time
$ns at 2.0 "$FTP1 start"
$ns at 20.0 "$FTP1 stop"
# ##############################

# ##############################
# Setting up TCP connection 2
set TCP2 [new Agent/TCP]
$ns attach-agent $n8 $TCP2
set SINK2 [new Agent/TCPSink]
$ns attach-agent $n11 $SINK2
$ns connect $TCP2 $SINK2
$TCP2 set fid_ 1

# Setup a FTP over TCP connection
set FTP2 [new Application/FTP]
$FTP2 attach-agent $TCP2

# Setup Start and end time
$ns at 4.0 "$FTP2 start"
$ns at 25.0 "$FTP2 stop"
# ##############################

# ##############################
# Setting up TCP connection 3
set TCP3 [new Agent/TCP]
$ns attach-agent $n9 $TCP3
set SINK3 [new Agent/TCPSink]
$ns attach-agent $n11 $SINK3
$ns connect $TCP3 $SINK3
$TCP3 set fid_ 2

# Setup a FTP over TCP connection
set FTP3 [new Application/FTP]
$FTP3 attach-agent $TCP3

# Setup Start and end time
$ns at 6.0 "$FTP3 start"
$ns at 30.0 "$FTP3 stop"
# ##############################

# ##############################
# Setting up TCP connection 4
set TCP4 [new Agent/TCP]
$ns attach-agent $n11 $TCP4
set SINK4 [new Agent/TCPSink]
$ns attach-agent $n1 $SINK4
$ns connect $TCP4 $SINK4
$TCP4 set fid_ 3

# Setup a FTP over TCP connection
set FTP4 [new Application/FTP]
$FTP4 attach-agent $TCP4

# Setup Start and end time
$ns at 8.0 "$FTP4 start"
$ns at 35.0 "$FTP4 stop"
# ##############################

# ##############################
# Setup UDP connection 1
set UDP1 [new Agent/UDP]
$ns attach-agent $n10 $UDP1
set NULL1 [new Agent/Null]
$ns attach-agent $n7 $NULL1
$ns connect $UDP1 $NULL1
$UDP1 set fid_ 4

# Setup a CBR over UDP connection
set CBR1 [new Application/Traffic/CBR]
$CBR1 attach-agent $UDP1

# Setup start and end time
$ns at 10.0 "$CBR1 start"
$ns at 40.0 "$CBR1 stop"
# ##############################

# ##############################
# Setup UDP connection 2
set UDP2 [new Agent/UDP]
$ns attach-agent $n6 $UDP2
$ns connect $UDP2 $NULL1
$UDP2 set fid_ 5

#Setup a CBR over UDP connection
set CBR2 [new Application/Traffic/CBR]
$CBR2 attach-agent $UDP2

# Setup start and end time
$ns at 12.0 "$CBR2 start"
$ns at 45.0 "$CBR2 stop"
# ##############################

# ##############################
# Setup UDP connection 3
set UDP3 [new Agent/UDP]
$ns attach-agent $n7 $UDP3
set NULL2 [new Agent/Null]
$ns attach-agent $n9 $NULL2
$ns connect $UDP3 $NULL2
$UDP3 set fid_ 6

#Setup a CBR over UDP connection
set CBR3 [new Application/Traffic/CBR]
$CBR3 attach-agent $UDP3

# Setup start and end time
$ns at 14.0 "$CBR3 start"
$ns at 50.0 "$CBR3 stop"
# ##############################

# ##############################
# Setup UDP connection 4
set UDP4 [new Agent/UDP]
$ns attach-agent $n8 $UDP4
$ns connect $UDP4 $NULL2
$UDP4 set fid_ 7

#Setup a CBR over UDP connection
set CBR4 [new Application/Traffic/CBR]
$CBR4 attach-agent $UDP4

# Setup start and end time
$ns at 16.0 "$CBR4 start"
$ns at 55.0 "$CBR4 stop"
# ##############################

#Call the finish procedure after 5 seconds of simulation time
$ns at 60 "finish"
#Print CBR packet size and interval
# puts "CBR packet size = [$cbr set packet_size_]"
# puts "CBR interval = [$cbr set interval_]"

#Define a 'finish' procedure
proc finish {} {
    global ns f namfile
    $ns flush-trace
    #Close the trace file
    close $f
    close $namfile
    exec nam out.nam &
    exit 0
}

# Trace Congestion Window and RTT
# set file [open cwnd_rtt.tr w]
# $tcp attach $file
# $tcp trace cwnd_
# $tcp trace rtt_

#Run the simulation
$ns run