# Installation des drivers WiFi sur Ubuntu 24.04.1 – Dell XPS 13 9350 (2024)

Le Dell XPS 13 9350 (2024) embarque généralement une carte WiFi **Intel Wi-Fi 6E AX211**.
Ce guide explique comment faire fonctionner cette carte sous Ubuntu 24.04.1.

---

## 1. Identifier la carte réseau

```bash
lspci | grep -i network
# ou
lspci | grep -i wireless
```

Exemple de sortie attendue :
```
Network controller: Intel Corporation Wi-Fi 6E(802.11ax) AX211 160MHz (rev 1a)
```

Vérifier également l'état du périphérique :
```bash
ip link
```
L'interface WiFi apparaît généralement sous la forme `wlp2s0` ou `wlo1`.

---

## 2. Mettre à jour le système

```bash
sudo apt update && sudo apt upgrade -y
```

---

## 3. Installer / mettre à jour le firmware Intel

Le driver `iwlwifi` (inclus dans le noyau Linux) a besoin des firmwares Intel.

```bash
sudo apt install linux-firmware
```

Vérifier si le firmware est présent :
```bash
ls /lib/firmware/iwlwifi-ty-a0-gf-a0*
```

Si des fichiers apparaissent, le firmware est bien installé.

---

## 4. Charger le module kernel

```bash
sudo modprobe iwlwifi
```

Vérifier que le module est actif :
```bash
lsmod | grep iwlwifi
```

---

## 5. Installer le paquet de backport (si le WiFi ne fonctionne toujours pas)

Pour les cartes très récentes, un backport du driver peut être nécessaire :

```bash
sudo apt install backport-iwlwifi-dkms
```

Après l'installation, redémarrer la machine :
```bash
sudo reboot
```

---

## 6. Vérifier que le WiFi est actif

Après le redémarrage :

```bash
ip link show wlp2s0
# ou
nmcli device status
```

Activer l'interface si elle est dans l'état `DOWN` :
```bash
sudo ip link set wlp2s0 up
```

Se connecter à un réseau :
```bash
nmcli device wifi list
nmcli device wifi connect "NomDuReseau" password "MotDePasse"
```

---

## 7. Dépannage

| Symptôme | Action |
|----------|--------|
| `RTNETLINK answers: Operation not possible due to RF-kill` | `sudo rfkill unblock wifi` |
| Firmware manquant dans les logs (`dmesg`) | Réinstaller `linux-firmware` + redémarrer |
| Interface absente de `ip link` | `sudo modprobe -r iwlwifi && sudo modprobe iwlwifi` |
| Driver non reconnu | Mettre à jour le noyau : `sudo apt install linux-generic-hwe-24.04` |

Consulter les logs du noyau pour plus de détails :
```bash
dmesg | grep iwlwifi
```

---

## Références

- [Ubuntu – Installation des pilotes WiFi](https://help.ubuntu.com/community/WifiDocs/Driver)
- [Intel Linux WiFi](https://wireless.wiki.kernel.org/en/users/drivers/iwlwifi)
- [backport-iwlwifi-dkms (Launchpad)](https://launchpad.net/ubuntu/+source/backport-iwlwifi-dkms)
