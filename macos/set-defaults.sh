#!/usr/bin/env bash
# Sets reasonable macOS defaults.
#
# Or, in other words, set shit how I like in macOS.
#
# The original idea (and a couple settings) were grabbed from:
#   https://github.com/mathiasbynens/dotfiles/blob/master/.macos
#
# Run ./set-defaults.sh and you'll be good to go.

# Disable press-and-hold for keys in favor of key repeat.
defaults write -g ApplePressAndHoldEnabled -bool false

# Always open everything in Finder's list view. This is important.
defaults write com.apple.Finder FXPreferredViewStyle Nlsv

# Show the ~/Library folder.
chflags nohidden ~/Library

# Set a really fast key repeat.
defaults write NSGlobalDomain KeyRepeat -int 1

# Set the Finder prefs for showing a few different volumes on the Desktop.
defaults write com.apple.finder ShowExternalHardDrivesOnDesktop -bool true
defaults write com.apple.finder ShowRemovableMediaOnDesktop -bool true

# Run the screensaver if we're in the bottom-left hot corner.
defaults write com.apple.dock wvous-bl-corner -int 5
defaults write com.apple.dock wvous-bl-modifier -int 0

# Show hidden files
defaults write com.apple.Finder AppleShowAllFiles true
killall Finder

# Switch keys to make sense... - `~ belong next to 1 and \| belong next to Z
read -p "Remap keys (only valid for PT/UK keyboards) [y/N]: " remap
if [[ "$remap" == "y" ]]
then
	hidutil property --set '{"UserKeyMapping":[
	{
		"HIDKeyboardModifierMappingSrc":0x700000035,
		"HIDKeyboardModifierMappingDst":0x700000031
	},{
		"HIDKeyboardModifierMappingSrc":0x700000064,
		"HIDKeyboardModifierMappingDst":0x700000035
	}]}'
fi

# Remove stupid shortcuts... Beeps on code...
mkdir -p ~/Library/KeyBindings
echo '{
  "^@\UF701" = "noop";
  "^@\UF702" = "noop";
  "^@\UF703" = "noop";
}' > ~/Library/KeyBindings/DefaultKeyBinding.dict
