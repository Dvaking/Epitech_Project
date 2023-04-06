
Ce que j'ai fait : 
    ->j'ai fais un fichier includes/ pour les deux programme (pour les proto en commun comme les limite et les proto de lib);
    ->Le fichier error_handing/ c'est là que l'on va mettre tout ce qui touche a l'error handing;
    ->J'ai commencé le script, pour reccupérer la taille du fichier et tout il y a la commande oak a associer au ls;

Your Goals :
    MUST
        • The antman binary must write a compressed version of the file it got as a parameter on the standard output
        • The giantman binary must write the original version of the compressed file it got as a parameter on the standard output
        • The original file printed by giantman must be the exact same as the one that antman got as parameter
        • The programs must work with files containing any value
        • The programs must compress files sometimes
        • The programs mustn’t take an unreasonable time to run, even on large files.
        • The programs must work with files that you only have permission to read from
    SHOULD
        • The compressed file shouldn’t be bigger than the original file.
        • The programs should take into account the given filetype.
        • The programs should compress files everytime.
    COULD
        • You could define new and/or more precise filetypes and use them
        • You could push a quantified analysis of your different compression algorithms as a bonus
        • You could propose new challenges for your peers and organise a competition
        • The programs could gather informations from the file itself (extension, size) and use them as indicators