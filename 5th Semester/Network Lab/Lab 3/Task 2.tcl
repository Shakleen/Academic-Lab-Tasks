#Create a simulator object
set ns [new Simulator]

#Open the All trace file
set namfile [open out.nam w]
set f [open out.tr w]
$ns trace-all $f
$ns namtrace-all $namfile

#Create six nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

#Create links between the nodes
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n3 $n4 500kb 40ms DropTail
$ns duplex-link $n3 $n5 500kb 30ms DropTail
$ns simplex-link $n2 $n3 300kb 100ms DropTail
$ns simplex-link $n3 $n2 300kb 100ms DropTail

# Orientation of links
$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n3 $n4 orient right-up
$ns duplex-link-op $n3 $n5 orient right-down
$ns simplex-link-op $n2 $n3 orient right
$ns simplex-link-op $n3 $n2 orient left

#Set Queue Size of link (n2-n3) to 10
$ns queue-limit $n2 $n3 10

# ===========================================
# TCP 1
# ===========================================
# Creating and linking TCP agent to node n3.
set tcp1 [new Agent/TCP]
$ns attach-agent $n3 $tcp1
# Creating and linking the sink to node n1.
set sink1 [new Agent/TCPSink]
$ns attach-agent $n1 $sink1
$ns connect $tcp1 $sink1
$tcp1 set fid_ 1

#Setup a FTP over TCP connection
set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1
$ftp1 set packet_size_ 512


# TCP 2
#Setup a TCP connection
set tcp2 [new Agent/TCP]
$ns attach-agent $n3 $tcp2
set sink2 [new Agent/TCPSink]
$ns attach-agent $n1 $sink2
$ns connect $tcp2 $sink2
$tcp2 set fid_ 1

#Setup a FTP over TCP connection
set ftp2 [new Application/FTP]
$ftp2 attach-agent $tcp2
$ftp2 set packet_size_ 512


# TCP 3
#Setup a TCP connection
set tcp3 [new Agent/TCP]
$ns attach-agent $n3 $tcp3
set sink3 [new Agent/TCPSink]
$ns attach-agent $n1 $sink3
$ns connect $tcp3 $sink3
$tcp3 set fid_ 1

#Setup a FTP over TCP connection
set ftp3 [new Application/FTP]
$ftp3 attach-agent $tcp3
$ftp3 set packet_size_ 512

# UDP 1
#Setup a UDP connection
set udp1 [new Agent/UDP]
$ns attach-agent $n0 $udp1
set null1 [new Agent/Null]
$ns attach-agent $n4 $null1
$ns connect $udp1 $null1
$udp1 set fid_ 2

#Setup a CBR over UDP connection
set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp1
$cbr1 set packet_size_ 1000
$cbr1 set rate_ 0.01mb

# UDP 2
#Setup a UDP connection
set udp2 [new Agent/UDP]
$ns attach-agent $n0 $udp2
set null2 [new Agent/Null]
$ns attach-agent $n4 $null2
$ns connect $udp2 $null2
$udp2 set fid_ 2

#Setup a CBR2 over UDP connection
set cbr2 [new Application/Traffic/CBR]
$cbr2 attach-agent $udp2
$cbr2 set packet_size_ 1000
$cbr2 set rate_ 0.01mb


#Schedule events for the CBR and FTP agents
$ns at 0.1 "$cbr1 start"
$ns at 5.9 "$cbr1 stop"

$ns at 1.1 "$cbr2 start"
$ns at 6.1 "$cbr2 stop"

$ns at 1.0 "$ftp1 start"
$ns at 7.6 "$ftp1 stop"

$ns at 1.5 "$ftp2 start"
$ns at 5.3 "$ftp2 stop"

$ns at 2.7 "$ftp3 start"
$ns at 6.7 "$ftp3 stop"

#Call the finish procedure after 5 seconds of simulation time
$ns at 5.0 "finish"

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
set file [open cwnd_rtt.tr w]
$tcp1 attach $file
$tcp1 trace cwnd_
$tcp1 trace rtt_

#Run the simulation
$ns run