#
# Copyright (c) 2018, RISC OS Open Ltd
# All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may
# not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# 
# Makefile for mbedTLS
#

COMPONENT  = mbedTLS
OBJS_X509  = certs pkcs11 x509 \
             x509_create x509_crl x509_crt \
             x509_csr x509write_crt x509write_csr
OBJS_TLS =   debug ssl_cache \
             ssl_ciphersuites ssl_cli \
             ssl_cookie ssl_srv ssl_ticket \
             ssl_tls net_sockets
OBJS_CRYPTO = aes aesni aria arc4 \
             asn1parse asn1write base64 \
             bignum blowfish camellia \
             ccm cmac chacha20 chachapoly cipher cipher_wrap \
             ctr_drbg des dhm \
             ecdh ecdsa ecjpake \
             ecp ecp_curves \
             entropy entropy_poll \
             error gcm havege \
             hkdf hmac_drbg md md2 \
             md4 md5 md_wrap \
             memory_buffer_alloc nist_kw oid \
             padlock pem pk \
             pk_wrap pkcs12 pkcs5 \
             pkparse pkwrite platform platform_util \
             poly1305 ripemd160 rsa rsa_internal sha1 \
             sha256 sha512 threading timing \
             version \
             version_features xtea
OBJS       = ${OBJS_X509} ${OBJS_TLS} ${OBJS_CRYPTO}
HDRS       = ro_config check_config other_mbedtls_hdrs
RO_CONFIG  = h${SEP}ro_config
CINCLUDES  = -ITCPIPLibs:
CDEFINES   = -DMBEDTLS_CONFIG_FILE="\"${RO_CONFIG}\"" -DRISCOS
CFLAGS     = -Wp

include CLibrary

exphdr.ro_config:
             ${AWK} -f ${RO_CONFIG}awk ${RO_CONFIG} > ${EXPDIR}${SEP}${RO_CONFIG}

exphdr.other_mbedtls_hdrs:
             ${CP} mbedtls ${EXPDIR}${SEP}mbedtls ${CPFLAGS}

# Dynamic dependencies:
