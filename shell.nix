{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  buildInputs = with pkgs; [
    clang
    glibc.dev
    raylib
  ];
  
  shellHook = ''
    # Keep system clangd in PATH
    export PATH="/run/current-system/sw/bin:$PATH"
  '';
}
