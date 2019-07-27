include "globals.mzn";
% include "regular.mzn";

set of int: Days = 1..7;
set of int: WorkDays = 1..5;

enum Doctors = {Dr_A, Dr_B, Dr_C, Dr_D, Dr_E};
enum ShiftTypes = {call, operation, appointment, none};

array [Doctors, Days] of var ShiftTypes: Roster;

constraint forall(day in Days) (
              count(Roster[.., day], call) = 1
            );

constraint forall(day in WorkDays) (
              count(Roster[.., day], operation) <= 2
            );

constraint count(array1d(Roster), operation) >= 7;

constraint count(array1d(Roster), appointment) >= 4;

% constraint forall(doctor in Doctors) (
%               regular (
%                 Roster[doctor,..], 
%                 "((operation none)|appointment|call|none)*"
%               )
%             );

solve satisfy;

output [
  "Day \(day)\n\(Roster[.., day])\n" | day in Days
];
