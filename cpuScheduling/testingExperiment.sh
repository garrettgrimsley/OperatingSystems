#!/bin/bash
cd outputs/
rm *
cd ..
for i in {1..10};
do
    echo ======== LOOP NUMBER $i ========
	./OSP parameters.high > /dev/null
	tail simulation.run | egrep 'throughput|turnaround|waiting' > "outputs/vanilla$i.txt"
	./OSP.demo.FCFS -d parameters.high > /dev/null
	tail simulation.run | egrep 'throughput|turnaround|waiting' > "outputs/fcfs$i.txt"
	./OSP.demo.RR -d parameters.high > /dev/null
	tail simulation.run | egrep 'throughput|turnaround|waiting' > "outputs/rr$i.txt"
	./OSP.demo.SJN -d parameters.high > /dev/null;
	tail simulation.run | egrep 'throughput|turnaround|waiting' > "outputs/sjn$i.txt"
done
cd outputs
cat vanilla* > vout.txt
cat fcfs* > fout.txt
cat rr* > rout.txt
cat sjn* > sout.txt

for i in vout fout rout sout
do
	echo System Throughput for $i
	sed -n '1~3p' $i.txt | awk 'NF>1{print $NF}'

	echo Average Waiting Time for $i
	sed -n '2~3p' $i.txt | awk 'NF>1{print $NF}'

	echo Average Turnaround for $i
	sed -n '3~3p' $i.txt | awk 'NF>1{print $NF}'
done