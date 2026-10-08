#!/bin/sh
set -eu

repo_root=$(git rev-parse --show-toplevel)

git -C "$repo_root" sparse-checkout init --no-cone
git -C "$repo_root" sparse-checkout set --no-cone --stdin < "$repo_root/.sparse-checkout"

echo "Sparse checkout enabled."
echo "Hidden: 2026spring-cs201/ and courseware/pptx_builder/"
echo "Run 'git sparse-checkout disable' to show all tracked files again."
