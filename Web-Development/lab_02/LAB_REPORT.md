# Лабораторная работа №2

## 1. Добавление логгирования

### Отдача HTML-страницы

```
{"time":"2019-09-29T15:05:37.575Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:05:37.581Z","lvl":"INFO","msg":"Response with status 200 in 6 ms."}
{"time":"2019-09-29T15:06:55.681Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:06:55.682Z","lvl":"INFO","msg":"Response with status 200 in 1 ms."}
{"time":"2019-09-29T15:07:41.219Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.220Z","lvl":"INFO","msg":"Response with status 200 in 1 ms."}
{"time":"2019-09-29T15:07:41.222Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.223Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.223Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.223Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.223Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.223Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.223Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.224Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.224Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.224Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.225Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.225Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.226Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.226Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.226Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.226Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.226Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.227Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.227Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.227Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.230Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.230Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.230Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.230Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.230Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.230Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.231Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.231Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.231Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.232Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.232Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.233Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.233Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.233Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.233Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.234Z","lvl":"INFO","msg":"Response with status 200 in 4 ms."}
{"time":"2019-09-29T15:07:41.234Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.234Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.234Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.235Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.236Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.236Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.236Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.238Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.238Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.238Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.238Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.238Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.238Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.239Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.239Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.240Z","lvl":"INFO","msg":"Response with status 200 in 4 ms."}
{"time":"2019-09-29T15:07:41.240Z","lvl":"INFO","msg":"Response with status 200 in 4 ms."}
{"time":"2019-09-29T15:07:41.240Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.241Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.241Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.241Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.241Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.241Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.242Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.243Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.244Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.244Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.244Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.244Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.244Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.245Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.245Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.246Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.246Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.246Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.246Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.247Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.247Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.247Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.247Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.248Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.248Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.248Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.249Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.250Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.250Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.250Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.251Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.252Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.252Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.252Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.253Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.253Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.253Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.254Z","lvl":"INFO","msg":"Response with status 200 in 4 ms."}
{"time":"2019-09-29T15:07:41.254Z","lvl":"INFO","msg":"Response with status 200 in 4 ms."}
{"time":"2019-09-29T15:07:41.254Z","lvl":"INFO","msg":"Response with status 200 in 4 ms."}
{"time":"2019-09-29T15:07:41.254Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.254Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.255Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.255Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.255Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.256Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.256Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.257Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.258Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.258Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.258Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.258Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.258Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.258Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.259Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.260Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.260Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.261Z","lvl":"INFO","msg":"Response with status 200 in 4 ms."}
{"time":"2019-09-29T15:07:41.261Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.262Z","lvl":"INFO","msg":"Response with status 200 in 4 ms."}
{"time":"2019-09-29T15:07:41.262Z","lvl":"INFO","msg":"Response with status 200 in 4 ms."}
{"time":"2019-09-29T15:07:41.262Z","lvl":"INFO","msg":"Response with status 200 in 4 ms."}
{"time":"2019-09-29T15:07:41.262Z","lvl":"INFO","msg":"Response with status 200 in 4 ms."}
{"time":"2019-09-29T15:07:41.262Z","lvl":"INFO","msg":"Response with status 200 in 4 ms."}
{"time":"2019-09-29T15:07:41.263Z","lvl":"INFO","msg":"Response with status 200 in 4 ms."}
{"time":"2019-09-29T15:07:41.263Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.264Z","lvl":"INFO","msg":"Response with status 200 in 4 ms."}
{"time":"2019-09-29T15:07:41.265Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.265Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.265Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.265Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.266Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.266Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.266Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.267Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.267Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.267Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.267Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.268Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.268Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.268Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.268Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.268Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.269Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.269Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.269Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.269Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.271Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.271Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.271Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.272Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.272Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.272Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.272Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.273Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.273Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.273Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.274Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.274Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.274Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.274Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.274Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.275Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.275Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.275Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.276Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.276Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.277Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.277Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.277Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.278Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.278Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.278Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.278Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.279Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.279Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.279Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.279Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.280Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.280Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.280Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.280Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.280Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.281Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.281Z","lvl":"INFO","msg":"Response with status 200 in 2 ms."}
{"time":"2019-09-29T15:07:41.282Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.283Z","lvl":"INFO","msg":"Response with status 200 in 4 ms."}
{"time":"2019-09-29T15:07:41.284Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.285Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.286Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.286Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.286Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.286Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.287Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.288Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.288Z","lvl":"INFO","msg":"Request from ::1: GET /"}
{"time":"2019-09-29T15:07:41.288Z","lvl":"INFO","msg":"Response with status 200 in 4 ms."}
{"time":"2019-09-29T15:07:41.288Z","lvl":"INFO","msg":"Response with status 200 in 3 ms."}
{"time":"2019-09-29T15:07:41.293Z","lvl":"INFO","msg":"Response with status 200 in 7 ms."}
{"time":"2019-09-29T15:07:41.293Z","lvl":"INFO","msg":"Response with status 200 in 7 ms."}
{"time":"2019-09-29T15:07:41.293Z","lvl":"INFO","msg":"Response with status 200 in 7 ms."}
{"time":"2019-09-29T15:07:41.294Z","lvl":"INFO","msg":"Response with status 200 in 8 ms."}
{"time":"2019-09-29T15:07:41.294Z","lvl":"INFO","msg":"Response with status 200 in 7 ms."}
{"time":"2019-09-29T15:07:41.294Z","lvl":"INFO","msg":"Response with status 200 in 6 ms."}
{"time":"2019-09-29T15:07:41.295Z","lvl":"INFO","msg":"Response with status 200 in 7 ms."}
```

```
 Benchmarking localhost (be patient).....done


Server Software:        
Server Hostname:        localhost
Server Port:            8000

Document Path:          /
Document Length:        100 bytes

Concurrency Level:      10
Time taken for tests:   0.077 seconds
Complete requests:      100
Failed requests:        0
Total transferred:      38700 bytes
HTML transferred:       10000 bytes
Requests per second:    1300.07 [#/sec] (mean)
Time per request:       7.692 [ms] (mean)
Time per request:       0.769 [ms] (mean, across all concurrent requests)
Transfer rate:          491.33 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    0   0.1      0       1
Processing:     2    7   1.8      7      13
Waiting:        2    6   1.8      6      13
Total:          2    7   1.8      7      13

Percentage of the requests served within a certain time (ms)
  50%      7
  66%      7
  75%      8
  80%      8
  90%      8
  95%     13
  98%     13
  99%     13
 100%     13 (longest request)

```

### Api (get-запрос)

```
{"time":"2019-09-29T15:09:48.383Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.383Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.385Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.385Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.385Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.385Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.386Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.386Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.387Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.387Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.387Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.387Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.388Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.388Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.388Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.388Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.388Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.388Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.388Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.389Z","lvl":"INFO","msg":"Response with status 200 in 1 ms."}
{"time":"2019-09-29T15:09:48.389Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.389Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.391Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.391Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.391Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.391Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.391Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.391Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.391Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.392Z","lvl":"INFO","msg":"Response with status 200 in 1 ms."}
{"time":"2019-09-29T15:09:48.392Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.392Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.393Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.393Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.393Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.393Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.393Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.393Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.393Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.394Z","lvl":"INFO","msg":"Response with status 200 in 1 ms."}
{"time":"2019-09-29T15:09:48.394Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.394Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.395Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.395Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.396Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.396Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.396Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.396Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.396Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.396Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.396Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.397Z","lvl":"INFO","msg":"Response with status 200 in 1 ms."}
{"time":"2019-09-29T15:09:48.397Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.397Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.398Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.398Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.398Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.398Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.398Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.399Z","lvl":"INFO","msg":"Response with status 200 in 1 ms."}
{"time":"2019-09-29T15:09:48.399Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.399Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.400Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.400Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.401Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.401Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.401Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.401Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.401Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.401Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.401Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.401Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.402Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.402Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.402Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.402Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.403Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.403Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.403Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.403Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.403Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.403Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.404Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.404Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.405Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.405Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.405Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.405Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.406Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.406Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.406Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.406Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.406Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.406Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.407Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.407Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.407Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.407Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.408Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.408Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.408Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.408Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.409Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.410Z","lvl":"INFO","msg":"Response with status 200 in 1 ms."}
{"time":"2019-09-29T15:09:48.410Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.410Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.410Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.410Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.411Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.411Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.411Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.411Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.412Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.412Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.412Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.412Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.412Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.412Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.413Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.413Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.413Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.413Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.414Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.414Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.415Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.415Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.415Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.415Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.415Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.415Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.415Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.415Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.416Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.416Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.416Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.416Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.416Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.417Z","lvl":"INFO","msg":"Response with status 200 in 1 ms."}
{"time":"2019-09-29T15:09:48.417Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.417Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.417Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.417Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.419Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.419Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.419Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.419Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.419Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.419Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.419Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.419Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.419Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.420Z","lvl":"INFO","msg":"Response with status 200 in 1 ms."}
{"time":"2019-09-29T15:09:48.420Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.420Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.420Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.420Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.421Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.421Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.422Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.422Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.423Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.423Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.424Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.424Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.425Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.425Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.425Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.425Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.425Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.425Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.425Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.425Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.426Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.426Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.426Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.426Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.426Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.426Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.427Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.427Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.427Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.427Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.428Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.428Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.429Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.429Z","lvl":"INFO","msg":"Response with status 200 in 1 ms."}
{"time":"2019-09-29T15:09:48.429Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.429Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.429Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.429Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.429Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.429Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.430Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.430Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.430Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.430Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.430Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.430Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
{"time":"2019-09-29T15:09:48.431Z","lvl":"INFO","msg":"Request from ::1: GET /api/"}
{"time":"2019-09-29T15:09:48.431Z","lvl":"INFO","msg":"Response with status 200 in 0 ms."}
```

```
Benchmarking localhost (be patient).....done


Server Software:        
Server Hostname:        localhost
Server Port:            8000

Document Path:          /api/
Document Length:        4 bytes

Concurrency Level:      10
Time taken for tests:   0.049 seconds
Complete requests:      100
Failed requests:        0
Total transferred:      20200 bytes
HTML transferred:       400 bytes
Requests per second:    2043.07 [#/sec] (mean)
Time per request:       4.895 [ms] (mean)
Time per request:       0.489 [ms] (mean, across all concurrent requests)
Transfer rate:          403.03 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    0   0.1      0       0
Processing:     1    5   0.8      4       6
Waiting:        1    4   0.8      4       5
Total:          1    5   0.8      5       6
WARNING: The median and mean for the processing time are not within a normal deviation
        These results are probably not that reliable.

Percentage of the requests served within a certain time (ms)
  50%      5
  66%      5
  75%      5
  80%      6
  90%      6
  95%      6
  98%      6
  99%      6
 100%      6 (longest request)

```

### Отдача изображения

```
Benchmarking localhost (be patient).....done


Server Software:        
Server Hostname:        localhost
Server Port:            8000

Document Path:          /img/image.jpg
Document Length:        101473 bytes

Concurrency Level:      10
Time taken for tests:   0.061 seconds
Complete requests:      100
Failed requests:        0
Total transferred:      10175200 bytes
HTML transferred:       10147300 bytes
Requests per second:    1636.15 [#/sec] (mean)
Time per request:       6.112 [ms] (mean)
Time per request:       0.611 [ms] (mean, across all concurrent requests)
Transfer rate:          162579.86 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    0   0.1      0       0
Processing:     1    6   1.7      5      11
Waiting:        1    4   1.2      4       8
Total:          2    6   1.7      6      11

Percentage of the requests served within a certain time (ms)
  50%      6
  66%      6
  75%      6
  80%      6
  90%      9
  95%     10
  98%     11
  99%     11
 100%     11 (longest request)
```

## 2. Конфигурация nginx

Добавил в файл конфигурации:

```
<...>
http {
    include       mime.types;
    default_type  application/octet-stream;

    sendfile        on;

    keepalive_timeout  65;

    server {
        listen       80;
        server_name  localhost;
	
	    location / {
            proxy_pass http://localhost:8000;
	    }
	}
<...>
```

## 3. Статика через nginx

Изменил файл конфигурации:

```
<...>
http {
    include       mime.types;
    default_type  application/octet-stream;

    sendfile        on;

    keepalive_timeout  65;

    server {
        listen       80;
        server_name  localhost;
	
	    location / {
            proxy_pass http://localhost:8000;
	        root /static/html;
	    }

	    location /img/ {
	        root /static;
	    }
	}
<...>
```

Получаю статику через сервер из первой лабораторной работы (изменил количество запросов на 1000 по 100): 

```
Benchmarking 127.0.0.1 (be patient)
Completed 100 requests
Completed 200 requests
Completed 300 requests
Completed 400 requests
Completed 500 requests
Completed 600 requests
Completed 700 requests
Completed 800 requests
Completed 900 requests
Completed 1000 requests
Finished 1000 requests


Server Software:        
Server Hostname:        127.0.0.1
Server Port:            8000

Document Path:          /
Document Length:        98 bytes

Concurrency Level:      100
Time taken for tests:   0.299 seconds
Complete requests:      1000
Failed requests:        0
Total transferred:      384000 bytes
HTML transferred:       98000 bytes
Requests per second:    3348.59 [#/sec] (mean)
Time per request:       29.863 [ms] (mean)
Time per request:       0.299 [ms] (mean, across all concurrent requests)
Transfer rate:          1255.72 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    1   0.4      1       2
Processing:     3   28   4.3     28      37
Waiting:        1   25   4.1     25      35
Total:          3   29   4.1     29      37

Percentage of the requests served within a certain time (ms)
  50%     29
  66%     30
  75%     32
  80%     33
  90%     35
  95%     37
  98%     37
  99%     37
 100%     37 (longest request)
```

Получаю статику через nginx:

```
Benchmarking 127.0.0.1 (be patient)
Completed 100 requests
Completed 200 requests
Completed 300 requests
Completed 400 requests
Completed 500 requests
Completed 600 requests
Completed 700 requests
Completed 800 requests
Completed 900 requests
Completed 1000 requests
Finished 1000 requests


Server Software:        nginx/1.17.3
Server Hostname:        127.0.0.1
Server Port:            80

Document Path:          /img/image.jpg
Document Length:        101473 bytes

Concurrency Level:      100
Time taken for tests:   0.070 seconds
Complete requests:      1000
Failed requests:        0
Total transferred:      101712000 bytes
HTML transferred:       101473000 bytes
Requests per second:    14298.38 [#/sec] (mean)
Time per request:       6.994 [ms] (mean)
Time per request:       0.070 [ms] (mean, across all concurrent requests)
Transfer rate:          1420231.13 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    1   0.6      1       3
Processing:     1    6   1.4      6       8
Waiting:        0    3   2.3      3       8
Total:          3    7   1.1      7       8

Percentage of the requests served within a certain time (ms)
  50%      7
  66%      7
  75%      7
  80%      7
  90%      8
  95%      8
  98%      8
  99%      8
 100%      8 (longest request)
```

Вывод: Производительность возросла в 4 раза. 

## 4. Кэширование и gzip-сжатие

Изменил файл конфигурации (добавил gzip-сжатие):

```
<...>
http {
    include       mime.types;
    default_type  application/octet-stream;

    sendfile        on;

    keepalive_timeout  65;

    server {
        listen       80;
        server_name  localhost;
        
        gzip on;
        gzip_comp_level 5;
        gzip_types text/plain text/css application/json application/x-javascript text/xml application/xml application/xml+rss text/javascript;
	
	    location / {
            proxy_pass http://localhost:8000;
	        root /static/html;
	    }

	    location /img/ {
	        root /static;
	    }
	}
<...>
```
Получаю статику через nginx с gzip:

```
Benchmarking 127.0.0.1 (be patient)
Completed 100 requests
Completed 200 requests
Completed 300 requests
Completed 400 requests
Completed 500 requests
Completed 600 requests
Completed 700 requests
Completed 800 requests
Completed 900 requests
Completed 1000 requests
Finished 1000 requests


Server Software:        nginx/1.17.3
Server Hostname:        127.0.0.1
Server Port:            80

Document Path:          /img/image.jpg
Document Length:        101473 bytes

Concurrency Level:      100
Time taken for tests:   0.067 seconds
Complete requests:      1000
Failed requests:        0
Total transferred:      101712000 bytes
HTML transferred:       101473000 bytes
Requests per second:    14941.65 [#/sec] (mean)
Time per request:       6.693 [ms] (mean)
Time per request:       0.067 [ms] (mean, across all concurrent requests)
Transfer rate:          1484126.36 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    0   0.6      0       3
Processing:     1    6   1.2      5       8
Waiting:        1    5   1.1      4       7
Total:          4    6   1.1      6       9

Percentage of the requests served within a certain time (ms)
  50%      6
  66%      7
  75%      7
  80%      7
  90%      8
  95%      8
  98%      8
  99%      9
 100%      9 (longest request)
```

Создал директроию для кэша:

```
sudo mkdir /var/cache
sudo mkdir /var/cache/nginx
```

Изменил файл конфигурации (добавил gzip-сжатие + кэширование):

```
<...>
http {
    include       mime.types;
    default_type  application/octet-stream;

    proxy_cache_path /var/cache/nginx levels=1:2 keys_zone=all:32m max_size=1g;

    sendfile        on;

    keepalive_timeout  65;

    server {
        listen 	     80;

        location / {
                proxy_pass http://127.0.0.1:81/;
                proxy_cache all;
                proxy_cache_valid any 1h;
        }
    }

    server {
	listen       81;
        server_name  localhost;

	gzip on;
        gzip_comp_level 5;
        gzip_types text/plain text/css application/json application/x-javascript text/xml application/xml application/xml+rss text/javascript;

	
	location / {
            proxy_pass http://localhost:8000;
	    root /static/html;
	}

	location /img/ {
	    root /static;
	}
}

<...>
```

Получаю статику через nginx с gzip и кэшированием:

```
Server Software:        nginx/1.17.3
Server Hostname:        127.0.0.1
Server Port:            80

Document Path:          /img/image.jpg
Document Length:        101473 bytes

Concurrency Level:      100
Time taken for tests:   0.072 seconds
Complete requests:      1000
Failed requests:        0
Total transferred:      101712000 bytes
HTML transferred:       101473000 bytes
Requests per second:    13807.39 [#/sec] (mean)
Time per request:       7.243 [ms] (mean)
Time per request:       0.072 [ms] (mean, across all concurrent requests)
Transfer rate:          1371461.86 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    0   0.6      0       3
Processing:     1    6   1.4      6       9
Waiting:        0    6   1.3      6       8
Total:          4    7   1.1      6       9

Percentage of the requests served within a certain time (ms)
  50%      6
  66%      7
  75%      8
  80%      8
  90%      8
  95%      9
  98%      9
  99%      9
 100%      9 (longest request)
```

Вывод: +- скорость осталась той же. 

## 5. Балансировка

Запущены 2 дополнительных инстанса сервера (порты 8001 и 8002) и настроены веса таким образом, чтобы на 2 новых сервера приходило в 3 раза больше запросов, чем на первый.

```
<...>
http {
    include       mime.types;
    default_type  application/octet-stream;

    proxy_cache_path /var/cache/nginx levels=1:2 keys_zone=all:32m max_size=1g;

    sendfile        on;

    keepalive_timeout  65;

    upstream backend {
	server 127.0.0.1:8000 weight=2;
	server 127.0.0.1:8001 weight=3;
	server 127.0.0.1:8002 weight=3;
    }

    server {
        listen 	     80;

        location / {
                proxy_pass http://127.0.0.1:81;
                proxy_cache all;
                proxy_cache_valid any 1h;
        }
    }

    server {
	listen       81;
        server_name  localhost;

	gzip on;
        gzip_comp_level 5;
        gzip_types text/plain text/css application/json application/x-javascript text/xml application/xml application/xml+rss text/javascript;

	
	location / {
            proxy_pass http://backend;
	    root /static/html;
	}

	location /img/ {
	    root /static;
	}
    }
<...>
```

## 6. Два мини-сервера

Запущены два сервиса (порты 8003 и 8004) и добавлены соответсвтующие html-страницы.

```
<...>
http {
    include       mime.types;
    default_type  application/octet-stream;

    proxy_cache_path /var/cache/nginx levels=1:2 keys_zone=all:32m max_size=1g;

    sendfile        on;

    keepalive_timeout  65;

    upstream backend {
	server 127.0.0.1:8000 weight=2;
	server 127.0.0.1:8001 weight=3;
	server 127.0.0.1:8002 weight=3;
    }

    server {
        listen 	     80;

        location / {
                proxy_pass http://127.0.0.1:81;
                proxy_cache all;
                proxy_cache_valid any 1h;
        }
        
        location /service1 {
                proxy_pass http://localhost:8003;
        }

	    location /service2 {
                proxy_pass http://localhost:8004;
        }
    }

    server {
	listen       81;
        server_name  localhost;

	gzip on;
        gzip_comp_level 5;
        gzip_types text/plain text/css application/json application/x-javascript text/xml application/xml application/xml+rss text/javascript;

	
	location / {
            proxy_pass http://backend;
	    root /static/html;
	}

	location /img/ {
	    root /static;
	}
    }
<...>
```

## 7. Статус

Добавил следующий код в первый блок server:

```
    location = /basic_status {
            stub_status;
        }

```

Если открыть страницу /basic_status, выведется следующая информация:

```
Active connections: 2 
server accepts handled requests
 37435 37435 37594 
Reading: 0 Writing: 1 Waiting: 1 
```

## 8. https 

Добавил следующий код в первую секцию server:

```
	listen 		     443 ssl;
	ssl_certificate      /certificate/localhost.crt;
    ssl_certificate_key  /certificate/localhost.key;
```

## 9. Server Push

Изменил код первой секции server на следующий код:

```
<...>
        listen 	     	     80;
	listen 		     443 ssl http2;
	ssl_certificate      /certificate/localhost.crt;
        ssl_certificate_key  /certificate/localhost.key;
	server_tokens off;

	location = /basic_status {
            stub_status;
        }

        location / {
                proxy_pass http://127.0.0.1:81/;
                proxy_cache all;
                proxy_cache_valid any 1h;

	        http2_push /img/picture.png;
        }
<...>
```

![005](https://sun9-29.userapi.com/c858428/v858428092/a0496/u0Qp4ZkMPxY.jpg)

## 10. Скрываю версию nginx

Добавил следующий код в первую секцию server:

```
<...>
server_tokens off;
<...>
```