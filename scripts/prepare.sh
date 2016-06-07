#! /bin/bash
set -euo pipefail
IFS=$'\n\t'

# Archives are to be downloaded from:
URL_BASE=https://sourceforge.net/projects/micro-os-plus/files/Vendor%20Archives/SEGGER/

# RELEASE_VERSION="V510u"
# RELEASE_VERSION="V512"
RELEASE_VERSION="V512a"


NAME_PREFIX="SEGGER_RTT_"
RELEASE_NAME="${NAME_PREFIX}${RELEASE_VERSION}"
ARCHIVE_NAME="${RELEASE_NAME}.tgz"
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

tar -xf "${LOCAL_ARCHIVE_FILE}"

mv SEGGER_RTT_* SEGGER_RTT

find . -name '*.exe' -exec rm \{} \;

cat <<EOF >README.md
# SEGGER RTT

This project, available from [GitHub](https://github.com/xpacks),
includes the SEGGER RTT files.

## Version

* ${RELEASE_VERSION}

## Documentation

The latest RTT documentation is available from
the J-Link manual [UM08001](https://www.segger.com/admin/uploads/productDocs/UM08001_JLink.pdf).

## Original files

The original files are available from the \`originals\` branch.

These files were extracted from \`${ARCHIVE_NAME}\`.

To save space, the following folders/files were removed:

* none

EOF

echo
echo Check if ok and when ready, issue:
echo git add -A
echo git commit -m ${ARCHIVE_NAME}
