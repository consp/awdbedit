# Awdbedit modified to read 4.50PG bioses (and bugfixes)

This "version" fixes some minor issues which annoyed me and carries the version into <insert date here>.

The latest release is compiled against the last Windows 10 SDK, should work on most machines but YMMV.

# fixes

v1.0.3
* Fixed tab order in IRQ routing edit
* Updated most unsafe string and file operations
* Fixed bug where if the new compressed blob would be smaller the original data would stick in place after the original.tmp and cause decompression errors. Depending on the decryption algorithm this might be the cause of corrupted bioses.

v1.0.2
* User can now open both 4.50PG and 4.51PG bioses in the same version. The EPA logo does not work in 4.50PG.
* User can edit all 4 PCI IRQ routing tables even if the 4th one is not present (is marked as IRQ 0xFF)
* User can now edit all values of the PCI IRQ routing table, even if they originally had less than 3 characters.
* Fixed a bug where compiling with the windows SDK later than 7 will result in the menu bar not showing.

v1.0.1
* Changed 1 to 0 to allow reading of 4.50PG bioses (no economies were harmed)

I guess the cleanup work has some more bugs but so far I have not encountered them (yet).

# Credits

All credits to the original author.

# Text from original author

Thank you for downloading the Award BIOS Editor. There are some important things regarding the Editor contained in this file, so please read carefully.

First of all, a few links to some resources:

    Our homepage is available at: http://awdbedit.sourceforge.net
    The SourceForge.net Project page is available at: http://sourceforge.net/projects/awdbedit/
    And finally, some documentation.

The Award BIOS Editor 1.0 release marks a comeback from being gone for almost two years. I have had a fair amount of personal things to deal with (I will not bore you by describing them to you), but now things are back to normal, and my interest in the Award BIOS Editor has returned.

The project has transformed itself from closed-source to open-source. I've always been a fan of open-source projects, but I've never had any of my stuff open. I like how the GPL works, where I maintain copyright, and require that derivative works remain open-source.

Most of this source code is over a year and a half old. I was reviewing it the other day, and it looked horrible. :) Please do not make any comments about how I could do this thing better or it would be easier if I did that instead -- I plan to cleanup the codebase and move to MFC from here on.

Note that this is version 1.0 of the Award BIOS Editor. This is newer than the last publicly available version (RC1) from my old website. Not too much has changed, but the "Setup Menu" tab works a _lot_ better, and execution of v4.51PG BIOSes is almost perfect.

I am currently _NOT_ recruiting developers to assist on the project -- you may ask, but I will probably say no. There is a lot of cleanup work I want to take care of first, along with the new plug-in API changes. Once that's been done, the Award BIOS Editor can start to proceed to v2.0, and I'll start looking for other developers to join the project. You are welcome to submit a patch if you like, however. Should it be useful, I will do my best to make sure it gets integrated into the source tree.

That's all for now. Thanks again, and happy hacking!
