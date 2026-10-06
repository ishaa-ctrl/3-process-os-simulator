# IPC Test Cases

| Test Case | Input | Expected Result | Actual Result | Status |
|---|---|---|---|---|
| TC01 | start | Core starts CPU execution and sends response to UI | CPU execution started | PASS |
| TC02 | status | Core sends CPU, Memory, Stack and Queue status to UI | Status received correctly | PASS |
| TC03 | stop | Core stops CPU execution and sends response to UI | CPU execution stopped | PASS |
| TC04 | exit | Core shuts down and processes terminate correctly | Processes terminated correctly | PASS |
| TC05 | Unknown command | Core should reject invalid command | Unknown command response received | PASS |

## IPC Communication Tested

- UI → Core through `ui_to_core`
- Core → UI through `core_to_ui`
- Core → Logger through `core_to_logger`

All tested IPC communication worked successfully.
