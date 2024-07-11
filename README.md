# Hospital-Management

Here is a list of all the changes made for Session B:

### Added
- DoctorRepo, PatientRepo, MedicineRepo are now classes in order to encapsulate the data better.
- DoctorOperations, PatientOperations, ParseFunctions are now classes which initialise the repos as smart pointers.
- All usages of arrays have been changed to vectors, alongside changing the manipulation functions to their respective vector counterparts.

### Removed
- Functions that only have definitions but have never been used in the program have been removed.
