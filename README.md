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













**Instructions de câblage détaillées (exemple) :**

1.  **Capteurs Ultrasons (HC-SR04) :**
    * `VCC` du capteur au `5V` de l'Arduino.
    * `GND` du capteur au `GND` de l'Arduino.
    * `Trig` du capteur à une broche digitale de l'Arduino (ex: Capteur 1 Trig -> D9, Capteur 2 Trig -> D11).
    * `Echo` du capteur à une broche digitale de l'Arduino (ex: Capteur 1 Echo -> D10, Capteur 2 Echo -> D12).

2.  **Servomoteur :**
    * Fil Orange (Signal) à une broche digitale PWM de l'Arduino (ex: D6).
    * Fil Rouge (VCC) au `5V` de l'Arduino.
    * Fil Marron (GND) au `GND` de l'Arduino.

3.  **LEDs :**
    * Chaque LED est connectée à une broche digitale de l'Arduino via une résistance de 220 ohms (ex: LED Verte -> D2, LED Jaune -> D3, LED Rouge -> D4).
    * La patte courte (cathode) de chaque LED est connectée au `GND` de l'Arduino.

4.  **Module SIM808 :**
    * `VCC` du SIM808 à une alimentation externe stable de 4V (4.2V recommandé) capable de fournir jusqu'à 2A en pointe (ne pas alimenter directement via l'Arduino 5V, cela peut endommager l'Arduino ou le module).
    * `GND` du SIM808 au `GND` de l'alimentation externe ET au `GND` de l'Arduino (masse commune).
    * `TX` du SIM808 à la broche `RX` de l'Arduino (broche 0 si pas de `SoftwareSerial`, sinon la broche RX définie dans `SoftwareSerial`).
    * `RX` du SIM808 à la broche `TX` de l'Arduino (broche 1 si pas de `SoftwareSerial`, sinon la broche TX définie dans `SoftwareSerial`). **Attention :** Le SIM808 fonctionne en 3.3V pour ses broches RX/TX. Utilisez un **convertisseur de niveau logique (logic level converter)** si votre Arduino fonctionne en 5V pour éviter d'endommager le module SIM808.

---

## 💻 Installation du Code

1.  **Installez l'IDE Arduino :** Téléchargez et installez l'environnement de développement Arduino depuis [arduino.cc](https://www.arduino.cc/en/software).
2.  **Bibliothèques Requises :**
    * `Servo` : Généralement incluse par défaut avec l'IDE Arduino.
    * `SoftwareSerial` : Incluse par défaut avec l'IDE Arduino (nécessaire si vous utilisez d'autres broches que 0 et 1 pour la communication série avec le SIM808).
    * `(Optionnel) NewPing` : Pour une gestion plus avancée et robuste des capteurs ultrasons (disponible via le gestionnaire de bibliothèques de l'IDE Arduino).
    * `(Optionnel) TinyGSM` : Pour une interaction plus facile avec le module SIM808 pour les SMS/GPRS (disponible via le gestionnaire de bibliothèques).

    Pour installer une bibliothèque : Allez dans `Croquis` > `Inclure une bibliothèque` > `Gérer les bibliothèques...` et recherchez le nom de la bibliothèque.
3.  **Téléchargez le Code :** Clonez ce dépôt GitHub ou téléchargez les fichiers du projet.
4.  **Ouvrez le fichier `.ino` :** Ouvrez le fichier `corbeille_intelligente.ino` (ou le nom que vous avez donné à votre sketch) dans l'IDE Arduino.
5.  **Configurez le Numéro de Téléphone :** Dans le code, trouvez la ligne où le numéro de téléphone pour les alertes SMS est défini et remplacez-le par le numéro de votre choix.
    ```cpp
    // Exemple :
    const char* phoneNumber = "+33123456789"; // Remplacez par votre numéro
    ```
6.  **Sélectionnez la Carte et le Port :** Dans l'IDE Arduino, allez dans `Outils` > `Type de carte` et sélectionnez votre modèle d'Arduino. Ensuite, allez dans `Outils` > `Port` et sélectionnez le port série correspondant à votre Arduino.
7.  **Téléchargez le Code :** Cliquez sur le bouton "Téléverser" (flèche vers la droite) pour compiler et envoyer le code à votre carte Arduino.

---

## ⚙️ Configuration & Personnalisation

* **Seuils de Remplissage :** Vous pouvez ajuster les distances (en cm) dans le code pour définir les seuils "vide", "mi-plein" et "plein" en fonction de la taille de votre corbeille.
* **Angle du Servomoteur :** Ajustez les angles `SERV_OUVERT` et `SERV_FERME` pour que le couvercle s'ouvre et se ferme correctement.
* **Fréquence des Vérifications :** Modifiez les délais pour la fréquence de lecture des capteurs et d'envoi des SMS.
* **Messages SMS :** Personnalisez le contenu des messages SMS envoyés par le module SIM808.

---



## 🤝 Contribution

Les contributions sont les bienvenues ! Si vous avez des améliorations, des corrections de bugs ou de nouvelles fonctionnalités à proposer, n'hésitez pas à :

1.  `Fork` (dupliquer) ce dépôt.
2.  Créer une nouvelle branche (`git checkout -b feature/NouvelleFonctionnalite`).
3.  Effectuer vos modifications.
4.  `Commit` vos changements (`git commit -m 'Ajout de NouvelleFonctionnalite'`).
5.  `Push` vers votre branche (`git push origin feature/NouvelleFonctionnalite`).
6.  Ouvrir une `Pull Request` (Demande de Tirage).

---

## 📧 Contact
Pour toute question ou suggestion, n'hésitez pas a me contacter sur myaltabienaime@gmail.com ou sur +235 60 57 98 96 ou sur ma page facebook 

---

