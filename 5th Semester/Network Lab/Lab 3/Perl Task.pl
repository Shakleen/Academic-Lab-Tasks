#!/usr/bin/perl
$src = "out.tr";

#initialization
$total_sent=0;
$total_recv=0;
$total_failed=0;
$T_delay=0;
$num_pkt=0;
$max_node = 6;

for ($i = 0; $i < $max_node; $i++) {
    $sent[$i] = 0;
    $recv[$i] = 0;
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
    
    if($input[0] eq '-' && $input[4] eq 'tcp') {
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
            print "Pckt:",$pck_id," Transmitted
            at:",$start[$pck_id]," src-ip:port-> ",$src_ip[$pck_id],":",$src_port[$pck_id]," dst-ip:port->",
            $dst_ip[$pck_id],":", $dst_port[$pck_id],"\n";
        }
    }

    #calculating receiving event
    if($input[0] eq 'r' && $input[4] eq 'tcp') {
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
            print "Pckt:",$pck_id," Received
            at:",$finish[$pck_id]," src-ip:port-> ",
            $src_ip[$pck_id],":",$src_port[$pck_id]," dst-ip:port->",
            $dst_ip[$pck_id],":", $dst_port[$pck_id],"\n";
        }
    }
}

#performance summary
$max = 0;
$min = 1000;
print "\n\nPer Source Survay:\n\n";
for ($i = 0; $i <=$max_node; $i++) {
    if ($sent[$i] > 0 ) {
        print " Source Node:",$i," ->
        Throughput(recved/sent): ",$recv[$i],"/", $sent[$i], "=",
        $recv[$i]/$sent[$i],"\n";
    }
}
print "\n\nAt a glance :\n";
print "Total_sent: ",$total_sent, "\nTotal_recv:", $total_recv,
"\nTotal_recv/Total_sent:", $total_recv/$total_sent,"\n";
close(IN);