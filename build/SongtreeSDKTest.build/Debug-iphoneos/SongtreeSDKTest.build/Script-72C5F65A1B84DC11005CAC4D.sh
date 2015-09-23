#!/bin/sh
echo "Deleting static lib in SongtreeSDK framework:"
THEPATH=${TARGET_BUILD_DIR}/${PRODUCT_NAME}.app/SongtreeSDK.framework/SongtreeSDK
echo -n ${THEPATH}
if [ -f ${THEPATH} ] ; then
rm ${THEPATH}
fi
