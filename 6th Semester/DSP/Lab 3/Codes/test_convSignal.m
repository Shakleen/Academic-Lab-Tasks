s = [3 2 5 7 9 8 17 2];
h = [2 0 1 4];
convSig = convSignals(s, h);

disp(convSig);
plotSignals(s, h, convSig);
