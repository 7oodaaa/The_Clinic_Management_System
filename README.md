# The_Clinic_Management_System
The Clinic Management System is a C program that provides a user-friendly interface for managing patient records and appointments in a clinic. It offers both admin and user modes, each with distinct functionalities.
# Admin Mode:
a. Password Entry:
 - The admin is prompted to enter a password (default: 1234).
 - The system allows 3 password entry attempts. After 3 incorrect attempts, the system closes.

b. Features in Admin Mode:
 1. Add New Patient Record:
  - The admin can add a new patient record with the following information: (name, age, gender, and unique ID)
  - If the entered ID already exists, the system rejects the entry.

 2. Edit Patient Record:
  - The admin can edit patient information by entering the patient's ID.
  - If the ID exists, the admin can modify the patient's details; otherwise, an incorrect ID message is displayed.
  
 3. Reserve a Slot with the Doctor:
  - The admin can reserve a slot for a patient from available time slots (2pm to 2:30pm, 2:30pm to 3pm, etc.).
  - The reserved slot is removed from the list of available slots for subsequent reservations.
  
 4. Cancel Reservation:
  - The admin can cancel a reservation by entering the patient's ID.
  - The canceled reservation becomes available again in the list of slots.
 
 5. Log out.

 6. Exit.


# User Mode:
a. Features in User Mode:
 1. View Patient Record:
  - The user can view basic information for a patient by entering the patient's ID.

 2. View Today's Reservations:
  - The user can view all reservations for the current day,
    displaying the patient ID attached to each reservation slot.

 3. Log out.

 4. Exit.

Note:
- The Clinic Management System ensures data accuracy by enforcing unique patient IDs.
- The admin password is used to prevent unauthorized access to admin features.
- Time slots are available for reservation and can be reserved or canceled as needed.
