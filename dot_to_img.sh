IFP=$'\t'

for i in *.dot; do
	dot -Tpng "$i" > "$(basename -s .dot $i).png" 
done
