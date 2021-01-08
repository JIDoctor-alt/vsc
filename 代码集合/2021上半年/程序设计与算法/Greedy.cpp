Sort all tasks A = {αi | 1 ≤ i ≤ n} according to fi(1 ≤ i ≤ n)；
Compatible := ∅;
while A ≠ empty do 
    Select the first task a in A;
    Delete a and all tasks which conflict with a from A;
    Compatible := Compatible∪{a};
return Compatible;