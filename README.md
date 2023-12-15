# temp-folder
:file_folder: :hourglass: temp-folder is a linux timed, automatically closed folder applicaton to store temporary files that can be disposed,<br>
:bell: it has notifications for folder changes(insertion, deletion).<br>
:no_entry_sign: 🔖 temp-folder is a no-dependancy program, it only uses STL of c++.

### 🎫 Limitation
The software runs in the background as long as the PC is on, meaning that if the program is still runing and the PC is turned off, 
you will need to manually remove the temporary folder yourself.


### 📥 Installation

`git clone https://github.com/ImTheCurse/temp-folder.git`<br>
 `cd temp-folder`<br>
 `sh install.sh`<br>
 `cd /usr/local/bin/temp-folder`<br>
 `sudo make all`<br><br>
 if you are using regular bash shell or a diffrent shell, change ```.zshrc``` to shell of choice inside ```install.sh```

### 🚀 Running the Program
```
usage:
-n           : Name of temporary folder. | string |
-t           : Time until folder closes  | int |
-f           : Time format - "s" for second, "m" for minutes, "h" for hours | char|
```

command example:<br>
``` nohup tfold -n tempFolderName -t 1 -f m ```

### Disclaimer
This program is a proof-of-concept, and should not be used for storing important, non temporary files - beaware of the files you keep inside the temporary files.

### Copyright
This software is licensed under MIT. Copyright © 2022 Rani Giro.
