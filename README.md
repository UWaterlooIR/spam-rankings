# Waterloo Spam Rankings for the ClueWeb12 Dataset

This repository provides the code needed to extract the spam scores for
the [ClueWeb12 (cw12)](http://lemurproject.org/clueweb12/)
dataset using spam models developed by [Cormack, Smucker, and
Clarke for ClueWeb09](http://plg.uwaterloo.ca/~gvcormac/clueweb09spam/).

As part of a "release" of this repository, we include a large tar file, waterloo-spam-cw12-encoded.tar, that
contains a gzip file for each of the cw12 directories.  Each file was
encoded using [compress-spam12.c](compress-spam12.c) before being gzip'd.  After gunzipping, each
file must be decompressed using [decompress-spam12.c](decompress-spam12.c).  To fetch and uncompress 
all of the files do (assuming a linux-like setup and bash shell):
```bash
  wget http://www.mansci.uwaterloo.ca/~msmucker/cw12spam/waterloo-spam-cw12-encoded.tar
  wget http://www.mansci.uwaterloo.ca/~msmucker/cw12spam/decompress-spam12.c
  gcc -o decompress-spam12 decompress-spam12.c
  mkdir waterloo-spam-cw12-decoded  
  tar -xvf waterloo-spam-cw12-encoded.tar
  cd waterloo-spam-cw12-encoded
  for f in *.spamPct.gz ; do cat $f | gunzip -c | ../decompress-spam12 | gzip -c &gt; ../waterloo-spam-cw12-decoded/$f ; done  
```
The tar is 654 MB.  Decoded, but still gzip'd, the files are 2.6 GB.

The format of each decoded file is:
```
    percentile-score clueweb-docid
```
where the percentile score indicates the percentage of the documents
in the corpus that are "spammier" as per the "fusion" spam score.  The
spammiest documents have a score of 0, and the least spammy have a
score of 99.  We have not extensively tested the spam scores on cw12,
but they appear reasonable.

The docids are not listed in any particular order in each file.

The fusion spam score is the average score produced by the three models
described in ["Efficient and Effective Spam Filtering and Re-ranking for 
Large Web Datasets"](http://link.springer.com/article/10.1007%2Fs10791-011-9162-z) 
with the modification that the "Britney" model has been trained on a very 
similar, but slightly different data set, from the the model used for ClueWeb09.
