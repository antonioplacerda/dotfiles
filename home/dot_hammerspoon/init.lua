hs.grid.setGrid('2x2') -- allows us to place on quarters, thirds and halves
hs.window.animationDuration = 0 -- disable animations

local grid = {
  bottomHalf = '0,1 2x1',
  leftHalf = '0,0 1x2',
  rightHalf = '1,0 1x2',
  topHalf = '0,0 2x1',

  fullScreen = '0,0 2x2',
}

--
-- Key bindings.
--

function moveFrontmostWindow(where)
  return function()
    local window = hs.window.frontmostWindow()
    local screen = window:screen()
    hs.grid.set(window, where, screen)
  end
end

function launchOrFocus(app)
  return function()
    hs.application.launchOrFocus(app)
  end
end

local bindings = {
  [{'cmd', 'ctrl'}] = {
    s = moveFrontmostWindow(grid.leftHalf),
    t = moveFrontmostWindow(grid.bottomHalf),
    m = moveFrontmostWindow(grid.topHalf),
    n = moveFrontmostWindow(grid.rightHalf),

    f = moveFrontmostWindow(grid.fullScreen),
  },

  [{'alt', 'cmd', 'ctrl', 'shift'}] = {
    c = launchOrFocus('Google Chrome'),
    f = launchOrFocus('Finder'),
    s = launchOrFocus('Slack'),
    t = launchOrFocus('Terminal'),
    y = launchOrFocus('System Preferences'),
  },
}

for modifier, keyActions in pairs(bindings) do
  for key, action in pairs(keyActions) do
    hs.hotkey.bind(modifier, tostring(key), action)
  end
end

--
-- Auto-reload config on change.
--

function reloadConfig(files)
  for _, file in pairs(files) do
    if file:sub(-4) == '.lua' then
      hs.reload()
    end
  end
end

hs.pathwatcher.new(os.getenv('HOME') .. '/.hammerspoon/', reloadConfig):start()