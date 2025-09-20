# Bug Report: Incorrect Redo Behavior After New Action

## Bug Identification

*   **File:** `src/undo.cpp`
*   **Function:** `storeUndoPIX(PIX *newPix)`

## Description

There is a logical error in the undo/redo functionality. When a user performs an action, undoes it, and then performs a new, different action, the "redo" stack is not cleared. This allows the user to "redo" the original undone action, which is incorrect and unintuitive behavior. The expected behavior is that any new action should clear the possibility of redoing past actions.

### Steps to Reproduce:

1.  Open an image in the application.
2.  Perform an image modification (e.g., rotate the image).
3.  Undo the modification. The image reverts to its original state.
4.  Perform a different modification (e.g., crop the image).
5.  The "Redo" button is still enabled. Clicking it will re-apply the rotation from step 2, instead of there being no action to redo.

## Impact

This bug leads to a confusing and unpredictable user experience. It can cause users to accidentally re-apply old changes, potentially leading to lost work or unexpected image states.

## Proposed Fix

The fix is to ensure the redo stack is cleared whenever a new action is taken. This is achieved by calling a `cleanRedoStack()` function from within the `storeUndoPIX()` function. This ensures that after a new modification, there is no longer a "redo" history, which aligns with standard application behavior. I have already implemented this fix.
