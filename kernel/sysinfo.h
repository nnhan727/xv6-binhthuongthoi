struct sysinfo {
  uint64 freemem;   // amount of free memory (bytes)
  uint64 nproc;     // number of process
  int loadavg_1m;
  int loadavg_5m;
  int loadavg_15m;
};