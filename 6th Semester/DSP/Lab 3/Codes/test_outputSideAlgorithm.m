s = [3 2 5 7 9 8 17 2];
h = [2 0 1 4];
convSig = outputSideAlgorithm(s, h);
disp(convSig);
% 6    4   13   28   31   43   71   48   49   70    8
plotSignals(s, h, convSig);
