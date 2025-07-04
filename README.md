# corbeilleIntelligente

Réaliser par MYALTA BIEN-AIME Tchenicien en informatique 
✨ Fonctionnalités
Détection du Niveau de Remplissage : Utilise deux capteurs ultrasons pour mesurer avec précision le niveau des déchets et déterminer si la corbeille est vide, à moitié pleine ou pleine.

Indication Visuelle : Trois LED signalent l'état de remplissage de la corbeille (verte : vide, jaune : mi-pleine, rouge : pleine).

Ouverture Automatique : Un servomoteur ouvre le couvercle de la corbeille lorsque des déchets sont détectés à proximité, évitant le contact manuel.

Notification SMS : Lorsqu'un niveau critique de remplissage est atteint (par exemple, 80% ou pleine), le module SIM808 envoie une alerte SMS à un numéro prédéfini.

Communication GPRS (Optionnel) : Le module SIM808 peut être configuré pour envoyer des données vers un serveur ou une plateforme IoT pour un suivi à distance plus avancé (requiert un développement backend).

🛠️ Composants Matériels
Voici la liste des composants nécessaires pour reproduire ce projet :

Carte Arduino (Uno, Nano ou équivalent) : Le cerveau du système.

2 Capteurs Ultrasons HC-SR04 : Pour mesurer les distances et le niveau de remplissage.

1 Servomoteur SG90 (ou équivalent) : Pour l'ouverture et la fermeture du couvercle.

1 Module SIM808 (ou SIM900) : Pour les fonctionnalités GSM/GPRS (envoi de SMS, communication de données).

3 LED (une verte, une jaune, une rouge) : Pour l'affichage visuel du niveau de remplissage.

Résistances (pour les LED, généralement 220 ohms).

Câbles de connexion (Male-Male, Male-Female).

Breadboard (platine d'expérimentation) ou PCB personnalisé.

Batterie/Alimentation pour l'Arduino et le module SIM808 (le SIM808 nécessite une alimentation stable et suffisante, souvent 5V et jusqu'à 2A en pointe).

Carte SIM (avec crédit ou forfait pour les SMS).

