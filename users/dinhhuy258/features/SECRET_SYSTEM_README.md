# QMK Secret Macro System

A highly secure, multi-layered secret macro system for QMK keyboards that allows you to safely store and type sensitive information like passwords, usernames, and 2FA codes.

## 🔒 Security Features

### Multi-Layer Authentication
- **Layer prerequisite**: Must be in WM layer (NAV + SYM held simultaneously)  
- **Combo trigger**: G+H keys pressed together while in WM layer
- **Sequence verification**: Must type "SEC" sequence correctly
- **Time-based lockouts**: Failed attempts result in temporary system lockout
- **Emergency disable**: Special sequence to completely disable secret system

### Steganographic Access (Hidden in Plain Sight)
- **Z+X long hold**: Hold Z for >2 seconds, then press X to enter sequence mode
- **Appears normal**: Failed attempts fall back to normal undo functionality
- **Context sensitive**: Only works when timing and sequence are perfect

## 🚀 Quick Setup

### 1. Copy and Configure Secrets
```bash
# Copy the template to create your secrets file
cp users/dinhhuy258/features/secrets_template.c users/dinhhuy258/features/secrets.c

# Edit with your actual secrets (NEVER commit this file!)
# It's already in .gitignore for safety
```

### 2. Update Your Secrets
Edit `users/dinhhuy258/features/secrets.c`:
```c
const char secret_1[] PROGMEM = "your_password_here";
const char secret_2[] PROGMEM = "your_username_here";  
const char secret_3[] PROGMEM = "your_email@domain.com";
const char secret_4[] PROGMEM = "your_2fa_backup_code";
const char secret_5[] PROGMEM = "your_api_key_here";
```

### 3. Build Firmware
```bash
# Normal build (includes secrets)
make crkbd:dinhhuy258:flash

# Public build (excludes secrets for sharing)
make crkbd:dinhhuy258:flash NO_SECRETS=yes
```

## 🎯 Activation Methods

### Method 1: Primary Trigger (Most Secure)
1. **Enter WM Layer**: Hold NAV + SYM keys together
2. **Trigger Combo**: Press G + H simultaneously (while still holding NAV + SYM)
3. **Enter Sequence**: Type "SEC" (S, then E, then C)
4. **Access Secrets**: You're now in SECRET layer for 30 seconds

### Method 2: Steganographic Trigger (Hidden)
1. **Long Hold Z**: Press and hold Z for more than 2 seconds
2. **Press X**: While Z is held, press X
3. **Enter Sequence**: Type "SEC" sequence
4. **Access Secrets**: SECRET layer is now active

## 🗂️ Secret Layer Layout

```
┌─────┬─────┬─────┬─────┬─────┐ ┌─────┬─────┬─────┬─────┬─────────┐
│ S1  │ S2  │ S3  │     │     │ │     │     │ S4  │ S5  │ DISABLE │
├─────┼─────┼─────┼─────┼─────┤ ├─────┼─────┼─────┼─────┼─────────┤  
│     │     │     │     │     │ │     │     │     │     │         │
├─────┼─────┼─────┼─────┼─────┤ ├─────┼─────┼─────┼─────┼─────────┤
│     │     │     │     │     │ │     │     │     │     │         │
└─────┴─────┴─────┼─────┼─────┤ ├─────┼─────┴─────┴─────┴─────────┘
                  │ ESC │     │ │     │     │
                  └─────┴─────┘ └─────┴─────┘
```

- **S1-S5**: Your five secret macros
- **ESC**: Exit secret mode immediately  
- **DISABLE**: Emergency disable (deactivates system completely)

## ⚡ Safety Features

### Automatic Timeouts
- **Secret mode**: Auto-deactivates after 30 seconds of inactivity
- **Sequence entry**: 5-second timeout for typing "SEC" sequence
- **Failed attempts**: System locks out for 1 minute after 3 failed attempts

### Emergency Controls
- **ESC key**: Immediately exits secret mode
- **Emergency disable**: Special 6-key sequence "ESCAPE" permanently disables system
- **Failed attempt lockout**: Temporary disable after repeated failures

### Operational Security
- **No visual feedback**: No LED indicators when secret mode is active
- **Modifier clearing**: Automatically clears all modifier keys before typing secrets
- **Keystroke delays**: Small delays between characters prevent detection
- **Memory protection**: Secrets stored in program memory (PROGMEM)

## 🔧 Advanced Configuration

### Customizing Timeouts
In `secret_triggers.h`:
```c
#define SECRET_MODE_TIMEOUT_MS 30000    // Secret mode duration
#define SECRET_SEQUENCE_TIMEOUT_MS 5000 // Sequence entry timeout  
#define SECRET_MAX_FAILED_ATTEMPTS 3    // Lockout threshold
#define SECRET_LOCKOUT_TIME_MS 60000    // Lockout duration
```

### Adding More Secrets
1. Add new keycode to `keycodes.h`:
   ```c
   SECRET_6,    // Sixth secret
   ```

2. Add to secret layer in `keymap_blocks.h`:
   ```c
   #define __________________SECRET_L1________________ SECRET_1, SECRET_2, SECRET_3, SECRET_6, XXXXXXX
   ```

3. Handle in `secrets.c`:
   ```c
   const char secret_6[] PROGMEM = "your_new_secret";
   
   // Add case in process_secret_macro():
   case SECRET_6:
       secret_string = secret_6;
       break;
   ```

### Disabling for Public Builds
```bash
# Build without secrets for sharing firmware
make crkbd:dinhhuy258:flash NO_SECRETS=yes

# Or set permanently in rules.mk:
NO_SECRETS = yes
```

## 🛡️ Security Best Practices

### File Security
- **Never commit secrets**: `secrets.c` and `secrets.h` are gitignored
- **Use templates**: Commit only `secrets_template.c` for others to copy
- **Backup separately**: Keep your actual secrets file backed up securely

### Usage Security  
- **Check surroundings**: Ensure no one can see your screen/keyboard
- **Practice sequences**: Learn the activation method through muscle memory
- **Use timeouts**: Don't leave secret mode active unnecessarily
- **Emergency disable**: Know how to quickly disable if compromised

### Operational Security
- **Randomize secrets**: Use unique, complex passwords
- **Regular rotation**: Change secrets periodically
- **Test carefully**: Verify secrets work before relying on them
- **Monitor access**: Be aware when secret mode is active

## 🐛 Troubleshooting

### Secrets Not Working
1. Check if `secrets.c` exists (copy from template)
2. Verify NO_SECRETS is not set in build
3. Ensure correct activation sequence
4. Check for emergency disable state

### Build Issues
```bash
# Clean build if having issues
make clean
make crkbd:dinhhuy258:flash
```

### Activation Problems
- Ensure you're in WM layer first (NAV + SYM held)
- G+H combo must be pressed simultaneously
- "SEC" sequence must be typed within 5 seconds
- Check for failed attempt lockout (wait 1 minute)

### Reset Emergency Disable
If system is emergency disabled:
1. Wait 5 minutes for auto-reset
2. Or rebuild firmware without NO_SECRETS flag
3. System will re-enable automatically

## 📝 Notes

- This system is designed for Corne keyboards but can be adapted for others
- The secret files are excluded from version control for security
- System gracefully degrades when disabled (no compilation errors)
- All secret operations clear modifier keys for reliable typing
- Failed sequences fall back to normal keyboard operation