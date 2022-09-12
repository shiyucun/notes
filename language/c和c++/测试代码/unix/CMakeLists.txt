cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(unix_test_code LANGUAGES C)

add_executable(access)
target_sources(access
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/access.c
)


add_executable(alarm)
target_sources(alarm
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/alarm.c
)

add_executable(brk_sbrk)
target_sources(brk_sbrk
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/brk_sbrk.c
)

add_executable(brk)
target_sources(brk
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/brk.c
)

add_executable(chmod_truncate)
target_sources(chmod_truncate
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/chmod_truncate.c
)

add_executable(dir)
target_sources(dir
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/dir.c
)

add_executable(dirC)
target_sources(dirC
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/dirC.c
)

add_executable(dup)
target_sources(dup
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/dup.c
)

add_executable(dup2)
target_sources(dup2
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/dup2.c
)

add_executable(EditUCEffective)
target_sources(EditUCEffective
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/EditUCEffective.c
)

add_executable(effective)
target_sources(effective
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/effective.c
)

add_executable(environ)
target_sources(environ
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/environ.c
)

add_executable(environment)
target_sources(environment
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/environment.c
)

add_executable(errno)
target_sources(errno
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/errno.c
)

add_executable(error)
target_sources(error
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/error.c
)

add_executable(execl)
target_sources(execl
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/execl.c
)

add_executable(exit)
target_sources(exit
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/exit.c
)

add_executable(FcntlFsetlkA)
target_sources(FcntlFsetlkA
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/FcntlFsetlkA.c
)

add_executable(FcntlFsetlkB)
target_sources(FcntlFsetlkB
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/FcntlFsetlkB.c
)

add_executable(fd)
target_sources(fd
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/fd.c
)

add_executable(fgetlck)
target_sources(fgetlck
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/fgetlck.c
)

add_executable(fork)
target_sources(fork
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/fork.c
)

add_executable(forkmemory)
target_sources(forkmemory
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/forkmemory.c
)

add_executable(forksignal)
target_sources(forksignal
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/forksignal.c
)

add_executable(itimer)
target_sources(itimer
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/itimer.c
)

add_executable(kill)
target_sources(kill
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/kill.c
)

add_executable(line)
target_sources(line
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/line.c
)

add_executable(lseek)
target_sources(lseek
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/lseek.c
)

add_executable(malloc)
target_sources(malloc
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/malloc.c
)

add_executable(mmap2)
target_sources(mmap2
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/mmap2.c
)

add_executable(mmap)
target_sources(mmap
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/mmap.c
)

add_executable(msgA)
target_sources(msgA
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/msgA.c
)

add_executable(msgB)
target_sources(msgB
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/msgB.c
)

add_executable(NoNamepipe)
target_sources(NoNamepipe
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/NoNamepipe.c
)

add_executable(open_close)
target_sources(open_close
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/open_close.c
)

add_executable(pipeA)
target_sources(pipeA
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/pipeA.c
)

add_executable(pipeB)
target_sources(pipeB
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/pipeB.c
)

add_executable(practice_pthread_join)
target_sources(practice_pthread_join
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/practice_pthread_join.c
)
target_link_libraries(practice_pthread_join
  PRIVATE
    pthread
)

add_executable(pragma_dependency)
target_sources(pragma_dependency
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/pragma_dependency.c
)

add_executable(pragma_packn)
target_sources(pragma_packn
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/pragma_packn.c
)

add_executable(pragma_poison)
target_sources(pragma_poison
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/pragma_poison.c
)

add_executable(processRelation)
target_sources(processRelation
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/processRelation.c
)

add_executable(pthread_cancel)
target_sources(pthread_cancel
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_cancel.c
)
target_link_libraries(pthread_cancel
  PRIVATE
    pthread
)

add_executable(pthread_create2)
target_sources(pthread_create2
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_create2.c
)
target_link_libraries(pthread_create2
  PRIVATE
    pthread
)

add_executable(pthread_create3)
target_sources(pthread_create3
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_create3.c
)
target_link_libraries(pthread_create3
  PRIVATE
    pthread
)

add_executable(pthread_create)
target_sources(pthread_create
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_create.c
)
target_link_libraries(pthread_create
  PRIVATE
    pthread
)

add_executable(pthread_detach)
target_sources(pthread_detach
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_detach.c
)
target_link_libraries(pthread_detach
  PRIVATE
    pthread
)

add_executable(pthread_exit)
target_sources(pthread_exit
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_exit.c
)
target_link_libraries(pthread_exit
  PRIVATE
    pthread
)

add_executable(pthread_join)
target_sources(pthread_join
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_join.c
)
target_link_libraries(pthread_join
  PRIVATE
    pthread
)

add_executable(pthread_mutex)
target_sources(pthread_mutex
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_mutex.c
)
target_link_libraries(pthread_mutex
  PRIVATE
    pthread
)

add_executable(pthread_sem)
target_sources(pthread_sem
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_sem.c
)
target_link_libraries(pthread_sem
PRIVATE
  pthread
)

add_executable(raise)
target_sources(raise
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/raise.c
)

add_executable(read)
target_sources(read
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/read.c
)

add_executable(read_UCemp)
target_sources(read_UCemp
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/read_UCemp.c
)

add_executable(Rmmap2)
target_sources(Rmmap2
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Rmmap2.c
)

add_executable(semset)
target_sources(semset
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/semset.c
)

add_executable(semsettest)
target_sources(semsettest
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/semsettest.c
)

add_executable(shmA)
target_sources(shmA
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/shmA.c
)

add_executable(shmB)
target_sources(shmB
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/shmB.c
)

add_executable(sigaction2)
target_sources(sigaction2
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/sigaction2.c
)

add_executable(sigaction)
target_sources(sigaction
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/sigaction.c
)

add_executable(signal)
target_sources(signal
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/signal.c
)

add_executable(sigprocmask)
target_sources(sigprocmask
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/sigprocmask.c
)

add_executable(sigqueue)
target_sources(sigqueue
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/sigqueue.c
)

add_executable(sigset_t)
target_sources(sigset_t
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/sigset_t.c
)

add_executable(sockA)
target_sources(sockA
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/sockA.c
)

add_executable(sockB)
target_sources(sockB
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/sockB.c
)

add_executable(socknetA)
target_sources(socknetA
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/socknetA.c
)

add_executable(socknetB)
target_sources(socknetB
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/socknetB.c
)

add_executable(stat)
target_sources(stat
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/stat.c
)

add_executable(system)
target_sources(system
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/system.c
)

add_executable(TCPA)
target_sources(TCPA
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/TCPA.c
)

add_executable(TCPB)
target_sources(TCPB
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/TCPB.c
)

add_executable(testfsetlk)
target_sources(testfsetlk
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/testfsetlk.c
)

add_executable(UCEffective)
target_sources(UCEffective
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/UCEffective.c
)

add_executable(UDPA)
target_sources(UDPA
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/UDPA.c
)

add_executable(UDPB)
target_sources(UDPB
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/UDPB.c
)

add_executable(umask)
target_sources(umask
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/umask.c
)

add_executable(unlock)
target_sources(unlock
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/unlock.c
)

add_executable(vfork)
target_sources(vfork
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/vfork.c
)

add_executable(vforksignal)
target_sources(vforksignal
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/vforksignal.c
)

add_executable(wait)
target_sources(wait
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/wait.c
)

add_executable(waitpid)
target_sources(waitpid
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/waitpid.c
)

add_executable(write)
target_sources(write
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/write.c
)

add_executable(write_UCemp)
target_sources(write_UCemp
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/write_UCemp.c
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/liba)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libso)
add_subdirectory(libdl)
