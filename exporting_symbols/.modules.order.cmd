cmd_/home/sai25goud/Documents/exporting_symbols/modules.order := {   echo /home/sai25goud/Documents/exporting_symbols/kern_sym.ko;   echo /home/sai25goud/Documents/exporting_symbols/kern_sym1.ko; :; } | awk '!x[$$0]++' - > /home/sai25goud/Documents/exporting_symbols/modules.order
