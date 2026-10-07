# COMPILATION COMMANDS:
# gcc main.c -o program
# gcc -Wall -Wextra -Werror -std=c23 main.c list.c -o program

{
    description = "Basic C console app";

    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    };

    outputs =
        { nixpkgs, ... }:
        let
            system = "x86_64-linux";
            pkgs = import nixpkgs { inherit system; };
        in
        {
            devShells.${system}.default = pkgs.mkShell {
                packages = with pkgs; [
                    gcc # GNU compiler
                    gdb # GNU debugger
                ];
            };
        };
}
