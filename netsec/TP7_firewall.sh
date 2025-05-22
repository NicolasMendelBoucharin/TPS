#!/bin/bash
set -e
# set -x Uncomment for debug (or launch me with bash -x)



start (){

	#Acceptation des trucs dans loopback
	iptables -A INPUT -i lo -j ACCEPT
	iptables -A OUTPUT -o lo -j ACCEPT

	#Drop de google
	iptables -A OUTPUT --dst 8.8.8.8 -j DROP

	#Acceptation de tout ce qui viens de people.irisa.fr
	iptables -A INPUT --src people.irisa.fr -j ACCEPT

	#acceptation de tout ce qu'on a déjà contacté
	iptables -A INPUT -m conntrack --ctstate RELATED,ESTABLISHED -j ACCEPT
	
	#création de la chaine LOGDROP
	iptables -N LOGDROP
	
	#Log des paquest avec le prefix [LOGDROP] puis drop
	iptables -A LOGDROP -j LOG --log-prefix '[LOGDROP]'
	iptables -A LOGDROP -j DROP

	#envoie dans logdrop de facebook
	iptables -A OUTPUT --dst www.facebook.com -j LOGDROP
	ip6tables -A OUTPUT --dst www.facebook.com -j LOGDROP

	#acceptation de http(port 80)
	iptables -A INPUT -p tcp --dport 80 -j ACCEPT
	iptables -A INPUT -p udp --dport 80 -j ACCEPT

	#envoie dans logdrop de tout ce qui reste 
	iptables -A INPUT -j LOGDROP
}

stop (){
	iptables -F LOGDROP
	iptables -X LOGDROP
	iptables -F
	iptables -X
}

case $1 in

"start")
	start
	;;
"stop")
	stop
	;;
"restart"|"reload")
	stop
	start
	;;
"status")
	iptables -L -v -n
	;;
"help"|*)
	echo "Usage: $(basename $0) start|stop|restart|reload|status|help"
	exit 1
esac

