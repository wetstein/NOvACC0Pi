# Meeting Notes


## Meeting with Matt and Sebastian Nov 1, 2018

Still using an older version works for CAF problems. Sebastian spoke with Miranda (notes [here](./OnMiranda'sCode.md))
Miranda uses unstandard code, written by her and Jeremy - can spiral away from the base version of CAFAna
Sebastian would prefer to stick with the standard release

Michael Baird has a talk on "Prong base studies in a Slice based world": [docdb-31906](https://nova-docdb.fnal.gov/cgi-bin/private/RetrieveFile?docid=31906&filename=18-08-24_BPF_summary_4_ND_group.pdf&version=1)
* Some capabilities already exist, but Sebastian will have to make his code work with something closer to the header.
* These new functions do not require new CAF files to be made
* Machinery still makes spectra once per slice. To do once per prong takes more hacking - that's what Miranda and Jeremy were using.

After discussing the complexities of the issue, we decided that it would be best to work on using CAF in more standard ways while we pursue more prong-based functionality at a later time.

Most immediately, we plan to move ahead with making some instant gratification plots using a sample of events with exactly 
two prongs, where one is definitely a muon at the truth-level and the other is definitely a pion, and samples with exactly one muon prong and no pions at truth level. We would the make plots:
1) Comparing track length distributions of the pion and muon prongs in the two-prong sample to the muon track in the single muon sample.
2) Comparing muon id (CVN-prong) "  "  "
3) Comparing muon id (ND-group) "  "  "
4) Comparing pion id (CVN-prong) "  "  "
5) Comparing proton id (CVN-prong) " " "
6) Comparing EM id (CVN-prong) " " "

The idea is to identify a first set of cuts that provides maximum purity without reducing efficiency. 

Side note: Sebastian has also added a [simple CAFAna example](../CAFAna/example/test.C
) for Matt's reference/learning.


## Meeting with Matt and Sebastian October 12, 2018

There were some problems in CAFana due to changes in the Develop release - going back to a previously frozen version worked to resolved.

Next step is working on plots separating by truth level particles:
* Next week, Matt should learn how a CAF analysis works
* We should talk to Miranda about how to pull out truth-particle information.


## Meeting notes: October 5th, 2018

ND group uses: 
- Own MuonID definition
- ProngCVN for pions or other particles

Questions to research:
- When do muons and pions become more indistinguishable? Select events having 1 muon and 1 pion (true) , where we have exactly two prongs (a true muon and a true pion). Then plot the Prong length, ND MuonID, the ProngCVN MuonID and ProngCVN PionID for all those. Pions and protons should have a different distribution here. Where to put the cut such that we don't touch the protons.
- How short can we make that prong length cut before we start rejecting other particles? Prong length is very transparent and orthogonal to other vars that may be correlated. So, how low can we get this cut?

Tasks to try:
1) Investigate prong length cuts (break signal and background distributions by truth particles). Focus on Pions vs Protons, and Pions vs NeutronActivity
2) Take samples with several (2,3,4...) multiplicities and plot ProngCVN IDs, break then by truth particles. Plot with several cuts on TrackLenghts (from previous file)
3) Plot explicitly 2 prong sample distributions of Pion and muon scores, to figure out how often these are confused (e.g., muon being the short track)

Things to consider:
- Protons are short (few cells), and neutrons give a displaced vertex (giveaway) and a short proton track. They might give some pizeros, but we can then put a EMID cut
- ProngCVN MuonID =-1 means prong got automatically labeled as a muon because of its length being greater than 5m.
- Contamination of electron neutrino events (i.e. electrons)
