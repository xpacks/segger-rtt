#! /bin/bash
set -euo pipefail
IFS=$'\n\t'

# Archives are to be downloaded from:
URL_BASE=https://sourceforge.net/projects/micro-os-plus/files/Vendor%20Archives/SEGGER/

# RELEASE_VERSION="V232"
# RELEASE_VERSION="V232a"
RELEASE_VERSION="V232b"


NAME_PREFIX="SystemView_Src_"
RELEASE_NAME="${NAME_PREFIX}${RELEASE_VERSION}"
ARCHIVE_NAME="${RELEASE_NAME}.zip"
ARCHIVE_URL="${URL_BASE}/${ARCHIVE_NAME}"

LOCAL_ARCHIVE_FILE="/tmp/xpacks/${ARCHIVE_NAME}"

for f in *
do
  if [ "${f}" == "scripts" ]
  then
    :
  else
    rm -rf "${f}"
  fi
done

if [ ! -f "${LOCAL_ARCHIVE_FILE}" ]
then
  mkdir -p $(dirname ${LOCAL_ARCHIVE_FILE})
  curl -o "${LOCAL_ARCHIVE_FILE}" -L "${ARCHIVE_URL}"
fi

unzip "${LOCAL_ARCHIVE_FILE}" -d SystemView

find . -name '*.exe' -exec rm \{} \;

rm SystemView/UM08027_SystemView.pdf

cat <<EOF >README.md
# SEGGER SystemView

This project, available from [GitHub](https://github.com/xpacks),
includes the SEGGER SystemView source files.

## Version

* ${RELEASE_VERSION}

## Documentation

The latest SystemView documentation is available from
the SystemView manual [UM08027](https://www.segger.com/downloads/free_tools/UM08027_SystemView.pdf).

## Original files

The original files are available from the \`originals-sv\` branch.

These files were extracted from \`${ARCHIVE_NAME}\`.

To save space, the following folders/files were removed:

* SystemView/UM08027_SystemView.pdf

EOF

echo
echo Check if ok and when ready, issue:
echo git add -A
echo git commit -m ${ARCHIVE_NAME}
