# fpmtop

### Build manually
You can build fpmtop from sources:
```bash
# Install build tools
sudo apt-get install build-essential cmake
# Install dependencies
sudo apt-get install libcurl4-openssl-dev

# Let's make and run
mkdir ~/tmp && cd ~/tmp
git clone https://github.com/qMBQx8GH/fpmtop
fpmtop/fpmtop/proj.cmake/run.sh
