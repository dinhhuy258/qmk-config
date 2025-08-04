# QMK Secret Macro System

A straightforward secret macro system for QMK keyboards that allows you to safely store and type sensitive information like passwords, usernames, and 2FA codes.

## 🔒 Security Features

### Simple Activation
- **Layer prerequisite**: Must be in WM layer (NAV + SYM held simultaneously)  
- **Combo trigger**: B+N keys pressed together while in WM layer
- **One-shot behavior**: SECRET layer deactivates after ANY keypress
- **Instant access**: Direct activation of SECRET layer - no sequences needed

## 🚀 Quick Setup

### 1. Copy and Configure Secrets
```bash
# Copy the template to create your secrets file
cp users/dinhhuy258/features/secrets_template.c users/dinhhuy258/features/secrets.c

# Edit with your actual secrets
# secrets.c is gitignored for safety
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
make crkbd:dinhhuy258:flash
```

## 🎯 How to Use

### Simple 3-Step Activation
1. **Enter WM Layer**: Hold NAV + SYM keys together
2. **Trigger Combo**: Press B + N simultaneously (while still holding NAV + SYM)
3. **Use Secrets**: You're now in SECRET layer - press any secret key

### What Happens
- SECRET layer activates immediately (no sequences to remember!)
- Press SECRET_1-5 to type your stored secrets
- Layer deactivates immediately after ANY keypress (one-shot behavior)
- If you press wrong key, layer exits and that key works normally

## 🗂️ Secret Layer Layout

```
┌─────┬─────┬─────┬─────┬─────┐ ┌─────┬─────┬─────┬─────┬─────┐
│ S1  │ S2  │ S3  │     │     │ │     │     │ S4  │ S5  │     │
├─────┼─────┼─────┼─────┼─────┤ ├─────┼─────┼─────┼─────┼─────┤  
│     │     │     │     │     │ │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┤ ├─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │ │     │     │     │     │     │
└─────┴─────┴─────┼─────┼─────┤ ├─────┼─────┴─────┴─────┴─────┘
                  │     │     │ │     │     │
                  └─────┴─────┘ └─────┴─────┘
```

- **S1-S5**: Your five secret macros
- **Any other key**: Deactivates secret layer and executes that key normally

## ⚡ Safety Features

### Automatic Controls
- **One-shot behavior**: Secret layer deactivates after ANY keypress
- **Modifier clearing**: Automatically clears all held modifiers before typing secrets

### Operational Security
- **No visual feedback**: No LED indicators when secret mode is active
- **Modifier clearing**: Automatically clears all modifier keys before typing secrets
- **Keystroke delays**: Small delays between characters for reliable transmission
- **Memory protection**: Secrets stored in program memory (PROGMEM)

## 🔧 Customization

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

### Customizing Timeouts
In `secret_triggers.h`:
```c
#define SECRET_MODE_TIMEOUT_MS 30000    // Secret mode duration (30 seconds)
#define SECRET_LOCKOUT_TIME_MS 300000   // Emergency disable duration (5 minutes)
```

## 🛡️ Security Best Practices

### File Security
- **Never commit secrets**: `secrets.c` is gitignored
- **Use templates**: Only commit `secrets_template.c` for others to copy
- **Backup separately**: Keep your actual secrets file backed up securely

### Usage Security  
- **Check surroundings**: Ensure no one can see your screen/keyboard
- **Practice activation**: Learn the B+N combo through muscle memory
- **One-shot design**: Layer exits immediately after any keypress - very safe

### Operational Security
- **Unique secrets**: Use complex, unique passwords
- **Regular rotation**: Change secrets periodically
- **Test carefully**: Verify secrets work before relying on them

## 🐛 Troubleshooting

### Secrets Not Working
1. Check if `secrets.c` exists (copy from template)
2. Ensure you're in WM layer first (NAV + SYM held)
3. B+N combo must be pressed simultaneously
4. Remember it's one-shot - any keypress deactivates the layer

### Build Issues
```bash
# Clean build if having issues
make clean
make crkbd:dinhhuy258:flash
```

### Activation Problems
- Must hold NAV + SYM first to get to WM layer
- Then press B+N combo while still holding NAV + SYM
- Layer is one-shot - deactivates after any keypress

## 📝 What Changed (Simplified Version)

### Removed Complexity
- ❌ No NO_SECRETS conditional compilation
- ❌ No sequence typing requirements ("SEC", etc.)
- ❌ No failed attempt tracking
- ❌ No steganographic triggers
- ❌ No timeout management
- ❌ No emergency disable feature

### Kept Essential Features
- ✅ Simple B+N combo activation in WM layer
- ✅ 5 secret storage slots
- ✅ One-shot behavior (deactivates on any keypress)
- ✅ Secure PROGMEM storage
- ✅ Modifier clearing for clean transmission

### Result
- Much simpler to use (just B+N combo in WM layer)
- No sequences to remember
- One-shot behavior - very safe and predictable
- Still secure (requires tri-layer activation)
- Ultra-simple code - easy to understand and maintain

Perfect for personal use where you want maximum simplicity and predictability!
