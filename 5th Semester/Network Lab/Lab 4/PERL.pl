#!/usr/bin/perl
$src = "out.tr";

#initialization
$total_sent=0;
$total_recv=0;
$total_failed=0;
$T_delay=0;
$num_pkt=0;
$max_node = 12;
$unique_packets = 0;
@up;

for ($i = 0; $i < $max_node; $i++) {
    $sent[$i] = 0;
    $recv[$i] = 0;
    $flow_sent[$i] = 0;
    $flow_received[$i] = 0;
}

for ($i = 0; $i < 43155; $i++) {
    $up[$i] = 0;
}

#collecting trace content into a variable
open(IN, $src); # IN is a handler
@line=<IN>; # Creaing an array named line.

#print @line;
#handaling each event seperately

# Run a loop through the trace file. For each line do the following:
foreach $i (@line){
    #print $i;
    @input=split(' ', $i);
    
    #print $input[0]."\n";
    
    #calculating sending event
    if($input[0] eq '-' ) {
        $pck_id = $input[11];
        @temp_src = split('\.',$input[8]);
        @temp_dst = split('\.',$input[9]);
        $src_ip[$pck_id] = $temp_src[0];
        $src_port[$pck_id] = $temp_src[1];
        $dst_ip[$pck_id] = $temp_dst[0];
        $dst_port[$pck_id] = $temp_dst[1];

        if($input[2] eq $src_ip[$pck_id]){
            $sent[$temp_src[0]]++;
            $start[$pck_id] = $input[1];
            $status[$pck_id] = 0;
            $total_sent++;
            
            $flow_sent[$input[7]]++;
        }

        $up[$input[11]]++;
    }

    #calculating receiving event
    if($input[0] eq 'r') {
        $pck_id=$input[11];
        @temp_src = split('\.',$input[8]);
        @temp_dst = split('\.',$input[9]);
        $src_ip[$pck_id] = $temp_src[0];
        $src_port[$pck_id] = $temp_src[1];
        $dst_ip[$pck_id] = $temp_dst[0];
        $dst_port[$pck_id] = $temp_dst[1];

        if($input[3] eq $dst_ip[$pck_id]){
            $recv[$temp_src[0]]++;
            $finish[$pck_id] = $input[1];
            $status[$pck_id] = 1;
            $delay[$pck_id]=$finish[$pck_id]-
            $start[$pck_id];
            $total_recv++;

            $flow_received[$input[7]]++;
        }

        $up[$input[11]]++;
    }
}

#performance summary
$max = 0;
$min = 1000;
print "\n\nPer Source Survay:\n\n";
for ($i = 0; $i <= $max_node; $i++) {
    if ($sent[$i] > 0 ) {
        print " Source Node:",$i," ->
        flow_sent(recved/sent): ",$recv[$i],"/", $sent[$i], "=",
        $recv[$i]/$sent[$i],"\n";
    }
}
print "\n\nAt a glance :\n";
print "Total_sent: ",$total_sent, "\nTotal_recv: ", $total_recv,
"\nTotal_recv/Total_sent: ", $total_recv/$total_sent,"\n";
close(IN);

for ($i = 0; $i <= 7; $i++) {
    print "FID ", $i, " -> Total sent: ", $flow_sent[$i], 
    "\nTotal received: ", $flow_received[$i],
    "\nThroughput: ", $flow_received[$i]/$flow_sent[$i], "\n\n";
}

for ($i = 0; $i < 43155; $i++) {
    if ($up[$i] > 0) {
        $unique_packets++;
    }
}

print "Unique packets : ", $unique_packets, "\n";