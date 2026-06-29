{
  description = "C/C++ learning environment with Clang, libc++, and Qt";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };

  outputs = { nixpkgs, ... }:
    let
      lib = nixpkgs.lib;
      forAllSystems = lib.genAttrs lib.systems.flakeExposed;
    in
    {
      devShells = forAllSystems (system:
        let
          pkgs = nixpkgs.legacyPackages.${system};
          clangPkgs = pkgs.llvmPackages_19;

          wrappedClangScanDeps = pkgs.writeShellScriptBin "clang-scan-deps" ''
            real="${clangPkgs.clang-unwrapped}/bin/clang-scan-deps"

            exec "$real" "$@" \
              -stdlib=libc++ \
              -isystem "${clangPkgs.libcxx.dev}/include/c++/v1" \
              -isystem "${clangPkgs.libunwind.dev}/include" \
              -isystem "${pkgs.glibc.dev}/include"
          '';
        in
        {
          default = pkgs.mkShell.override {
            stdenv = clangPkgs.libcxxStdenv;
          } {
            nativeBuildInputs = with pkgs; [
              wrappedClangScanDeps

              clangPkgs.clang
              clangPkgs.clang-tools
              clangPkgs.lldb

              cmake
              ninja
              gnumake
              pkg-config

              qt6.wrapQtAppsHook
            ];

            buildInputs = with pkgs; [
              clangPkgs.libcxx
              clangPkgs.libunwind

              qt6.qtbase
              qt6.qttools
            ];

            shellHook = ''
              export CC=clang
              export CXX=clang++

              export CLANGD_FLAGS="--query-driver=$(which clang),$(which clang++)"

              export CMAKE_PREFIX_PATH=${pkgs.qt6.qtbase}

              echo "C/C++ dev shell loaded with Clang + libc++ + Qt"
              echo "CC              = $(which clang)"
              echo "CXX             = $(which clang++)"
              echo "clang-scan-deps = $(which clang-scan-deps)"
              echo "CLANGD_FLAGS    = $CLANGD_FLAGS"
              echo "Qt version:"
              ${pkgs.qt6.qtbase}/bin/qmake --version | head -n 2
              clang --version | head -n 1
            '';
          };
        });
    };
}
