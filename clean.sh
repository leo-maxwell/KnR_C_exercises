find . \
  -type f \
  ! -path '*/.git/*' \
  ! -name '.gitignore' \
  -exec sh -c '
    for f do
      if [ "$(file -b --mime-encoding -- "$f")" = "binary" ]; then
        rm -- "$f"
      fi
    done
  ' sh {} +
